#include "golua.h"
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

using namespace std;
int main()
{
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
	boy1:
  fstream g1;
  g1.open("bank.dat",ios::in|ios::out|ios::ate);
  if(g1==0)
  {
      g1.open("bank.dat",ios::out);
      g1.close();
        g1.open("bank.dat",ios::in|ios::out|ios::ate);
  }




    bank a,a1,a2,a3,a4,a88,a6,a7;
    admin a5;
    char chh,n,o;
    char id[20],amt1[10];
    int k=1,j=1,flag=0,slag;
    int t;
    cout<<"                                                              WELCOME TO GOLU BANK      "<<endl<<endl;
    SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    while(n!=4)
    {
    	SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY );
        cout<<"\n\nENTER CHOICE:";
        b13:
        		SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY );
		cout<<"\n________________________________________________________________________________________________________________________________________________________________________\n";
		cout<<"       1. FOR CREATE NEW ACCOUNT                     2. FOR COSTUMER LOGIN                              3. FOR ADMIN LOGIN                               4. FOR EXIT";
        cout<<"\n________________________________________________________________________________________________________________________________________________________________________\n\n";
	    n=getche();
	    getch();
	    if(n>=48&&n<=57)
	    {

        if(n=='1')
        {
        	a.in();
        	s1:
        	flag=0;
        	g1.seekg(0,ios::beg);
        	while(g1.read((char*)&a1,sizeof (a1)))
        	{
        	if(!strcmp(a1.q,a.q))
			{
			flag=1;
			break;
			}
			}
			g1.clear();
			if(flag==1)
			{
					SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
				cout<<"\nA/C NO. MATCHED\nRe-Enter NEW A/C NO : ";
				cin>>a.q;
				flag=0;
				goto s1;
			}

            g1.write((char *)&a,sizeof a);
            	SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
            cout<<"\n_____________________________________________________________________________________________________________________________________________________________________\n";

            cout<<"\n                                                                  ACCOUNT IS SUCUSSFULLY CREATED    ";
            cout<<"\n_____________________________________________________________________________________________________________________________________________________________________\n\n\n";
        }
        else if(n=='2')
        {
        	int nah=1;
            b1:
            slag=0;
            	SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout<<"\nENTER A/C No.  :- ";
            cin>>id;
        	g1.seekg(0,ios::beg);
        	while(g1.read((char*)&a2,sizeof (a2)))
        	{
        	if(!strcmp(a2.q,id))
			{
			t=g1.tellg();
			t=t- sizeof (a2);
			slag=1;
			break;
			}
			}
			if(slag==0)
			{
				if(nah!=3)
				{
					SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
				cout<<"\nA/C NOT FOUND \nRe- ";
				nah++;
				slag=0;
				g1.clear();
				goto b1;
			   }
			   else
			   {
			   	SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
			   cout<<"\n\n                                                      SORRY!! YOU CROSS YOUR LOGIN LIMIT\n";
			   goto b13;
	           }
			}
			else
			{
				b2:
		int p=pass(a2.c);
		if(p==1)
		{
			SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
			cout<<"\n                                                              WELCOME TO YOUR ACCOUNT "<<a2.a<<endl;
			b6:
				SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY );
			cout<<"\n_______________________________________________________________________________________________________________________________________________________________________\n";
			cout<<"  1. DEPOSIT           2. WITHDRAWL            3.BALANCE ENQUERY            4.EDIT ACCOUNT            5.MONEY TRANSFER           6.UPDATE PASSBOOK              7.EXIT";
			cout<<"\n_______________________________________________________________________________________________________________________________________________________________________\n\n\n";
			o=getche();
			getch();
            if(o>=48&&o<=57)
            {
			while(o!='7')
			{
				SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY );
				if(o=='1')
				{

					int e,w,amt;
					w=atoi(a2.w1);
					e=atoi(a2.e1);
					amt=atoi(amt1);
					cout<<"\n\n_________________________________________________________________________________________________________________________________________________________________\n\n\n";
					cout<<"ENTER DEPOSITED AMOUNT\n"; cin>>amt;
					if(amt<=0)
					{
						SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
					cout<<"AMOUNT MUST BE GREATER THAN ZERO\n";
					goto b6;
				    }
					else
					{

					b3:
					cout<<"Press 'S' to Deposit in Saving account\n Press 'C' to Deposit in Current account\n";

					cin>>chh;
					if(chh=='s'||chh=='S')
					{
				e=e+amt;
					}
					else if(chh=='c'||chh=='C')
					{
				w=w+amt;
					}
					else
					{
						SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
						cout<<"\nWRONG TYPE OF ACCOUNT\nAgain  ";
					goto b3;
					}
					int son;
					son=atoi(id);
					 update(a2,chh,amt,1,son);
					 itoa(amt,amt1,10);
					 itoa(w,a2.w1,10);
					 itoa(e,a2.e1,10);
					g1.seekp(t,ios::beg);
					g1.write((char*)&a2, sizeof a2);
                     g1.clear();
					goto b6;
				}
			}
				else if(o=='2')
				{
						int e,w,amt,mal=1,pal=1;
					w=atoi(a2.w1);
					e=atoi(a2.e1);
					amt=atoi(amt1);
					cout<<"\n\n__________________________________________________________________________________________________________________________________________________________________\n\n\n";
					b4:
							SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY );
					cout<<"ENTER WITHDRAWL AMOUNT\n"; cin>>amt;
					if(amt<=0)
					{
						SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
						cout<<"\nAMOUNT MUST BE GREATER THAN ZERO\n";
						goto b6;
					}
					else
					{
					b5:
					cout<<"Press 'S' to Withdrawl from Saving account\n Press 'C' to Withdrawl from Current account\n";
					cin>>chh;
						if(chh=='s'||chh=='S')
					{
						if(amt<=e)
				e=e-amt;

				else
				{
					if(mal!=3)
					{

						SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
				cout<<"\nNOT SUFFICIENT BALANCE\nRe- ";
				mal++;
				goto b4;
			       }
			       else
			       {
			       	SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
			       	cout<<"\n\n                                                       SORRY!! YOU CROSS YOUR WITHDRWAL AMOUNT LIMIT\n";
			       	goto b6;
				   }
			    }

					}
					else if(chh=='c'||chh=='C')
					{
							if(amt<=w)
				w=w-amt;

				else
				{
					if(pal!=3)
					{
						SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
				cout<<"\nNOT SUFFICIENT BALANCE\nRe- ";
				pal++;
				goto b4;
			        }
			        else
			        {
			        	SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
			        		cout<<"\n\n                                                SORRY!! YOU CROSS YOUR WITHDRWAL AMOUNT LIMIT\n";
			       	goto b6;
					}
			   }
			}
			int son;
					son=atoi(id);
			    update(a2,chh,amt,2,son);
			   itoa(amt,amt1,10);
					 itoa(w,a2.w1,10);
					 itoa(e,a2.e1,10);
			    g1.seekp(t,ios::beg);
					g1.write((char*)&a2, sizeof a2);
					g1.clear();

					goto b6;
				}
			}

				 else if(o=='3')
				 {
				 		SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY );
				cout<<"\n\n___________________________________________________________________________________________________________________________________________________________________\n\n\n";
				 cout<<"\nCUSTOMER NAME  :  "<<a2.a;
				 cout<<"\nA/C No. = "<<a2.q;
				 cout<<"\nAMOUNT IN SAVING ACCOUNT =  "<<a2.e1;
				 cout<<"\nAMOUNT IN CURRENT ACCOUNT = "<<a2.w1<<endl;
				 cout<<"\n____________________________________________________________________________________________________________________________________________________________________\n";
				 goto b6;
				 }
				else if(o=='4')
				{
				cout<<"\n\n____________________________________________________________________________________________________________________________________________________________________\n\n\n";
                cout<<"ENTER THE CUSTOMER NAME : ";fflush(stdin);
                cin.getline(a2.a,50);
                fflush(stdin);
                repass(a2.c);
                 g1.seekp(t,ios::beg);
					g1.write((char*)&a2, sizeof a2);
					g1.clear();
					goto b6;
                }
				else if(o=='5')
				{
					char acc[20],ch,chh,mt1[10];
					int flag=0,ac,t1,ff=1;

			 cout<<"\n\n____________________________________________________________________________________________________________________________________________________________________\n\n";
			 b8:
			 cout<<"ENTER A/C No. ON WHICH YOU WANT TO SEND MONEY : ";
			 cin>>acc;
			 g1.clear();
			 g1.seekg(0,ios::beg);
			 while((g1.read((char*)&a3, sizeof (a3))))
			 {
			 	if(!strcmp(a3.q,acc))
			 	{
			 		flag=1;
			 			t1=g1.tellg();
			            t1=t1- sizeof (a3);
			 		break;
				 }
			 }
			 g1.clear();
			if(flag==1)
			{
				if(!strcmp(a2.q,acc))
				{
						SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
					cout<<"THIS IS YOUR OWN ACCOUNT\nRe- ";
						flag=0;
					goto b8;
				}
				else
					SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
				cout<<"\n    •• A/C FOUND •• \n";
				flag=0;
			}

			else
			{
				if(ff!=3)
				{
					SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
				cout<<" \n •• A/C NOT FOUND ••\nRe- ";
				ff++;
				goto b8;
			    }
			    else
			    {
			    	SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
			    	cout<<"\n\n                                                          SORRY!!YOU CROSS YOUR YOUR ACCESS LIMIT\n";
			    	goto b6;
				}
			}
				SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY );
             int mt=atoi(mt1);
             int e=atoi(a2.e1);
             int w=atoi(a2.w1);
              int ee=atoi(a3.e1);
             int ww=atoi(a3.w1);
             lll:
             	SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY );
			cout<<"ENTER AMOUNT TO SEND   : Rs. "; cin>>mt;
                 if(mt<=0)
                 {
                 	SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
                 	cout<<"\nAMOUNT MUST BE GREATER THAN ZERO\n";
                 	goto lll;
				 }
				 else
				 {

					cout<<"Press 'S' to Transfer FROM Saving account\n Press 'C' to Transfer FROM Current account\n";
					cin>>chh;
						if(chh=='s'||chh=='S')
						{
						if(mt<=e)
				        e=e-mt;
				        else
				        {
				        		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
				        	cout<<"NOT SUFFICIENT AMOUNT";
				        	goto b6;
						}
					    }
					    else
					    {
					    if(mt<=w)
				        w=w-mt;
				        else
				        {
				        		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
				        	cout<<"NOT SUFFICIENT AMOUNT";
				        	goto b6;
						}
						}


				b9:
						SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY );
				cout<<"Press 'S' to Send TO Saving account\n Press 'C' to Send TO Current account\n"; cin>>ch;
					if(ch=='s'||ch=='S')
				{
					ee=ee+mt;
				}
				else if(ch=='c'||ch=='C')
				{
					ww=ww+mt;
				}
				else
				{
						SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
					cout<<"\nWRONG A/C TYPE\nAgain ";
					goto b9;
				}
				int son;
					son=atoi(id);
					int son1;
					son1=atoi(acc);
               update(a2,chh,mt,5,son1);
                update(a3,ch,mt,6,son);
             itoa(mt,mt1,10);
             itoa(e,a2.e1,10);
             itoa(w,a2.w1,10);
            itoa(ee,a3.e1,10);
             itoa(ww,a3.w1,10);
			    g1.seekp(t,ios::beg);
					g1.write((char*)&a2, sizeof a2);
					g1.seekp(t1,ios::beg);
					g1.write((char*)&a3, sizeof a3);

			goto b6;
				}
			}

				else if(o=='6')
				{
					SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
					cout<<" \n                                                               TRANSACTION HISTORY\n";
				   	cout<<"_________________________________________________________________________________________________________________________________________________________________\n";
					cout<<"| ==TRANSACTION== | |          ==ACCOUNT NO.==           |  |           ==AMOUNT==           |  |             ==DATE & TIME==             |  |==A/C TYPE==|";
					cout<<"\n_______________________________________________________________________________________________________________________________________________________________";
				update(a2,0,0,0,0);
				goto b6;
				}
				else if(o=='7')
				{
					cout<<"\n                                                               THANKS TO VISIT YOUR ACCOUNT\n";
					break;
				}
				else
				{
					cout<<"\nINVALID CHOICE\nSELECT PROPER CHOICE\n  ";
					goto b6;
				}


			}
		}
		else
		{
			SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
			cout<<"\nINVALID CHOICE\nSELECT PROPER CHOICE\n";
			goto b6;
		}
	}
			else
			{
				SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
				cout<<"\nWRONG PASSWORD\nAgain Enter ";
				goto b2;
			}
		}
	}
		else if(n=='3')
		{
			char bi;
			int xy=a5.adm();
			if(xy==1)
			{
		   pri:
		   	SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY );
			cout<<"______________________________________________________________________________________________________________________________________________________________________\n";
		    cout<<"1.TOTAL AMOUNT IN BANK                               2.DELETE ACCOUNT                              3.ALL ACCOUNT DETAILS                                     4.EXIT";
		    cout<<"\n____________________________________________________________________________________________________________________________________________________________________\n\n\n";
			bi=getche();
			getch();
			if(bi>=48&&bi<=57)
			{
			if(bi=='4')
			{
				SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
				cout<<"                                                                          THANKU ADMIN\n\n";
				goto b13;
			}
				else if(bi=='3')
			{
				SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
				cout<<"\n                                                                    ACCOUNT HOLDER DETAILS\n";
				SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY );
				cout<<"____________________________________________________________________________________________________________________________________________________________________\n";
				SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY );
				cout<<"|         a/c no.        |   |     pass     |  |  AMOUNT(CURRENT) |   | AMOUNT(SAVING)| |               ACCOUNT HOLDER NAME              |\n";
			   SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY );
			    cout<<"_____________________________________________________________________________________________________________________________________________________________________\n";
				g1.seekg(0,ios::beg);
				while(g1.read((char*)&a88,sizeof (a88)))
				{
					SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY );
					cout<< "         "<<a88.q<<"                 "<<a88.c<<"                    "<<a88.w1<<"                "<<a88.e1<<"                              "<<a88.a<<endl;
				}
				cout<<"_______________________________________________________________________________________________________________________________________________________________________\n";
		       g1.clear();
			   goto pri;
			}

			else if(bi=='2')

				{
					SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY );
					char did[20],cho;
                    int count=0,i=0,jk=0;
                    int w,e;

			cout<<"\n\nENTER THE ACCOUNT No. TO DELETE : ";
			cin>>did;
			cout<<"\nARE YOU SURE TO DELETE??\n Press 'Y' to YES && Press 'N' to NO :  ";
			cin>>cho;
			if(cho=='y'||cho=='Y')
			{
				jk=0;
				g1.clear();
			g1.seekg(0,ios::beg);
			while(g1.read((char*)&a7,sizeof a7))
			{
				if(!strcmp(a7.q,did))
				{
				jk=1;
				 w=atoi(a7.w1);
                    e=atoi(a7.e1);
                }
			count++;
			}
			if(jk==1)
			{
			bank a8[count];
			g1.clear();
				g1.seekg(0,ios::beg);
			while(g1.read((char*)&a7,sizeof a7))
			{
			a8[i]=a7;
			i++;
			}
			g1.close();
			 g1.open("bank.dat",ios::out);
			 g1.seekg(0,ios::beg);
			 for(int j=0;j<i;j++)
			 {
			 if(strcmp(a8[j].q,did))
			 {
			 g1.write((char*)&(a8[j]),sizeof a8[j]);
		     }
			 else
			 {
			 continue;
			 }
		     }
		     SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
		     cout<<"\n                                                                   ACCOUNT SUCCESSFULLY DELETED\n\n";
			 g1.clear();
			goto boy1 ;
		     }
		     else
		     {
		     	SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
		     	cout<<"\n                                                                     ACCOUNT NOT FOUND\n";
		     	goto pri;
			 }
         }
         else
         goto pri;
			}
			else if(bi=='1')
			{
             int e=atoi(a2.e1);
             int w=atoi(a2.w1);
				int samt=0,camt=0;
			 g1.seekg(0,ios::beg);
				while(g1.read((char*)&a2, sizeof a2))

				{
					 int e=atoi(a2.e1);
                     int w=atoi(a2.w1);
					samt=samt+e;
					camt=camt+w;
				}
				g1.clear();
				SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY );
				cout<<"\n\n TOTAL AMOUNT IN SAVING ACCOUNT IN YOUR BANK = RS. "<<samt;
				cout<<"\n\n TOTAL AMOUNT IN CURRENT ACCOUNT IN YOUR BANK = RS. "<<camt<<endl;
				goto pri;
			}
			}
			else
			{
				SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
				cout<<"\nINVALID CHOICE\nSELECT PROPER CHOICE\n";
				goto pri;
			}
			}//admin login success
		}//0==3 admin
		else if(n=='4')
		{
			break;
		}
		else
		{
		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
		cout<<"\nINVALID CHOICE\nENTER VALID CHOICE\n";
		goto b13;
	    }
    }
    else
    {
    	SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
    	cout<<"\nINVALID CHOICE\nENTER VALID CHOICE\n";
    	goto b13;
	}
}
    SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout<<"\n___________________________________________________________________________________________________________________________________________________________________________\n\n";
    cout<<"                                                                         THANKS TO VISIT PERSONAL BANK "<<endl;
    cout<<"\n___________________________________________________________________________________________________________________________________________________________________________\n";
}
