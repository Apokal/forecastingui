#pragma once
#include <iostream>
#include <vector>

using namespace std;

vector<float> WMA(vector<float> initVector) {
    vector<float> resultVector;
    int period = 3;

    double calcValue = 0; // weightened, calculated value
    int j_inc = 0; // calc loop helpers for calcValue
    int period_inc = period;
    int w_inc = 0;

    vector<float> weights = { 0.2f, 0.3f, 0.5f };

    cout << "Kalkulacja WMA..." << endl;

    for (int i = 0; i < period; i++) {
        resultVector.push_back(initVector[i]);
    }

    for (int i = period; i < initVector.size(); i++) {
        for (int j = j_inc; j < period_inc; j++) {
            if (w_inc % period == 0)
                w_inc = 0;
            calcValue += initVector[j] * weights[w_inc];
            j_inc++;
            period_inc++;
            w_inc++;
            if (w_inc % period == 0) {
                initVector[j_inc] = calcValue;
                break;
            }
        }
        resultVector.push_back(calcValue);
        calcValue = 0;
        j_inc = j_inc - period + 1;
        period_inc = period_inc - period;
        if (j_inc % period_inc == 0)
            period_inc++;
            w_inc = 0;
    }

    cout << "Obliczenia WMA sie skonczyly" << endl;
    return resultVector;
}
