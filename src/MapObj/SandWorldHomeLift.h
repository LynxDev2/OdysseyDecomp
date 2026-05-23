#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class SandWorldHomeLift : public al::LiveActor {
public:
    SandWorldHomeLift(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void start();
    void stop();
    void appearAndSetStart();
    void initAfterPlacement() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    s64 getStopActionName() const;
    void exeStandBy();
    void exeDelay();
    void exeWait();
    void exeMoveSign();
    void exeMove();
    void exeStopSign();
    void exeStop();
    void exeReset();
    void exeWaitAppearCameraInterpole();
    void exeAppearByMainShine();
    void startDemoAppearByMainShine();
    void startAppearByMainShine();
    bool isEndDemoAppearCameraInterpole() const;
    bool isEndDemoAppearByMainShine() const;

private:
    u8 filler[0x168 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SandWorldHomeLift) == 0x168);
