#pragma once

#include "Library/Audio/IUseAudioKeeper.h"
#include "Library/Scene/ISceneObj.h"

class BgmAnimeSyncDirector : public al::ISceneObj, public al::IUseAudioKeeper{
public:
BgmAnimeSyncDirector();
    const char * getSceneObjName() const override;
    void initAfterPlacementSceneObj(const al::ActorInitInfo &) override;
    void initSceneObj() override;
    al::AudioKeeper* getAudioKeeper() const override;
private:
    char filler[0x20];
};
