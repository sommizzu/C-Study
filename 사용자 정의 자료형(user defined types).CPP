enum {eID_NUM, eID_NAME};

enum class COLOR { RED, GREEN, BLUE };

class MyClassType {
  public:
    MyClass() = default;
    ~MyClass() = default;
    int nID_;
};

struct MyStructType {
  int nNumber;
  std::string strName;
};

MyClassType MyClass;
MyStructType MyStruct;
int nNumber = eID_NUM;
COLOR Color = COLOR::RED;