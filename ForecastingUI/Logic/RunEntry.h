#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <iterator>
#include <functional>
#include <map>
#include <string>
#include <sstream>
#include "RunEntry.h"
#include "vectorGenerator.h"
#include "fileGenerator.h"
#include "SMA.h"
#include "WMA.h"
#include "ES.h"
#include "LTP.h"

using namespace std;

void RunEntry(vector<float> initVector, std::map<std::string, std::function<vector<float>(vector<float>)>> forecastMap, string forecastType) {
    typedef std::chrono::high_resolution_clock Clock;
    vector<float> resultVector;

    auto t_start = Clock::now();

    resultVector = forecastMap[forecastType](initVector);
    std::ostringstream oss;
    oss << "C:\\Users\\SP\\ForeCode\\SMA\\SMAProject\\Pliki\\" << forecastType << ".txt";
    std::string path = oss.str();
    fileGenerator(path, resultVector);

    auto t_end = Clock::now();

    std::cout << "Czas wykonania: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count()
        << " milisekudny" << endl << endl;
}
