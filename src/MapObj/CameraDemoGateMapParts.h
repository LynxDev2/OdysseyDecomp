#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class CameraDemoGateMapParts : public al::LiveActor {
public:
    CameraDemoGateMapParts(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void start();
    void appearAndSetStart();
    void exeWait();
    void exeCamera();
    void exeOpen();
    f32 updatePose(f32 pose);
    void exeBound();
    void exeEnd();

private:
    u8 filler[0x170 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CameraDemoGateMapParts) == 0x170);
