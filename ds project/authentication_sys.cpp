#include <bits/stdc++.h>
#include<conio.h>
using namespace std;

class extra
{
public:
    void printmap(map<string,string> userdata)
    {
        map<string, string>::iterator itr;
        for (itr = userdata.begin(); itr != userdata.end(); ++itr)
        {
            cout << '\t' << itr->first << '\t' << itr->second << '\n';
        }
    }
    string passwrd()
    {
        char x;
        string p="";
        cout<<"\n\t\tEnter password: ";
        for (int i = 0; i>=0;i++)
        {
            x = _getch();
            if (x == 13)
            {
                break;
            }
            else if(x==8)
            {
                cout<<"Backspace option not available! Enter data again";
                getch();
                return "1";
            }
            else
            {
                p=p+x;
                _putch('*');
            }
        }
        return p;
    }
    string timestamp()
    {
        string ss;
        time_t my_time = time(NULL);
        ss = ctime(&my_time);
        return ss;
    }
    string generate_password()
    {
        srand(time(0));
        char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u','v', 'w', 'x', 'y', 'z' };
        string res = "";
        for (int i = 0; i < 10; i++)
            res = res + alphabet[rand() % 26];
        return res;
    }
    string enrollment_generator()
    {
        //cout<<"\n\t\tHere";
        ifstream f;
        vector<string> v;
        string e,n,br,ba,x;
        f.open("student_table.csv");
        while(!f.eof())
        {
            getline(f,e,',');
            getline(f,n,',');
            getline(f,br,',');
            getline(f,ba,'\n');
            v.push_back(e);
        }
        v.pop_back();
        //cout<<"v.size(): "<<v.size();
        if(v.size()==1)
        {
            //string s = timestamp();
             x = "200000";
        }
        else
        {
            string s;
            // s will hold the last enrollment no as string
            s=v[v.size()-1];
            stringstream a(s);
            int t = 0;
            a >> t;
            //t now has the enrollment as integer
            t=t+1;
            ostringstream str1;
            str1 << t;
            x = str1.str();
            //x now holds the value as string
        }
        f.close();
        return x;
    }
    string id_generator()
    {
        ifstream f;
        vector<string> v;
        string id,n,d,b1,b2,x;
        f.open("teacher_table.csv");
        while(!f.eof())
        {
            getline(f,id,',');
            getline(f,n,',');
            getline(f,d,',');
            getline(f,b1,',');
            getline(f,b2,'\n');
            v.push_back(id);
        }
        v.pop_back();
        if(v.size()==1)
        {
            //string s = timestamp();
            x = "9920";
            x=x+"000";

        }
        else
        {
            string s;
            // s will hold the last enrollment no as string
            s=v[v.size()-1];
            stringstream a(s);
            int t = 0;
            a >> t;
            //t now has the enrollment as integer
            t=t+1;
            ostringstream str1;
            str1 << t;
            x = str1.str();
            //x now holds the value as string
        }
        f.close();
        return x;
    }
};
class Auth: public extra
{
private:
    vector< map<string,string> > userlist;
    string temp1,temp2,temp3;
    vector<string> name,enroll,password,role;
protected:
    map<string,string> loginuser;
public:


    void appendinregister(map<string,string> userdata)
    {
        ofstream f;
        string n,e,r,p,t;
        f.open("registry.csv",ios::app);
        if(!f.is_open())
        {
            cout<<"File open error!";
            return;
        }
        map<string, string>::iterator itr;
        for (itr = userdata.begin(); itr != userdata.end(); ++itr)
        {
            if(itr->first == "name")//key
                n=itr->second;//value
            if(itr->first == "enroll")
                e=itr->second;
            if(itr->first == "role")
                r=itr->second;
            if(itr->first == "password")
                p=itr->second;
        }
        f<< n << ","<<e << ","<<r << ","<<p;
        f<<"\n";
        f.close();
    }

