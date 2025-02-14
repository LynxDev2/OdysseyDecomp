#include "Library/LiveActor/ActorSensorFunction.h"
#include "Library/LiveActor/LiveActor.h"
#include "Project/HitSensor/HitSensor.h"
#include "Library/HitSensor/HitSensorKeeper.h"

namespace alActorSensorFunction{

al::HitSensorKeeper* getSensorKeeper(const al::LiveActor* actor){
    return actor->getHitSensorKeeper();
}

bool sendMsgSensorToSensor(const al::SensorMsg& message, al::HitSensor* sender, al::HitSensor* receiver){
    return receiver->getParentActor()->receiveMsg(&message, sender, receiver);
}

bool sendMsgToActorUnusedSensor(const al::SensorMsg& message, al::LiveActor* receiverActor){
    //Trying to store the HitSensorKeeper or the actual HitSensor into a local variable here mismatches
    return receiverActor->receiveMsg(&message, receiverActor->getHitSensorKeeper()->getSensor(0), receiverActor->getHitSensorKeeper()->getSensor(0));
}
}
