#pragma once

#include <basis/seadTypes.h>

#include "Camera/EventKeyMoveCameraObjNoDemo.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class EventKeyMoveCameraObjWithDemo : public EventKeyMoveCameraObjNoDemo {
public:
    EventKeyMoveCameraObjWithDemo(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    void kill() override;

private:
    u8 filler[0x120 - sizeof(EventKeyMoveCameraObjNoDemo)];
};

static_assert(sizeof(EventKeyMoveCameraObjWithDemo) == 0x120);
