#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class ForestWorldFlowerCtrl : public al::LiveActor {
public:
    ForestWorldFlowerCtrl(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void exeWait();
    void exeWaitAfter();
    void exeFadeOut();
    void exeFadeWait();
    void exeFadeIn();
    void exeWaitBloom();
    void exeBloom();

private:
    u8 filler[0x170 - sizeof(al::LiveActor)];
};

static_assert(sizeof(ForestWorldFlowerCtrl) == 0x170);
