#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class SignBoardLayoutTexture : public al::LiveActor {
public:
    SignBoardLayoutTexture(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void appear() override;
    void kill() override;

private:
    u8 filler[0x110 - sizeof(al::LiveActor)];
};

static_assert(sizeof(SignBoardLayoutTexture) == 0x110);
