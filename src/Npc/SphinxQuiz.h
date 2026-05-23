#pragma once

#include <basis/seadTypes.h>

#include "Library/Event/IEventFlowEventReceiver.h"
#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class SphinxQuiz : public al::LiveActor, public al::IEventFlowEventReceiver {
public:
    SphinxQuiz(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool receiveEvent(const al::EventFlowEventData* eventData) override;
    void exeWait();
    void exeKeyWait();
    void exeKeyMove();
    void exeWaitMiniGame();

private:
    u8 filler[0x1F0 - sizeof(al::LiveActor) - sizeof(al::IEventFlowEventReceiver)];
};

static_assert(sizeof(SphinxQuiz) == 0x1F0);
