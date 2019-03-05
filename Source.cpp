#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MyVector.h"

using namespace std;


void test1()
{

	MyVector<int> myVector1(10);

	for (int i = 0; i < 10; i++)
	{
		myVector1[i] = 10 + i;
	}

	cout << "vector1" << endl;
	cout << myVector1 << endl;


	MyVector<int> myVector2(myVector1); // 拷贝构造
	//等价于 MyVector<int> myBector2 = myVector1 (在初始化的时候使用=

	cout << "vector2" << endl;
	cout << myVector2 << endl;

	MyVector<int> myVector3;
	myVector3 = myVector2; // 调用类的=号操作符

	cout << "vector3" << endl;
	cout << myVector3 << endl;
}


void test2()
{

	MyVector<char> myVector1(10);

	for (int i = 0; i < 10; i++)
	{
		myVector1[i] = 'a' + i;
	}

	cout << "vector1" << endl;
	cout << myVector1 << endl;


	MyVector<char> myVector2(myVector1); // 拷贝构造
	//等价于 MyVector<int> myBector2 = myVector1 (在初始化的时候使用=

	cout << "vector2" << endl;
	cout << myVector2 << endl;

	MyVector<char> myVector3;
	myVector3 = myVector2; // 调用类的=号操作符

	cout << "vector3" << endl;

}

int main(void)
{


	test2();

	return 0;

}