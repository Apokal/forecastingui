#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_customFilePath_Btn_clicked();

    void on_outputFilePath_Btn_clicked();

    void on_run_Btn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
