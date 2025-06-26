#include "Graphics.h"
#include "qwidget.h"

Graphics::GraphicsViewExample(QWidget *parent)
    : QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);

    // 사각형 아이템 추가 및 스타일 설정
    QGraphicsRectItem *rect = scene->addRect(-10, -10, 120, 50);
    rect->setPen(QPen(Qt::red));
    rect->setBrush(QBrush(Qt::yellow));

    // 텍스트 아이템 추가
    QGraphicsTextItem *textItem = new QGraphicsTextItem("Hello World!");
    scene->addItem(textItem);

    // Scene을 View에 설정
    this->setScene(scene);
}
