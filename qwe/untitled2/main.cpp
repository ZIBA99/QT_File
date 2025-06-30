
/*
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    for(int i=0; i<q.size(); ++i){
        cout << q.front() << " ";
        //q.pop();
    }

    cout << endl;
    return 0;
}*/
/*
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    queue<int> temp = q;  // 복사

    int size = temp.size();

    for (int i = 0; i < size; ++i) {
        cout << temp.front() << " ";
        temp.pop();
    }

    cout << endl;

    // 원본 큐는 여전히 존재
    cout << "q size = " << q.size() << endl;  // 4

    return 0;
}*/

//queue
/*
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
    priority_queue<int, deque<int>, greater<int>> pq3;

    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(40);
    pq.push(10);
    pq.push(20);

    // pq -> pq2
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq2.push(pq.top());
        pq.pop();
    }

    cout << endl;

    // pq2 -> pq3
    while (!pq2.empty()) {
        cout << pq2.top() << " ";
        pq3.push(pq2.top());
        pq2.pop();
    }

    cout << endl;

    // 출력: pq3
    while (!pq3.empty()) {
        cout << pq3.top() << " ";
        pq3.pop();  // 수정된 부분
    }

    cout << endl;

    return 0;
}*/

//stack
/*
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> st;
    stack<int> st2;
    stack<int> st3;

    // st에 값 추가 (순서대로 넣음)
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(40);
    st.push(10);
    st.push(20);

    // st → st2로 복사하면서 출력
    while (!st.empty()) {
        cout << st.top() << " ";  // top부터 출력
        st2.push(st.top());       // st2에 저장
        st.pop();
    }

    cout << endl;

    // st2 → st3로 복사하면서 출력
    while (!st2.empty()) {
        cout << st2.top() << " ";
        st3.push(st2.top());
        st2.pop();
    }

    cout << endl;

    // st3 출력 (원래 순서 유지)
    while (!st3.empty()) {
        cout << st3.top() << " ";
        st3.pop();
    }

    cout << endl;

    return 0;
}*/

//map
/*
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map<string, int> m;
    m.insert(make_pair("A",10));
    m.insert(make_pair("B",20));
    m.insert(make_pair("C",30));
    m.insert(make_pair("D",40));
    m.insert(make_pair("E",50));
    m["F"] = 100;
    for(auto i = m.begin(); i!=m.end(); ++i)
        cout << "[" << i->first << " " << i->second << "]";
    cout << endl;
    auto i = m.find("A");
    cout << "[" << i->first << " " << i->second << "]";
    m.insert(make_pair("E", 150));

    return 0;
}*/

//multimap
/*
#include <iostream>
#include <map>
using namespace std;

int main()
{
    multimap<string, int> mm;
    mm.insert(make_pair("A", 10));
    mm.insert(make_pair("B", 20));
    mm.insert(make_pair("C", 30));
    mm.insert(make_pair("D", 40));
    mm.insert(make_pair("E", 50));
    mm.insert(make_pair("C", 100));
    mm.insert(make_pair("C", 200));

    for(auto i = mm.begin(); i!=mm.end(); ++i){
        cout << "[" << i->first << " " << i->second << "]";
    }
    cout << endl;

    auto lo_bo = mm.lower_bound("C");
    auto up_bo = mm.upper_bound("C");

    cout << "key C의 value들: ";
    for (auto i = lo_bo; i != up_bo; ++i ){
        cout << i->second << " ";
    }
    cout <<endl;

    auto eq_ra = mm.equal_range("c");
    cout << "(또 다른 방법)key의 value 들: ";
    for (auto i = eq_ra.first; i != eq_ra.second; ++i){
        cout << i->second << "";
    }
    cout << endl;

    return 0;
}*/


//set
/*
#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    pair<set<int>::iterator, bool> pr;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    pr = s.insert(40);

    for(auto i = s.begin(); i != s.end(); ++i){
        cout << *i << " ";
    }
    cout << endl;

    s.insert(pr.first, 55);

    for(auto i = s.begin(); i != s.end(); ++i){
        cout << *i << " ";
    }
    cout << endl;

    auto f = s.find(55);
    if(f != s.end()){
        cout << *f << endl;
    }

    return 0;
}*/


