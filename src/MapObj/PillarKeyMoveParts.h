#pragma once

#include <basis/seadTypes.h>

#include "Library/MapObj/KeyMoveMapParts.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class PillarKeyMoveParts : public al::KeyMoveMapParts {
public:
    PillarKeyMoveParts(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void updateFinder();
    void exeMove();
    void exeWait();
    bool tryPlayHoldSe();
    void exeDelay();

private:
    u8 filler[0x1B8 - sizeof(al::KeyMoveMapParts)];
};

static_assert(sizeof(PillarKeyMoveParts) == 0x1B8);
