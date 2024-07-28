#pragma once

#include <gfx/seadFrameBuffer.h>

namespace agl {
    class DrawContext;
}

namespace al { 
class GraphicsInitArg
{
public:
    GraphicsInitArg(agl::DrawContext*, sead::FrameBuffer*);
};
}
