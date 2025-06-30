/*
#include <iostream>

using namespace std;

class Adder{
public:
    int operator()(const int& n1, const int& n2)
    {
        return n1 + n2;
    }
    double operator()(const double& e1,const double& e2)
    {
        return e1 + e2;
    }
    Point operator()(const Point& pos1, const Point& pos2)
    {
        return pos1 + pos2;
    }
};


int main()
{
    Adder adder;
    cout<<adder(1,3)<<endl;
    cout<<adder(1.5, 3.7)<<endl;
    //cout<<adder(Point(3,4),Point(7,9));
    return 0;
}*/

/*
#include <iostream>
using namespace std;

// 2차원 좌표를 나타내는 Point 클래스 정의
class Point { //???????
public:
    int x, y;

    // 생성자 (기본값: (0, 0))
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // + 연산자 오버로딩: 두 Point 객체를 더할 수 있게 함
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // 출력 스트림 연산자 << 오버로딩: Point를 출력할 수 있게 함
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

// Adder 클래스: 다양한 타입에 대해 () 연산자를 오버로딩하여 덧셈 수행
class Adder {
public:
    // 정수 덧셈
    int operator()(const int& n1, const int& n2) {
        return n1 + n2;
    }

    // 실수 덧셈
    double operator()(const double& e1, const double& e2) {
        return e1 + e2;
    }

    // Point 객체 덧셈
    Point operator()(const Point& pos1, const Point& pos2) {
        return pos1 + pos2;
    }
};

int main() {
    // Adder 객체 생성
    Adder adder;

    // 정수 덧셈 호출
    cout << adder(1, 3) << endl; // 출력: 4

    // 실수 덧셈 호출
    cout << adder(1.5, 3.7) << endl; // 출력: 5.2

    // Point 객체 덧셈 호출
    cout << adder(Point(3, 4), Point(7, 9)) << endl; // 출력: (10, 13)

    return 0;
}



//스마트 포인터
/*
#include <iostream>
#include <memory> // 스마트 포인터 사용을 위한 헤더

using namespace std;

// 예시용 클래스
class MyClass {
public:
    MyClass(int val) : value(val) {
        cout << "MyClass 생성자 호출 (value = " << value << ")" << endl;
    }
    ~MyClass() {
        cout << "MyClass 소멸자 호출 (value = " << value << ")" << endl;
    }
    void show() const {
        cout << "값: " << value << endl;
    }
private:
    int value;
};*/

/*
int main() {
    // unique_ptr: 소유권이 하나만 존재. 자동으로 메모리 해제됨.
    {
        unique_ptr<MyClass> ptr1 = make_unique<MyClass>(10); // C++14 이상
        ptr1->show(); // 포인터처럼 객체 접근 가능
        // ptr1이 범위를 벗어나면 자동으로 delete
    }

    cout << "---------------------" << endl;

    // shared_ptr: 여러 개의 shared_ptr이 같은 객체를 공유함.
    {
        shared_ptr<MyClass> ptr2 = make_shared<MyClass>(20);
        {
            shared_ptr<MyClass> ptr3 = ptr2; // 참조 카운트 증가
            cout << "ptr2와 ptr3가 같은 객체를 가리킴" << endl;
            ptr3->show();
        } // ptr3 소멸 → 참조 카운트 감소

        cout << "ptr3는 소멸, ptr2는 여전히 유효" << endl;
        ptr2->show();
    } // ptr2 소멸 → 참조 카운트 0 → 객체 삭제

    cout << "프로그램 종료" << endl;
    return 0;
}*/



