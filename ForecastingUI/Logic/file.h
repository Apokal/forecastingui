#pragma once
#include <fstream>
#include <iterator>
#include <vector>
#include <string>

#include <iostream>

void write_to_file(std::string path, std::vector<float> Vector)
{
    std::ofstream ofs;
    ofs.open(path);
    std::ostream_iterator<float> output_iterator_generated(ofs, "\n");
    std::copy(Vector.begin(), Vector.end(), output_iterator_generated);
    ofs.close();
}

std::vector<float> read_custom_file(std::string path)
{
    std::vector<float> ret;
    std::ifstream ifs;
    ifs.open(path);

    std::cout << "############# PARSING INPUT FILE ###############" << std::endl;
    std::cout << "### File path: " << path << std::endl;

    float num;
    while (ifs >> num)
    {
        //std::cout << num << std::endl;
        ret.push_back(num);
    }

    ifs.close();

    return ret;
}
