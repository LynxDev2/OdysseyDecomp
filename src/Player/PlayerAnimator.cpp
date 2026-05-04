#include "Player/PlayerAnimator.h"

#include "Library/Action/ActorActionKeeper.h"
#include "Library/Base/StringUtil.h"
#include "Library/Effect/EffectSystemInfo.h"
#include "Library/LiveActor/ActorActionFunction.h"
#include "Library/LiveActor/ActorAnimFunction.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/LiveActor/LiveActor.h"
#include "Library/LiveActor/LiveActorFunction.h"
#include "Library/Math/MathUtil.h"
#include "Library/Obj/ActorDitherAnimator.h"

#include "Player/PlayerAnimFrameCtrl.h"
#include "Player/PlayerModelHolder.h"

namespace {
constexpr const char* sDeadAnimNames[] = {"Dead01", "Dead02", "Dead03"};
const char* const sAllBlendPartNames[] = {"顔", "目", "頭", "左手", "右手"};

al::LiveActor* getCurrentModelActor(const PlayerModelHolder* modelHolder) {
    return modelHolder->getCurrentModelActor();
}

al::LiveActor* getNormalModelActor(const PlayerModelHolder* modelHolder) {
    return modelHolder->findModelActor("Normal");
}

void setPartsAnimFrameAll(al::LiveActor* actor, const char* actionName, f32 frame) {
    if (!al::isActionPlaying(actor, actionName))
        return;

    if (al::isSklAnimExist(actor, actionName))
        al::setSklAnimBlendFrameAll(actor, frame, true);

    if (al::isMtpAnimExist(actor, actionName))
        al::setMtpAnimFrame(actor, frame);

    if (al::isMtsAnimExist(actor, actionName))
        al::setMtsAnimFrame(actor, frame);

    if (al::isVisAnimExist(actor, actionName))
        al::setVisAnimFrameForAction(actor, frame);
}

void setPartsAnimRateAll(al::LiveActor* actor, const char* actionName, f32 rate) {
    if (!al::isActionPlaying(actor, actionName))
        return;

    if (al::isSklAnimExist(actor, actionName))
        al::setSklAnimBlendFrameRateAll(actor, rate, true);

    if (al::isMtpAnimExist(actor, actionName))
        al::setMtpAnimFrameRate(actor, rate);

    if (al::isMtsAnimExist(actor, actionName))
        al::setMtsAnimFrameRate(actor, rate);

    if (al::isVisAnimExist(actor, actionName))
        al::setVisAnimFrameRateForAction(actor, rate);
}

void restoreEyeControlAnim(al::LiveActor* currentModel) {
    const char* actionName = al::getActionName(currentModel);
    f32 actionFrame = al::getActionFrame(currentModel);
    f32 actionRate = al::getActionFrameRate(currentModel);
    al::LiveActor* eye = al::tryGetSubActor(currentModel, "目");

    if (eye == nullptr)
        return;

    if (al::tryStartAction(eye, actionName)) {
        setPartsAnimRateAll(eye, actionName, actionRate);
        setPartsAnimFrameAll(eye, actionName, actionFrame);
    } else {
        al::startAction(eye, "Wait");
    }

    if (al::isMtsAnimPlaying(eye, "EyeMove"))
        al::startMtsAnim(eye, "EyeReset");
}

}  // namespace

PlayerAnimator::PlayerAnimator(const PlayerModelHolder* modelHolder,
                               al::ActorDitherAnimator* ditherAnim)
    : mModelHolder(modelHolder), mPlayerDeco(nullptr), mPlayer(nullptr),
      mAnimFrameCtrl(new PlayerAnimFrameCtrl()), mDitherAnim(ditherAnim) {
    const PlayerModelHolder* playerModelHolder = modelHolder;

    mEyeControlAnimFrame = 0.0f;
    mEndEyeControlAnimDelay = 0;
    mRunStartAnimRate = 0.0f;
    mModelAlphaInvalidateCounter = 0;
    mIsNeedFullFaceAnim = false;
    mIsBlendWeightEnabled = false;
    mIsSubAnimPlaying = false;
    mIsUpperBodyAnimPlaying = false;
    mIsUpperBodyAnimHeadVisKeep = false;
    mIsEyeControlAnim = false;
    _1a6 = false;
    mIsSubAnimOnlyAir = false;
    mSklAnimBlendWeights = new f32[6];
    mPlayer = playerModelHolder->getCurrentModelActor();
    mPlayerDeco = al::tryGetSubActor(getNormalModelActor(playerModelHolder), "飾り");
    startAnim("Wait");
}

