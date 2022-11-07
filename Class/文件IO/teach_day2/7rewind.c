#include <stdio.h>
#include <string.h>

struct student
{
	char name[32];
	int id;
	int age;
};

int main()
{
	FILE *fp1;
	struct student stu2;
	struct student stu1 = {"rose", 2, 18};
	
	fp1 = fopen("student.txt","w+");//以读写方式打开一个文件
	if(fp1 == NULL)
	{
		perror("student.txt");
		return -1;
	}
	
	fwrite(&stu1, sizeof(stu1),1,fp1);//向文件中写入一个结构体变量
//	fseek(fp1,-sizeof(stu1),SEEK_END);//移动文件指针到文件开头
//	fseek(fp1,-sizeof(stu1),SEEK_CUR);//移动文件指针到文件开头
//	fseek(fp1,0,SEEK_SET);//移动文件指针到文件开头
	rewind(fp1);//等价于fseek(fp1,0,SEEK_SET)
	fread(&stu2,sizeof(stu2),1,fp1);//从文件中读数据到stu2中保存
//	fread(&stu2,36,1,fp1);//从文件中读数据为第2个和第3个参数的乘积
	printf("name: %s id = %d age = %d\n",stu2.name,stu2.id,stu2.age);//打印stu2里的数据
	return 0;
}
