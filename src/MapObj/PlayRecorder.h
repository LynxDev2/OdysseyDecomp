#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class PlayRecorder : public al::LiveActor {
public:
    PlayRecorder(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void exeRecord();
    void exeEnd();

private:
    u8 filler[0x108 - sizeof(al::LiveActor)];
};

static_assert(sizeof(PlayRecorder) == 0x108);
