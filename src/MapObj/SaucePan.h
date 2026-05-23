#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class SaucePanItemInfo;

class SaucePan : public al::LiveActor {
public:
    SaucePan(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeAnimReaction();
    void exeInNoDemo();
    bool tryUpdateItems();
    void exeReaction();
    void exeReactionBubbleIn();
    void exeAppearShineBubbleIn();
    f32 calcInDemoEndPos(sead::Vector3f* pos) const;
    bool tryUpdateItem(SaucePanItemInfo* saucePanItemInfo);

private:
    u8 filler[0x140 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SaucePan) == 0x140);
