#pragma once

#include <basis/seadTypes.h>

//A strange one byte class that the StageScene uses. Its constructor is empty and it has a a few getters that return a fixed value
class ProjectSeNamedList{
public:
    ProjectSeNamedList();
    char** getMuteSeInPVList();
    s32 getMuteSeInPVListSize();
};

static_assert(sizeof(ProjectSeNamedList) == 0x1, "ProjectSeNamedList size");
