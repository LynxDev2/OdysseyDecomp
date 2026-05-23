#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class CapFlowerGroup : public al::LiveActor {
public:
    CapFlowerGroup(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void changeFlowersColorWhite();
    void appear() override;
    bool isBloomed() const;
    void makeActorAlive() override;
    void kill() override;
    void makeActorDead() override;
    void killAll();
    void killWithoutFlowers();
    void makeActorDeadWithoutFlowers();
    void exeWait();
    void exeTimer();
    void exeAllBloomed();
    void exeEndWait();

private:
    u8 filler[0x130 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CapFlowerGroup) == 0x130);
