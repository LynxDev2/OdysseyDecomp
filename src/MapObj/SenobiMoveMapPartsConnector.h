#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class SenobiMoveMapPartsConnector : public al::LiveActor {
public:
    SenobiMoveMapPartsConnector(const char* name);
    void init(const al::ActorInitInfo& info) override;
    s64 broadcastMsg(SenobiMoveMapParts* senobiMoveMapParts, f32 moveSpeed);

private:
    u8 filler[0x118 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SenobiMoveMapPartsConnector) == 0x118);
