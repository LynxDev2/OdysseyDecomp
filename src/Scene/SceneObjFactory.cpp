#include "Scene/SceneObjFactory.h"

#include "Library/Scene/ISceneObj.h"
#include "Library/Scene/SceneObjHolder.h"

[[maybe_unused]] static al::ISceneObj* sceneObjCreator(s32 id) {
    // TODO
    return nullptr;
}

/*
 * Don't override with empty
al::SceneObjHolder* SceneObjFactory::createSceneObjHolder() {
    return new al::SceneObjHolder(&sceneObjCreator, SceneObjID_Max);
}
*/
