#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class TwistChainList : public al::LiveActor {
public:
    TwistChainList(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void init(const al::ActorInitInfo& info, const sead::Vector3f& upDir,
              const sead::Vector3f& startPos, const sead::Vector3f& endPos,
              const char* archiveName);
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isExistChain(s32 chainIndex);
    s64 fixChain(s32 chainIndex);
    void startBlow(const sead::Vector3f& pos);
    void forceKill();
    s32 getChainCount() const;
    void exeFix();
    void exeTwist();
    void exeBlow();

private:
    u8 filler[0x128 - sizeof(al::LiveActor)];
};

static_assert(sizeof(TwistChainList) == 0x128);
