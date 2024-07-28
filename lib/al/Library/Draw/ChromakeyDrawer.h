#pragma once

#include "Library/Graphics/IUsePartsGraphics.h"

namespace al {
class ChromakeyDrawer : public al::IUsePartsGraphics{
public:
    void finalize() override;
};
}
