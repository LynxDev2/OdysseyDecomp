#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class CageShineWatcher : public al::LiveActor {
public:
    CageShineWatcher(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initBySwitch();
    void initAfterPlacement() override;
    void syncShineGetCamera();
    void startBreakDemo();
    bool isSameShine(const Shine* shine) const;
    void exeShineWatch();
    void exeWaitCameraStart();
    void exeCameraInterpole();
    void exeBreak();
    const sead::Vector3f& endBreakDemo();
    const sead::Vector3f& exeWaitEntranceCameraStart();
    void exeLinkSwitchWatch();
    bool isSwitchOn() const;

private:
    u8 filler[0x180 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CageShineWatcher) == 0x180);
