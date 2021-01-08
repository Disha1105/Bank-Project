#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<ctime>
#include<stdlib.h>
using namespace std;

int pass(char c[])
{
    char ch[5];
    int i;
    cout<<"FOUR PIN PASSWORD:    ";
    for(i=0;i<4;i++)
    {
        k:
   ch[i]=getch();
    if(!(ch[i]>=48 &&ch[i]<=57))
    {
        goto k;
    }
    cout<<"*";
    }
    ch[4]=0;
       if(!(strcmp(ch,c)))
        return 1;
    else
        return 0;
}
int repass(char c[])
{
    int t=1;
    re:
        if(t!=1)
            cout<<"\n PASSWORD NOT MATCHED\n again ";
    cout<<"ENTER FOUR PIN PASSWORD:    ";
    for(int i=0;i<4;i++)
    {
        n:
       c[i]= getch();
        if(!(c[i]>=48 &&c[i]<=57))
        {
            goto n;
        }
        fflush(stdin);
        cout<<"*";
    }

    c[4]=0;
    cout<<"\n Re-Enter ";
    t=pass(c);
    if(t==0)
        goto re;
}
class bank
{   public:
    char a[20],q[20],c[5];
    char d[10][11],t[10][30];
	char tr[10][2];
	char am[10][10],account[10][20];
    char w1[10],e1[10];
    bank()
    {
    	for(int i=0;i<10;i++)
    	{
    		for(int j=0;j<30;j++)
    		{   if(j<11)
    			d[i][j]=0;
    			t[i][j]=0;
    			if(j<2)
    			tr[i][j]=0;
    			if(j<10)
    			am[i][j]=0;
    			if(j<20)
    			account[i][j]=0;
			}
		}
	}
    void in()
{
    int w,e;
	cout<<"\nENTER CUSTOMER NAME: ";fflush(stdin);
    cin.getline(a,50);
    fflush(stdin);
    cout<<"SET 8 DIGITS ACCOUNT No. : ";cin>>q;
    repass(c);

    fflush(stdin);
    w=e=50;
            cout<<"\nBALANCE IN SAVING ACCOUNT = Rs "<<e;
            cout<<"\nBALANCE IN CURRENT ACCOUNT = Rs "<<w;
            itoa(w,w1,10);
            itoa(e,e1,10);

}};

class admin
{
	public:
		int adid,admid,pr;
        char adpass[5];
		admin()
		{
			adid=1710141146;
			strcpy(adpass,"2311");
			adpass[4]=0;
		}
		int adm()
		{
			so:
			int z=1;
			cout<<"\nENTER ADMIN ID: ";
			cin>>admid;
			if(admid==adid)
			{
				so1:
				if(z!=4)
				{
				 pr=pass(adpass);
				}
				 else
				 pr=0;

				if(pr!=1)
				{
					z++;
					cout<<"\n                                                          ADMIN LOGIN UNSUCCESSFULL\n";
					if(z!=4)
					goto so1;
					return 0;
				}
				else
				{
					cout<<"\n                                                          ADMIN LOGIN SUCCESSFULL\n";
					return 1;
				}

			}
			else
			{
			
				cout<<"\nWRONG ADMIN ID\n";
			   goto so;
			}
		}

};



   void update(bank &de,char ty,int z,int y,int acnt)
{
	 time_t now=time(0);
    char*dt=ctime(&now);
    char z1[10],z2[20];
    itoa(z,z1,10);
    itoa(acnt,z2,10);
    int i;
    for(int i=0;i<10;i++)
    {
    if((de.am[i][0]==0))
    	break;

	}
	if(y==1)
	{
		for(int k=8;k>=0;k--)
		{
           if((de.am[i][0]==0))
               continue;
                strcpy(de.d[k+1],de.d[k]);
                strcpy(de.t[k+1],de.t[k]);
                strcpy(de.tr[k+1],de.tr[k]);
               strcpy(de.am[k+1],de.am[k]);
               strcpy(de.account[k+1],de.account[k]);
		}
        strcpy(de.d[0],"  DEPOSIT");
        if(ty=='s'||ty=='S')
       strcpy(de.tr[0],"S");
       else if(ty=='c'||ty=='C')
       strcpy(de.tr[0],"C");
       
       strcpy(de.account[0],z2);
        strcpy(de.t[0],dt);
        strcpy(de.am[0],z1);
        de.t[0][24]=de.t[0][28];
    }
    else if(y==2)
    {
        for(int k=8;k>=0;k--)
        {
          if((de.am[i][0]==0))
              continue;
             strcpy(de.d[k+1],de.d[k]);
             strcpy(de.t[k+1],de.t[k]);
            strcpy(de.tr[k+1],de.tr[k]);
             strcpy(de.am[k+1],de.am[k]);
            strcpy(de.account[k+1],de.account[k]);
        }
         strcpy(de.d[0],"WITHDRAWL");
         if(ty=='s'||ty=='S')
        strcpy(de.tr[0],"S");
        else if(ty=='c'||ty=='C')
        strcpy(de.tr[0],"C");
        
        strcpy(de.account[0],z2);
        strcpy(de.t[0],dt);
        strcpy(de.am[0],z1);
        de.t[0][24]=de.t[0][28];
    }
    else if(y==5)
    {
		for(int k=8;k>=0;k--)
		{
           if((de.am[i][0]==0))
               continue;
                strcpy(de.d[k+1],de.d[k]);
                strcpy(de.t[k+1],de.t[k]);
                strcpy(de.tr[k+1],de.tr[k]);
               strcpy(de.am[k+1],de.am[k]);
               strcpy(de.account[k+1],de.account[k]);
		}
        strcpy(de.d[0],"  SEND TO");
        if(ty=='s'||ty=='S')
       strcpy(de.tr[0],"S");
       else if(ty=='c'||ty=='C')
       strcpy(de.tr[0],"C");

       strcpy(de.account[0],z2);
	    strcpy(de.t[0],dt);
        strcpy(de.am[0],z1);
        de.t[0][24]=de.t[0][28];
    }
    else if(y==6)
    {
		for(int k=8;k>=0;k--)
		{
           if((de.am[i][0]==0))
               continue;
                strcpy(de.d[k+1],de.d[k]);
                strcpy(de.t[k+1],de.t[k]);
                strcpy(de.tr[k+1],de.tr[k]);
               strcpy(de.am[k+1],de.am[k]);
               strcpy(de.account[k+1],de.account[k]);
		}
        strcpy(de.d[0]," ADD FROM");
        if(ty=='s'||ty=='S')
       strcpy(de.tr[0],"S");
       else if(ty=='c'||ty=='C')
       strcpy(de.tr[0],"C");

        strcpy(de.account[0],z2);
		strcpy(de.t[0],dt);
        strcpy(de.am[0],z1);
        de.t[0][24]=de.t[0][28];
    }
     else
    {
        cout<<endl;
		for(int k=0;k<10;k++)
        {
            if(de.d[k][0]==0||de.tr[k][0]==0||de.am[k][0]==0||de.t[k][0]==0||de.account[k][0]==0)
                break;

               cout<<"     " <<de.d[k]<<"                    "<<de.account[k]<<"                                 "<<de.am[k]<<"                            "<<de.t[k]<<"                   "<<de.tr[k]<<endl;
        }

    }
}