void PlayerAnimator::startAnim(const sead::SafeString& animName) {
    const PlayerModelHolder* modelHolder = mModelHolder;
    sead::FixedSafeString<64>* curAnim = &mCurAnim;
    al::LiveActor* currentModel = modelHolder->getCurrentModelActor();
    al::LiveActor* normalModel = modelHolder->findModelActor("Normal");

    curAnim->format("%s%s", animName.cstr(), modelHolder->getAnimSuffix().cstr());
    if (!al::isExistAction(normalModel, curAnim->cstr()))
        curAnim->format("%s", animName.cstr());

    mAnimFrameCtrl->startAction(currentModel, *curAnim);
    mIsBlendWeightEnabled = false;

    if (!mIsSubAnimPlaying) {
        al::LiveActor* modelActor = getCurrentModelActor(mModelHolder);

        al::startAction(modelActor, curAnim->cstr());
        startPartsAnim(curAnim->cstr());
    }

    mAnimFrameCtrl->setRate(1.0f);

    if (!mIsSubAnimPlaying)
        setAnimRateCommon(1.0f);
}

void PlayerAnimator::updateAnimFrame() {
    if (!mIsSubAnimPlaying) {
        mAnimFrameCtrl->updateSync(getCurrentModelActor(mModelHolder));
        return;
    }

    mAnimFrameCtrl->update();
}

void PlayerAnimator::updateModel() {
    al::LiveActor* currentModel = getCurrentModelActor(mModelHolder);
    if (mPlayer == currentModel)
        return;

    copyAnimLocal();

    if (mIsUpperBodyAnimPlaying) {
        al::clearPartialSklAnim(mPlayer, 0);
        mIsUpperBodyAnimPlaying = false;
    }

    mDitherAnim->reset();
    setModelAlpha(1.0f);
    mPlayer = currentModel;
}

void PlayerAnimator::copyAnim() {
    copyAnimLocal();

    if (mIsUpperBodyAnimPlaying) {
        al::clearPartialSklAnim(mPlayer, 0);
        mIsUpperBodyAnimPlaying = false;
    }

    mDitherAnim->reset();
    setModelAlpha(1.0f);
}

void PlayerAnimator::startAnimCommon(const sead::SafeString& animName) {
    al::LiveActor* currentModel = getCurrentModelActor(mModelHolder);

    al::startAction(currentModel, animName.cstr());
    startPartsAnim(animName.cstr());
}

void PlayerAnimator::setAnimRate(f32 rate) {
    mAnimFrameCtrl->setRate(rate);

    if (!mIsSubAnimPlaying)
        setAnimRateCommon(rate);
}

void PlayerAnimator::startAnimSpinAttack(const sead::SafeString& animName) {
    const PlayerModelHolder* modelHolder = mModelHolder;
    sead::FixedSafeString<64>* spinAttackAnim = &_128;
    al::LiveActor* normalModel = modelHolder->findModelActor("Normal");

    spinAttackAnim->format("%s%s", animName.cstr(), modelHolder->getAnimSuffix().cstr());
    if (!al::isExistAction(normalModel, spinAttackAnim->cstr()))
        spinAttackAnim->format("%s", animName.cstr());

    startAnim(animName);
}

void PlayerAnimator::setAnimRateCommon(f32 rate) {
    if (al::isSklAnimPlaying(getCurrentModelActor(mModelHolder), 0))
        al::setSklAnimBlendFrameRateAll(getCurrentModelActor(mModelHolder), rate, true);

    if (al::isVisAnimPlayingForAction(getCurrentModelActor(mModelHolder)))
        al::setVisAnimFrameRateForAction(getCurrentModelActor(mModelHolder), rate);

    setPartsAnimRate(rate, mCurAnim.cstr());
}

void PlayerAnimator::setAnimFrame(f32 frame) {
    mAnimFrameCtrl->setFrame(frame);
    if (!mIsSubAnimPlaying)
        setAnimFrameCommon(frame);
}

void PlayerAnimator::setAnimFrameCommon(f32 frame) {
    al::LiveActor* currentModel = getCurrentModelActor(mModelHolder);
    bool isSklAnimExist = al::isSklAnimExist(currentModel, mCurAnim.cstr());
    currentModel = getCurrentModelActor(mModelHolder);

    if (isSklAnimExist) {
        al::setSklAnimBlendFrameAll(currentModel, frame, true);
    } else if (al::isVisAnimExist(currentModel, mCurAnim.cstr())) {
        f32 visFrame = al::getVisAnimFrameMaxForAction(getCurrentModelActor(mModelHolder));
        if (visFrame > frame)
            visFrame = frame;
        al::setVisAnimFrameForAction(getCurrentModelActor(mModelHolder), visFrame);
    }

    setPartsAnimFrame(frame, mCurAnim.cstr());
}

bool PlayerAnimator::isAnimEnd() const {
    return mAnimFrameCtrl->isActionEnd();
}

bool PlayerAnimator::isAnim(const sead::SafeString& animName) const {
    return al::isEqualString(animName.cstr(), mCurAnim.cstr()) ||
           al::isEqualString(animName.cstr(), mAnimFrameCtrl->getActionName());
}

