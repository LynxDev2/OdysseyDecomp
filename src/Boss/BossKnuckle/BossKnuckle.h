#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

#include "Demo/IUseDemoSkip.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class IUseDemoSkip;

class BossKnuckle : public al::LiveActor, public IUseDemoSkip {
public:
    BossKnuckle(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    void appear() override;
    bool isFirstDemo() const;
    bool isEnableSkipDemo() const;
    void skipDemo();
    void finishStartDemo(bool startDemo);
    void exeWait();
    bool turnToPlayer();
    void updateBodySyncPos();
    void syncHandIfWaiting();
    bool checkHackAndSetNerve();
    void exeRelay();
    void updatePlayerDemo();
    void exeAttackBeatStart();
    void exeAttackBeat();
    s64 genMummyAgainstPlayer(s32 mummyNum);
    s64 relayNextNerve(const al::Nerve* nerve, s32 step, bool isImmediate);
    void exeAttackHandFall();
    s32 countAliveIce();
    void exeAttackHandFallFirstPainDemo();
    void exeAttackSideStamp();
    void exeRunAwayStart();
    void exeRunAway();
    void breakAirIce();
    void startPlayerDemo();
    void exeDamage();
    void exeRestoreHand();
    void exeAttackRocketPunch();
    s64 genMummy(const al::LiveActor* actor, s32 mummyNum);
    void exeReturn();
    void exeBeforeBattleStart();
    void exeBeforeDemoBattleStartWait();
    void exeDemoBattleStart();
    void addDemoActorAll();
    void exeDemoBattleEnd();
    void exeAfterBattleEnd();
    void breakAllIce();

private:
    u8 filler[0x438 - sizeof(al::LiveActor) - sizeof(IUseDemoSkip)];
};

static_assert(sizeof(BossKnuckle) == 0x438);
