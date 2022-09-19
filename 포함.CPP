#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

class DataType{
public:
    DataType() {}
    DataType(int n, const std::string& str) : nIndex_(n), strMsg_(str) {}
    bool operator<(const DataType& d) const { return nIndex_ < d.nIndex_; }
    std::string to_string() const {
        std::ostringstream oss;
        oss << nIndex_ << ',' << strMsg_;
        return oss.str();
    }
private:
    void init();
    int nIndex_ = 0;
    std::string strMsg_;
};

std::ostream& operator<<(std::ostream& os, const DataType& d)
{
    os << d.to_string();
    return os;
}

class DataSetType {
public:
    using value_type = DataType;
    using container_type = std::vector<value_type>;
    using size_type = container_type::size_type;

    DataSetType() {}
    explicit DataSetType(size_t n) : DataSet_(n) {}

    void addData(const DataType& data) { DataSet_.push_back(data); }
    void addData(DataType&& data) { DataSet_.emplace_back(data); }
    void addDataSet(const DataSetType& data) {
        std::copy(data.begin(), data.end(), std::back_inserter(DataSet_));
    }

    const DataType& operator[](size_t i) const { return DataSet_[i]; }
    DataType& operator[](size_t i) { return DataSet_[i]; }

    container_type::const_iterator begin() const { return DataSet_.cbegin(); }
    container_type::const_iterator end() const { return DataSet_.cend(); }

    container_type::iterator begin() { return DataSet_.begin(); }
    container_type::iterator end() { return DataSet_.end(); }

    void sort() {
        std::sort(DataSet_.begin(), DataSet_.end());
    }

    void print(std::ostream& os) {
        for (const auto& value: DataSet_) {
            os << value << std::endl;
        }
    }
private:
    container_type DataSet_;
};

using namespace std;

int main()
{
    DataSetType DataSet;
    DataSet.addData({5, "a"});
    DataSet.addData({1, "b"});
    DataSet.addData({3, "c"});

    cout << "DataSet initialized:" << endl;
    DataSet.print(cout);

    DataSetType DataSetTemp(3);
    DataSetTemp[0] = DataType {10, "d"};
    DataSetTemp[1] = DataType {7, "e"};
    DataSetTemp[2] = DataType {4, "f"};

    cout << "DataSetTemp initialized:" << endl;
    DataSetTemp.print(cout);

    DataSet.addDataSet(DataSetTemp);
    cout << "add DataSetTemp to DataSet:" << endl;
    DataSet.print(cout);

    DataSet.sort();
    cout << "sorted DataSet:" << endl;
    DataSet.print(cout);

    return EXIT_SUCCESS;
}