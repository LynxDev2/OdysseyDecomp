#pragma once

#include <basis/seadTypes.h>
#include <gfx/seadColor.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

namespace agl {
class DrawContext;
class TextureData;
}  // namespace agl

class DrawRequest;

class PaintObj : public al::LiveActor {
public:
    PaintObj(const char* name);
    ~PaintObj();
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void switchOn();
    void switchOff();
    void reset();
    void switchKill();
    void switchStop();
    void control() override;
    u64 checkPaintAlpha(const sead::Vector2i& screenPos) const;
    void onClipped();
    void requestDrawPlot(const DrawRequest* drawRequest) const;
    void requestDrawTexture(const DrawRequest* drawRequest) const;
    void draw() const override;
    void drawNrm(agl::TextureData* baseTexture, agl::TextureData* normalTexture, s32 x, s32 y,
                 s32 width, s32 height) const;
    void drawBlurAndNormal() const;
    s64 drawLabelingAndVanish(const sead::Vector2i& screenPosMin,
                              const sead::Vector2i& screenPosMax, agl::DrawContext* drawContext,
                              const sead::Vector2i& labelMin, const sead::Vector2i& labelMax) const;
    f32 calcCoord(sead::Vector2i* outScreenPos, const sead::Vector3f& worldPos,
                  const sead::Vector2i& screenSize) const;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    void appendNrmDrawRequest(const sead::Vector2i& screenPos, s32 drawScale, al::HitSensor* self);
    bool checkPaintClear(const sead::Vector3f& worldPos, const sead::Color4u8& paintColor,
                         s32 clearType) const;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    s64 medianFilter(agl::TextureData* textureData, const sead::Vector2i& screenPosMin,
                     const sead::Vector2i& screenPosMax);
    void exeWait();

private:
    u8 filler[0x207BD0 - sizeof(al::LiveActor)];
};

static_assert(sizeof(PaintObj) == 0x207BD0);
