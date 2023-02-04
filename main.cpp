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
        void  deposit(void);
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

user::user()
{
    income = 0;
    expend = 0;
    remaining = 0;
    userchecknum = 0;
    flag = 1;
}

void user::createuser(void)
{
    cout << "请输入姓名" << endl;
    cin >> name;
    cout << "请输入密码" << endl;
    cin >> userpassword;
    cout << "请输入身份ID" << endl;
    cin >> ID;
    bankcardID = bankcardID0++;
}

void user::writeuser(void)
{
    cout << userchecknum << endl;
    cout << name << endl;
    cout << bankcardID << endl;
    cout << userpassword << endl;
    cout << ID << endl;
    cout << remaining << endl;

    list<string>::iterator iter = usercheck.begin();
    while (iter != usercheck.end())
    {
        cout << *iter << endl;
        iter ++;
    }
}

void user::deposit(void)
{
    cout << "请输入存款金额" << endl;
    cin >> income;
    remaining += income;
    cout << "当前余额:" << remianing << endl;

    string newcheck;
    string string1 = "+";
    string string2 = changeint(income);
    string string3 = "--余额:";
    string string4 = changeint(remaining);
    string string5 = gettime();
}

void user::showuser(void)
{
    cout << "姓名: " << name << endl;
    cout << "银行卡号: " << bankcardID << endl;
    cout << "身份ID: " << ID << endl;
    cout << "余额: " << remaining << endl;

    list<string>::iterator iter = usercheck.begin();
    while (iter != usercheck.end())
    {
        cout << *iter << endl;
        iter++;
    }
}

int user::finduser(long& bi,string& pw)
{
    if (bankcardID == bi && userpassword == pw)
    {
        return 0;
    }
    return -1;
}

void user::readuser(void)
{
    string tempcheck;
    
    cin >> userchecknum;
    cin >> name;
    cin >> bankcardID;
    cin >> userpassword;
    cin >> ID;
    cin >> remaining;
    for (int i = 0; i < userchecknum; i++)
    {
        cin >> tempcheck;
        usercheck.push_back(tempcheck);
    }
}

int user::findusertransfer(long& bi)
{
    if (bankcardID == bi)
    {
        return 0;
    }
    return -1;
}

void user::dispense(void)
{
    cout << "请输入取款金额" << endl;
    cin >> expend;
    if (remaining < expend)
    {
        cout << "当前余额不足" << endl;
        return;
    }
    remaining -= expend;
    cout << "当前余额:" << remaining << endl;

    string newcheck;
    string string1 = "-";
    string string2 = changeint(expend);
    string string3 = "--余额:";
    string string4 = changeint(remaining);
    string string5 = gettime();
    string string6 = "---ATM取款---";
    newcheck = string1 + string2 + string3 + string4 + string5 + string6;
    usercheck.push_back(newcheck);
    userchecknum++;
}

int user::transferfrom(string& tempname)
{
    cout << "请输入转账金额" << endl;
    cin >> income;
    if (remaining < income)
    {
        cout << "账户余额不足" << endl;
        return -1;
    }
    else
    {
        remaining -= income;

        string newcheck;
        string string1 = "-";
        string string2 = changeint(income);
        string string3 = "---余额";
        string string4 = changeint(remaining);
        string string5 = gettime();
        string string6 = "---转账给";
        string string7 = "---";

        newcheck = string1 + string2 + string3 + string4 + string5 + string6 + string7 + tempname;
        usercheck.push_back(newcheck);
        userchecknum++;
        return income;
    }
    
    
}

void user::transferto(int& in,string& tempname)
{
    income =  in;
    remaining += income;

    string newcheck;
    string string1 = "+";
    string string2 = changint(income);
    string string3 = "---余额:";
    string string4 = changeint(remaining);
    string string5 = gettime();
    string string6 = "---来自";
    string string7 = "的转账---";
    newcheck = string1 + string2 + string3 + string4 + string5 + string6 + string7 + tempname;
    usercheck.push_back(newcheck);
    userchecknum++;
}

int user::changepassword(void)
{
    
}
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
int admin::usernum = 0;
admin::admin()
{
    adminpassword = "123456";
}

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

int admin::cancel(void)
{
    string temppassword;
    long tempbankcardID;
    int i = 0;
    cout << "请输入管理密码" << endl;
    cin >> temppassword;
    if (temppassword == adminpassword)
    {
        cout << "请输入要注销的卡号" << endl;
        cin >> tempbankcardID;
        vector<user>::iterator iter = myuser.begin();
        while(iter != myuser.end())
        {
            if (iter->findusertransfer(tempbankcardID) == 0)
            {
                myuser.erase(myuser.begin() + i);
                cout << "账户删除成功" << endl;
                usernum--;
                return 0;
            }
            iter++;
            i++;
        }
        cout << "卡号输入有误" <<endl;
        return -1;
    }
    else
    {
        cout << "密码输入有误" << endl;
        return -1;
    }
}

int admin::login()
{
    long tempbankcardID;
    string tempuserpassword;
    cout << "请输入卡号" << endl;
    cin >> tempbankcardID;
    vector<user>::iterator iter1 = myuser.begin();
    while (iter1 != myuser.end())
    {
        if (iter1->findusertransfer(tempbankcardID) == 0)
        {
            if (iter1->getflag() == 1)
            {
                for (int i = 3; i > 0; i--)
                {
                    cout << "请输入密码,您还有" << i << "次尝试" << endl;
                    cin >> tempuserpassword;
                    vector<user>::iterator iter2 = myuser.begin();
                    while (iter2 != myuser.end())
                    {
                        if (iter2->finduser(tempbankcardID,tempuserpassword) == 0)
                        {
                            loginchoose(*iter2);
                            return 0;
                        }
                        iter2++;
                    }
                    cout << "密码输入有误" << endl;
                }
                iter1->setflag();
                cout << "账户已冻结" << endl;
                return -1;
            }
            else
            {
                cout << "您的账户已冻结" << endl;
                return -1;
            }
        }
        iter1++;
    }
    cout << "卡号输入有误" << endl;
    return -1;
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

int admin::resetuserflag()
{
    string temppassword;
    long tempbankcardID;
    cout << "请输入管理密码" << endl;
    cin >> temppassword;
    if (temppassword == adminpassword)
    {
        cout << "请输入要解冻的卡号" << endl;
        cin >> tempbankcardID;
        vector<user>::iterator iter = myuser.begin();
        while (iter != myuser.end())
        {
            if (iter->findusertransfer(tempbankcardID) == 0)
            {
                if (iter->getflag() == 1)
                {
                    cout << "您的账户未冻结" << endl;
                    return -1;
                }
                else
                {
                    iter->resetflag();
                    cout << "解冻成功" << endl;
                    return 0;
                }
            }
            iter++;
        }
        cout << "卡号输入有误" << endl;
        return -1;
    }
    else
    {
        cout << "密码输入有误" << endl;
        return -1;
    }
}

int admin::writeinfile(void)
{
    streambuf* backup;
    ofstream fout;
    fout.open("./bank.txt");
    backup = cout.rdbuf();
    cout.rdbuf(fout.rdbuf());

    cout << usernum << endl;
    cout << user::bankcardID0 << endl;

    cout.rdbuf(backup);
    fout.close();

    fout.open("./bank.txt",ios::app);
    backup = cout.rdbuf();
    cout.rdbuf(fout.rdbuf());

    vector<user>::iterator iter = myuser.begin();
    while (iter != myuser.end())
    {
        iter->writeuser();
        iter++;
    }
    cout.rdbuf(backup);
    fout.close();
    cout << "write called" << endl;
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