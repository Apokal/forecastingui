#ifndef QMODELLOGIC_H
#define QMODELLOGIC_H

#include <map>
#include <string>
#include <chrono>
#include <vector>

namespace Quantitative {
    class QQuantitativeMethodBase;
}

namespace Logic
{
    using QuantativeMethodsExecutionTime = std::map<std::string, std::chrono::milliseconds>;
    using QuantitativeMethodPtr = std::unique_ptr<Quantitative::QQuantitativeMethodBase>;

    struct QRunSettings
    {
        bool use_custom_file = false;
        std::string custom_file_path;

        size_t inputsize = 0;

        float min_value = 0.0f;
        float max_value = 0.0f;
        unsigned int precision = 0;

        std::string output_dir;
    };

    class QModelLogic
    {
    public:
        QModelLogic();

        void AddQuantitativeMethod(QuantitativeMethodPtr pmethod);
        void Run(const QRunSettings& settings);
        QuantativeMethodsExecutionTime execution_time_results();
        void ClearMethods();

    private:
        std::chrono::milliseconds ExecuteMethod(Quantitative::QQuantitativeMethodBase* pmethod, std::vector<float> initVector, const std::string &output_dir);

        std::vector<QuantitativeMethodPtr>  m_quant_methods;
        QuantativeMethodsExecutionTime      m_quant_meths_exec_time;
    };

}

#endif // QMODELLOGIC_H
