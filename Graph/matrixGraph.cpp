#include "matrixGraph.hpp"

MatrixGraph::MatrixGraph(int numberOfVertices)
{
    this->numberOfVertices = numberOfVertices;
    matrix = new int *[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++)
    {
        matrix[i] = new int[numberOfVertices];
    }
    clear();
}

MatrixGraph::~MatrixGraph()
{
    for (int i = 0; i < numberOfVertices; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void MatrixGraph::clear()
{
    for (int i = 0; i < numberOfVertices; ++i)
    {
        for (int j = 0; j < numberOfVertices; ++j)
        {
            matrix[i][j] = 0;
        }
    }
}

void MatrixGraph::createVertices(int number)
{
    for (int i = 0; i < numberOfVertices; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    numberOfVertices = number;

    matrix = new int *[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++)
    {
        matrix[i] = new int[numberOfVertices];
    }
}

bool MatrixGraph::checkVertices(const int &v1, const int &v2)
{
    if (v1 < 0 || v1 >= numberOfVertices || v2 < 0 || v2 >= numberOfVertices)
    {
        return false;
    }

    return true;
}

void MatrixGraph::addEdge(const int &v1, const int &v2, const int &value)
{
    if (checkVertices(v1, v2))
    {
        if(!contains(v1))
        {
            realVertices++;
        }
        if(!contains(v2))
        {
            realVertices++;
        }
        matrix[v1][v2] = value;
    }
    else
    {
        throw BadVertixException();
    }
}

void MatrixGraph::removeEdge(const int &v1, const int &v2)
{
    if (checkVertices(v1, v2))
    {
        matrix[v1][v2] = 0;
    }
    throw BadVertixException();
}

int MatrixGraph::checkEdge(const int &v1, const int &v2)
{
    if (checkVertices(v1, v2))
    {
        return matrix[v1][v2];
    }
    throw BadVertixException();
}

int MatrixGraph::vertexDegree(const int &v)
{
    int degree = 0;

    if ((v > numberOfVertices - 1) || (v < 0))
    {
        throw BadVertixException();
    }

    for (int i = 0; i < numberOfVertices; i++)
    {
        if (matrix[v][i] != 0)
        {
            degree++;
        }
    }
    return degree;
}

std::vector<int> MatrixGraph::getNeighbourIndices(const int &v)
{
    if (v < 0 || v > numberOfVertices)
    {
        throw BadVertixException();
    }

    std::vector<int> neighbours;
    for (int i = 0; i < numberOfVertices; i++)
    {
        if (matrix[v][i] != 0)
        {
            neighbours.push_back(i);
        }
    }
    return neighbours;
}

void MatrixGraph::printNeighbourIndices(const int &v)
{
    std::vector<int> neighbours = getNeighbourIndices(v);

    for (auto iterator = neighbours.cbegin(); iterator != neighbours.cend(); ++iterator)
    {
        std::cout << *iterator << ' ';
    }
    std::cout << '\n';
}

int MatrixGraph::getNumberOfEdges()
{
    int number = 0;

    for (int i = 0; i < numberOfVertices; ++i)
    {
        for (int j = 0; j < numberOfVertices; ++j)
        {
            if (matrix[i][j] != 0)
            {
                number++;
            }
        }
    }

    return number;
}

std::string MatrixGraph::modifyStr(std::string line)
{
    // Making line more capable for reading data
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == ',')
        {
            line.replace(i, 1, " ");
        }
    }
    return line;
}

void MatrixGraph::makeInput(int *v1, int *v2, int *value, std::string line)
{
    std::stringstream ss;
    ss << line;

    std::string tmp;
    ss >> tmp;
    std::stringstream(tmp) >> *v1;
    tmp = "";
    ss >> tmp;
    std::stringstream(tmp) >> *v2;
    tmp = "";
    ss >> tmp;
    std::stringstream(tmp) >> *value;
    tmp = "";
}

void MatrixGraph::read_graph(std::string path)
{
    try
    {
        std::ifstream file;
        file.open(path);
        std::string line;
        int v1, v2, value;

        while (!file.eof())
        {
            v1 = 0;
            v2 = 0;
            value = 0;
            std::getline(file, line);
            line = modifyStr(line);
            makeInput(&v1, &v2, &value, line);

            addEdge(v1, v2, value);
        }
        file.close();
    }
    catch (const std::ifstream::failure &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void MatrixGraph::to_dot(std::string fileName)
{
    try
    {
        std::ofstream file(fileName);
        std::string line;

        file << "digraph {" << std::endl;
        for (int i = 0; i < numberOfVertices; i++)
        {
            for (int j = 0; j < numberOfVertices; j++)
            {
                if (matrix[i][j] != 0)
                {
                    line += std::to_string(i);
                    line += " -> ";
                    line += std::to_string(j);
                    line += "[label=\"" + std::to_string(matrix[i][j]) + "\"];";

                    file << line << std::endl;
                    line = "";
                }
            }
        }
        file << "}" << std::endl;
        file.close();
    }
    catch (const std::ofstream::failure &e)
    {
        std::cerr << e.what() << '\n';
    }
}

bool MatrixGraph::contains(const int &v)
{
    for (int i = 0; i < numberOfVertices; i++)
    {
        if (matrix[v][i] != 0)
        {
            return true;
        }
    }

    for(int i = 0; i < numberOfVertices; i++)
    {
        if(matrix[i][v] != 0)
        {
            return true;
        }
    }
    return false;
}

bool MatrixGraph::isComplete()
{
    int edges = getNumberOfEdges();
    int E = (realVertices * (realVertices - 1)) / 2;

    return E == edges;
}