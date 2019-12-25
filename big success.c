#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 5
struct students
{
    char name[100];
    int score[N+1];
    char abc;
}stu[2000];
void function (struct students stu[],int *p);
void new      (struct students stu[],int *p);
void delete   (struct students stu[],int *p);
void show     (struct students stu[],int *p);
void calculate(struct students stu[],int *p);
void rank     (struct students stu[],int *p);
void search   (struct students stu[],int *p);
void diagram  (struct students stu[],int *p);
int main()
{
    int i,n=0,m;
    printf("name grades of Clanguage Math English Art History in order\nif there is no student left, enter 0\n");
    gets(stu[n].name);
    while(stu[n].name[0]!='0')
    {
        for(i=0;i<N;i++)
        scanf("%d",&stu[n].score[i]);
        getchar();
        printf("name grades of Clanguage Math English Art History in order\nif there is no student left, enter 0\n");
        n++;
        gets(stu[n].name);
    }
    show(stu,&n);
    function(stu,&n);
    return 0;
}
void function (struct students stu[],int *p)
{
    int m;
    printf("1-new 2-delete 3-show 4-calculate 5-rank 6-search 7-diagram 8-break\n");
    scanf("%d",&m);
    switch(m){
    case 1:       new(stu,p);break;
    case 2:    delete(stu,p);break;
    case 3:      show(stu,p);break;
    case 4: calculate(stu,p);break;
    case 5:      rank(stu,p);break;
    case 6:    search(stu,p);break;
    case 7:   diagram(stu,p);break;
    defult:   printf("thanks bye");exit(0);
    }
        function(stu,p);
}
void new (struct students stu[],int *p)
{
    int i;
    printf("name grades of Clanguage Math English Art History in order\nif there is no student left, enter 0\n");
    getchar();
    gets(stu[*p].name);
    while(stu[*p].name[0]!='0')
    {
        for(i=0;i<N;i++)
        scanf("%d",&stu[*p].score[i]);
        getchar();
        printf("name grades of Clanguage Math English Art History in order\nif there is no student left, enter 0\n");
        (*p)++;
        gets(stu[*p].name);
    }
    show(stu,p);
    function(stu,p);
}

void delete   (struct students stu[],int *p)
{
    char name[100];
    int i,q;
    printf("name, if there're no left, enter 0\n");
    getchar();
    gets(name);
    while(name[0]!='0')
    {
    for(q=0;q<*p;q++)
    {
        if(strcmp(stu[q].name,name)==0)
        break;
    }
    for(i=q;i<*p;i++)
    {
        stu[i]=stu[i+1];
    }
    (*p)--;
    gets(name);
    }
    show(stu,p);
    function(stu,p);
}

void show     (struct students stu[],int *p)
{
     int q,i,sum=0;
     printf("name\tClanguage  Math   English Art  History  rank\n");
     for(q=0;stu[q].name[0]!='0';q++)
    {
        sum=0;
        printf("%s\t",stu[q].name);
        for(i=0;i<N;i++)
        {
            printf("%7d",stu[q].score[i]);
            sum+=stu[q].score[i];
        }
        if(sum>=450)
            stu[q].abc='A';
        else if(sum>=300)
            stu[q].abc='B';
        else
            stu[q].abc='C';
        printf("%7c\n",stu[q].abc);
    }
    function(stu,p);
}
void calculate(struct students stu[],int *p)
{
    void calculate_student(struct students stu[],int *p);
    void calculate_subject(struct students stu[],int *p,int option);
    int m;
    printf("0-Clanguage 1-Math 2-English 3-Art 4-History 5-average student grades 6-return \n");
    scanf("%d",&m);
    switch(m){
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:calculate_subject(stu,p,m);break;
    case 5:calculate_student(stu,p);break;
    case 6:calculate(stu,p);break;
    defult:break;
    }
    function(stu,p);
}
void calculate_subject(struct students stu[],int *p,int option)
{
    int q;
    double ave=0;
    for(q=0;q<*p;q++)
    ave+=stu[q].score[option];
    ave/=*p;
    printf("%.2f",ave);
    printf("\n");
    function(stu,p);
}
void calculate_student(struct students stu[],int *p)
{
    int i,q;
    double sum=0;
    char name[100];
    printf("enter student's name\n");
    getchar();
    gets(name);
    for(i=0;i<*p;i++)
    if(strcmp(name,stu[i].name)==0)
    {
        for(q=0;q<N;q++)
        sum=sum + stu[i].score[q];
        sum/=N;
        printf("%.2f",sum);
        printf("\n");
    }
    function(stu,p);
}

