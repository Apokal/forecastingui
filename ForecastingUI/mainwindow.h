#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

namespace Logic {
    class QModelLogic;
    struct QRunSettings;
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
    Logic::QRunSettings ParseGeneralSettingsAndUpdateLogic(const QWidget* num_setts_widget);

private slots:
    void on_customFilePath_Btn_clicked();

    void on_outputFilePath_Btn_clicked();

    void on_run_Btn_clicked();

    void on_execTimeResults_PushBtn_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<Logic::QModelLogic> m_logic;

    QDialog* m_exec_times_results_dlg = nullptr;
};

#endif // MAINWINDOW_H
