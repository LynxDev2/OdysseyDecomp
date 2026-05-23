#pragma once

#include <basis/seadTypes.h>

#include "Demo/StageEventDemoBase.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class OpeningStageStartDemo : public StageEventDemoBase {
public:
    OpeningStageStartDemo(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void startDemo();
    void startCamera(al::CameraTicket* cameraTicket, s32 camera);
    void endDemo();
    bool isDemoLastStep() const;
    bool isEndDemo() const;
    bool isDrawLayout() const;
    void exeWait();
    void exeBeforeCameraAuto();
    void exeCameraAuto();
    void exeCameraTutorial();
    void endCamera(s32 camera);
    void exeWaitShowStandUpGuide();
    void exeWaitStandUp();
    void exeStandUp();

private:
    u8 filler[0x170 - sizeof(StageEventDemoBase)];
};

static_assert(sizeof(OpeningStageStartDemo) == 0x170);
