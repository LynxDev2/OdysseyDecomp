#include "Project/Item/ActorScoreKeeper.h"

#include "Library/Base/StringUtil.h"
#include "Library/Yaml/ByamlIter.h"

namespace al {
ActorScoreInfo::ActorScoreInfo() = default;

void ActorScoreInfo::init(const ByamlIter& iter) {
    iter.tryGetStringByKey(&factorName, "FactorName");
    iter.tryGetStringByKey(&categoryName, "CategoryName");
}

ActorScoreKeeper::ActorScoreKeeper() = default;

void ActorScoreKeeper::init(const ByamlIter& iter) {
    if (iter.isTypeArray()) {
        mSize = iter.getSize();
        allocArray();
        for (s32 i = 0; i < mSize; i++) {
            ByamlIter subIter;
            iter.tryGetIterByIndex(&subIter, i);
            putEntry(i, subIter);
        }
    } else {
        mSize = 1;
        allocArray();
        putEntry(0, iter);
    }
}

inline void ActorScoreKeeper::allocArray() {
    Entry* localArray = new Entry[mSize];
    if (mSize)
        memset(localArray, 0, sizeof(Entry) * mSize);
    mArray = localArray;
}

inline void ActorScoreKeeper::putEntry(s32 index, const ByamlIter& iter) {
    const char** categoryName = &mArray[index].categoryName;
    iter.tryGetStringByKey(categoryName - 1, "FactorName");
    iter.tryGetStringByKey(categoryName, "CategoryName");
}

const char* ActorScoreKeeper::getCategoryName() const {
    return mArray[0].categoryName;
}

const char* ActorScoreKeeper::tryGetCategoryName(const char* factorName) const {
    for (s32 i = 0; i < mSize; i++) {
        if (mArray[i].factorName && isEqualString(mArray[i].factorName, factorName))
            return mArray[i].categoryName;
    }

    return nullptr;
}
}  // namespace al
