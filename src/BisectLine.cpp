#include "Voronoi.h"


Voronoi::BisectLine::BisectLine(const MasterPoint& p1, const MasterPoint& p2)
{
    _midPoint = (p1 + p2) / 2.0;
    _dirVec = p2 - p1;
    _dirVec.normalize();
}

Voronoi::BisectLine::BisectLine(const VoronoiCell& v1, const VoronoiCell& v2)
{
    _midPoint = (v1._mPoint + v2._mPoint) / 2.0;
    _dirVec = v1._mPoint - v2._mPoint;
    _dirVec.normalize();
}

double Voronoi::BisectLine::substitutePoint(const VoronoiPoint& p)
{
    return (p - _midPoint).dot(_dirVec);
}

bool Voronoi::BisectLine::isIntersected(const VoronoiPoint& p1, const VoronoiPoint& p2)
{
    return substitutePoint(p1) * substitutePoint(p2) < 0.0;
}

Voronoi::VoronoiPoint Voronoi::BisectLine::intersectAt(const VoronoiPoint& p1, const VoronoiPoint& p2)
{
    vector2d otherPoint = _midPoint + _dirVec;
    double D = (p1.x()-p1.x())*(_midPoint.y()-otherPoint.y()) - (p1.y()-p2.y())*(_midPoint.x()-otherPoint.x());
    double temp1 = (p1.x()*p2.y()-p1.y()*p2.x()) / D;
    double temp2 = (_midPoint.x()*otherPoint.y()-_midPoint.y()*otherPoint.x()) / D;
    return Voronoi::VoronoiPoint(temp1*(_midPoint.x()-otherPoint.x()) - (p1.x()-p2.x())*temp2,
                                 temp1*(_midPoint.y()-otherPoint.y()) - (p1.y()-p2.y())*temp2);
}