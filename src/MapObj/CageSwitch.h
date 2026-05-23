#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CageSwitch : public al::LiveActor {
public:
    CageSwitch(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void open();
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeCloseWait();
    void exeWaitOpenDemoStart();
    void exeWaitCameraInterpole();
    void exeOpenDemo();
    void exeOpenWait();

private:
    u8 filler[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CageSwitch) == 0x120);
