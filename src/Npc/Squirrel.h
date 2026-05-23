#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Squirrel : public al::LiveActor {
public:
    Squirrel(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void control() override;
    void appear() override;
    void kill() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeHide();
    void exeAppear();
    void exeWait();
    void exeTurn();
    void exeRunaway();
    void exeDisappear();
    void exeRestartPrepare();

private:
    u8 filler[0x178 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Squirrel) == 0x178);
