#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class FukuwaraiWatcher : public al::LiveActor {
public:
    FukuwaraiWatcher(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    s32 getPartsNum() const;
    s64 getParts(s32 parts) const;
    void exeWait();
    void exeSetStartPosition();
    void exeMemorize();
    void exePlay();
    void exeWaitStartResultEnd();
    s64 calcTotalScore() const;
    void exeResultWait();
    void exeResultAppearParts();
    void exeEnd();

private:
    u8 filler[0x238 - sizeof(al::LiveActor)];
};

static_assert(sizeof(FukuwaraiWatcher) == 0x238);
