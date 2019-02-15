#include "qwmasettingswidget.h"
#include "ui_qwmasettingswidget.h"

QWMASettingsWidget::QWMASettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QWMASettingsWidget)
{
    ui->setupUi(this);
}

QWMASettingsWidget::~QWMASettingsWidget()
{
    delete ui;
}
