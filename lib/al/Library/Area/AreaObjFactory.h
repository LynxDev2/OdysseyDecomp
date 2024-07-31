#pragma once

#include "Library/Factory/Factory.h"

namespace al {
class AreaObj;

using AreaObjCreatorFunction = AreaObj* (*)(const char* areaObjName);

class AreaObjFactory : public Factory<AreaObjCreatorFunction> {
public:
    AreaObjFactory(const char* factoryName);
protected:
    void* filler[2];
};
}  // namespace al
