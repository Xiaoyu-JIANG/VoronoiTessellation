#include "Voronoi.h"

void Voronoi::Graph::appandNewMasterPoint(const int id, const Voronoi::MasterPoint mp)
{
    _vcells.push_back(Voronoi::VoronoiCell(id, mp));
}

void Voronoi::Graph::appandNewMasterPoint(const int id, const double x, const double y)
{
    _vcells.push_back(Voronoi::VoronoiCell(id, x, y));
}

void Voronoi::Graph::initializeFirstVoronoiCell()
{
    if (_vcells.size() == 0) {
        std::cout << "There is no Voronoi cell, please appand one." << std::endl;
        exit(101);
    }
    if (_vcells.size() > 1) {
        std::cout << "There are too many Voronoi cells (" << _vcells.size() << "), pleases start with one Voronoi cell." << std::endl;
        exit(102);
    }
    std::cout << "Start initializing first Voronoi cell." << std::endl;

}