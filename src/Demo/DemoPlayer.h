#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>

#include "Library/Demo/DemoActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class DemoPlayer : public al::DemoActor {
public:
    DemoPlayer(const char* name);
    void forceSetCostumeAndCapType(const char* name, const char* setCostumeAndCapTypeName);
    void init(const al::ActorInitInfo& info) override;
    void hairControl();
    void initAfterCreateFromFactory(const al::ActorInitInfo& info,
                                    const al::ActorInitInfo& demoInfo,
                                    const sead::Matrix34f* matrix, bool isAfterCreateFromFactory);
    void makeActorAlive() override;
    void control() override;
    void startAction(s32 action);
    void resetDynamics();

private:
    u8 filler[0x258 - sizeof(al::DemoActor)];
};

static_assert(sizeof(DemoPlayer) == 0x258);
