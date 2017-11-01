#include <stdio.h>
#include <stdlib.h>
#include <string.h>         /*�ַ���������*/
#include <conio.h>          /*��Ļ����������*/

#define HEADER1 "    ---------------------STUDENT-------------------------      \n"
#define HEADER2 "    | number  | name  | Comp  |Math|Eng |  sum  |  ave  |mici| \n"
#define HEADER3 "    -----------------------------------------------------      \n"
#define FORMAT  "    |   %-10s |%-15s  |%4d    |%4d |%4d |%4d    | %.2f  |%4d | \n"

#define DATA p->data.num, p->data.name, p->data.egrade, p->data.mgrade, p->data.cgrade, p->data.cgrade, p->data.total, p->data.ave, p->data.mingci
#define END     "    -----------------------------------------------------      \n"

int saveflag=0;             /*�Ƿ���Ҫ���̵ı�־����*/
/*������ѧ���йص����ݽṹ*/
typedef struct student      /*���Ϊstudent*/
{
    char num[10];     /*ѧ��*/
    char name[15];    /*����*/
    int cgrade;       /*c���Գɼ�*/
    int mgrade;       /*��ѧ�ɼ�*/
    int egrade;       /*Ӣ��ɼ�*/
    int total;        /*�ܷ�*/
    float ave;        /*ƽ����*/
    int mingci;       /*����*/
};

/*����ÿ����¼���߽ڵ�����ݽṹ�����Ϊ:node*/
typedef struct node
{
    struct student data;   /*������*/
    struct node *next;     /*ָ����*/
}Node, *Link;              /*Npde Ϊnode���͵Ľṹ������*LinkΪnode���͵�ָ�����*/


void menu()    /*���˵�*/
{
    Node *p;
    p=l->next;    /*l�洢���ǵ�������ͷ�ڵ��ָ�룬��ͷ�ڵ�û�д洢ѧ����Ϣ��ָ����ָ���̽ڵ����ѧ����Ϣ*/
    if(!p)        /*p=NULL,NULL��stdlib�ж���Ϊ0*/
    {
        printf("\n=====>Not student record!\n");
        getchar();
        return ;
    }
    printf("\n\n");
    printheader();     /*������ͷ��*/
    while(p)           /*������������д洢��ѧ������**/
    {
        printdata(p);
        p=p->next;
        printf(HEADER3);
    }
    getchar();
}

void printheader()     /*��ʽ�������ͷ*/
{
    printf(HEADER1);
    printf(HEADER2);
    printf(HEADER3);
}

void printdata(Node *pp)     /*��ʽ�������������*/
{
    Node* p;
    p=pp;
    printf(FORMAT,DATA);
}

void Wrong()    /*�������������Ϣ*/
{
    printf("\n\n\n\n\n*********Error,input has wrong! press any key to continue********\n");
    getchar();
}

void Nofind()     /*���δ���Ҵ�ѧ������Ϣ*/
{
    printf("\n=====>Not find this student!\n");
}

/*----------------------------------------------------
����:���ڶ�λ�������Ҫ��Ľڵ㣬�����ظýڵ��ָ��
������findmess[]����Ҫ���ҵ����ݣ�nameornum[]���水ʲô�ֶ�������1�н��в��ҡ�
------------------------------------------------------*/
Node* Locate(Link l, char findmess[], char nameornum[])
{
    Node *r;
    if(strcmp(nameornum,"num")==0)  /*��ѧ�Ų�ѯ*/
    {
        r=l->next;
        while(r)
            {
                if(strcmp(r->data.num, findmess)==0)    /*���ҵ�findmessֵ��ѧ��*/
                return r;
                r=r->next;
            }
    }
    else if(strcmp(nameornum,"name")==0)    /*����������*/
    {
        r=l->next;
        while(r)
            {
                if(strcmp(r->data.name,findmess)==0)      /*���ҵ�findmessֵ��ѧ������*/
                return r;
                r=r->next;
            }
    }
    return 0;    /*��δ�ҵ�������һ����ָ��*/
}

