#include<stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>

int accounts=0;

void welcome()
{
        for(int i=0;i<100;i++) printf("*");
        printf("\n\t\t\t\t\tWElCOME TO SDF BANK \n");
        for(int i=0;i<100;i++) printf("*");
}
struct profile{
        char username[50];
        char name[50];
        char address[100];
        char mail[50];
        char dob[10];
        long long phone;
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
        if(*ch!='\0'||*h!='\0') return 1;
        if(a==0) return 0;
        else return 1;
 }

 int account_no()
 {
        printf("\nenter username\n");
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
                break;
            }
            c++;
        }
        if(c<accounts)
        {
            return c;
        }
        printf("username does not exist\n");
        main();

}

void printprofile(int x)
{
        printf("\nNAME : %s\nADDRESS : %s\nPHONE : %d\nMAIL : %s\nDATE OF BIRTH : %s\nAADHAR : %d\nBALANCE : %d\nLOAN : %d\n",user[x].name,user[x].address,user[x].phone,user[x].mail,user[x].dob,user[x].aadhar,user[x].balance,user[x].loan);
}

int login()
{
        int x;
        printf("\nPRESS\n0 TO SIGN UP\n1 TO LOG IN\n2 TO LOGOUT\n");
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

int admmenu()
{
        int x;
        printf("\nMENU\n1 TO TRANSFER FUNDS\n2 TO TAKE LOAN\n3 TO DEPOSIT FUNDS\n4 TO OPEN FIXED DEPOSITS\n5 TO WITHDRAW FUNDS\n6 TO EDIT PROFILE\n7 TO SHOW TRANSACTIONS\n8 TO LOGOUT\n0 TO DELETE\n");
        scanf("%d",&x);
        return x;
}

int custmenu()
{
        int x;
        printf("\nMENU\n1 TO TRANSFER FUNDS\n2 TO SHOW TRANSACTIONS\n0 TO LOGOUT\n");
        scanf("%d",&x);
        return x;
}

int main()
{
        welcome();

        int choice;
        int upin,me,re,numb;
        char password[100];


        printf("\nWELCOME TO THE LOGIN SYSTEM.\nPLEASE ENTER YOUR CHOICE :\n1. ADMIN LOGIN\n2. CUSTOMER LOGIN\n");
        scanf("%d", &choice);
        switch (choice)
    {
        case 1:
            {
            printf("ENTER THE ADMIN PASSWORD : ");
            scanf("%s",&password);
            if (strcmp(password, "admin123") == 0)
            {
                printf("ADMIN LOGIN SUCCESSFUL.\n");
                adm:
                upin=login();
                switch(upin)
    {
        case 0:
        {
           accounts++;
           int v=accounts-1;
           printf("SIGN IN\n");
           printf("ENTER NAME\n");
           gets(user[v].name);
           gets(user[v].name);
           printf("ENTER ADDRESS\n");
           gets(user[v].address);
           printf("ENTER EMAIL\n");
           gets(user[v].mail);
           printf("ENTER DOB IN DD/MM/YYYY\n");
           gets(user[v].dob);
           printf("ENTER PHONE\n");
           scanf("%0.lf",&user[v].phone);
           printf("AADHAR\n");
           scanf("%d",&user[v].aadhar);
           printf("CREATE USERNAME:\n");
           gets(user[v].username);
           gets(user[v].username);
           printf("CREATE PASSWORD:\n");
           gets(user[v].password);
           printprofile(v);
           goto adm;
           break;
        }
        case 1:
        {
            printf("LOG IN\n");
            numb=account_no();

            printf("\nENTER PASSWORD%s",user[numb].password);
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
                printf("\nWRONG PASSWORD\n");
                goto adm;
            }
            break;
        }
        case 2:
            {
                main();
            }
        default:
            {
                printf("\nTRY AGAIN\n");
                goto adm;
            }
    }
        if(me==9)
    {
            notout:
        {
                int u,f,amount;
                u=admmenu();
                switch(u)
            {
                case 1:
                {
                    printf("ENTER USER TO TRANSFER FUNDS TO\n");
                    f=account_no();
                    printf("ENTER AMOUNT TO BE TRANSFERRED");
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
                            printf("TRANSFER SUCCESSFUL");
                        }
                        else
                        {
                            printf("NOT ENOUGH FUNDS");
                        }
                    }
                    else
                    {
                        printf("AMOUNT CANNOT BE NEGATIVE");
                    }
                    goto notout;
                }
                case 2:
                {
                     printf("\nENTER AMOUNT OF LOAN REQUIRED");
                     scanf("%d",&amount);
                     if(amount>=0)
                     {
                        int years;
                        printf("\nENTER NUMBER OF YEARS FOR THE REPAYMENT OF LOAN");
                        scanf("%d",&years);
                        printf("\nINTEREST RATE IS 12% PER ANNUM\nTOTAL INTEREST IS %d\n",amount*years*12/100);
                        printf("ARE YOU SURE?(Y/N)\n");
                        char sure;
                        sure=getch();
                        if(sure=='y')
                        {
                            user[numb].balance+=amount;
                            user[numb].loan+=amount+amount*years*12/100;
                            printf("TOTAL AMOUNT OF LOAN REPAYMENT %d\n",amount+amount*years*12/100);
                        }
                    }
                    else
                    {
                        printf("AMOUNT CANNOT BE NEGATIVE");
                    }
                    goto notout;
                }
                case 3:
                {
                    if(user[numb].loan==0)
                    {
                        printf("ENTER AMOUNT TO BE DEPOSITED");
                        scanf("%d",&amount);
                        if(amount>=0)
                        {
                            user[numb].balance+=amount;
                        }
                        else
                        {
                            printf("AMOUNT CANNOT BE NEGATIVE");
                        }
                    }
                    else if(user[numb].loan>0)
                    {
                        printf("LOAN NEEDS TO BE REPAYED\n ENTER AMOUNT TO BE PAYED:");
                        scanf("%d",&amount);
                        if(amount>=0)
                        {
                            user[numb].loan-=amount;
                        }
                        else
                        {
                            printf("AMOUNT CANNOT BE NEGATIVE");
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
                     printf("\nENTER AMOUNT OF FIXED DEPOSIT");
                     scanf("%d",&amount);
                     if(amount>=0)
                     {
                        int years;
                        printf("\nENTER NUMBER OF YEARS FOR THE FIXED DEPOSIT");
                        scanf("%d",&years);
                        printf("\nINTEREST RATE IS 5 PERCENT PER ANNUM\nTOTAL PROFIT IS %d\n",amount*years*5/100);
                        printf("ARE YOU SURE?(y/n)\n");
                        char sure;
                        sure=getch();
                        if(sure=='y')
                        {
                            if(user[numb].balance-amount>=0)
                            {
                                user[numb].balance-=amount;
                                user[numb].fd+=amount+amount*years*5/100;
                                printf("TOTAL AMOUNT AFTER THE TERM IS %d\nKEEP THE PROOF OF FIXED DEPOSIT SAFE",amount+amount*years*5/100);
                            }
                            else
                            {
                                printf("\nNOT ENOUGH FUNDS");
                            }
                        }
                    }
                    else
                    {
                            printf("AMOUNT CANNOT BE NEGATIVE");
                    }
                    goto notout;

                }
                case 5:
                {
                    printf("ENTER AMOUNT TO BE WITHDRAWN");
                    scanf("%d",&amount);
                    if(amount>=0)
                    {
                         if(user[numb].balance-amount>=0)
                        {
                            user[numb].balance-=amount;
                            printf("\nWITHDRAWL SUCCESSFUL");
                        }
                        else
                        {
                            printf("\nNOT ENOUGH FUNDS");
                        }
                    }
                    else
                    {
                        printf("AMOUNT CANNOT BE NEGATIVE");
                    }
                    goto notout;
                }
                case 6:
                {
                    editor:
                    {
                        printprofile(numb);
                        int edit;
                        printf("\nTO EDIT\nPRESS\n1 FOR NAME\n2 FOR ADDRESS\n3 FOR MAIL\n4 FOR PHONE\n5 FOR PASSWORD\n0 TO EXIT\n");
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
                    printf("TRANSACTION LIST");
                    for(int i=payer[numb].counter-1;i>=0;i--)
                    {
                        printf("\nYOU PAYED %d RUPEES TO %s",payer[numb].sent_amount[i],payer[numb].payee[i]);
                    }
                    goto notout;
                }
                case 8:
                {
                    goto adm;
                    break;
                }
                case 0:
                {
                    printf("MAKE SURE TO WITHDRAW ALL YOUR MONEY BEFORE DELETING ACCOUNT\nARE YOU SURE?(y/n)\n");
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
    goto adm;
            }
            else
            {
                printf("WRONG PASSWORD.PLEASE TRY AGAIN.\n");
                main();
            }
            break;
            }

        case 2:
            {

                printf("\nSIGN IN TO YOUR ACCOUNT");
                int acc=account_no();

                printf("\nENTER PASSWORD%s",user[acc].password);
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
            k=strcmp(h,user[acc].password);
            if(k==0)
            {
                printprofile(acc);
                re=9;
            }
            else
            {
                printf("\nWRONG PASSWORD\n");
                main();
            }
            if(re==9)
            {
                 cust:
                     {
                         int r,f,amount;
            r=custmenu();
            switch(r)
            {
           case 1:
            {
                    printf("ENTER USER TO TRANSFER FUNDS TO\n");
                    f=account_no();
                    printf("ENTER AMOUNT TO BE TRANSFERRED TO");
                    scanf("%d",&amount);
                    if(amount>=0)
                    {
                        if(user[acc].balance-amount>=0)
                        {
                            user[acc].balance-=amount;
                            user[f].balance+=amount;
                            if(payer[acc].counter==100)
                            {
                                for(int i=0;i<50;i++)
                                {
                                    payer[acc].sent_amount[i]=payer[acc].sent_amount[50+i];
                                    strcpy(payer[acc].payee[i],payer[acc].payee[50+i]);
                                }
                                payer[acc].counter=50;
                            }
                            payer[acc].sent_amount[payer[acc].counter]=amount;
                            strcpy(payer[acc].payee[payer[acc].counter],user[f].username);
                            payer[acc].counter++;
                            printf("TRANSFER SUCCESSFUL");
                        }
                        else
                        {
                            printf("NOT ENOUGH FUNDS");
                        }
                    }
                    else
                    {
                            printf("AMOUNT CANNOT BE NEGATIVE");
                    }
                    goto cust;
                }
           case 2:
            {
                    printf("TRANSACTION LIST");
                    for(int i=payer[acc].counter-1;i>=0;i--)
                    {
                            printf("\nYOU PAYED %d RUPEES TO %s",payer[acc].sent_amount[i],payer[acc].payee[i]);
                    }
                    goto cust;
            }
           case 0:
            {
                main();
            }
            }

            }
                 break;
            }

                     }

        default:
            printf("INVALID CHOICE.PLEASE ENTER A VALID OPTION.\n");
            main();
    }
}
