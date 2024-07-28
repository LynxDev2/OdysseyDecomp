#pragma once

namespace al { 

class AudioDirector;

class DemoSyncedEventKeeper
{
public:
    DemoSyncedEventKeeper(al::AudioDirector*);
    void updateOnlyWhenDemoRun(int);
    void finalize();
    void startDemo(const char*);
    void endDemo(bool, bool);
private:
    char filler[0x20];
};

} 
