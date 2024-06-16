
#include "MapObj/TankBullet.h"

#include <prim/seadSafeString.h>

#include "Library/LiveActor/ActorClippingFunction.h"
#include "Library/LiveActor/ActorInitInfo.h"
#include "Library/LiveActor/ActorSensorFunction.h"

TankBullet::TankBullet(const char* name) : al::LiveActor(name){}

void TankBullet::init(const al::ActorInitInfo& initInfo){
    al::initActorWithArchiveName(this, initInfo, sead::SafeString("TankBullet"), nullptr);
    al::initNerve(this, nullptr, 0);
    al::invalidateClipping(this);
    al::invalidateHitSensor(this, "Explosion");
    al::invalidateHitSensor(this, "ExplosionWide");
    makeActorDead();
}
