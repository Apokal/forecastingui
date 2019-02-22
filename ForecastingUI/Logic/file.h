#pragma once
#include <fstream>
#include <iterator>
#include <vector>

void write_to_file(std::string path, std::vector<float> Vector)
{
    std::ofstream ofs;
    ofs.open(path);
    std::ostream_iterator<float> output_iterator_generated(ofs, "\n");
    std::copy(Vector.begin(), Vector.end(), output_iterator_generated);
    ofs.close();
}
