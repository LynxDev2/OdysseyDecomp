#include "Project/HitSensor/HitSensorDirector.h"

#include "Library/Execute/ExecuteDirector.h"
#include "Library/Execute/ExecuteTableHolderUpdate.h"
#include "Library/LiveActor/ActorSensorFunction.h"
#include "Project/HitSensor/HitSensor.h"
#include "Project/HitSensor/SensorHitGroup.h"

namespace al {
HitSensorDirector::HitSensorDirector(ExecuteDirector* dir) {
    mPlayer = new SensorHitGroup(256, "Player");
    mPlayerEye = new SensorHitGroup(128, "PlayerEye");
    mRide = new SensorHitGroup(128, "Ride");
    mEye = new SensorHitGroup(1024, "Eye");
    mLookAt = new SensorHitGroup(512, "LookAt");
    mSimple = new SensorHitGroup(1536, "Simple");
    mMapObj = new SensorHitGroup(1536, "MapObj");
    mCharacter = new SensorHitGroup(1024, "Character");
    al::registerExecutorUser(this, dir, "センサー");
}

void HitSensorDirector::execute() {
    mPlayer->clear();
    mPlayerEye->clear();
    mRide->clear();
    mEye->clear();
    mLookAt->clear();
    mSimple->clear();
    mMapObj->clear();
    mCharacter->clear();
    executeHitCheckInSameGroup(mPlayer);
    executeHitCheckGroup(mPlayer, mPlayerEye);
    executeHitCheckGroup(mPlayer, mCharacter);
    executeHitCheckGroup(mPlayer, mMapObj);
    executeHitCheckGroup(mPlayer, mRide);
    executeHitCheckGroup(mPlayer, mSimple);
    executeHitCheckGroup(mPlayer, mEye);
    executeHitCheckGroup(mPlayerEye, mCharacter);
    executeHitCheckGroup(mPlayerEye, mMapObj);
    executeHitCheckGroup(mPlayerEye, mRide);
    executeHitCheckGroup(mPlayerEye, mSimple);
    executeHitCheckGroup(mPlayerEye, mLookAt);
    executeHitCheckGroup(mRide, mCharacter);
    executeHitCheckGroup(mRide, mMapObj);
    executeHitCheckGroup(mRide, mSimple);
    executeHitCheckGroup(mRide, mEye);
    executeHitCheckGroup(mEye, mCharacter);
    executeHitCheckGroup(mEye, mMapObj);
    executeHitCheckGroup(mEye, mSimple);
    executeHitCheckGroup(mEye, mLookAt);
    executeHitCheckGroup(mCharacter, mMapObj);
    executeHitCheckInSameGroup(mCharacter);
}

void HitSensorDirector::executeHitCheckInSameGroup(SensorHitGroup* group) const {
    // Forces the this pointer to be passed in to match execute
    asm volatile("" : : "r"(this) : "memory");

    int sensorCount = group->getSensorCount();
    for (s32 i = 0; i < sensorCount; i++) {
        auto* sensor = group->getSensor(i);
        // only loop trough sensors after i to avoid the same pair
        for (s32 j = i; j != sensorCount; j++) {
            auto* otherSensor = group->getSensor(j);
            if (sensor->mParentActor != otherSensor->mParentActor) {
                sead::Vector3f distance = (sensor->mPos - otherSensor->mPos);
                float combinedRadius = sensor->mRadius + otherSensor->mRadius;
                if (distance.squaredLength() >= combinedRadius * combinedRadius)
                    continue;
                if (otherSensor->mSensorType != HitSensorType::Eye &&
                    otherSensor->mSensorType != HitSensorType::PlayerEye)
                    sensor->addHitSensor(otherSensor);
                if (sensor->mSensorType != HitSensorType::Eye &&
                    sensor->mSensorType != HitSensorType::PlayerEye)
                    otherSensor->addHitSensor(sensor);
            }
        }
    }
}

void HitSensorDirector::executeHitCheckGroup(SensorHitGroup* group, SensorHitGroup* group2) const {
    // Same as above
    asm volatile("" : : "r"(this) : "memory");

    s32 sensorCount = group->getSensorCount();
    for (s32 i = 0; i < sensorCount; i++) {
        auto* sensor = group->getSensor(i);
        s32 group2SensorCount = group2->getSensorCount();
        for (s32 j = 0; j < group2SensorCount; j++) {
            auto* otherSensor = group2->getSensor(j);
            if (sensor->mParentActor != otherSensor->mParentActor) {
                sead::Vector3f distance = (sensor->mPos - otherSensor->mPos);
                float combinedRadius = sensor->mRadius + otherSensor->mRadius;
                if (distance.squaredLength() >= combinedRadius * combinedRadius)
                    continue;
                if (otherSensor->mSensorType != HitSensorType::Eye &&
                    otherSensor->mSensorType != HitSensorType::PlayerEye)
                    sensor->addHitSensor(otherSensor);
                if (sensor->mSensorType != HitSensorType::Eye &&
                    sensor->mSensorType != HitSensorType::PlayerEye)
                    otherSensor->addHitSensor(sensor);
            }
        }
    }
}

// Seems to be unused
void HitSensorDirector::executeHitCheck(HitSensor* sensor, HitSensor* otherSensor) const {
    if (sensor->mParentActor != otherSensor->mParentActor) {
        sead::Vector3f distance = (sensor->mPos - otherSensor->mPos);
        float combinedRadius = sensor->mRadius + otherSensor->mRadius;
        if (distance.squaredLength() >= combinedRadius * combinedRadius)
            return;
        if (otherSensor->mSensorType != HitSensorType::Eye &&
            otherSensor->mSensorType != HitSensorType::PlayerEye)
            sensor->addHitSensor(otherSensor);
        if (sensor->mSensorType != HitSensorType::Eye &&
            sensor->mSensorType != HitSensorType::PlayerEye)
            otherSensor->addHitSensor(sensor);
    }
}

void HitSensorDirector::initGroup(HitSensor* sensor) {
    if (al::isSensorPlayerEye(sensor)) {
        sensor->mHitGroup = mPlayerEye;
        return;
    }
    if (al::isSensorPlayerAll(sensor)) {
        sensor->mHitGroup = mPlayer;
        return;
    }
    if (al::isSensorRide(sensor)) {
        sensor->mHitGroup = mRide;
        return;
    }
    if (al::isSensorEye(sensor)) {
        sensor->mHitGroup = mEye;
        return;
    }
    if (al::isSensorSimple(sensor)) {
        sensor->mHitGroup = mSimple;
        return;
    }
    if (al::isSensorMapObj(sensor)) {
        sensor->mHitGroup = mMapObj;
        return;
    }
    if (al::isSensorLookAt(sensor)) {
        sensor->mHitGroup = mLookAt;
        return;
    }
    sensor->mHitGroup = mCharacter;
}

}  // namespace al