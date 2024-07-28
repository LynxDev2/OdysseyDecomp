#pragma once

#include "Library/HostIO/HioNode.h"
#include "Library/Scene/ISceneObj.h"
#include "Library/Network/IUseNexNetworkStateHolder.h"

namespace al {

class RankingDirector : public ISceneObj, public IUseNexNetworkStateHolder, public HioNode{
public:
    const char* getSceneObjName() const override;
    virtual ~RankingDirector();
    NexNetworkStateHolder* getNexNetworkStateHolder() override;
};
}
