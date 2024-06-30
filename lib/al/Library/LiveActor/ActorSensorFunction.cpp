#include "Library/LiveActor/ActorSensorFunction.h"

#include "Library/HitSensor/HitSensorKeeper.h"
#include "Library/LiveActor/ActorInitInfo.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/LiveActor/LiveActor.h"
#include "Project/HitSensor/HitSensor.h"
#include "math/seadMatrix.h"
#include "math/seadVectorFwd.h"

#define ADD_SENSOR_WITH_TYPE_FUNCTION(type)                                                        \
    HitSensor* addHitSensor##type(al::LiveActor* actor, const ActorInitInfo& initInfo,             \
                                  const char* name, f32 radius, u16 maxSensorCount,                \
                                  const sead::Vector3f& offset) {                                  \
        return addHitSensor(actor, initInfo, name, (u32)HitSensorType::type, radius,               \
                            maxSensorCount, offset);                                               \
    }

namespace al {
// Too much auto?
HitSensor* addHitSensor(al::LiveActor* actor, const ActorInitInfo& initInfo, const char* name,
                        u32 hitSensorType, f32 radius, u16 maxSensorCount,
                        const sead::Vector3f& offset) {
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    auto* actorTrans = al::getTransPtr(actor);
    auto* sensor = sensorKeeper->addSensor(actor, name, hitSensorType, radius, maxSensorCount,
                                           actorTrans, nullptr, offset);
    initInfo.getHitSensorDirector()->initGroup(sensor);
    return sensor;
}

// Use a FOR_EACH with no first arg for cleaner code or no macro?
ADD_SENSOR_WITH_TYPE_FUNCTION(Player);
ADD_SENSOR_WITH_TYPE_FUNCTION(PlayerAttack);
ADD_SENSOR_WITH_TYPE_FUNCTION(PlayerEye);
ADD_SENSOR_WITH_TYPE_FUNCTION(Enemy);
ADD_SENSOR_WITH_TYPE_FUNCTION(EnemyBody);
ADD_SENSOR_WITH_TYPE_FUNCTION(EnemyAttack);
ADD_SENSOR_WITH_TYPE_FUNCTION(MapObj);
ADD_SENSOR_WITH_TYPE_FUNCTION(Bindable);
ADD_SENSOR_WITH_TYPE_FUNCTION(BindableGoal);
ADD_SENSOR_WITH_TYPE_FUNCTION(BindableAllPlayer);
ADD_SENSOR_WITH_TYPE_FUNCTION(BindableBubbleOutScreen);
ADD_SENSOR_WITH_TYPE_FUNCTION(BindableKoura);
ADD_SENSOR_WITH_TYPE_FUNCTION(BindableRouteDokan);
ADD_SENSOR_WITH_TYPE_FUNCTION(BindableBubblePadInput);
ADD_SENSOR_WITH_TYPE_FUNCTION(CollisionParts);
ADD_SENSOR_WITH_TYPE_FUNCTION(Eye);

void setHitSensorPosPtr(LiveActor* actor, const char* name, const sead::Vector3f* posPtr) {
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    auto* sensor = sensorKeeper->getSensor(name);
    sensor->setFollowPosPtr(posPtr);
}

HitSensor* getHitSensor(const LiveActor* actor, const char* name) {
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    return sensorKeeper->getSensor(name);
}

void setHitSensorMtxPtr(LiveActor* actor, const char* name, const sead::Matrix34f* mtxPtr) {
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    auto* sensor = sensorKeeper->getSensor(name);
    sensor->setFollowMtxPtr(mtxPtr);
}

void setHitSensorJointMtx(LiveActor* actor, const char* name, const char* jointName) {
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    auto* sensor = sensorKeeper->getSensor(name);
    auto* actorJointMtx = al::getJointMtxPtr(actor, jointName);
    sensor->setFollowMtxPtr(actorJointMtx);
}

void setSensorRadius(LiveActor* actor, const char* name, float radius) {
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    auto* sensor = sensorKeeper->getSensor(name);
    sensor->setRadius(radius);
}

void setSensorRadius(LiveActor* actor, float radius) {
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    auto* sensor = sensorKeeper->getSensor(0);
    sensor->setRadius(radius);
}

f32 getSensorRadius(const LiveActor* actor, const char* name) {
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    return sensorKeeper->getSensor(name)->getRadius();
}

f32 getSensorRadius(const LiveActor* actor) {
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    // Nullptr, because it needs to use a 64-bit register to match
    return sensorKeeper->getSensor(nullptr)->getRadius();
}

const sead::Vector3f& getSensorPos(const LiveActor* actor, const char* name) {
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    return sensorKeeper->getSensor(name)->getPos();
}

const sead::Vector3f& getSensorPos(const LiveActor* actor) {
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    // Same as above
    return sensorKeeper->getSensor(nullptr)->getPos();
}
/*
void setSensorFollowPosOffset(LiveActor* actor, const char* name, const sead::Vector3f& offset){
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    sensorKeeper->getSensor(name)->setOffset(&offset);
}

void setSensorFollowPosOffset(LiveActor* actor, const sead::Vector3f& offset){
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    sensorKeeper->getSensor(0)->setOffset(&offset);
}
*/

const sead::Vector3f& getSensorFollowPosOffset(const LiveActor* actor, const char* name) {
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    return sensorKeeper->getSensor(name)->getOffset();
}

const sead::Vector3f& getSensorFollowPosOffset(const LiveActor* actor) {
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    return sensorKeeper->getSensor(nullptr)->getOffset();
}

}  // namespace al