bool PlayerAnimator::isCurrentAnimOneTime() const {
    return mAnimFrameCtrl->isActionOneTime();
}

f32 PlayerAnimator::getAnimFrame() const {
    return mAnimFrameCtrl->getCurrentFrame();
}

f32 PlayerAnimator::getAnimFrameMax() const {
    return mAnimFrameCtrl->getActionFrameMax();
}

f32 PlayerAnimator::getAnimFrameRate() const {
    return mAnimFrameCtrl->getRate();
}

void PlayerAnimator::clearInterpolation() {
    if (!mIsSubAnimPlaying)
        al::clearSklAnimInterpole(getCurrentModelActor(mModelHolder));
}

void PlayerAnimator::startSubAnim(const sead::SafeString& animName) {
    const PlayerModelHolder* modelHolder = mModelHolder;

    mIsSubAnimPlaying = true;
    mIsSubAnimOnlyAir = false;
    sead::FixedSafeString<64>* curSubAnim = &mCurSubAnim;
    al::LiveActor* normalModel = modelHolder->findModelActor("Normal");
    curSubAnim->format("%s%s", animName.cstr(), modelHolder->getAnimSuffix().cstr());
    if (!al::isExistAction(normalModel, curSubAnim->cstr()))
        curSubAnim->format("%s", animName.cstr());

    al::LiveActor* currentModel = getCurrentModelActor(mModelHolder);
    al::startAction(currentModel, curSubAnim->cstr());
    startPartsAnim(curSubAnim->cstr());
}

void PlayerAnimator::startSubAnimOnlyAir(const sead::SafeString& animName) {
    startSubAnim(animName);
    mIsSubAnimOnlyAir = true;
}

void PlayerAnimator::endSubAnim() {
    mIsSubAnimPlaying = false;
    mIsSubAnimOnlyAir = false;

    if (al::isEqualString(mCurAnim.cstr(), mCurSubAnim.cstr()))
        return;

    const char* actionName = mAnimFrameCtrl->getActionName();
    al::startAction(getCurrentModelActor(mModelHolder), actionName);
    startPartsAnim(actionName);
    setAnimRate(mAnimFrameCtrl->getRate());
    setAnimFrame(mAnimFrameCtrl->getCurrentFrame());
    applyBlendWeight();
}

void PlayerAnimator::applyBlendWeight() {
    if (!mIsBlendWeightEnabled)
        return;

    al::LiveActor* currentModel = getCurrentModelActor(mModelHolder);
    al::setSklAnimBlendWeightSixfold(currentModel, mSklAnimBlendWeights[0], mSklAnimBlendWeights[1],
                                     mSklAnimBlendWeights[2], mSklAnimBlendWeights[3],
                                     mSklAnimBlendWeights[4], mSklAnimBlendWeights[5]);
    const char* actionName = al::getActionName(currentModel);

    if (mIsUpperBodyAnimPlaying) {
        al::LiveActor* face = al::tryGetSubActor(currentModel, "顔");
        if (face != nullptr) {
            if (al::isActionPlaying(face, actionName)) {
                if (al::isSklAnimExist(face)) {
                    al::setSklAnimBlendWeightSixfold(
                        face, mSklAnimBlendWeights[0], mSklAnimBlendWeights[1],
                        mSklAnimBlendWeights[2], mSklAnimBlendWeights[3],
                        mSklAnimBlendWeights[4], mSklAnimBlendWeights[5]);
                }
            }
        }

        al::LiveActor* eye = al::tryGetSubActor(currentModel, "目");
        if (eye != nullptr) {
            if (al::isActionPlaying(eye, actionName)) {
                if (al::isSklAnimExist(eye)) {
                    al::setSklAnimBlendWeightSixfold(
                        eye, mSklAnimBlendWeights[0], mSklAnimBlendWeights[1],
                        mSklAnimBlendWeights[2], mSklAnimBlendWeights[3],
                        mSklAnimBlendWeights[4], mSklAnimBlendWeights[5]);
                }
            }
        }
        return;
    }

    for (s64 i = 0; i != 5; i++) {
        al::LiveActor* part = al::tryGetSubActor(currentModel, sAllBlendPartNames[i]);
        if (part != nullptr) {
            if (al::isActionPlaying(part, actionName)) {
                if (al::isSklAnimExist(part)) {
                    al::setSklAnimBlendWeightSixfold(
                        part, mSklAnimBlendWeights[0], mSklAnimBlendWeights[1],
                        mSklAnimBlendWeights[2], mSklAnimBlendWeights[3],
                        mSklAnimBlendWeights[4], mSklAnimBlendWeights[5]);
                }
            }
        }
    }
}

void PlayerAnimator::setSubAnimFrame(f32 frame) {
    setAnimFrameCommon(frame);
}

