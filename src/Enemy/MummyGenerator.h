#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class MummyGenerator : public al::LiveActor {
public:
    MummyGenerator(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void startGenerate();
    void endGenerate();
    void startClipped() override;
    void endClipped() override;
    void exeStop();
    void exeStandBy();
    void exeWait();
    void exeAppear();
    bool tryGenerateRandom();
    bool tryGenerateLine(s32 lineIndex);

private:
    u8 filler[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(MummyGenerator) == 0x120);