/*�����ַ����������г��ȼ��飨����<lens)*/
void stringinput(char *t, int lens, char *notice)
{
    char n[255];
    do
    {
        printf(notice);     /*��ʾ��ʾ��Ϣ*/
        scanf("%s", &n);    /*�����ַ���*/
        if(strlen(n)>lens)printf("\n exceed the required length!\n");
        /*���г���У�飬����lensֵ��������*/
    }while(strlen(n)>lens);
    strcpy(t,n);     /*��������ַ������Ƶ��ַ���t��*/
}

/*���������0<=����<=100*/
int numberinput(char *notice)
{
    int t=0;
    do
    {
        printf(notice);     /*��ʾ��ʾ��Ϣ*/
        scanf("%d",&t);     /*�������*/
        if(t>100||t<0) printf("\n score must in [0,100]!\n");   /*���з�������*/
    }while(t>100||t<0);
    return r;
}

/*z����ѧ����¼*/
void Add(Link l)
{
    Node *p, *r, *s;     /*ʵ����Ӳ������ٽ�Ľṹ��ָ�����*/
    char ch, flag=0, num[10];
    r=l;
    s=l->next;
    system("cls");
    Disp(l);     /*�ȴ�ӡ������ѧ������Ϣ*/
    while(r->next!=NULL)
        r=r->next;     /*��ָ���ƶ���������ĩβ��׼����Ӽ�¼*/
    while(1)     /*һ�ο������������¼��ֱ������ѧ��Ϊ0�ļ�¼�ڵ���Ӳ���*/
    {
        while(1)/*����ѧ�ţ���֤��ѧ��û�б�ʹ�ã�������ѧ��Ϊ0�����˳���Ӽ�¼����*/
        {
            stringinput(num, 10, "input number(press '0'return menu):");   /*��ʽ������ѧ�Ų�У��*/
            flag=0;
            if(strcmp(num, "0")==0)     /*����ѧ��Ϊ0�����˳���Ӳ���������������*/
            {
                return;
            }
            s=l->next;
            while(s)     /*��ѯ��ѧ���Ƿ��Ѵ��ڣ���������Ҫ����������һ��δ��ռ�õ�ѧ��*/
            {
                if(strcmp(s->data.num, num)==0)
                {
                    flag=1;
                    break;
                }
                s=s->next;
            }
            if(flag==1)     /*��ʾ�û��Ƿ���������*/
            {
                getchar();
                printf("=====>The number %s is not existing, try again?(y/n):", num);
                scanf("%c", &ch);
                if(ch=='y'||ch=='Y')
                    continue;
                else
                    return;
            }
            else{break;}
        }
        p=(Node *)malloc(sizeof(Node));     /*�����ڴ�ռ�*/
        if(!p)
        {
            printf("\n allocate memory failure ");     /*���û�����뵽����ӡ��ʾ��Ϣ*/
            return;     /*����������*/
        }
        strcpy(p->data.num,num);     /*���ַ���num���Ƶ�p->data.num��*/
        stringinput(p->data.name, 15, "Name:");
        p->data.cgrade=numberinput("C language Score[0-100]:");     /*���벢У�������������0-100֮��*/
        p->data.mgrade=numberinput("math language Score[0-100]:");     /*���벢У�������������0-100֮��*/
        p->data.egrade=numberinput("English language Score[0-100]:");     /*���벢У�������������0-100֮��*/
        p->data.total=p->data.egrade+p->data.cgrade+p->data.mgrade;     /*�����ܷ�*/
        p->data.ave=(float)(p->data.total/3);     /*����ƽ����*/
        p->data.mingci=0;
        p->next=NULL;      /*������������Ľڵ�*/
        r->next=p;     /*���½��Ľڵ��������β����*/
        r=p;
        saveflag=1;
    }
    return;
}

