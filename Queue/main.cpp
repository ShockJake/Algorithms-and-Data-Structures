#include "arrayBasedQueue.hpp"
#include "pointerBasedQueue.hpp"
int main(int argc, char const *argv[])
{
    cout << "\t--- Queue test ---\n";
    ArrayBasedQueue<string> abq(8);
    PointerBasedQueue<string> pbq(8);

    cout << "\n==* Enqueing elements: \'Ada\', \'Eva\', \'Ala\' \n";
    abq.enqueue("Ada");
    abq.enqueue("Eva");
    abq.enqueue("Ala");
    cout << abq.toString() << "| size: " << abq.size() << " <- Array Based Queue\n";

    pbq.enqueue("Ada");
    pbq.enqueue("Eva");
    pbq.enqueue("Ala");
    cout << pbq.toString() << "| size: " << pbq.size() << " <- Pointer Based Queue\n";

    cout << "\n==* Rearing the last element:\n";
    cout << abq.rear() << " <- Array Based Queue\n";
    cout << pbq.rear() << " <- Pointer Based Queue\n";

    cout << "\n==* Dequeue one element:\n";
    abq.dequeue();
    pbq.dequeue();
    cout << abq.toString() << " <- Array Based Queue\n";
    cout << pbq.toString() << " <- Pointer Based Queue\n";

    return 0;
}
