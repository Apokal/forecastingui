#include "qnumbersettingswidget.h"
#include "ui_qnumbersettingswidget.h"

QNumberSettingsWidget::QNumberSettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QNumberSettingsWidget)
{
    ui->setupUi(this);
}

QNumberSettingsWidget::~QNumberSettingsWidget()
{
    delete ui;
}