//unique C++ 11이후
/*
#include <memory>
#include <iostream>
using namespace std;

int main()
{
    unique_ptr<int> ptr01(new int(5));

    auto ptr02 = std::move(ptr01);// move(ptr01)?? std::move(ptr01)
    //대입 연산자를 이용한 복사는 오류를 발생시킴
    //unique_ptr<int> ptr03 = prt01
    cout << ptr01 << endl;
    cout << ptr02 << endl;

    ptr02.reset();
    ptr01.reset();

    cout << ptr01 << endl;
    cout << ptr02 << endl;

}


//
int main(void)
{
    unique_ptr<Cox> coxSmptr1(new Cox(30));
    coxSmptr1 -> introduce();
    cout << " " << endl;
    unique_ptr<Cox> coxSmptr2 = coxSmptr1;
    //unique_ptr<Cox> coxSmptr2 = move(coxSmptr1);
    coxSmptr1 -> introduce();
    coxSmptr2 -> introduce();

    return 0;
}*/


//shared_ptr
/*
#include <memory>
#include <iostream>
using namespace std;

int mian()
{
    shared_ptr<int> ptr01 (new int(5));
    cout << ptr01.use_count() << endl;
    auto ptr02(ptr01);
    cout << ptr01.use_count() << endl;
    auto ptr03 = ptr01;
    cout << ptr01.use_count() << endl;
}

int main(void)
{
    shared_ptr<Cox> coxSmptr1 (new Cox(30));
    cout << coxSmptr1.use_count() << endl;
    coxSmptr1 -> introduce();
    cout << " " << coxSmptr1;
    shared_ptr<Cox> coxSmptr2 = coxSmptr1;
    cout << coxSmptr1.use_count() << endl;
    coxSmptr1 -> introduce();
    coxSmptr2 -> introduce();

    return 0;
}*/

//weak_ptr



//수정전
/*
#include <iostream>
using namespace st;

class Person
{
private:
    int age;
    char name;
public:
    Person(int myage, char* myname) : age(myage)
    {
        strcpy(name, myname);
    }
    void WhatYourname() const
    {
        cout << "My name is" <<name<<endl;
    }
    void HowOldAreYou() const
    {
        cout << "I'm "<<age<<" years old"<<endl;
    }
};

class UnivStudent : public
{
private:
    char major[50];
public:
    UnivStudent(char* myname, int myage, char* mymajor)
        : Person(myage, myname)
    {
        strcpy(major, myname);
    }
    void WhoAreYou() const
    {
        WhatYourName();
        HowOldAreYou();
        cout << " " << major<<endl;<<endl;
    }
};*/
/*
#include <iostream>
#include <cstring> // strcpy 사용을 위해 필요
using namespace std;

class Person
{
private:
    int age;
    char name[50]; // 문자열 저장을 위한 배열
public:
    Person(int myage, const char* myname) : age(myage)
    {
        strcpy(name, myname);
    }

    void WhatYourname() const
    {
        cout << "My name is " << name << endl;
    }

    void HowOldAreYou() const
    {
        cout << "I'm " << age << " years old" << endl;
    }
};

class UnivStudent : public Person
{
private:
    char major[50];
public:
    UnivStudent(const char* myname, int myage, const char* mymajor)
        : Person(myage, myname)
    {
        strcpy(major, mymajor);
    }

    void WhoAreYou() const
    {
        WhatYourname();
        HowOldAreYou();
        cout << "My major is " << major << endl;
    }
};

int main()
{
    UnivStudent student("Alice", 21, "Computer Science");
    student.WhoAreYou();

    return 0;
}*/


//유도 클래스
/*
#include <iostream>
using namespace std;

class SoBase
{
private:
    int baseNum;
public:
    SoBase():baseNum(20)
    {
        cout << "SoBase()" << endl;
    }
    SoBase(int n):baseNum(n)
    {
        cout << "SoBase(int n)" << endl;
    }
    void ShowBaseData()
    {
        cout << baseNum << endl;
    }
};

class SoDerived : public SoBase
{
private:
    int derivNum;
public:
    SoDerived() : derivNum(30)
    {
        cout << "SoDerived()" << endl;
    }
    SoDerived(int n) : derivNum(n)
    {
        cout << "SoDerived(int n)" << endl;
    }
    SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)
    {
        cout << "SoDerived(int n1, int n2)" << endl;
    }
    void ShowDerivData()
    {
        ShowBaseData();
        cout << derivNum << endl;
    }
};


int main(void)
{
    cout << "case1..... " << endl;
    SoDerived dr1;
    dr1.ShowDerivData();
    cout << "----------------------" << endl;
    cout << "case2..... " <<endl;
    SoDerived dr2(12);
    dr2.ShowDerivData();
    cout << "----------------------" << endl;
    cout << "case3..... " << endl;
    SoDerived dr3(23, 24);
    dr3.ShowDerivData();

    return 0;
}*/


