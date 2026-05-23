#pragma once

#include <basis/seadTypes.h>

#include "Library/LiveActor/LiveActor.h"

namespace al {
struct ActorInitInfo;
class SensorMsg;
class HitSensor;
}  // namespace al

class TextureReplaceScreen : public al::LiveActor {
public:
    TextureReplaceScreen(const char* name);
    ~TextureReplaceScreen();
    void init(const al::ActorInitInfo& info) override;
    void initAfterPlacement() override;
    void switchOn();
    void switchOff();
    void control() override;
    void onClipped();
    void draw() const override;
    void attackSensor(al::HitSensor* self, al::HitSensor* other) override;
    bool receiveMsg(const al::SensorMsg* message, al::HitSensor* other,
                    al::HitSensor* self) override;
    void exeWait();

private:
    u8 filler[0x170 - sizeof(al::LiveActor)];
};

static_assert(sizeof(TextureReplaceScreen) == 0x170);
