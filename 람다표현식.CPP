#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    auto f = [](int val, int n)->int {
                int sum = 0;
                for(int i = 0; i < n; i++, sum+=val);
                return sum;
            };

    cout << f(100, 5) << endl;
    return EXIT_SUCCESS;
}