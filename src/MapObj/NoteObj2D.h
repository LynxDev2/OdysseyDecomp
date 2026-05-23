#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

#include "Util/IUseDimension.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class ActorDimensionKeeper;
class NoteObjDirector;

class NoteObj2D : public al::LiveActor, public IUseDimension {
public:
    NoteObj2D(const char* name, NoteObjDirector* noteObjDirector = nullptr);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void appear() override;
    s64 reAppear();
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool tryStartDisappear();
    const sead::Vector3f& tryAppearShine();
    void exeAppear();
    void exeWait();
    void exeGot();
    void exeDisappear();
    void exeUpperPunchReaction();
    ActorDimensionKeeper* getActorDimensionKeeper() const override;

private:
    u8 filler[0x140 - sizeof(al::LiveActor) - sizeof(IUseDimension)];
};

static_assert(sizeof(NoteObj2D) == 0x140);
