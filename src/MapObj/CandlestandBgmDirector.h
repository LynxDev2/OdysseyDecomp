#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class CandlestandBgmDirector : public al::LiveActor {
public:
    CandlestandBgmDirector(const char* name, bool candlestandBgmDirector = false);
    void init(const al::ActorInitInfo& info) override;
    void listenStart();
    void listenStop();
    s64 copyCandlestandList(const sead::PtrArray<Candlestand>& ptrArray);
    void movement() override;
    void exeSleep();
    void exeWaitActive();
    void exeActive();

private:
    u8 filler[0x148 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CandlestandBgmDirector) == 0x148);
