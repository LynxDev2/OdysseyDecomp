#pragma once

#include <basis/seadTypes.h>

#include "MapObj/ReactionObject.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class ReactionObjectPoster : public ReactionObject {
public:
    ReactionObjectPoster(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;

private:
    u8 filler[0x218 - sizeof(ReactionObject)];
};

static_assert(sizeof(ReactionObjectPoster) == 0x218);
