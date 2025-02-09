#include "Project/HitSensor/HitSensor.h"

#include <container/seadPtrArray.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {

// Symbol doesn't allow the use of an enum nor enum class for the HitSensor type
HitSensor::HitSensor(LiveActor* parentActor, const char* name, u32 hitSensorType, f32 radius,
                     u16 maxSensorCount, const sead::Vector3<f32>* followPos,
                     const sead::Matrix34<f32>* followMatrix, const sead::Vector3<f32>& offset)
    : mName(name), mSensorType((HitSensorType)hitSensorType), mRadius(radius),
      mMaxSensorCount(maxSensorCount), mParentActor(parentActor), mFollowPos(followPos), mFollowMtx(followMatrix),
      mOffset(offset) {
        
    if (maxSensorCount) {
        mSensors = new HitSensor*[mMaxSensorCount];
        for (int i = 0; i < mMaxSensorCount; i++)
            mSensors[i] = nullptr;
    }
}


void HitSensor::setFollowPosPtr(const sead::Vector3f* pFollowPos) {
    mFollowPos = pFollowPos;
    mFollowMtx = nullptr;
}

void HitSensor::setFollowMtxPtr(const sead::Matrix34f* pFollowMtx) {
    mFollowPos = nullptr, mFollowMtx = pFollowMtx;
}

void HitSensor::validate() {
    if (!mIsValid) {
        mIsValid = true;

        if (mMaxSensorCount) {
            if (mIsValidBySystem)
                mHitGroup->add(this);
        }
    }

    mSensorCount = 0;
}

void HitSensor::invalidate() {
    if (mIsValid) {
        mIsValid = false;

        if (mMaxSensorCount) {
            if (mIsValidBySystem)
                mHitGroup->remove(this);
        }
    }

    mSensorCount = 0;
}

void HitSensor::validateBySystem() {
    if (mIsValidBySystem)
        return;
    if (mMaxSensorCount && mIsValid)
        mHitGroup->add(this);
    mIsValidBySystem = true;
    mSensorCount = 0;
}

void HitSensor::invalidateBySystem() {
    if (!mIsValidBySystem)
        return;
    if (mMaxSensorCount && mIsValid)
        mHitGroup->remove(this);
    mIsValidBySystem = false;
    mSensorCount = 0;
}

// HitSensor::update (requires some more LiveActor research)


void HitSensor::addHitSensor(HitSensor* sensor) {
    // todo -- registers are different
    if (mSensorCount < mMaxSensorCount) {
        mSensors[mSensorCount] = sensor;
        mSensorCount++;
    }
}


void al::HitSensor::update() {
    if (mFollowPos) {
        const sead::Matrix34f* parentMtx = mParentActor->getBaseMtx();
        if (parentMtx) {
            mPos.setRotated(*parentMtx, mOffset);
            mPos.add(*mFollowPos);
        } else {
            mPos.x = mFollowPos->x + mOffset.x;
            mPos.y = mFollowPos->y + mOffset.y;
            mPos.z = mFollowPos->z + mOffset.z;
        }
    } else {
        if (mFollowMtx)
            mPos.setMul(*mFollowMtx, mOffset);
    }
}

void HitSensor::trySensorSort() {
    if (mSortFunctionPtr && mSensorCount > 1) {
        std::sort(mSensors, mSensors + mSensorCount, *mSortFunctionPtr);
    }
}

}  // namespace al
