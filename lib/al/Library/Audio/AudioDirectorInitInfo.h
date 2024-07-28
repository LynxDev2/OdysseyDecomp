#pragma once

#include <basis/seadTypes.h>
#include <cstring>

#include "Library/Se/Info/SeDirectorInitInfo.h"
#include "Library/Bgm/BgmDirectorInitInfo.h"

namespace al {

class AudioSystemInfo;
class AreaObjDirector;
class DemoDirector;

struct AudioDirectorInitInfo{
  AudioSystemInfo *audioSystemInfo;
  AreaObjDirector *areaObjDirector;
  const char *currentStage;
  s32 scenarioNo;
  DemoDirector *demoDirector;
  SeDirectorInitInfo seDirectorInitInfo;
  BgmDirectorInitInfo bgmDirectorInitInfo;
  const char *duckingName;
};

AudioDirectorInitInfo createAudioDirectorInitInfoForStageScene(){
  AudioDirectorInitInfo audioDirInitInfo;
  audioDirInitInfo.seDirectorInitInfo.maxRequests = -1;
  audioDirInitInfo.seDirectorInitInfo.playerCount = -1;
  audioDirInitInfo.seDirectorInitInfo.field_30 = 1;
  audioDirInitInfo.seDirectorInitInfo.interiorSize = -1.0f;
  audioDirInitInfo.seDirectorInitInfo.listenerCount = 1;
  audioDirInitInfo.seDirectorInitInfo.pitchModifier = 1.0f;
  audioDirInitInfo.demoDirector = nullptr;
  memset(&audioDirInitInfo, 0, 28);
  audioDirInitInfo.seDirectorInitInfo.useMeInfo = true;
  audioDirInitInfo.seDirectorInitInfo.useLoopSequencer = false;
  audioDirInitInfo.seDirectorInitInfo.field_28 = nullptr;
  memset(&audioDirInitInfo.seDirectorInitInfo.cameraPos, 0, 40);
  audioDirInitInfo.bgmDirectorInitInfo.isScene = false;
  audioDirInitInfo.bgmDirectorInitInfo.stageName = nullptr;
  audioDirInitInfo.duckingName = nullptr;
  audioDirInitInfo.seDirectorInitInfo.defaultListenerName = "カスタム線リスナ";
  audioDirInitInfo.seDirectorInitInfo.defaultStageEffectName = nullptr;
  return audioDirInitInfo;
}

}