/*��ѯѧ����¼*/
void Qur(Link l)     /*��ѧ�Ż���������ѯѧ����Ϣ*/
{

    int select;     /*1:��ѧ�Ų飻 2���������飬���������������棨�˵���*/
    char searchinput[20];     /*�����û����������*/
    Node *p;
    if(!l->next)     /*������Ϊ��*/
    {
        system("cls");
        printf("\n=====>No student record!\n");
        getchar();
        return ;
    }
    system("cls");
    printf("\n     =====>1 Search by number  =====>2 Search by name:");
    printf("Please choose[1,2]");
    scanf(%d, &select);
    if(select==1)
    {
        stringinput(searchinput, 10, "input the existing student number:");
        p=Locate(1, searchinput, "num");     /*��1�в���ѧ��Ϊsearchinputֵ�ýڵ㣬�����ؽڵ��ָ��*/
        if(p)     /*��p!=NULL*/
        {
            printheader();
            printdata(p);
            printf(END);
            printf("press any key to continue");
            getchar();
        }
        else
            Nofind();
            getchar();
    }
    else if(select==2)     /*����������ѯ*/
    {
        stringinput(searchinput, 15,"input the exiting student name:");
        p=Locate(1, searchinput, "name");
        if(p)
        {
            printheader();
            printdata();
            printf(END);
            printf("press any key to continue");
            getchar();
        }
        else
            Nofind();
            getchar();
    }
    else
        Wrong();
    getchar();
}

/*ɾ��ѧ����¼*/
void Del(Link l)
{
    int sel;
    Node *p, *r;
    char findmess[20];
    if(!l->next)
    {
        system("cls");
        printf("\n=====>No student record!\n");
        getchar();
        return;
    }
    system("cls");
    Disp(l);
    printf("\n     =====>1 Delete by number     =====>Delete by name\n");
    printf("     Please choose[1,2]:\n");
    scanf("%d", &sel);
    if(sel==1)
    {
        stringinput(findmess , 10, "input the existing student number:");
        p=Locate(l, findmess, "num");
        if(p)   /*p!=NULL*/
        {
            r=l;
            while(r->next!=p)
                r=r->next;
            r->next=p->next;     /*��p��ָ�ڵ��������ɾ��*/
            free(p);     /*�ͷ�p�Ŀռ�*/
            printf("\n=====>delete success!\n");
            getchar();
            saveflag=1;
        }
        else
            Nofind();
        getchar();
    }
    else if(sel==2)   /*�Ȱ�ѧ��������ѯ���ü�¼���ڵĽڵ�*/
    {
        stringinput(findmess, 15,"input the existing student name");
        p=Locate(1, findmess,"name");
        if(p)
        {
            r=l;
            while(r->next!=p)
            {
                r=r->next;
            }
            r->next=p->next;    /*ɾ��p��ָ��Ľڵ�*/
            free(p);     /*�ͷ��ڴ�*/
            printf("\n delete success!");
            getchar();
            saveflag=1;
        }
        else
            Nofind();
        getchar();
    }
    else
        Wrong();
    getchar();
}

/*�޸�ѧ����¼*/
void Modify(Link l)
{
    Node *p;
    char findmess[20];
    if(!l->next)
    {
        system("cls");
        printf("\n=====>No student record!\n");
        getchar();
        return;
    }
    system("cls");
    printf("Modify student record!");
    Disp(l);
    stringinput(findmess, 10, "input the existing student number:");
    /*���벢��֤��ѧ��ѧ��*/
    p=Locate(1, findmess, "num");     /*��ѯ���ýڵ�*/
    if(p)     /*��p!=NULL�������Ѿ��ҵ��ýڵ�*/
    {
        printf("Number:%s,\n", p->data.num);
        printf("Name:%s", p->data.name);
        stringinput(p->data.name, 15, "input new name:");
        printf("C language score:%d,", p->data.cgrade);
        p->data.cgrade=numberinput("C language Score[0-100]:");
        printf("Math score: %d,", p->data.mgrade);
        p->data.mgrade=numberinput("Math Score[0-100]:");
        printf("English Score [0-100]:");
        p->data.egrade=numberinput("English Score[0-100]:");
        p->data.total=p->data.cgrade+p->data.egrade+p->data.mgrade;
        p->data.ave=(float)(p->data.total/3);
        p->data.mingci=0;
        printf("\n=====modify success!\n");
        Disp(l);
        saveflag=1;
    }
    else
        Nofind();
    getchar();
}


