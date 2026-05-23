#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CameraDemoKeyMoveMapParts : public al::LiveActor {
public:
    CameraDemoKeyMoveMapParts(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void start();
    void stop();
    void appearAndSetStart();
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    void exeStandBy();
    void exeDelay();
    void exeWait();
    void setWaitEndNerve();
    void exeMoveSign();
    void exeMove();
    void exeStopSign();
    void exeStop();
    void exeCamera();

private:
    u8 filler[0x158 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CameraDemoKeyMoveMapParts) == 0x158);
