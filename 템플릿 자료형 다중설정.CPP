#include <bits/stdc++.h>

template<typename Key, typename T>
struct PairType {
    Key key;
    T value;
    std::string to_string() const {
        std::ostringstream oss;
        oss << key << ',' << value;
        return oss.str();
    }
};

template <typename Key, typename T>
std::ostream& operator<<(std::ostream&os, const PairType<Key,T>& Pair) {
    os << Pair.to_string();
    return os;
}

using namespace std;

int main()
{
    PairType<std::string, double> Pair{"AAA", 1.234};
    cout << Pair << endl;
}