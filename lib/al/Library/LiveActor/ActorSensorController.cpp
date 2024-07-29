#include "Library/LiveActor/ActorSensorController.h"

#include "Project/HitSensor/HitSensor.h"
#include "Library/LiveActor/ActorSensorFunction.h"
#include "math/seadVectorFwd.h"

namespace al{

ActorSensorController::ActorSensorController(al::LiveActor* sensorParent, const char* sensorName){
    auto actorSensor = al::getHitSensor(sensorParent, sensorName);
    mHitSensor = actorSensor;
    mSensorRadius = actorSensor->getRadius();
    mSensorOffset = actorSensor->getOffset();
}

void ActorSensorController::setSensorScale(float scale){
    setSensorRadius(mSensorRadius * scale);
    mHitSensor->setOffset(mSensorOffset * scale);
}

void ActorSensorController::setSensorRadius(float radius){
    mHitSensor->setRadius(radius);
}

void ActorSensorController::setSensorFollowPosOffset(const sead::Vector3f& offset){
    mHitSensor->setOffset(offset);
}

void ActorSensorController::resetActorSensorController(){
    setSensorRadius(mSensorRadius);
    mHitSensor->setOffset(mSensorOffset);
}

}