//multiset
/*
#include <iostream>
#include <set>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    multiset<int> ms;
    multiset<int>::iterator ms_iter;
    ms.insert(10);
    ms.insert(30);
    ms.insert(60);
    ms.insert(20);
    ms.insert(50);
    ms.insert(40);
    ms_iter = ms.insert(40);



    for(auto i = ms.begin(); i != ms.end(); ++i){
        cout << *i << " ";
    }
    cout << endl;
    cout << "40 개수: " << ms.count(40) <<endl;
    auto f = ms.find(40);
    if (f != ms.end()){
        cout << *f << endl;
    }

    return 0;
}*/

//unordered_map
/*
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, int> um;
    um.insert({"A", 100});
    um.insert(make_pair("B",200));
    um.insert({
               {"C",1000},
               {"D",2000}
    });

    for(auto i = um.begin(); i != um.end(); ++i){
        cout << "[" << i->first << " " << i ->second << "]";
    }
    cout << endl;
    cout << "B의 값을 찾아보자."<<endl;
    auto bc = um.bucket("B");
    for(auto i = um.begin(); i != um.end(); ++i){
        cout << i->first << " " << i ->second << "]";
    }
    cout << endl;

    return 0;
}*/

//STL 배열 수정전
/*
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
    int arr[10] = {97,44,23,55,61,12,3,75,27,84};
    cout << "정렬된 배열: "

        sort(arr,arr+10);
    for(int i = 0; i<10;i++)
        cout << arr[i]<<" ";
    cout << "\n";

    vector<string> strings;
    string s;
    cout << "문자열을 입력하시요: ";
    while(cin<<s)
        strings.push_back(s);
    sort(strings.begin(),strings.end());
    cout << "정렬된 문자열: ";
    for (vector<string>::iterator it=strings.begin();it != strings.end(); ++i)
        cout << *it <<" ";
    cout <<"\n";

    return 0;
}*/


//STL 배열 수정 후
/*
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>  // for sort

using namespace std;

int main()
{
    int arr[10] = {97, 44, 23, 55, 61, 12, 3, 75, 27, 84};

    // Sorting array
    sort(arr, arr + 10);

    cout << "Sorted array: ";
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << "\n";

    // Input strings
    vector<string> strings;
    string s;

    cout << "Enter strings (Ctrl+D to end input on Linux/macOS, Ctrl+Z on Windows):" << endl;
    while (cin >> s)
        strings.push_back(s);

    // Sort strings
    sort(strings.begin(), strings.end());

    cout << "Sorted strings: ";
    for (vector<string>::iterator it = strings.begin(); it != strings.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    return 0;
}*/


//C++98 C++11
/*
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>  // for sort

using namespace std;

int main()
{
    int arr[5] = {0, 1, 2, 3, 4};

    // Print array elements
    cout << "Array elements:" << endl;
    for (int i : arr) {
        cout << i << endl;
    }

    // Copy array to vector
    vector<int> v(arr, arr + 5);

    // Print vector elements using const_iterator
    //cout << "Vector elements (using const_iterator):" << endl;
    //vector<int>::const_iterator it;
    //for (it = v.begin(); it != v.end(); ++it) {
    //    cout << *it << endl;
    //}

    for(auto i: v){
        cout << i << endl;
    }

    return 0;
}*/

//divide 예제  0넣으면 죽음 수정 본 필요
/*
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    int result;

    cout << "Performing a / b. Please enter a and b." << endl;

    cout << "a: ";
    cin >> a;  // 수정된 부분

    cout << "b: ";
    cin >> b;  // 수정된 부분

    // 예외 처리 없이 단순 계산 (0으로 나누면 런타임 에러 발생)
    result = a / b;
    cout << "The result of a / b is " << result << "." << endl;

    return 0;
}*/


//수정본
/*
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int a, b;

    cout << "Performing a / b. Please enter a and b." << endl;

    cout << "a: ";
    cin >> a;

    cout << "b: ";
    cin >> b;

    try {
        if (b == 0)
            throw runtime_error("Division by zero is not allowed.");

        int result = a / b;
        cout << "The result of a / b is " << result << "." << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}*/

/*
#include <iostream>
using namespace std;

int main(void)
{
    int num1, num2;
    cout << "두 개의 숫자 입력: ";
    cin >> num1 >> num2;

    try {
        if(num2==0)throw num2;
        cout << "나눗셈 몫: "<<num1/num2<<endl;
        cout << "나눗셈의 나머지: "<<num1%num2<<endl;
    }
    catch (int expn) {
        cout << "제수는 "<<expn<<"이 될 수 없습니다."<<endl;
        cout << "프로그램을 다시 실행 하시오."<<endl;
    }
    cout << "end of main"<<endl;
    return 0;
}*/


