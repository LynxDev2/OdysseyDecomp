#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Radish : public al::LiveActor {
public:
    Radish(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void resetForHide();
    void control() override;
    void reset();
    void updateCollider() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void release(s32 releaseDelay);
    s64 pull();
    void exeHideWait();
    void exeHideReaction();
    void exePull();
    void exePullOut();
    void exeWait();
    void exeHold();
    void exeThrow();
    bool trySendBoundMsgToSaucePan();
    void exeBound();
    void exeLand();
    void exeSaucePanInNoDemo();
    void exeSaucePanIn();
    void exeReaction();
    void exeBreak();
    void exeResetWait();
    void exeReset();

private:
    u8 filler[0x1D0 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Radish) == 0x1D0);
