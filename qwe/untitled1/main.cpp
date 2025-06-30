//다중 상속
/*
#include <iostream>

using namespace std;


class BaseOne
{
public:
    void SimpleFuncOne(){cout << "BaseOne" << endl;}
};
class BaseTwo
{
public:
    void SimpleFuncTwo(){cout << "BaseTwo" << endl;}
};
class MultDerived : public BaseOne, protected BaseTwo
{
public:
    void ComplexFunc()
    {
        SimpleFuncOne();
        SimpleFuncTwo();
    }
};

int main()
{
    MultDerived mdr;
    mdr.ComplexFunc();
    return 0;
}*/

/*
#include <iostream>
using namespace std;

class Person
{
public:
    Person(){
        cout << "Person::PerSon() 생성자 호출" << endl;
    }
    ~Person(){
        cout << "Person::~Person() 소멸자 호출" << endl;
    }
    virtual void write() = 0;
};

class Cox: public Person{
public:
    Cox():Person(){
        cout << "Cox::cox() 생성자 호출" <<endl;
    }
    ~Cox(){
        cout << "Cox::cox() 소멸자 호출" <<endl;
    }
    void write(){
        cout << "책을 잘 쓴다" << endl;
    }
};

class Soo: public Person{
public:
    Soo():Person(){
        cout << "Soo::soo() 생성자 호출" << endl;
    }
    ~Soo(){
        cout << "Soo::~soo() 소멸자 호출" << endl;
    }
    void write(){
        cout << "챡을 못 쓴다" << endl;
    }
};
class Chul:public Cox, public Soo{
public:
    Chul():Cox(),Soo(){
        cout << "Chul::chul()생성자 호출" <<endl;
    }
    ~Chul(){
        cout << "Chul::~Chul() 소멸자 호출" << endl;
    }
    void write(){
        Chul::write();
    }
};


int main(void)
{
    Cox sox;
    Soo soo;
    Chul chul;
}*/

//
/*
#include <iostream>
using namespace std;

// Abstract base class
class Person {
public:
    Person() {
        cout << "Person::Person() constructor called" << endl;
    }

    ~Person() {
        cout << "Person::~Person() destructor called" << endl;
    }

    // Pure virtual function: must be overridden
    virtual void write() = 0;
};

// Derived class Cox from Person
class Cox : public  virtual Person {
public:
    Cox() : Person() {
        cout << "Cox::Cox() constructor called" << endl;
    }

    ~Cox() {
        cout << "Cox::~Cox() destructor called" << endl;
    }

    // Override write method
    void write() override {
        cout << "Writes books well." << endl;
    }
};

// Derived class Soo from Person
class Soo : public virtual Person {
public:
    Soo() : Person() {
        cout << "Soo::Soo() constructor called" << endl;
    }

    ~Soo() {
        cout << "Soo::~Soo() destructor called" << endl;
    }

    // Override write method
    void write() override {
        cout << "Does not write books well." << endl;
    }
};

// Chul inherits from both Cox and Soo
class Chul : public Cox, public Soo {
public:
    Chul() : Cox(), Soo() {
        cout << "Chul::Chul() constructor called" << endl;
    }

    ~Chul() {
        cout << "Chul::~Chul() destructor called" << endl;
    }

    // Override write and specify which parent's version to call
    void write() override {
        Cox::write();  // or Soo::write();
    }
};

int main(void) {
    cout << "--- Creating Cox object ---" << endl;
    Cox sox;

    cout << "\n--- Creating Soo object ---" << endl;
    Soo soo;

    cout << "\n--- Creating Chul object ---" << endl;
    Chul chul;

    cout << "\n--- Testing Chul.write() ---" << endl;
    chul.write();

    cout << "\n--- End of program ---" << endl;
    return 0;
}*/

