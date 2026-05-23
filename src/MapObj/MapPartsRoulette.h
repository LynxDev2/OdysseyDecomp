#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class MapPartsRoulette : public al::LiveActor {
public:
    MapPartsRoulette(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool tryCreateLinks(al::LiveActor** outActor, al::LiveActor* actor, bool* outIsLinked,
                        const al::ActorInitInfo& info, const char* linkName, s32 linkIndex);
    void stop();
    s64 roulette();
    void exeStop();
    void exeRoulette();

private:
    u8 filler[0x530 - sizeof(al::LiveActor)];
};

static_assert(sizeof(MapPartsRoulette) == 0x530);
