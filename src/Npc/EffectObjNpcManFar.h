#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class EffectObjNpcManFar : public al::LiveActor {
public:
    EffectObjNpcManFar(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void startClipped() override;
    void endClipped() override;
    void exeOn();
    void exeOff();
    const sead::Matrix34f* getBaseMtx() const override;

private:
    u8 filler[0x138 - sizeof(al::LiveActor)];
};

static_assert(sizeof(EffectObjNpcManFar) == 0x138);