/*����ѧ����¼*/
void Insert(Link l)
{
    Link p, v, newinfo;
    /*pָ�����λ�ã�newinfoָ���²����¼*/
    char ch, num[10], s[10];
    /*s[]��������֮ǰ��λ�ã�num[]������������¼�¼��ѧ��*/
    int flag=0;
    v=l->next;
    system("cls");
    Disp(l);
    while(1)
    {
        stringinput(s, 10, "Please input insert location after the number:");
        flag=0;
        v=l->next;
        while(v)     /*��ѯ��ѧ���Ƿ���ڣ�flag=1��ʾ��ѧ���Ѵ���*/
        {
            if(strcmp(v->data.num, num)==0);
            {
                flag=1;
                break;
            }
            v=v->next;
        }
        if(flag==1)
            break;     /*����ѧ�Ŵ��ڣ��򷵻ز���֮ǰ���¼�¼���������*/
        else
        {
            getchar();
            printf("\n=====>The number %s is not existing, try again?(y/n):", s);
            scanf("%c", &ch);
            if(ch=='y'||ch=='Y')
            {
                continue;
            }
            else
                return;
        }
    }
    /*�����¼�¼�����������Add()��ͬ*/
    stringinput(num, 10, "input the new student Number:");
    v=l->next;
    while(v)
    {
        if(strcmp(v->data.num, s)==0)
        {
            printf("=====>Sorry, the new number: '%s' is existing!\n", num);
            printheader();
            printdata(v);
            printf("\n");
            getchar();
            return;
        }
        v=v->next;
    }
    newinfo()=(Node *)malloc(sizeof(Node));
    if(!=newinfo)
    {
        printf("\n mallocate memory failure!\n");     /*���û�����뵽����ӡ��ʾ��Ϣ*/
        return;     /*����������*/
    }
    strcpy(newinfo->data.num, num);
    stringinput(newinfo->data.name, 15, "Name:");
    newinfo->data.cgrade=numberinput("C language Score[0-100]:");
    newinfo->data.mgrade=numberinput("math Score[0-100]");
    newinfo->data.egrade=numberinput("English Score[0-100]");
    newinfo->data.total=newinfo->data.cgrade+newinfo->data.mgrade+newinfo->data.egrade;
    newinfo->data.ave=(float)(newinfo->data.total/3);
    newinfo->data.mingci=0;
    newinfo->next=NULL;
    saveflag=1;
    /*��main�������ж�ȫ�ֱ������жϣ���Ϊ1������д��̲���*/
    /*��ָ�븳ֵ��p,��Ϊ1�е�ͷ�ڵ����һ���ڵ��ʵ�ʱ�����ѧ���ļ�¼*/
    p=l->next;
    while(1)
    {
        if(strcmp(p->data.num,s)==0)     /*�������в���һ���ڵ�*/
        {
            newinfo->next=p->next;
            p->next=newinfo;
            break;
        }
        p=p->next;
    }
    Disp(l);
    printf("\n\n");
    getchar();
}

