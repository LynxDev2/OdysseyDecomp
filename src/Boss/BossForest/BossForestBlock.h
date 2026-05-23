#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
class PlacementInfo;
}  // namespace al

class BossForestBlock : public al::LiveActor {
public:
    bool isArgBlockTypeSatellite(const al::PlacementInfo& placementInfo);
    BossForestBlock(const char* name, bool bossForestBlock = false);
    void init(const al::ActorInitInfo& info) override;
    void appear() override;
    void kill() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool tryReaction();
    bool isBreaking() const;
    bool isStateWait() const;
    void startMove();
    void endMove();
    s64 goWait();
    void updateEmptyModel();
    void exeAppear();
    void exeWait();
    void exeReaction();
    void exeMoveStart();
    void exeMove();
    void exeMoveEnd();
    void exeEmpty();

private:
    u8 filler[0x140 - sizeof(al::LiveActor)];
};

static_assert(sizeof(BossForestBlock) == 0x140);
