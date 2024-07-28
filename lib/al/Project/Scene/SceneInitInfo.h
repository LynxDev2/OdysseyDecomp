#pragma once

#include <prim/seadSafeString.h>    

#include "System/GameDataHolderAccessor.h"

namespace al {

struct GameSystemInfo;
class ScreenCaptureExecutor;
class AudioDirector;
class GameDataHolderBase;

struct SceneInitInfo {
  const al::GameSystemInfo* gameSysInfo;
  al::GameDataHolderBase* gameDataHolder;
  al::ScreenCaptureExecutor* screenCaptureExecutor;
  const char *initStageName;
  u32 scenarioNo;
  int pad;
  sead::FixedSafeString<512> unkSafeStr;
  al::AudioDirector *audioDir;
};
}  // namespace al
