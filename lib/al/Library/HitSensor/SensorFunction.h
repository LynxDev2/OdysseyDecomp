#pragma once

#include <basis/seadTypes.h>
#include "Project/HitSensor/HitSensor.h"

namespace al {
class LiveActor;
}

namespace alSensorFunction {

struct NameToSensorType {
    const char* name;
    const al::HitSensorType sensorType;
};

static NameToSensorType sensorTypeNameToTypeMap[] = {
    {"Player", al::HitSensorType::Player},
    {"PlayerAttack", al::HitSensorType::PlayerAttack},
    {"PlayerFoot", al::HitSensorType::PlayerFoot},
    {"PlayerDecoration", al::HitSensorType::PlayerDecoration},
    {"PlayerEye", al::HitSensorType::PlayerEye},
    {"Npc", al::HitSensorType::Npc},
    {"Ride", al::HitSensorType::Ride},
    {"Enemy", al::HitSensorType::Enemy},
    {"EnemyBody", al::HitSensorType::EnemyBody},
    {"EnemyAttack", al::HitSensorType::EnemyAttack},
    {"EnemySimple", al::HitSensorType::EnemySimple},
    {"MapObj", al::HitSensorType::MapObj},
    {"MapObjSimple", al::HitSensorType::MapObjSimple},
    {"CollisionParts", al::HitSensorType::CollisionParts},
    {"PlayerFireBall", al::HitSensorType::PlayerFireBall},
    {"HoldObj", al::HitSensorType::HoldObj},
    {"LookAt", al::HitSensorType::LookAt},
    {"BindableGoal", al::HitSensorType::BindableGoal},
    {"BindableAllPlayer", al::HitSensorType::BindableAllPlayer},
    {"BindableBubbleOutScreen", al::HitSensorType::BindableBubbleOutScreen},
    {"BindableKoura", al::HitSensorType::BindableKoura},
    {"BindableRouteDokan", al::HitSensorType::BindableRouteDokan},
    {"BindableBubblePadInput", al::HitSensorType::BindableBubblePadInput},
    {"Bindable", al::HitSensorType::Bindable}};

void updateHitSensorsAll(al::LiveActor*);
void clearHitSensors(al::LiveActor*);

al::HitSensorType findSensorTypeByName(const char*);

}  // namespace alSensorFunction
