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

        virtual std::vector<float> run(std::vector<float> initVector, size_t history_range, size_t forecast_range)
        {
            std::cout << "Kalkulacja WMA..." << std::endl;

            std::vector<float> resultVector;
            float weightValue = m_settings.smoothConstant;
            std::cout << "weightValue: " << weightValue << std::endl;

            // Number of previous values taken for one new forecast
            size_t historicalData = history_range;
            std::cout << "historicalData: " << history_range << std::endl;

            // Number of values in future forecast
            size_t numForFutureForecast = forecast_range;
            std::cout << "numForFutureForecast: " << forecast_range << std::endl;

            // initVectorSize in the beginning of algorithm
            size_t startInitVectorSize = initVector.size();

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
