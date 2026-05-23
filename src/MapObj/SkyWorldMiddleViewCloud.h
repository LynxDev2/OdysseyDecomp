#pragma once

#include <basis/seadTypes.h>

#include "Library/Obj/Sky.h"

class SkyWorldMiddleViewCloud : public al::Sky {
public:
    SkyWorldMiddleViewCloud(const char* name);
    void control() override;

private:
    u8 filler[0x128 - sizeof(al::Sky)];
};

static_assert(sizeof(SkyWorldMiddleViewCloud) == 0x128);
