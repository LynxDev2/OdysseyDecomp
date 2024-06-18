#pragma once

#include "Library/LiveActor/LiveActor.h"
#include "math/seadVector.h"
#include "math/seadVectorFwd.h"

namespace al{
    class ActorInitInfo;
    class HitSensor;
}

class TankBullet : public al::LiveActor{

public:
    TankBullet(const char* name);
    void init(const al::ActorInitInfo& initInfo) override;
    void attackSensor(al::HitSensor* target, al::HitSensor* source) override;
    void explode();
    void appear() override;
    void disappear();
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* source,
                    al::HitSensor* target) override;
    void shoot(
        const sead::Vector3f& startingPos,
        const sead::Vector3f& bulletVelocity,
        int unusedInt,
        bool isShotByPlayer,
        bool unusedBool);
    void shootByPlayer(const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, const sead::Vector3f&, f32, s32);

    void exeStart();
    void exeMove();
    void exeMovePlayer();
    void exeExplode();
    void exeYoshiEat();

private:
    s32 mUnusedInt = -1;
    bool mIsShotByPlayer = false;
    bool pad_10D[3];
    sead::Vector3f mStartingPos = {0.0f, 0.0f, 0.0f};
    sead::Vector3f mUnkVector3f = {0.0f, 0.0f, 0.0f};
    sead::Vector3f mUnkVector3f2 = {0.0f, 0.0f, 0.0f};
    f32 mUnusedFloat = .0f;
    bool mIsCapAttack = false;
    bool pad_139[7];
};
