#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class MultiGateKeeperWatcher : public al::LiveActor {
public:
    MultiGateKeeperWatcher(const char*);
    void init(const al::ActorInitInfo&) override;
    bool isExistAliveGK() const;
    bool isEnableShowPlayer() const;
    bool isEndDemo() const;
    void addDemoKoopaStatue();
    s64 noticeGKDead(const al::LiveActor*, al::LiveActor*);
    void exeWatch();
    void exeBonFire();
    void exeShineAppear();
    void exeEntranceCamera();
private:
    u8 filler[0x170 - sizeof(al::LiveActor)];
};
static_assert(sizeof(MultiGateKeeperWatcher) == 0x170);
