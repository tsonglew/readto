#ifndef READUNTILIO_HPP
#define READUNTILIO_HPP

#include <iostream>
#include <fstream>
#include <string>

class ReadUntilIO
{
private:
    std::ifstream ifs;
    std::string delimiter;

public:
    ReadUntilIO(std::ifstream file, const std::string& delimiter);
    ~ReadUntilIO();
    std::string readline();
    void closeFile();
};

#endif
