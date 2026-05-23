#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class PillarSwitchOpenMapParts : public al::LiveActor {
public:
    PillarSwitchOpenMapParts(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void open();
    void close();
    void initAfterPlacement() override;
    void exeWait();
    void exeDelayOpen();
    void exeOpen();
    void exeWaitOpend();
    void exeDelayClose();
    void exeClose();

private:
    u8 filler[0x170 - sizeof(al::LiveActor)];
};

static_assert(sizeof(PillarSwitchOpenMapParts) == 0x170);
