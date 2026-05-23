#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Closet : public al::LiveActor {
public:
    Closet(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    bool isOpenEnd();
    bool isSelect();
    bool tryCloseDoor();
    void exeWait();
    void exeOpen();
    void exeSelect();
    void exeClose();
    void exeWearEnd();
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;

private:
    u8 filler[0x140 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Closet) == 0x140);
