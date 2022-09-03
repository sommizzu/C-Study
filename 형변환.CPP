#include <iostream>
using namespace std;
int main()
{
    double dValue = 3.141592;
    int nValue = 0;
    nValue = static_cast<int>(dValue);

    printf("%lf\n", dValue);
    printf("%d\n", nValue);

    size_t unValue = 0x0102030405060708;
    short sValue = 0;
    sValue = static_cast<short>(unValue);

    printf("%016lx\n", unValue);
    printf("%x\n", sValue);
    return EXIT_SUCCESS;
}