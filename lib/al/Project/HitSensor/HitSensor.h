#pragma once

#include <math/seadMatrix.h>
#include <math/seadVector.h>

#include "Project/HitSensor/HitSensorDirector.h"
#include "Project/HitSensor/SensorHitGroup.h"
#include "container/seadPtrArray.h"
#include "math/seadVectorFwd.h"

/*
namespace std {
    template<typename A, typename B>
    void sort(al::HitSensor*, al::HitSensor*, A);
}
*/

namespace al {
class LiveActor;
class HitSensorDirectror;
class HitSensorKeeper;

using SensorSortCmpFunc = bool (*)(al::HitSensor* a, al::HitSensor* b);

/*
enum class HitSensorType : u32 {
    Player,
    PlayerAttack,
    PlayerFoot,
    PlayerDecoration,
    PlayerEye,
    Npc,
    Ride,
    Enemy,
    EnemyBody,
    EnemyAttack,
    EnemySimple,
    MapObj,
    MapObjSimple,
    CollisionParts,
    PlayerFireBall,
    HoldObj,
    LookAt,
    BindableGoal,
    BindableAllPlayer,
    BindableBubbleOutScreen,
    BindableKoura,
    BindableRouteDokan,
    BindableBubblePadInput,
    Bindable
};
*/

enum class HitSensorType : u32 {
    Eye = 0,
    Player = 1,
    PlayerAttack = 2,
    PlayerFoot = 3,
    PlayerDecoration = 4,
    PlayerEye = 5,
    Npc = 6,
    Ride = 7,
    Enemy = 8,
    EnemyBody = 9,
    EnemyAttack = 10,
    EnemySimple = 11,
    MapObj = 12,
    MapObjSimple = 13,
    Bindable = 14,
    CollisionParts = 15,
    PlayerFireBall = 16,
    HoldObj = 17,
    LookAt = 18,
    BindableGoal = 19,
    BindableAllPlayer = 20,
    BindableBubbleOutScreen = 21,
    BindableKoura = 22,
    BindableRouteDokan = 23,
    BindableBubblePadInput = 24
};

class HitSensor {
public:

    HitSensor(LiveActor* parentActor, const char* name, u32 hitSensorType, f32 radius,
              u16 maxSensorCount, const sead::Vector3f* followPos,
              const sead::Matrix34f* followMatrix, const sead::Vector3f& offset);

    bool trySensorSort();
    void setFollowPosPtr(const sead::Vector3f*);
    void setFollowMtxPtr(const sead::Matrix34f*);
    void validate();
    void invalidate();
    void validateBySystem();
    void invalidateBySystem();
    void update();
    void addHitSensor(HitSensor*);
/*
    template <typename T, typename Compare>
    void sort_(Compare cmp){
        std::sort(mSensors, mSensors + mSensors->size(), [&](const void* a, const void* b) {
            return cmp(static_cast<const T*>(a), static_cast<const T*>(b));
        }); 
    }
*/

    // Use these plus a few for HitSensorDirector or use friend classes?
    /*
    u16 getSensorCount() const { return mSensorCount; }
    al::HitSensor* getSubSensor(s32 index) const { return mSensors[index]; }
    al::LiveActor* getParentActor() const { return mParentActor; }
    */

    void setSensorCountZero() { mSensorCount = 0; }
    void setRadius(float radius) { mRadius = radius; }
    float getRadius() const { return mRadius; }
    const sead::Vector3f& getPos() const { return mPos; }
    void setOffset(const sead::Vector3f& offset) { 
        mOffset.set(offset);
    }
    const sead::Vector3f& getOffset() const { return mOffset; }
    al::LiveActor* getParentActor() const { return mParentActor; }
    bool isInvalidOrInvalidBySystem() const { return !mIsValid || !mIsValidBySystem; }
    bool isValid() const { return mIsValid && mIsValidBySystem; };
    const char* getName() const { return mName; }
    HitSensorType getType() const { return mSensorType; }

private:
    const char* mName;  // _0
    HitSensorType mSensorType;
    sead::Vector3f mPos = {.0f, .0f, .0f};
    f32 mRadius;
    u16 mMaxSensorCount;             // _1C
    u16 mSensorCount = 0;            // _1E
    HitSensor** mSensors = nullptr;  // _20
    SensorSortCmpFunc* mSortFunctionPtr = nullptr;
    SensorHitGroup* mHitGroup = nullptr;      // _30
    bool mIsValidBySystem = false;  // _38
    bool mIsValid = true;           // _39
    bool _3a[4];                    // unknown type
    u16 _3e;
    LiveActor* mParentActor;                // _40
    const sead::Vector3f* mFollowPos;       // _48
    const sead::Matrix34f* mFollowMtx;  // _50  bool mIsValidBySystem;
    sead::Vector3f mOffset;

    friend class HitSensorDirector;
    friend class HitSensorKeeper;
};
}  // namespace al
