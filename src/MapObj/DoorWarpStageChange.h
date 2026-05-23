#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class DoorWarpStageChange : public al::LiveActor {
public:
    DoorWarpStageChange(const char* name);
    void init(const al::ActorInitInfo& info) override;
    s64 unlock();
    void initAfterPlacement() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeLock();
    void exeUnlock();
    void exeWait();
    void exeMoveToFront();
    void exeOpen();
    void exeClose();
    void exeAppear();
    void exeWaitOut();
    void exeOpenOut();
    void exeCloseOut();
    void exeDisappear();

private:
    u8 filler[0x198 - sizeof(al::LiveActor)];
};

static_assert(sizeof(DoorWarpStageChange) == 0x198);
