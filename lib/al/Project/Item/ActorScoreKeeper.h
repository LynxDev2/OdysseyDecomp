#pragma once

#include <basis/seadTypes.h>

namespace al {
class ByamlIter;

struct ActorScoreInfo {
    ActorScoreInfo();

    void init(const ByamlIter& iter);

    const char* factorName = nullptr;
    const char* categoryName = nullptr;
};

class ActorScoreKeeper {
public:
    struct Entry {
        const char* factorName;
        const char* categoryName;
    };

    ActorScoreKeeper();

    void init(const ByamlIter& iter);
    const char* getCategoryName() const;
    const char* tryGetCategoryName(const char* factorName) const;

private:
    inline void allocArray();
    inline void putEntry(s32 index, const ByamlIter& iter);

    Entry* mArray = nullptr;
    s32 mSize = 0;
};
}  // namespace al
