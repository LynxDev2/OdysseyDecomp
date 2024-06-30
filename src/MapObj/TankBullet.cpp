
#include "MapObj/TankBullet.h"

#include <prim/seadSafeString.h>

#include "Library/LiveActor/ActorActionFunction.h"
#include "Library/LiveActor/ActorClippingFunction.h"
#include "Library/LiveActor/ActorCollisionFunction.h"
#include "Library/LiveActor/ActorInitInfo.h"
#include "Library/LiveActor/ActorMovementFunction.h"
#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/LiveActor/ActorSensorFunction.h"
#include "Library/LiveActor/ActorSensorMsgFunction.h"
#include "Library/Nerve/NerveSetupUtil.h"
#include "Library/Nerve/NerveUtil.h"
#include "Project/HitSensor/HitSensor.h"
#include "Library/Math/MathAngleUtil.h"

#include "Util/Sensor.h"

namespace {
NERVE_IMPL(TankBullet, Move);
NERVE_IMPL(TankBullet, Start);
NERVE_IMPL(TankBullet, YoshiEat);
NERVE_IMPL(TankBullet, Explode);
NERVE_IMPL(TankBullet, MovePlayer);

NERVE_MAKE(TankBullet, Move);

NERVES_MAKE_STRUCT(TankBullet, Start, YoshiEat, Explode, MovePlayer)

}

TankBullet::TankBullet(const char* name) : al::LiveActor(name) {}

void TankBullet::init(const al::ActorInitInfo& initInfo) {
    al::initActorWithArchiveName(this, initInfo, sead::SafeString("TankBullet"), nullptr);
    al::initNerve(this, &NrvTankBullet.Start, 0);
    al::invalidateClipping(this);
    al::invalidateHitSensor(this, "Explosion");
    al::invalidateHitSensor(this, "ExplosionWide");
    makeActorDead();
}

void TankBullet::explode() {
    al::startAction(this, "Explode");
    al::startHitReaction(this, "爆発");
    al::setVelocityZero(this);
    al::validateHitSensor(this, "Explosion");
    al::validateHitSensor(this, "ExplosionWide");
    al::setNerve(this, &NrvTankBullet.Explode);
}

// NON MATCHING

void TankBullet::attackSensor(al::HitSensor* target, al::HitSensor* source) {
    if ((al::isNerve(this, &NrvTankBullet.Start) || al::isNerve(this, &NrvTankBullet.YoshiEat) ||
         mIsShotByPlayer) &&
        !al::isSensorEye(target) && al::isSensorMapObj(source) &&
        rs::sendMsgWeaponItemGet(source, target))
        return;

    if (al::isNerve(this, &NrvTankBullet.Explode) && al::isSensorEye(target)) {
        if (al::isSensorName(target, "Explosion")) {
            if (!mIsCapAttack || !al::isSensorPlayer(source))
                al::sendMsgExplosion(source, target, nullptr);
        } else if (mIsShotByPlayer && al::isSensorName(target, "ExplosionWide")) {
            rs::sendMsgTankExplosion(source, target);
        }
        return;
    }
    if (!mIsShotByPlayer) {
        if (!al::sendMsgExplosion(source, target, nullptr))
            return;
        explode();
        return;
    }
    if (rs::sendMsgTankBulletNoReaction(source, target)) {
        kill();
        return;
    }
        if (rs::sendMsgTankBullet(source, target) || al::sendMsgExplosion(source, target, nullptr)) {
        if (al::isExistCollisionParts(al::getSensorHost(source)) &&
            al::isValidCollisionParts(al::getSensorHost(source)))
            al::startHitReaction(this, "キャプチャショット壁あたり");
        else
            al::startHitReaction(this, "キャプチャショットオブジェあたり");
        explode();
    }
}

void TankBullet::appear(){
    al::setScaleAll(this, 1.0f);
    mIsCapAttack = false;
    al::LiveActor::appear();
}

void TankBullet::disappear(){
    kill();
}

bool TankBullet::receiveMsg(const al::SensorMsg* message, al::HitSensor* source,
                    al::HitSensor* target){
    if(rs::isMsgPlayerDisregardTargetMarker(message))
        return true;

    if(al::isNerve(this, &NrvTankBullet.Explode))
        return false;

    if(rs::isMsgYoshiTongueEatBind(message) && !al::isNerve(this, &NrvTankBullet.YoshiEat)){
        rs::setMsgYoshiTongueEatBindRadiusAndOffset(message, .0f, .0f);
        rs::requestHitReactionToAttacker(message, target, source);
        al::setNerve(this, &NrvTankBullet.YoshiEat);
        return true;
    }

    if(rs::isMsgYoshiTongueEatBindFinish(message)){
        rs::requestHitReactionToAttacker(message, target, source);
        kill();
        return true;
    }

    if(rs::isMsgYoshiTongueEatBindCancel(message)){
        kill();
        return true;
    }

    if(al::isNerve(this, &NrvTankBullet.YoshiEat))
        return false;

    if(rs::isMsgBlowDown(message) || rs::isMsgCapAttack(message)){
        if(mIsShotByPlayer && rs::isMsgCapAttack(message))
            return false;
        rs::requestHitReactionToAttacker(message, target, source);
        if(rs::isMsgCapAttack(message))
            mIsCapAttack = true;
        if(!rs::isMsgMotorcycleDashAttack(message)){
            explode();
            return true;
        }
    }
    return false;
}

void TankBullet::shoot(const sead::Vector3f& startingPos,
        const sead::Vector3f& bulletVelocity,
        int unusedInt,
        bool isShotByPlayer,
        bool unusedBool){

    mIsShotByPlayer = isShotByPlayer;
    al::setTrans(this, startingPos);
    al::setVelocity(this, bulletVelocity);
    mUnusedInt = unusedInt;
    al::setSensorRadius(this, "Explosion", .0f);
    al::startAction(this, "Appear");
    sead::Vector3f front = bulletVelocity;
    al::tryNormalizeOrZero(&front);
    al::setFront(this, front);
    al::setNerve(this, &NrvTankBullet.Start);
    if (isShotByPlayer){
        al::validateHitSensor(this, "Body");
        al::invalidateHitSensor(this, "Attack");
    }
    else{
        al::invalidateHitSensor(this, "Body");
        al::validateHitSensor(this, "Attack");
    }
    appear();
}

void TankBullet::exeStart(){
    if(al::isGreaterStep(this, -1))
        al::setNerve(this, &Move);
}