    void apnd_in_student(string name,string enrol)
    {
         system("cls");
         cout<<"\t\t\t\t\t\t\t\t\t\tWelcome to the Webkiosk Prototype\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t__________________________________\n\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter Student Record\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\t*******************";
         ofstream f;
         string branch, batch;
         int x;
         cout<<"\n\t\tChoose student Branch: ";
         cout<<"\n\t\t1. CSE\n\t\t2. ECE\n\t\t3. Biotech\n\t\tChoose: ";
         cin>>x;
         switch(x)
         {
         case 1:
            {
                branch="CSE";
                batch="B";
                break;
            }
         case 2:
            {
                branch="ECE";
                batch="A";
                break;
            }
         case 3:
            {
                branch="Biotech";
                batch = "F";
                break;
            }
         default:
            {
                cout<<"\n\t\tEnter a valid choice!";
                getch();
                apnd_in_student(name,enrol);
            }
         }
         cout<<"\n\t\tEnter Batch number: ";
         cin>>x;
         ostringstream str1;
         str1 << x;
         string t = str1.str();
         batch=batch+t;
         f.open("student_table.csv",ios::app);
         f<<enrol<<","<<name<<","<<branch<<","<<batch<<"\n";
         f.close();
         this->temp1 = "student_marks_"+branch+".csv";
         f.open(this->temp1,ios::app);
         if(branch=="CSE")
            f<<enrol<<","<<"0"<<","<<"0"<<","<<"0"<<","<<"0"<<"\n";
         else if(branch=="ECE")
            f<<enrol<<","<<"0"<<","<<"0"<<","<<"0"<<","<<"0"<<","<<"0"<<"\n";
         f.close();
         this->temp2 = "student_attendence_"+branch+".csv";
         f.open(this->temp2,ios::app);
         if(branch=="CSE")
            f<<enrol<<","<<"0"<<","<<"0"<<","<<"0"<<","<<"0"<<"\n";
         else if(branch=="ECE")
            f<<enrol<<","<<"0"<<","<<"0"<<","<<"0"<<","<<"0"<<","<<"0"<<"\n";
         f.close();
         cout<<"\n\t\tData Entered successfully!";
         cout<<"\n\t\tPress any key to go back to Admin page";
         getch();
    }

     void apnd_in_teacher(string name, string id)
     {
         system("cls");
         cout<<"\t\t\t\t\t\t\t\t\t\tWelcome to the Webkiosk Prototype\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t__________________________________\n\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\tEnter Teacher Record\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\t*******************";
         ofstream f;
         string department, batch1, batch2;
         int x;
         cout<<"\n\t\tChoose Teacher department: ";
         cout<<"\n\t\t1. Commputer Science\n\t\t2. Humanities and social sciences\n\t\t3. Electrical\n\t\t4. Physics\n\t\t5. Mathematics\n\t\tChoose: ";
         cin>>x;
         switch(x)
         {
         case 1:
            {
                department="Computer Science";
                break;
            }
         case 2:
            {
                department="Humanities and social sciences";
                break;
            }
         case 3:
            {
                department="Electrical";
                break;
            }
        case 4:
            {
                department="Physics";
                break;
            }
        case 5:
            {
                department="Mathematics";
                break;
            }
         default:
            {
                cout<<"\n\t\tEnter a valid choice!";
                getch();
                apnd_in_student(name,id);
            }
         }
         cout<<"\n\t\tEnter Batch to be alloted, type \"Nil\" for no batch";
         cout<<"\n\t\tEnter Batch 1 to be alloted: ";
         fflush(stdin);
         cin>>batch1;
         f.open("teacher_table.csv",ios::app);
         f<<id<<","<<name<<","<<department<<","<<batch1<<"\n";
         f.close();
         cout<<"\n\t\tData Entered successfully!";
         cout<<"\n\t\tPress any key to go back to Admin page";
         getch();
     }

