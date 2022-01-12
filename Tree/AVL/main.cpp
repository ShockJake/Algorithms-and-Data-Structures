#include "avlTree.hpp"

int main(int argc, char const *argv[])
{
    try
    {
        AVLTree<int> myTree;

        //myTree.printInOrder();

        myTree.insert(12);
        myTree.insert(13);
        myTree.insert(10);
        myTree.insert(11);

        myTree.printInOrder();
        std::cout << "InOrder\n";
        myTree.printPreOrder();
        std::cout << "PreOrder\n";
        myTree.printPostOrder();
        std::cout << "PostOrder\n\n";

        std::cout << myTree.findMax() << " - max\n";
        std::cout << myTree.findMin() << " - min\n\n";

        std::cout << myTree.contains(11) << " - contains 11\n";

        myTree.remove(11);
        myTree.printInOrder();
        std::cout << "\n--- removed 11\n";

        std::cout << myTree.contains(11) << " - not contains 11\n\n";

        AVLTree<int> myTree2;
        myTree2 = myTree;

        myTree2.printInOrder();
        std::cout << " - second tree\n";

    }
    catch (const AVLTree<int>::EmptyTreeException &e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}
