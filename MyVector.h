#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


// 自定义一个模板数组类
// 1 该数组能够存放int,double 还有自定义类型
// 2 重载[]操作符: array[i] = ??? ; array[i]
// 3 重载<<操作符: cout << array
// 4 重载拷贝构造函数: array1 = array2 // 初始化时进行赋值调用的是拷贝构造函数
// 5 重载拷贝构造函数: array1(array2) // 拷贝构造函数
// 6 重载等号操作符: array[i] = array[j]


template <class T>
class MyVector
{
public:

	// 注意这里必须要加friend 本质相当于在这里声明 然后再外面定义的传统写法，只是把声明和定义放到一起写了，
	// 不要和 操作符重载(成员函数) 弄混， 如果去掉friend 会被编译器认为是操作符重载(成员函数) 双目运算符应当只传一个参数
	friend ostream & operator << (ostream &os, MyVector<T> &v)
	{
		for (int i = 0; i < v.len; i++)
		{
			os << v[i] << " ";
		}
		return os;
	}


	// 无参的构造
	MyVector();

	// 有参构造
	MyVector(int num); // num代表整个数组在初始化的时候连续开辟多少个元素

	// 拷贝构造函数
	MyVector(const MyVector & v);

	// 析构函数
	~MyVector();

	// 重载[]操作符
	T & operator[](int index);

	// 重载等号操作符
	// array1 = array2 = array3
	MyVector & operator=(const MyVector &v);


private:
	// 数组长度
	T len;
	// 内存空间地址
	T * space;
};



// 实现拷贝构造函数
template <class T>
MyVector<T>::MyVector(const MyVector & v)
{
	this->len = v.len;
	this->space = new T[this->len];

	// copy数组中每一个元素
	for (int i = 0; i < this->len; i++)
	{
		this->space[i] = v.space[i]; // Teacher1 = teacher2 // 如果存放对象 那么对象应该实现 深拷贝
	}
}


// 实现无参构造函数
template <class T>
MyVector<T>::MyVector()
{
	len = 0;
	this->space = NULL;
}


// 实现有参构造函数
template <class T>
MyVector<T>::MyVector(int num)
{
	len = num;
	// 在堆上连续开辟sizeof(T)*num大小的空间
	this->space = new T[num];
}

// 实现等号操作符重载
template <class T>
MyVector<T> & MyVector<T>::operator=(const MyVector &v)
{
	if (this->space != NULL)
	{
		// 存在之前的旧数据 需要清理
		delete[] this->space;
		this->space = NULL;
		this->len = 0;
	}

	this->len = v.len;
	this->space = new T[this->len];// 深拷贝动作

	// copy数据
	for (int i = 0; i < this->len; i++)
	{
		this->space[i] = v.space[i];
	}

	return *this;
}


// 析构函数重写
template <class T>
MyVector<T>::~MyVector()
{
	if (this->space != NULL) {
		delete[] this->space;
		this->len = 0;
	}
}

// []操作符重载
template <class T>
T & MyVector<T>::operator[](int index)
{
	return this->space[index];
}


// 重写 输出操作符
//template <class T>
//ostream & operator << (ostream &os, MyVector<T> &v)
//{
//	for (int i = 0; i < v.len; i++)
//	{
//		cout << v[i] << " ";
//	}
//
//
//
//	return os;
//}