#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

namespace Logic {
    class QModelLogic;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void ParseSMASettingsAndUpdateLogic(const QWidget* settingswidget, std::unique_ptr<Logic::QModelLogic>& logic);
    void ParseWMASettingsAndUpdateLogic(const QWidget* settingswidget, std::unique_ptr<Logic::QModelLogic>& logic);
    void ParseESSettingsAndUpdateLogic(const QWidget* settingswidget, std::unique_ptr<Logic::QModelLogic>& logic);
    void ParseLTPSettingsAndUpdateLogic(const QWidget* settingswidget, std::unique_ptr<Logic::QModelLogic>& logic);

private slots:
    void on_customFilePath_Btn_clicked();

    void on_outputFilePath_Btn_clicked();

    void on_run_Btn_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<Logic::QModelLogic> m_logic;
};

#endif // MAINWINDOW_H
