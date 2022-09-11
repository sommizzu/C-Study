using size_t = unsigned int;
int fnSum(int* pValues, size_t nSize)
{
    int nSum = 0;
    for (size_t i = 0; i < nSize; nSum+=pValues[i++]);
    return nSum;
}

int main()
{
    int arrValues[] = {1,2,3,4,5};
    int nSum = fnSum(arrValues, 5);
}