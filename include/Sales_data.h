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

// struct Sales_data
class Sales_data
{
// 友元
friend Sales_data add(const Sales_data &, const Sales_data &);
friend std::ostream &printf(std::ostream &, const Sales_data &);
friend std::istream &read(std::istream &, Sales_data &);
public:
    Sales_data(std::istream &);
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data() = default;

    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

private:
    double avg_price() const { return units_sold ? revenue / units_sold : 0; }
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// Sales_data的非成员接口函数
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &printf(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

#endif // SALES_DATA_H