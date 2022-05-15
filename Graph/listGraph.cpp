#include "listGraph.hpp"

ListGraph::ListGraph(int vertices)
{
    numberOfVertices = vertices;
}

ListGraph::~ListGraph()
{
}

bool ListGraph::checkVertices(const int &v1, const int &v2)
{
    if (v1 < 0 || v1 >= numberOfVertices || v2 < 0 || v2 >= numberOfVertices)
    {
        return false;
    }

    return true;
}

void ListGraph::addEdge(const int &v1, const int &v2, const int &value)
{
    
}