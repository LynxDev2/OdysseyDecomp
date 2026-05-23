#pragma once

#include <basis/seadTypes.h>

#include "MapObj/ReactionObject.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class ReactionObjectSkyRhythm : public ReactionObject {
public:
    ReactionObjectSkyRhythm(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void endClipped() override;
    s64 getSyncFrame() const;
    void control() override;

private:
    u8 filler[0x248 - sizeof(ReactionObject)];
};

static_assert(sizeof(ReactionObjectSkyRhythm) == 0x248);
