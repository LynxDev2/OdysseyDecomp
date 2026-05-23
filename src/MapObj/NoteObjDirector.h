#pragma once

#include <basis/seadTypes.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class NoteObjDirector : public al::LiveActor {
public:
    NoteObjDirector(const char* name, NoteObjDirector* hostDirector = nullptr,
                    f32 noteSpeed = 0.0f);
    void init(const al::ActorInitInfo& info) override;
    void appearNote();
    s64 getNote(bool note);
    void getNoteFirst(bool noteFirst);
    const sead::Vector3f& reAppear();
    void exeInit();
    void exeAppearDemo();
    bool tryAddAppearDemo();
    void exeWait();
    void exeWaitGetAll();
    const sead::Vector3f& tryNotifyAllGet();

private:
    u8 filler[0x170 - sizeof(al::LiveActor)];
};

static_assert(sizeof(NoteObjDirector) == 0x170);