void rank (struct students stu[],int *p)
{
    void rank_name  (struct students stu[],int *p);
    void rank_score (struct students stu[],int *p,int n);
    void rank_average (struct students stu[],int *p);
    printf("relate to which kind of scores?:\n0-Clanguage 1-Math 2-English 3-Art 4-History 5-average\nrelate to name?-6\n");
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:rank_score  (stu,p,n);break;
        case 5:rank_average(stu,p);break;
        case 6:rank_name   (stu,p);break;
        default:break;
    }
}
void rank_name  (struct students stu[],int *p)
{

    struct students kstu;
   int i,q,j,time=1;
   for(j=1;time!=0;j++)
   {
       time=0;
        for(i=0;i<*p-j;i++)
        if(strcmp(stu[i].name,stu[i+1].name)>0)
    {
        kstu=stu[i];
        stu[i]=stu[i+1];
        stu[i+1]=kstu;
        time++;
    }
   }
    show(stu,p);
    function(stu,p);
}
void rank_score (struct students stu[],int *p,int n)
{

    struct students kstu;
   int i,q,j,time=1;
   for(j=1;time!=0;j++)
   {
       time=0;
        for(i=0;i<*p-j;i++)
        if(stu[i].score[n]<stu[i+1].score[n])
    {
        kstu=stu[i];
        stu[i]=stu[i+1];
        stu[i+1]=kstu;
        time++;
    }
   }
    show(stu,p);
    function(stu,p);
}
void rank_average (struct students stu[],int *p)
{
    int i,q,j,time=1,sum=0;
    for(i=0;i<*p;i++)
    {
        sum=0;
        for(j=0;j<5;j++)
        sum+=stu[i].score[j];
        sum/=5;
        stu[i].score[j]=sum;
    }
    struct students kstu;

    for(j=1;time!=0;j++)
    {
        time=0;
        for(i=0;i<*p-j;i++)
        if(stu[i].score[5]<stu[i+1].score[5])
    {
        kstu=stu[i];
        stu[i]=stu[i+1];
        stu[i+1]=kstu;
        time++;
    }
   }
    show(stu,p);
    function(stu,p);
}

void search(struct students stu[],int *p)
{
    int i,q;
    char name[100];
    printf("enter student's name\n");
    getchar();
    gets(name);
    printf("name  Clanguage Math  English  Art  History    rank\n");
    printf("%s",name);
    for(i=0;i<*p;i++)
    {
        if(strcmp(name,stu[i].name)==0)
    {
        for(q=0;q<N;q++)
        printf("%8d",stu[i].score[q]);
        printf("%8c\n",stu[i].abc);
        break;
    }
    }
        if(i==*p)
        printf("Not Found\n");
    function(stu,p);
}
void diagram  (struct students stu[],int *p)
{
    printf("name, if there're no left, enter 0\n");

    char name[100];
    int i,j,m,sum=0;
    getchar();
    gets(name);
    while(name[0]!='0')
    {
    sum=0;
    for(m=0;m<*p;m++)
    if(strcmp(name,stu[m].name)==0)
    break;
    char dia[4][7]={' ','C','M','E','A','H','R'};
    dia[1][0]='A';
    dia[2][0]='B';
    dia[3][0]='C';
    for(i=1;i<6;i++)
    {
    if(stu[m].score[i-1]>=90)
    dia[1][i]='*';
    else if(stu[m].score[i-1]>=60)
    dia[2][i]='*';
    else
    dia[3][i]='*';
    sum+=stu[m].score[i-1];
    }
    if(sum>=450)
    dia[1][6]='*';
    else if(sum>=300)
    dia[2][6]='*';
    else
    dia[3][6]='*';
    for(i=0;i<4;i++)
    {
        for(j=0;j<7;j++)
        printf("%c\t",dia[i][j]);
        printf("\n");
    }
    gets(name);
    }
    function(stu,p);
}
