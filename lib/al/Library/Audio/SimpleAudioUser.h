#pragma once

#include <basis/seadTypes.h>

#include "Library/Audio/IUseAudioKeeper.h"
#include "Library/HostIO/HioNode.h"

namespace al{

class AudioDirector;
class ActorInitInfo;
class LayoutInitInfo;

class SimpleAudioUser : public HioNode, public IUseAudioKeeper{
public:
    SimpleAudioUser(const char*, AudioDirector*);
    SimpleAudioUser(const char*, const ActorInitInfo&);
    SimpleAudioUser(const char*, const LayoutInitInfo&);
    AudioKeeper* getAudioKeeper() const override;
private:
    AudioKeeper *mAudioKeeper;
    s32 filler;
};
}

static_assert(sizeof(al::SimpleAudioUser) == 0x18, "al::SimpleAudioUser size");