void PlayerAnimator::setSubAnimRate(f32 rate) {
    setAnimRateCommon(rate);
}

bool PlayerAnimator::isSubAnimEnd() const {
    if (!mIsSubAnimPlaying)
        return true;

    al::LiveActor* currentModel = getCurrentModelActor(mModelHolder);
    const char* actionName = al::getActionName(currentModel);
    if (al::isSklAnimExist(currentModel, actionName))
        return al::isActionEnd(currentModel);

    return al::isVisAnimEnd(currentModel);
}

bool PlayerAnimator::isSubAnim(const sead::SafeString& animName) const {
    return mIsSubAnimPlaying && al::isEqualString(animName.cstr(), mCurSubAnim.cstr());
}

f32 PlayerAnimator::getSubAnimFrame() const {
    return al::getActionFrame(getCurrentModelActor(mModelHolder));
}

f32 PlayerAnimator::getSubAnimFrameMax() const {
    return al::getActionFrameMax(getCurrentModelActor(mModelHolder));
}

bool PlayerAnimator::isUpperBodyAnimAttached() const {
    return al::isPartialSklAnimAttached(getCurrentModelActor(mModelHolder), 0);
}

bool PlayerAnimator::isUpperBodyAnimEnd() const {
    return al::isPartialSklAnimEnd(getCurrentModelActor(mModelHolder), 0);
}

bool PlayerAnimator::isUpperBodyAnim(const sead::SafeString& animName) const {
    return al::isPartialSklAnimPlaying(getCurrentModelActor(mModelHolder), animName.cstr(), 0);
}

void PlayerAnimator::startUpperBodyAnim(const sead::SafeString& animName) {
    const PlayerModelHolder* modelHolder = mModelHolder;
    sead::FixedSafeString<64>* upperBodyAnim = &mCurUpperBodyAnim;
    al::LiveActor* currentModel = modelHolder->getCurrentModelActor();
    al::LiveActor* normalModel = modelHolder->findModelActor("Normal");

    upperBodyAnim->format("%s%s", animName.cstr(), modelHolder->getAnimSuffix().cstr());
    if (!al::isExistAction(normalModel, upperBodyAnim->cstr()))
        upperBodyAnim->format("%s", animName.cstr());

    al::startPartialSklAnim(currentModel, upperBodyAnim->cstr(), 0, 0, nullptr);
    startPartsPartialAnim(upperBodyAnim->cstr());
    mIsUpperBodyAnimPlaying = true;
    mIsUpperBodyAnimHeadVisKeep = false;
}

void PlayerAnimator::startPartsPartialAnim(const sead::SafeString& animName) {
    al::LiveActor* currentModel = getCurrentModelActor(mModelHolder);
    al::LiveActor* head = al::tryGetSubActor(currentModel, "頭");
    if (head != nullptr)
        al::tryStartAction(head, animName.cstr());

    al::LiveActor* leftHand = al::tryGetSubActor(currentModel, "左手");
    if (leftHand != nullptr)
        al::tryStartAction(leftHand, animName.cstr());

    al::LiveActor* rightHand = al::tryGetSubActor(currentModel, "右手");
    if (rightHand != nullptr)
        al::tryStartAction(rightHand, animName.cstr());
}

void PlayerAnimator::startUpperBodyAnimSubParts(const sead::SafeString& animName) {
    const PlayerModelHolder* modelHolder = mModelHolder;
    sead::FixedSafeString<64>* upperBodyAnim = &mCurUpperBodyAnim;
    al::LiveActor* currentModel = modelHolder->getCurrentModelActor();
    al::LiveActor* normalModel = modelHolder->findModelActor("Normal");

    upperBodyAnim->format("%s%s", animName.cstr(), modelHolder->getAnimSuffix().cstr());
    if (!al::isExistAction(normalModel, upperBodyAnim->cstr()))
        upperBodyAnim->format("%s", animName.cstr());

    al::startPartialSklAnim(currentModel, upperBodyAnim->cstr(), 0, 1, nullptr);
    startPartsPartialAnim(upperBodyAnim->cstr());
    mIsUpperBodyAnimPlaying = true;
    mIsUpperBodyAnimHeadVisKeep = false;
}

void PlayerAnimator::startUpperBodyAnimAndHeadVisKeep(const sead::SafeString& animName) {
    startUpperBodyAnim(animName);
    mIsUpperBodyAnimHeadVisKeep = true;
}

