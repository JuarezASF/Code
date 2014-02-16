#ifndef WIDGET_H
#define WIDGET_H

#include <QLabel>
#include <QMenu>

class Widget : public QLabel
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:

    bool selectionStarted;
    QRect selectionRect;
    QMenu contextMenu;

private slots:
    void saveSlot();

};

#endif // WIDGET_H
