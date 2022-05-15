#ifndef LISTGRAPH_H
#define LISTGRAPH_H

#include <iostream>
#include <vector>
#include <list>

#define MAX_SIZE 500

enum Color
{
    White,
    Gray,
    Black
};

class Vertex
{
public:
    int value = 0;
    int color = White;
    int distance = 0;
    int position = 0;
    int endpoint = 0;
    int start_time = 0;
    int end_time = 0;
};

class ListGraph
{
private:
    std::vector<std::list<Vertex>> data;
    int numberOfVertices = 0;
    int realVertices = 0;

    // Method to check
    bool checkVertices(const int &v1, const int &v2);
    // Method to modify line
    std::string modifyStr(std::string line);
    // Method to prepeare input for adding a new vertex
    void makeInput(int *v1, int *v2, int *value, std::string line);
    // Method to color all vertices to white color
    void makeWhite();
    // Method to visit all vertices in DFS.
    void DFS_visit(int pos1, int pos2, int &time, std::list<int> &data, bool isFirst);

public:
    ListGraph(int vertices = MAX_SIZE);
    ~ListGraph();

    // Method to create connection between two vertices
    void addEdge(const int &v1, const int &v2, const int &value);

    // Method for Deep First Search
    std::list<int> DFS();
    // Method for printing DFS
    std::string DFS_toString(std::list<int> dfs);
};

#endif //LISTGRAPH_H