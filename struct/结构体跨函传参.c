//结构体跨函传递值

struct Student
{
		int sid;
		char name[200];
		int age;
};                                     //分号不能省

void f(struct Student * pst)
void g(struct Student st)

int main()
{
	struct Student st;
	
	
	f(&st);
	g(st);
	
	
	
	return 0;
}

void g(struct Student st)       //这种方式耗内存，耗时间，不推荐
{
	printf("%d %s %d\n". st.sid, st.name, st.age);
	
}

void f(struct Student * pst)
{
	printf("%d %s %d\n", pst->sid, pst->name, (*pst).age);
	
}

