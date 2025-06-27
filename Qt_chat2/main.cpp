#include <QApplication>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>

#include "serverwidget.h"
#include "clientwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 사용자에게 모드를 선택하게 할 대화상자 생성
    QDialog modeDialog;
    modeDialog.setWindowTitle("모드 선택");

    QPushButton *serverButton = new QPushButton("서버 시작", &modeDialog);
    QPushButton *clientButton = new QPushButton("클라이언트 시작", &modeDialog);

    QVBoxLayout *layout = new QVBoxLayout(&modeDialog);
    layout->addWidget(serverButton);
    layout->addWidget(clientButton);
    modeDialog.setLayout(layout);

    ServerWidget *serverWidget = nullptr;
    ClientWidget *clientWidget = nullptr;

    // 서버 버튼을 누르면 서버 위젯을 생성하고 대화상자를 닫음
    QObject::connect(serverButton, &QPushButton::clicked, [&]() {
        serverWidget = new ServerWidget();
        serverWidget->show();
        modeDialog.accept();
    });

    // 클라이언트 버튼을 누르면 클라이언트 위젯을 생성하고 대화상자를 닫음
    QObject::connect(clientButton, &QPushButton::clicked, [&]() {
        clientWidget = new ClientWidget();
        clientWidget->show();
        modeDialog.accept();
    });

    // 대화상자를 실행. 사용자가 버튼을 누르기 전까지 여기서 멈춤.
    modeDialog.exec();

    // 메인 이벤트 루프를 실행. (선택된 위젯이 계속 동작하도록 함)
    return a.exec();
}
