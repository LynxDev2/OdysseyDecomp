#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class UtsuboWatcher : public al::LiveActor {
public:
    UtsuboWatcher(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    void exeWait();
    bool checkTouchPosActiveUtsubo(const sead::Vector3f& pos);
    bool tryGetFreeUtsubo();

private:
    u8 filler[0x128 - sizeof(al::LiveActor)];
};

static_assert(sizeof(UtsuboWatcher) == 0x128);