//다중 상속의 모호성()
/*
#include <iostream>
using namespace std;

// Abstract base class
class Person {
public:
    Person() {
        cout << "Person::Person() constructor called" << endl;
    }

    ~Person() {
        cout << "Person::~Person() destructor called" << endl;
    }

    virtual void write() = 0;

    void sleep() {
        cout << "Sleeping..." << endl;
    }
};

// Derived class Cox
class Cox : public Person {
public:
    Cox() : Person() {
        cout << "Cox::Cox() constructor called" << endl;
    }

    ~Cox() {
        cout << "Cox::~Cox() destructor called" << endl;
    }

    void write() override {
        cout << "Writes books well." << endl;
    }
};

// Derived class Soo
class Soo : public Person {
public:
    Soo() : Person() {
        cout << "Soo::Soo() constructor called" << endl;
    }

    ~Soo() {
        cout << "Soo::~Soo() destructor called" << endl;
    }

    void write() override {
        cout << "Cannot write books well." << endl;
    }
};

// Derived class Chul (multiple inheritance)
class Chul : public Cox, public Soo {
public:
    Chul() : Cox(), Soo() {
        cout << "Chul::Chul() constructor called" << endl;
    }

    ~Chul() {
        cout << "Chul::~Chul() destructor called" << endl;
    }

    void write() override {
        // Fix: avoid infinite recursion
        Cox::write();  // You could also use Soo::write() here
    }
};

int main(void) {
    cout << "--- Creating Cox object ---" << endl;
    Cox sox;

    cout << "\n--- Creating Soo object ---" << endl;
    Soo soo;

    cout << "\n--- Creating Chul object ---" << endl;
    Chul chul;

    cout << "\n--- Testing Chul.write() ---" << endl;
    chul.write();

    cout << "\n--- Program end ---" << endl;

    return 0;
}*/


//template
/*
#include <iostream>
using namespace std;

template <typename T>
T const add (T const& a, T const& b){
    return a+b;
}

int main(void){
    double i = 5.1;
    double j = 10.2;

    int a = 5;
    int b = 10;

    cout <<i<< "+" <<j<< "=" <<add(i,j)<<endl;
    cout <<a<< "+" <<b<< "=" <<add(a,b)<<endl;

    return 0;
}*/
/*
#include <iostream>
using namespace std;

template <class T1, class T2>
void ShowData(double num)
{
    cout << (T1)num << ", " << (T2)num <<endl;
}

#include <iostream>
using namespace std;

int main (void)
{
    ShowData<char, int>(65);
    ShowData<char, int>(67);
    ShowData<char, double>(68.9);
    ShowData<short, double>(69.2);
    ShowData<short, double>(70.4);

    return 0;
}*/
/*
#include <iostream>
using namespace std;

template <typename T,typename R>
R MaxValue(const T num1, const R num2)
{
    if (num1>num2)
        return num1;
    else
        return num2;
}

int main()
{
    cout << " " << MaxValue(3,5) << endl;
    cout << " " << MaxValue(9.1, 3.6)<< endl;
    return 0;
}*/
/*
#include <iostream>
using namespace std;

template <typename R,typename T,typename U>
R const add(T const& a,U const& b)
{
    return a+b;
}

int main(){
    double i = 5.1;
    int a = 5;
    cout <<i<< "" << a << "=" << add(i,a)<<endl;
    return 0;
}*/

//함수템플릿 특수화
/*
#include <iostream>
using namespace std;

template <typename T>
T Max(T a, T b)
{
    return a>b ? a : b;
}

template <>
char* Max(char* a, char* b)
{
    cout<<"char* Max<char*>(char* a, char* b)"<<endl;
    return strlen(a) > strlen(b) ? a : b;
}
template <>
const char* Max(const char* a,const char* b)
{
    cout<<"const char* Max<const char*>(const char* a,const char* b)"<<endl;
    return strcmp(a,b) > 0 ? a : b;
}

int main(){
    cout << Max(11,15) <<endl;
    cout << Max(11,15) <<endl;
    cout << Max(11,15) <<endl;
    cout << Max(11,15) <<endl;
    char str1[]="Simple";
    char str2[]="Best";
    cout << Max(str1,str2)<<endl;

    return 0;
}*/

//클래스 템플릿
//수정전
/*
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MyArray{
private:
    vector<T> list;
public:
    void add_lost(T const&);
    void delete_last_list(void);
    void show_list(void);
};

template <typename T>
void MyArray<T>::add_list(T const& element){
    list.push_back(element);
}
template <typename T>
    void MyArray<T>::delete_list(void){
    list.pop_back();
}
template <typename T>
void MyArray<T>::show_list(void){
    cout << "[MyArray list look up]" << endl;
    for(typename vector<T>::iterator i=list.begin(); i!=list.end();i++)
        cout << *i << endl;
}

int main(){
    MyArray<int> array1;
    array1.add_list(1);
    array1.add_list(2);
    array1.add_list(3);
    array1.add_list(4);
    array1.add_list(5);
    array1.show_list();

    array1.delete_last_list();
    array1.delete_last_list();
    array1.show_list();

    MyArray<double> array2;
    array2.add_list(1.1);
    array2.add_list(2.2);
    array2.add_list(3.3);
    array2.add_list(4.4);
    array2.add_list(5.5);
    array2.show_list();
    array2.delete_last_list();
    array2.delete_last_list();

    array2.show_list();

    return 0;
}*/

