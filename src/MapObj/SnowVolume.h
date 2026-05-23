#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class SnowVolume : public al::LiveActor {
public:
    SnowVolume(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void updateDifferential();
    void updateVolume();
    void clearModifyFlag();
    void initAfterPlacement() override;
    f32 calcGridPos(sead::Vector3f* outPos, s32 xIndex, s32 yIndex, s32 zIndex) const;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    const sead::Vector3f& calcRemovePoint(const sead::Vector3f& point, f32 removePoint);
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void startClipped() override;
    void endClipped() override;
    void control() override;
    void updateRemovePoint();
    void updateConnection();
    void updateGravity();
    void createVolume();
    const sead::Vector3f& calcNormal(sead::Vector3f* outPos, const sead::Vector3f& pos) const;
    s64 removeSnow(const sead::Vector3f& worldPos, f32 radius, f32 power);

private:
    u8 filler[0x1C8 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SnowVolume) == 0x1C8);
