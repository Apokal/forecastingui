#include "qexecutiontimeresultswidget.h"
#include "ui_qexecutiontimeresults.h"

QExecutionTimeResultsDialog::QExecutionTimeResultsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QExecutionTimeResults)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

QExecutionTimeResultsDialog::~QExecutionTimeResultsDialog()
{
    delete ui;
}


void QExecutionTimeResultsDialog::build_chart()
{
    QBarSeries *series = new QBarSeries();

    long long max_exec_time = 0;
    for ( const auto& elem : m_exec_time_results )
    {
        QBarSet *set = new QBarSet(elem.first.c_str());
        *set << elem.second.count();
        series->append(set);

        if (elem.second.count() > max_exec_time )
        {
            max_exec_time = elem.second.count();
        }
    }

    max_exec_time += max_exec_time / 20;

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Wykres czasów wykonywania");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Quantitative methods" ;
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Czas wykonywania (ms)");
    axisY->setRange(0, max_exec_time);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->verticalLayout->addWidget(chartView);
}
