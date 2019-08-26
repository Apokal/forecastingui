#pragma once
#include <iostream>
#include <vector>

#include "quantitativemethodbase.h"

namespace Quantitative
{
    class QESQuntitativeMethod : public QQuantitativeMethodBase
    {
    public:

        struct Settings
        {
            float smoothConstant = 0.0f;
        };

        QESQuntitativeMethod (const Settings& settings)
            : QQuantitativeMethodBase("ES"),
              m_settings(settings)
        {}
        virtual ~QESQuntitativeMethod() {}

        virtual std::vector<float> run(std::vector<float> initVector)
        {
            std::vector<float> resultVector;
            float weightValue = m_settings.smoothConstant;

            // Number of previous values taken for one new forecast
            // int historicalData = m_settings.period;
            int historicalData = 60;

            // Number of values in future forecast
            // int numForFutureForecast = m_settings.numForFutureForecast;
            int numForFutureForecast = 30;

            // initVectorSize in the beginning of algorithm
            int startInitVectorSize = initVector.size();

            std::cout << "Kalkulacja ES...." << std::endl;

            resultVector.push_back(initVector[initVector.size() - historicalData]);

            for (int i = 0; i < numForFutureForecast; i++) {
                float forecast;

                if((initVector.size() - historicalData + i) >= initVector.size()){
                    initVector.push_back(resultVector[resultVector.size() - 2]);
                }

                forecast = (weightValue * initVector[startInitVectorSize - historicalData + i]) + ((1 - weightValue) * resultVector[i]);
                resultVector.push_back(forecast);
            }

            // first element always will be predefined - no need to store
            resultVector.erase(resultVector.begin());

            std::cout << "Obliczenia ES sie skonczyly" << std::endl;
            return resultVector;
        }

    private:
        Settings m_settings;
    };
}
