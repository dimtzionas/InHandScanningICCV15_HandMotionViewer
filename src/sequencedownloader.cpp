#include "sequencedownloader.h"
#include "ui_sequencedownloader.h"

SequenceDownloader::SequenceDownloader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SequenceDownloader)
{
    ui->setupUi(this);
}

SequenceDownloader::~SequenceDownloader()
{
    delete ui;
}

void SequenceDownloader::on_loadSequenceButton_clicked()
{
    QUrl sequence;

    if      (ui->sequenceRadio_01->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/In-Hand-Scanning/Dataset/Frames___All_Files___No_Detections/001.zip");
    else if (ui->sequenceRadio_02->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/In-Hand-Scanning/Dataset/Frames___All_Files___No_Detections/002.zip");
    else if (ui->sequenceRadio_03->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/In-Hand-Scanning/Dataset/Frames___All_Files___No_Detections/003.zip");
    else if (ui->sequenceRadio_04->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/In-Hand-Scanning/Dataset/Frames___All_Files___No_Detections/004.zip");
    QDesktopServices::openUrl (sequence );
    emit closeWindow( true );
}

void SequenceDownloader::closeEvent(QCloseEvent *){
    emit closeWindow(false);
}
