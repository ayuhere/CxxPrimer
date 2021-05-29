/*
* 数据抽象：依赖于接口和实现分离的编程技术
* 封装  
* 继承 
* 多态
*/

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

// class Sales_data
// {
// public:
//     std::string ();  // 返回对象的ISBN编号
//     Sales_data& combine(Sales_data&);  // 将另一个Sales_data对象加到另一个对象上
//     void add(Sales_data&);  // 执行两个Sales_data对象的加法
//     void read(std::istream &);  // 将数据从istream读入到Sales_data对象中
//     void print();  // 将Sales_data对象的值输出到ostream
// private:
//     std::string ISBN;
// };

struct Sales_data
{
    // 构造函数
    Sales_data(istream &);
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data() = default;
    // 成员函数
    /*
     * 1. 放在成员函数参数列表后的const的函数称为常量成员函数，表示this指向常量，即不能在函数内部修改对象
     * 2. 编译器首先编译成员的声明，再编译成员函数体
     * 3. this是一个常量指针
     * 
    */
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;
    // 数据成员
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// Sales_data的非成员接口函数
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &printf(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

#endif // SALES_DATA_H