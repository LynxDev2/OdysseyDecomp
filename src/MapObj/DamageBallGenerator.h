#pragma once

#include <basis/seadTypes.h>
#include <container/seadPtrArray.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class IBgmParamsChanger;
}  // namespace al

class DamageBallGenerator : public al::LiveActor {
public:
    DamageBallGenerator(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void listenStart();
    void listenKill();
    void listenStop();
    void control() override;
    void changeStreinBgmVolume(sead::PtrArray<al::IBgmParamsChanger>* ptrArray, f32* volume) const;
    void resetStreinBgmVolume(sead::PtrArray<al::IBgmParamsChanger>* ptrArray) const;
    void exeWait();
    void exeDelayWait();
    void exeLaunch();
    bool tryLaunch();

private:
    u8 filler[0x168 - sizeof(al::LiveActor)];
};

static_assert(sizeof(DamageBallGenerator) == 0x168);
