#include "matrixGraph.hpp"

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    MatrixGraph g1(600);
    g1.read_graph(argv[1]);

    int start = atoi(argv[2]);
    std::vector<Vertex> v = g1.BFS(start);

    for (int i = 3; i < argc; i++)
    {
        int end_point = atoi(argv[i]);
        cout << g1.get_hop(v, end_point) << " ";
    }
    cout << endl;

    return 0;
}
