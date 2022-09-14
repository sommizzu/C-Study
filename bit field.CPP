#include <iostream>
struct S {
 unsigned int b : 2;
};
int main()
{
    S s = {2};
    ++s.b;
    printf("%d\n", s.b);
    ++s.b;
    printf("%d\n", s.b);
}