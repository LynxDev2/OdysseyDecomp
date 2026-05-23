#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class HitSensor;
}  // namespace al

class IcicleFall : public al::LiveActor {
public:
    IcicleFall(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool isFallEnd() const;
    void setFallEnd();
    void exeWait();
    void exeFallSign();
    void exeFall();
    void exeStop();

private:
    u8 filler[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(IcicleFall) == 0x120);
