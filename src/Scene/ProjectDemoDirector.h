#pragma once

#include <basis/seadRawPrint.h>
#include <container/seadPtrArray.h>
#include <iterator>

#include "Library/Demo/DemoDirector.h"

namespace al {
    class PlayerHolder;
    class GraphicsSystemInfo;
    class WipeSimple;
}

class ShineTowerRocket;
class RiseMapPartsHolder;
class Shine;
class DemoHackFirstDirector;

class ProjectDemoDirector : public al::DemoDirector{
public:
    ProjectDemoDirector(const al::PlayerHolder*, al::GraphicsSystemInfo*);
    
    void endInit(const al::ActorInitInfo &) override;
    void updateDemoActor(al::EffectSystem*) override;
    void startDemo(const char *) override;
    void endDemo(const char *) override;

private:
    const al::PlayerHolder *mPlayerHolder;
    al::GraphicsSystemInfo *mGraphicsSystemInfo;
    ShineTowerRocket *mShineTowerRocket;
    RiseMapPartsHolder *mRiseMapPartsHolder;
    s32 *mList;
    Shine *mShine;
    void *gap1[4];
    al::WipeSimple *mSimpleWipeFadeBlack;
    DemoHackFirstDirector *mDemoHackFirstDirector;
    void *gap2[2];
    sead::PtrArrayImpl mUnkPtrArray;
    void *filler[3];
};
