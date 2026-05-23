#pragma once

#include <basis/seadTypes.h>

#include "Library/MapObj/FixMapParts.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class FixMapPartsCapHanger : public al::FixMapParts {
public:
    FixMapPartsCapHanger(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void movement();  // Function should be implemented in header
    void calcAnim();  // Function should be implemented in header
private:
    u8 filler[0x120 - sizeof(al::FixMapParts)];
};

static_assert(sizeof(FixMapPartsCapHanger) == 0x120);
