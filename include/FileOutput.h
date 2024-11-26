#ifndef FILEOUTPUT_H
#define FILEOUTPUT_H

#include <fstream> 
#include <string>
#include <filesystem>
#include "Missile.h"

// Class to handle writing simulation results to a CSV file
class FileOutput {
public:
    FileOutput(const std::string& folder, const std::string& filename);
    ~FileOutput();

    void writeHeader();
    void writeData(double time, const State& state);

private:
    std::string filepath_;
    std::ofstream outFile_;

    void setupFolder(const std::string& folder);
    void deleteExistingFile(const std::string& filepath);
};

#endif // FILEOUTPUT_H

