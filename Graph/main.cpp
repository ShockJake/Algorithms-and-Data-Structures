#include "matrixGraph.hpp"

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    MatrixGraph g1(1000);
    g1.read_graph(argv[1]);
    if (g1.isComplete())
    {
        cout << "graph is comlete" << endl;
    }
    else
    {
        cout << "graph is not complete" << endl;
    }
    g1.to_dot("result.dot");

    return 0;
}
