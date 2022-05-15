#include "priorityQueue.hpp"
#include <string>
#include <fstream>

int main(int argc, char *argv[])
{
    std::string line;
    int lineNum = 0;
    std::fstream file;

    file.open(std::string(argv[1]).c_str(), std::fstream::in);
    if (!file.is_open())
    {
        std::cout << "Can't open the file\n";
        return 1;
    }

    while (!file.eof())
    {
        std::getline(file, line);
        lineNum++;
    }
    file.close();
    PriorityQueue pq(lineNum);

    file.open(std::string(argv[1]).c_str(), std::fstream::in);
    while (!file.eof())
    {
        std::getline(file, line);
        Element el(line, (int)line[0]);
        pq.InsertElement(el);
    }
    file.close();

    std::string newFile("sorted-");
    newFile.assign(argv[1]);

    file.open(newFile, std::fstream::out);

    while (!pq.isEmpty())
    {
        Element e = pq.pop();
        file << e.getValue() << '\n';
    }

    file.close();
    return 0;
}
