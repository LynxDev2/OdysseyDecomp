#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class YoshiFruitShineHolder : public al::LiveActor {
public:
    YoshiFruitShineHolder(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void updateHintPos(const sead::Vector3f& pos);
    void appearShineFromFruit(const sead::Vector3f& pos);

private:
    u8 filler[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(YoshiFruitShineHolder) == 0x120);