     int registeruser()
     {
         string n,e,r,p;
         int x;
         system("cls");
         cout<<"\t\t\t\t\t\t\t\t\t\tWelcome to the Webkiosk Prototype\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t__________________________________\n\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\tWelcome to Register\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\t*******************";
         map<string,string> userdata;
         //intake data and put in hashmap
         cout<<"\n\t\tPlease Enter the user data(If you want to go back, type \"back\" in any entry)";
         cout<<"\n\n\t\tEnter name: ";
         fflush(stdin);
         getline(cin,n);
         if(n=="back" || n=="Back")
            return 1;

         cout<<"\n\t\tChoose role: \n\t\tOptions: \n\t\t1. Student \n\t\t2. Teacher\n\t\tEnter: ";
         fflush(stdin);
         cin>>x;
         if(x==1)
         {
             r="Student";
             fflush(stdin);
             e=enrollment_generator();
             cout<<"\n\t\tGenerated id/enrollment number: ";
             cout<<e;
             cout<<"\n\n\t\tGenerated password: ";
             fflush(stdin);
             p=generate_password();
             cout<<p;
             getch();
             apnd_in_student(n,e);
         }
         else if(x==2)
         {
             r="Teacher";
             e=id_generator();
             cout<<"\n\t\tGenerated Id : ";
             cout<<e;
             cout<<"\n\n\t\tGenerated password: ";
             p=generate_password();
             cout<<p;
             getch();
             apnd_in_teacher(n,e);
         }
         else
         {
             cout<<"\n\t\tEnter valid number";
             getch();
             registeruser();
         }
             userdata.insert({"name",n});
             userdata.insert({"enroll",e});
             userdata.insert({"role",r});
             userdata.insert({"password",p});
             getch();
             appendinregister(userdata);
         return 1;
     }


    int checkcredential(string enrol, string pasw, string r)
    {
        string n,e,p,fid,fname,fdep,fbatch;
        int i;
        int flag=0,found = 0;
        int l = this->enroll.size();
        for(i=0;i<l;i++)
        {
            if(enrol == this->enroll[i])
            {
                found=1;
                p = this->password[i];
                break;
            }
        }
        if(found==1)
        {
            if(pasw == p)
            {
                    //cout<<"chk cred name: "<<this->name[i];
                    this->loginuser.insert({"name",this->name[i]});
                    this->loginuser.insert({"enroll",this->enroll[i]});
                    this->loginuser.insert({"password",this->password[i]});
                    this->loginuser.insert({"role",this->role[i]});
                    if(r=="Teacher")
                    {
                        ifstream f;
                        f.open("teacher_table.csv");
                        while(!f.eof())
                        {
                            getline(f,fid,',');
                            getline(f,fname,',');
                            getline(f,fdep,',');
                            getline(f,fbatch,'\n');
                            if(fid == this->enroll[i])
                            {
                                break;
                            }
                        }
                        this->loginuser.insert({"batch",fbatch});
                    }
                return 0;
                //here i will give values to loginuser map
            }
            else
            {
                cout<<"\n\t\tYour credentials dont match";
                getch();
            }
        }
        else
        {
            cout<<"\n\t\tSorry, couldnt find your data";
            getch();
        }

        // else wapis on login
        return 1;

    }

    void changeuserpassword()
    {
        fflush(stdin);
        cout<<"\n\n\t\tEnter your new password(type \"back\" to return back): ";
        string s;
        getline(cin,s);
        if( s=="back")
        {
            return;
        }
        if(s.size()<8)
        {
            cout<<"\n\n\t\tPassword too short, enter again! Minimum length 8 characters";
            changeuserpassword();
        }
        else
        {
            ofstream myfile;
            myfile.open("registrynew.csv");
            auto str = this->loginuser.find("password");
            str->second = s;
            string n;
            auto str1 = this->loginuser.find("enroll");
            n = str1->second;
            int l = this->enroll.size();
            for(int i = 0 ; i<l; i++)
            {
                if(this->enroll[i]==n)
                {
                    this->password[i]=s;
                }
                myfile<<this->name[i]<<","<<this->enroll[i]<<","<<this->role[i]<<","<<this->password[i]<<"\n";
            }
            myfile.close();
            remove("registry.csv");
            rename("registrynew.csv","registry.csv");
        }

    }

    int checkcredentialadmin(string enrol, string pasw)
    {
        //admin ke credential check karne hai.
        //registry me admin ke credential hai.
        ifstream f;
        string n,e,p,r;
        f.open("registry.csv");
        if(!f.is_open())
        {
            cout<<"File open error!";
            return 1;
        }
        int flag=0,found = 0;
        while(!f.eof())
        {
            //skip the first row
            if (flag==0)
            {
                flag=1;
                getline(f,n,',');
                getline(f,e,',');
                getline(f,r,',');
                getline(f,p,'\n');
            }
            else
            {
                getline(f,n,',');
                getline(f,e,',');
                getline(f,r,',');
                getline(f,p,'\n');
                if(e==enrol)
                {
                    found=1;
                    break;
                }
            }

        }
        if(found==1)
        {
            if(pasw == p)
            {
                return 0;

            }
            else
            {
                cout<<"\n\t\tYour credentials dont match";
                getch();
            }
        }
        else
        {
            cout<<"\n\t\tSorry, couldnt find your data";
            getch();
        }
        return 1;
    }


