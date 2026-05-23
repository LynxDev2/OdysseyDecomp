#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class DoorAreaChange : public al::LiveActor {
public:
    DoorAreaChange(const char* name);
    void init(const al::ActorInitInfo& info) override;
    void switchCloseAgain();
    void start();
    void appear() override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    bool isOpen() const;
    void setNoStart();
    void enableStart();
    void setHomeDoor(bool homeDoor);
    void exeNoStart();
    void exeNoStartWithMessage();
    void exeCloseWait();
    void exeOpen();
    void exeOpenWait();
    void exeCloseBefore();
    void exeClose();

private:
    u8 filler[0x118 - sizeof(al::LiveActor)];
};

static_assert(sizeof(DoorAreaChange) == 0x118);
