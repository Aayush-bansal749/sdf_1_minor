// account to account
#include<stdio.h>
int r=0;
struct profile{
        char name[50];
        char address[100];
        char mail[50];
        char dob[10];
        int phone;
        int account_no;
        int aadhar;
        char password[50];

    }user[100];

void printprofile(int x)
{
     printf("name=%s\naccount number=%d\naddress=%s\nmail=%s\ndob=%s\nphone=%d\naadhar=%d\n",user[x].name,x,user[x].address,user[x].mail,user[x].dob,user[x].phone,user[x].aadhar);
}
int login()
{
    int x;
    printf("press 0 to sign up and 1 to log in\n");
    scanf("%d",&x);
    return x;
}
int main()
{
    int x;
    x=login();

    switch(x)
    {
        case 0:
        {
            r++;
            int v=r-1;
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
            int e;
            printf("log in\n");
            printf("enter account number\n");
            scanf("%d",&e);
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
                if(h[j]==user[e].password[j])
                {
                    k++;
                }
            }
            if(k==i)
            {
                printprofile(e);

            }
            break;
        }
        default:
            {
                printf("try again");
                main();
            }
            

    }

}
