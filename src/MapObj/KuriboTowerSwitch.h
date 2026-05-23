#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class KuriboTowerSwitch : public al::LiveActor {
public:
    KuriboTowerSwitch(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isReactionNerve() const;
    void exeDisable();
    void exeOffWait();
    void exeReactionLand();
    void exeOn();
    void exeOnWait();

private:
    u8 filler[0x130 - sizeof(al::LiveActor)];
};

static_assert(sizeof(KuriboTowerSwitch) == 0x130);
