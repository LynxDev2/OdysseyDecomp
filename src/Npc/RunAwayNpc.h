#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/Event/IEventFlowEventReceiver.h"
#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class RunAwayNpc : public al::LiveActor, public al::IEventFlowEventReceiver {
public:
    RunAwayNpc(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void control() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool receiveEvent(const al::EventFlowEventData* eventData) override;
    void exePatrol();
    s64 getCurrentWaitActionName();
    void reactToPlayer();
    void exeReaction();
    void exeSurprised();
    void exeScaredToRun();
    void exeScaredByRegularEnemy();
    void exeRelieved();
    void resetScareUneffectiveWindow();
    void exePrepareToRunAway();
    void exeRunAway();
    void exeHiding();
    void exeHidingAndTurning();
    void exeTurn();
    void exeTurnToPlacementFront();
    bool canSeeWithCylindricalLineOfSight(const sead::Vector3f& pos);

private:
    u8 filler[0x208 - sizeof(al::LiveActor) - sizeof(al::IEventFlowEventReceiver)];
};

static_assert(sizeof(RunAwayNpc) == 0x208);
