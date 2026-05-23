#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
class HitSensor;
class SensorMsg;
struct ActorInitInfo;
}  // namespace al

class GoalMark : public al::LiveActor {
public:
    GoalMark(const char* actorName);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void movement() override;
    void calcAnim() override;
    void activate();
    s64 disappear();
    s64 reAppear();
    void exeSleep();
    void killIfIsGotShine();
    void exeStop();
    void exeWait();
    void exeWaitUnderPyramid();
    void exeHide();

private:
    char _108[0x30];
};

static_assert(sizeof(GoalMark) == 0x138);
static_assert(sizeof(GoalMark) == 0x138);
