#pragma once

#include <basis/seadTypes.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

#include "Util/IUseDimension.h"

class ActorDimensionKeeper;

class Shine : public al::LiveActor, public IUseDimension {
public:
    Shine(const char* name);
    void init(const al::ActorInitInfo& info) override;
    s64 getCurrentModel();
    bool tryExpandShadowAndClipping();
    void initAppearDemo(const al::ActorInitInfo& info);
    void onAppear();
    void offAppear();
    void hideAllModel();
    void invalidateKillSensor();
    void initAfterPlacement() override;
    void getDirect();
    void updateHintTrans(const sead::Vector3f& hintTrans) const;
    void appear() override;
    void makeActorAlive() override;
    void makeActorDead() override;
    void control() override;
    void updateModelActorPose();
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void showCurrentModel();
    void appearPopup();
    void addDemoActorWithModel();
    s64 get();
    void endClipped() override;
    void initAppearDemoFromHost(const al::ActorInitInfo& info, const sead::Vector3f& hostTrans);
    void initAppearDemoFromHost(const al::ActorInitInfo& info);
    void initAppearDemoActorCamera(const al::ActorInitInfo& info);
    void createShineEffectInsideObject(const al::ActorInitInfo& info,
                                       const sead::Vector3f& effectOffset, const char* modelName);
    bool isGot() const;
    bool isEmptyShineForDemoGetGrand() const;
    void setShopShine();
    bool isEndAppear() const;
    bool isEndAppearGK() const;
    void onSwitchGet();
    s64 getColorFrame() const;
    void setHintPhotoShine(const al::ActorInitInfo& info);
    bool appearCommon();
    bool tryChangeCoin();
    bool tryAppearOrDemoAppear();
    void appearPopup(const sead::Vector3f& trans);
    void appearPopupDelay(s32 delayFrame);
    void appearPopupSlot(const sead::Vector3f& trans);
    void appearWarp(const sead::Vector3f& trans, const sead::Vector3f& warpTrans);
    void appearStatic();
    void appearPopupWithoutDemo();
    void appearPopupGrandByBoss(s32 delayFrame);
    void appearPopupWithoutWarp();
    void appearAndJoinBossDemo(const char* demoName, const sead::Quatf& quat,
                               const sead::Vector3f& trans);
    void endBossDemo();
    void endBossDemoAndStartFall(f32 fallSpeed);
    void appearWait();
    void appearWait(const sead::Vector3f& trans);
    void startHold();
    void startFall();
    const sead::Vector3f& getDirectWithDemo();
    void addDemoModelActor();
    void setGrandShine();
    void exeWaitRequestDemo();
    void exeWaitKill();
    void exeDemoAppear();
    bool tryWaitCameraInterpole() const;
    bool tryStartAppearDemo();
    s64 calcCameraAt();
    void exeDemoMove();
    void updateIgnoreFrame();
    void exeDemoWait();
    void exeDemoGet();
    void exeDemoGetMain();
    void exeDemoGetGrand();
    void exeBossDemo();
    void exeBossDemoAfterFall();
    void exeBossDemoAfterLanding();
    void exeBossDemoFall();
    void exeBossDemoFallSlowdown();
    void exeBossDemoRise();
    void exeBossDemoRiseDamp();
    void exeAppearSlot();
    void exeAppearSlotDown();
    void exeAppear();
    void exeAppearWait();
    void exeAppearDown();
    void exeAppearStatic();
    void exeAppearEnd();
    void exeAppearWaitCameraInterpole();
    void exeWait();
    void exeGot();
    void exeHold();
    void exeFall();
    void exeDelay();
    void exeHide();
    void exeReaction();
    void exeCoin();
    void updateModelActorResetPosition();
    ActorDimensionKeeper* getActorDimensionKeeper() const override;

    const sead::Vector3f& get_16c() { return _16c; }

    void set_16c(const sead::Vector3f& newValue) { _16c.set(newValue); }

    bool isMainShine() const { return mIsMainShine; }

private:
    char filler_110[92];
    sead::Vector3f _16c;
    void* filler[35];
    s32 filler2;
    bool mIsMainShine;
    void* filler3[29];
};

static_assert(sizeof(Shine) == 0x380);
static_assert(sizeof(Shine) == 0x380);

namespace ShineFunction {
const char* getMovePointLinkName();
}
