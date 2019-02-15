#include "qltpsettingswidget.h"
#include "ui_qltpsettingswidget.h"

QLTPSettingsWidget::QLTPSettingsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QLTPSettingsWidget)
{
    ui->setupUi(this);
}

QLTPSettingsWidget::~QLTPSettingsWidget()
{
    delete ui;
}
