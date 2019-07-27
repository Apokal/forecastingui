#include "qmethodsresultswidget.h"
#include "ui_qmethodsresults.h"

#include <iostream>
#include <QtCharts>

QMethodsResultsDialog::QMethodsResultsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QMethodsResults)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

QMethodsResultsDialog::~QMethodsResultsDialog()
{
    delete ui;
}

void QMethodsResultsDialog::set_method_results(const std::map<std::string, std::vector<float>>& method_results)
{
    m_method_results = method_results;
    build_chart();
}

void QMethodsResultsDialog::build_chart()
{
    QChart *chart = new QChart();

    std::cout << "-------------------" << std::endl;
    std::cout << "Building chart:" << std::endl;

    for(const auto& r : m_method_results )
    {
        std::cout << r.first << ": " << std::endl;
        QSplineSeries  *series = new QSplineSeries ();
        series->setName(r.first.c_str());

        for ( size_t i = 0; i < r.second.size(); ++i)
        {
            //std::cout << i << ": " << r.second[i] << std::endl;
            series->append(static_cast<qreal>(i), static_cast<qreal>(r.second[i]));
        }

        chart->addSeries(series);
    }

    chart->createDefaultAxes();
    chart->setTitle("Simple line chart example");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->verticalLayout->addWidget(chartView);
}
