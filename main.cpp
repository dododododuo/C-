#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

typedef struct person
{
    int patientsNum;
    char patientsName[10];
    char admissionTime[12];
    char nativePlace[20];
    int age;
    char patientsSituation[20];
    char changeTime [20];
    int flag;           //flag  1——现存  2——痊愈  3——死亡
}patients;

typedef struct link
{
    patients p;
    struct link *next;
}Node;

void write(Node *head){
   Node *temp = head->next;
   ofstream out;
   out.open("date.txt", ios::out);
   out.clear();
   while(temp){
      if(temp->p.flag == 1){
               out<<temp->p.flag<<" ";
               out<<temp->p.patientsNum<<" ";
               out<<temp->p.patientsName<<" ";
               out<<temp->p.admissionTime<<" ";
               out<<temp->p.nativePlace<<" ";
               out<<temp->p.age<<" ";
               out<<temp->p.patientsSituation<<endl;
      }else{
               out<<temp->p.flag<<" ";
               out<<temp->p.patientsNum<<" ";
               out<<temp->p.patientsName<<" ";
               out<<temp->p.admissionTime<<" ";
               out<<temp->p.nativePlace<<" ";
               out<<temp->p.age<<" ";
               out<<temp->p.patientsSituation<<" ";
               out<<temp->p.changeTime<<endl;
      }
      temp = temp->next;

   }
   out.close();

}


void exitSystem(Node *head)
{
    printf("是否现在退出系统？请输入Y/N：");
        char c;
        getchar();
        scanf("%c",&c);
        if(c =='Y'||c =='y')
        {
             write(head);

            exit(0);
        }

        else if(c =='n'||c =='N')
        {
            printf("即将返回主菜单\n");

            return;
        }
        else
        {
            printf("输入有误，即将返回主菜单\n");

            return;
        }
}

//-------------------------------建表
Node *creatHead()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head ->next = NULL;
    return head;
}

//-------------------------------新建结点
void creatPatients(Node *head)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode ->next = head ->next;
    head ->next = newnode;
    printf("请输入病人编号：");
    scanf("%d",&newnode ->p.patientsNum);
    printf("请输入病人名字：");
    scanf("%s",newnode ->p.patientsName);
    printf("请输入入院时间：");
    scanf("%s",newnode ->p.admissionTime);
    printf("请输入病人籍贯：");
    scanf("%s",newnode ->p.nativePlace);
    printf("请输入病人年龄：");
    scanf("%d",&newnode ->p.age);
    printf("请输入病人的病情现状：");
    scanf("%s",newnode ->p.patientsSituation);
    newnode ->p.flag = 1;
}

//-------------------------------打印表
void showPatients(Node *head,int n)
{
    Node *temp = head->next;

    printf("\t病人号码\t病人名\t入院时间  \t籍贯\t\t\t年龄\t病情现状\t痊愈或死亡时间\n");
    while(temp)
    {
        if((temp ->p.flag == n && n ==1) ||(n == 4 && temp ->p.flag == 1))
        {
            printf("\t%-8d\t%-6s\t%-10s\t%-20s\t%-2d  \t%-16s\n",temp ->p.patientsNum,temp ->p.patientsName,temp ->p.admissionTime,temp ->p.nativePlace,temp ->p.age,temp ->p.patientsSituation);

        }
        else if((temp ->p.flag == n && n ==2)||(n == 4 && temp ->p.flag == 2))
        {

            printf("\t%-8d\t%-6s\t%-10s\t%-20s\t%-2d  \t已痊愈\t\t%-10s\n",temp ->p.patientsNum,temp ->p.patientsName,temp ->p.admissionTime,temp ->p.nativePlace,temp ->p.age,temp ->p.changeTime);

        }
        else if((temp ->p.flag == n && n ==3) || (n == 4 && temp ->p.flag == 3))
        {
            printf("\t%-8d\t%-6s\t%-10s\t%-20s\t%-2d  \t已死亡\t\t%-10s\n",temp ->p.patientsNum,temp ->p.patientsName,temp ->p.admissionTime,temp ->p.nativePlace,temp ->p.age,temp ->p.changeTime);

        }
        temp = temp ->next;
    }

}

//-------------------------------打印菜单
void Menu()
{
    printf("====================【医院新冠状肺炎病人管理系统】====================\n");
    printf("\t  \t\t0.所有病人信息\n");
    printf("\t  \t\t1.现存病人信息\n");
    printf("\t  \t\t2.痊愈和死亡病人信息\n");
    printf("\t  \t\t3.查询病人信息\n");
    printf("\t  \t\t4.删除病人信息\n");
    printf("\t  \t\t5.增加病人信息\n");
    printf("\t  \t\t6.现存病人病情信息修改\n");
    printf("\t  \t\t7.退出系统\n");
    printf("======================================================================\n");

}

