#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#include<string.h> 
int count = 0;
void menu() {      //�˵����� 
	printf("------------[��Ա����Ϣ����ϵͳ]-----------\n");
	printf("\t\t1.¼����Ϣ\n");
	printf("\t\t2.�����Ϣ\n");
	printf("\t\t3.ɾ����Ϣ\n");
	printf("\t\t4.�޸���Ϣ\n");
	printf("\t\t5.��ѧ�Ų���ѧ����Ϣ\n");
	printf("\t\t6.����������ѧ����Ϣ\n");
	printf("\t\t0.�˳�ϵͳ\n");
	printf("\t\t0.�˳�ϵͳ\n");
	printf("--------------------------------------------\n");
}
struct student    // ѧ����Ϣ�ṹ���Ͷ��� 
{
	int num[20];/*ѧ��*/
	char name[25];/*����*/
	char sex[10];/*�Ա�*/
	int age;/*����*/
	char addr[50];/*����*/
	char dept[50]; /*ϵ��*/
	char major[30]; /*רҵ*/
	char classs[30]; /*�༶*/
	char phone[20];/*�绰*/
};
void new_student(struct student stundent[]);    //ѧ��ѧ��¼�뺯������ 
void output_student(struct student stundent[]);    //��Ϣ����������� 
int update_student(struct student *p, int num, int course, double x);    //��Ϣ�޸ĺ������� 
void del_student(struct student stundent[], int num);   //��Ϣɾ���������� 
int main(void)    //������ 
{
	int num, n;
	int course, pos;
	double x;
	menu();            //�˵����� 
	int choice;
	struct student stundent[MAX]; //����ѧ��ѧ����Ϣ�ṹ����
	do {
		scanf("%d", &choice);
		switch (choice) {
		case 1:printf("----------��¼����Ϣ��----------\n");
			new_student(student);  //���ú��� 
			menu();
			break;
		case 2:printf("----------�������Ϣ]-----------\n");
			output_student(student);  //���ú��� 
			menu();
			break;
		case 3:printf("----------��ɾ����Ϣ��----------\n");
			del_student(student, num);   //���ú��� 
			menu();
			break;
		case 4:printf("----------���޸���Ϣ��----------\n");
			printf("��������Ҫ�޸ĵı��:\n");
			scanf("%d", &num);
			printf("��ѡ���޸����ݣ�1.ѧ�� 2.���� 3.�Ա� 4.�������� 5.���� 6.���� 7.ϵ�� 8.רҵ 9.�༶ 10.�绰\n");
			scanf("%d", &course);
			printf("������Ҫ�޸ĵ���Ϣ:\n");
			scanf("%lf", &x);
			pos = update_student(student, num, course, x);   //���ú��� 
			printf("�޸Ľ�����");
			menu();
			break;
		case 0:printf("----------���˳�ϵͳ��----------\n");
			break;
		default:
			printf("ѡ�������������\n");
			system("pause");
			break;
		}
	} while (choice != 0);
	printf("END!\n");
	return 0;
}
void new_student(struct student student[])  //��Ϣ¼�뺯�� 
{
	FILE *fp;   //�����ļ�ָ�� 
	struct student s;
	fp = fopen("D:\\student.txt", "ab");
	if ((fp = fopen("D:\\student.txt", "ab")) == NULL)  //���ļ� 
		printf("�ļ��򿪴���\n");
	else {
		printf("������ѧ��ѧ�ţ�");     //������Ϣ 
		scanf("%d", &s.num);
		printf("������ѧ��������");
		scanf("%s", s.name);
		printf("������ѧ���Ա�");
		scanf("%s", s.sex);
		printf("������ѧ�����䣺");
		scanf("%s", s.age);
		printf("������ѧ�����᣺");
		scanf("%s", &s.addr);
		printf("������ѧ��ϵ��");
		scanf("%s", &s.dept);
		printf("������ѧ��רҵ��");
		scanf("%s", &s.major);
		printf("������ѧ���༶��");
		scanf("%s", s.classs);
		printf("������ѧ���绰:");
		scanf("%s", s.phone)
			fprintf(fp, "%d  %s  %s  %d %s  %s  %s %s %s\n", s.num, s.name, s.sex, s.age, s.addr, s.dept, s.majoy, s.classs, s.phone);  //������д���ļ� 
		printf("����ɹ���\n");
	}
	student[count] = s;
	count++;  //ѧ��ѧ����Ϣ+1 
}
void output_student(struct student student[])  //��Ϣ������� 
{
	int i;
	if (count == 0)  //�ж��Ƿ���ѧ��ѧ����Ϣ 
	{
		printf(" ѧ��ѧ����ϢΪ0 !\n");
		return;
	}
	for (i = 0; i < count; i++)   //����ѧ��ѧ����Ϣ���������ʾ 
	{
		printf("ѧ��ѧ��:%d\n", student[i].num);
		printf("ѧ������:%s\n", student[i].name);
		printf("ѧ���Ա�:%s\n", student[i].sex);
		printf("ѧ������:%d\n", student[i].age);
		printf("ѧ������:%s\n", student[i].addr);
		printf("ѧ��ϵ��:%s\n", student[i].dept);
		printf("ѧ��רҵ:%s\n", student[i].major);
		printf("ѧ���༶:%s\n", student[i].classs);
		printf("ѧ���绰:%s\n", student[i].phone);
	}
}
int update_student(struct student *p, int num, int course, double x)    //�����޸ĺ��� 
{
	int i, pos;
	for (i = 0; i < count; i++, p++)
		if (p->num == num)
			break;
	if (i < count)                      //�ҵ�λ�� 
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
		pos = i;          //����ѧ��ѧ����Ϣ��������±� 
	}
	else
		pos == -1;

	return pos;
}
void del_student(struct student student[], int num)  //����ɾ������ 
{
	int i;
	printf("������Ҫɾ����ѧ��ѧ�ţ�");
	scanf("%d", &num);
	for (i = 0; i < count; i++)        //����forѭ���ҵ�λ�� 
	{
		if (student[i].num == num)
			break;
	}
	student[i] = student[count + 1];        //���ø���ɾ����Ϣ 
	printf("ɾ���ɹ���\n");
}
