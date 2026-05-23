#pragma once

#include <basis/seadTypes.h>

#include "Library/Event/IEventFlowEventReceiver.h"
#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class AmiiboNpc : public al::LiveActor, public al::IEventFlowEventReceiver {
public:
    AmiiboNpc(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void reenterStage();
    bool receiveEvent(const al::EventFlowEventData* eventData) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    void exeWait();
    void exeWaitEndAmiiboSearch();
    bool exeTalk();
    void exeReaction();
    void exeWaitPlayerPutOn();
    void exeChangeCostume();

private:
    u8 filler[0x158 - sizeof(al::LiveActor) - sizeof(al::IEventFlowEventReceiver)];
};

static_assert(sizeof(AmiiboNpc) == 0x158);
