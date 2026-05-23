#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class CityBuilding : public al::LiveActor {
public:
    CityBuilding(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void listenDemoStart();
    void listenBattleStart();
    void listenBattleEnd();
    void listenKill();
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWaitScenario1();
    void exeMofumofuDemo();
    void exeLightOff();
    void exeLightUp();

private:
    void exeWaitScenario2_();
    u8 filler[0x110 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CityBuilding) == 0x110);
