#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class CandlestandWatcher : public al::LiveActor {
public:
    CandlestandWatcher(const char* name, bool candlestandWatcher = false);
    void init(const al::ActorInitInfo& info) override;
    s64 copyCandlestandList(const sead::PtrArray<Candlestand>& ptrArray);
    void control() override;
    bool tryUpdateHintTrans();

private:
    u8 filler[0x148 - sizeof(al::LiveActor)];
};

static_assert(sizeof(CandlestandWatcher) == 0x148);
