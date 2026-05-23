#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class GrowFlowerCoin : public al::LiveActor {
public:
    GrowFlowerCoin(const char* name);
    void init(const al::ActorInitInfo& info) override;
    s32 calcLevel(s32 level);
    void setGrowLevel();
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isEnableCoinReaction() const;
    bool isEnableReaction() const;
    void control() override;
    void startClipped() override;
    void endClipped() override;
    void exeWait();
    void startActionAllLeaf(const char* actionName);
    const sead::Vector3f& exeGrow();
    void updateGrowLevel();
    void exeReaction();
    void exeCoinReaction();
    void exeAppearMoon();

private:
    u8 filler[0x168 - sizeof(al::LiveActor)];
};

static_assert(sizeof(GrowFlowerCoin) == 0x168);
