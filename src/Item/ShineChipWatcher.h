#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class ShineChipWatcher : public al::LiveActor {
public:
    ShineChipWatcher(const char* name);
    s32 getCompleteNum();
    void init(const al::ActorInitInfo& info) override;
    void createShineChips(const al::ActorInitInfo& info, const char* shineChipName,
                          const char* shineChipArchiveName);
    void initAfterPlacement() override;
    void updateHints();
    bool isInArea() const;
    void appear() override;
    void kill() override;
    s32 getCount() const;
    bool isWatch(const al::LiveActor* actor) const;
    void updateCount();
    bool tryStartAppearShine();
    bool isAppearedShine() const;
    void addDemoActorWithChips();
    void exeWait();
    void exeStartAppearShine();
    void exeWaitAppearShine();
    void exeComplete();
    void exeDone();

private:
    u8 filler[0x150 - sizeof(al::LiveActor)];
};

static_assert(sizeof(ShineChipWatcher) == 0x150);
