#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class RhythmSpotlight : public al::LiveActor {
public:
    RhythmSpotlight(const char* name);
    void init(const al::ActorInitInfo& info) override;
    f32 readLightPatternData(s32 patternIndex);
    void setLightIntensity(f32 lightIntensity);
    void control() override;
    u64 setLightColor(const sead::Vector3f& pos);
    u64 setLightColorRedComponent(f32 lightColorRedComponent);
    u64 setLightColorGreenComponent(f32 lightColorGreenComponent);
    u64 setLightColorBlueComponent(f32 lightColorBlueComponent);
    void setLightOn();
    void setFadeOutStart(f32 fadeOutStart);
    void setLightOff();
    void setActionRotate();
    void setLightXZAperture(f32 lightXZAperture);
    void setLightBeamRadius(f32 lightBeamRadius);
    void setLightYReach(f32 lightYReach);
    void setLightTiltX(f32 lightTiltX);
    void exeRotating();
    void setActionFrameRate(f32 actionFrameRate);
    void exeOff();
    void setHoldActionAtFrame(f32 holdActionAtFrame);
    void toggleRotationSense();
    void setLightTilt(const sead::Vector3f& pos);
    void setLightTiltY(f32 lightTiltY);
    void setLightTiltZ(f32 lightTiltZ);

private:
    u8 filler[0x148 - sizeof(al::LiveActor)];
};

static_assert(sizeof(RhythmSpotlight) == 0x148);
