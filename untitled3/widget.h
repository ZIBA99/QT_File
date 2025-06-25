#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QPoint>
#include <QPen>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;//그림판 사이즈 갱신

private:
    QImage image;         // 그림을 저장하는 이미지 버퍼
    QPoint prevPos;       // 이전 마우스 위치
    bool drawing;         // 그리기 상태 플래그
    QPen pen;             // 펜 설정
};

#endif // WIDGET_H
