#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

#include "Boss/GolemClimb/IUseGolemState.h"
#include "Demo/IUseDemoSkip.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class IUseDemoSkip;

class GolemClimb : public al::LiveActor, public IUseGolemState, public IUseDemoSkip {
public:
    GolemClimb(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    void appear() override;
    void kill() override;
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void startDown();
    void startDamage();
    void exeReady();
    void exeMove();
    void endMove();
    void exeDamage();
    void exeDownStart();
    void endDownStart();
    void exeDown();
    void endDown();
    void exeDownShout();
    void exeDownRecover();
    void endDownRecover();
    void exeDownBreak();
    void exeStandBreak();
    void exeRun();
    void exeShout();
    void exeLegRecoverFull();
    void exeLegRecoverHalf();
    void exeTest();
    void exeDemoBattleStart();
    void exeDemoBattleEnd();
    void exeDemoSimpleFade();
    void exeDemoSimpleMain();
    void exeBattleStart();
    void updateLookAt();
    bool isFirstDemo() const;
    bool isEnableSkipDemo() const;
    void skipDemo();
    void updateOnlyDemoGrapics();
    void throwReflectBomb();
    void throwTsukkun();
    void startDemo();
    void endDemo();
    void startShout();
    void endShout();
    void replaceDemoPlayer() override;
    void getShoutPos(sead::Vector3f* pos) const override;
    void stampFoot(const sead::Vector3f& pos, const sead::Quatf& quat) override;
    void showDamageArea();
    void hideDamageArea();
    void setDamageAreaPose(const sead::Matrix34f& matrix) override;
    void throwSearchBomb();
    void updatePushSensor();
    void endPushSensor();
    bool tryNextPushSensor() const;
    al::LiveActor* getActor() override;
    al::LiveActor* getSkeleton() override;
    GolemJointIKRootCtrl* getFootRootL() const override;
    GolemJointIKRootCtrl* getFootRootR() const override;
    GolemClimbThrustPoint* getThrustPointL() const override;
    GolemClimbThrustPoint* getThrustPointR() const override;
    GolemClimbWeakPoint* getWeakPoint(s32 weakPoint) const override;
    bool isPrepareShout() const override;
    IUseDemoSkip* getDemoSkip() override;
    bool isInFootL() override;
    bool isInFootR() override;
    bool isMoon() override;

private:
    u8 filler[0x430 - sizeof(al::LiveActor) - sizeof(IUseGolemState) - sizeof(IUseDemoSkip)];
};

static_assert(sizeof(GolemClimb) == 0x430);
