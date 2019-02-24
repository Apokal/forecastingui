#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

#include "Logic/modellogic.h"
#include "Logic/SMA.h"
#include "Logic/WMA.h"
#include "Logic/ES.h"
#include "Logic/LTP.h"

#include "qexecutiontimeresults.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_logic = std::make_unique<Logic::QModelLogic>();

    QObject::connect(ui->customFile_RadBtn, &QRadioButton::toggled, ui->genInputSize_SpBox, &QLineEdit::setDisabled);
    QObject::connect(ui->customFile_RadBtn, &QRadioButton::toggled, ui->numberSettings_GrBox, &QWidget::setDisabled);

    QObject::connect(ui->randomGenerator_RadBtn, &QRadioButton::toggled, ui->customFilePath_LnEdit, &QLineEdit::setDisabled);
    QObject::connect(ui->randomGenerator_RadBtn, &QRadioButton::toggled, ui->customFilePath_Btn, &QPushButton::setDisabled);

    // setting up default dir
    QString output_dir = QCoreApplication::applicationDirPath() + "/Pliki";
    ui->outputFilePath_LnEdit->setText(output_dir);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_customFilePath_Btn_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setNameFilter(tr("Text files (*.txt)"));
    dialog.setViewMode(QFileDialog::Detail);
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();

    if (!fileNames.isEmpty())
    {
        ui->customFilePath_LnEdit->setText(fileNames.first());
    }
}

void MainWindow::on_outputFilePath_Btn_clicked()
{
    QFileDialog dialog(this);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setNameFilter(tr("Text files (*.txt)"));
    dialog.setViewMode(QFileDialog::Detail);
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();

    if (!fileNames.isEmpty())
    {
        ui->outputFilePath_LnEdit->setText(fileNames.first());
    }
}

void MainWindow::ParseSMASettingsAndUpdateLogic(const QWidget* settingswidget, std::unique_ptr<Logic::QModelLogic>& logic)
{
    const QSMASettingsWidget* w = qobject_cast<const QSMASettingsWidget*>(settingswidget);
    w->x();

    if (w->useMethod())
    {
        Quantitative::QSMAQuntitativeMethod::Settings settings;
        settings.period = static_cast<unsigned int>(w->periodValue());
        logic->AddQuantitativeMethod(std::make_unique<Quantitative::QSMAQuntitativeMethod>(settings));
    }
}

void MainWindow::ParseWMASettingsAndUpdateLogic(const QWidget* settingswidget, std::unique_ptr<Logic::QModelLogic>& logic)
{
    const QWMASettingsWidget* w = qobject_cast<const QWMASettingsWidget*>(settingswidget);

    if (w->useMethod())
    {
        Quantitative::QWMAQuntitativeMethod::Settings settings;
        settings.weights = w->weights();
        logic->AddQuantitativeMethod(std::make_unique<Quantitative::QWMAQuntitativeMethod>(settings));
    }
}

void MainWindow::ParseESSettingsAndUpdateLogic(const QWidget* settingswidget, std::unique_ptr<Logic::QModelLogic>& logic)
{
    const QESSettingsWidget* w = qobject_cast<const QESSettingsWidget*>(settingswidget);

    if (w->useMethod())
    {
        Quantitative::QESQuntitativeMethod::Settings settings;
        settings.smoothConstant = static_cast<float>(w->smoothConstant());
        logic->AddQuantitativeMethod(std::make_unique<Quantitative::QESQuntitativeMethod>(settings));
    }
}

void MainWindow::ParseLTPSettingsAndUpdateLogic(const QWidget* settingswidget, std::unique_ptr<Logic::QModelLogic>& logic)
{
    const QLTPSettingsWidget* w = qobject_cast<const QLTPSettingsWidget*>(settingswidget);

    if (w->useMethod())
    {
        Quantitative::QLTPQuntitativeMethod::Settings settings;
        settings.period = static_cast<unsigned int>(w->period());
        logic->AddQuantitativeMethod(std::make_unique<Quantitative::QLTPQuntitativeMethod>(settings));
    }
}

Logic::QRunSettings MainWindow::ParseGeneralSettingsAndUpdateLogic(const QWidget* num_setts_widget)
{
    const auto* w = qobject_cast<const QNumberSettingsWidget*>(num_setts_widget);
    w->x();

    Logic::QRunSettings setts;
    setts.inputsize = static_cast<size_t>(ui->genInputSize_SpBox->value());
    setts.output_dir = ui->outputFilePath_LnEdit->text().toStdString();

    setts.precision = static_cast<unsigned int>(ui->numberSettings_Wdgt->precision());
    setts.min_value = ui->numberSettings_Wdgt->min_value();
    setts.max_value = ui->numberSettings_Wdgt->max_value();

    return setts;
}

void MainWindow::on_run_Btn_clicked()
{
    m_logic->ClearMethods();
    ParseSMASettingsAndUpdateLogic(ui->PageSMA, m_logic);
    ParseWMASettingsAndUpdateLogic(ui->PageWMA, m_logic);
    ParseESSettingsAndUpdateLogic(ui->PageES, m_logic);
    ParseLTPSettingsAndUpdateLogic(ui->PageLTP, m_logic);
    auto runsetts = ParseGeneralSettingsAndUpdateLogic(ui->numberSettings_Wdgt);

    m_logic->Run(runsetts);

    auto exec_time = m_logic->execution_time_results();

    std::string msg = "Czas wykonywania (ms): \n";
    for ( const auto& p : exec_time )
    {
        msg += p.first + ": " + std::to_string(p.second.count()) + "\n";
    }

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText(msg.c_str());
    msgBox.exec();
}

void MainWindow::on_execTimeResults_PushBtn_clicked()
{
    if ( !m_exec_times_results_dlg )
    {
        m_exec_times_results_dlg = new QExecutionTimeResultsDialog(this);
    }

    QExecutionTimeResultsDialog* dlg = qobject_cast<QExecutionTimeResultsDialog*>(m_exec_times_results_dlg);
    auto exec_time = m_logic->execution_time_results();
    dlg->set_exec_time_results(exec_time);

    dlg->show();
    dlg->raise();
    dlg->activateWindow();
}
