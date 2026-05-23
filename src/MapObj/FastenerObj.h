#pragma once

#include <basis/seadTypes.h>
#include <math/seadQuat.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"
#include "Library/Rail/VertexGraph.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class FastenerObj : public al::LiveActor {
public:
    FastenerObj(const char* name);
    void createFastenerKnobModel(const al::ActorInitInfo& info);
    void createFastenerPartsModel(const al::ActorInitInfo& info);
    void createSensor(const al::ActorInitInfo& info);
    void init(const al::ActorInitInfo& info) override;
    void createGraph(const al::ActorInitInfo& info);
    void switchKill();
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    const sead::Vector3f& searchGraphFastenerVertexBySensorPos(const al::HitSensor* sensor);
    s64 searchFastenerKnobModelBySensor(const al::HitSensor* sensor);
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void endCapture(const sead::Vector3f* pos, const sead::Quatf* quat);
    void control() override;
    void exeHackEnd();
    void exeFullOpenEnd();
    void exeCleanupWait();
    void exeCleanup();
    void exeStandby();
    void exeCaptureWait();
    void exeCaptureStart();
    void exeCaptureHackStart();
    bool trySetPoseGraphMoveDir(f32 moveSpeed, const sead::Vector3f& moveDir,
                                const sead::Vector3f& upDir);
    void exeMove();
    bool checkMovableInputAndNextNerve();
    bool checkEnableMoveByGraph(const al::Graph::PosVertex** outPosVertex,
                                const sead::Vector2f& inputDir, const al::LiveActor* actor,
                                const al::Graph::PosVertex* posVertex);
    bool checkMovableInputNextByGraph(bool* isMoveInput, const al::Graph::PosVertex* posVertex,
                                      const sead::Vector2f& inputDir);
    void exeMoveEnd();

private:
    u8 filler[0x4AE8 - sizeof(al::LiveActor)];
};

static_assert(sizeof(FastenerObj) == 0x4AE8);
