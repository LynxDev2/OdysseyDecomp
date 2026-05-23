#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class EventKeyMoveCameraObjNoDemo : public al::LiveActor {
public:
    EventKeyMoveCameraObjNoDemo(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void makeActorAlive() override;
    void kill() override;
    void control() override;

private:
    u8 filler[0x118 - sizeof(al::LiveActor)];
};

static_assert(sizeof(EventKeyMoveCameraObjNoDemo) == 0x118);
