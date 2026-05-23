#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class GameDataHolder;

class DemoWorldMoveHomeBackGround : public al::LiveActor {
public:
    DemoWorldMoveHomeBackGround(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void changeGraphics(s32 graphicsPreset);
    void exeWait();

private:
    u8 filler[0x108 - sizeof(al::LiveActor)];
};

static_assert(sizeof(DemoWorldMoveHomeBackGround) == 0x108);

class DemoChangeWorldGraphicsDataHolder {
public:
    DemoChangeWorldGraphicsDataHolder(const GameDataHolder* gameDataHolder);
    s32 getGraphicsType(s32 worldType, s32 stageType) const;
    s64 getGraphicsPreset(s32* outGraphicsPreset, s32 worldType, s32 stageType) const;
};