    int readregistry()
    {
        ifstream f;
        string n,e,p,r;
        f.open("registry.csv");
        if(!f.is_open())
        {
            cout<<"File open error!";
            getch();
            return 1;
        }
        while(!f.eof())
        {
            //sara data 4 vectors me enter karo
                getline(f,n,',');
                getline(f,e,',');
                getline(f,r,',');
                getline(f,p,'\n');
                //cout<<"read registry name: "<<n<<endl;
                //getch();
                this->name.push_back(n);
                this->enroll.push_back(e);
                this->role.push_back(r);
                this->password.push_back(p);
        }
        this->name.pop_back();
        this->enroll.pop_back();
        this->role.pop_back();
        this->password.pop_back();
        f.close();
    }


    void updateadminpassword()
    {
         system("cls");
         int i;
         cout<<"\t\t\t\t\t\t\t\t\t\tWelcome to the Webkiosk Prototype\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t__________________________________\n\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\tWelcome back Admin\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\t*******************";
         cout<<role[1];
         //admin ko dhundo, basically admin ka index
         for(i=0;i<enroll.size();i++)
         {
             if(role[i]=="Admin")
             {
                 break;
             }
         }
         string pnew;
         cout<<"\n\t\tEnter new Password: ";
         cin>>pnew;
         //fir password vector me jaake password change karo
         if(pnew.size()>8)
         {
             password[i]=pnew;
         }
         else
         {
             cout<<"\n\t\tPassword length too short";
             getch();
             updateadminpassword();
         }
         //new file open karo aur sara data waha dalo;
         fstream fout;
         fout.open("registrynew.csv",ios::out);
         for(i=0;i<enroll.size();i++)
         {
             fout<<name[i]<<","<<enroll[i]<<","<<role[i]<<","<<password[i]<<"\n";
         }
         //new file save karo
         fout.close();
         //purani fime ko remove karo
         remove("registry.csv");
         //new file ko rename karo
         rename("registrynew.csv","registry.csv");
    }


    void updateadminid()
    {
        system("cls");
         int i;
         cout<<"\t\t\t\t\t\t\t\t\t\tWelcome to the Webkiosk Prototype\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t__________________________________\n\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\tWelcome back Admin\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\t*******************";
         cout<<role[1];
         //admin ko dhundo, basically admin ka index
         for(i=0;i<enroll.size();i++)
         {
             if(role[i]=="Admin")
             {
                 break;
             }
         }
         string pnew;
         cout<<"\n\t\tEnter new ID: ";
         cin>>pnew;
         enroll[i]=pnew;
         //new file open karo aur sara data waha dalo;
         fstream fout;
         fout.open("registrynew.csv",ios::out);
         for(i=0;i<enroll.size();i++)
         {
             fout<<name[i]<<","<<enroll[i]<<","<<role[i]<<","<<password[i]<<"\n";
         }
         //new file save karo
         fout.close();
         //purani fime ko remove karo
         remove("registry.csv");
         //new file ko rename karo
         rename("registrynew.csv","registry.csv");

    }


