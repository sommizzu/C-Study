#include <iostream>
#include <typeinfo>

using namespace std;

template <typename T> T fnSquare(const T& a) {
    return a*a;
}

template <typename Container> void fnPrintContainer(const Container& container) {
    for (const auto& element: container) std::cout << element << std::endl;
}

template <typename T1, typename T2> T1 fnDivid(const T2& a, const T2& b) {
    return static_cast<T1>(a)/static_cast<T1>(b);
}

template <typename T, size_t N = 2> T fnPower(const T& a) { 
    T rst = 1;
    for (size_t i = 0; i < N; i++, rst*=a);
    return rst;
}

int main()
{
    // 인수로 입력된 값의 자료형으로 template의 자료형을 결정한다.
    auto v1 = fnSquare(5);
    cout << v1 << ',' << typeid(v1).name() << endl;
    // template 자료형을 명시적으로 지정한다.
    auto v2 = fnSquare<double>(5);
    cout << v2 << ',' << typeid(v2).name() << endl;
    // template 자료형을 명시적으로 지정한다.
    cout << fnDivid<double, int>( 3, 5) << endl;
    // template에 기본값이 있는 경우 값을 넣지 않아도 된다.
    cout << fnPower<int>(5) << endl;
    cout << fnPower<int, 3>(5) << endl;
}