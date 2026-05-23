#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class LavaStewVeget : public al::LiveActor {
public:
    LavaStewVeget(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeBreak();
    void control() override;
    void updateFinder();
    bool isExistSurface() const;
    void approachSurface();
    void syncSurfaceUp();

private:
    u8 filler[0x180 - sizeof(al::LiveActor)];
};

static_assert(sizeof(LavaStewVeget) == 0x180);
