#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class ShopBgmPlayer : public al::LiveActor {
public:
    ShopBgmPlayer(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void makeActorAlive() override;
    void movement() override;
    void exeWaitOnSwitch();
    void exePlay();

private:
    u8 filler[0x118 - sizeof(al::LiveActor)];
};

static_assert(sizeof(ShopBgmPlayer) == 0x118);
