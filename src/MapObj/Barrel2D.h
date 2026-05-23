#pragma once

#include <basis/seadTypes.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

#include "Util/IUseDimension.h"

class ActorDimensionKeeper;

class Barrel2D : public al::LiveActor, public IUseDimension {
public:
    Barrel2D(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void appearByGenerator(const sead::Vector3f& pos, const sead::Quatf& quat, f32 byGenerator);
    void startMove();
    void exeWait();
    f32 exeMove();

    ActorDimensionKeeper* getActorDimensionKeeper() const override { return mDimensionKeeper; }

private:
    ActorDimensionKeeper* mDimensionKeeper;
    f32 _118;
    f32 mMoveSpeed;
    f32 _120;
    s32 _124;
    s32 _128;
};

static_assert(sizeof(Barrel2D) == 0x130);
static_assert(sizeof(Barrel2D) == 0x130);
