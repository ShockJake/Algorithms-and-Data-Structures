#include "arrayBasedStack.h"

using namespace std;

int main(int argc, char const *argv[])
{
    ArrayBasedStack<int> ar_stack(10);
    ar_stack.push(6);
    cout << ar_stack.peek() << endl;
    ar_stack.push(7);
    cout << ar_stack.peek() << endl;
    cout << ar_stack.size() << endl;
    ar_stack.pop();
    cout << ar_stack.peek();
    return 0;
}
