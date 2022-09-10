#include <iostream>
#include <vector>

int main()
{
    using Vec_INT = std::vector<int>;
    Vec_INT srcVec { 1,2,3,4,5 };
    Vec_INT& refVec = srcVec;
    std::printf("srcVec variable address:%p, element address in container:%p\n", &srcVec, &srcVec[0]);
    std::printf("refVec variable address:%p, element address in container:%p\n", &refVec, &refVec[0]);

    Vec_INT newVec = std::move(srcVec);
    std::printf("newVec variable address:%p, element address in container:%p\n", &newVec, &newVec[0]);
    std::printf("srcVec variable address:%p, element address in container:%p\n", &srcVec, &srcVec[0]);

    return 0;
}