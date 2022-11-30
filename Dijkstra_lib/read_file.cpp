//
// Created by Alexander Allis on 10/10/22.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>

#include "read_file.h"
#include "LinkedList.h"

using std::ifstream;

int readFile(const std::string & fileName, std::vector<LinkedList> & treePairs, int & numberOfVertices, int & numberOfEdges) {

    // Check if file exists
    ifstream inFile(fileName.c_str());  // Check to make sure file exists
    if (!inFile) {
        std::cerr << "File not found." << std::endl;
        return -1;
        // Or throw error
    }

// Open file
    ifstream fileStream(fileName);
    if (!fileStream.is_open()) {
        std::cout << "Can't read file." << std::endl;
        return -1;
        // Or throw error
    }

    std::stringstream sStream;  // stream to parse each line
    std::string line;  // each line (string)
    std::vector<int> row;  // each line (int)
    std::string vectorA;  // each vertex
    std::string vectorB;
    std::string vectorC;

    getline(fileStream, line);  // Consume first line
    numberOfVertices = stoi(line);

    getline(fileStream, line);  // Consume second line
    numberOfEdges = stoi(line);

    // Resize treePairs to be as large as the number of vertices
    treePairs.resize(numberOfVertices);

    while(!fileStream.eof()) {  // Loop through lines

        getline(fileStream, line);

        if (!fileStream.fail()) {
            sStream << line;
            while(!sStream.eof()) {  // Loop through numbers
                if(!sStream.fail()) {
                    sStream >> vectorA;
                    sStream >> vectorB;
                    sStream >> vectorC;
                    treePairs.at(std::stoi(vectorA) - 1).add(std::stoi(vectorB), std::stof(vectorC));
                }
            }

            // Clean up
            sStream.str(std::string());  // Clear string
            sStream.clear();  // Clear the state flags for eof()
            for (int &k: row) {    // Clear contents of the vector
                row.clear();
            }
        }
    }

    fileStream.close();
    return 0;
}