//수정후
/*
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MyArray {
private:
    vector<T> list;

public:
    void add_list(T const&);          // 원소 추가
    void delete_last_list(void);      // 마지막 원소 삭제
    void show_list(void);             // 전체 출력
};

// 함수 정의들

template <typename T>
void MyArray<T>::add_list(T const& element) {
    list.push_back(element);
}

template <typename T>
void MyArray<T>::delete_last_list(void) {
    if (!list.empty()) {
        list.pop_back();
    }
}

template <typename T>
void MyArray<T>::show_list(void) {
    cout << "[MyArray list look up]" << endl;
    for (typename vector<T>::iterator i = list.begin(); i != list.end(); ++i)
        cout << *i << endl;
}

int main() {
    MyArray<int> array1;
    array1.add_list(1);
    array1.add_list(2);
    array1.add_list(3);
    array1.add_list(4);
    array1.add_list(5);
    array1.show_list();

    array1.delete_last_list();
    array1.delete_last_list();
    array1.show_list();  // ← 수정됨

    MyArray<double> array2;
    array2.add_list(1.1);
    array2.add_list(2.2);
    array2.add_list(3.3);
    array2.add_list(4.4);
    array2.add_list(5.5);
    array2.show_list();

    array2.delete_last_list();
    array2.delete_last_list();
    array2.show_list();

    return 0;
}*/
/*
#include <iostream>
#include <vector>
using namespace std;

template <typename T, int init =3 >
class MyArray{
private:
    vector<T> list;
public:
    MyArray(){
        for(int i=0;i<init;++i)
            list.push_back(i);
    }
    void add_list(T const&);
    void delete_last_list(void);
    void show_list(void);
};
template <typename T, int init>
void MyArray<T, init>::add_list(T const& element){
    list.push_back(element);
}
template <typename T, int init>
void MyArray<T, init>::delete_show_list(void){
    list.pop_back();
}
template <typename T,int init>
void MyArray<T, init>::show_list(void){
    cout << "[MyArray list look]" << endl;
    for(typename vetor<T>::itertor i=list.begin();i!=list.end;++i)
        cout << *i <<endl;
}

int main(){
    MyArray<int, 3>array1;
    array1.add_list(1);
    array1.add_list(2);
    array1.add_list(3);
    array1.add_list(4);
    array1.add_list(5);
    array1.show_list();

    return 0;
}*/
//수정후
/*
#include <iostream>
#include <vector>
using namespace std;

template <typename T, int init = 3>
class MyArray {
private:
    vector<T> list;
public:
    MyArray() {
        for (int i = 0; i < init; ++i)
            list.push_back(i);
    }
    void add_list(T const&);
    void delete_last_list(void);
    void show_list(void);
};*/

// 멤버 함수 정의
/*
template <typename T, int init>
void MyArray<T, init>::add_list(T const& element) {
    list.push_back(element);
}

template <typename T, int init>
void MyArray<T, init>::delete_last_list(void) {
    if (!list.empty())
        list.pop_back();
}

template <typename T, int init>
void MyArray<T, init>::show_list(void) {
    cout << "[MyArray list look]" << endl;
    for (typename vector<T>::iterator i = list.begin(); i != list.end(); ++i)
        cout << *i << endl;
}

// main 함수
int main() {
    MyArray<int, 3> array1;
    array1.add_list(1);
    array1.add_list(2);
    array1.add_list(3);
    array1.add_list(4);
    array1.add_list(5);
    array1.show_list();

    return 0;
}*/


