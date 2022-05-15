#include "matrixGraph.hpp"

MatrixGraph::MatrixGraph(int numberOfVertices)
{
    this->numberOfVertices = numberOfVertices;
    matrix = new Vertex *[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++)
    {
        matrix[i] = new Vertex[numberOfVertices];
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
            matrix[i][j].value = 0;
            matrix[i][j].color = White;
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

    matrix = new Vertex *[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++)
    {
        matrix[i] = new Vertex[numberOfVertices];
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
        if (!contains(v1))
        {
            realVertices++;
        }
        if (!contains(v2))
        {
            realVertices++;
        }
        matrix[v1][v2].value = value;
        matrix[v1][v2].position = v1;
        matrix[v1][v2].endpoint = v2;
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
        matrix[v1][v2].value = 0;
    }
    throw BadVertixException();
}

int MatrixGraph::checkEdge(const int &v1, const int &v2)
{
    if (checkVertices(v1, v2))
    {
        return matrix[v1][v2].value;
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
        if (matrix[v][i].value != 0)
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

    std::vector<int> neighbors;
    for (int i = 0; i < numberOfVertices; i++)
    {
        if (matrix[v][i].value != 0)
        {
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

void MatrixGraph::printNeighbourIndices(const int &v)
{
    std::vector<int> neighbors = getNeighbourIndices(v);

    for (auto iterator = neighbors.cbegin(); iterator != neighbors.cend(); ++iterator)
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
            if (matrix[i][j].value != 0)
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
            if (strlen(line.c_str()) == 0)
            {
                continue;
            }

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
                if (matrix[i][j].value != 0)
                {
                    line += std::to_string(i);
                    line += " -> ";
                    line += std::to_string(j);
                    line += "[label=\"" + std::to_string(matrix[i][j].value) + "\"];";

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
        if (matrix[v][i].value != 0)
        {
            return true;
        }
    }

    for (int i = 0; i < numberOfVertices; i++)
    {
        if (matrix[i][v].value != 0)
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

void MatrixGraph::makeWhite()
{
    for (int i = 0; i < numberOfVertices; i++)
    {
        for (int j = 0; j < numberOfVertices; j++)
        {
            if (matrix[i][j].color != White)
            {
                matrix[i][j].color = White;
            }
        }
    }
}

std::vector<Vertex> MatrixGraph::BFS(int start)
{
    makeWhite();

    std::vector<Vertex> result;
    int pos, distance = 0;
    std::list<int> queue;
    queue.push_back(start);

    result.push_back(matrix[start][start]);

    while (!queue.empty())
    {
        pos = queue.front();
        queue.pop_back();
        distance++;

        for (int i = 0; i < numberOfVertices; i++)
        {
            if (i == pos)
            {
                continue;
            }
            if (matrix[pos][i].value > 0 && matrix[pos][i].color == White)
            {
                matrix[pos][i].color = Gray;
                matrix[pos][i].distance = distance;
                result.push_back(matrix[pos][i]);
                queue.push_back(i);
            }
        }
        matrix[pos][pos].color = Black;
    }
    return result;
}

int MatrixGraph::get_hop(std::vector<Vertex> queue, int endPoint)
{
    if (endPoint == queue.at(0).endpoint)
    {
        return 0;
    }

    for (int i = 0; i < queue.size(); i++)
    {
        if (queue.at(i).endpoint == endPoint)
        {
            return queue.at(i).distance;
        }
    }
    return -1;
}

int containsNum(std::list<int> &data, int number)
{
    int n = 0;
    for (int i : data)
    {
        if (i == number)
        {
            n++;
        }
    }
    return n;
}

void MatrixGraph::DFS_visit(int pos1, int pos2, int &time, std::list<int> &data, bool isFirst, std::list<int> &visited)
{
    bool hasNext = false;
    visited.push_back(pos2);
    matrix[pos1][pos2].color = Gray;
    time++;
    matrix[pos1][pos2].start_time = time;
    for (int i = 0; i < numberOfVertices; i++)
    {
        // std::cout << '#'<< pos2 << ',' << i << ' ' << matrix[pos2][i].color << '\n';
        if (matrix[pos2][i].color == White && matrix[pos2][i].endpoint != 0)
        {
            //std::cout << "\tDetection: " << pos2 << ',' << i << '\n';
            matrix[pos2][i].color = Gray;
            DFS_visit(pos2, i, time, data, false, visited);
            hasNext = true;
        }
    }
    matrix[pos1][pos2].color = Black;
    time++;
    matrix[pos1][pos2].end_time = time;
    if (containsNum(visited, pos2) > 1 && !hasNext)
    {
        return;
    }
    if (!hasNext && !containsNum(data, pos2) && containsNum(visited, pos2) == 0)
    {
        //std::cout << "Pushing " << pos2 << " from dfs_visit hn\n";
        data.push_front(pos2);
    }
    else if (!containsNum(data, matrix[pos1][pos2].endpoint))
    {
        //std::cout << "Pushing " << pos2 << " from dfs_visit con\n";
        data.push_front(matrix[pos1][pos2].endpoint);
    }
}

std::list<int> MatrixGraph::DFS()
{
    makeWhite();

    int time = 0;
    std::list<int> dfs_list;
    bool isConnected = false;

    std::list<int> visited;

    for (int i = 0; i < numberOfVertices; i++)
    {
        for (int j = 0; j < numberOfVertices; j++)
        {
            if (matrix[i][j].color == White && matrix[i][j].endpoint != 0)
            {
                visited.push_back(i);
                //std::cout << "Starting DFS_visit(" << i << ',' << j << ")\n";
                DFS_visit(i, j, time, dfs_list, true, visited);
                isConnected = true;
            }
        }
        if (isConnected)
        {
            //std::cout << "Pushing " << i << " from dfs\n";
            dfs_list.push_front(i);
            isConnected = false;
        }
    }

    return dfs_list;
}

std::string MatrixGraph::DFS_toString(std::list<int> dfs)
{
    std::string dfs_str;

    for (int pos : dfs)
    {
        dfs_str += std::to_string(pos);
        dfs_str += " ";
    }
    return dfs_str;
}
