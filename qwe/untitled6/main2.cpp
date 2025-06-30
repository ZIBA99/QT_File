/*
#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;
public:
    // 생성자: 시, 분, 초를 받아 초기화
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    // 시간을 초로 변환하는 형 변환 연산자
    operator int() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    // 시간을 출력하는 함수
    void ShowTime() const {
        cout << hours << " hours " << minutes << " minutes " << seconds << " seconds" << endl;
    }
};

int main() {
    Time t1(2, 30, 45);  // 2시간 30분 45초

    t1.ShowTime();  // 시간 출력

    // Time 객체를 int로 형 변환하여 초 단위로 출력
    int totalSeconds = t1;  // Time 객체를 int로 변환
    cout << "Total time in seconds: " << totalSeconds << " seconds" << endl;

    return 0;
}*/

/*
#include <iostream>
using namespace std;

class Cox{
private:
    int age;
public:
    Cox(const Cox& source):age(source.age){
        cout << "Cox::Cox " << endl;
    }
    Cox(int age):age(age){
        cout << "Cox::Cox(age) " << endl;
    }
    Cox(){
        cout << "Cox::Cox() " << endl;
    }
    void introduce();
    ~Cox(){
        cout << "Cox::~Cox() " << endl;
    }
};

int main(void){
    Cox cox1(32);
    Cox cox2(50);
    cox1.introduce();
    cox2.introduce();
    cout << "===================================" << endl;
    cox1 = cox2;
    cout << "====================================" << endl;
    cox1.introduce();
    cox2.introduce();

    return 0;
}*/

//수정 코드
/*
#include <iostream>
using namespace std;

// Cox 클래스 정의
class Cox {
private:
    int age;  // 개인 멤버 변수: 나이

public:
    // 복사 생성자: 다른 Cox 객체를 복사하여 생성할 때 호출
    Cox(const Cox& source) : age(source.age) {
        cout << "Cox::Cox " << endl;
    }

    // 매개변수가 있는 생성자: 나이를 인자로 받아 초기화
    Cox(int age) : age(age) {
        cout << "Cox::Cox(age) " << endl;
    }

    // 기본 생성자
    Cox() {
        cout << "Cox::Cox() " << endl;
    }

    // 멤버 함수 선언
    void introduce();

    // 소멸자: 객체가 소멸될 때 호출
    ~Cox() {
        cout << "Cox::~Cox() " << endl;
    }
};

// introduce 함수 정의: age 값을 출력
void Cox::introduce() {
    cout << "My age is " << age << endl;
}

int main(void) {
    // Cox 객체 생성 및 생성자 호출
    Cox cox1(32);  // Cox::Cox(age) 출력
    Cox cox2(50);  // Cox::Cox(age) 출력

    // 각 객체의 상태 출력
    cox1.introduce();  // My age is 32
    cox2.introduce();  // My age is 50

    cout << "===================================" << endl;

    // 복사 대입 연산자 사용 (기본 제공됨, 복사 생성자 아님)
    cox1 = cox2;

    cout << "====================================" << endl;

    // 대입 이후의 상태 확인
    cox1.introduce();  // My age is 50
    cox2.introduce();  // My age is 50

    // main 종료 시 소멸자 자동 호출
    return 0;
}*/

/*
#include <iostream>
using namespace std;

class Number{
private:
    int num;
public:
    Number(int n=0):num(n){
        cout << "Number("<<n<<")"<<endl;
    }
    Number& operator=(const Number& ref){
        cout << "operator=()"<<endl;
        num =ref.num;
        return *this;
    }
    void printNumber(){
        cout << num << endl;
    }
};

int main()
{
    Number num1(3.14);

    num1 = 30;
    num1.printNumber();

    return 0;
}*/

//객체 동적 할당
/*
#include <iostream>
using namespace std;

class Cox{
private:
    int age;
public:
    Cox (int age):age(age){
        cout << "Cox::Cox(age) 생성자 완료"<< endl;
    }
    Cox(){
        cout << "Cox::Cox(age) 생성자 완료" <<endl;
    }
    ~Cox(){
        cout << "Chulsoo::Chulsoo() 소멸자 완료" <<endl;
    }
    void setAge(int age){
        this -> age = age;
    }
    void introduce();
};

int main(void){
    Cox* coxPtr1 = (Cox*)malloc(sizeof(Cox));
    coxPtr1 -> setAge(30);
    coxPtr1 -> introduce();
    free(coxPtr1);
    return 0;
}

void Cox::introduce(){
    cout << "Cox age: " << age << endl;
}*/

//배열클래스
#include <iostream>

using namespace std;

class Point {
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) {  }
    friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}

class BoundCheckPointArray {
private:
    Point *arr;
    int arrlen;

    BoundCheckPointArray(const BoundCheckPointArray& arr) { }
    BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) { return *this; }

public:
    BoundCheckPointArray(int len) :arrlen(len) {
        arr = new Point[len];
    }

    Point& operator[] (int idx) {
        if(idx<0 || idx>=arrlen) {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }

        return arr[idx];
    }

    Point operator[] (int idx) const {
        if(idx<0 || idx>=arrlen) {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }

        return arr[idx];
    }

    int GetArrLen() const {
        return arrlen;
    }

    ~BoundCheckPointArray() {
        delete []arr;
    }
};

int main(void)
{
    BoundCheckPointArray arr(3);
    arr[0] = Point(3,4);
    arr[1] = Point(5,6);
    arr[2] = Point(7,8);

    for(int i = 0; i<arr.GetArrLen(); i++)
        cout<<arr[i];

    return 0;
}
