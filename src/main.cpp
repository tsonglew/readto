#include <iostream>
#include <fstream>
#include <string>
#include "readto.hpp"

int main()
{
    auto fn = "testb";
    std::ifstream file(fn, std::ios::binary);

    // Check if the file is successfully opened
    if (!file.is_open())
    {
        std::cout << "Error opening file." << std::endl;
        return 1;
    }
    auto data_len = 0;
    auto data_cnt = 0;
    std::string delimiter = "$ND$\n";
    ReadUntilIO io(std::move(file), delimiter);
    for (auto i = 0; i < 1; i++)
    {
        auto s = io.readline();
        data_len += s.size();
        data_cnt++;
        // std::cout << s << std::endl;
    }
    std::cout << "Total data length: " << data_len << std::endl;
    std::cout << "Total data cnt: " << data_cnt << std::endl;

    return 0;
}