void PlayerAnimator::clearUpperBodyAnim() {
    al::clearPartialSklAnimWithInterpolate(getCurrentModelActor(mModelHolder), 0, 5);

    al::LiveActor* currentModel = getCurrentModelActor(mModelHolder);

    const char* actionName = al::getActionName(currentModel);
    f32 actionFrame = al::getActionFrame(currentModel);
    f32 actionRate = al::getActionFrameRate(currentModel);
    bool keepHeadAction = al::isEqualString(actionName, _128.cstr());

    if (keepHeadAction) {
        al::LiveActor* head = al::tryGetSubActor(currentModel, "頭");
        if (head != nullptr && !al::isEqualString("頭", "頭")) {
            if (!al::tryStartAction(head, actionName))
                al::startAction(head, "Wait");
            setPartsAnimFrameAll(head, actionName, actionFrame);
            setPartsAnimRateAll(head, actionName, actionRate);
        }

        al::LiveActor* leftHand = al::tryGetSubActor(currentModel, "左手");
        if (leftHand != nullptr && !al::isEqualString("頭", "左手")) {
            if (!al::tryStartAction(leftHand, actionName))
                al::startAction(leftHand, "Wait");
            setPartsAnimFrameAll(leftHand, actionName, actionFrame);
            setPartsAnimRateAll(leftHand, actionName, actionRate);
        }

        al::LiveActor* rightHand = al::tryGetSubActor(currentModel, "右手");
        if (rightHand != nullptr && !al::isEqualString("頭", "右手")) {
            if (!al::tryStartAction(rightHand, actionName))
                al::startAction(rightHand, "Wait");
            setPartsAnimFrameAll(rightHand, actionName, actionFrame);
            setPartsAnimRateAll(rightHand, actionName, actionRate);
        }
    } else {
        al::LiveActor* head = al::tryGetSubActor(currentModel, "頭");
        if (head != nullptr) {
            if (!al::tryStartAction(head, actionName))
                al::startAction(head, "Wait");
            setPartsAnimFrameAll(head, actionName, actionFrame);
            setPartsAnimRateAll(head, actionName, actionRate);
        }

        al::LiveActor* leftHand = al::tryGetSubActor(currentModel, "左手");
        if (leftHand != nullptr) {
            if (!al::tryStartAction(leftHand, actionName))
                al::startAction(leftHand, "Wait");
            setPartsAnimFrameAll(leftHand, actionName, actionFrame);
            setPartsAnimRateAll(leftHand, actionName, actionRate);
        }

        al::LiveActor* rightHand = al::tryGetSubActor(currentModel, "右手");
        if (rightHand != nullptr) {
            if (!al::tryStartAction(rightHand, actionName))
                al::startAction(rightHand, "Wait");
            setPartsAnimFrameAll(rightHand, actionName, actionFrame);
            setPartsAnimRateAll(rightHand, actionName, actionRate);
        }
    }

    if (mIsUpperBodyAnimHeadVisKeep) {
        al::LiveActor* head = al::tryGetSubActor(currentModel, "頭");
        if (head != nullptr) {
            al::startVisAnimForAction(head, mCurUpperBodyAnim.cstr());
            al::setVisAnimFrameForAction(head, al::getVisAnimFrameMaxForAction(head));
        }
    }

    mIsUpperBodyAnimPlaying = false;
    mIsUpperBodyAnimHeadVisKeep = false;
}

void PlayerAnimator::setBlendWeight(f32 weight0, f32 weight1, f32 weight2, f32 weight3,
                                    f32 weight4, f32 weight5) {
    mSklAnimBlendWeights[0] = weight0;
    mSklAnimBlendWeights[1] = weight1;
    mSklAnimBlendWeights[2] = weight2;
    mSklAnimBlendWeights[3] = weight3;
    mSklAnimBlendWeights[4] = weight4;
    mSklAnimBlendWeights[5] = weight5;
    mIsBlendWeightEnabled = true;

    if (!mIsSubAnimPlaying)
        applyBlendWeight();
}

f32 PlayerAnimator::getBlendWeight(s32 index) {
    return mSklAnimBlendWeights[index];
}

void PlayerAnimator::startAnimDead() {
    if (al::getRandom(0, 20) != 0) {
        startAnim(sDeadAnimNames[al::getRandom(0, 2)]);
        return;
    }

    startAnim("Dead04");
}

void PlayerAnimator::startPress() {
    setAnimRate(0.0f);
    getCurrentModelActor(mModelHolder)->getActorActionKeeper()->tryStartActionNoAnim("Press");
}

void PlayerAnimator::forceCapOn() {
    al::LiveActor* head = al::tryGetSubActor(getNormalModelActor(mModelHolder), "頭");
    if (head != nullptr)
        al::startVisAnimForAction(head, "CapOn");
}

void PlayerAnimator::forceCapOff() {
    al::LiveActor* head = al::tryGetSubActor(getNormalModelActor(mModelHolder), "頭");
    if (head != nullptr)
        al::startVisAnimForAction(head, "CapOff");
}

f32 PlayerAnimator::getModelAlpha() const {
    return mDitherAnim->getDitherAlpha();
}

