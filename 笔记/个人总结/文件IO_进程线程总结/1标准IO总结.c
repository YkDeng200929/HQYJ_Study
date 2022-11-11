#include <stdio.h>

// 标准IO: 通过文件流指针打开关闭和读写文件

int main(void)
{
	FILE *fp = NULL;
	fp = fopen("hello.txt", "r+");
	char ch;

	// 1. 从文件流中得到单个字符
	ch = fgetc(fp);

	// 2. 将字符写入文件流
	fputc('a', fp);

	// 3. fgets(读行)把从文件流中获取的字符串写入一个缓存数组中, 最多只能读取字符长度-1个字符, 读到EOF或换行符时终止
	char buf[10] = {0};
	fgets(buf, sizeof(buf), fp);
	printf("已经从文件流中获得字符串: %s\n", buf);

	// 4. fputs(写行)把 缓存数组中的字符串写入 文件流
	fputs(buf, fp);

	//5. fwrite(把对象写入流) 得有个结构体
	struct number
	{
		int data;
	};
	struct number num1 = {20};
	fwrite(&num1, sizeof(num1), 1, fp);
	// 参数说明(<你要给的对象在哪里>,  <对象的体积有多大>,  <对象的数量>, <你要把对象给谁>)

	// !!! 当你写完一个对象时, 光标在文件流的末尾, 所以需要把光标重新放到最前面
	fseek(fp, 0, SEEK_SET);

	//6. fread 从文件中读取对象到另一个对象
	struct number num2;
	fread(&num2, 4, 1, fp);
	printf("num2 data: %d\n", num2.data);

	//7. 定位文件
	// fseek(stream, offset, whence)
	// ftell(stream) 直接定位到尾部
	// rewind(stream) 直接定位到头部(rewind又称倒带)

	//8. 关闭流指针
	fclose(fp);

	return 0;
}
