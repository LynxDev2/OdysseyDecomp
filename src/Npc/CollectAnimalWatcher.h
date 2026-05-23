#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class CollectAnimalWatcher : public al::LiveActor {
public:
    CollectAnimalWatcher(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void updateHints();
    void appear() override;
    void exeWait();
    s32 countAnimalsInTheFence();
    void exeAllAnimalsInTheFence();
    void exeAppearShine();

private:
    u8 filler[0x138 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CollectAnimalWatcher) == 0x138);
