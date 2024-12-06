#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>

#include "Project/HitSensor/HitSensor.h"

namespace al {
class HitSensor;
class LiveActor;

class HitSensorKeeper {
public:
    HitSensorKeeper(s32 sensorCount);

    HitSensor* addSensor(LiveActor* parentActor, const char* name, u32 hitSensorType, f32 radius,
                         u16 maxSensorCount, const sead::Vector3<f32>* followPos,
                         const sead::Matrix34<f32>* followMatrix, const sead::Vector3<f32>& offset);
    void update();
    s32 getSensorNum() const;
    HitSensor* getSensor(s32) const;
    void attackSensor();
    void clear();
    void validate();
    void invalidate();
    void validateBySystem();
    void invalidateBySystem();
    HitSensor* getSensor(const char*) const;

private:
    s32 mMaxSensors;
    s32 mSensorCount = 0;
    HitSensor** mSensors;
};

static_assert(sizeof(HitSensorKeeper) == 0x10);

}  // namespace al