void PlayerAnimator::updateModelAlpha() {
    f32 alpha = 1.0f;
    if (mModelAlphaInvalidateCounter != 0) {
        mModelAlphaInvalidateCounter = al::converge(mModelAlphaInvalidateCounter, 0, 1);
        mDitherAnim->reset();
    } else {
        mDitherAnim->update();
        alpha = mDitherAnim->getDitherAlpha();
    }

    setModelAlpha(alpha);
}

void PlayerAnimator::setModelAlpha(f32 alpha) {
    al::LiveActor* currentModel = getCurrentModelActor(mModelHolder);
    al::setModelAlphaMask(currentModel, alpha);

    al::LiveActor* face = al::tryGetSubActor(currentModel, "顔");
    if (face != nullptr)
        al::setModelAlphaMask(face, al::getModelAlphaMask(currentModel));

    al::LiveActor* eye = al::tryGetSubActor(currentModel, "目");
    if (eye != nullptr)
        al::setModelAlphaMask(eye, al::getModelAlphaMask(currentModel));

    al::LiveActor* head = al::tryGetSubActor(currentModel, "頭");
    if (head != nullptr)
        al::setModelAlphaMask(head, al::getModelAlphaMask(currentModel));

    al::LiveActor* leftHand = al::tryGetSubActor(currentModel, "左手");
    if (leftHand != nullptr)
        al::setModelAlphaMask(leftHand, al::getModelAlphaMask(currentModel));

    al::LiveActor* rightHand = al::tryGetSubActor(currentModel, "右手");
    if (rightHand != nullptr)
        al::setModelAlphaMask(rightHand, al::getModelAlphaMask(currentModel));
}

void PlayerAnimator::resetModelAlpha() {
    mDitherAnim->reset();
    setModelAlpha(1.0f);
}

void PlayerAnimator::endDemoInvalidateModelAlpha() {
    mModelAlphaInvalidateCounter =
        mModelAlphaInvalidateCounter > 1 ? mModelAlphaInvalidateCounter : 1;
}

void PlayerAnimator::startSnapShotMode() {
    mDitherAnim->setClippingJudgeDistanceParam("SnapShotMode");
}

void PlayerAnimator::endSnapShotMode() {
    mDitherAnim->resetClippingJudgeDistanceParam();
}

void PlayerAnimator::startEyeControlAnim(bool isKeep) {
    mIsEyeControlAnim = true;
    _1a6 = isKeep;
    mEndEyeControlAnimDelay = 0;
}

void PlayerAnimator::endEyeControlAnim(s32 delay) {
    mIsEyeControlAnim = false;
    _1a6 = false;
    mEndEyeControlAnimDelay = delay;

    if (delay == 0) {
        al::LiveActor* currentModel = mModelHolder->getCurrentModelActor();
        const char* actionName = al::getActionName(currentModel);
        f32 actionFrame = al::getActionFrame(currentModel);
        f32 actionRate = al::getActionFrameRate(currentModel);
        al::LiveActor* eye = al::tryGetSubActor(currentModel, "目");

        if (eye == nullptr)
            return;

        if (al::tryStartAction(eye, actionName)) {
            setPartsAnimRateAll(eye, actionName, actionRate);
            setPartsAnimFrameAll(eye, actionName, actionFrame);
        } else {
            al::startAction(eye, "Wait");
        }

        if (al::isMtsAnimPlaying(eye, "EyeMove"))
            al::startMtsAnim(eye, "EyeReset");
    }
}

void PlayerAnimator::clearEndEyeControlAnimDelay() {
    if (mEndEyeControlAnimDelay < 1)
        return;

    mEndEyeControlAnimDelay = 0;
    restoreEyeControlAnim(mModelHolder->getCurrentModelActor());
}

void PlayerAnimator::updateEyeControlAnim() {
    if (mIsEyeControlAnim) {
        f32 eyeControlAnimFrame = mEyeControlAnimFrame;
        al::LiveActor* eye = al::tryGetSubActor(mModelHolder->getCurrentModelActor(), "目");
        if (eye != nullptr) {
            if (al::isMtsAnimExist(eye, "EyeMove"))
                al::startMtsAnimAndSetFrameAndStop(eye, "EyeMove", eyeControlAnimFrame);
        }
    } else if (mEndEyeControlAnimDelay >= 1) {
        mEndEyeControlAnimDelay = al::converge(mEndEyeControlAnimDelay, 0, 1);
        if (mEndEyeControlAnimDelay == 0)
            restoreEyeControlAnim(mModelHolder->getCurrentModelActor());
    }
}

void PlayerAnimator::startRightHandAnim(const char* animName) {
    al::LiveActor* rightHand = al::tryGetSubActor(getCurrentModelActor(mModelHolder), "右手");
    if (rightHand != nullptr)
        al::startAction(rightHand, animName);
}

void PlayerAnimator::overwrideYoshiEatVis() {
    al::tryStartVisAnimIfNotPlayingForAction(getCurrentModelActor(mModelHolder), "Eat");
}

