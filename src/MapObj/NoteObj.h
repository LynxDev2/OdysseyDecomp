#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class NoteObjDirector;

class NoteObj : public al::LiveActor {
public:
    NoteObj(const char* name, NoteObjDirector* noteObjDirector = nullptr);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void appear() override;
    void kill() override;
    s64 reAppear();
    void control() override;
    void updateReaction();
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool tryStartDisappear();
    const sead::Vector3f& tryAppearShine();
    void setShadowDropLength(f32 shadowDropLength);
    void exeAppear();
    void exeWait();
    void exeGot();
    void exeDisappear();

private:
    u8 filler[0x148 - sizeof(al::LiveActor)];
};

static_assert(sizeof(NoteObj) == 0x148);
