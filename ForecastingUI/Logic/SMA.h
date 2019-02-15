#pragma once
#include <iostream>
#include <vector>

using namespace std;

vector<float> SMA(vector<float> initVector) {
    vector<float> resultVector;
    int length = 5; // Liczba okresow
    double sum = 0;
    int counter = 0;

    cout << "Kalkulacja SMA..." << endl;

    for (int i = 0; i < initVector.size(); i++) {
        sum += initVector[i];
        counter++;
        if (counter >= length) {
            resultVector.push_back(sum / length);
            sum -= initVector[counter - length];
        }
    }

    cout << "Obliczenia SMA sie skonczyly" << endl;
    return resultVector;
}
