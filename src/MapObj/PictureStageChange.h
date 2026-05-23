#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class PictureStageChange : public al::LiveActor {
public:
    PictureStageChange(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    f32 setupOutCamera();
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isPlayerAtForceBind() const;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool isPlayerInBounds() const;
    void control() override;
    void exeWait();
    void exeBindIn();
    void exeBindOut();

private:
    u8 filler[0x1A0 - sizeof(al::LiveActor)];
};

static_assert(sizeof(PictureStageChange) == 0x1A0);
