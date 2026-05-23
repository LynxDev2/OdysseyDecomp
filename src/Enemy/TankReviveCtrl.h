#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class TankReviveCtrl : public al::LiveActor {
public:
    TankReviveCtrl(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;

private:
    u8 filler[0x110 - sizeof(al::LiveActor)];
};

static_assert(sizeof(TankReviveCtrl) == 0x110);
