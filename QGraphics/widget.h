#ifndef GRAPHICSVIEWEXAMPLE_H
#define GRAPHICSVIEWEXAMPLE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

class GraphicsViewExample : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GraphicsViewExample(QWidget *parent = nullptr);

private:
    QGraphicsScene *scene;
};

#endif // GRAPHICSVIEWEXAMPLE_H
