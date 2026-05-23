#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class TalkNpcFreeze : public al::LiveActor {
public:
    TalkNpcFreeze(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void makeActorAlive() override;
    void movement();  // Function should be implemented in header
    void calcAnim();  // Function should be implemented in header
private:
    u8 filler[0x108 - sizeof(al::LiveActor)];
};

static_assert(sizeof(TalkNpcFreeze) == 0x108);
