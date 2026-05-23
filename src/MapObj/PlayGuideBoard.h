#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"
#include "Library/Message/IUseMessageSystem.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class PlayGuideBoard : public al::LiveActor, public al::IUseMessageSystem {
public:
    PlayGuideBoard(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isCanStartRotate();
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    void exeWait();
    void exeEvent();
    void exeRotate();
    void exeDead();
    const al::MessageSystem* getMessageSystem() const override;

private:
    u8 filler[0x160 - sizeof(al::LiveActor) - sizeof(al::IUseMessageSystem)];
};

static_assert(sizeof(PlayGuideBoard) == 0x160);
