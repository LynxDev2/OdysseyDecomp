#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class StackerCapWorldCtrl : public al::LiveActor {
public:
    StackerCapWorldCtrl(const char*);
    void init(const al::ActorInitInfo&) override;
    void appear() override;
    void exeBattle();
    void exeDemoCamera();
    void exeObjAppear();
private:
    u8 filler[0x128 - sizeof(al::LiveActor)];
};
static_assert(sizeof(StackerCapWorldCtrl) == 0x128);
