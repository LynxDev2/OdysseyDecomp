#pragma once

#include <container/seadPtrArray.h>

#include "Library/Scene/ItemDirectorBase.h"

class GameDataHolder;

class ProjectItemDirector : public al::ItemDirectorBase{
public:
    ProjectItemDirector();
    void appearItem(const char *, const sead::Vector3f &, const sead::Quatf &, const al::HitSensor *) override;
    void acquireItem(const al::LiveActor *, al::HitSensor *, const char *) override;
    void declareItem(const char *, const al::ActorInitInfo &) override;
    void endInit() override;
    void initPlayerDeadCoin(GameDataHolder*, const al::ActorInitInfo&);
private:
    void *gap[10];
    sead::PtrArrayImpl *mPtrArray;
    void *filler;
};
