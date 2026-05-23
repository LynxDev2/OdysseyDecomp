#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"
#include "Library/Scene/ISceneObj.h"

#include "Demo/IUseDemoSkip.h"
#include "Player/IUsePlayerCollision.h"

class WaterLauncherCork;

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
class RailRider;
}  // namespace al

class GiantWanderBoss : public al::LiveActor,
                        public al::ISceneObj,
                        public IUsePlayerCollision,
                        public IUseDemoSkip {
public:
    GiantWanderBoss(const char*);

    void init(const al::ActorInitInfo&) override;
    void switchOn();
    void initAfterPlacement() override;
    void updateCorkInfo();
    s32 calcOnCorkNum() const;
    bool isOnSwitchAll() const;
    void startBattle(bool);
    void setMagmaOn();
    void kill() override;
    void control() override;
    bool isActiveBattle() const;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool isHitMagma(al::HitSensor*, al::HitSensor*) const;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void endAllRangeAttack();
    void updateCollider() override;
    bool isFirstDemo() const override;
    bool isEnableSkipDemo() const override;
    void skipDemo() override;
    void endDemo();
    const sead::Matrix34f& getBulletMtx() const;
    void hideAllMine();
    void resetHideAllMine();
    void killAttachedMine();
    void addDemoActorAllMine();
    void addDemoActorAllCork();
    void killAllWeapon();
    s32 calcCorkIndex(const WaterLauncherCork*) const;
    void updateSwitchSave();
    s64 getSwitchForCageShine(s32) const;
    void startDemoWorldEnter();
    void exeStopBeforeBattle();
    void exeRequestDemoBeforeBattle();
    void exeOnGlass();
    void exeDemoBattleStart();
    void exeDemoBattleStartWorldEnter();
    void exeDemoBattleStartLevel2();
    void exeWaitDemoBattleEnd();
    void exeDemoBattleEnd();
    void exeDemoBattleEndCameraDemo();
    void exeDemoFade();
    void exeDemoFadeWait();
    void exeDemoFadeOpen();
    void exeFlyFirstRail();
    void updateRumble();
    void turnToPlayer(bool);
    f32 updateRail();
    al::RailRider* getCurrentRailKeeper() const;
    bool tryShot(s32);
    void exeFly();
    void exeFlyFast();
    void changeFly();
    void exeAttack();
    void exeAttackAndEscape();
    void exeShotMineSpecialBefore();
    void exeShotMineSpecialStart();
    void exeShotMineSpecial();
    void exeAttackAllRangeStart();
    void turnToHorizon();
    void exeAttackAllRangeLoop();
    void startAllRangeAttack();
    void endAttackAllRangeLoop();
    void exeAttackAllRangeEnd();
    void exeStopTrample();
    void exeDamageStop();
    void exeDamageStopInEscape();
    void exeHipDropFall();
    void setCollisionShapeSmall();
    void exeHipDropDown();
    void exeGoToEscapeRailStart();
    void setCollisionShapeNormal();
    void exeGoToEscapeRail();
    void exeEscapeRailStart();
    void exeEscapeRail();
    bool tryEscapeCancel();
    void exeEscapeRailAttack();
    void exeEscapeCancelStart();
    void exeEscapeCancel();
    void exeEscapeInvincibleEnd();
    void exeAngry();
    al::RailRider* getRailRider() const override;
    const sead::Vector3f& calcMagmaPos(sead::Vector3f*) const;
    PlayerCollider* getPlayerCollider() const override;

private:
    u8 filler[0x3D0 - sizeof(al::LiveActor) - sizeof(al::ISceneObj) - sizeof(IUsePlayerCollision) -
              sizeof(IUseDemoSkip)];
};

static_assert(sizeof(GiantWanderBoss) == 0x3D0);

namespace rs {
bool isActiveBattleGiantWanderBoss(const al::IUseSceneObjHolder*);
bool isScareByGiantWanderBoss(const al::LiveActor*);
}  // namespace rs
