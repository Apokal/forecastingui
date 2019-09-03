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

    void QModelLogic::Run(QRunSettings settings)
    {
        std::vector<float> initVector;

        QDir output_dir(settings.output_dir.c_str());
        if (!output_dir.exists())
        {
            output_dir.mkdir(settings.output_dir.c_str());
        }

        if ( !settings.use_custom_file )
        {
            QInputGenerator gen;
            settings.init_vector = gen.generate(settings.inputsize, settings.min_value, settings.max_value, settings.precision);
            auto filepath = settings.output_dir + "/initVector.txt";
            write_to_file(filepath, initVector);
        }

        m_quant_meths_results.clear();
        for (const auto& p : m_quant_methods)
        {
            auto result = ExecuteMethod(p.get(), settings.init_vector, settings.output_dir, settings.historical_data_range, settings.forecast_range);
            m_quant_meths_results[p->name()] = result;
        }
    }

    const QQuantativeMethodResults& QModelLogic::method_results()
    {
        return m_quant_meths_results;
    }

    void QModelLogic::ClearMethods()
    {
        m_quant_methods.clear();
    }

    QQuantativeMethodResult QModelLogic::ExecuteMethod(Quantitative::QQuantitativeMethodBase* pmethod, std::vector<float> initVector, const std::string& output_dir, size_t history_range, size_t forecast_range)
    {
        std::vector<float> output_vector;

        using Clock = std::chrono::high_resolution_clock;
        auto t_start = Clock::now();

        output_vector = pmethod->run(initVector, history_range, forecast_range);

        auto currdir = QDir::currentPath();
        auto filepath = output_dir + "/" + pmethod->name() + ".txt";
        write_to_file(filepath, output_vector);

        auto t_end = Clock::now();

        return { std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start), output_vector };
    }
}
