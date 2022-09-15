#include iostream

struct DataType1 {
    char c[10];
    double d;
    int n;
};

struct DataType2 {
    int n;
    char c[10];
    double d;
};

int main()
{
    stdprintf(%ldn, sizeof(DataType1));
    stdprintf(%ldn, sizeof(DataType2));
}