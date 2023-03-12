/*group members name           ID no        section 42
  Abebe Nano              ugr/22636/13
  Abegia Tadele           ugr/22693/13
  Esey Merd               ugr/22984/13
  Mihret Girum            ugr/23375/13
  Michael berhanu         ugr/23151/13
  Nasiha Abdella          ugr/23662/13*/

#include<bits/stdc++.h>
using namespace std;
vector <string> f_name;
vector <string> l_name;
vector <int> salary;
vector <int> id;
vector <int> phone_number;
vector<string> work_position;
int i_d=0;
int j=-1;
bool check_element(int i_d)
{
    for(int i=0; i<id.size(); i++)
    {
        if(i_d==id[i])
        {
            j=i;
            return true;
            break;

        }
    }
    return false;

}
int check(int n)
{

    while(1)
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"You have entered wrong input"<<endl;
            cout<<"Please try again: ";
            cin>>n;

        }
        if(!cin.fail())
            break;
    }
    return n;
}
void add_employer()
{
    string fn, ln, wp;
    int  phn;
    int s;
    while(cout<<"Enter first name: "&&cin>>fn)
    {
        cout<<"Enter last name: ";
        cin>>ln;
        cout<<"Enter salary amount: ";
        cin>>s;
        s=check(s);
        cout<<"Enter phone number: ";
        cin>>phn;
        phn=check(phn);
        cout<<"Enter work position: ";
        cin>>wp;
        f_name.push_back(fn);
        l_name.push_back(ln);
        salary.push_back(s);
        phone_number.push_back(phn);
        work_position.push_back(wp);
        i_d++;
        id.push_back(i_d);
        cout<<"Employer successfully added"<<endl;
        cout<<"1: to continue"<<endl;
        cout<<"0: to stop"<<endl;
        int f;
        cin>>f;
        if(f==0)
            break;
        else if(f==1)
            continue;
    }
}
void display()
{
    cout<<endl;
    cout<<"ID        NAME                             SALARY          PHONE NUMBER     WORK POSITION"<<endl;
    cout<<"**        ****                             ******          ************     *************"<<endl;
    for(int i=0; i<f_name.size(); i++)
    {
        cout<<id[i]<<"         "<<f_name[i]<<" "<<l_name[i]<<"                        "<<salary[i]<<"          0"<<phone_number[i]<<"     "<<work_position[i]<<endl;
    }
    cout<<endl;

}
void Delete()
{
    if(f_name.size()==0)
    {
        cout<<"There is No Employer"<<endl;
        // return 0;
    }
    else
    {
        int dlt;
        cout<<"Enter Employer Id: ";
        cin>>dlt;
        if(check_element(dlt))
        {
            id.erase(id.begin()+j);
            f_name.erase(f_name.begin()+j);
            l_name.erase(l_name.begin()+j);
            salary.erase(salary.begin()+j);
            phone_number.erase(phone_number.begin()+j);
            work_position.erase(work_position.begin()+j);
            cout<<"Employer with this Id: "<<dlt<<"  is successfully removed from Employers"<<endl;

        }
        else
        {
            cout<<"There is no Employer with this Id"<<endl;
        }
    }
}
void update()
{
    if(id.size()==0)
    {
        cout<<"There is No Employer"<<endl;
    }
    else
    {
        int upd;
        cout<<"Enter Employer Id: ";
        cin>>upd;
        if(check_element(upd))
        {
            cout<<"What you want to Update"<<endl;
            cout<<"1 : to update employer first name"<<endl;
            cout<<"2 : to update employer last name"<<endl;
            cout<<"3 : to update employer salary"<<endl;
            cout<<"4 : to update employer phone number"<<endl;
            cout<<"5 : to update employer work position"<<endl;
            int choic;
            cout<<"Enter your choice: ";
            cin>>choic;
            switch(choic)
            {
            case 1:
            {
                string upf_name;
                cout<<"Enter the New first Name: ";
                cin>>upf_name;
                f_name[j]=upf_name;
                cout<<"Employer Information successfully Updated"<<endl;
                break;
            }

            case 2:
            {
                string upl_name;
                cout<<"Enter the New Last Name: ";
                cin>>upl_name;
                l_name[j]=upl_name;
                cout<<"Employer Information successfully Updated"<<endl;
                break;
            }


            case 3:
            {
                double up_salary;
                cout<<"Enter the New Salary: ";
                cin>>up_salary;
                up_salary=check(up_salary);
                salary[j]=up_salary;
                cout<<"Employer Information successfully Updated"<<endl;
                break;
            }


            case 4:
            {
                int  up_phn;
                cout<<"Enter the New Phone number: ";
                cin>>up_phn;
                up_phn=check(up_phn);
                phone_number[j]=up_phn;
                cout<<"Employer Information successfully Updated"<<endl;
                break;
            }


            case 5:
            {
                string up_work;
                cout<<"Enter the New Work Position: ";
                cin>>up_work;
                work_position[j]=up_work;
                cout<<"Employer Information successfully Updated"<<endl;
                break;
            }


            default:
                cout<<"Wrong Input"<<endl;
                break;

            }

        }
        else
            cout<<"There is no Employer with this Id"<<endl;


    }


}

int main()
{
    while(true)
    {

        cout<<"ASTU school of electrical engineering and computing employee management system"<<endl;
        cout<<"*******************************************************************************"<<endl;
        cout<<"1 : to add employer"<<endl;
        cout<<"2 : to view employer"<<endl;
        cout<<"3 : to delete employer"<<endl;
        cout<<"4 : to Update employer Information"<<endl;
        cout<<"0 : to exit"<<endl;
        cout<<"***************************"<<endl;
        int ch;
        cin>>ch;
        if(ch==0)
            break;
        switch(ch)
        {
        case 1:
            add_employer();
            break;
        case 2:
            display();
            break;
        case 3:
            Delete();
            break;
        case 4:
            update();
            break;
        default:
            cout<<"incorrect input"<<endl;
            break;

        }

    }
    return 0;


}
