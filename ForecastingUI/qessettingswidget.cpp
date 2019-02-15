#include "qessettingswidget.h"
#include "ui_qessettingswidget.h"

QESSettingsWidget::QESSettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QESSettingsWidget)
{
    ui->setupUi(this);
}

QESSettingsWidget::~QESSettingsWidget()
{
    delete ui;
}
