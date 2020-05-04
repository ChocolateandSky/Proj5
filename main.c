#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#include<string.h> 
int count = 0;
void menu() {      //菜单函数 
	printf("------------[会员卡信息管理系统]-----------\n");
	printf("\t\t1.录入信息\n");
	printf("\t\t2.浏览信息\n");
	printf("\t\t3.删除信息\n");
	printf("\t\t4.修改信息\n");
	printf("\t\t5.按学号查找学生信息\n");
	printf("\t\t6.按姓名查找学生信息\n");
	printf("\t\t0.退出系统\n");
	printf("\t\t0.退出系统\n");
	printf("--------------------------------------------\n");
}
struct student    // 学生信息结构类型定义 
{
	int num[20];/*学号*/
	char name[25];/*姓名*/
	char sex[10];/*性别*/
	int age;/*年龄*/
	char addr[50];/*籍贯*/
	char dept[50]; /*系别*/
	char major[30]; /*专业*/
	char classs[30]; /*班级*/
	char phone[20];/*电话*/
};
void new_student(struct student stundent[]);    //学生学籍录入函数声明 
void output_student(struct student stundent[]);    //信息浏览函数声明 
int update_student(struct student *p, int num, int course, double x);    //信息修改函数声明 
void del_student(struct student stundent[], int num);   //信息删除函数声明 
int main(void)    //主函数 
{
	int num, n;
	int course, pos;
	double x;
	menu();            //菜单函数 
	int choice;
	struct student stundent[MAX]; //定义学生学籍信息结构数组
	do {
		scanf("%d", &choice);
		switch (choice) {
		case 1:printf("----------【录入信息】----------\n");
			new_student(student);  //调用函数 
			menu();
			break;
		case 2:printf("----------【浏览信息]-----------\n");
			output_student(student);  //调用函数 
			menu();
			break;
		case 3:printf("----------【删除信息】----------\n");
			del_student(student, num);   //调用函数 
			menu();
			break;
		case 4:printf("----------【修改信息】----------\n");
			printf("请输入需要修改的编号:\n");
			scanf("%d", &num);
			printf("请选择修改内容：1.学号 2.姓名 3.性别 4.出生日期 5.年龄 6.籍贯 7.系别 8.专业 9.班级 10.电话\n");
			scanf("%d", &course);
			printf("请输入要修改的信息:\n");
			scanf("%lf", &x);
			pos = update_student(student, num, course, x);   //调用函数 
			printf("修改结束！");
			menu();
			break;
		case 0:printf("----------【退出系统】----------\n");
			break;
		default:
			printf("选择错误，重新输入\n");
			system("pause");
			break;
		}
	} while (choice != 0);
	printf("END!\n");
	return 0;
}
void new_student(struct student student[])  //信息录入函数 
{
	FILE *fp;   //定义文件指针 
	struct student s;
	fp = fopen("D:\\student.txt", "ab");
	if ((fp = fopen("D:\\student.txt", "ab")) == NULL)  //打开文件 
		printf("文件打开错误！\n");
	else {
		printf("请输入学生学号：");     //输入信息 
		scanf("%d", &s.num);
		printf("请输入学生姓名：");
		scanf("%s", s.name);
		printf("请输入学生性别：");
		scanf("%s", s.sex);
		printf("请输入学生年龄：");
		scanf("%s", s.age);
		printf("请输入学生籍贯：");
		scanf("%s", &s.addr);
		printf("请输入学生系别：");
		scanf("%s", &s.dept);
		printf("请输入学生专业：");
		scanf("%s", &s.major);
		printf("请输入学生班级：");
		scanf("%s", s.classs);
		printf("请输入学生电话:");
		scanf("%s", s.phone)
			fprintf(fp, "%d  %s  %s  %d %s  %s  %s %s %s\n", s.num, s.name, s.sex, s.age, s.addr, s.dept, s.majoy, s.classs, s.phone);  //将数据写入文件 
		printf("输入成功！\n");
	}
	student[count] = s;
	count++;  //学生学籍信息+1 
}
void output_student(struct student student[])  //信息浏览函数 
{
	int i;
	if (count == 0)  //判断是否有学生学籍信息 
	{
		printf(" 学生学籍信息为0 !\n");
		return;
	}
	for (i = 0; i < count; i++)   //根据学生学籍信息数量逐个显示 
	{
		printf("学生学号:%d\n", student[i].num);
		printf("学生姓名:%s\n", student[i].name);
		printf("学生性别:%s\n", student[i].sex);
		printf("学生年龄:%d\n", student[i].age);
		printf("学生籍贯:%s\n", student[i].addr);
		printf("学生系别:%s\n", student[i].dept);
		printf("学生专业:%s\n", student[i].major);
		printf("学生班级:%s\n", student[i].classs);
		printf("学生电话:%s\n", student[i].phone);
	}
}
int update_student(struct student *p, int num, int course, double x)    //定义修改函数 
{
	int i, pos;
	for (i = 0; i < count; i++, p++)
		if (p->num == num)
			break;
	if (i < count)                      //找到位置 
	{
		switch (course) {
		case 1: p->num = x;    break;
		case 2: p->name = x;   break;
		case 3: p->sex = x;   break;
		case 4: p->age = x;    break;
		case 5: p->addr = x;    break;
		case 6: p->dept = x;    break;
		case 7: p->major = x;    break;
		case 8: p->classs = x;    break;
		case 9: p->phone = x;    break;
		}
		pos = i;          //被修学生学籍信息在数组的下标 
	}
	else
		pos == -1;

	return pos;
}
void del_student(struct student student[], int num)  //定义删除函数 
{
	int i;
	printf("请输入要删除的学生学号：");
	scanf("%d", &num);
	for (i = 0; i < count; i++)        //利用for循环找到位置 
	{
		if (student[i].num == num)
			break;
	}
	student[i] = student[count + 1];        //利用覆盖删除信息 
	printf("删除成功！\n");
}
