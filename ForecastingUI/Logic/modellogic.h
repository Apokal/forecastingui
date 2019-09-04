#ifndef QMODELLOGIC_H
#define QMODELLOGIC_H

#include <map>
#include <string>
#include <chrono>
#include <vector>
#include <memory>

namespace Quantitative {
    class QQuantitativeMethodBase;
}

namespace Logic
{
    struct QQuantativeMethodResult
    {
        std::chrono::milliseconds exec_time;
        std::vector<float> output;
    };

    using QQuantativeMethodResults = std::map<std::string, QQuantativeMethodResult>;
    using QuantitativeMethodPtr = std::unique_ptr<Quantitative::QQuantitativeMethodBase>;

    struct QRunSettings
    {
        bool use_custom_file = false;
        std::string custom_file_path;
        size_t inputsize = 0;

        std::vector<float> init_vector;

        float min_value = 0.0f;
        float max_value = 0.0f;
        unsigned int precision = 0;

        size_t historical_data_range = 0;
        size_t forecast_range = 0;
        std::string output_dir;
    };

    class QModelLogic
    {
    public:
        QModelLogic();

        void AddQuantitativeMethod(QuantitativeMethodPtr pmethod);
        void Run(QRunSettings settings);
        const QQuantativeMethodResults &method_results();
        void ClearMethods();

    private:
        QQuantativeMethodResult ExecuteMethod(Quantitative::QQuantitativeMethodBase* pmethod, std::vector<float> initVector, const std::string &output_dir, size_t history_range, size_t forecast_range);

        std::vector<QuantitativeMethodPtr>  m_quant_methods;
        QQuantativeMethodResults            m_quant_meths_results;
    };

}

#endif // QMODELLOGIC_H
