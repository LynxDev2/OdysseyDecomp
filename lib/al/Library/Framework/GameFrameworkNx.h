#pragma once

#include <framework/nx/seadGameFrameworkNx.h>

#include "Library/HostIO/HioNode.h"

namespace agl {
class RenderBuffer;
class DrawContext;
class RenderTargetColor;
class DisplayList;
}  // namespace agl

namespace al {

class GpuPerf;

class GameFrameworkNx : public sead::GameFrameworkNx, public al::HioNode {
public:
    agl::DrawContext* mDrawContext;
    agl::RenderBuffer* mRenderBuffer1;
    agl::RenderTargetColor* mRenderTargetColor1;
    agl::RenderBuffer* mRenderBuffer2;
    agl::RenderTargetColor* mRenderTargetColor2;
    agl::DisplayList* mDisplayList1;
    agl::DisplayList* mDisplayList2;
    al::GpuPerf* mGpuPerf;
    void* gap[3];
    bool mHasNoScene;
    void* filler[3];
};
}  // namespace al