    void get_data(string id, string r)
    {
        string fname,fid,fbatch,fbranch,fdepartment,fb1,fb2;
        int found=0;
        if(r=="student")
        {
            ifstream f;
            f.open("student_table.csv");
            if(id=="all")
            {
                while(!f.eof())
                {
                    getline(f,fid,',');
                    getline(f,fname,',');
                    getline(f,fbranch,',');
                    getline(f,fbatch,'\n');
                    cout<<"\n\t\t"<<fid<<"\t\t"<<fname<<"\t\t"<<fbranch<<"\t\t"<<fbatch;
                }
            }
            else
            {
                while(!f.eof())
                {
                    getline(f,fid,',');
                    getline(f,fname,',');
                    getline(f,fbranch,',');
                    getline(f,fbatch,'\n');
                    if(fid==id)
                    {
                        found=1;
                        break;
                    }
                }
                if(found==0)
                {
                    cout<<"\n\n\t\tSorry No data found";
                    getch();
                }
                else
                {
                    cout<<"\n\t\tEnrollment: "<<fid;
                    cout<<"\n\t\tName: "<<fname;
                    cout<<"\n\t\tBranch: "<<fbranch;
                    cout<<"\n\t\tBatch: "<<fbatch;
                }
            }
            f.close();

        }
        else
        {
            ifstream f;
            f.open("teacher_table.csv");
            if(id=="all")
            {
                while(!f.eof())
                {
                    getline(f,fid,',');
                    getline(f,fname,',');
                    getline(f,fdepartment,',');
                    getline(f,fb1,'\n');
                    cout<<"\n\t\t"<<fid<<"\t\t"<<fname<<"\t\t"<<fdepartment<<"\t\t"<<fb1;
                }
            }
            else
            {
                while(!f.eof())
                {
                    getline(f,fid,',');
                    getline(f,fname,',');
                    getline(f,fdepartment,',');
                    getline(f,fb1,'\n');
                    if(fid==id)
                    {
                        found=1;
                        break;
                    }
                }
                if(found==0)
                {
                    cout<<"\n\n\t\tSorry No data found";
                    getch();
                }
                else
                {
                    cout<<"\n\t\tTeacher Id: "<<fid;
                    cout<<"\n\t\tName: "<<fname;
                    cout<<"\n\t\tDepartment: "<<fdepartment;
                    cout<<"\n\t\tBatch 1: "<<fb1;
                }
            }
            f.close();
        }
        getch();
    }


    void viewdata()
    {
         system("cls");
         string id;
         cout<<"\t\t\t\t\t\t\t\t\t\tWelcome to the Webkiosk Prototype\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t__________________________________\n\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\tView Data\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\t*******************";
         cout<<"\n\n\t\tWho's data you want to view?";
         cout<<"\n\t\t1. Student\n\t\t2. Teacher\n\t\t3. Back";
         int x;
         cout<<"\n\t\tChoose(1 or 2): ";
         cin>>x;
         switch(x)
         {
         case 1:
            {
                cout<<"\n\t\tEnter student enrollment number(enter \"all\" to view all student records): ";
                fflush(stdin);
                getline(cin,id);
                get_data(id,"student");
                break;
            }
         case 2:
            {
                cout<<"\n\t\tEnter teacher id(enter \"all\" to view all teachers records): ";
                fflush(stdin);
                getline(cin,id);
                get_data(id,"teacher");
                break;
            }
         case 3:
            {
                return;
            }
         default:
            {
                cout<<"\n\t\tEnter Valid choice!";
                getch();
                viewdata();
                break;
            }
         }
    }


