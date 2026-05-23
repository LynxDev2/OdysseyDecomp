#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class MoonBasementFallObjDecoration : public al::LiveActor {
public:
    MoonBasementFallObjDecoration(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void turnEffectOff();
    void initAfterPlacement() override;
    void exeStandBy();
    void exeAppear();
    void exeFall();
    void exeVanish();
    void exeVanishNoEffect();
    void startFalling();  // Function should be implemented in header
    void stopFalling();   // Function should be implemented in header
private:
    u8 filler[0x150 - sizeof(al::LiveActor)];
};

static_assert(sizeof(MoonBasementFallObjDecoration) == 0x150);
