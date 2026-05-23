#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class BossRaidRivet : public al::LiveActor {
public:
    BossRaidRivet(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void setConnect(al::LiveActor* actor, const char* jointName, const sead::Vector3f& startPos,
                    const sead::Vector3f& endPos);
    void setChainRootConnect(al::LiveActor* actor, const char* jointName,
                             const sead::Vector3f& startPos, const sead::Vector3f& endPos);
    void createChainAndPopn(al::LiveActor* actor, const al::ActorInitInfo& info);
    void calcAnim() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isElectric() const;
    bool isEnableCapKeepLockOn() const;
    bool isPullOut() const;
    void exeDemo();
    void exeWait();
    void exeElectricSign();
    void exeElectric();
    void exeElectricEnd();
    void exePull();
    void exePullOut();
    void appearPopn();
    void reset();
    void startAnim(const char* animName);
    void startElectricSign();
    void startElectric();
    void endElectric();
    bool tryAppearPopn();
    bool tryKillPopn();
    void killChain();
    void resetChain();

private:
    u8 filler[0x158 - sizeof(al::LiveActor)];
};

static_assert(sizeof(BossRaidRivet) == 0x158);
