#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class RouteGuideRail : public al::LiveActor {
public:
    RouteGuideRail(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void place(const sead::Vector3f& trans, s32 railIndex, f32 distance);
    bool validate();
    void invalidate();
    void exeAppear();
    void fitGround();
    void exeKill();
    void initAfterPlacement() override;

private:
    u8 filler[0x138 - sizeof(al::LiveActor)];
};

static_assert(sizeof(RouteGuideRail) == 0x138);
