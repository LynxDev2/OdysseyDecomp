#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CapAppearMapParts : public al::LiveActor {
public:
    CapAppearMapParts(const char* name);
    void init(const al::ActorInitInfo& info) override;
    const sead::Vector3f& listenAppear();
    void startWait();
    void killAll();
    void control() override;
    void appear() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeAppear();
    void exeAppearEnd();
    void exeWait();
    void exeReaction();
    void exeWaitForever();
    void exeDisappear();

private:
    u8 filler[0x138 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CapAppearMapParts) == 0x138);
