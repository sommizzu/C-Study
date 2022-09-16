#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <stdexcept>

class Algorithm {
public:
    enum class SORT_MODE { DESCEND, ASCEND };
    template <typename Container>
    static void sort(Container& c, const SORT_MODE& mode ) {
        typedef typename Container::value_type value_type;
        switch (mode) {
            case SORT_MODE::DESCEND:
                std::sort(begin(c), end(c), std::greater<value_type>());
                break;
            case SORT_MODE::ASCEND:
                std::sort(begin(c), end(c), std::less<value_type>());
                break;
            default:
                throw std::domain_error("error:sort mode");
        }
        nUsed++;
    }

    static size_t nUsed;
};

size_t Algorithm::nUsed = 0;

using namespace std;

int main()
{
    try {
        vector<int> vecInt = {2,3,1,6,7,4,2,4,3,2};
        Algorithm::sort(vecInt, Algorithm::SORT_MODE::ASCEND);

        for (const auto& e: vecInt) cout << e << ' ';
        cout << endl;

        Algorithm::sort(vecInt, Algorithm::SORT_MODE::DESCEND);
        for (const auto& e: vecInt) cout << e << ' ';
        cout << endl;

        cout << "to be called Algorithms: " << Algorithm::nUsed << endl;
    }
    catch(const exception& error) {
        cerr << "Exception caught:" << error.what() << endl;
        exit(EXIT_FAILURE);
    }
    catch(...) {
        cerr << "Unknown exception caught." << endl;
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}