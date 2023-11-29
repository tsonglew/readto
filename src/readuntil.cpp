#include "readuntil.hpp"

ReadUntilIO::ReadUntilIO(std::ifstream ifs, const std::string &delimiter) : ifs(std::move(ifs)), delimiter(delimiter)
{
}

void ReadUntilIO::closeFile()
{
    if (this->ifs.is_open())
    {
        this->ifs.close();
    }
}

ReadUntilIO::~ReadUntilIO()
{
    this->closeFile();
}

bool ends_with(const std::string &str, const std::string &suffix)
{
    if (str.length() < suffix.length())
    {
        return false;
    }
    return str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0;
}

std::string ReadUntilIO::readline()
{
    std::string pattern = "$ND$\n";
    std::string readPattern;
    int cnt = 0;

    std::string s, out;

    // while (std::getline(this->ifs, s, '\n'))
    // {
    //     out += s;
    //     out += '\n';
    //     if (ends_with(out, pattern))
    //     {
    //         break;
    //     }
    // }
    // return out;
    std::getline(this->ifs, s, '\n');
    s += '\n';
    return s;
}
