#pragma once

#include <basis/seadTypes.h>

namespace al {
    class AudioDirector;
}

class SceneAudioSystemPauseController{

public:
    SceneAudioSystemPauseController(al::AudioDirector*);

private:
    al::AudioDirector *mAudioDir;
    s32 mUnkNumber;
    bool mUnkBool;
    bool mIsPaused;
    char filler[2];
};
