#pragma once

#include "Library/HostIO/HioNode.h"
#include "Library/Network/IUseNexNetworkStateHolder.h"

namespace al {

class DataStoreDirector;
class RankingDirector;
class NexUtilityDirector;

class NetworkSystem : al::IUseNexNetworkStateHolder, al::HioNode{
public:
    NexNetworkStateHolder* getNexNetworkStateHolder() override;

    DataStoreDirector* getDataStoreDirector() const { return mDataStoreDirector; }
    RankingDirector* getRankingDirector() const { return mRankingDirector; }

private:
    void *gap1[2];
    al::NexNetworkStateHolder *mNexNetworkStateHolder;
    void *gap2[2];
    al::DataStoreDirector *mDataStoreDirector;
    al::RankingDirector *mRankingDirector;
    al::NexUtilityDirector *mNexUtilityDirector;
};
}
