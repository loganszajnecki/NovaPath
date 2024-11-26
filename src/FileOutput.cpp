#include <fstream>
#include <iostream>
#include <filesystem>
#include "FileOutput.h"

FileOutput::FileOutput(const std::string& folder, const std::string& filename) {
    // Ensure the folder exists
    setupFolder(folder);

    // Build the full file path
    filepath_ = folder + "/" + filename;

    // Delete the existing file if it exists
    deleteExistingFile(filepath_);

    // Open the file for writing
    outFile_.open(filepath_);
    if (!outFile_) {
        throw std::ios_base::failure("Failed to open file: " + filepath_);
    }
}

FileOutput::~FileOutput() {
    if (outFile_.is_open()) {
        outFile_.close();
    }
}

void FileOutput::setupFolder(const std::string& folder) {
    if (!std::filesystem::exists(folder)) {
        std::filesystem::create_directory(folder);
    }
}

void FileOutput::deleteExistingFile(const std::string& filepath) {
    if (std::filesystem::exists(filepath)) {
        std::filesystem::remove(filepath);
    }
}

void FileOutput::writeHeader() {
    if (outFile_.is_open()) {
        outFile_ << "Time,PosX,PosY,PosZ,VelX,VelY,VelZ\n";
    }
}

void FileOutput::writeData(double time, const State& state) {
    if (outFile_.is_open()) {
        outFile_ << time << "," << state.x << "," << state.y << "," << state.z << ","
                 << state.u << "," << state.v << "," << state.w << "\n";
    }
}
