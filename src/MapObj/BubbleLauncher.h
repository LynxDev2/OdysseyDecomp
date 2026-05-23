#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class BubbleLauncher : public al::LiveActor {
public:
    BubbleLauncher(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void onSwitch();
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeCatch();
    bool tryCancel();
    void exeReady();
    f32 controlCameraReady();
    f32 calcEffectMtx();
    void endReady();
    void exeShoot();
    f32 controlCameraShoot();
    void control() override;

private:
    u8 filler[0x1F8 - sizeof(al::LiveActor)];
};

static_assert(sizeof(BubbleLauncher) == 0x1F8);
