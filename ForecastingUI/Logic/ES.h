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

        virtual std::vector<float> run(std::vector<float> initVector, size_t forecast_range)
        {
            std::vector<float> resultVector;
            float weightValue = m_settings.smoothConstant;

            std::cout << "Kalkulacja ES...." << std::endl;

            resultVector.push_back(initVector[0]);
            resultVector.push_back(initVector[0]);

            for (int i = 2; i < initVector.size(); i++) {
                float forecast = (weightValue * initVector[i - 1]) + ((1 - weightValue) * resultVector[i - 1]);
                resultVector.push_back(forecast);
            }

            std::cout << "Obliczenia ES sie skonczyly" << std::endl;
            return resultVector;
        }

    private:
        Settings m_settings;
    };
}
