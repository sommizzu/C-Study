#include iostream
#include functional

#if (__cplusplus  201700)  before c++17
templatetypename T
T sum(T first) {
  return first;
}

templatetypename T, typename... Args
T sum(T first, Args... args) {
  return first + sum(args...);
}
#else  since c++17
templatetypename... Args
auto sum(Args... args)
{
    return (args + ...);
}
#endif

using namespace std;

int main()
{
    cout  sum(1,2,3,4,5,6)  endl;

    functionint(int) fn1 = sumint;
    cout  fn1(1)  endl;

    functionint(int, int, int, int) fn2 = sumint, int, int, int;
    cout  fn2(1,2,3,4)  endl;

    return EXIT_SUCCESS;
}