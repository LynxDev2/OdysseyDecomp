#pragma once

#include <basis/seadTypes.h>

namespace al {
struct ActorInitInfo;
class LiveActor;
class SensorMsg;
class HitSensor;
}  // namespace al

class SubActorLodFixPartsScenarioAction : public al::LiveActor {
public:
    SubActorLodFixPartsScenarioAction(const char* name);

    void init(const al::ActorInitInfo& info) override;
    void listenStartSnapShotMode();
    void listenEndSnapShotMode();
    void movement() override;
    void calcAnim() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;

private:
    u8 filler[0x118 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SubActorLodFixPartsScenarioAction) == 0x118);

namespace al {
void registSupportFreezeSyncGroup(LiveActor* actor, const ActorInitInfo& info);
}  // namespace al
