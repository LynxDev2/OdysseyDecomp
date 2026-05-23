#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CityWorldUndergroundMachine : public al::LiveActor {
public:
    CityWorldUndergroundMachine(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void startMoveSign();
    void startStepMoveSign();
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void startAcitonSync(const char* name);
    void exeStartDemoRequest();
    void exeMoveSign();
    void exeMove();
    void exeStepDemoRequest();
    void exeStepMoveSign();
    void exeShineAppear();
    void exeStepMove();

private:
    u8 filler[0x150 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CityWorldUndergroundMachine) == 0x150);
