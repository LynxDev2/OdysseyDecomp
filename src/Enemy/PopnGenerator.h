#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class PopnGenerator : public al::LiveActor {
public:
    PopnGenerator(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void startGenerate();
    void endGenerate();
    void reset();
    bool tryGenerate(bool isAppearStart);
    void exeStop();
    void exeWait();
    void exeGenerate();
    void exeSwitchDelay();

private:
    u8 filler[0x130 - sizeof(al::LiveActor)];
};

static_assert(sizeof(PopnGenerator) == 0x130);
