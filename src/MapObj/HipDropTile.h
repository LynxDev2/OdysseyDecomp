#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class HipDropTile : public al::LiveActor {
public:
    HipDropTile(const char* name);
    HipDropTile(u32 hipDropTile, const char* hipDropTileName = nullptr);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeWaitPlayerOnTop();
    void exePressDown();
    void exeShowPopup();
    void exePlayerHopOn();
    s64 shake();
    void exePlayerHopOff();

private:
    u8 filler[0x138 - sizeof(al::LiveActor)];
};

static_assert(sizeof(HipDropTile) == 0x138);
