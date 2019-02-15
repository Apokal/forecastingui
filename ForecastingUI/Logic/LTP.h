#pragma once
#include <iostream>
#include <vector>

using namespace std;

vector<float> LTP(vector<float> initVector) {
    vector<float> results;
    int limit = 10;
    float xSum = 0;
    float ySum = 0;
    float xySum = 0;
    float xSqrSum = 0;

    cout << "Kalkulacja LTP..." << endl;

    for (int i = 0; i < limit; i++) {
        xSum += i+1;
        ySum += initVector[i];
        xySum += (i + 1) * initVector[i];
        xSqrSum += (i + 1) * (i + 1);
    }

    float intercept = ((xSqrSum * ySum) - (xSum * xySum)) /
                      ((limit * xSqrSum) - (xSum * xSum));

    float slope = ((limit * xySum) - (xSum * ySum)) /
                  ((limit * xSqrSum) - (xSum * xSum));

    for (int i = 0; i < initVector.size(); i++) {
        if (i < limit) {
            results.push_back(initVector[i]);
        }
        else {
            float val = intercept + slope * i;
            results.push_back(val);
        }
    }

    return results;
}
