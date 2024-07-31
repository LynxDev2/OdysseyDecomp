#pragma once


#include "Library/Area/AreaObjFactory.h"

class ProjectAreaFactory : public al::AreaObjFactory {
public:
    ProjectAreaFactory();
    const char* convertName(const char* name) const override;
};
