#pragma once

#include "Library/HostIO/HioNode.h"

namespace al {

class ActorInitInfo;
class EffectSystem;

class DemoDirector : public al::HioNode{
public:
    virtual void endInit(const ActorInitInfo&);
    virtual void updateDemoActor(EffectSystem*);
    virtual void startDemo(const char*);
    virtual void endDemo(const char*);
private:
    void* filler[9];
};
}
