#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class MoonBasementMeteorPointObj : public al::LiveActor {
public:
    MoonBasementMeteorPointObj(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void onSwitchStart();
    void offSwitchStart();
    void initAfterPlacement() override;
    void movement() override;
    void exeDelay();
    void exeWait();
    void exeStop();
    void onChangeTrans();   // Function should be implemented in header
    void offChangeTrans();  // Function should be implemented in header
private:
    u8 filler[0x128 - sizeof(al::LiveActor)];
};

static_assert(sizeof(MoonBasementMeteorPointObj) == 0x128);
