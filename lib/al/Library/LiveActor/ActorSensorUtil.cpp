#include "Library/LiveActor/ActorSensorUtil.h"

#include "Library/Base/StringUtil.h"
#include "Library/HitSensor/HitSensorKeeper.h"
#include "Project/HitSensor/HitSensorDirector.h"
#include "Library/LiveActor/ActorInitInfo.h"
#include "Library/LiveActor/ActorModelFunction.h"
#include "Library/LiveActor/ActorMovementFunction.h"
#include "Library/LiveActor/ActorPoseKeeper.h"
#include "Library/LiveActor/ActorSensorController.h"
#include "Library/LiveActor/LiveActor.h"
#include "Project/HitSensor/HitSensor.h"
#include "Library/LiveActor/ActorSensorController.h"
#include "Library/LiveActor/ActorFlagFunction.h"
#include "Library/Math/MathUtil.h"
#include "Library/LiveActor/ActorSensorFunction.h"

#define ADD_SENSOR_WITH_TYPE_FUNCTION(type)                                                        \
    HitSensor* addHitSensor##type(al::LiveActor* actor, const ActorInitInfo& initInfo,             \
                                  const char* name, f32 radius, u16 maxSensorCount,                \
                                  const sead::Vector3f& offset) {                                  \
        return addHitSensor(actor, initInfo, name, (u32)HitSensorType::type, radius,               \
                            maxSensorCount, offset);                                               \
    }

