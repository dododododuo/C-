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
    int flag;           //flag  1�����ִ�  2����Ȭ��  3��������
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
    printf("�Ƿ������˳�ϵͳ��������Y/N��");
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
            printf("�����������˵�\n");

            return;
        }
        else
        {
            printf("�������󣬼����������˵�\n");

            return;
        }
}

//-------------------------------����
Node *creatHead()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head ->next = NULL;
    return head;
}

//-------------------------------�½����
void creatPatients(Node *head)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode ->next = head ->next;
    head ->next = newnode;
    printf("�����벡�˱�ţ�");
    scanf("%d",&newnode ->p.patientsNum);
    printf("�����벡�����֣�");
    scanf("%s",newnode ->p.patientsName);
    printf("��������Ժʱ�䣺");
    scanf("%s",newnode ->p.admissionTime);
    printf("�����벡�˼��᣺");
    scanf("%s",newnode ->p.nativePlace);
    printf("�����벡�����䣺");
    scanf("%d",&newnode ->p.age);
    printf("�����벡�˵Ĳ�����״��");
    scanf("%s",newnode ->p.patientsSituation);
    newnode ->p.flag = 1;
}

//-------------------------------��ӡ��
void showPatients(Node *head,int n)
{
    Node *temp = head->next;

    printf("\t���˺���\t������\t��Ժʱ��  \t����\t\t\t����\t������״\tȬ��������ʱ��\n");
    while(temp)
    {
        if((temp ->p.flag == n && n ==1) ||(n == 4 && temp ->p.flag == 1))
        {
            printf("\t%-8d\t%-6s\t%-10s\t%-20s\t%-2d  \t%-16s\n",temp ->p.patientsNum,temp ->p.patientsName,temp ->p.admissionTime,temp ->p.nativePlace,temp ->p.age,temp ->p.patientsSituation);

        }
        else if((temp ->p.flag == n && n ==2)||(n == 4 && temp ->p.flag == 2))
        {

            printf("\t%-8d\t%-6s\t%-10s\t%-20s\t%-2d  \t��Ȭ��\t\t%-10s\n",temp ->p.patientsNum,temp ->p.patientsName,temp ->p.admissionTime,temp ->p.nativePlace,temp ->p.age,temp ->p.changeTime);

        }
        else if((temp ->p.flag == n && n ==3) || (n == 4 && temp ->p.flag == 3))
        {
            printf("\t%-8d\t%-6s\t%-10s\t%-20s\t%-2d  \t������\t\t%-10s\n",temp ->p.patientsNum,temp ->p.patientsName,temp ->p.admissionTime,temp ->p.nativePlace,temp ->p.age,temp ->p.changeTime);

        }
        temp = temp ->next;
    }

}

//-------------------------------��ӡ�˵�
void Menu()
{
    printf("====================��ҽԺ�¹�״���ײ��˹���ϵͳ��====================\n");
    printf("\t  \t\t0.���в�����Ϣ\n");
    printf("\t  \t\t1.�ִ没����Ϣ\n");
    printf("\t  \t\t2.Ȭ��������������Ϣ\n");
    printf("\t  \t\t3.��ѯ������Ϣ\n");
    printf("\t  \t\t4.ɾ��������Ϣ\n");
    printf("\t  \t\t5.���Ӳ�����Ϣ\n");
    printf("\t  \t\t6.�ִ没�˲�����Ϣ�޸�\n");
    printf("\t  \t\t7.�˳�ϵͳ\n");
    printf("======================================================================\n");

}

//-------------------------------���Ҳ���
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