/*ͳ��ѧ����¼*/
void Tongji(Link l)
{
    Node *pm, *pe, *pc, *pt;     /*����ָ�������ߵĽڵ�*/
    Node *r=l->next;
    int countc=0, countm=0, counte=0;     /*�������ſ��в����������*/
    if(!r)
    {
        system("cls");
        printf("\n=====>Not student record!\n");
        getchar();
        return ;
    }
    system("cls");
    Disp(l);
    pm=pe=pc=pt=r;
    while(r)
    {
        if(r->data.cgrade<60) countc++;
        if(r->data.mgrade<60) countm++;
        if(r->data.egrade<60) counte++;
        if(r->data.cgrade>=p->data.cgrade) pc=r;
        if(r->data.mgrade>=p->data.mgrade) pm=r;
        if(r->data.egrade>=p->data.egrade) pe=r;
        if(r->data.total>=p->data.total) pt=r;
        r=r->next;
    }
    printf("\n-----The tongji result----------\n");
    printf("C language<60:%d (ren)\n", countc);
    printf("math<60:%d (ren)\n", countm);
    printf("English<60:%d (ren)\n", counte);
    printf("\n--------------------------------\n");
    printf("The highest student by total score name:%s total score:%d\n", pt->data.name, pt->data.total);
    printf("The highest student by English score name:%s English score:%d\n", pe->data.name, pe->data.egrade);
    printf("The highest student by math score name:%s math score:%d\n", pm->data.name, pm->data.mgrade);
    printf("The highest student by C score name:%s English score:%d\n", pc->data.name, pc->data.cgrade);
    printf("Press any key to return!\n");
    getchar();
}

/*����ѧ����¼*/
void Sort(Link l)
{
    Link ll;
    Node *p, *rr, *s;
    int i=0;
    if(l->next==NULL)
    {
        system("cls");
        printf("\n=====>Not student record!\n");
        getchar();
        return ;
    }
    ll=(Node *)malloc(sizeof(Node));
    /*���ڴ����µĽڵ�*/
    if(!ll)
    {
        printf("\n allocate memory failure!\n");     /*���û�����뵽�����ӡ��ʾ��Ϣ*/
        return ;     /*����������*/
    }
    ll->next=NULL;
    system("cls");
    Disp(l);     /*��ʾ����ǰ��ѧ����¼*/
    p=l->next;
    while(p)     /* *p!=NULL*/
    {
        s=(Node*)malloc(sizeof(Node));
        /*�½��ڵ����ڱ����ԭ��������ȡ���Ľڵ���Ϣ*/
        if(!s)     /* s==NULL*/
        {
            printf("\n allocate memory failure!");
            /*���û�����뵽�����ӡ��ʾ��Ϣ*/
            return ;     /*����������*/
        }
        s->data=p->data;    /*��������*/
        s->next=NULL;     /*ָ����Ϊ��*/
        rr=ll;
        /*rr���ڱ�ʾ�洢���뵥���ڵ�󱣳���������� ll����������ͷָ�룬ÿ�δ�ͷ��ʼ���Ҳ���λ��*/
        while(rr->next!=NULL && rr->next->data.total>=p->data.total)
        {
            rr=rr-next;
        }
        /*ָ�������ֱܷ�p��ָ�ļ�����ܷ�С�Ľڵ�λ��*/
        if(rr->next==NULL)
            /*��������ll�е����нڵ���ܷ�������p->data.total��ʱ���ͽ�p��ָ�ڵ��������β��*/
            rr->next=s;
        else     /*���򽫸ýڵ��������һ���ܷ��ֶα���С�Ľڵ��ǰ��*/
        {
            s->next=rr->next;
            rr->next=s;
        }
        p=p->next;     /*ԭ�����е�ָ������һ���ڵ�*/
    }
    l->next=ll->next;     /*ll�洢����������������ͷָ��*/
    p=l->next;     /*������õ�ͷָ�븳ֵ��p��׼����д����*/
    while(p!=NULL)     /*��p��Ϊ��ʱ���������в���*/
    {
        i++;   /*�ڵ����*/
        p->data.mingci=i;     /*�����θ�ֵ*/
        p=p->next;     /*zָ�����*/
    }
    Disp(l);
    saveflag=1;
    printf("\n     =====>sort complete!\n");
}

