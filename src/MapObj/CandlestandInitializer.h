#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class CandlestandInitializer : public al::LiveActor {
public:
    CandlestandInitializer(const char* name);
    void init(const al::ActorInitInfo& info) override;

private:
    u8 filler[0x118 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CandlestandInitializer) == 0x118);
