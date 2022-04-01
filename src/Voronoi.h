#pragma once

#include "MathVector.h"
#include "MathMatrix2d.h"

#include <utility>
#include <iostream>
#include <vector>
#include <unordered_map>

namespace Voronoi
{
    typedef vector2d MasterPoint;
    typedef vector2d VoronoiPoint;

    class BisectLine;
    class VoronoiCell;



    class BisectLine
    {
    public:
        vector2d _midPoint;
        vector2d _dirVec;

        BisectLine(){}
        ~BisectLine(){}
        BisectLine(const MasterPoint& p1, const MasterPoint& p2);
        BisectLine(const VoronoiCell& v1, const VoronoiCell& v2);

        double substitutePoint(const VoronoiPoint& p);
        bool isIntersected(const VoronoiPoint& p1, const VoronoiPoint& p2);
        VoronoiPoint intersectAt(const VoronoiPoint& p1, const VoronoiPoint& p2);
    };


    class VoronoiCell
    {
    public:
        const int _id = -1;
        MasterPoint _mPoint;
        std::vector<VoronoiPoint> _vPoints;

        VoronoiCell(){}
        ~VoronoiCell(){}
        VoronoiCell(const int id, const MasterPoint mp) : _id(id), _mPoint(mp) {}
        VoronoiCell(const int id, const double x, const double y) : _id(id), _mPoint(MasterPoint(x,y)) {}
    };


    class Graph
    {
    public:
        double _xmin = 0.0;
        double _xmax = 0.0;
        double _ymin = 0.0;
        double _ymax = 0.0;
        double _xLen = 0.0;
        double _yLen = 0.0;
        double _xHalfLen = 0.0;
        double _yHalfLen = 0.0;
        std::vector<VoronoiCell> _vcells;

        Graph(){}
        ~Graph(){}
        Graph(const double xmin, const double xmax, const double ymin, const double ymax) : 
        _xmin(xmin), _xmax(xmax), _ymin(ymin), _ymax(ymax) 
        {
            _xLen = _xmax - _xmin;
            _yLen = _ymax - _ymin;
            _xHalfLen = _xLen / 2.0;
            _yHalfLen = _yLen / 2.0;
        }

        void appandNewMasterPoint(const int id, const MasterPoint mp);
        void appandNewMasterPoint(const int id, const double x, const double y);
        void initializeFirstVoronoiCell();
    };

}