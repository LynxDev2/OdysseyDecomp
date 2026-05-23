#pragma once

#include <basis/seadTypes.h>

#include "Library/Event/IEventFlowEventReceiver.h"
#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Yukimaru : public al::LiveActor, public al::IEventFlowEventReceiver {
public:
    Yukimaru(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void movement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isEnableHack() const;
    void afterHack();
    bool isEnableReaction() const;
    bool receiveEvent(const al::EventFlowEventData* eventData) override;
    void disableHack();
    void enableHack();
    bool exeEvent();
    void exeReaction();
    void exeHack();
    void exeHackAfter();

private:
    u8 filler[0x160 - sizeof(al::LiveActor) - sizeof(al::IEventFlowEventReceiver)];
};

static_assert(sizeof(Yukimaru) == 0x160);
