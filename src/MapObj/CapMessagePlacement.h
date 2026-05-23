#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class CapMessagePlacement : public al::LiveActor {
public:
    CapMessagePlacement(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void onKill();
    void onAppear();
    void initAfterPlacement() override;
    void showStart();
    bool trySave();
    bool showEnd();
    bool isActive() const;
    bool checkEnbale() const;

private:
    u8 filler[0x378 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CapMessagePlacement) == 0x378);