//-------------------------------查找病人
Node *findPatients(Node *head,int num)
{
    Node *temp = head ->next;
    while(temp)
    {
        if(temp->p.patientsNum == num)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//-------------------------------更新病情
void updatePatients(Node *head)
{
    printf("请输入需要修改病人编号：");
    int num;
    scanf("%d",&num);
    Node *temp = findPatients(head,num);
    if(temp)
    {
        printf("病人%s记录病情为：%s\n请输入该病人最新病情:",temp ->p.patientsName,temp ->p.patientsSituation);
        char sit [20];
        scanf("%s",sit);
        if(strcmp(sit,"已痊愈") == 0)
        {
            temp ->p.flag = 2;

            strcpy(temp ->p.patientsSituation,sit);
            printf("请输入痊愈时间：");
            scanf("%s",temp ->p.changeTime);
        }
        else if(strcmp(sit,"已死亡") == 0)
        {
            temp ->p.flag = 3;

            strcpy(temp ->p.patientsSituation,sit);
            printf("请输入死亡时间：");
            scanf("%s",temp ->p.changeTime);
        }
        else strcpy(temp ->p.patientsSituation,sit);

    }
    else printf("未找到病人信息，即将返回主菜单\n");
}

//-------------------------------删除信息
void deletePatients(Node *head)
{
        printf("==================================================删除病人信息==================================================\n");
        printf("请输入您需要删除的病人编号：\n");
        int n;
        scanf("%d",&n);
        Node *temp = findPatients(head,n);
        if(temp == NULL )
        {
            printf("未找到该病人信息，即将返回主菜单\n");
            return ;
        }
        else
        {
        printf("您确定要删除病人%s的信息？请输入Y/N：",temp ->p.patientsName);
        char c;
        getchar();
        scanf("%c",&c);
        if(c =='n'||c == 'N')
        {
            printf("即将返回主菜单\n");
            return ;
        }
        else if(c =='y'||c == 'Y')
        {
            if(temp ->next == NULL)
            {
                free(temp);
            }

            else
            {
                temp ->p = temp ->next->p;
                temp ->next = temp ->next->next;

            }
            printf("删除成功，即将返回主菜单\n");

        }
        else if(c !='n'&&c != 'N'&&c !='y'&&c != 'Y')
        {
            printf("输入有误，即将返回主菜单\n");
            return ;
        }
        }

}


//-------------------------------键入选项
void keyInput(Node *head)
{
    int temp;
    printf("请输入您需要操作的序号：\n");
    scanf("%d",&temp);

    switch(temp)
    {
    case 0:

        printf("==================================================所有病人信息==================================================\n");
        showPatients(head,4);
        system("pause");
        break;
    case 1:

        printf("==================================================现存病人信息==================================================\n");
        showPatients(head,1);
        system("pause");
        break;
    case 2:
        printf("==================================================痊愈病人信息==================================================\n");
        showPatients(head,2);
        printf("==================================================死亡病人信息==================================================\n");
        showPatients(head,3);
        system("pause");
        break;
    case 3:
        {
        printf("==================================================查询病人信息==================================================\n");
        printf("请输入病人编号：");
        int n;
        scanf("%d",&n);
        Node *temp = findPatients(head,n);
        printf("以下为编号%d的病人住院信息\n",temp ->p.patientsNum);
        printf("病人姓名：%s\n",temp ->p.patientsName);
        printf("病人入院时间：%s\n",temp ->p.admissionTime);
        printf("病人籍贯：%s\n",temp ->p.nativePlace);
        printf("病人年龄：%d\n",temp ->p.age);
        printf("病人病情：%s\n",temp ->p.patientsSituation);


        if(temp ->p.flag == 1){}
        else if(temp ->p.flag == 2)printf("痊愈时间为：%s\n",temp ->p.changeTime);

        else if(temp ->p.flag == 3)printf("死亡时间为：%s\n",temp ->p.changeTime);

        }
        system("pause");
        break;
    case 4:
        deletePatients(head);
        system("pause");
        break;
    case 5:
        printf("==================================================增添病人信息==================================================\n");
        creatPatients(head);
        system("pause");
        break;
    case 6:
        printf("=================================================现存病人病情修改=================================================\n");
        updatePatients(head);
        system("pause");
        break;
    case 7:
        exitSystem(head);
        system("pause");
        break ;
    default:
        printf("输入格式有误，请重新输入!\n");
        system("pause");
        break ;
    }
}

void read(Node *head)
{

  ifstream infile;
  infile.open("date.txt",ios::in);
  if(!infile)
  {
     cout<<"打开文件失败！"<<"TEST.txt"<<endl;
  }

    int x;
    while(infile >> x) //可以像用cin那样用ifstream对象
        {
            Node *newnode = (Node*)malloc(sizeof(Node));
            newnode ->next = head ->next;
            head ->next = newnode;
            if(x == 1){
               newnode->p.flag = 1;
               infile>>newnode->p.patientsNum;
               infile>>newnode->p.patientsName;
               infile>>newnode->p.admissionTime;
               infile>>newnode->p.nativePlace;
               infile>>newnode->p.age;
               infile>>newnode->p.patientsSituation;
            }else{
               newnode->p.flag = x;
               infile>>newnode->p.patientsNum;
               infile>>newnode->p.patientsName;
               infile>>newnode->p.admissionTime;
               infile>>newnode->p.nativePlace;
               infile>>newnode->p.age;
               infile>>newnode->p.patientsSituation;
               infile>>newnode->p.changeTime;
            }
        }
        infile.close();

}
int main()
{
    Node *head = creatHead();
    read(head);
    while(1)
    {
    Menu();
    keyInput(head);
    system("cls");
    }
    return 0;
}
