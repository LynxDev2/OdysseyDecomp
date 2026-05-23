#pragma once

#include <basis/seadTypes.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class GhostPlayer;

class RaceManGoal : public al::LiveActor {
public:
    RaceManGoal(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isAttachedActor(const al::LiveActor* actor) const;
    void exeWait();
    void exeEnd();
    bool isGoalPlayer() const;
    void attachActor(GhostPlayer* ghostPlayer);
    const sead::Vector3f& calcMarioJointQuatPos(sead::Quatf* quat, sead::Vector3f* pos);
    s64 getRaceFirstJointName();

private:
    u8 filler[0x188 - sizeof(al::LiveActor)];
};

static_assert(sizeof(RaceManGoal) == 0x188);
