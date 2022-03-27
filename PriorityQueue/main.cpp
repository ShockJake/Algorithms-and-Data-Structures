#include "priorityQueue.hpp"

int main(int argc, char const *argv[])
{
    PriorityQueue<std::string> queue;

    Element<std::string, int> *elements = new Element<std::string, int>[argc - 1];
    int number_position;
    for (int i = 1; i < argc; i++)
    {
        std::string input = to_string(argv[i]);
        std::string word = "";
        std::string priority = "";

        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '(')
            {
                continue;
            }
            if (input[i] == ',')
            {
                number_position = i;
                break;
            }
            word += input[i];
        }

        for (int i = number_position + 1; i < input.size(); i++)
        {
            if (input[i] == ')')
            {
                break;
            }

            priority += input[i];
        }

        elements[i - 1].first = word;
        elements[i - 1].second = atoi(priority.c_str());
    }

    for (int i = 0; i < argc - 1; i++)
    {
        queue.insertElement(elements[i]);
    }
    std::cout << queue.toString() << std::endl;

    delete[] elements;

    return 0;
}
