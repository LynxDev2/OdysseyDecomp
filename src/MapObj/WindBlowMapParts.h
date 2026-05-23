#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class WindBlowPuzzle;

class WindBlowMapParts : public al::LiveActor {
public:
    WindBlowMapParts(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;
    void activatePuzzleMode(WindBlowPuzzle* windBlowPuzzle);
    bool isFixed() const;
    f32 exeFreeMove();
    void exeRailStop();
    void calcRailForce(sead::Vector3f* outRailForce, sead::Vector3f* outLiftForce);
    void exeRailMove();
    void exeGridWait();
    void exeGridMove();
    void exeGridFix();

private:
    u8 filler[0x130 - sizeof(al::LiveActor)];
};

static_assert(sizeof(WindBlowMapParts) == 0x130);
