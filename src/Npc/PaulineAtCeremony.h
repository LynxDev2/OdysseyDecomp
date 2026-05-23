#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/Event/IEventFlowEventReceiver.h"
#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class PaulineAtCeremony : public al::LiveActor, public al::IEventFlowEventReceiver {
public:
    PaulineAtCeremony(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void startProcessing();
    void control() override;
    void forceControlForDance();
    void controlForReSing();
    void controlForLipSync();
    void controlForEyeline();
    void controlForDance();
    void setDanceAction(s32 actionIndex, f32 blendStep);
    void setMouthAction(s32 mouthAction);
    void setEyelineLookAtPos(f32 lookAtX, f32 lookAtY);
    f32 calPosInFrontOfSelf(sead::Vector3f* outPos, f32 frontOffset, f32 heightOffset);
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool receiveEvent(const al::EventFlowEventData* eventData) override;
    void endClipped() override;
    void setHeadLookAtPos(f32 lookAtX, f32 lookAtY);
    void exeStandBy();
    void exeIntro();
    bool exeDance();
    void exeReaction();
    void setIsManualSetHeadLookAt(bool isManualSetHeadLookAt);
    void setIsManualSetEyelineLookAt(bool isManualSetEyelineLookAt);

private:
    u8 filler[0x190 - sizeof(al::LiveActor) - sizeof(al::IEventFlowEventReceiver)];
};

static_assert(sizeof(PaulineAtCeremony) == 0x190);
