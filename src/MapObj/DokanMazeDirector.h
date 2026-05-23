#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class DokanMazeDirector : public al::LiveActor {
public:
    DokanMazeDirector(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void initLevel(const al::ActorInitInfo& info, DokanMaze* dokanMaze);
    s64 getStartDokan();
    void exeWait();
    void setRandom();
    void setMiss();
    void exeInLevel();

private:
    u8 filler[0x140 - sizeof(al::LiveActor)];
};

static_assert(sizeof(DokanMazeDirector) == 0x140);