void PlayerAnimator::restartYoshiActionVis() {
    if (*mCurAnim.getStringTop() == sead::SafeStringBase<char>::cNullChar)
        return;

    al::LiveActor* currentModel = getCurrentModelActor(mModelHolder);
    al::startVisAnimForAction(currentModel, "Wait");
    if (!al::tryStartVisAnimIfExistForAction(currentModel, mCurAnim.cstr()))
        return;

    f32 actionFrame = al::getActionFrameMax(currentModel);
    f32 visFrame = al::getVisAnimFrameMaxForAction(currentModel);
    if (!(actionFrame > visFrame))
        visFrame = actionFrame;
    al::setVisAnimFrameForAction(currentModel, visFrame);
}

f32 PlayerAnimator::getMario3DWaitFrameMax() const {
    return al::getSklAnimFrameMax(getNormalModelActor(mModelHolder), "Wait");
}

f32 PlayerAnimator::getRunStartAnimFrameMax() const {
    return al::getSklAnimFrameMax(getCurrentModelActor(mModelHolder), "RunStart");
}

f32 PlayerAnimator::getRunStartAnimBlendRate() const {
    return mRunStartAnimRate;
}

void PlayerAnimator::recordRunStartAnimRate(f32 rate) {
    mRunStartAnimRate = rate;
}

void PlayerAnimator::calcModelJointRootMtx(sead::Matrix34f* jointRootMtx) const {
    *jointRootMtx = *al::getJointMtxPtr(getCurrentModelActor(mModelHolder), "JointRoot");
}

void PlayerAnimator::startPartsAnim(const sead::SafeString& animName) {
    al::LiveActor* currentModel = getCurrentModelActor(mModelHolder);
    bool isUpperBodyAnimPlaying = mIsUpperBodyAnimPlaying;
    al::LiveActor* face = al::tryGetSubActor(currentModel, "顔");
    const char* partName = "目";

    if (isUpperBodyAnimPlaying) {
        if (face != nullptr) {
            if (!al::tryStartAction(face, animName.cstr()))
                al::startAction(face, "Wait");
        }
    } else {
        if (face != nullptr) {
            if (!al::tryStartAction(face, animName.cstr()))
                al::startAction(face, "Wait");
        }

        al::LiveActor* eye = al::tryGetSubActor(currentModel, "目");
        if (eye != nullptr) {
            if (!al::tryStartAction(eye, animName.cstr()))
                al::startAction(eye, "Wait");
        }

        al::LiveActor* head = al::tryGetSubActor(currentModel, "頭");
        if (head != nullptr) {
            if (!al::tryStartAction(head, animName.cstr()))
                al::startAction(head, "Wait");
        }

        al::LiveActor* leftHand = al::tryGetSubActor(currentModel, "左手");
        if (leftHand != nullptr) {
            if (!al::tryStartAction(leftHand, animName.cstr()))
                al::startAction(leftHand, "Wait");
        }
        partName = "右手";
    }

    al::LiveActor* part = al::tryGetSubActor(currentModel, partName);
    if (part != nullptr) {
        if (!al::tryStartAction(part, animName.cstr()))
            al::startAction(part, "Wait");
    }

    if (mIsNeedFullFaceAnim) {
        face = al::tryGetSubActor(currentModel, "顔");
        if (face != nullptr) {
            al::StringTmp<128> fullFaceAnim("%sFullFace", animName.cstr());
            al::tryStartAction(face, fullFaceAnim.cstr());
        }
    }

    if (mPlayerDeco != nullptr && !al::tryStartAction(mPlayerDeco, animName.cstr()))
        al::startAction(mPlayerDeco, "Wait");
}

void PlayerAnimator::setPartsAnimRate(f32 rate, const char* actionName) {
    al::LiveActor* currentModel = getCurrentModelActor(mModelHolder);
    bool isUpperBodyAnimPlaying = mIsUpperBodyAnimPlaying;
    al::LiveActor* face = al::tryGetSubActor(currentModel, "顔");

    if (isUpperBodyAnimPlaying) {
        if (face != nullptr)
            setPartsAnimRateAll(face, actionName, rate);

        al::LiveActor* eye = al::tryGetSubActor(currentModel, "目");
        if (eye != nullptr)
            setPartsAnimRateAll(eye, actionName, rate);
    } else {
        if (face != nullptr)
            setPartsAnimRateAll(face, actionName, rate);

        al::LiveActor* eye = al::tryGetSubActor(currentModel, "目");
        if (eye != nullptr)
            setPartsAnimRateAll(eye, actionName, rate);

        al::LiveActor* head = al::tryGetSubActor(currentModel, "頭");
        if (head != nullptr)
            setPartsAnimRateAll(head, actionName, rate);

        al::LiveActor* leftHand = al::tryGetSubActor(currentModel, "左手");
        if (leftHand != nullptr)
            setPartsAnimRateAll(leftHand, actionName, rate);

        al::LiveActor* rightHand = al::tryGetSubActor(currentModel, "右手");
        if (rightHand != nullptr)
            setPartsAnimRateAll(rightHand, actionName, rate);
    }

    if (mPlayerDeco != nullptr)
        setPartsAnimRateAll(mPlayerDeco, actionName, rate);
}

