#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
class convert{
    protected:
    T val1;
    T val2;

    public:
    convert(T val1) : val1(val1) {}
    virtual ~convert() = default;

    virtual void compute() = 0;
    T getconverted(){
        return this->val2;
    }
};

template<typename T> 
class l_to_g : public convert<T> {

    public:
    l_to_g(T val1) : convert<T>(val1) {}
    ~l_to_g() = default;

    void compute() override {
        this->val2 = this->val1 * 0.264172;
    }
};

template <typename T>
class f_to_c : public convert<T>{

    public:
    f_to_c(T val1) : convert<T>(val1) {}
    ~f_to_c() = default;

    void compute() override {
        this->val2 = (this->val1 - 32) / 1.8;
    }
};

int main(){
    convert<double>* c1;
    convert<double>* c2;  

    c1 = new l_to_g<double>(4.0);
    c2 = new f_to_c<double>(70.0);

    c1->compute();
    c2->compute();

    cout << "4 litres is equal to: " << c1->getconverted() << endl;
    cout << "70 fehrenheit to celsius " << c2->getconverted() << endl;
}
