#include <iostream>
using namespace std;
int main()
{
    constexpr size_t row = 4;
    constexpr size_t col = 5;
    // 다중 포인터로 정의하고 row 크기로 할당
    int** pMatrix = new int*[row];
    // 첫번째 위치에 사용할 공간을 row * col로 1차원 공간으로 할당
    pMatrix[0] = new int[row*col];
    // 각 행에 해당하는 row의 주소를 계산하여 저장
    for (size_t r = 1; r < row; r++) {
        pMatrix[r] = pMatrix[r-1] + col;
    }

    for (size_t r = 0; r < row; r++)
        for (size_t c = 0; c < col; c++)
            // operator[] 를 사용할 수 있으므로 2차원 배열 사용과 동일
            pMatrix[r][c] = r*col+c;

    for (size_t r = 0; r < row; r++) {
        for (size_t c = 0; c < col; c++) {
            printf("%d\t", pMatrix[r][c]);
        }
        printf("\n");
    }
    // 할당 받은 자원 해제
    if (pMatrix != nullptr) {
            delete [] pMatrix[0];
            delete [] pMatrix;
    }

    return 0;
}