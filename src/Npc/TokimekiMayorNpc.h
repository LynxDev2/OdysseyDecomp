#pragma once

#include <basis/seadTypes.h>

#include "Library/Event/IEventFlowEventReceiver.h"
#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class TokimekiMayorNpc : public al::LiveActor, public al::IEventFlowEventReceiver {
public:
    TokimekiMayorNpc(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool receiveEvent(const al::EventFlowEventData* eventData) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool exeWait();
    void exeReaction();

private:
    u8 filler[0x1B8 - sizeof(al::LiveActor) - sizeof(al::IEventFlowEventReceiver)];
};

static_assert(sizeof(TokimekiMayorNpc) == 0x1B8);
