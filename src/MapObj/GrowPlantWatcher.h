#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class GrowPlantWatcher : public al::LiveActor {
public:
    GrowPlantWatcher(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool isPlantEndAll() const;
    void kill() override;
    void exeWatch();

private:
    u8 filler[0x120 - sizeof(al::LiveActor)];
};

static_assert(sizeof(GrowPlantWatcher) == 0x120);
