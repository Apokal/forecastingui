#pragma once
#include <vector>
#include <string>

void write_to_file(std::string path, std::vector<float> Vector);
std::vector<float> read_custom_file(std::string path);
