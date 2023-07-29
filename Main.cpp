#include <iostream>
#include "FileSearch.h"

int main() {
    std::string filename;
    std::cout << "Enter the file name to search: ";
    std::cin >> filename;

    std::string path = "/";
    std::string foundPath = FindFile(path, filename);

    if (!foundPath.empty()) {
        std::cout << "File found at the path: " << foundPath << std::endl;
    } else {
        std::cout << "File not found." << std::endl;
    }

    return 0;
}
