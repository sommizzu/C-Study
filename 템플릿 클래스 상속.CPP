#include <bits/stdc++.h>

template<typename T>
class Base {
public:
    Base(const T& val_base)
        : val_base_(val_base) {}
    virtual ~Base() {}
    virtual const T& get() const {
        return val_base_;
    }
protected:
    T val_base_;
};

template<typename T, typename U>
class Derived : public Base<T> {
public:
    Derived(const T& val_base, const U& val_derived)
        : Base<T>(val_base), val_derived_(val_derived) {}
    ~Derived() {}
    const T& get() const override {
        return Base<T>::get();
    }
    const std::pair<T, U> get_pair() const {
        return std::make_pair(Base<T>::val_base_, val_derived_);
    }
private:
    U val_derived_;
};

using namespace std;

int main()
{
    shared_ptr<Base<double>> data(new Derived<double, string>(M_PI, "ABC"));
    cout << "data->get() : " << data->get() << endl;

    auto p = dynamic_pointer_cast<Derived<double, string>>(data);
    cout << "p->get() : " << p->get() << endl;
    cout << "p->get_pair().first : " << p->get_pair().first << endl;
    cout << "p->get_pair().second : " << p->get_pair().second << endl;
}