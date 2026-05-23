#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class TreasureBoxSequentialDirector : public al::LiveActor {
public:
    TreasureBoxSequentialDirector(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    bool isCorrectOpen(s32 correctOpen);
    bool isKillAllEnemy();
    void exeWait();
    void exeMissDemo();
    void exeMiss();
    void exeMissEnd();

private:
    u8 filler[0x138 - sizeof(al::LiveActor)];
};

static_assert(sizeof(TreasureBoxSequentialDirector) == 0x138);
