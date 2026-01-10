#include "Sequence/HakoniwaSequence.h"

#include <common/aglDrawContext.h>
#include <common/aglRenderBuffer.h>
#include <gfx/seadViewport.h>

#include "Library/Layout/LayoutUtil.h"
#include "Library/Nerve/NerveSetupUtil.h"
#include "Library/Nerve/NerveUtil.h"
#include "Library/Play/Layout/WipeHolder.h"
#include "Library/Screen/ScreenFunction.h"
#include "Library/Sequence/Sequence.h"
#include "Library/System/GameSystemInfo.h"
#include "Library/Thread/AsyncFunctorThread.h"

#include "Sequence/WorldResourceLoader.h"
#include "System/GameDataFunction.h"
#include "System/WorldList.h"

NERVE_IMPL(HakoniwaSequence, LoadStage);

NERVES_MAKE_NOSTRUCT(HakoniwaSequence, LoadStage);

void HakoniwaSequence::drawMain() const {
    al::Sequence::drawMain();
    al::DrawSystemInfo* info = getDrawInfo();
    agl::DrawContext* context = info->drawContext;
    const agl::RenderBuffer* buffer = info->dockedRenderBuffer;
    if (!info->isDocked)
        buffer = info->handheldRenderBuffer;

    mScreenCaptureExecutor->tryCaptureAndDraw(context, buffer, 0);
    sead::Viewport viewport{*buffer};
    viewport.apply(context, *buffer);
    buffer->bind(context);
    al::setRenderBuffer(mLayoutKit, buffer);
    al::executeDraw(mLayoutKit, "２Ｄバック（メイン画面）");
    al::executeDraw(mLayoutKit, "２Ｄベース（メイン画面）");
    al::executeDraw(mLayoutKit, "２Ｄオーバー（メイン画面）");
}

// CUSTOM SpeedBoot with code addpated from:  https://github.com/Amethyst-szs/shadow-clone-chasers
bool hasStartedLoadingResource = false;

void HakoniwaSequence::exeBootLoadData() {
    if (al::isFirstStep(this))
        mInitThread->start();
    if (!mInitThread->isDone())
        return;
    if (!hasStartedLoadingResource) {
        const char* name = GameDataFunction::getNextStageName(mGameDataHolderAccessor);
        if (!name)
            name = GameDataFunction::getMainStageName(mGameDataHolderAccessor, 0);
        int scenario = GameDataFunction::calcNextScenarioNo(mGameDataHolderAccessor);
        if (scenario == -1)
            scenario = 1;
        int world = mGameDataHolderAccessor->getWorldList()->tryFindWorldIndexByStageName(name);
        if (world > -1)
            mResourceLoader->requestLoadWorldHomeStageResource(world, scenario);
        hasStartedLoadingResource = true;
        // This wipe is automatically opened by exePlayStage
        mWipeHolder->startClose("FadeWhite", -1);
    }
    if (mResourceLoader->isEndLoadWorldResource() && mWipeHolder->isCloseEnd())
        al::setNerve(this, &LoadStage);
}
