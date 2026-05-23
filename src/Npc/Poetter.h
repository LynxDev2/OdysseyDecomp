#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"
#include "Library/Message/IUseMessageSystem.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Poetter : public al::LiveActor, public al::IUseMessageSystem {
public:
    Poetter(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    void exeWait();
    void startTalkNoMore();
    void resetYawnWait();
    void exeEvent();
    void exeEventScare();
    void exeReaction();
    const al::MessageSystem* getMessageSystem() const override;

private:
    u8 filler[0x160 - sizeof(al::LiveActor) - sizeof(al::IUseMessageSystem)];
};

static_assert(sizeof(Poetter) == 0x160);
