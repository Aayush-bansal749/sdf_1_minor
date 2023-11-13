#include<stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>

int accounts=0;

int start=0;

void welcome()
{
    for(int i=0;i<20;i++)
    printf("*");
    printf("\nwelcome to sdf bank\n");
    for(int i=0;i<20;i++)
    printf("*");
}
struct profile{
        char name[50];
        char address[100];
        char mail[50];
        char dob[10];
        int phone;
        int aadhar;
        char password[50];
        int balance;
        int loan;
    }user[100];

int balancing()
 {
    for(int i=0;i<100;i++)
    {
        user[i].balance=0;
    }
    return 1;
 }

void printprofile(int x)
{
     printf("\nname=%s\naccount number=%d\nbalance=%d\naddress=%s\nmail=%s\ndob=%s\nphone=%d\naadhar=%d\nloan=%d\n",user[x].name,x,user[x].balance,user[x].address,user[x].mail,user[x].dob,user[x].phone,user[x].aadhar,user[x].loan);
}

int login()
{
    int x;
    printf("\npress\n0 to sign up\n1 to log in\n");
    scanf("%d",&x);
    return x;
}

int menu()
{
    int x;
    printf("\npress\n1 to transfer funds\n2 to take loan\n3 to deposit funds\n4 to withdraw funds\n5 to edit profile\n6 to logout\n");
    scanf("%d",&x);
    return x;
}

int main()
{
    if(start==0)
    {
        start=balancing();
    }
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
           printf("create password:\n");
           gets(user[v].password);
            gets(user[v].password);
           printprofile(v);
           main();
           break;
        }
        case 1:
        {
            printf("log in\n");
            printf("enter account number\n");
            scanf("%d",&numb);
            printf("enter password\n");
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
            int k=0,j;
            for(j=0;j<i;j++)
            {
                if(h[j]==user[numb].password[j])
                {
                    k++;
                }
            }
            if(k==i)
            {
                printprofile(numb);
                me=9;
            }
            else
            {
                printf("\nwrong account or password\n");
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
        switch (u)
        {
            case 1:
                {
                    printf("enter account number to transfer fund to");
                    scanf("%d",&f);
                    printf("enter amount to be transfered");
                    scanf("%d",&amount);
                    if(amount>=0)
                    {
                    if(user[numb].balance-amount>=0)
                    {
                        user[numb].balance-=amount;
                        user[f].balance+=amount;
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

                        goto notout;
                }
            case 3:
                {
                    if(user[numb].loan<0)
                    {
                        user[numb].balance-=user[numb].loan;
                        user[numb].loan=0;
                    }
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
                    goto notout;
                }
            case 4:
                {
                    printf("enter amount to be withdrawn");
                    scanf("%d",&amount);
                    if(amount>=0)
                    {
                         if(user[numb].balance-amount>=0)
                    {
                        user[numb].balance-=amount;

                        printf("\ntransfer successful");
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
            case 5:
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
                        }
                    default:
                        {
                            goto editor;
                        }
                    }
                        }
                        goto notout;
                }
            case 6:
                {
                    main();
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
