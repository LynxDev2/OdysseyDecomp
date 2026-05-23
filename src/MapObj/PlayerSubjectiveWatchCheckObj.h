#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class PlayerSubjectiveWatchCheckObj : public al::LiveActor {
public:
    PlayerSubjectiveWatchCheckObj(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void control() override;
    void appear() override;
    void kill() override;
    void endClipped() override;
    void exeNotSubjective();
    void exeIn();
    void exeOut();

private:
    u8 filler[0x108 - sizeof(al::LiveActor)];
};

static_assert(sizeof(PlayerSubjectiveWatchCheckObj) == 0x108);
