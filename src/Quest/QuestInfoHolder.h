#pragma once

#include "Library/Scene/ISceneObj.h"

namespace al {
    class IUseSceneObjHolder;
    class SceneObjHolder;
}

class QuestInfoHolder : public al::ISceneObj{
public:
    void finalizeForScene();
    void initSceneObjHolder(al::SceneObjHolder*);
};

namespace rs {
    QuestInfoHolder* getQuestInfoHolder(const al::IUseSceneObjHolder*);
}
