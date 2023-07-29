#include "FileSearch.h"
#include <iostream>
#include <vector>
#include <dirent.h>

// Function to search for a file in the specified directory and its subdirectories
void SearchInDirectory(const std::string& directory, const std::string& filename) {
    DIR* dir = opendir(directory.c_str());
    if (dir) {
        struct dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            if (entry->d_type == DT_DIR && std::string(entry->d_name) != "." && std::string(entry->d_name) != "..") {
                // Recursively call the function to search in the subdirectory.
                SearchInDirectory(directory + "/" + entry->d_name, filename);
            } else if (entry->d_type == DT_REG && std::string(entry->d_name) == filename) {
                std::cout << "File not found: " << directory + "/" + entry->d_name << std::endl;
                // File found, so we stop the search
                return;
            }
        }
        closedir(dir);
    }
}

// Function to search for a file by name in the specified path
std::string FindFile(const std::string& path, const std::string& filename) {
    SearchInDirectory(path, filename);
    return "";
}
