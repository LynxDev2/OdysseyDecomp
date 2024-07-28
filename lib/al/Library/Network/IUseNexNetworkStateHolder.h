#pragma once

namespace al {

class NexNetworkStateHolder;

class IUseNexNetworkStateHolder{
public:
    virtual NexNetworkStateHolder* getNexNetworkStateHolder() = 0;
};
}
