#include "Library/HitSensor/SensorFunction.h"

#include "Library/Base/StringUtil.h"
#include "Library/HitSensor/HitSensorKeeper.h"
#include "Library/LiveActor/LiveActor.h"
#include "Project/HitSensor/HitSensor.h"

void alSensorFunction::clearHitSensors(al::LiveActor* actor) {
    actor->getHitSensorKeeper()->clear();
}

void alSensorFunction::updateHitSensorsAll(al::LiveActor* actor) {
    actor->getHitSensorKeeper()->update();
}

al::HitSensorType alSensorFunction::findSensorTypeByName(const char* name) {
    for(s32 i=0; i<25; i++) {
        if(al::isEqualString(sensorTypeNameToTypeMap[i].name, name))
            return sensorTypeNameToTypeMap[i].sensorType;
    }
    return al::HitSensorType::MapObj;
}
