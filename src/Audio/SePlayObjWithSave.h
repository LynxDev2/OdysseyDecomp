#pragma once

#include <basis/seadTypes.h>

#include "Library/Obj/SePlayObj.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class SePlayObjWithSave : public al::SePlayObj {
public:
    SePlayObjWithSave(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;

private:
    u8 filler[0x1A0 - sizeof(al::SePlayObj)];
};

static_assert(sizeof(SePlayObjWithSave) == 0x1A0);