    void Updatemarks()
    {
        string e;
        system("cls");
         cout<<"\t\t\t\t\t\t\t\t\t\tWelcome to the Webkiosk Prototype\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t__________________________________\n\n";
         auto s = this->loginuser.find("name");
         cout<<"\t\t\t\t\t\t\t\t\t\t\tWelcome back "<<s->second<<"\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\t*******************";
         cout<<"\n\n\t\tEnrollment no of student(type \"back\" to go back) : ";
         getline(cin,e);
         if(e=="back")
         {
             return;
         }
         int found=0;
         for(int i=0;i<this->enroll.size();i++)
         {
             if(this->enroll[i] == e)
             {
                 found=1;
                 break;
             }
         }
         if(found!=1)
         {
             //data nahi mila
             cout<<"\n\t\tData not found!";
             getch();
             Updatemarks();

         }
         cout<<"\n\t\tEnter Subject(DS/DMW/ECO/ES): ";
         string sub;
         getline(cin,sub);
         cout<<"\n\t\tEnter the marks you want to increment(positive) or decrement(negative): ";
         int marks;
         cin>>marks;
         string fenrol,fds,fdmw,feco,fes;
         ifstream frd;
         ofstream fwrt;
         frd.open("student_marks_CSE.csv");
         fwrt.open("student_marks_CSEnew.csv");
         while(!frd.eof())
         {
             getline(frd,fenrol,',');
             getline(frd,fds,',');
             getline(frd,fdmw,',');
             getline(frd,feco,',');
             getline(frd,fes,',');
             if(fenrol==e)
             {
                 if(sub=="DS")
                 {
                     // s will hold the last enrollment no as string
                    stringstream a(fds);
                    int t = 0;
                    a >> t;
                    //t now has the enrollment as integer
                    t=t+marks;
                    ostringstream str1;
                    str1 << t;
                    fds = str1.str();
                    //x now holds the value as string
                 }
                 else if(sub=="DMW")
                 {
                     // s will hold the last enrollment no as string
                    stringstream a(fdmw);
                    int t = 0;
                    a >> t;
                    //t now has the enrollment as integer
                    t=t+marks;
                    ostringstream str1;
                    str1 << t;
                    fdmw = str1.str();
                    //x now holds the value as string
                 }
                 else if(sub=="ECO")
                 {
                     // s will hold the last enrollment no as string
                    stringstream a(feco);
                    int t = 0;
                    a >> t;
                    //t now has the enrollment as integer
                    t=t+marks;
                    ostringstream str1;
                    str1 << t;
                    feco = str1.str();
                    //x now holds the value as string
                 }
                 else if(sub=="ES")
                 {
                     // s will hold the last enrollment no as string
                    stringstream a(fes);
                    int t = 0;
                    a >> t;
                    //t now has the enrollment as integer
                    t=t+marks;
                    ostringstream str1;
                    str1 << t;
                    fes = str1.str();
                    //x now holds the value as string
                 }
             }
             fwrt<<fenrol<<","<<fds<<","<<fdmw<<","<<feco<<","<<fes<<"\n";
         }
         fwrt.close();
         frd.close();
         remove("student_marks_CSE.csv");
         rename("student_marks_CSEnew.csv","student_marks_CSE.csv");
    }

    void entertime(string r)
    {
        ofstream fwrt;
        fwrt.open("userlogintime.csv",ios::app);
        string s = timestamp();
        int i;
        auto str = this->loginuser.find("enroll");
        string enrol = str->second;
        auto str2 = this->loginuser.find("name");
        string na = str2->second;
        cout<<"name: "<<na;
        getch();
        fwrt<<enrol<<","<<na<<","<<r<<","<<s<<"\n";
        fwrt.close();
    }

};

class box : public Auth
{
private:
    int readrflag = 0;
    public:
      void frontpage()
      {
          system("cls");
          if(this->readrflag==0)
          {
              readregistry();
              this->readrflag=1;
          }
          cout<<"\t\t\t\t\t\t\t\t\t\tWelcome to the Webkiosk Prototype\n";
          cout<<"\t\t\t\t\t\t\t\t\t\t__________________________________\n";
          cout<<"\n\n\n\t\t\t What do you wanna do?\n";
          cout<<"\t\t\t1. Login\n";
          cout<<"\t\t\t2. Admin Login\n";
          cout<<"\t\t\t3. Exit\n";
          int x;
          cout<<"\t\t\tChoice(1-3): ";
          cin>>x;
          switch(x)
          {
          case 1:
            {
                Login();
                frontpage();
                break;
            }
          case 2:
            {
                if(Adminlogin())
                {
                    frontpage();
                }
                break;
            }
          case 3:
            {
                exit(1);
                break;
            }
          default:
            {
                cout<<"\n\t\t\tWrong choice, enter again!";
                getch();
                frontpage();
                break;
            }
          }
      }


      void Login()
     {
         system("cls");
         cout<<"\t\t\t\t\t\t\t\t\t\tWelcome to the Webkiosk Prototype\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t__________________________________\n\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\tWelcome to Login\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t*******************";
         string e,p;
         int r;
         cout<<"\n\t\tEnter Enrollment no/ID(type \"back\" to go to previous page): ";
         fflush(stdin);
         getline(cin,e);
         if(e=="back")
         {
             return;
         }
         p=passwrd();
         if(p=="1")
         {
             Login();
         }
         cout<<"\n\n\t\tEnter Role(1. Student, 2. Teacher)(1 or 2): ";
         cin>>r;
         if(r==1)
         {
             if(checkcredential(e,p,"Student"))
             {
                 Login();
             }
             else
             {
                 entertime("Student");
                 Studentpage();
             }
         }
         else if(r==2)
         {
             if(checkcredential(e,p,"Teacher"))
             {
                 Login();
             }
             else
             {
                 entertime("Teacher");
                 Teacherpage();
             }
         }
         else
         {
             cout<<"\n\t\tEnter Valid role";
             getch();
             Login();
         }

     }


