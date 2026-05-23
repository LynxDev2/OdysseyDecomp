#pragma once

#include <basis/seadTypes.h>
#include <container/seadObjArray.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"
#include "Library/Rail/VertexGraph.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
class LiveActorGroup;
}  // namespace al

class FastenerVertex;

class FastenerEdge : public al::Graph::PosEdge {
public:
    f32 getWeight() const override;

private:
    u8 filler[0x5150 - sizeof(al::Graph::PosEdge)];
};

class FastenerVertex {
public:
    s32 calcValidEdgeNum() const;
    s32 calcValidEdgeNumFastener() const;
};

class Fastener : public al::LiveActor {
public:
    Fastener(const char* name);
    void init(const al::ActorInitInfo& info) override;
    bool tryCreateFastenerLinks(al::LiveActor** outLinkActor, al::LiveActor* parentActor,
                                const al::ActorInitInfo& info, const char* linkName, s32 linkIndex);
    void createGraph(const al::ActorInitInfo& info);
    void switchStartOn();
    void tryUpdateDisplayModel();
    void createEdgeModel(const al::ActorInitInfo& info);
    void setKnobOrder(sead::FixedObjArray<s32, 64>* knobOrder);
    void createMesh(const al::ActorInitInfo& info);
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    const sead::Vector3f&
    searchAliveKeeperGraphFastenerVertexBySensorPos(const al::HitSensor* sensor);
    s64 searchFastenerKnobModelBySensor(const al::HitSensor* sensor);
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void endCapture(const sead::Vector3f* startPos, const sead::Vector3f* endPos);
    void kill() override;
    void appear() override;
    void control() override;
    void tryReset();
    void exeHackEnd();
    void exeStandby();
    void exeCaptureWait();
    void exeCaptureStart();
    void exeCaptureHackStart();
    void trySetPoseGraphMoveDir(f32 moveSpeed, const sead::Vector3f& moveDir);
    void exeMove();
    bool checkMovableInputAndNextNerve();
    bool checkEnableMoveByGraph(const al::Graph::PosVertex** outNextVertex,
                                const sead::Vector2f& inputDir, const al::LiveActor* actor,
                                const al::Graph::PosVertex* currentVertex);
    bool checkMovableInputNextByGraph(bool* isMoveInput, const al::Graph::PosVertex* currentVertex,
                                      const sead::Vector2f& inputDir);
    void exeMoveEnd();
    void onMoveEndEnd();

private:
    u8 filler[0x5150 - sizeof(al::LiveActor)];
};

static_assert(sizeof(Fastener) == 0x5150);

class FastenerFunction {
public:
    bool tryMakeQuatResetKnob(sead::Quatf* outQuat, const FastenerVertex* vertex);
    void resetKnobPose(al::LiveActor* actor, const FastenerVertex* vertex);
};
