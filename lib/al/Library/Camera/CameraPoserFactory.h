#pragma once

#include "Library/Factory/Factory.h"

namespace al {
class CameraPoser;

using CameraPoserCreatorFunction = CameraPoser* (*)(const char* cameraPoserName);

class CameraPoserFactory : public Factory<CameraPoserCreatorFunction> {
public:
    CameraPoserFactory(const char* factoryName);
};
}  // namespace al
