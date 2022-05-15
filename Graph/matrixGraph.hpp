#ifndef MATRIXGRAPH_HPP
#define MATRIXGRAPH_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
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

class MatrixGraph
{
private:
    // Neighborhood matrix
    Vertex **matrix = nullptr;
    int numberOfVertices = 0;
    int realVertices = 0;

    // Method to clear verticies
    void clear();
    // Method to check
    bool checkVertices(const int &v1, const int &v2);
    // Method to modify line
    std::string modifyStr(std::string line);
    // Method to prepeare input for adding a new vertex
    void makeInput(int *v1, int *v2, int *value, std::string line);
    // Method to color all vertices to white color
    void makeWhite();
    // Method to visit all vertices in DFS.
    void DFS_visit(int pos1, int pos2, int &time, std::list<int> &data, bool isFirst, std::list<int> &visited);

public:
    MatrixGraph(int vertices = MAX_SIZE);
    ~MatrixGraph();

    // Method to create connection between two vertices
    void addEdge(const int &v1, const int &v2, const int &value);
    // Method to remove connection between two vertices
    void removeEdge(const int &v1, const int &v2);
    // Method to check if there is a connection between two vertices and get value of weight
    int checkEdge(const int &v1, const int &v2);
    // Method to clear graph and set up new settings
    void createVertices(int number);

    // Method to get number of neighbours of vertex
    int vertexDegree(const int &v);
    // Method to get all neihgbour vertices
    std::vector<int> getNeighbourIndices(const int &v);
    // Method to print all neihgbour vertices
    void printNeighbourIndices(const int &v);
    // Method to get number of edges
    int getNumberOfEdges();
    // Method to add edges from a file
    void read_graph(std::string path);
    // Method to export graph to a file
    void to_dot(std::string fileName);
    // Method to check wheather graph is a complete
    bool isComplete();
    // Method to check if given vertice is in graph
    bool contains(const int &v);

    // Method for Breadth First Search
    std::vector<Vertex> BFS(int s);
    // Method to get distance between starting point and end point
    int get_hop(std::vector<Vertex> queue, int endPoint);

    // Method for Deep First Search
    std::list<int> DFS();
    // Method for printing DFS
    std::string DFS_toString(std::list<int> dfs);

    class BadVertixException : std::exception
    {
        const char *what() const throw()
        {
            return "Incorect vertix value";
        }
    };
};

#endif // MATRIXGRAPH_HPP