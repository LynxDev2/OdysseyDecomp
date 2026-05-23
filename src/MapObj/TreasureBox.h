#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class TreasureBox : public al::LiveActor {
public:
    TreasureBox(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void changeOpenCollision();
    void setupOpenNerve();
    void exeWait();
    void exeTrampleReaction();
    void exeOpen();
    void exeBounce();
    void exeSenobiBounce();
    void exeOpenWait();
    void exeOpenTouchReaction();
    void exeOpenReaction();

private:
    u8 filler[0x158 - sizeof(al::LiveActor)];
};

static_assert(sizeof(TreasureBox) == 0x158);