     void Studentpage()
     {
         int x;
         system("cls");
         cout<<"\t\t\t\t\t\t\t\t\t\tWelcome to the Webkiosk Prototype\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t__________________________________\n\n";
         auto s = this->loginuser.find("name");
         cout<<"\t\t\t\t\t\t\t\t\t\t\tWelcome back "<<s->second<<"\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\t*******************";
         cout<<"\n\n\t\tWhat would you like to do?";
         cout<<"\n\t\t1. Change Password";
         cout<<"\n\t\t2. View Marks";
         cout<<"\n\t\t3. Back";
         cout<<"\n\t\tChoose(1 to 4): ";
         cin>>x;
         switch(x)
         {
         case 1:
            {
                changeuserpassword();
                Studentpage();
                break;
            }
         case 2:
            {
                Studentpage();
                break;
            }
         case 3:
            {
                frontpage();
            }
         default:
            {
                cout<<"\n\t\tEnter a valid choice";
                getch();
                Studentpage();
            }
         }
     }

     void Teacherpage()
     {
         int x;
         system("cls");
         cout<<"\t\t\t\t\t\t\t\t\t\tWelcome to the Webkiosk Prototype\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t__________________________________\n\n";
         auto s = this->loginuser.find("name");
         cout<<"\t\t\t\t\t\t\t\t\t\t\tWelcome back "<<s->second<<"\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\t*******************";
         cout<<"\n\n\t\tWhat would you like to do?";
         cout<<"\n\t\t1. Change Password";
         cout<<"\n\t\t2. Update marks";
         cout<<"\n\t\t3. Back";
         cout<<"\n\t\tChoose(1 to 4): ";
         cin>>x;
         switch(x)
         {
         case 1:
            {
                changeuserpassword();
                Teacherpage();
                break;
            }
         case 2:
            {
                Updatemarks();
                Teacherpage();
                break;
            }
         case 3:
            {
                frontpage();
            }
         default:
            {
                cout<<"\n\t\tEnter a valid choice";
                getch();
                Studentpage();
            }
         }
     }



     int Adminlogin()
    {
         system("cls");
         cout<<"\t\t\t\t\t\t\t\t\t\tWelcome to the Webkiosk Prototype\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t__________________________________\n\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\tWelcome to Login\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\t*******************";
         string e,p,r;
         cout<<"\n\t\tEnter Admin Id(type \"back\" to go to previous page): ";
         fflush(stdin);
         getline(cin,e);
         if(e=="back")
         {
             return 1;
         }
         p=passwrd();
         if(p=="1")
         {
             Adminlogin();
         }
         if(checkcredentialadmin(e,p))
         {
             Adminlogin();
         }
         else
         {
             Adminpage();
         }

    }


    void Adminpage()
    {
        system("cls");
         cout<<"\t\t\t\t\t\t\t\t\t\tWelcome to the Webkiosk Prototype\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t__________________________________\n\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\tWelcome back Admin\n";
         cout<<"\t\t\t\t\t\t\t\t\t\t\t*******************";
         cout<<"\n\n\t\tWhat would you like to do?";
         cout<<"\n\t\t1. View Data of teacher or student";
         cout<<"\n\t\t2. Register a new user";
         cout<<"\n\t\t3. Change your admin id";
         cout<<"\n\t\t4. Change your password";
         cout<<"\n\t\t5. Go back";
         int x;
         cout<<"\n\t\tChoose: ";
         cin>>x;
         switch(x)
         {
         case 1:
            {
                viewdata();
                Adminpage();
                break;
            }
         case 2:
            {
                registeruser();
                Adminpage();
                break;
            }
         case 3:
            {
                updateadminid();
                Adminpage();
                break;
            }
         case 4:
            {
                updateadminpassword();
                Adminpage();
                break;
            }
         case 5:
            {
                frontpage();
                break;
            }
         default:
            {
                cout<<"\n\t\tEnter right choice";
                getch();
                Adminpage();
            }
         }
    }
};
int main()
{
    box b;
    //cout<<time(0);
    b.frontpage();
    //b.updateadminpassword();
    //b.enrollment_generator();
}
