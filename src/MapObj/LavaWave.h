#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/Fluid/IUseFluidSurface.h"
#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class LavaWave : public al::LiveActor, public al::IUseFluidSurface {
public:
    LavaWave(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void control() override;
    f32 calcCoord(sead::Vector2i* screenPos, const sead::Vector3f& pos, s32 coord) const;
    f32 startEndDemoBossMagma();
    void setEndDemoParamBossMagma(const sead::Vector3f& pos, s32 endDemoParamBossMagma);
    f32 endEndDemoBossMagma();
    bool tryKillEmitterAndParticleAll();
    bool calcIsInArea(const sead::Vector3f& pos) const;
    void calcPos(sead::Vector3f* outPos, const sead::Vector3f& samplePos) const override;
    void calcPosFlat(sead::Vector3f* outPos, const sead::Vector3f& samplePos) const override;
    void calcNormal(sead::Vector3f* outPos, const sead::Vector3f& pos) const;
    bool tryAddRipple(const sead::Vector3f& ripplePos, f32 radius, f32 power);
    bool tryAddRippleWithRange(const sead::Vector3f& ripplePos, f32 radius, f32 power, f32 minRange,
                               f32 maxRange);
    bool tryAddQuadRipple(const sead::Vector3f& cornerA, const sead::Vector3f& cornerB,
                          const sead::Vector3f& cornerC, const sead::Vector3f& cornerD, f32 power);
    const char* getTypeName() const override;

private:
    u8 filler[0x1A0 - sizeof(al::LiveActor) - sizeof(al::IUseFluidSurface)];
};

static_assert(sizeof(LavaWave) == 0x1A0);
