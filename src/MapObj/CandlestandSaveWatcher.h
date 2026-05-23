#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class CandlestandSaveWatcher : public al::LiveActor {
public:
    CandlestandSaveWatcher(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void exeOffWait();
    void exeWaitOnDemo();
    void exePlayingOnDemo();
    void exeOnWait();

private:
    u8 filler[0x128 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CandlestandSaveWatcher) == 0x128);
