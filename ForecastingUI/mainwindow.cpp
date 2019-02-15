#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    ui->customFilePath_LnEdit->setText(fileNames.first());
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

    ui->outputFilePath_LnEdit->setText(fileNames.first());
}

void MainWindow::on_run_Btn_clicked()
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("Бомж ещё не готово. Ты чё такой резкий!? Пойди отдохни!");
    msgBox.setInformativeText("Отдохнуть, пока братела порешает?");
    msgBox.exec();
}
