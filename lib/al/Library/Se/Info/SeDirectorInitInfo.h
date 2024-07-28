#pragma once

#include <math/seadVector.h>
#include <math/seadMatrix.h>

namespace al {

class Projection;
class OcclusionCullingJudge;

struct SeDirectorInitInfo{
  s32 maxRequests;
  s32 playerCount;
  s32 listenerCount;
  const char *defaultListenerName;
  const char *defaultStageEffectName;
  bool useMeInfo;
  bool useLoopSequencer;
  u32 *field_28;
  s32 field_30;
  sead::Vector3f *cameraPos;
  sead::Matrix34f *cameraMatrix;
  al::Projection *cameraProjection;
  sead::Vector3f *cameraAt;
  OcclusionCullingJudge* occlusionCullingJudge;
  f32 interiorSize;
  f32 pitchModifier;
};
}
