#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class RotateTarget;

class RotateTargetParts : public al::LiveActor {
public:
    RotateTargetParts(const RotateTarget* rotateTarget);
    void makeActorAlive() override;
    void endClipped() override;
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;

private:
    u8 filler[0x178 - sizeof(al::LiveActor)];
};

class RotateTarget : public al::LiveActor {
public:
    s32 getAliveTargetNum() const;
    RotateTarget(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void saveKill();
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    void exeRotate();
    void exeSlowdown();
    void exeStop();
    void exeBreak();

private:
    u8 filler[0x178 - sizeof(al::LiveActor)];
};

static_assert(sizeof(RotateTarget) == 0x178);