//C++ STL
/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(6,1);
    cout << "v.capacity(): " << v.capacity() << "/v.size: "<<v.size()<<endl;
    for (auto i = 0; i<v.size();i++)
        cout << v[i] << endl;
    cout << endl << endl;

    v.assign(4,3);
    cout << "v.capacity(): " << v.capacity() << "/v.size: "<<v.size()<<endl;
    for (auto i = 0; i<v.size();i++)
        cout << v[i] << endl;
    cout << endl << endl;

    v[2] = 7;
    for(vector<int>::iterator it = v.begin()+3;it !=v.end();it++)
        *it = 9;
    v.push_back(10);
    v.push_back(20);
    cout << "v.capacity(): " << v.capacity() << "/v.size: "<<v.size()<<endl;
    for (auto i = 0; i<v.size();i++)
        cout << v[i] << endl;
    cout << endl << endl;

    v.push_back(30);
    cout << "v.capacity(): " << v.capacity() << "/v.size: "<<v.size()<<endl;
    for (auto i = 0; i<v.size();i++)
        cout << v[i] << endl;
    cout << endl << endl;

    v.resize(17);
    cout << "v.capacity(): " << v.capacity() << "/v.size: "<<v.size()<<endl;
    for (auto i = 0; i<v.size();i++)
        cout << v[i] << endl;
    cout << endl << endl;

    return 0;
}*/

/*
#include <iostream>
#include <vector>
#include <sting>
#include <algorithm>
using namespace std;

class Person{
private:
    int age;
    string name;
public:
    Person(const int a, const string& n): age(a), name(n){}
    int getName(){return name;}
};

int main(int argc, char** argv)
{
    Person p1{20, "Tom"};
    Person p2{19,"Jane"};

    vector<Person>vec{
        {21, "Smith"},{39,"John"},{23,"Mary"},{45,"Ted"}
    };
    for_each(vec,begin(),vec.end(),[](Person p){
        cout <<p.getAge()<<","<<p.getName()<<endl;
    };)
        return 0;
}*/


//유니폼 초기화
/*
#include <iostream>
#include <vector>
#include <string>       // string 헤더 오타 수정
#include <algorithm>
using namespace std;

class Person {
private:
    int age;
    string name;
public:
    Person(const int a, const string& n) : age(a), name(n) {}

    int getAge() const { return age; }          // getAge 함수 추가
    string getName() const { return name; }     // 반환형 수정 및 const 함수로 선언
};

int main() {
    Person p1{20, "Tom"};
    Person p2{19, "Jane"};

    vector<Person> vec{
        {21, "Smith"}, {39, "John"}, {23, "Mary"}, {45, "Ted"}
    };

    // 올바른 for_each 문
    for_each(vec.begin(), vec.end(), [](const Person& p) {
        cout << p.getAge() << ", " << p.getName() << endl;
    });

    return 0;
}*/
//2 수정 전
/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class multiplier{
    int first;
    int second;
private:
    multiplier(int f,int s){
        first = f;
        second = s;
    }
    int getResult(){
        return first* second;
    }
};

int main()
{
    vector<multiplier>multipleData;

    for(int i = 0; i<10; i++){
        multiplier multiple = multiplier(rand() % 10,rand() % 10);
        multipleData.push_back(multiple);
    }

    cout << "정렬되지 않는 결과" <<endl;
    for (vector<Multiplier>::iterator iter=multipleData.begin();iter!= multipleData.end();iter++){
        cout << iter->getResult()<<endl;
    }
    sort(multipleData.begin(),multipleData.end(),[](multiplier& m1,multiplier& m2))
    {
        return m1.getResult()<m2.getResult();
    });
cout<<" "<<endl;
    for(vector<multiplier>::iterator iter=multipleData.begin();iter != multipleData.end();iter++){
    cout << iter->getResult() << endl;
    }
    return 0;
}*/
//2 수정 후
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> // rand()

using namespace std;

class Multiplier {
    int first;
    int second;
public:
    Multiplier(int f, int s) : first(f), second(s) {}

    int getResult() const {
        return first * second;
    }
};

int main() {
    vector<Multiplier> multipleData;

    for (int i = 0; i < 10; i++) {
        Multiplier multiple(rand() % 10, rand() % 10);
        multipleData.push_back(multiple);
    }

    cout << "Unsorted results:" << endl;
    for (vector<Multiplier>::iterator iter = multipleData.begin(); iter != multipleData.end(); iter++) {
        cout << iter->getResult() << endl;
    }

    // Sort by result value
    sort(multipleData.begin(), multipleData.end(), [](const Multiplier& m1, const Multiplier& m2) {
        return m1.getResult() < m2.getResult();
    });

    cout << "\nSorted results:" << endl;
    for (vector<Multiplier>::iterator iter = multipleData.begin(); iter != multipleData.end(); iter++) {
        cout << iter->getResult() << endl;
    }

    return 0;
}*/