//-------------------------------���²���
void updatePatients(Node *head)
{
    printf("��������Ҫ�޸Ĳ��˱�ţ�");
    int num;
    scanf("%d",&num);
    Node *temp = findPatients(head,num);
    if(temp)
    {
        printf("����%s��¼����Ϊ��%s\n������ò������²���:",temp ->p.patientsName,temp ->p.patientsSituation);
        char sit [20];
        scanf("%s",sit);
        if(strcmp(sit,"��Ȭ��") == 0)
        {
            temp ->p.flag = 2;

            strcpy(temp ->p.patientsSituation,sit);
            printf("������Ȭ��ʱ�䣺");
            scanf("%s",temp ->p.changeTime);
        }
        else if(strcmp(sit,"������") == 0)
        {
            temp ->p.flag = 3;

            strcpy(temp ->p.patientsSituation,sit);
            printf("����������ʱ�䣺");
            scanf("%s",temp ->p.changeTime);
        }
        else strcpy(temp ->p.patientsSituation,sit);

    }
    else printf("δ�ҵ�������Ϣ�������������˵�\n");
}

//-------------------------------ɾ����Ϣ
void deletePatients(Node *head)
{
        printf("==================================================ɾ��������Ϣ==================================================\n");
        printf("����������Ҫɾ���Ĳ��˱�ţ�\n");
        int n;
        scanf("%d",&n);
        Node *temp = findPatients(head,n);
        if(temp == NULL )
        {
            printf("δ�ҵ��ò�����Ϣ�������������˵�\n");
            return ;
        }
        else
        {
        printf("��ȷ��Ҫɾ������%s����Ϣ��������Y/N��",temp ->p.patientsName);
        char c;
        getchar();
        scanf("%c",&c);
        if(c =='n'||c == 'N')
        {
            printf("�����������˵�\n");
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
            printf("ɾ���ɹ��������������˵�\n");

        }
        else if(c !='n'&&c != 'N'&&c !='y'&&c != 'Y')
        {
            printf("�������󣬼����������˵�\n");
            return ;
        }
        }

}


//-------------------------------����ѡ��
void keyInput(Node *head)
{
    int temp;
    printf("����������Ҫ��������ţ�\n");
    scanf("%d",&temp);

    switch(temp)
    {
    case 0:

        printf("==================================================���в�����Ϣ==================================================\n");
        showPatients(head,4);
        system("pause");
        break;
    case 1:

        printf("==================================================�ִ没����Ϣ==================================================\n");
        showPatients(head,1);
        system("pause");
        break;
    case 2:
        printf("==================================================Ȭ��������Ϣ==================================================\n");
        showPatients(head,2);
        printf("==================================================����������Ϣ==================================================\n");
        showPatients(head,3);
        system("pause");
        break;
    case 3:
        {
        printf("==================================================��ѯ������Ϣ==================================================\n");
        printf("�����벡�˱�ţ�");
        int n;
        scanf("%d",&n);
        Node *temp = findPatients(head,n);
        printf("����Ϊ���%d�Ĳ���סԺ��Ϣ\n",temp ->p.patientsNum);
        printf("����������%s\n",temp ->p.patientsName);
        printf("������Ժʱ�䣺%s\n",temp ->p.admissionTime);
        printf("���˼��᣺%s\n",temp ->p.nativePlace);
        printf("�������䣺%d\n",temp ->p.age);
        printf("���˲��飺%s\n",temp ->p.patientsSituation);


        if(temp ->p.flag == 1){}
        else if(temp ->p.flag == 2)printf("Ȭ��ʱ��Ϊ��%s\n",temp ->p.changeTime);

        else if(temp ->p.flag == 3)printf("����ʱ��Ϊ��%s\n",temp ->p.changeTime);

        }
        system("pause");
        break;
    case 4:
        deletePatients(head);
        system("pause");
        break;
    case 5:
        printf("==================================================��������Ϣ==================================================\n");
        creatPatients(head);
        system("pause");
        break;
    case 6:
        printf("=================================================�ִ没�˲����޸�=================================================\n");
        updatePatients(head);
        system("pause");
        break;
    case 7:
        exitSystem(head);
        system("pause");
        break ;
    default:
        printf("�����ʽ��������������!\n");
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
     cout<<"���ļ�ʧ�ܣ�"<<"TEST.txt"<<endl;
  }

    int x;
    while(infile >> x) //��������cin������ifstream����
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