//catch문
/*수정전
#include <iostream>
using namespace std;

void inputName(char *name){
    cout << "이름을 입력하세요: ";
    if (strlen(name) <= 2)
        throw name;
}

int inputAge(){
    int age;
    cout << "나이를 입력하세요: ";
    cin >> age;
    if(age < 1)
        throw age;
    return age;
}

int main()
{
    char name[512];
    int age;

    try{
        inputName(name);
        inputAge();

        cout << "저의 이름은"<<name<<"입니다."<<endl;
        cout << "저의 나이는"<<age<<"입니다."<<endl;
    }
    catch(char* e){
        cout << "예외 발생.잘못된 이름 입력: "<<e<<'\n';
    }
    catch(int e){
        cout << "에외 발생.잘못된 나이 입력: "<<e<<'\n';

    return 0;
}*/


//수정 후
//#pragma warning (disable: 4290)
/*
#include <iostream>
#include <cstring>  // strlen 사용
using namespace std;

void inputName(char* name) {
    cout << "Enter your name: ";
    cin >> name;

    if (strlen(name) <= 2)
        throw name;  // 짧은 이름은 예외 처리
}

int inputAge() {
    int age;
    cout << "Enter your age: ";
    cin >> age;

    if (age < 1)
        throw age;  // 1세 미만은 예외 처리

    return age;
}

int main() {
    char name[512];
    int age;

    try {
        inputName(name);
        age = inputAge();  // 입력 결과를 변수에 저장

        cout << "My name is " << name << "." << endl;
        cout << "I am " << age << " years old." << endl;
    }
    catch (const char* e) {
        cout << "Exception: Invalid name entered: " << e << endl;
    }
    catch (int e) {
        cout << "Exception: Invalid age entered: " << e << endl;
    }

    return 0;
}*/

//수정전
//catch() 문법 오류 → 반드시 예외 타입을 명시해야 합니다 (catch(int) 또는 catch(...))
//f1()은 예외를 던지지만, main()의 첫 호출은 예외를 잡지 않아서 프로그램이 비정상 종료됩니다
//f2() 함수는 정의됐지만 main()에서 호출되지 않음
/*
#include <iostream>
using namespace std;

void handler(){
    cout << "in handler" <<endl;
}

void f1(void) noexcept(false){
    cout << "About th throw1" << endl;
    if(1)
        throw 1;
}

void f2(void) noexcept(false){
    try{
        f1();
    }
    catch(){
        handler();
    }
}

int main(){
    f1();

    try{
        f1();
    }
    catch(){
        cout << "Caught exception from f2" <<endl;
    }
}*/

//수정
/*
#include <iostream>
using namespace std;

void handler() {
    cout << "in handler" << endl;
}

void f1() noexcept(false) {
    cout << "About to throw 1" << endl;
    throw 1;  // int 타입 예외 던짐
}

void f2() noexcept(false) {
    try {
        f1();
    }
    catch (...) {  // 모든 타입의 예외를 잡음
        handler();
    }
}

int main() {
    try {
        f1();  // 예외 발생
    }
    catch (...) {
        cout << "Caught exception from first f1" << endl;
    }

    f2();  // f1() 호출 → 내부에서 handler() 호출

    try {
        f1();  // 다시 예외 발생
    }
    catch (...) {
        cout << "Caught exception from second f1" << endl;
    }

    return 0;
}*/

//예외 처리 예
/*
#include <iostream>
#include <exception>

using namespace std;

void MyErrorHandler()
{
    cout << "처리되지 않은 예외가 발생했습니다." << endl;
    exit(-1);
}

int main()
{
    set_terminate(MyErrorHandler);
    try{
        throw 1;
    }
    catch(char* const ex){
          //이 catch 절은 정수형 예외를 처리할 수 없음.
    }
    return 0;
}*/

