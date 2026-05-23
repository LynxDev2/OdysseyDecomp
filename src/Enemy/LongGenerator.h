#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class LongGenerator : public al::LiveActor {
public:
    LongGenerator(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void listenKill();
    void listenAppear();
    void exeInitGenerateAll();
    void exeWait();
    void exeGenerate();
    bool tryGenerate();
    void exeGenerateAll();

private:
    u8 filler[0x118 - sizeof(al::LiveActor)];
};

static_assert(sizeof(LongGenerator) == 0x118);