void PlayerAnimator::setPartsAnimFrame(f32 frame, const char* actionName) {
    al::LiveActor* currentModel = getCurrentModelActor(mModelHolder);
    bool isUpperBodyAnimPlaying = mIsUpperBodyAnimPlaying;
    al::LiveActor* face = al::tryGetSubActor(currentModel, "顔");

    if (isUpperBodyAnimPlaying) {
        if (face != nullptr)
            setPartsAnimFrameAll(face, actionName, frame);

        al::LiveActor* eye = al::tryGetSubActor(currentModel, "目");
        if (eye != nullptr)
            setPartsAnimFrameAll(eye, actionName, frame);
    } else {
        if (face != nullptr)
            setPartsAnimFrameAll(face, actionName, frame);

        al::LiveActor* eye = al::tryGetSubActor(currentModel, "目");
        if (eye != nullptr)
            setPartsAnimFrameAll(eye, actionName, frame);

        al::LiveActor* head = al::tryGetSubActor(currentModel, "頭");
        if (head != nullptr)
            setPartsAnimFrameAll(head, actionName, frame);

        al::LiveActor* leftHand = al::tryGetSubActor(currentModel, "左手");
        if (leftHand != nullptr)
            setPartsAnimFrameAll(leftHand, actionName, frame);

        al::LiveActor* rightHand = al::tryGetSubActor(currentModel, "右手");
        if (rightHand != nullptr)
            setPartsAnimFrameAll(rightHand, actionName, frame);
    }

    if (mPlayerDeco != nullptr)
        setPartsAnimFrameAll(mPlayerDeco, actionName, frame);
}

void PlayerAnimator::copyAnimLocal() {
    al::LiveActor* currentModel = getCurrentModelActor(mModelHolder);
    const char* fallbackAnim = "Jump";
    bool isStartWithString = al::isStartWithString(mCurAnim.cstr(), "Jump");
    if (!isStartWithString)
        fallbackAnim = "Wait";

    if (mIsSubAnimPlaying) {
        if (al::isExistAction(currentModel, mCurSubAnim.cstr())) {
            al::startAction(currentModel, mCurSubAnim.cstr());
            startPartsAnim(mCurSubAnim.cstr());
            setAnimRateCommon(al::getActionFrameRate(mPlayer));
            setAnimFrameCommon(al::getActionFrame(mPlayer));

            if (!al::isExistAction(currentModel, mCurAnim.cstr())) {
                mCurAnim = fallbackAnim;
                mAnimFrameCtrl->startAction(currentModel, mCurAnim);
            }
        } else {
            mIsSubAnimPlaying = false;
            if (al::isExistAction(currentModel, mCurAnim.cstr())) {
                mAnimFrameCtrl->startAction(currentModel, mCurAnim);
                al::startAction(currentModel, mCurAnim.cstr());
                startPartsAnim(mCurAnim.cstr());
                setAnimRateCommon(al::getActionFrameRate(mPlayer));
                setAnimFrameCommon(al::getActionFrame(mPlayer));
            } else {
                mCurAnim = fallbackAnim;
                mAnimFrameCtrl->startAction(currentModel, mCurAnim);
                al::startAction(currentModel, mCurAnim.cstr());
                startPartsAnim(mCurAnim.cstr());
                setAnimRateCommon(1.0f);
            }
        }
    } else {
        if (al::isExistAction(currentModel, mCurAnim.cstr())) {
            mAnimFrameCtrl->startAction(currentModel, mCurAnim);
            al::startAction(currentModel, mCurAnim.cstr());
            startPartsAnim(mCurAnim.cstr());
            setAnimRateCommon(al::getActionFrameRate(mPlayer));
            setAnimFrameCommon(al::getActionFrame(mPlayer));
        } else {
            mCurAnim = fallbackAnim;
            mAnimFrameCtrl->startAction(currentModel, mCurAnim);
            al::startAction(currentModel, mCurAnim.cstr());
            startPartsAnim(mCurAnim.cstr());
            setAnimRateCommon(1.0f);
        }

        if (isStartWithString) {
            f32 frame = al::getActionFrameMax(currentModel);
            mAnimFrameCtrl->setFrame(frame);
            if (!mIsSubAnimPlaying)
                setAnimFrameCommon(frame);

            if (currentModel->getEffectKeeper() != nullptr)
                al::tryDeleteEffect(currentModel, "Jump");
        }
    }

    al::clearSklAnimInterpole(currentModel);
}
