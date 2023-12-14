#include <iostream>
/**
 * 运算符重载demo
 * */
using namespace std;

class MyInt {
    //运算符重载常常需要访问类的私有变量，需要申请友元（又称友元重载）
//    friend MyInt operator+(const MyInt &a, const MyInt &b);
    friend ostream &operator<<(ostream &out, const MyInt &a);

private:
    int val;
public:
    explicit MyInt(int val) : val(val) {}

    /**
     * 成员函数重载 参数个数比操作数个数少一个
     * 第一个参数用this指针替换
     * 这里的+作为二元运算符使用
     * */
    MyInt operator+(const MyInt &b) const {
        return MyInt(this->val + b.val);
    }

    /**
     * 这里的‘-’作为一元运算符使用
     * */
    MyInt operator-() const {
        return MyInt(-this->val);
    }

    /**
     * 这里的‘-’作为二元运算符使用
     * */
    MyInt operator-(const int b) const {
        return MyInt(this->val - b);
    }

    /**
     * 重载自增运算符（前缀）
     * 自增后返回this对象的引用即可
     * */
    MyInt &operator++() {
        this->val++;
        return *this;
    }

    /**
     * 重载自增运算符（后缀）
     * 参数int不用传，仅仅是为了区分前缀与后缀重载
     * 自增后返回原始值的副本
     * */
    MyInt operator++(int) {
        MyInt tmp = *this;
        this->val++;
        return tmp;
    }

    /**
     * 重载赋值运算符‘=’\n
     * C++编译器会生成一个默认的赋值运算符重载 \n
     * ‘=’必须作为成员函数重载 \n
     * 返回值必须是this对象的引用 \n
     * 注意与复制构造函数区分，适用于不创建新对象的场景
     * */
    MyInt &operator=(const int b) {
        cout << "assignment operator\t";
        this->val = b;
        return *this;
    }

    /**
     * 复制构造函数
     * 适用于创建新对象的场景
     * */
    MyInt(MyInt &o) : val(o.val) {
        cout << "copy constructor" << endl;
    }

    /**
     * 定义转换操作符 \n
     * 1.必须是成员函数
     * 2.没有返回值
     * 3.参数列表为空
     * */
    operator int() {
        cout << "MyInt to int" << endl;
        return this->val;
    }

    /**
     * 非explicit构造函数加上自定义转换操作符
     * 可实现如Java自动装箱功能
     * MyInt a = 1;
     * */
    //MyInt(int v) : val(v) {}


};

//MyInt operator+(const MyInt &a, const MyInt &b) {
//    return MyInt(a.val + b.val);
//}

/**
 * 重载左移运算符，无法作为成员函数修改，因为要重载就要修改标准库
 * */
ostream &operator<<(ostream &out, const MyInt &a) {
    out << a.val;
    return out;
}

int main() {
    MyInt a(3), b(4);
    cout << "a+b:" << a + b << endl;
    //相当于执行
    operator<<(cout, a.operator+(b)).operator<<(endl);

    int c = 5;
    cout << "b-c:" << b - c << endl;
    cout << "c++:" << c++ << endl;
    cout << "++c:" << ++c << endl;

    b = 8;
    cout << b << endl;

    MyInt d = a; //创建了新对象d
    cout << d << endl;

    int i = d;
    cout << "i:" << i << endl;
    return 0;
}