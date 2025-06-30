//수정전
/*
#include <iostream>

using namespace std;

class Chulsoo;

class Younghee{
private:
    int age;
public:
    Younghee(int age):age(age){
        cout << "Younghee::Yoynghee(age) " << endl;
    }
    void introduce(){
        cout << "younghee age: " << age << endl;
    }
    void whoIsOlder(const Chulsoo & chulsooObj);
};

class Chuldsoo{
private:
    int age;
public:
    Chulsoo(int age):age(age){
        cout << "Chulsoo::Chulsoo(age) " << endl;
    }
    void introduce(){
        cout << "chulsoo age: " << age << endl;
    };

};

void Younghee::whoIsOlder(const Chulsoo & chulsooObj){
    cout << " " << ((age > chulsooObj.age)?\" ":" ") << endl;
}

int main()
{
    Chulsoo chulsoo(32);
    chulsoo1.introduce();
    Younhee younghee(35);
    younghee1.introduce();

    younghee1.WhoIsOlder(Chuls001);

    return 0;
}*/



/*
#include <iostream>
using namespace std;

class Chulsoo;  // Forward declaration

class Younghee {
private:
    int age;
public:
    Younghee(int age): age(age) {
        cout << "Younghee::Younghee(age)" << endl;
    }

    void introduce() {
        cout << "younghee age: " << age << endl;
    }

    void whoIsOlder(const Chulsoo &chulsooObj);

    friend void howOldAreYou(const Chulsoo & chulsooObj, const Younghee & youngheeObj);
};

class Chulsoo {
private:
    int age;
public:
    Chulsoo(int age): age(age) {
        cout << "Chulsoo::Chulsoo(age)" << endl;
    }

    void introduce() {
        cout << "chulsoo age: " << age << endl;
    }

    // Give Younghee access to private members
    friend void Younghee::whoIsOlder(const Chulsoo &chulsooObj);
    friend void howOldAreYou(const Chulsoo & chulsooObj, const Younghee & youngheeObj);
};

void Younghee::whoIsOlder(const Chulsoo &chulsooObj) {
    if (age > chulsooObj.age)
        cout << "Younghee is older." << endl;
    else if (age < chulsooObj.age)
        cout << "Chulsoo is older." << endl;
    else
        cout << "They are the same age." << endl;
}

void howOldAreYou(const Chulsoo & chulsooObj, const Younghee & youngheeObj){
    cout << "chulsoo is " << chulsooObj.age << endl;
    cout << "younhee is " << youngheeObj.age << endl;
}

int main() {
    Chulsoo chulsoo(32);
    chulsoo.introduce();

    Younghee younghee(35);
    younghee.introduce();

    younghee.whoIsOlder(chulsoo);

    //howOldAreYou(chulsoo, younghee);

    return 0;
}*/

//정올 1341 구구단2
/*
#include <iostream>
#include <iomanip>  // setw 사용
using namespace std;

int main() {
    int s, e;
    cin >> s >> e;

    int step = (s <= e) ? 1 : -1;

    for (int dan = s; dan != e + step; dan += step) {
        for (int i = 1; i <= 9; ++i) {
            // 예: 2 * 1 = 2  형식 출력
            cout << dan << " * " << i << " = " << setw(2) << dan * i;

            if (dan != e) cout << "   ";  // 구구단 사이 간격 3칸
        }
        cout << endl;
    }

    return 0;
}*/


/*
#include <iostream>
using namespace std;

class SoSimple{
private:
    static int simObjCnt;
public:
    SoSimple()
    {
        simObjCnt++;
        cout << simObjCnt << " " << endl;//몇번째 객체
    }
};

int SoSimple::simObjCnt=0;

int main(void)
{
    SoSimple sim1;
    SoSimple sim2;
    SoSimple Sim3;
}*/
//예제확인



