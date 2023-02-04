#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <list>
#include <stdio.h>

using namespace std;

class user
{
    public:
        user();
        void showuser(void);
        void createuser(void);
        int findusertransfer(long&);
        int finduser(long&,string&);
        void deposit(void);
        void dispense(void);
        int transferfrom(string&);
        void transferto(int&,string&);
        int changepassword(void);
        void writeuser(void);
        void readuser(void);
        string gettime(void);
        string getname(void);
        int getflag(void);
        void setflag(void);
        void resetflag(void);
        long getbankcardID(void);
        string changeint(int&);
        static long bankcardID0;
    private:
        string name;
        long bankcardID;
        string userpassword;
        string ID;
        int income;
        int expend;
        int remaining;
        string opdate;
        string note;
        list<string> usercheck;
        int userchecknum;
        int flag;
};

long user::bankcardID0 = 633304;

class admin
{
    public:
        admin();
        void showmain(void);
        void establish(void);
        int cancel(void);
        int login(void);
        void loginchoose(user&);
        int admintransfer(user&);
        int writeinfile(void);
        int readinfile(void);
        int resetuserflag(void);
    private:
        string adminpassword;
        vector<user> myuser;
        static int usernum;
};

void admin::establish()
{
    string temppassword;
    cout << "请输入管理密码" << endl;
    cin >> temppassword;
    
    if (temppassword == adminpassword)
    {
        user newuser;
        newuser.createuser();
        cout << "开户成功" << endl;
        usernum ++;
        cout << "您现在是否想要存款:1.是 2.否" << endl;
        
        int ah;
        cin >> ah;
        if (1 == ah)
        {
            newuser.deposit();
        }
        myuser.push_back(newuser);
        newuser.showuser();
    }
    else
    {
        cout << "密码输入错误" << endl;
    }
}

void admin::showmain()
{
    int ah;
    label1:cout << "请选择功能:1.开户 2.登录 3.销户 4.解冻 5.退出" <<endl;
    cin >> ah;
    switch (ah)
    {
    case 1:
        establish();
        goto label1;
    case 2:
        login();
        goto label1;
    case 3:
        cancel();
        goto label1;
    case 4:
        resetuserflag();
        goto label1;
    default:
        break;
    }
}

int admin::readinfile(void)
{
    int i = 0;
    streambuf* backup;                  
    ofstream fin;
    fin.open("./bank.txt",ios::in);     // 只读的方式访问
    backup = cin.rdbuf();               // backup是一个缓冲流，用于保存原来cin流的状态
    cin.rdbuf(fin.rdbuf());             // 将cin流重定向到fin流中

    cin >> usernum;
    cin >> user::bankcardID0;
    for (i = 0; i < usernum; i++)
    {
        user tempuser;
        tempuser.readuser();
        myuser.push_back(tempuser);
    }
    cin.rdbuf(backup);
    fin.close();

    cout << "read called" << endl;
    return 0;
}
int main()
{
    admin mybank;
    mybank.readinfile();
    mybank.showmain();
    mybank.writeinfile();
    return 0;
}