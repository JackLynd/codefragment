//动态内存分配     动态一维数组的实现     
//优点：避免了静态分配必须所在函数结束才能释放内存的缺点，有效利用硬件资源
# include <stdio.h>
# include <malloc.h>

int main (void)
{
	int a[5] = {4, 10, 2, 8, 6};
	
	int len;
	printf("请输入你需要分配的数组的长度：len= ");
	scanf("%d", &len);
	int * pArr = (int *)malloc(sizeof(int)*len);  //强制类型转换是为了将分配的空间以多少字节划分，从而使用
	*pArr = 4; //类似于 a[0]=4; 数组名即第一个数的地址
	pArr[1] = 10; //类似a[1] = 10;
	
//	printf("%d %d\n", *pArr, pArr[1]);  //可以把pArr作为普通数组使用
	for (int i=0; i<; ++i)             //c99才开始支持循环内定义变量
		scanf("%d", &pArr[i]);
	for (i=0; i<len;++i)              //Java内必须再次定义才能使用i变量
		printf("%d\n",*(pArr+i));
	
	
	free(pArr); //把所代表的动态分配内存释放
	
	return 0；
}