namespace al {
HitSensor* addHitSensor(al::LiveActor* actor, const ActorInitInfo& initInfo, const char* name,
                        u32 hitSensorType, f32 radius, u16 maxSensorCount,
                        const sead::Vector3f& offset) {
    al::HitSensorKeeper* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    sead::Vector3f* actorTrans = al::getTransPtr(actor);
    al::HitSensor* sensor = sensorKeeper->addSensor(actor, name, hitSensorType, radius, maxSensorCount,
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
    // All of these use a nullptr, because they need to use a 64-bit register to match
    return sensorKeeper->getSensor(nullptr)->getRadius();
}

const sead::Vector3f& getSensorPos(const LiveActor* actor, const char* name) {
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    return sensorKeeper->getSensor(name)->getPos();
}

const sead::Vector3f& getSensorPos(const LiveActor* actor) {
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    return sensorKeeper->getSensor(nullptr)->getPos();
}

void setSensorFollowPosOffset(LiveActor* actor, const char* name, const sead::Vector3f& offset){
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    sensorKeeper->getSensor(name)->setFollowPosOffset(offset);
}

void setSensorFollowPosOffset(LiveActor* actor, const sead::Vector3f& offset){
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    sensorKeeper->getSensor(nullptr)->setFollowPosOffset(offset);
}


const sead::Vector3f& getSensorFollowPosOffset(const LiveActor* actor, const char* name) {
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    return sensorKeeper->getSensor(name)->getFollowPosOffset();
}

const sead::Vector3f& getSensorFollowPosOffset(const LiveActor* actor) {
    auto* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    return sensorKeeper->getSensor(nullptr)->getFollowPosOffset();
}

ActorSensorController* createActorSensorController(al::LiveActor* actor, const char* sensorName){
    return new ActorSensorController(actor, sensorName);
}

void setSensorRadius(ActorSensorController* controller, f32 radius){
    controller->setSensorRadius(radius);
}

void setSensorScale(ActorSensorController* controller, f32 scale){
    controller->setSensorScale(scale);
}

void setSensorFollowPosOffset(ActorSensorController* controller, const sead::Vector3f& offset){
    controller->setSensorFollowPosOffset(offset);
}

f32 getOriginalSensorRadius(const ActorSensorController* controller){
    return controller->getSensorRadius();
}

const sead::Vector3f& getOriginalSensorFollowPosOffset(const ActorSensorController* controller){
    return controller->getSensorFollowPosOffset();
}

void resetActorSensorController(ActorSensorController* controller){
    controller->resetActorSensorController();
}

void calcPosBetweenSensors(sead::Vector3f* pos, const HitSensor* sensor1, const HitSensor* sensor2, f32 pFloat){
    sead::Vector3f sensor1Pos = sensor1->getPos();
    sead::Vector3f sensor2Pos = sensor2->getPos();
    sead::Vector3f difference = sensor1Pos - sensor2Pos;
    if(al::isNearZero(difference, 0.001f)){
        *pos = sensor1Pos;
        return;
    }
    al::normalize(&difference);
    f32 combinedRadius = sensor1->getRadius() + sensor2->getRadius();
    f32 res = sensor1->getRadius() + ((sensor1Pos - sensor2Pos).length() - combinedRadius) * 0.5f + pFloat;
    *pos *= res;
    *pos += sensor2Pos;
}

f32 calcDistance(const HitSensor* sensor1, const HitSensor* sensor2){
    return (sensor1->getPos() - sensor2->getPos()).length();
}

const sead::Vector3f& getSensorPos(const al::HitSensor* sensor){
    return sensor->getPos();
}

al::LiveActor* getSensorHost(const al::HitSensor* sensor){
    return sensor->getParentActor();
}

bool isFaceBetweenSensors(const sead::Vector3f& pos, const HitSensor* sensor1, const HitSensor* sensor2){
    const sead::Vector3f& sensor1pos = sensor1->getPos();
    const sead::Vector3f& sensor2pos = sensor2->getPos();
    sead::Vector3f vecBetweenSensors;
    vecBetweenSensors.x = sensor2pos.x - sensor1pos.x;
    vecBetweenSensors.y = sensor2pos.y - sensor1pos.y;
    vecBetweenSensors.z = sensor2pos.z - sensor1pos.z;
    al::tryNormalizeOrZero(&vecBetweenSensors);
    return vecBetweenSensors.dot(pos) > 0.0f;
}

bool isEnableLookAtTargetSensor(const HitSensor* sensor, const sead::Vector3f& pos, f32 maxDistance){
    if(isDead(getSensorHost(sensor)) || !isSensorValid(sensor))
        return false;
    return (sensor->getPos() - pos).squaredLength() <= maxDistance * maxDistance;
}

bool isSensorValid(const HitSensor* sensor){ return sensor->isValid(); }

const sead::Vector3f& getActorTrans(const HitSensor* sensor){ return getTrans(getSensorHost(sensor)); }
const sead::Vector3f& getActorVelocity(const HitSensor* sensor){ return getVelocity(getSensorHost(sensor)); }
const sead::Vector3f& getActorGravity(const HitSensor* sensor){ return getGravity(getSensorHost(sensor)); };

bool isSensorName(const HitSensor* sensor, const char* name) { return al::isEqualString(sensor->getName(), name); }
bool isSensorHostName(const HitSensor* sensor, const char* name) { return al::isEqualString(getSensorHost(sensor)->getName(), name); }
bool isSensorHost(const HitSensor* sensor, const LiveActor* host) { return al::getSensorHost(sensor) == host; }

void validateHitSensors(LiveActor* actor){
    HitSensorKeeper* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    if(sensorKeeper)
        sensorKeeper->validate();
}
void invalidateHitSensors(LiveActor* actor){
    HitSensorKeeper* sensorKeeper = alActorSensorFunction::getSensorKeeper(actor);
    if(sensorKeeper)
        sensorKeeper->invalidate();
}
bool isSensorValid(const LiveActor* actor, const char* name) { return getHitSensor(actor, name)->isValid(); }
void validateHitSensor(const LiveActor* actor, const char* name) { return getHitSensor(actor, name)->validate(); }
void invalidateHitSensor(const LiveActor* actor, const char* name) { return getHitSensor(actor, name)->invalidate(); }

void validateHitSensorBindableAll(LiveActor*);
bool isSensorBindableAll(const HitSensor* sensor){
    if(isSensorBindableGoal(sensor) || isSensorBindableAllPlayer(sensor) || isSensorBindableBubbleOutScreen(sensor) || isSensorBindableKoura(sensor) || isSensorBindableRouteDokan(sensor) || isSensorBindableBubblePadInput(sensor) || isSensorBindable(sensor))
    //Required to match, thanks clang
        return true;
    return false;
}
void validateHitSensorEnemyAll(LiveActor*);
bool isSensorEnemy(const HitSensor*);
void validateHitSensorEnemyAttackAll(LiveActor*);
bool isSensorEnemyAttack(const HitSensor*);
void validateHitSensorEnemyBodyAll(LiveActor*);
bool isSensorEnemyBody(const HitSensor*);
void validateHitSensorEyeAll(LiveActor*);
bool isSensorEye(const HitSensor*);
void validateHitSensorMapObjAll(LiveActor*);
bool isSensorMapObj(const HitSensor*);
void validateHitSensorNpcAll(LiveActor*);
bool isSensorNpc(const HitSensor*);
void validateHitSensorPlayerAll(LiveActor*);
bool isSensorPlayer(const HitSensor*);
bool isSensorPlayerAll(const HitSensor*);
void validateHitSensorRideAll(LiveActor*);
bool isSensorRide(const HitSensor*);
bool isSensorSimple(const HitSensor*);
bool isSensorLookAt(const HitSensor*);
void invalidateHitSensorEyeAll(LiveActor*);
void invalidateHitSensorPlayerAll(LiveActor*);
void invalidateHitSensorPlayerAttackAll(LiveActor*);
bool isSensorPlayerAttack(const HitSensor*);
bool isSensorPlayerEye(const HitSensor*);

bool isSensorBindableGoal(const HitSensor* sensor){ return sensor->getType() == HitSensorType::BindableGoal; }
bool isSensorBindableAllPlayer(const HitSensor* sensor){ return sensor->getType() == HitSensorType::BindableAllPlayer; }
bool isSensorBindableBubbleOutScreen(const HitSensor* sensor){ return sensor->getType() == HitSensorType::BindableBubbleOutScreen; }
bool isSensorBindableKoura(const HitSensor* sensor){ return sensor->getType() == HitSensorType::BindableKoura; }
bool isSensorBindableRouteDokan(const HitSensor* sensor){ return sensor->getType() == HitSensorType::BindableRouteDokan; }
bool isSensorBindableBubblePadInput(const HitSensor* sensor){ return sensor->getType() == HitSensorType::BindableBubblePadInput; }
bool isSensorBindable(const HitSensor* sensor){ return sensor->getType() == HitSensorType::Bindable; }

}  // namespace al
