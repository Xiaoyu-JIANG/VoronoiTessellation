#include <iostream>
#include "src/Voronoi.h"



int main()
{
    std::cout << "hello Voronoi Tessellation" << std::endl;
    
    Voronoi::Graph graph(-10.0, 10.0, -10.0, 10.0);
    graph.initializeFirstVoronoiCell();
    // graph.appandNewMasterPoint(0, 0.0, 0.0);

    // graph._vcells[0]._mPoint.print();


    return 0;
}