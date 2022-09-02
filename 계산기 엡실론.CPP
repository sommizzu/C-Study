#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

int main()
{
    double ex, g = 1, eps;

    try {
        do{
            g = g / 2;
            ex = g * 0.98 + 1;
            ex = ex - 1;
            printf( "g = %.14e\tex = %.14e\n", g, ex );
            if ( ex > 0 ) eps = ex;
        }
        while ( ex > 0 );

        printf( "\nmachine epsilon = %.14e\n", eps);
        printf( "\nnumeric_limits::epsilon = %.14e\n", numeric_limits<double>::epsilon() );
    }
    catch (const exception &error) {
        cerr << error.what() << endl;
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}