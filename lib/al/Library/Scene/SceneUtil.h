#pragma once

#include <basis/seadTypes.h>

namespace al {

class ISceneObj;
class Scene;
class IUseSceneObjHolder;
class PlayerHolder;

ISceneObj* getSceneObj(const IUseSceneObjHolder*, s32);
void createSceneObj(IUseSceneObjHolder*, s32);
void setSceneObj(IUseSceneObjHolder*, ISceneObj*, s32);
void tryDeleteSceneObj(const IUseSceneObjHolder*, s32);
PlayerHolder* getScenePlayerHolder(const Scene*);
void stopPadRumble(const Scene*);

}  // namespace al
