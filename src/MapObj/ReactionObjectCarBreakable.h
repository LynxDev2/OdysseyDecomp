#pragma once

#include <basis/seadTypes.h>

#include "MapObj/ReactionObject.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class ReactionObjectCarBreakable : public ReactionObject {
public:
    ReactionObjectCarBreakable(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void kill() override;

private:
    u8 filler[0x220 - sizeof(ReactionObject)];
};

static_assert(sizeof(ReactionObjectCarBreakable) == 0x220);
