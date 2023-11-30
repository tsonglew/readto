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
    ssize_t ReadUntilIO::scan_eol(ssize_t);

public:
    ReadUntilIO(std::ifstream, const std::string &);
    ~ReadUntilIO();
    std::string readline();
    void closeFile();
};

#endif