//42
/*
#include <iostream>
using namespace std;

class MyException
{
    int myValue;
public:
    MyException(int value) {
        myValue = value;
    }
    void exceptionResult(){
        if(myValue<10)
            cout << "10이상의 값을 일력하세요"<<endl;
        else if (myValue>20)
            cout << "20이하의 값을 입력하세요"<<endl;
        else if (myValue % 7 != 0)
            cout <<"7의 배수 값을 입력하세요" <<endl;
    }
};

int main()
{
    int value;
    try {
        cout << "10과 20사이의 7의 배수를 입력하세요: ";
        cin >> value;
        if(value<10|value>20|value%7!=0)
            throw MyException(value);
        cout << "정답!! 10과 20사이의 7의 배수는"<<value<<"입니다."<<endl;    }
    catch (MyException &e) {
        e.exceptionResult();
    }
    return 0;
}*/

/*
#include <iostream>
using namespace std;

class MyException {
    int myValue;

public:
    MyException(int value) {
        myValue = value;
    }

    void exceptionResult() {
        cout << "Entered value: " << myValue << endl;

        if (myValue < 10)
            cout << " Please enter a value of 10 or more." << endl;
        else if (myValue > 20)
            cout << " Please enter a value of 20 or less." << endl;
        else if (myValue % 7 != 0)
            cout << " Please enter a multiple of 7." << endl;
    }
};

int main() {
    int value;

    try {
        cout << "Enter a multiple of 7 between 10 and 20: ";
        cin >> value;

        if (value < 10 || value > 20 || value % 7 != 0)
            throw MyException(value);

        cout << "Correct! " << value << " is a multiple of 7 between 10 and 20." << endl;
    }
    catch (MyException &e) {
        e.exceptionResult();
    }

    return 0;
}*/

//what() 가상함수 예제
/*
#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception {
    int myValue;
public:
    MyException(int value) {
        myValue = value;
    }

    virtual const char* what() const noexcept override {
        if (myValue < 10)
            return "Please enter a value of 10 or more.";
        else if (myValue > 20)
            return "Please enter a value of 20 or less.";
        else if (myValue % 7 != 0)
            return "Please enter a multiple of 7.";
        return "Invalid input.";
    }
};

int main() {
    int value;

    try {
        cout << "Enter a multiple of 7 between 10 and 20: ";
        cin >> value;

        if (value < 10 || value > 20 || value % 7 != 0)
            throw MyException(value);

        cout << "Correct! " << value << " is a multiple of 7 between 10 and 20." << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}*/

//stack unwinding
/*
#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "Constructor of A\n"; }
    ~A() { cout << "Destructor of A\n"; }
};

class B {
public:
    B() { cout << "Constructor of B\n"; }
    ~B() { cout << "Destructor of B\n"; }
};

void throwException() {
    A a;  // 지역 객체 A
    cout << "Throwing exception...\n";
    throw 42;  // 예외 발생
    cout << "This will not be printed\n";
}

int main() {
    try {
        B b;         // 지역 객체 B
        throwException();  // 함수 호출
    }
    catch (int e) {
        cout << "Caught exception: " << e << endl;
    }

    return 0;
}*/

//스택 퓰기(stack unwinding)2
/*
#include <iostream>
#include <exception>
using namespace std;

// 사용자 정의 예외 클래스
class MyException : public exception {
    int myValue; // 잘못된 입력 값을 저장
public:
    // 생성자에서 값 저장
    MyException(int value) : myValue(value) {}

    // 예외 메시지를 반환하는 함수
    virtual const char* what() const noexcept override {
        if (myValue < 10)
            return "Please enter a value of 10 or more."; // 10 미만일 경우
        else if (myValue > 20)
            return "Please enter a value of 20 or less."; // 20 초과일 경우
        else if (myValue % 7 != 0)
            return "Please enter a multiple of 7."; // 7의 배수가 아닐 경우
        return "Invalid input."; // 이론적으로 도달하지 않음
    }
};

// 사용자로부터 값을 입력받고 조건 검사하는 함수
int getMultiple() {
    int value;
    cout << "Enter a multiple of 7 between 10 and 20: ";
    cin >> value;

    // 조건에 맞지 않으면 예외 발생
    if (value < 10 || value > 20 || value % 7 != 0)
        throw MyException(value);

    return value; // 조건을 만족하면 값을 반환
}

// 메인 함수
int main() {
    try {
        // 사용자로부터 입력을 받고 조건 검사
        int value = getMultiple();
        cout << "Correct! " << value << " is a multiple of 7 between 10 and 20." << endl;
    }
    catch (exception& e) {
        // 예외 발생 시 메시지 출력
        cout << e.what() << endl;
    }

    return 0;
}*/


