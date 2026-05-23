#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class Pen : public al::LiveActor {
public:
    Pen(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void onAppear();
    void onKill();
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeDisappear();

private:
    u8 filler[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Pen) == 0x120);
