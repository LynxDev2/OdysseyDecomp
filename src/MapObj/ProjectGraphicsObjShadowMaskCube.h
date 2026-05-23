#pragma once

#include <basis/seadTypes.h>
#include <math/seadMatrix.h>
#include <math/seadVector.h>

#include "Library/LiveActor/LiveActor.h"
#include "Library/Shadow/ShadowMaskBase.h"

namespace al {
struct ActorInitInfo;
}  // namespace al

class ProjectGraphicsObjShadowMaskCube : public al::ShadowMaskBase, public al::LiveActor {
public:
    ProjectGraphicsObjShadowMaskCube(const char* name);
    ~ProjectGraphicsObjShadowMaskCube();
    void init(const al::ActorInitInfo& info) override;
    bool tryInitTexture(const char* name);
    void listenStartSnapShotMode();
    void listenEndSnapShotMode();
    void initAfterPlacement() override;
    const sead::Matrix34f& calcProjTexMatrix(sead::Matrix34f* outProjMatrix,
                                             sead::Matrix34f* shadowMatrix);
    void declare(al::ShadowMaskDrawCategory shadowMaskDrawCategory);
    void update();
    void calcShadowMatrix(sead::Matrix34f* shadowMatrix) override;
    void updateMulti() override;
    void addMulti() override;
    al::ShadowMaskType getShadowMaskType() const override;
    void control() override;

private:
    u8 filler[0x450 - sizeof(al::ShadowMaskBase) - sizeof(al::LiveActor)];
};

static_assert(sizeof(ProjectGraphicsObjShadowMaskCube) == 0x450);
