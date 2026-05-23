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

class DokanMaze : public al::LiveActor, public IUseDimension {
public:
    DokanMaze(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void appear() override;
    void kill() override;
    void control() override;
    void endClipped() override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void startAppear();
    void startDisappear();
    bool tryStartObjectCamera();
    bool tryEndObjectCamera();
    bool tryStartKeyMoveCamera();
    bool isEndKeyMoveCamera() const;
    void exeWait();
    void exeReadyBind();
    void exeIn();
    void exeWaitCameraInterpolate();
    void exeWaitCameraKeyMove();
    void exeWaitAppear();
    void exeOut();
    void exeWaitDisappear();
    void exeAppear();
    void exeDisappear();
    bool isAppearStart();
    void setIsExitOnly();
    ActorDimensionKeeper* getActorDimensionKeeper() const override;

private:
    u8 filler[0x168 - sizeof(al::LiveActor) - sizeof(IUseDimension)];
};

static_assert(sizeof(DokanMaze) == 0x168);
