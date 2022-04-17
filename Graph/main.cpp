#include "matrixGraph.hpp"

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    MatrixGraph g1(100);
    g1.read_graph(argv[1]);

    std::list<int> v = g1.DFS();

    cout << "\n" << g1.DFS_toString(v);
    cout << endl;

    return 0;
}
