#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class WindBlowPuzzle : public al::LiveActor {
public:
    WindBlowPuzzle(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void updateCollisionAll();
    void updatePartsAllCollision(s32 partIndex, bool isCollisionOn);
    void control() override;
    void exeWait();
    void exeComplete();
    bool checkEnableMove(const WindBlowMapParts* windBlowMapParts, s32 moveX, s32 moveY) const;
    void moveParts(WindBlowMapParts* windBlowMapParts, s32 moveX, s32 moveY);
    bool checkOnAnswer(s32 answerIndex) const;
    bool checkCollision(const sead::Vector3i& vector3I) const;

private:
    u8 filler[0x270 - sizeof(al::LiveActor)];
};

static_assert(sizeof(WindBlowPuzzle) == 0x270);
