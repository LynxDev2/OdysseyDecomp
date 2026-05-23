#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class WaterRoad : public al::LiveActor {
public:
    WaterRoad(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void onAppear();
    void appear() override;
    void movement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool isInSensorAlready(const al::HitSensor* sensor) const;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    bool isNearPlayer() const;
    bool tryMoveSensorToCapHit();
    void exeFlow();
    void updateFlow();
    bool tryGetOff(al::CameraTicket* cameraTicket);
    void exeFlowAfter();
    void exeRelease();
    void exeInvalidateBind();

private:
    u8 filler[0x1C8 - sizeof(al::LiveActor)];
};

static_assert(sizeof(WaterRoad) == 0x1C8);
