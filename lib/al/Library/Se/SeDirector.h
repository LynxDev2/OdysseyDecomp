#pragma once

#include <basis/seadTypes.h>

namespace al{
class SeDirector{
public:
    void setMuteSeInPVList(char** value){ mMuteSeInPVList = value; }
    void setMuteSeInPVListSize(s32 value){ mMuteSeInPVListSize = value; }

private:
  void *gap[21];
  char **mMuteSeInPVList;
  s32 mMuteSeInPVListSize;
  void *filler;
};
}
