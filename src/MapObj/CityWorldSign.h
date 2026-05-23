#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class CityWorldSign : public al::LiveActor {
public:
    CityWorldSign(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    const sead::Vector3f& controlForDance();
    void setLightAnim(s32 lightAnim);
    void setTexturePattern(s32 texturePattern);
    void changeActionByBgmAnim(s32 actionIndex, s32 animIndex);
    void setAnimWaitA(s32 animWaitA);
    void setAnimWaitB(s32 animWaitB);
    void setAnimMoveAToB(s32 animMoveAToB);
    void setAnimMoveBToA(s32 animMoveBToA);
    void exeMoveAtoB();
    void exeWaitB();
    void exeMoveBtoA();
    void exeWaitA();

private:
    u8 filler[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CityWorldSign) == 0x120);
