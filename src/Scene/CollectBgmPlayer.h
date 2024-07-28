#pragma once

#include "Library/HostIO/HioNode.h"
#include "Library/Scene/ISceneObj.h"

class CollectBgmPlayer : public al::HioNode, public al::ISceneObj{
public:
    const char * getSceneObjName() const override;
    void initAfterPlacementSceneObj(const al::ActorInitInfo &) override;
    void initSceneObj() override;
};
