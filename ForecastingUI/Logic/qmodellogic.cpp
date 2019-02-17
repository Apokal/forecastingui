#include "qmodellogic.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <iterator>
#include <functional>
#include <map>
#include <string>
#include <sstream>

#include <QDir>

#include "vectorGenerator.h"
#include "fileGenerator.h"
#include "SMA.h"
#include "WMA.h"
#include "ES.h"
#include "LTP.h"

namespace Logic
{
    QModelLogic::QModelLogic()
    {
        srand(time(0));
    }

    void QModelLogic::Run()
    {
        std::vector<float> initVector = vectorGenerator(100000);

        auto currdir = QDir::currentPath();
        auto filepath = currdir.toStdString() + "/Pliki/initVector.txt";

        fileGenerator(filepath, initVector);

        std::map<std::string, std::function<vector<float>(vector<float>)>> forecastMap =
        {
//            { "SMA", SMA},
//            { "WMA", WMA}, std::vector<float> weights = { 0.2f, 0.3f, 0.5f };
//            { "ES", ES},
//            { "LTP", LTP}
        };

        m_quant_meths_exec_time.clear();
        for (const auto& p : forecastMap)
        {
            //auto exec_time = RunEntry(initVector, forecastMap, p.first);
            auto exec_time = std::chrono::milliseconds(0);
            m_quant_meths_exec_time[p.first] = exec_time;
        }
    }

    QuantativeMethodsExecutionTime QModelLogic::execution_time_resutls()
    {
        return m_quant_meths_exec_time;
    }

//    std::chrono::milliseconds QModelLogic::RunEntry(std::vector<float> initVector, std::map<std::string, >> forecastMap,
//                                                    std::string forecastType)
//    {
//        std::vector<float> resultVector;

//        using Clock = std::chrono::high_resolution_clock;
//        auto t_start = Clock::now();

//        resultVector = forecastMap[forecastType](initVector);

//        auto currdir = QDir::currentPath();
//        auto filepath = currdir.toStdString() + "/Pliki/" + forecastType + ".txt";
//        fileGenerator(filepath, resultVector);

//        auto t_end = Clock::now();

//        return std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start);
//    }
}
