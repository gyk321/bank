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

int main()
{
    admin mybank;
    mybank.readinfile();
    mybank.showmain();
    mybank.writeinfile();
    return 0;
}