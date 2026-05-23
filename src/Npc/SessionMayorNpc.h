#pragma once

#include <basis/seadTypes.h>

#include "Library/Event/IEventFlowEventReceiver.h"
#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class SessionMayorNpc : public al::LiveActor, public al::IEventFlowEventReceiver {
public:
    SessionMayorNpc(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveEvent(const al::EventFlowEventData* eventData) override;

private:
    u8 filler[0x170 - sizeof(al::LiveActor) - sizeof(al::IEventFlowEventReceiver)];
};

static_assert(sizeof(SessionMayorNpc) == 0x170);