//deque 수정 전
/*
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    cout << "dq.size(): " << dq.size() << endl;
    cout << "[dq]: ";
    for(auto i = 0; i<dq.size(); i++)
        cout << dq[i]<<" ";
    cout << endl;

    for(auto i = 0; i<dq.size();i++)
        cout << "dqress["<<i<<"] address: "<<&dq[i]<<endl;
    cout<<endl;
    deque<int> dq2;
    dq2.push_back(100);
    dq2.push_back(200);
    dq2.push_back(300);

    cout<<"dq2.size(): "<<dq2.size()<<endl;
    cout<<"[dq2]: ";
    for(auto i = 0; i<dq2.size();i++)
        cout <<dq2[i]<<" ";
    cout << endl;
    for(auto i = 0; i<dq2.size();i++)
        cout <<"dq2["<<i<<"]address: "<<&dq2[i]<<endl;
    cout << endl;

    dq.push_back(40);
    dq.push_back(50);
    dq.push_back(60);
    cout<<"dp.size(): "<<dq.size()<<endl;
    cout<<"[dq]: ";
    for(auto i = 0; i<dq.size();i++)
        cout <<dq[i]<<" ";
    cout << endl;
    for(auto i = 0; i<dq.size();i++)
        cout <<"dq["<<i<<"]address: "<<&dq2[i]<<endl;
    cout << endl;

    for(int i = 70;i<2000;i+=10)
        dq.push_back(i);

    cout << "dq.size(): "<<dq.size()<<endl;
    cout << "[dq]: ";

    for(auto i = 0; i<dq.size();i++)
            cout <<dq[i]<<" ";
    cout << endl;
    for(auto i = 0; i<dq.size();i++)
        cout <<"dq["<<i<<"]address: "<<&dq2[i]<<endl;
    cout << endl;

    cout<<"dq[127]("<<&dq[127]<<"):"<<dq[127]<<endl;
    cout<<"dq[128]("<<&dq[128]<<"):"<<dq[128]<<endl;
    deque<int>::iterator i = dq.begin()+127;
    cout << "*i("<<&(i)<<");"<<*i<<endl;
    i++;
    cout<<"*++i("<<&(*i)<<"):"<<*i<<endl;
    int* j=&dq[127];
    cout<<j<<": "<<*j<<endl;
    j++;
    cout<<j<<": "<<*j<<endl;

    return 0;
}*/

//수정 후
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    cout << "dq.size(): " << dq.size() << endl;
    cout << "[dq]: ";
    for (auto i = 0; i < dq.size(); i++)
        cout << dq[i] << " ";
    cout << endl;

    for (auto i = 0; i < dq.size(); i++)
        cout << "dq[" << i << "] address: " << &dq[i] << endl;
    cout << endl;

    deque<int> dq2;
    dq2.push_back(100);
    dq2.push_back(200);
    dq2.push_back(300);

    cout << "dq2.size(): " << dq2.size() << endl;
    cout << "[dq2]: ";
    for (auto i = 0; i < dq2.size(); i++)
        cout << dq2[i] << " ";
    cout << endl;
    for (auto i = 0; i < dq2.size(); i++)
        cout << "dq2[" << i << "] address: " << &dq2[i] << endl;
    cout << endl;

    dq.push_back(40);
    dq.push_back(50);
    dq.push_back(60);
    cout << "dq.size(): " << dq.size() << endl;
    cout << "[dq]: ";
    for (auto i = 0; i < dq.size(); i++)
        cout << dq[i] << " ";
    cout << endl;
    for (auto i = 0; i < dq.size(); i++)
        cout << "dq[" << i << "] address: " << &dq[i] << endl;
    cout << endl;

    for (int i = 70; i < 2000; i += 10)
        dq.push_back(i);

    cout << "dq.size(): " << dq.size() << endl;
    cout << "[dq]: ";
    for (auto i = 0; i < dq.size(); i++)
        cout << dq[i] << " ";
    cout << endl;
    for (auto i = 0; i < dq.size(); i++)
        cout << "dq[" << i << "] address: " << &dq[i] << endl;
    cout << endl;

    cout << "dq[127] (" << &dq[127] << "): " << dq[127] << endl;
    cout << "dq[128] (" << &dq[128] << "): " << dq[128] << endl;

    deque<int>::iterator i = dq.begin() + 127;
    cout << "*i (" << &(*i) << "): " << *i << endl;
    ++i;
    cout << "*++i (" << &(*i) << "): " << *i << endl;

    int* j = &dq[127];
    cout << j << ": " << *j << endl;
    ++j;
    cout << j << ": " << *j << endl;

    return 0;
}

