#include <stdio.h>

// 4-29

////realloc����
//
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 0;
//	}
//	//ʹ��
//	//�����ڴ�
//	int* p2 = realloc(p, 80);
//	if (p2 != NULL)
//	{
//		p = p2;
//	}
//	//ʹ��
//	//�ͷ��ڴ�
//	free(p);
//	p = NULL;
//	int* p = realloc(NULL, 40);  //�� malloc(40)����ͬ�Ľ��
//
//	return 0;
//}


//��������
#include <errno.h>

int main()
{
	//// 1.��NULLָ������ò���
	//int* p1 = (int*)malloc(40);
	//*p1 = 10;
	//// δ��p�����жϣ����Ƿ��ǿ�ָ�룩�����malloc���ٿռ�ʧ�ܣ�
	//// p����NULL�����Ǿ��Ƕ�NULL������

	//// 2.�Զ�̬���ٵĿռ�Խ�����
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
	//		*(p + i) = i;     //һ���Ϳ�����10���ռ䣬����Ҫ����11���ռ�
	//	}
	//}
	//free(p2);
	//p2 = NULL;
	
	//// 3.�ԷǶ�̬�����ڴ�ʹ��free�ͷ�
	//int a = 10;
	//int* p3 = &a;
	//free(p3);
	//p3 = NULL;
	////���ｨ��a��������ջ���ٵĿռ䣬��̬���ٵĿռ��ڶѣ�
	////�Ƕ�̬���ٵ��ڴ治��ʹ��free�ͷ�

	//// 4.ʹ��free�ͷŶ�̬�����ڴ��һ����
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
	//		// �����ǽ�0-9��Ԫ�طŵ����Ѿ����ٺõĿռ䣬��p�������ʣ�
	//		// pָ���λ�÷����仯
	//	}
	//}
	//free(p4);
	//p4 = NULL;
	//// �����ͷŵ���pָ��ָ���λ�������ڴ棬ǰ����ڴ沢û�б��ͷ�

	//// 5.��ͬһ�鶯̬�ڴ�Ķ���ͷ�

	//int* p5 = (int*)malloc(40);
	//if (p5 == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//}
	//////ʹ��
	////free(p);
	//////ʹ��
	////free(p);    // error
	////�������ε���free�����������˶���ͷ�
	////����������ͷ��˿ռ䣬�ͽ��丳Ϊ NULL
	//free(p5);
	//p5 = NULL;

	//// 6.��̬�����ڴ������ͷţ��ڴ�й©��
	//while (1)
	//{
	//	malloc(1);   // ����
	//}
	return 0;
}

//�������͵ı�����

////1.
//
//#include <stdlib.h>
// #include <string.h>
//
////void GetMemory(char* p)
////{
////	p = (char*)malloc(100);
////	//�����ǽ��ڶ��п��ٵĿռ�ĵ�ַ���� p
////}
////
////void Test(void)
////{
////	char* str = NULL;
////	GetMemory(str);
////	strcpy(str, "hello world");  
////	//1.���д���������ֱ��������� - ��һ��ֵ�����˿�ָ�� - NULL�������str������������str
////	printf(str);
////	//2.��������ڴ�й©����  - ���£�
////	// str ��ֵ���ݵķ�ʽ�� p - str��ֵ��&str���ǵ�ַ
////	// p��GetMemory�������βΣ�ֻ�ܺ����ڲ���Ч
////	// ��GetMemory��������֮�󣬶�̬�����ڴ���δ�ͷţ������޷��򿪣���ַ�Ҳ����ˣ�
////}
//
//////����1 ��
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
//////����2 ��
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
//	//˵��
//	/*char* str = "abcdef";
//	printf("%s\n", str);
//	printf(str);
//	printf("abcdef");*/
//	//�������ߴ�ӡ����ͬ
//	return 0;
//}