//수정전
/*
#include <iostream>
using namespace std;

class Chulsoo{
private:
    int age;
    static int chulsooPrivateCounter;
protected:
    static int chulsooProtectedCounter;
public:
    static int chulsooPublicCounter;
    Chulsoo(int age):age(age){
        chulsooPrivateCounter++;
        chulsooProtectedCounter++;
        chulsooPublicCounter++;
        cout << "Chulsoo::chulsoo(age): " << chulsooPrivateCounter << "(private)" << endl;
        cout << "Chulsoo::chulsoo(age): " << chulsooProtectedCounter << "(ProtectedCounter)" << endl;
        cout << "Chulsoo::chulsoo(age): " << chulsooPublic << "(Public)" << endl;
    }
};
int Chulsoo::chulsooPrivateCounter;
int Chulsoo::chulsooProtectedCounter;
int Chulsoo::chulsooPublicCounter;

class Younghee{
private:
    int age; return 0;
public:
    Younghee(int age):age(age){
        Chulsoo::chulsooPublicCounter++;
        cout << "Yonghee::younghee(age): " << Chulsoo::chulsooPublicCounter << " " << endl;
    }
};

int main(void)
{
    Chulsoo chulsoo1(32);
    Chulsoo chulsoo2(32);
    Younghee younghee1(32);
    Younghee younghee2(32);

    retuen 0;
}*/


/*
#include <iostream>
using namespace std;

class Chulsoo {
private:
    int age;
    static int chulsooPrivateCounter;
protected:
    static int chulsooProtectedCounter;
public:
    static int chulsooPublicCounter;
    Chulsoo(int age) : age(age) {
        chulsooPrivateCounter++;
        chulsooProtectedCounter++;
        chulsooPublicCounter++;
        cout << "Chulsoo::chulsoo(age): " << chulsooPrivateCounter << " (private)" << endl;
        cout << "Chulsoo::chulsoo(age): " << chulsooProtectedCounter << " (protected)" << endl;
        cout << "Chulsoo::chulsoo(age): " << chulsooPublicCounter << " (public)" << endl;
    }
};

// static 멤버 초기화
int Chulsoo::chulsooPrivateCounter = 0;
int Chulsoo::chulsooProtectedCounter = 0;
int Chulsoo::chulsooPublicCounter = 0;

class Younghee {
private:
    int age;
public:
    Younghee(int age) : age(age) {
        Chulsoo::chulsooPublicCounter++;
        cout << "Younghee::younghee(age): " << Chulsoo::chulsooPublicCounter << endl;
    }
};

int main(void) {
    Chulsoo chulsoo1(32);     // 객체 1 생성
    Chulsoo chulsoo2(32);     // 객체 2 생성
    Younghee younghee1(32);   // 객체 3 생성 (Chulsoo::publicCounter 증가)
    Younghee younghee2(32);   // 객체 4 생성 (Chulsoo::publicCounter 증가)

    return 0;
}*/

/*
#include <iostream>
using namespace std;

class Chulsoo{
private:
    int age;
public:
    Chulsoo(int age):age(age){
        cout << "Chulsoo::chulsoo(age)" << endl;
    }
    void introduce(){
        cout << " " << age << endl;
    }
    Chulsoo add(const Chulsoo& chulsooObj);
    Chulsoo sub(const Chulsoo& chulsooObj);
    Chulsoo mul(const Chulsoo& chulsooObj);
    Chulsoo div(const Chulsoo& chulsooObj);
};

int main(void)
{
    Chulsoo chulsoo1(30);
    Chulsoo chulsoo2(15);
    chulsoo1.introduce();
    chulsoo2.introduce();

    Chulsoo chulsooAdd = chulsoo1.add(chulsoo2);
    chulsooAdd.introduce();
    Chulsoo chulsoosub = chulsoo1.sub(chulsoo2);
    chulsoosub.introduce();
    Chulsoo chulsoomul = chulsoo1.mul(chulsoo2);
    chulsoomul.introduce();
    Chulsoo chulsoodiv = chulsoo1.div(chulsoo2);
    chulsoodiv.introduce();

    return 0;
}

Chulsoo Chulsoo::add(const Chulsoo& chulsooObj){
    cout << "chul::add()" << endl;
    Chulsoo chulsoo(this->age+chulsooObj.age);
    return chulsoo;
}

Chulsoo Chulsoo::sub(const Chulsoo& chulsooObj){
    cout << "chul::sub()" << endl;
    Chulsoo chulsoo(this->age-chulsooObj.age);
    return chulsoo;
}

Chulsoo Chulsoo::mul(const Chulsoo& chulsooObj){
    cout << "chul::mul()" << endl;
    Chulsoo chulsoo(this->age*chulsooObj.age);
    return chulsoo;
}

Chulsoo Chulsoo::div(const Chulsoo& chulsooObj){
    cout << "chul::div()" << endl;
    Chulsoo chulsoo(this->age/chulsooObj.age);
    return chulsoo;
}*/

