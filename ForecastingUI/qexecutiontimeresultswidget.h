#ifndef QEXECUTIONTIMERESULTS_H
#define QEXECUTIONTIMERESULTS_H

#include <QDialog>
#include <QtCharts>

using namespace QtCharts;

namespace Ui {
class QExecutionTimeResults;
}

class QExecutionTimeResultsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QExecutionTimeResultsDialog(QWidget *parent = nullptr);
    ~QExecutionTimeResultsDialog();

    void set_exec_time_results(const std::map<std::string, std::chrono::milliseconds>& results)
    {
        m_exec_time_results = results;
        build_chart();
    }

private:
    void build_chart();

    Ui::QExecutionTimeResults *ui;
    std::map<std::string, std::chrono::milliseconds> m_exec_time_results;
};

#endif // QEXECUTIONTIMERESULTS_H
