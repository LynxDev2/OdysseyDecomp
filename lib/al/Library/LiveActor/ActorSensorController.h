#pragma once

#include <math/seadVector.h>

namespace al{
class LiveActor;
class HitSensor;

class ActorSensorController{
public:
    ActorSensorController(al::LiveActor* sensorParent, const char* sensorName);
    void setSensorScale(float scale); // Should this be called multiplier?
    void setSensorRadius(float radius);
    void setSensorFollowPosOffset(const sead::Vector3f& offset);
    void resetActorSensorController();
private:
    HitSensor* mHitSensor = nullptr;
    float mSensorRadius = .0f;
    sead::Vector3f mSensorOffset = {.0f, .0f, .0f};
};
}
