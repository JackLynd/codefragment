//结构体基础

#include <stdio.h>
#include <string.h>//stpcpy 复制串在其中

struct Student        //定义新数据类型 struct Student 
{
	int sid;
	char name[200];
	int age;
	
	
};                      //结构体声明，分号不能省

int main (void)
{
	struct Student st ={1000, "zhangsan", 20};
	printf("%d %s %d\n", st.sid, st.name, st.age);
	
/*	
	//第一种方式 每个名赋值
	st.sid =99;
//	st.name ="lisi";
strcpy(st.name, "lisi"); //c语言中，结构体中的字符串只能通过复制给值
	st.age = 22;
	
//		printf("%d %s %d\n", st); //error
		
	printf("%d %s %d\n", st.sid, st.name, st.age);//编译后再输入，会自动提示
	
	
*/	
	
//第二种 指针赋值

struct Student st = {1000, "zhangsan", 20};

struct Student * pst;
pst = &st;
pst->sid = 99;// 等价(*pst).sid
		//pst 所指向的结构体变量中的sid这个成员
	
	
	
	
	return 0;
}
