#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class OceanWaveActor : public al::LiveActor {
public:
    OceanWaveActor(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initOceanPreset();
    void initCloudPreset();
    void onSnapShotMode();
    void offSnapShotMode();
    bool tryLoadPreset();
    void initAfterPlacement() override;
    void makeActorAlive() override;
    void makeActorDead() override;
    void control() override;
    bool isSodaOcean() const;
    bool calcIsInArea(const sead::Vector3f& pos) const;
    const sead::Vector3f& calcPos(sead::Vector3f* outPos, const sead::Vector3f& samplePos) const;
    void calcNormal(sead::Vector3f* outPos, const sead::Vector3f& pos) const;
    void calcVelocity(sead::Vector3f* outVelocity, const sead::Vector3f& samplePos) const;

private:
    u8 filler[0x198 - sizeof(al::LiveActor)];
};

static_assert(sizeof(OceanWaveActor) == 0x198);
