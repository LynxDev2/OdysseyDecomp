#pragma once

#include <basis/seadTypes.h>

#include "Library/Obj/EffectObj.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class DemoChangeEffectObj : public al::EffectObj {
public:
    DemoChangeEffectObj(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void onDemoEnvironmentChange();
    void offDemoEnvirnomentChange();

private:
    u8 filler[0x158 - sizeof(al::EffectObj)];
};

static_assert(sizeof(DemoChangeEffectObj) == 0x158);
