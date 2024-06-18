
#include "MapObj/TankBullet.h"

#include <prim/seadSafeString.h>

#include "Library/LiveActor/ActorActionFunction.h"
#include "Library/LiveActor/ActorClippingFunction.h"
#include "Library/LiveActor/ActorCollisionFunction.h"
#include "Library/LiveActor/ActorInitInfo.h"
#include "Library/LiveActor/ActorMovementFunction.h"
#include "Library/LiveActor/ActorSensorFunction.h"
#include "Library/LiveActor/ActorSensorMsgFunction.h"
#include "Library/Nerve/NerveSetupUtil.h"
#include "Library/Nerve/NerveUtil.h"
#include "Project/HitSensor/HitSensor.h"

#include "Util/Sensor.h"

namespace {
NERVE_IMPL(TankBullet, Move);
NERVE_IMPL(TankBullet, Start);
NERVE_IMPL(TankBullet, YoshiEat);
NERVE_IMPL(TankBullet, Explode);
NERVE_IMPL(TankBullet, MovePlayer);

NERVE_MAKE(TankBullet, Move);
struct {
    NERVE_MAKE(TankBullet, Start);
    NERVE_MAKE(TankBullet, YoshiEat);
    NERVE_MAKE(TankBullet, Explode);
    NERVE_MAKE(TankBullet, MovePlayer);
} NrvTankBullet;
}  // namespace

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


