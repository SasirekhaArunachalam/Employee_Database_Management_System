#include<iostream>
using namespace std;
class error{};
class company
{
public:
    company(){};
    int c_id;
    char c_name[30];
    static int c_bal;

    void get_c()
    {
        cout<<"\n-----------COMPANY DETAILS----------\n";
        cout<<"\nCOMPANY ID\t::";
        cin>>c_id;
        cout<<"\nCOMPANY NAME\t::";
        cin>>c_name;
        cout<<"\nACCOUNT BALANCE\t::"<<c_bal;
    }
};
int company::c_bal=5000000;
class employee
{
public:
    employee(){};
    int e_id,exp,s_date,tax,b_date,bsb,h_wage,acc_no,w_hours,salary;
    char e_name[40],e_type[40],l_name[40],gen[20],a_name[30];
    int e_age;
    char address[60];

    double phno;
    int year;
    static int e_bal;
    void get_e()
    {
        cout<<"\nENTER THE EMPLOYEE ID::";
        cin>>e_id;
        try
        {
         if(e_id<10000)
            throw error();

        }
        catch(error a)
        {
            cout<<"\nERROR:EMPLOYEE ID SHOULD NOT LESS THAN 5 DIGIT!!!!!!!!!!!";

            cout<<"\nPLEASE ENTER THE CORRECT EMPLOYEE ID::";
            cin>>e_id;
        }
        cout<<"\nENTER THE FIRST NAME::";
        cin>>e_name;
        cout<<"\nENTER THE LAST NAME::";
        cin>>l_name;
        cout<<"\nENTER THE GENDER::";
        cin>>gen;
        cout<<"\nENTER THE DATE OF BIRTH::(DDMMYYYY)::";
        cin>>b_date;
        cout<<"\nENTER THE YEAR OF EXPERIENCE::";
        cin>>exp;
        cout<<"\nENTER THE EMPLOYMENT TYPE::";
        cin>>e_type;
        cout<<"\nENTER THE EMPLOYEE ADDRESS::";
        cin>>address;
        cout<<"\nENTER THE EMPLOYEE PHONE NUMBER::";
        cin>>phno;
        try
        {
            if(phno>10000000000)
                throw error();
        }
        catch(error b)
        {
            cout<<"\nERROR:PLEASE ENTER THE VALID PHONE NUMBER:";
            cin>>phno;
        }
        cout<<"\nENTER THE HOUR WAGE::";
        cin>>h_wage;
        cout<<"\nENTER THE TOTAL WORKING HOURS::";
        cin>>w_hours;
        cout<<"\nENTER THE JOINED YEAR::";
        cin>>year;
        cout<<"\nENTER THE ACCOUNT NUMBER::";
        cin>>acc_no;
        cout<<"\nENTER THE ACCOUNTANT NAME:";
        cin>>a_name;
        cout<<"\nENTER THE BSB NO.::";
        cin>>bsb;
        salary=30*h_wage*w_hours;
    }


};
int employee::e_bal=50000;

class bank:public company,public employee
{
public:
    int c,t;
    bank *left,*right;
    int height;
    bank()
    {
    	left=right=NULL;
    	height=1;
	}
    void current_bal()
    {
        c=c_bal-salary;
        t=e_bal+salary;
        cout<<"\nCURRENT EMPLOYEE BANK BALANCE::"<<t;
        cout<<"\nCURRENT COMPANY BANK BALANCE::"<<c;

            }

            void display()
            {

                cout<<"\n\n\nID:"<<e_id;
                cout<<"\nFIRST NAME:"<<e_name;
                cout<<"\nLAST NAME:"<<l_name;
                cout<<"\nGENDER:"<<gen;
                cout<<"\nYEAR OF EXPERIENCE:"<<exp;
                cout<<"\nSTART DATE:(DDMMYYYY)"<<s_date;
                cout<<"\nTAX FILE NUMBER:"<<tax;
                cout<<"\nDATE OF BIRTH(DDMMYYYY):"<<b_date;
                cout<<"\nADDRESS:"<<address;
                cout<<"\nEMPLOYEE PHNO.:"<<phno;
                cout<<"\nEMPLOYEMENT(PART TIME/FULL TIME):"<<e_type;
                cout<<"\nYEAR OF JOINED:"<<year;
                cout<<"\n\nPAYMENT METHODS DETAILS::\n\n";
                cout<<"ACCOUNT NAME:"<<a_name;
                cout<<"\nBSB NO.:"<<bsb;
                cout<<"\nACCOUNT NUMBER:"<<acc_no;
                cout<<"\nCURRENT BANK BALANCE:"<<t;
                cout<<"\n\nWAGE RATE::\n\n";
                cout<<"HOURLY WAGE:"<<h_wage;
                cout<<"\nTOTAL WORKING HOURS:"<<w_hours;
                cout<<"\nDAILY WAGE:"<<h_wage*w_hours;
                cout<<"\nMONTHLY WAGE:"<<30*h_wage*w_hours;




            }

};
#include "avl tree.cpp"
int main()
{
    bank* broot=new bank();
    int i,n,ch;

    cout<<"\nAVL TREE IS IMPLEMENTED IN THIS PROGRAM TO SEARCH DELETE AND TRAVERSE THE DETAILS OF THE EMPLOYEE.\n";
    cout<<"\n\n________________COMPANY DETAILS______________";
    cout<<"\n\nTATA CONSULTANCY AND SERVICE LIMITED\n\n";
    cout<<"\n__________________EMPLOYEE DETAILS_____________";
    cout<<"\n\nENTER THE NUMBER OF EMPLOYEE TO BE INSERTED INTO THE DATABASE ::";
    cin>>n;

      broot->get_e();
      broot->current_bal();

    for(i=0;i<n-1;i++)
    {
    bank *b=new bank();
    b->get_e();
    b->current_bal();
    broot=avlinsert(broot,b);
    }

  //for deletion
       int id;
  cout<<"\n\nENTER 1 to search a delete an particulae emplotye details from the database::\nEnter 2 to search a particular employee::\nEnter 3 to display all the employee details of the company\n\n";
  cin>>ch;
  switch(ch)
  {


  case 1:
      {

    cout<<"Enter emp_id to delete employee...\n";
    cin>>id;

   broot=deleteavl(broot,id);
      }
//  for search
  case 2:
    {


bank *s=new bank();
cout<<"Enter emp_id to search...\n";
    cin>>id;
s=searchavl(broot,id);
if(s!=NULL){
        cout<<"\n\n";
	s->display();
}

    }
  case 3:
    {


//    for display
    cout<<"\n\nLIST OF EMPLOYEES\n\n[DISPLAYING THE LIST OF EMPLOYEES IN BASED ON THE INORDER TRAVERSAL OF THE AVL TREE]\n\n";
  displayavl(broot);
}
}    return 0;
}


