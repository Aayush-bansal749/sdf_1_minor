#include<stdio.h>
int accounts=0;
int start=0;
struct profile{
        char name[50];
        char address[100];
        char mail[50];
        char dob[10];
        int phone;
        int account_no;
        int aadhar;
        char password[50];
        int balance;
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
     printf("\nname=%s\naccount number=%d\nbalance=%d\naddress=%s\nmail=%s\ndob=%s\nphone=%d\naadhar=%d\n",user[x].name,x,user[x].balance,user[x].address,user[x].mail,user[x].dob,user[x].phone,user[x].aadhar);
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
    printf("\npress\n1 to transfer funds\n2 to take loan\n3 to deposit funds\n4 to withdraw funds\n5 to logout");
    scanf("%d",&x);
    return x;
}
int main()
{
    if(start==0)
    {
        start=balancing();
    }
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
                printf("wrong password");
                main();
            }
            break;
        }
        default:
            {
                printf("try again");
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
                    if(user[numb].balance-amount>0)
                    {
                        user[numb].balance-=amount;
                        user[f].balance+=amount;
                        printf("transfer successful");
                    }
                    else
                    {
                        printf("not enough funds");
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
                    printf("\ninterest rate is 12% per annum\ntotal interest is %d",12/100*amount*years);
                    printf("are you sure?(y/n)");
                    char sure;
                    scanf("%c",&sure);
                    if(sure=='y')
                    {
                        user[numb].balance+=amount;
                        printf("total ammount of repayment is %d",amount+amount*12*years/100);
                    }
                    else
                    {
                        goto notout;
                    }
                }
            case 3:
                {
                    printf("enter amount to be deposited");
                    scanf("%d",&amount);
                    user[numb].balance+=amount;
                    goto notout;
                }
            case 5:
                {
                    main();
                }
        }
        }
    }
    main();
}
