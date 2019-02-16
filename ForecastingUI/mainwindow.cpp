#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

#include "Logic/qmodellogic.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    logic = std::make_unique<Logic::QModelLogic>();

    QObject::connect(ui->customFile_RadBtn, &QRadioButton::toggled, ui->genFileSize_LnEdit, &QLineEdit::setDisabled);
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

void MainWindow::on_run_Btn_clicked()
{
    logic->Run();

    auto exec_time = logic->last_exec_time();

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
