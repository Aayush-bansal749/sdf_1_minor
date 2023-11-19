#include<stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>

int accounts=0;

void welcome()
{
    for(int i=0;i<20;i++)
        printf("*");
    printf("\nwelcome to sdf bank\n");
    for(int i=0;i<20;i++)
        printf("*");
}
struct profile{
        char username[50];
        char name[50];
        char address[100];
        char mail[50];
        char dob[10];
        int phone;
        int aadhar;
        char password[50];
        int balance;
        int loan;
        int fd;
    }user[100];

struct transactions
{
    int counter;
    char payee[100][50];
    int sent_amount[100];
}payer[100];

 int compare(char *ch,int e)
 {
     char *h=user[e].username;
     int a;
     while(*ch!='\0'&&*h!='\0')
     {
         if(*ch!=*h)
         {
             a=1;
         }
         ch++;h++;
     }
     if(*ch!='\0'||*h!='\0')
        return 1;
     if(a==0)
        return 0;
     else
        return 1;
 }

 int account_no()
 {
    printf("enter username\n");
    char username[50];
    int c=0;
    gets(username);
    gets(username);
    while(c!=accounts)
        {
            int d;
            printf("%d",c);
            d=compare(username,c);
            if(d==0)
            {
                printf("%d,%d",d,c);
                break;
            }
            c++;
        }return c;
         if(c=accounts)
            {
                printf("username does not exist\n");
                main();
            }
}

void printprofile(int x)
{
     printf("\nname=%s\naddress=%s\nphone=%d\nmail=%s\ndob=%s\naadhar=%d\nbalance=%d\nloan=%d\n",user[x].name,user[x].address,user[x].phone,user[x].mail,user[x].dob,user[x].aadhar,user[x].balance,user[x].loan);
}

int login()
{
    int x;
    printf("\npress\n0 to sign up\n1 to log in\n");
    scanf("%d",&x);
    return x;
}

void deleter(int j)
{
    for(int e=j;e<accounts;e++)
    {
       user[e]=user[e+1];
    }

    accounts--;
    main();
}

int menu()
{
    int x;
    printf("\nmenu\n1 to transfer funds\n2 to take loan\n3 to deposit funds\n4 to open fixed deposits\n5 to withdraw funds\n6 to edit profile\n7 to show transactions\n8 to logout\n0 to delete\n");
    scanf("%d",&x);
    return x;
}

