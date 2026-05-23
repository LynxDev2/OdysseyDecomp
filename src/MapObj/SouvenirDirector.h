#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class SouvenirDirector : public al::LiveActor {
public:
    SouvenirDirector(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void createLinks(al::LiveActor** outActor, al::LiveActor* actor, const al::ActorInitInfo& info,
                     s32 links, const char* linksName);
    void exeWait();

private:
    u8 filler[0x518 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SouvenirDirector) == 0x518);