/*�洢ѧ����¼*/
void Save(Link l)
{
    FILE *fp;
    Node *p;
    int count=0;
    fp=fopen("c:\\student","wb");     /*��ֻд��ʽ��*/
    if(fp==NULL)     /*���ļ�ʧ��*/
    {
        printf("=====>open file error!\n");
        getchar();
        return ;
    }
    p=l->next;
    while(p)
        {
            if(fwrite(p, sizeof(Node),1, fp)==1)     /*ÿ��дһ����¼��һ���ڵ���Ϣ���ļ�*/
            {
                p=p->next;
                count++;
            }
            else
                {
                    break;
                }
        }
        if(count>0)
        {
            getchar();
            printf("\n\n\n\n\n=====>save file complete, total saved's record number is:%d\n",count);
            getchar();
            saveflag=0;
        }
        else
        {
            system("cls");
            printf("the current link is empty, no student record is saved!\n");
            getchar();
        }
        fclose(fp);     /*�رմ��ļ�*/
}

void main()
{
    Link l;             /*��������*/
    FILE *fp;           /*�ļ�ָ��*/
    int select;         /*����ѡ��������*/
    char ch;            /*����(y, Y, n, N)*/
    int count=0;        /*�����ļ��еļ�¼��������ڵ������*/
    Node *p, *r;        /*�����¼ָ�����*/
    l=(Node*)malloc(sizeof(Node));
    if(!l)
    {
        printf("\n allocate memory failure ");   /*���û�����뵽����ӡ��ʾ��Ϣ*/
        return ;                                 /*����������*/
    }
    l->next=NULL;
    r=l;
    fp=fopen("C:\\student","ab+");               /*��׷�ӷ�ʽ��һ���������ļ����ɶ���д�������ļ������ڣ���ᴴ�����ļ�*/
    if(fp=NULL)
    {
        printf("\n====>Can't open file!\n");
        exit(0);
    }
    while(!feop(fp)
          {
              p=(Node*)malloc(sizeof(Node));
              if(!p)
                {
                    printf(" memory malloc failure!\n"); /*û������ɹ�*/
                    exit(0);        /*�˳�*/
                }
              if(fread(p, sizeof(Node),l,fp)==1)         /*һ�δ��ļ��ж�ȡһ��ѧ���ɼ���¼*/
              {
                  P->next=NULL;
                  r->next=p;
                  r=p;                            /*r��ָ������ƶ�һ��λ��*/
                  count++;
              }
          }
    fclose(fp);    /*�ر��ļ�*/
    printf("\n=====>open file sucess, the total records number is : %.d\n", count);
    menu();
    while(1)
    {
        system("cls");
        menu();
        p=r;
        printf("\n Please enter your choice(0~9):");      /*��ʾ��ʾ��Ϣ*/
        scanf("%d", &select);
        if(select==0)
        {
            if(saveflag==1)     /*����������������޸���δ���д��̲�������˱�־λ1*/
            {
                getchar();
                printf("\n=====>Whether save the modified record to file?(y/n):");
                scanf("%c", &ch);
                if(ch=='y'||ch=='Y')
                    Save(l);
            }
            printf("=====>Thank you for useness!");
            getchar();
            break;
        }
        switch(select)
        {
            case 1: Add(l);break;     /*����ѧ����¼*/
            case 2: Del(l);break;     /*ɾ��ѧ����¼*/
            case 3: Qur(l);break;     /*��ѯѧ����¼*/
            case 4: Modify(l);break;     /*�޸�ѧ����¼*/
            case 5: Insert(l);break;     /*����ѧ����¼*/
            case 6: Tongji(l);break;     /*ͳ��ѧ����¼*/
            case 7: Sort(l);break;     /*����ѧ����¼*/
            case 8: Save(l);break;     /*����ѧ����¼*/
            case 9: system("cls");Disp(l);break;     /*��ʾѧ����¼*/
            default : Wrong();getchar();break;       /*�������󣬱���Ϊ��ֵ0~9*/
        }
    }
}

