#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class CapMessageAfterInformation : public al::LiveActor {
public:
    CapMessageAfterInformation(const char* name);
    void makeActorDead() override;
    void init(const al::ActorInitInfo& info) override;
    void exeWait();
    bool isEnable() const;
    void exeShow();
    const sead::Vector3f& endShow();

private:
    u8 filler[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CapMessageAfterInformation) == 0x120);
