#pragma once

#include "Library/Scene/ISceneObj.h"
namespace al{
    class DataStoreDirector : public ISceneObj{
        virtual const char * getSceneObjName() const override;
        virtual ~DataStoreDirector();
    };
}
