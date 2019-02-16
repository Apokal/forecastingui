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
            { "SMA", SMA},
            { "WMA", WMA},
            { "ES", ES},
            { "LTP", LTP}
        };

        m_last_exec_time.clear();
        for (const auto& p : forecastMap)
        {
            auto exec_time = RunEntry(initVector, forecastMap, p.first);
            m_last_exec_time[p.first] = exec_time;
        }

//        auto sma = RunEntry(initVector, forecastMap, "SMA");
//        auto wma = RunEntry(initVector, forecastMap, "WMA");
//        auto es = RunEntry(initVector, forecastMap, "ES");
//        auto ltp = RunEntry(initVector, forecastMap, "LTP");
    }

    std::map<std::string, std::chrono::milliseconds> QModelLogic::last_exec_time()
    {
        return m_last_exec_time;
    }

    std::chrono::milliseconds QModelLogic::RunEntry(std::vector<float> initVector, std::map<std::string, std::function<std::vector<float>(std::vector<float>)>> forecastMap,
                                                    std::string forecastType)
    {
        typedef std::chrono::high_resolution_clock Clock;
        std::vector<float> resultVector;

        using Clock = std::chrono::high_resolution_clock;
        auto t_start = Clock::now();

        resultVector = forecastMap[forecastType](initVector);

        auto currdir = QDir::currentPath();
        auto filepath = currdir.toStdString() + "/Pliki/" + forecastType + ".txt";
        fileGenerator(filepath, resultVector);

        auto t_end = Clock::now();

        return std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start);
    }
}
