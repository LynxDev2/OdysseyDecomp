#pragma once

namespace al {

//Might be structs?
class GraphicsCopyInfo;
class GraphicsComputeInfo;
class GraphicsRenderInfo;
class RenderVariables;

class IUsePartsGraphics{
public:
    virtual void finalize() = 0;
    virtual void endInit();
    virtual void doCommandBufferCopy(const GraphicsCopyInfo*);
    virtual void doComputeShader(const GraphicsComputeInfo*);
    virtual void drawSystem(const GraphicsRenderInfo*);
    virtual void pure_virtual2() = 0;
    virtual void pure_virtual3() = 0;
    virtual void drawGBufferAfterSky(const GraphicsRenderInfo&);
    virtual void drawForward(const GraphicsRenderInfo&, const RenderVariables&);
    virtual void drawDeferred(const GraphicsRenderInfo&);
    virtual void drawLdr(const GraphicsRenderInfo&);
    virtual void drawIndirect(const GraphicsRenderInfo&, const RenderVariables&);
    virtual void drawCubemap(const GraphicsRenderInfo&);
    virtual void pure_virtual4() = 0;
};
}
