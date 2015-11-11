#include "sequenceselector.h"
#include "ui_sequenceselector.h"

SequenceSelector::SequenceSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SequenceSelector)
{
    ui->setupUi(this);
}

SequenceSelector::~SequenceSelector()
{
    delete ui;
}

void SequenceSelector::on_loadSequenceButton_clicked()
{
    this->hide();
    QString sequence = "";
    if      (ui->sequenceRadio_01->isChecked())     sequence = QString("001");
    else if (ui->sequenceRadio_02->isChecked())     sequence = QString("002");
    else if (ui->sequenceRadio_03->isChecked())     sequence = QString("003");
    else if (ui->sequenceRadio_04->isChecked())     sequence = QString("004");
    emit setSequence(sequence);
}

void SequenceSelector::closeEvent(QCloseEvent *){
    emit closeWindow( false );
}
