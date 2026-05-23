#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>

#include "Library/Demo/DemoActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class DemoActorCapManHero : public al::DemoActor {
public:
    DemoActorCapManHero(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterCreateFromFactory(const al::ActorInitInfo& info,
                                    const al::ActorInitInfo& demoInfo,
                                    const sead::Matrix34f* matrix, bool isAfterCreateFromFactory);
    void makeActorAlive() override;
    void control() override;
    void startAction(s32 action);

private:
    u8 filler[0x170 - sizeof(al::DemoActor)];
};

static_assert(sizeof(DemoActorCapManHero) == 0x170);
