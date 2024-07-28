#pragma once

#include "Library/Nerve/NerveExecutor.h"

class Shine;

class EventFlowSceneExecuteCtrl : public al::NerveExecutor{
public:
    EventFlowSceneExecuteCtrl();
private:
    Shine* mShine;
    const char* mAchivementName;
};
