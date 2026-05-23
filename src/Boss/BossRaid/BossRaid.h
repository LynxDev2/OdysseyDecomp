#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/Event/IEventFlowEventReceiver.h"
#include "Library/LiveActor/LiveActor.h"

#include "Demo/IUseDemoSkip.h"

namespace al {
struct ActorInitInfo;
class ByamlIter;
class SensorMsg;
class HitSensor;
}  // namespace al

class IUseDemoSkip;

class BossRaid : public al::LiveActor, public IUseDemoSkip, public al::IEventFlowEventReceiver {
public:
    BossRaid(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initRivetList(const al::ActorInitInfo& info);
    void killRivetAll();
    void invalidateCollisionAll();
    void startDemoBattleStart();
    void startBattle();
    bool tryGetFollowTargetInfo(al::LiveActor** outActor, sead::Vector3f* outTargetPos,
                                sead::Vector3f* outTargetFront, const char** outActionName,
                                const al::ByamlIter& byamlIter);
    void endBattleStartDemo();
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool isElectric() const;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isEnableDamage() const;
    bool receiveEvent(const al::EventFlowEventData* eventData);
    void calcAnim() override;
    void updatePlayerPose();
    void control() override;
    bool isPullOutRivetAll() const;
    void hintCapMessage(const char* name, s32 capMessage);
    bool isPullOutRivetAny() const;
    bool isNearWeakPoint() const;
    void damageCapMessage();
    bool isFirstDemo() const;
    bool isEnableSkipDemo() const;
    void skipDemo();
    void exeBattleStartWait();
    void exePreDemoBattleStart();
    void setUpDemoBattleStart();
    void exeDemoBattleStart();
    void startActionMain(const char* actionName);
    s32 getEnableRivetCount() const;
    void resetChainAll();
    void exeStartAttack();
    void exeBreathAttack();
    void exeGroundAttack();
    void exeTired();
    void appearRivetPopnAll();
    void exeUpSign();
    void startElectricSignParts();
    void exeUp();
    void killRivetPopnAll();
    void startAttack();
    void exeDamage();
    void exeRoarSign();
    void exeRoar();
    void resetRivetAll();
    void startRoarAnimParts();
    void exePreDemoBattleEnd();
    void setUpDemoBattleEnd();
    void exeDemoBattleEnd();
    void exeEndTalk();
    s32 getShotLevel() const;
    void startElectricParts();
    void endElectricParts();
    void validateCollisionAll();
    void killElectoricAll();
    void killChainAll();
    void appearAndHideRivetAll();
    void showRivetAll();
    void startDemoBattleEnd();

private:
    u8 filler[0x1A8 - sizeof(al::LiveActor) - sizeof(IUseDemoSkip) -
              sizeof(al::IEventFlowEventReceiver)];
};

static_assert(sizeof(BossRaid) == 0x1A8);
