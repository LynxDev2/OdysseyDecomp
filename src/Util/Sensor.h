#pragma once

#include "math/seadVectorFwd.h"
namespace al {
class HitSensor;
class SensorMsg;
}  // namespace al

namespace rs {

bool sendMsgEnemyAttack2D(al::HitSensor* source, al::HitSensor* target);
bool sendMsgNoticePlayerDamage(al::HitSensor* source, al::HitSensor* target);
bool sendMsgTouchFireDrum2D(al::HitSensor* source, al::HitSensor* target);
bool sendMsgItemAmiiboKoopa(al::HitSensor* source, al::HitSensor* target);
bool sendMsgWeaponItemGet(al::HitSensor* source, al::HitSensor* target);
bool sendMsgTankExplosion(al::HitSensor* source, al::HitSensor* target);
bool sendMsgTankBulletNoReaction(al::HitSensor* source, al::HitSensor* target);
bool sendMsgTankBullet(al::HitSensor* source, al::HitSensor* target);

bool isMsgCapTouchWall(const al::SensorMsg*);
bool isMsgPlayerDisregardTargetMarker(const al::SensorMsg*);
bool isMsgYoshiTongueEatBind(const al::SensorMsg*);
bool isMsgYoshiTongueEatBindFinish(const al::SensorMsg*);
bool isMsgYoshiTongueEatBindCancel(const al::SensorMsg*);
bool isMsgBlowDown(const al::SensorMsg*);
bool isMsgCapAttack(const al::SensorMsg*);
bool isMsgMotorcycleDashAttack(const al::SensorMsg*);

void setMsgYoshiTongueEatBindRadiusAndOffset(const al::SensorMsg*, float, float);

void requestHitReactionToAttacker(const al::SensorMsg*, const al::HitSensor*, const al::HitSensor*);
void requestHitReactionToAttacker(const al::SensorMsg*, const al::HitSensor*, const sead::Vector3f&);

}  // namespace rs
