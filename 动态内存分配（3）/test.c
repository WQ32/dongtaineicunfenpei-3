#include <stdio.h>

// 4-29

////realloc函数
//
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 0;
//	}
//	//使用
//	//扩大内存
//	int* p2 = realloc(p, 80);
//	if (p2 != NULL)
//	{
//		p = p2;
//	}
//	//使用
//	//释放内存
//	free(p);
//	p = NULL;
//	int* p = realloc(NULL, 40);  //与 malloc(40)有相同的结果
//
//	return 0;
//}


//常见错误
#include <errno.h>

int main()
{
	//// 1.对NULL指针解引用操作
	//int* p1 = (int*)malloc(40);
	//*p1 = 10;
	//// 未对p进行判断（看是否是空指针），如果malloc开辟空间失败，
	//// p就是NULL，于是就是对NULL解引用

	//// 2.对动态开辟的空间越界访问
	//int* p2 = (int*)malloc(40);
	//if (p == NULL)
	//{
	//	return 0;
	//}
	//else
	//{
	//	int i = 0;
	//	for (i = 0; i <= 10; i++)
	//	{
	//		*(p + i) = i;     //一共就开辟了10个空间，这里要访问11个空间
	//	}
	//}
	//free(p2);
	//p2 = NULL;
	
	//// 3.对非动态开辟内存使用free释放
	//int a = 10;
	//int* p3 = &a;
	//free(p3);
	//p3 = NULL;
	////这里建立a变量是在栈开辟的空间，动态开辟的空间在堆，
	////非动态开辟的内存不能使用free释放

	//// 4.使用free释放动态开辟内存的一部分
	//int* p4 = (int*)malloc(40);
	//if (p4 != NULL)
	//{
	//	return 0;
	//}
	//else
	//{
	//	int i = 0;
	//	for (i = 0; i < 10; i++)
	//	{
	//		*p4++ = i;
	//		// 这里是将0-9个元素放到了已经开辟好的空间，但p会向后访问，
	//		// p指向的位置发生变化
	//	}
	//}
	//free(p4);
	//p4 = NULL;
	//// 这里释放的是p指针指向的位置向后的内存，前面的内存并没有被释放

	//// 5.对同一块动态内存的多次释放

	//int* p5 = (int*)malloc(40);
	//if (p5 == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//}
	//////使用
	////free(p);
	//////使用
	////free(p);    // error
	////这里两次调用free函数，进行了多此释放
	////解决方法：释放了空间，就将其赋为 NULL
	//free(p5);
	//p5 = NULL;

	//// 6.动态开辟内存忘记释放（内存泄漏）
	//while (1)
	//{
	//	malloc(1);   // 崩溃
	//}
	return 0;
}

//几个典型的笔试题

////1.
//
//#include <stdlib.h>
// #include <string.h>
//
////void GetMemory(char* p)
////{
////	p = (char*)malloc(100);
////	//这里是将在堆中开辟的空间的地址赋给 p
////}
////
////void Test(void)
////{
////	char* str = NULL;
////	GetMemory(str);
////	strcpy(str, "hello world");  
////	//1.运行代码程序会出现崩溃的现象 - 将一个值赋给了空指针 - NULL，这里的str还是起初定义的str
////	printf(str);
////	//2.程序存在内存泄漏问题  - 见下：
////	// str 以值传递的方式给 p - str是值，&str才是地址
////	// p是GetMemory函数的形参，只能函数内部有效
////	// 等GetMemory函数返回之后，动态开辟内存尚未释放，并且无法打开（地址找不到了）
////}
//
//////改正1 ：
////
////void GetMemory(char** p)
////{
////	*p = (char*)malloc(40);
////}
////void Test(viod)
////{
////	char* str = NULL;
////	GetMemory(&str);
////	strcpy(str, "hello world");
////	printf(str);
////	free(str);
////	str = NULL;
////}
//
//////改正2 ：
////
////char* GetMemory(char* p)
////{
////	p = (char*)malloc(40);
////	return p;
////}
////void Test(viod)
////{
////	char* str = NULL;
////	str = GetMemory(str);
////	strcpy(str, "hello world");
////	printf(str);
////	free(str);
////	str = NULL;
////}
//
//int main()
//{
//	Test();
//	//说明
//	/*char* str = "abcdef";
//	printf("%s\n", str);
//	printf(str);
//	printf("abcdef");*/
//	//上面三者打印都相同
//	return 0;
//}
