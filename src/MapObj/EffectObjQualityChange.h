#pragma once

#include <basis/seadTypes.h>

#include "Library/Obj/EffectObj.h"

class EffectObjQualityChange : public al::EffectObj {
public:
    EffectObjQualityChange(const char* name);
    void control() override;
    bool tryEmitStart();

private:
    u8 filler[0x158 - sizeof(al::EffectObj)];
};

static_assert(sizeof(EffectObjQualityChange) == 0x158);
