#include "Library/Area/AreaShapes.h"

namespace al {

AreaShapeCube::AreaShapeCube(AreaShapeCube::OriginType originType) : mOriginType(originType) {}

bool AreaShapeCube::isInVolume(const sead::Vector3f& trans) const {
    sead::Vector3f localPos = sead::Vector3f::zero;
    calcLocalPos(&localPos, trans);

    return isInLocalVolume(localPos);
}

bool AreaShapeCube::isInLocalVolume(const sead::Vector3f& trans) const {
    f32 bottom = mOriginType == OriginType::Base ?
                     0.0f :
                     (mOriginType == OriginType::Top ? -1000.0f : 500.0f);
    f32 top = mOriginType == OriginType::Base ? 1000.0f :
                                                (mOriginType == OriginType::Top ? 0.0f : 500.0f);

    sead::Vector3f min = {-500.0f, bottom, -500.0f};
    sead::Vector3f max = {500.0f, top, 500.0f};

    if ((trans.y < min.y || max.y < trans.y) || (trans.x < min.x || max.x < trans.x) ||
        (trans.z < min.z || max.z < trans.z))
        return false;

    return true;
}

AreaShapeSphere::AreaShapeSphere() {}

bool AreaShapeSphere::isInVolume(const sead::Vector3f& trans) const {
    sead::Vector3f baseTrans;
    calcTrans(&baseTrans);
    sead::Vector3f offsetTrans = trans - baseTrans;
    f32 radius = getScale().x * 500.0f;

    return offsetTrans.squaredLength() <= sead::Mathf::square(radius);
}

bool AreaShapeSphere::isInVolumeOffset(const sead::Vector3f& trans, f32 offset) const {
    sead::Vector3f baseTrans;
    calcTrans(&baseTrans);
    sead::Vector3f offsetTrans = trans - baseTrans;
    f32 radius = getScale().x * 500.0f + offset;

    return offsetTrans.squaredLength() <= sead::Mathf::square(radius);
}

bool AreaShapeSphere::calcNearestEdgePoint(sead::Vector3f* edgePoint,
                                           const sead::Vector3f& trans) const {
    sead::Vector3f localPos = sead::Vector3f::zero;
    calcLocalPos(&localPos, trans);
    f32 length = localPos.length();

    if (length > 0.0f)
        localPos *= 500.0f / length;

    calcWorldPos(edgePoint, localPos);

    return true;
}

bool AreaShapeSphere::checkArrowCollision(sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&,
                                          const sead::Vector3f&) const {
    return false;
}

bool AreaShapeSphere::calcLocalBoundingBox(sead::BoundBox3f* boundingBox) const {
    boundingBox->set({-500.0f, -500.0f, -500.0f}, {500.0f, 500.0f, 500.0f});
    return true;
}

AreaShapeOval::AreaShapeOval() {}

bool AreaShapeOval::isInVolume(const sead::Vector3f& trans) const {
    sead::Vector3f localPos = sead::Vector3f::zero;
    calcLocalPos(&localPos, trans);

    return localPos.squaredLength() <= sead::Mathf::square(500.0f);
}

bool AreaShapeOval::isInVolumeOffset(const sead::Vector3f& trans, f32 offset) const {
    sead::Vector3f scale = getScale();

    // has to be this way around to match
    if (scale.x == scale.y && scale.y == scale.z) {
        sead::Vector3f baseTrans;
        calcTrans(&baseTrans);
        sead::Vector3f offsetTrans = trans - baseTrans;
        f32 radius = scale.x * 500.0f + offset;

        return offsetTrans.squaredLength() <= sead::Mathf::square(radius);
    }

    return false;
}

bool AreaShapeOval::calcNearestEdgePoint(sead::Vector3f* edgePoint,
                                         const sead::Vector3f& trans) const {
    sead::Vector3f localPos = sead::Vector3f::zero;
    calcLocalPos(&localPos, trans);
    f32 length = localPos.length();

    if (length > 0.0f)
        localPos *= 500.0f / length;

    calcWorldPos(edgePoint, localPos);
    return true;
}

bool AreaShapeOval::checkArrowCollision(sead::Vector3f* a2, sead::Vector3f* a3,
                                        const sead::Vector3f& a4, const sead::Vector3f& a5) const {
    sead::Vector3f localA4 = sead::Vector3f::zero;
    calcLocalPos(&localA4, a4);
    sead::Vector3f localA5 = sead::Vector3f::zero;
    calcLocalPos(&localA5, a5);

    sead::Vector3f tmp1 = {0, 0, 0};
    sead::Vector3f tmp2 = {0, 0, 0};
    calcWorldPos(&tmp1, localA4);
    calcWorldPos(&tmp2, localA5);

    if (!checkHitSegmentSphere(sead::Vector3f::zero, localA4, localA5, 500.0f, a3, a2))
        return false;

    calcWorldPos(a2, *a2);
    calcWorldDir(a3, *a3);
    *a3 *= (-1);
    return true;
}

AreaShapeCylinder::AreaShapeCylinder(AreaShapeCylinder::OriginType originType)
    : mOriginType(originType) {}

}

AreaShapeInfinite::AreaShapeInfinite() {}

bool AreaShapeInfinite::isInVolume(const sead::Vector3f&) const {
    return true;
}

bool AreaShapeInfinite::isInVolumeOffset(const sead::Vector3f&, f32) const {
    return true;
}

bool AreaShapeInfinite::calcNearestEdgePoint(sead::Vector3f*, const sead::Vector3f&) const {
    return false;
}

bool AreaShapeInfinite::checkArrowCollision(sead::Vector3f*, sead::Vector3f*, const sead::Vector3f&,
                                            const sead::Vector3f&) const {
    return false;
}

bool AreaShapeInfinite::calcLocalBoundingBox(sead::BoundBox3f*) const {
    return false;
}
