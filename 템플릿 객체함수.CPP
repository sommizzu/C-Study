#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <list>

//  Print Container Element
template <typename T> inline void DataPrint (const T& coll, const char* str="")
{
    typename T::const_iterator pos;
    std::cout << str;
    for (pos=coll.begin(); pos!=coll.end(); ++pos)
        std::cout << *pos << ' ';
    std::cout << std::endl;
}

// Template function object
template <typename T>
class ValueAdd
{
private:
    T value;
public:
    //초기값을 갖는 생성자
    ValueAdd(const T &v) : value(v){}
    //()를 overloading하여 각 원소에 value를 더함
    void operator() (T & elem) const {
        elem += value;
    }
};

int main()
{
    using namespace std;
    list<double> nList;

    double dblInvalue = 0.;
    cout << "Enter the number (floating type) : ";
    cin >> dblInvalue;

    for( int i = 0 ; i < 10 ; ++i )
        nList.push_back(i);

    DataPrint (nList, "Befor adding each element : ");
    // 각 원소에 입력된 값을 더함.
    for_each (nList.begin(), nList.end(), ValueAdd<double>(dblInvalue));
    DataPrint (nList, "After adding each element : ");
    return EXIT_SUCCESS;
}