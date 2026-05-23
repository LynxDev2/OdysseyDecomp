#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class MarchingCubeBlockCollision;

class MarchingCubeBlock : public al::LiveActor {
public:
    MarchingCubeBlock(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void killUnusedCollision();
    void updateAnimAll();
    void control() override;
    void updateTargetMarkerSensorPos();
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    s64 calcVertexBitFlag(s32 xIndex, s32 yIndex, s32 zIndex);
    void updateAnim(const sead::Vector3i& vector3I);
    bool receiveBreakIndex(const sead::Vector3i& vector3I,
                           MarchingCubeBlockCollision* marchingCubeBlockCollision, bool index);
    s32 countupCoinCount(MarchingCubeBlockCollision* marchingCubeBlockCollision);
    bool receiveBreakIndexAndAbove(const sead::Vector3i& vector3I,
                                   MarchingCubeBlockCollision* marchingCubeBlockCollision,
                                   bool index);
    bool receiveExplosionMsg(const al::SensorMsg* message, al::HitSensor* other);

private:
    u8 filler[0x1A0 - sizeof(al::LiveActor)];
};

static_assert(sizeof(MarchingCubeBlock) == 0x1A0);
