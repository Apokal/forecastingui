#pragma once
#include <iostream>
#include <vector>

std::vector<float> ES(std::vector<float> initVector)
{
    std::vector<float> resultVector;
    float weightValue = 0.6f;
    float MSE;
    float sum_of_elems = 0;

    std::cout << "Kalkulacja ES..." << std::endl;

    resultVector.push_back(initVector[0]);
    resultVector.push_back(initVector[0]);

    for (int i = 2; i < initVector.size(); i++) {
        float forecast = (weightValue * initVector[i - 1]) + ((1 - weightValue) * resultVector[i - 1]);
        resultVector.push_back(forecast);
    }

    for (auto& n : resultVector)
        sum_of_elems += n;

    MSE = sum_of_elems / resultVector.size();

    std::cout << "MSE = " << MSE << std::endl;
    std::cout << "Obliczenia ES sie skonczyly" << std::endl;
    return resultVector;
}
