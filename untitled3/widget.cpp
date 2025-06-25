#include "widget.h"
#include <QPainter>
#include <QMouseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent), drawing(false)
{
    // 위젯 크기 설정 및 이미지 초기화
    resize(400, 400);
    image = QImage(size(), QImage::Format_ARGB32_Premultiplied);
    image.fill(Qt::white);

    // 펜 설정 (색상, 두께, 끝 모양)
    pen.setColor(Qt::black);
    pen.setWidth(3);
    pen.setCapStyle(Qt::RoundCap);
}

Widget::~Widget()
{
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // 저장된 이미지를 화면에 그리기
    painter.drawImage(0, 0, image);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        prevPos = event->pos();
        drawing = true;
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (drawing && (event->buttons() & Qt::LeftButton)) {
        QPoint newPos = event->pos();

        QPainter painter(&image);
        painter.setPen(pen);
        painter.drawLine(prevPos, newPos);
        painter.end();

        // 변경된 영역 계산 (선이 그려진 영역 + 여유 공간)
        int x1, x2, y1, y2;
        if (prevPos.x() < newPos.x()) {
            x1 = prevPos.x(); x2 = newPos.x();
        } else {
            x1 = newPos.x(); x2 = prevPos.x();
        }
        if (prevPos.y() < newPos.y()) {
            y1 = prevPos.y(); y2 = newPos.y();
        } else {
            y1 = newPos.y(); y2 = prevPos.y();
        }

        QRect updateRect(x1, y1, x2 - x1, y2 - y1);
        int RADIUS = pen.width() / 2 + 2; // 여유 공간

        updateRect = updateRect.adjusted(-RADIUS, -RADIUS, RADIUS, RADIUS);
        update(updateRect);

        prevPos = newPos;
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && drawing) {
        QPainter painter(&image);
        painter.setPen(pen);
        painter.drawPoint(prevPos);
        painter.end();

        drawing = false;
        update();
    }
}

void Widget::resizeEvent(QResizeEvent *event)
{
    if (width() > image.width() || height() > image.height()) {
        // 새 이미지 크기: 현재 위젯 크기
        int newWidth = qMax(width(), image.width());
        int newHeight = qMax(height(), image.height());

        // 새 이미지 생성 (기존 이미지보다 크거나 같음)
        QImage newImage(newWidth, newHeight, QImage::Format_ARGB32_Premultiplied);
        newImage.fill(Qt::white);  // 배경 흰색으로 초기화

        // 기존 이미지 내용을 새 이미지로 복사
        QPainter painter(&newImage);
        painter.drawImage(0, 0, image);
        painter.end();

        image = newImage;  // 기존 이미지 교체

        update();  // 화면 갱신
    }

    QWidget::resizeEvent(event);  // 기본 처리 호출
}
