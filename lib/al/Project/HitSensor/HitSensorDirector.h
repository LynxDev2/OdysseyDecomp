#pragma once

#include "Library/Execute/IUseExecutor.h"
#include "Library/HostIO/HioNode.h"

namespace al {
class ExecuteDirector;
class HitSensor;
class SensorHitGroup;

class HitSensorDirector : public IUseExecutor, public IUseHioNode {
public:
    HitSensorDirector(ExecuteDirector*);

    void execute() override;
    void initGroup(HitSensor*);

private:
    void executeHitCheckInSameGroup(SensorHitGroup*) const;
    void executeHitCheckGroup(SensorHitGroup*, SensorHitGroup*) const;
    void executeHitCheck(HitSensor*, HitSensor*) const;

private:
    SensorHitGroup* mPlayer = nullptr;
    SensorHitGroup* mPlayerEye = nullptr;
    SensorHitGroup* mRide = nullptr;
    SensorHitGroup* mEye = nullptr;
    SensorHitGroup* mLookAt = nullptr;
    SensorHitGroup* mSimple = nullptr;
    SensorHitGroup* mMapObj = nullptr;
    SensorHitGroup* mCharacter = nullptr;
};

static_assert(sizeof(HitSensorDirector) == 0x48);

}  // namespace al
