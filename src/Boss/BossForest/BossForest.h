#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

#include "Demo/IUseDemoSkip.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class IUseDemoSkip;

class BossForest : public al::LiveActor, public IUseDemoSkip {
public:
    BossForest(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool isFirstDemo() const;
    bool isEnableSkipDemo() const;
    void skipDemo();
    void updateSatellitesPose(const sead::Quatf& quat);
    s64 getCurrentSatelliteController() const;
    const sead::Vector3f& getSenobiGeneratePoint(s32 senobiGeneratePoint) const;
    s64 getFieldWalls();
    void control() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool isStateBodyAttack() const;
    void setStateDemoBattleEnd();
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    const sead::Matrix34f& getLifePartsEffectMtx(const char* effectName);
    void exeWaitForBattleStart();
    void exeDemoBattleStart();
    void exeBattlePhase1();
    void exeBattlePhase2();
    void exeBattlePhase3();
    void exeDemoBattleEnd();
    void exeDie();

private:
    u8 filler[0x2E8 - sizeof(al::LiveActor) - sizeof(IUseDemoSkip)];
};

static_assert(sizeof(BossForest) == 0x2E8);
