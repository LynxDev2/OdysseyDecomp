#pragma once

#include "Library/Camera/CameraPoserFactory.h"

class ProjectCameraPoserFactory : public al::CameraPoserFactory {
public:
    ProjectCameraPoserFactory();
    const char* convertName(const char* name) const override;
};