#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>

struct node
{
    int voter_id;
    char vote[5];
    struct node *next;
};

struct max
{
    int num;
    char name[6];
}m[5];

struct node *head;
int a=0;
int b=0;
int c=0;
int d=0;
int e=0;
int f=0;

void main()
{
    head=NULL;
    int ch;
    while(1)
    {
        system("COLOR E9");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("                                              WELCOME TO EVM MACHINE                                                    \n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("=>Enter 1 for admin\n");
        printf("=>Enter 2 for voting\n");
        printf("=>Enter 3 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            admin();
            break;
        case 2:
            voter();
            break;
        case 3:
            system("cls");
            printf("Thank you for your time. :-)");
            exit(0);
        default:
            system("COLOR EC");
            printf("Invalid choice!Enter again.\n");
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("Press any key to continue.....");
            getch();
        }
        system("cls");
    }
}

void admin()
{
    system("cls");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                                    LOG IN TO ENTER                                                     \n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    char name[10];
    int pass;
    int n;
    int id;
    int x;
    int count=0;
    int count1=0;
    printf("Enter Username:\n>");
    fflush(stdin);
    scanf("%s",&name);
    printf("Enter password:\n>");
    scanf("%d",&pass);
    if(strcmp(name,"admin")!=0 || pass!=12345)
    {
        system("COLOR EC");
        printf("Wrong details!!\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Press any key to continue.....");
        getch();
    }
    else
    {
        system("cls");
        P:
        system("COLOR B6");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("                                                    WELCOME ADMIN                                                       \n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Enter 1 to see who won.\n");
        printf("Enter 2 to enter a voter id and see their vote.\n");
        printf("Enter 3 to exit.\n>");
        scanf("%d",&n);
        if(n==1)
        {
            maximum();
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("                                                    WELCOME ADMIN                                                       \n");
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("Enter 1 to see the no. of votes per party.\n");
            printf("Enter 2 to go back.\n>");
            scanf("%d",&x);
            if(x==1)
            {
                system("cls");
                cal_vote();
                system("cls");
                goto P;
            }
            else if(x==2)
            {
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("Press any key to continue.....");
                getch();
                system("cls");
                goto P;
            }
            else

            {
                count++;
                if(count<2)
                {
                    system("COLOR BC");
                    printf("Wrong choice.1 more attempt left!\n");
                    printf("------------------------------------------------------------------------------------------------------------------------\n");
                    printf("Press any key to continue.....");
                    getch();
                    system("cls");
                    goto P;
                }
                else
                {
                    system("COLOR BC");
                    printf("Entered wrong choice twice.Log in again.\n");
                    printf("------------------------------------------------------------------------------------------------------------------------\n");
                    printf("Press any key to continue.....");
                    getch();
                    return;
                }
            }
        }
        else if(n==2)
        {
            system("cls");
            printf("Enter the voter id.\n>");
            scanf("%d",&id);
            search(id);
        }
        else if(n==3)
        {
            system("cls");
            printf("Thank you for your time. :-)");
            exit(0);
        }
        else
        {
            count1++;
            if(count1<2)
            {
                system("COLOR BC");
                printf("Wrong choice.1 more attempt left!\n");
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("Press any key to continue.....");
                getch();
                system("cls");
                goto P;
            }
            else
            {
                system("COLOR BC");
                printf("Entered wrong choice twice.Log in again.\n");
                printf("------------------------------------------------------------------------------------------------------------------------\n");
                printf("Press any key to continue.....");
                getch();
                return;
            }
        }
    }
}

void voter()
{
    system("cls");
    int count2=0;
    Q:
    system("COLOR A5");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                                    WELCOME VOTER                                                       \n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    char ch;
    int id;
    printf("Enter your 5-digit voter ID:\t");
    scanf("%d",&id);
    if(id<9999 || id>99999)
    {
        count2++;
        if(count2<2)
        {
            system("COLOR AC");
            printf("Invalid voter ID.1 more attempt left!\n");
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("Press any key to continue.....");
            getch();
            system("cls");
            goto Q;
        }
        else
        {
            system("COLOR AC");
            printf("Entered wrong ID twice.Go back to main menu.\n");
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("Press any key to continue.....");
            getch();
            return;
        }
    }
    if(check(id)==1)
    {
        return;
    }
    system("cls");
    printf("\t\tLIST OF CANDIDATES:\n\n");
    printf("Enter 'A' for BJP\n");
    printf("Enter 'B' for INC\n");
    printf("Enter 'C' for AAP\n");
    printf("Enter 'D' for SP\n");
    printf("Enter 'E' for JDU\n");
    printf("Enter 'F' for NCP\n\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("Enter your vote:\n");
    fflush(stdin);
    scanf("%c",&ch);
    if(ch>=97 && ch<=122)
    {
        ch=ch-32;
    }
    switch(ch)
    {
    case 'A':
        a++;
        insert(id,"BJP");
        break;
    case 'B':
        b++;
        insert(id,"INC");
        break;
    case 'C':
        c++;
        insert(id,"AAP");
        break;
    case 'D':
        d++;
        insert(id,"SP");
        break;
    case 'E':
        e++;
        insert(id,"JDU");
        break;
    case 'F':
        f++;
        insert(id,"NCP");
        break;
    default:
        system("COLOR AC");
        printf("Wrong choice!\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Press any key to continue.....");
        getch();
        break;
    }
}

void insert(int id,char ch[5])
{
    struct node *temp;
    struct node *temp1;
    temp=(struct node *)malloc(sizeof(struct node));
    temp1=head;
    if(head==NULL)
    {
        temp->voter_id=id;
        strcpy(temp->vote,ch);
        temp->next=head;
        head=temp;
    }
    else
    {
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp->voter_id=id;
        strcpy(temp->vote,ch);
        temp->next=NULL;
        temp1->next=temp;
    }
    printf("\nYour vote has been accepted.Thank you for voting...\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("Press any key to continue.....");
    getch();
}

void cal_vote()
{
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                                    VOTING STATUS                                                       \n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("Vote scored by BJP = %d\n",a);
    printf("Vote scored by INC = %d\n",b);
    printf("Vote scored by AAP = %d\n",c);
    printf("Vote scored by SP  = %d\n",d);
    printf("Vote scored by JDU = %d\n",e);
    printf("Vote scored by NCP = %d\n",f);
    printf("Press any key to continue.....");
    getch();
}

int check(int id)
{
    struct node *temp;
    temp=head;
    int i;
    while(temp!=NULL)
    {
        if(id==temp->voter_id)
        {
            printf("Your vote has already been registered.\n");
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("Press any key to continue.....");
            getch();
            return 1;
        }
        else
        {
            temp=temp->next;
        }
    }
}

void maximum()
{
    strcpy(m[0].name,"BJP");
    m[0].num=a;
    strcpy(m[1].name,"INC");
    m[1].num=b;
    strcpy(m[2].name,"AAP");
    m[2].num=c;
    strcpy(m[3].name,"SP");
    m[3].num=d;
    strcpy(m[4].name,"JDU");
    m[4].num=e;
    strcpy(m[5].name,"NCP");
    m[5].num=f;
    int i;
    int j;
    int k;
    int count3=0;
    struct max temp;
    for(i=0;i<5;i++)
    {
        for(j=0;j<4-i;j++)
        {
            if(m[j].num<m[j+1].num)
            {
                temp=m[j];
                m[j]=m[j+1];
                m[j+1]=temp;
            }
        }
    }
    for(k=1;k<5;k++)
    {
        if(m[0].num==m[k].num)
        {
            count3++;
        }
        else
        {
            break;
        }
    }
    if(a==0 && b==0 && c==0 && d==0 && e==0 && f==0)
    {
        printf("No votes have been registered yet.\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Press any key to continue.....");
        getch();
        system("cls");
    }
    else if(count3>0)
    {
        printf("There's a tie between ");
        for(k=0;k<=count3;k++)
        {
            printf("%s,",m[k].name);
        }
        printf("\b with %d vote/s.\n",m[0].num);
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Press any key to continue.....");
        getch();
        system("cls");
    }
    else
    {
        printf("%s won with %d votes.\n",m[0].name,m[0].num);
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Press any key to continue.....");
        getch();
        system("cls");
    }
}

void search(int id1)
{
    struct node *temp;
    temp=head;
    int i;
    int flag=0;
    while(temp!=NULL)
    {
        if(temp->voter_id==id1)
        {
            printf("\n%d has voted %s.\n",temp->voter_id,temp->vote);
            printf("------------------------------------------------------------------------------------------------------------------------\n");
            printf("Enter any key to continue....");
            getch();
            flag++;
            break;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        printf("No such voter ID found.\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Enter any key to continue....");
        getch();
    }
}
