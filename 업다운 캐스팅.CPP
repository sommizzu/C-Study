#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <vector>
#include <typeinfo>
#include <algorithm>

class Base {
public:
    using value_type = std::string;
    virtual ~Base() {}
    void init(const value_type& data) { Data_ = data; }

    virtual std::string to_string() const {
        std::ostringstream oss;
        oss << Data_;
        return oss.str();
    }
private:
    value_type Data_;
};

class Derived : public Base {
public:
    using value_type = std::vector<std::string>;
    ~Derived() {}
    void init(const value_type& data) { Data_ = data; }

    std::string to_string() const {
        std::ostringstream oss;
        std::copy(Data_.begin(), Data_.end(), std::ostream_iterator<std::string>(oss, " "));
        return oss.str();
    }
private:
    value_type Data_;
};

std::ostream& operator<<(std::ostream& os, const Base& pData) {
    os << pData.to_string();
    return os;
}

using namespace std;

int main()
{
    // upcasting
    shared_ptr<Base> pData (new Derived);

    if (typeid(*pData) == typeid(Base)) {
        pData->init(Base::value_type{"ABC"});
    }
    else if (typeid(*pData) == typeid(Derived)) {
        // downcasting
        dynamic_pointer_cast<Derived>(pData)->init(Derived::value_type{"ABC", "DEF", "GHI"});
    }
    cout << *pData << endl;
}