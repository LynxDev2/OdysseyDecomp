#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class FireHydrant : public al::LiveActor {
public:
    FireHydrant(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    void exeWait();
    void exeSquirtStart();
    void exeSquirtLoop();
    void exeSquirtStop();
    void exeForbidSquirt();

private:
    u8 filler[0x130 - sizeof(al::LiveActor)];
};

static_assert(sizeof(FireHydrant) == 0x130);