int main()
{
    welcome();
    int upin,me,numb;
    upin=login();
    switch(upin)
    {
        case 0:
        {
           accounts++;
           int v=accounts-1;
           printf("sign in\n");
           printf("enter name\n");
           gets(user[v].name);
           gets(user[v].name);
           printf("enter address\n");
           gets(user[v].address);
           printf("enter mail\n");
           gets(user[v].mail);
           printf("enter dob in dd/mm/yyyy\n");
           gets(user[v].dob);
           printf("enter phone\n");
           scanf("%d",&user[v].phone);
           printf("aadhar\n");
           scanf("%d",&user[v].aadhar);
           printf("create username:\n");
           gets(user[v].username);
           gets(user[v].username);
           printf("create password:\n");
           gets(user[v].password);
           printprofile(v);
           main();
           break;
        }
        case 1:
        {
            printf("log in\n");
            numb=account_no();

            printf("\n%denter password%s",numb,user[numb].password);
            char h[50],ch;
            int i;
            for(i=0;i<50;i++)
            {
                ch=getch();
                if(ch==13)
                break;
                h[i]=ch;
                ch='*';
                printf("%c",ch);
            }
            h[i]='\0';
            int k,j;
            k=strcmp(h,user[numb].password);
            if(k==0)
            {
                printprofile(numb);
                me=9;
            }
            else
            {
                printf("\nwrong password\n");
                main();
            }
            break;
        }
        default:
            {
                printf("\ntry again\n");
                main();
            }
    }
    if(me==9)
    {
        notout:
        {
            int u,f,amount;
            u=menu();
            switch(u)
            {
                case 1:
                {
                    printf("enter user to transfer funds to\n");
                    f=account_no();
                    printf("enter amount to be transfered");
                    scanf("%d",&amount);
                    if(amount>=0)
                    {
                        if(user[numb].balance-amount>=0)
                        {
                            user[numb].balance-=amount;
                            user[f].balance+=amount;
                            if(payer[numb].counter==100)
                            {
                                for(int i=0;i<50;i++)
                                {
                                    payer[numb].sent_amount[i]=payer[numb].sent_amount[50+i];
                                    strcpy(payer[numb].payee[i],payer[numb].payee[50+i]);
                                }
                                payer[numb].counter=50;
                            }
                            payer[numb].sent_amount[payer[numb].counter]=amount;
                            strcpy(payer[numb].payee[payer[numb].counter],user[f].username);
                            payer[numb].counter++;
                            printf("transfer successful");
                        }
                        else
                        {
                            printf("not enough funds");
                        }
                    }
                    else
                    {
                        printf("amount cannot be negative");
                    }
                    goto notout;
                }
                case 2:
                {
                     printf("\nenter amount of loan required");
                     scanf("%d",&amount);
                     if(amount>=0)
                     {
                        int years;
                        printf("\nenter number of years for the repayement of loan");
                        scanf("%d",&years);
                        printf("\ninterest rate is 12 percent per annum\ntotal interest is %d\n",amount*years*12/100);
                        printf("are you sure?(y/n)\n");
                        char sure;
                        sure=getch();
                        if(sure=='y')
                        {
                            user[numb].balance+=amount;
                            user[numb].loan+=amount+amount*years*12/100;
                            printf("total amount of repayment is %d\n",amount+amount*years*12/100);
                        }
                    }
                    else
                    {
                        printf("amount cannot be negative");
                    }
                    goto notout;
                }
                case 3:
                {
                    if(user[numb].loan==0)
                    {
                        printf("enter amount to be deposited");
                        scanf("%d",&amount);
                        if(amount>=0)
                        {
                            user[numb].balance+=amount;
                        }
                        else
                        {
                            printf("amount cannot be negative");
                        }
                    }
                    else if(user[numb].loan>0)
                    {
                        printf("loan needs to be repayed\n enter amount to be payed:");
                        scanf("%d",&amount);
                        if(amount>=0)
                        {
                            user[numb].loan-=amount;
                        }
                        else
                        {
                            printf("amount cannot be negative");
                        }
                    }
                    if(user[numb].loan<0)
                    {
                        user[numb].balance-=user[numb].loan;
                        user[numb].loan=0;
                    }
                    goto notout;
                }
                case 4:
                {
                    printf("\nenter amount of fixed deposit");
                     scanf("%d",&amount);
                     if(amount>=0)
                     {
                        int years;
                        printf("\nenter number of years for the fixed deposit");
                        scanf("%d",&years);
                        printf("\ninterest rate is 5 percent per annum\ntotal profit is %d\n",amount*years*5/100);
                        printf("are you sure?(y/n)\n");
                        char sure;
                        sure=getch();
                        if(sure=='y')
                        {
                            if(user[numb].balance-amount>=0)
                            {
                                user[numb].balance-=amount;
                                user[numb].fd+=amount+amount*years*5/100;
                                printf("total amount after the term is %d\nkeep the proof of fixed deposit safe",amount+amount*years*5/100);
                            }
                            else
                            {
                                printf("\nnot enough funds");
                            }
                        }
                    }
                    else
                    {
                        printf("amount cannot be negative");
                    }
                    goto notout;

                }
                case 5:
                {
                    printf("enter amount to be withdrawn");
                    scanf("%d",&amount);
                    if(amount>=0)
                    {
                         if(user[numb].balance-amount>=0)
                        {
                            user[numb].balance-=amount;
                            printf("\nwithdrawal successful");
                        }
                        else
                        {
                            printf("\nnot enough funds");
                        }
                    }
                    else
                    {
                        printf("amount cannot be negative");
                    }
                    goto notout;
                }
                case 6:
                {
                    editor:
                    {
                        printprofile(numb);
                        int edit;
                        printf("\nto edit\npress\n1 for name\n2 for address\n3 for mail\n4 for phone\n5 for password\n0 to exit\n");
                        scanf("%d",&edit);
                        switch(edit)
                        {
                        case 1:
                         {
                            gets(user[numb].name);
                            gets(user[numb].name);
                            break;
                         }
                        case 2:
                         {
                            gets(user[numb].address);
                            gets(user[numb].address);
                            break;
                         }
                        case 3:
                         {
                            gets(user[numb].mail);
                            gets(user[numb].mail);
                            break;
                         }
                        case 4:
                         {
                            scanf("%d",&user[numb].phone);
                            break;
                         }
                        case 5:
                         {
                            gets(user[numb].password);
                            gets(user[numb].password);
                            break;
                         }
                        case 0:
                         {
                            goto notout;
                            break;

                         }
                    default:
                         {
                            goto editor;
                            break;
                         }
                        }
                    }
                        goto notout;
                }
                case 7:
                {
                    printf("transaction list");
                    for(int i=payer[numb].counter-1;i>=0;i--)
                    {
                        printf("\nyou payed %d rupees to %s",payer[numb].sent_amount[i],payer[numb].payee[i]);
                    }
                    goto notout;

                }
                case 8:
                {
                    main();
                    break;
                }
                case 0:
                {
                    printf("make sure to withdraw all your money before deleting account\nare you sure?(y/n)\n");
                    char sure;
                    sure=getch();
                    if(sure=='y')
                    {
                        deleter(numb);
                    }
                    else
                        goto notout;
                    break;
                }
                default:
                {
                    goto notout;
                }
            }
        }
    }
    main();
}
