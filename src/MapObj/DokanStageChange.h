#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

#include "Util/IUseDimension.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class ActorDimensionKeeper;

class DokanStageChange : public al::LiveActor, public IUseDimension {
public:
    DokanStageChange(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void appear() override;
    void kill() override;
    void control() override;
    void endClipped() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();
    void exeReadyBind();
    void exeIn();
    void exeAppear();
    void exeOut();
    void exeDisappear();
    ActorDimensionKeeper* getActorDimensionKeeper() const override;

private:
    u8 filler[0x160 - sizeof(al::LiveActor) - sizeof(IUseDimension)];
};

static_assert(sizeof(DokanStageChange) == 0x160);
