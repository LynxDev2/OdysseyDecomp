#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class WaveSurfMapParts : public al::LiveActor {
public:
    WaveSurfMapParts(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isExistSurface() const;
    void control() override;
    void updateFinder();
    void approachSurface();
    void syncSurfaceUp();
    void exeWait();
    void exeSink();
    void exeSinkDeep();
    f32 getSurfaceHeight() const;

private:
    u8 filler[0x158 - sizeof(al::LiveActor)];
};

static_assert(sizeof(WaveSurfMapParts) == 0x158);
