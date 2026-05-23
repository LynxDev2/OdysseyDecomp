#pragma once

#include <basis/seadTypes.h>

#include "Library/Event/IEventFlowEventReceiver.h"
#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class WorldTravelingPeach : public al::LiveActor, public al::IEventFlowEventReceiver {
public:
    WorldTravelingPeach(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void startPeachWorldHomeCastleCapDemo();
    void endPeachWorldHomeCastleCapDemo();
    void initAfterPlacement() override;
    void makeActorDead() override;
    void control() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool receiveEvent(const al::EventFlowEventData* eventData) override;
    void exeEvent();

private:
    u8 filler[0x1C8 - sizeof(al::LiveActor) - sizeof(al::IEventFlowEventReceiver)];
};

static_assert(sizeof(WorldTravelingPeach) == 0x1C8);
