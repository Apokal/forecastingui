#include "modellogic.h"

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

#include "inputgenerator.h"
#include "file.h"
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

    void QModelLogic::AddQuantitativeMethod(QuantitativeMethodPtr pmethod)
    {
        m_quant_methods.push_back(std::move(pmethod));
    }

    void QModelLogic::Run(const QRunSettings& settings)
    {
        QInputGenerator gen;
        std::vector<float> initVector = gen.generate(settings.inputsize);

        auto currdir = QDir::currentPath();
        auto filepath = currdir.toStdString() + "/Pliki/initVector.txt";

        write_to_file(filepath, initVector);

        m_quant_meths_exec_time.clear();
        for (const auto& p : m_quant_methods)
        {
            auto exec_time = ExecuteMethod(p.get(), initVector);
            m_quant_meths_exec_time[p->name()] = exec_time;
        }
    }

    QuantativeMethodsExecutionTime QModelLogic::execution_time_results()
    {
        return m_quant_meths_exec_time;
    }

    std::chrono::milliseconds QModelLogic::ExecuteMethod(Quantitative::QQuantitativeMethodBase* pmethod, std::vector<float> initVector)
    {
        std::vector<float> resultVector;

        using Clock = std::chrono::high_resolution_clock;
        auto t_start = Clock::now();

        resultVector = pmethod->run(initVector);

        auto currdir = QDir::currentPath();
        auto filepath = currdir.toStdString() + "/Pliki/" + pmethod->name() + ".txt";
        write_to_file(filepath, resultVector);

        auto t_end = Clock::now();

        return std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start);
    }
}