//8장 64p
/*
#include "rec.h"
#include <iostream>
using namespace std;

int main() {
    Rectangle rect1;                // 객체 생성

    rect1.SetWidth(3.2);            // 너비 설정
    rect1.SetHeight(4.3);           // 높이 설정
    rect1.CalArea();                // 넓이 계산
    rect1.SetColor("blue");         // 색상 설정

    // 결과 출력
    cout << "* Width: " << rect1.GetWidth() << endl;
    cout << "* Height: " << rect1.GetHeight() << endl;
    cout << "* Area: " << rect1.GetArea() << endl;

    if (rect1.IsPaint()) {
        cout << "* Color: " << rect1.GetColor() << endl;
    }

    return 0;
}*/


//
/*
#include <iostream>
using namespace std;

class First
{
public:
    void MyFunc(){cout << "FirstFunc" << endl;}
};

class Second: public First
{
    void MyFunc(){cout << "SecondFunc" << endl;}
};

class Third: Public Second
{
    void MyFunc(){cout << "ThirdFunc"<< endl; }
};

int main(void)
{
    Thrid* tptr = new Thrid();
    Second* sptr = tptr;
    First* ftr = sptr;

    fptr -> MyFunc();
    sptr -> MyFunc();
    fptr -> MyFunc();
    delete tptr;

    return 0;
}*/

//수정 코드
/*
#include <iostream>
using namespace std;

class First {
public:
    // 가상 함수 선언 (다형성 가능)
    virtual void MyFunc() { cout << "FirstFunc" << endl; }
};

class Second : public First {
public:
    // 오버라이딩
    void MyFunc() override { cout << "SecondFunc" << endl; }
};

class Third : public Second {
public:
    // 오버라이딩
    void MyFunc() override { cout << "ThirdFunc" << endl; }
};

int main(void) {
    Third* tptr = new Third();   // Third 클래스 포인터
    Second* sptr = tptr;         // 업캐스팅 (Third → Second)
    First* ftr = sptr;           // 업캐스팅 (Second → First)

    // 모두 Third::MyFunc() 출력됨 (다형성 작동)
    ftr->MyFunc();   // ThirdFunc
    sptr->MyFunc();  // ThirdFunc
    tptr->MyFunc();  // ThirdFunc

    delete tptr;
    return 0;
}*/



/*
#include <iostream>
#include <string>
using namespace std;

class AbstractClass
{
public:
    virtual string SampleFunction() = 0;
};

class TestClass: public AbstractClass
{
public:
    string SampleFunstion()
    {
        return "SampleFunction";
    }
};


int main()
{
    AbstractClass Obj1;
    cout << obj.SampleFunction() << endl;
    retuen 0;
}*/



//수정 후
#include <iostream>  // 입출력을 위한 헤더
#include <string>    // string 클래스 사용을 위한 헤더
using namespace std; // std 네임스페이스 사용

// 추상 클래스 선언
class AbstractClass
{
public:
    // 순수 가상 함수: 이 클래스를 상속받는 클래스는 반드시 이 함수를 구현해야 함
    virtual string SampleFunction() = 0;
};

// 추상 클래스를 상속받은 구체 클래스
class TestClass : public AbstractClass
{
public:
    // 순수 가상 함수 구현 (오버라이딩)
    string SampleFunction() override
    {
        return "SampleFunction";  // 문자열 반환
    }
};

int main()
{
    TestClass obj1;  // TestClass 객체 생성
    cout << obj1.SampleFunction() << endl;  // SampleFunction 함수 호출 및 결과 출력
    return 0;  // 프로그램 정상 종료
}

