#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class ReactionObject : public al::LiveActor {
public:
    ReactionObject(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initReactionObject(const al::ActorInitInfo& info, const char* reactionObjectName);
    void startSwitchOn();
    void initAfterPlacement() override;
    bool isExistItem() const;
    void control() override;
    void movement() override;
    void calcAnim() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    void exeWait();
    void exeEnd();
    void exeBlow();
    void appearItem(al::HitSensor* sensor);
    void exeReaction();
    bool isReaction() const;
    bool isNerveWait() const;

private:
    u8 filler[0x218 - sizeof(al::LiveActor)];
};

static_assert(sizeof(ReactionObject) == 0x218);
