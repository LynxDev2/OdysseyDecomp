#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class DoorAreaChangeCap : public al::LiveActor {
public:
    DoorAreaChangeCap(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool isGotShine(const al::ActorInitInfo& info);
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeNoStart();
    void exeCloseWait();
    void exeDelayOpen();
    void exeOpen();
    void exeClose();

private:
    u8 filler[0x260 - sizeof(al::LiveActor)];
};

static_assert(sizeof(DoorAreaChangeCap) == 0x260);
