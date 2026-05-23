#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class RabbitGraphVertex {
public:
    s32 calcValidEdgeNum() const;
};

class RabbitGraphEdge : public al::Graph::PosEdge {
public:
    bool isValid() const;
    f32 getWeight() const override;

private:
    u8 filler[0x288 - sizeof(al::Graph::PosEdge)];
};

class RabbitGraphEdgeMoon : public RabbitGraphEdge {
public:
    f32 getWeight() const override;

private:
    u8 filler[0x288 - sizeof(RabbitGraphEdge)];
};

class RabbitGraph : public al::LiveActor {
public:
    RabbitGraph(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool tryCreateRabbitGraphLinks(al::LiveActor** outActor, al::LiveActor* actor,
                                   const al::ActorInitInfo& info, const char* linkName,
                                   s32 linkIndex, bool isStartOn);
    void initAfterPlacement() override;
    void exeStandby();
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void control() override;

private:
    u8 filler[0x288 - sizeof(al::LiveActor)];
};

static_assert(sizeof(RabbitGraph) == 0x288);
