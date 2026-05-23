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

class TalkNpc : public al::LiveActor, public al::IEventFlowEventReceiver {
public:
    TalkNpc(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void onFukankunCameraNearClipSetting();
    void offFukankunCameraNearClipSetting();
    void initAfterPlacement() override;
    bool tryGetCurrentEventState() const;
    void movement() override;
    bool tryGetCurrentEvent() const;
    void calcAnim() override;
    void updateCollider() override;
    void kill() override;
    void endClipped() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool receiveEvent(const al::EventFlowEventData* eventData) override;
    void startDemoKoopa(const sead::Vector3f& pos);
    void endDemoKoopa();
    void exeEvent();
    void exeHackEvent();
    void exeKinopioBrigadeFirstEvent();
    void exeDemoKoopa();

private:
    u8 filler[0x238 - sizeof(al::LiveActor) - sizeof(al::IEventFlowEventReceiver)];
};

static_assert(sizeof(TalkNpc) == 0x238);
