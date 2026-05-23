#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
class BgmDataBase;
class PlayParams;
struct ActorInitInfo;

class BgmPlayObj : public LiveActor {
public:
    BgmPlayObj(const char* name, bool isWaitPlayStart = false);
    void init(const ActorInitInfo& info) override;
    void createShape(BgmDataBase* bgmDataBase);
    void init(const ActorInitInfo& info, const char* bgmName);
    void init(const ActorInitInfo& info, const char* bgmName, const char* shapeName,
              const char* switchName);
    void initAfterPlacement() override;
    void appear() override;
    void kill() override;
    void stopBgm(s32 fadeFrame);
    void movement() override;
    bool isEnableCalcSpeakerParam() const;
    s64 calc3DParams(bool isUsePlayParams);
    void finalize();
    f32 getDistanceFromSourceToListener();
    bool isPlayable() const;
    void activate(bool isForceStart, bool isUsePlayParams, bool isCalc3DParam);
    void startBgm(bool isUsePlayParams, bool isCalc3DParam);
    void activate(const PlayParams& playParams, bool isCalc3DParam);
    void deactivate(bool isStopImmediately, s32 fadeFrame);
    void exeWaitOnSwitch();
    void exeWaitPlayStart();
    void exePlay();

private:
    u8 filler[0x1E8 - sizeof(LiveActor)];
};

static_assert(sizeof(BgmPlayObj) == 0x1E8);
}  // namespace al
