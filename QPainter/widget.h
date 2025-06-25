#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QImage buffer;

public:
    void paintEvent(QPaintEvent* event) override;
};
