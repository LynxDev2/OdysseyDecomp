#pragma once

#include <basis/seadTypes.h>

#include "Library/MapObj/KeyMoveMapParts.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class MeganeKeyMoveMapParts : public al::KeyMoveMapParts {
public:
    MeganeKeyMoveMapParts(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;

private:
    u8 filler[0x158 - sizeof(al::KeyMoveMapParts)];
};

static_assert(sizeof(MeganeKeyMoveMapParts) == 0x158);
