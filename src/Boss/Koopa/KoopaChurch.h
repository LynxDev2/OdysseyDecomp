#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

#include "Demo/IUseDemoSkip.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class IUseDemoSkip;

class KoopaChurch : public al::LiveActor, public IUseDemoSkip {
public:
    KoopaChurch(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isFirstDemo() const;
    void skipDemo() override;
    void exeBeforeEnter();
    void exeDemoEnter();
    void exeWait();
    void exeDemoChurch();
    void exeChangeStage();
    void exeEnd();
    bool isEnableSkipDemo() const override;

private:
    u8 filler[0x148 - sizeof(al::LiveActor) - sizeof(IUseDemoSkip)];
};

static_assert(sizeof(KoopaChurch) == 0x148);
