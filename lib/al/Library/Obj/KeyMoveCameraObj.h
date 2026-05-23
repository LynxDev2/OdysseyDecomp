#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
class CameraPoser;
class CameraTicket;
struct ActorInitInfo;

class KeyMoveCameraObj : public LiveActor {
public:
    KeyMoveCameraObj(const char* name);
    void init(const ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void switchCamera(s32 camera);
    void appear() override;
    void control() override;
    s64 getCurrentCamera() const;
    s64 getCurrentCameraTicket() const;
    void kill() override;
    void setFirstCameraStartInterpoleStepDefault();
    bool validateStartAtNearestPosition();
    void setPlaySumStep(s32 playSumStep);
    void setEndWaitStep(s32 endWaitStep);

private:
    bool* _108;
    CameraPoser** _110;
    CameraTicket** _118;
    s32 _120;
    s32 _124;
};

static_assert(sizeof(KeyMoveCameraObj) == 0x128);
}  // namespace al
