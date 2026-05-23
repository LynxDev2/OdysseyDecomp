#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class DoorWarpPuppetController;

class DoorWarp : public al::LiveActor {
public:
    DoorWarp(const char* name);
    void init(const al::ActorInitInfo& info) override;
    s64 unlock();
    void initAfterPlacement() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    s64 cancelBind();
    void controlTransfer(DoorWarpPuppetController* doorWarpPuppetController);
    bool tryStartExitCamera();
    void exeLock();
    void exeUnlock();
    void exeWait();
    void exeMoveToFront();
    void exeOpenIn();
    void exeCloseIn();
    void exeWaitCameraInterpolate();
    void exeAppear();
    void exeWaitOut();
    void exeOpenOut();
    void exeCloseOut();
    void exeDisappear();

private:
    u8 filler[0x1A8 - sizeof(al::LiveActor)];
};

static_assert(sizeof(DoorWarp) == 0x1A8);
