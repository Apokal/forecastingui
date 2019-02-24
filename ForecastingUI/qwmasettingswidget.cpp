#include "qwmasettingswidget.h"
#include "ui_qwmasettingswidget.h"

#include <QMessageBox>

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

bool QWMASettingsWidget::useMethod() const
{
 return ui->useMethod_ChkBox->isChecked();
}

std::vector<float> QWMASettingsWidget::weights() const
{
    std::vector<float> weights;
    auto str = ui->weightScheme_LnEdit->text();
    for ( const auto& token : str.split(';', QString::SplitBehavior::SkipEmptyParts))
    {
        bool ok = false;
        float num = token.toFloat(&ok);
        if (!ok)
        {
            QMessageBox msgBox;
            msgBox.setText("Could not parse the weights string");
            msgBox.setInformativeText("Error in string: " + str);
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.exec();

            exit(0);
        }
        else
        {
            weights.push_back(num);
        }
    }

    return weights;
}
