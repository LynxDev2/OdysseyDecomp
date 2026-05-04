#pragma once

#include <basis/seadTypes.h>

#include "Library/Anim/DitherAnimator.h"

namespace al {
class LiveActor;
class Resource;

// TODO: Finish this
class ActorDitherAnimator : public DitherAnimator {
public:
    static ActorDitherAnimator* tryCreate(LiveActor*, const Resource*, const char*);

    ActorDitherAnimator(LiveActor* host);

    void reset();
    f32 getDitherAlpha() const;
    void setClippingJudgeDistanceParam(const char*);
    void resetClippingJudgeDistanceParam();
    void validateDitherAnim();
    void invalidateDitherAnim();

private:
    unsigned char padding[0x68 - sizeof(DitherAnimator)];
};

static_assert(sizeof(ActorDitherAnimator) == 0x68);
}  // namespace al
