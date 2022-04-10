#ifndef MATRIXGRAPH_HPP
#define MATRIXGRAPH_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
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
};

class MatrixGraph
{
private:
    // Neighborhood matrix
    Vertex **matrix = nullptr;
    int numberOfVertices = 0;
    int realVertices = 0;

    // Function to clear verticies
    void clear();
    // Function to check
    bool checkVertices(const int &v1, const int &v2);
    // Function to modify line
    std::string modifyStr(std::string line);
    // Function to prepeare input for adding a new vertex
    void makeInput(int *v1, int *v2, int *value, std::string line);
    // Color all vertices to white color
    void makeWhite();

public:
    MatrixGraph(int vertices = MAX_SIZE);
    ~MatrixGraph();

    // Function to create connection between two vertices
    void addEdge(const int &v1, const int &v2, const int &value);
    // Function to remove connection between two vertices
    void removeEdge(const int &v1, const int &v2);
    // Function to check if there is a connection between two vertices and get value of weight
    int checkEdge(const int &v1, const int &v2);
    // Function to clear graph and set up new settings
    void createVertices(int number);

    // Function to get number of neighbours of vertex
    int vertexDegree(const int &v);
    // Function to get all neihgbour vertices
    std::vector<int> getNeighbourIndices(const int &v);
    // Function to print all neihgbour vertices
    void printNeighbourIndices(const int &v);
    // Function to get number of edges
    int getNumberOfEdges();
    // Function to add edges from a file
    void read_graph(std::string path);
    // Function to export graph to a file
    void to_dot(std::string fileName);
    // Function to check wheather graph is a complete
    bool isComplete();
    // Function to check if given vertice is in graph
    bool contains(const int &v);

    // Function for Breadth First Search
    std::vector<Vertex> BFS(int s);
    // Function to get distance between starting point and end point
    int get_hop(std::vector<Vertex> queue, int endPoint);

    class BadVertixException : std::exception
    {
        const char *what() const throw()
        {
            return "Incorect vertix value";
        }
    };
};

#endif // MATRIXGRAPH_HPP