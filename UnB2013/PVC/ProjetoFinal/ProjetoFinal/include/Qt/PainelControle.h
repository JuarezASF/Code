#ifndef PAINELCONTROLE_H
#define PAINELCONTROLE_H

#include <QWidget>

namespace Ui {
class PainelControle;
}

class PainelControle : public QWidget
{
    Q_OBJECT

public:
    explicit PainelControle(QWidget *parent = 0);
    ~PainelControle();

private:
    Ui::PainelControle *ui;
};

#endif // PAINELCONTROLE_H