/*
#include <iostream>
using namespace std;

class Chulsoo{
private:
    int age;
public:
    Chulsoo(int age):age(age){
        cout << "Chulsoo::Chulsoo(age) " << endl;
    }
    void introduce(){
        cout << " " << age << endl;
    }
    Chulsoo operator+(const Chulsoo& chulsooObj);
    Chulsoo operator-(const Chulsoo& chulsooObj);
    Chulsoo operator*(const Chulsoo& chulsooObj);
    Chulsoo operator/(const Chulsoo& chulsooObj);
};

int main(void)
{
    Chulsoo chulsoo1(30);
    Chulsoo chulsoo2(15);
    chulsoo1.introduce();
    chulsoo2.introduce();

    Chulsoo chulsooAdd = chulsoo1 + chulsoo2;
    chulsooAdd.introduce();
    Chulsoo chulsooSub = chulsoo1 - chulsoo2;
    chulsooSub.introduce();
    Chulsoo chulsooMul = chulsoo1 * chulsoo2;
    chulsooMul.introduce();
    Chulsoo chulsooDiv = chulsoo1 / chulsoo2;
    chulsooDiv.introduce();

    return 0;
}

Chulsoo Chulsoo::operator+(const Chulsoo& ChulsooObj){
    cout << "Chulsoo::operator+()" << endl;
    Chulsoo chulsoo(this->age + ChulsooObj.age);
    return chulsoo;
}

Chulsoo Chulsoo::operator-(const Chulsoo& ChulsooObj){
    cout << "Chulsoo::operator-()" << endl;
    Chulsoo chulsoo(this->age - ChulsooObj.age);
    return chulsoo;
}

Chulsoo Chulsoo::operator*(const Chulsoo& ChulsooObj){
    cout << "Chulsoo::operator*()" << endl;
    Chulsoo chulsoo(this->age * ChulsooObj.age);
    return chulsoo;
}

Chulsoo Chulsoo::operator/(const Chulsoo& ChulsooObj){
    cout << "Chulsoo::operator/()" << endl;
    Chulsoo chulsoo(this->age / ChulsooObj.age);
    return chulsoo;
}*/

/*
#include <iostream>
using namespace std;

class Chulsoo{
private:
    int age;
public:
    Chulsoo(int age) : age(age){
        cout << "Chulsoo::Chulsoo(age) " << endl;
    }
    void introduce(){
        cout << " " << age << endl;
    }
    friend Chulsoo operator+(const Chulsoo& chulsooObj1, const Chulsoo& chulsooObj2);
};

int main(void)
{
    Chulsoo chulsoo1(30);
    Chulsoo chulsoo2(15);
    chulsoo1.introduce();
    chulsoo2.introduce();
    Chulsoo chulsooAdd = 3+chulsoo1;
    chulsooAdd.introduce();

    return 0;
}

Chulsoo operator+(const Chulsoo& chulsooObj1, const Chulsoo& chulsooObj2){
    cout << "operator+()" << endl;
    Chulsoo chulsoo(chulsooObj1.age + chulsooObj2.age);
    return chulsoo;
}*/


/*
#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y){}
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point& operator++()
    {
        xpos += 1;
        ypos += 1;
        return *this;
    }
    friend Point& operator--(Point &ref);
    //friend const Point operator++();
};


Point& operator--(Point &ref)
{
    ref.xpos-=1;
    ref.ypos-=1;
    return ref;
}

int main (void)
{

    //const Point pos(3, 4);
    //const Point &ref = pos;

    Point pos(1, 2);
    ++pos;
    pos.ShowPosition();
    --pos;
    pos.ShowPosition();
    ++(++pos);
    pos.ShowPosition();
    --(--pos);
    pos.ShowPosition();

    return 0;
}*/

/*
const Point operator++(int)
{
    const Point retobj(xpos, ypos);
    xpos+=1;
    ypos+=1;
    return retobj;
}*/

/*
#include "time.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() {
    Time t1(7, 30, 20);
    cout << t1.ShowTime() << endl;
    cout << "s: " << t1.CalSec() << endl;

    Time t2(4, 50, 23);

    if (t1 >= t2) {
        cout << t1.ShowTime() << " " << t2.ShowTime() << endl;
    } else {
        cout << t2.ShowTime() << " " << t1.ShowTime() << endl;
    }

    if (t1 <= t2) {
        cout << t2.ShowTime() << " " << t1.ShowTime() << endl;
    } else {
        cout << t1.ShowTime() << " " << t2.ShowTime() << endl;
    }

    return 0;
}*/

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
}



