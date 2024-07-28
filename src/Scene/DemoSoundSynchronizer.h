#pragma once

namespace al {
    class ApplicationMessageReceiver;
    class AudioDirector;
}

class DemoSoundSynchronizer{
public:
    DemoSoundSynchronizer(const al::ApplicationMessageReceiver*, al::AudioDirector*);
private:
    const al::ApplicationMessageReceiver *mApplicationMessageReceiver;
    al::AudioDirector *mAudioDirector;
    void* filler[2];
};
