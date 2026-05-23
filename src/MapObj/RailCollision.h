#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class RailCollision : public al::LiveActor {
public:
    RailCollision(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void appendVertexUnit(bool isReverse);
    void onAppear();
    void offAppear();
    void startClipped() override;
    void endClipped() override;
    void control() override;
    void appear() override;
    void kill() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeStandby();
    bool tryEmitEffect();
    void updateIvyEffect();
    void moveAndCreate();
    void updateCollision();
    void exeMove();

private:
    u8 filler[0x280 - sizeof(al::LiveActor)];
};

static_assert(sizeof(RailCollision) == 0x280);
