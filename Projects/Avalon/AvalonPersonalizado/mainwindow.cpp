#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Avalon Customizer");

    this->customizador = new AvalonCustomizer();

    this->ui->comboBox->addItem("Moldura");
    this->ui->comboBox->addItem("Verso");
    this->ui->comboBox->addItem("Plano de Fundo");
    this->ui->comboBox->addItem("Personagem");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete customizador;
}

void MainWindow::on_nomeLineEdit_returnPressed()
{
    QString arg1 = ui->nomeLineEdit->text();
    customizador->setNome(arg1.toStdString());

    update();
}

void MainWindow::on_botaoCarregar_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open File", "../AvalonPersonalizado/images/", "Files (*.*)");
    if(fileName == NULL)
        cout << "Entrada cancelada" <<endl;
    else{
        Mat novo = imread(fileName.toStdString().c_str());
        QLabel *alvo;
        switch (ui->comboBox->currentIndex()){
        case 0:
            alvo = ui->moldura;
            customizador->setMoldura(novo);
            break;
        case 1:
            alvo = ui->verso;
            customizador->setVerso(novo);
            break;
        case 2:
            alvo = ui->background;
            customizador->setPlano(novo);
            break;
        case 3:
            alvo = ui->personagem;
            customizador->setPersonagem(novo);
            break;
        }

        Cv2QtImage::setLabelImage(alvo, novo);
        update();

    }
}
void MainWindow::update(){
    Mat card = customizador->getCard();
    if(!card.empty())
        Cv2QtImage::setLabelImage(ui->resultado, card);
}
