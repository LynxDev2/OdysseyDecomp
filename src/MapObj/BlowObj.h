#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class BlowObj : public al::LiveActor {
public:
    BlowObj(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void killByStageSwitch();
    void initWithMapunitArgs(const al::ActorInitInfo& info);
    void initAfterPlacement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void startClipped() override;
    s64 respawn();
    void exeWait();
    void exeBlow();
    void tryAppearItem(const sead::Vector3f& pos, const char* tryAppearItemName);
    void exeInSaucePan();
    void exeEatingByYoshi();
    void endEatingByYoshi();
    void exeBreak();
    void exeWaitRespawn();

private:
    u8 filler[0x1B8 - sizeof(al::LiveActor)];
};

static_assert(sizeof(BlowObj) == 0x1B8);
