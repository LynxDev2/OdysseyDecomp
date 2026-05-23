#pragma once

#include <basis/seadTypes.h>

#include "Library/Event/IEventFlowEventReceiver.h"
#include "Library/LiveActor/LiveActor.h"
#include "Library/Message/IUseMessageSystem.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class HelpNpc : public al::LiveActor,
                public al::IUseMessageSystem,
                public al::IEventFlowEventReceiver {
public:
    HelpNpc(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveEvent(const al::EventFlowEventData* eventData) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    void control() override;
    void exeWait();
    void exeScare();
    void exeReaction();
    const al::MessageSystem* getMessageSystem() const override;

private:
    u8 filler[0x158 - sizeof(al::LiveActor) - sizeof(al::IUseMessageSystem) -
              sizeof(al::IEventFlowEventReceiver)];
};

static_assert(sizeof(HelpNpc) == 0x158);
