#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

#include "Logic/modellogic.h"
#include "Logic/SMA.h"
#include "Logic/WMA.h"
#include "Logic/ES.h"
#include "Logic/LTP.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_logic = std::make_unique<Logic::QModelLogic>();

    QObject::connect(ui->customFile_RadBtn, &QRadioButton::toggled, ui->genInputSize_SpBox, &QLineEdit::setDisabled);
    QObject::connect(ui->customFile_RadBtn, &QRadioButton::toggled, ui->outputFilePath_LnEdit, &QLineEdit::setDisabled);
    QObject::connect(ui->customFile_RadBtn, &QRadioButton::toggled, ui->outputFilePath_Btn, &QPushButton::setDisabled);
    QObject::connect(ui->customFile_RadBtn, &QRadioButton::toggled, ui->numberSettings_GrBox, &QWidget::setDisabled);

    QObject::connect(ui->randomGenerator_RadBtn, &QRadioButton::toggled, ui->customFilePath_LnEdit, &QLineEdit::setDisabled);
    QObject::connect(ui->randomGenerator_RadBtn, &QRadioButton::toggled, ui->customFilePath_Btn, &QPushButton::setDisabled);
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

    Quantitative::QSMAQuntitativeMethod::Settings settings;
    logic->AddQuantitativeMethod(std::make_unique<Quantitative::QSMAQuntitativeMethod>(settings));
}

void MainWindow::ParseWMASettingsAndUpdateLogic(const QWidget* settingswidget, std::unique_ptr<Logic::QModelLogic>& logic)
{
    const QWMASettingsWidget* w = qobject_cast<const QWMASettingsWidget*>(settingswidget);
    w->x();

    Quantitative::QWMAQuntitativeMethod::Settings settings;
    settings.weights = { 0.2f, 0.3f, 0.5f };
    logic->AddQuantitativeMethod(std::make_unique<Quantitative::QWMAQuntitativeMethod>(settings));
}

void MainWindow::ParseESSettingsAndUpdateLogic(const QWidget* settingswidget, std::unique_ptr<Logic::QModelLogic>& logic)
{
    const QESSettingsWidget* w = qobject_cast<const QESSettingsWidget*>(settingswidget);
    w->x();

    Quantitative::QESQuntitativeMethod::Settings settings;
    logic->AddQuantitativeMethod(std::make_unique<Quantitative::QESQuntitativeMethod>(settings));
}

void MainWindow::ParseLTPSettingsAndUpdateLogic(const QWidget* settingswidget, std::unique_ptr<Logic::QModelLogic>& logic)
{
    const QLTPSettingsWidget* w = qobject_cast<const QLTPSettingsWidget*>(settingswidget);
    w->x();

    Quantitative::QLTPQuntitativeMethod::Settings settings;
    logic->AddQuantitativeMethod(std::make_unique<Quantitative::QLTPQuntitativeMethod>(settings));
}

Logic::QRunSettings MainWindow::ParseGeneralSettingsAndUpdateLogic(const QWidget* num_setts_widget)
{
    const auto* w = qobject_cast<const QNumberSettingsWidget*>(num_setts_widget);
    w->x();

    Logic::QRunSettings setts;
    setts.inputsize = static_cast<size_t>(ui->genInputSize_SpBox->value());
    return setts;
}

void MainWindow::on_run_Btn_clicked()
{
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
