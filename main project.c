// account to account
#include<stdio.h>
struct profile{
        char name[50];
        char address[100];
        char mail[50];
        char dob[10];
        int phone;
        int account_no;
        int aadhar;
    }user;

int login()
{
    int x;
    printf("press 0 to sign up and 1 to log in ");
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
           printf("sign in\n");
           printf("enter name\n");
           gets(user.name);
            gets(user.name);
           printf("enter address\n");
           gets(user.address);
           printf("enter mail\n");
           gets(user.mail);
           printf("enter dob in dd/mm/yyyy\n");
           gets(user.dob);
           printf("enter phone\n");
           scanf("%d",&user.phone);
           printf("aadhar\n");
           scanf("%d",&user.aadhar);

           printf("name=%s\naddress=%s\nmail=%s\ndob=%s\nphone=%d\naadhar=%d",user.name,user.address,user.mail,user.dob,user.phone,user.aadhar);
        }

    }

}
