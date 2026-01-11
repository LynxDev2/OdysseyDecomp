#include "Scene/ProjectSceneFactory.h"

#include "Library/Scene/CreateSceneFunc.h"

#include "Scene/FirstSequenceScene.h"
#include "Scene/TitleMenuScene.h"

const al::NameToCreator<alSceneFunction::SceneCreatorFunction> sProjectSceneFactoryEntries[] = {
    {"DemoChangeWorldScene", alSceneFunction::createSceneFunc<class DemoChangeWorldScene>},
    {"DemoScene", alSceneFunction::createSceneFunc<class DemoScene>},
    {"DemoSceneWithCinemaCaption", alSceneFunction::createSceneFunc<class DemoSceneWithCinemaCaption>},
    {"EndingScene", alSceneFunction::createSceneFunc<class EndingScene>},
    {"FirstSequenceScene", alSceneFunction::createSceneFunc<FirstSequenceScene>},
    {"StageScene", alSceneFunction::createSceneFunc<class StageScene>},
    {"StaffRollScene", alSceneFunction::createSceneFunc<class StaffRollScene>},
    {"TitleMenuScene", alSceneFunction::createSceneFunc<TitleMenuScene>},
    {"WorldWarpHoleScene", alSceneFunction::createSceneFunc<class WorldWarpHoleScene>}};

ProjectSceneFactory::ProjectSceneFactory() : SceneFactory("シーン生成") {
    initFactory(sProjectSceneFactoryEntries);
}
