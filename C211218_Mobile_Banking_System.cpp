///      Tasmi Khair Tapu
///      ID: C211218
///      Project Name: Mobile Banking System


/*

Name of the System: SafePay

Features of SafePay:
    1. Multiple users can use SafePay.
    2. Users can register & login to their perspective account.
    3. Users can Cash in money to their account.
    4. Users can Cash out their money from their account.
    5. Users can Send money to others(obviously who is a SafePay user too).
    6. Users can do Mobile Recharge.
    7. Users can see their transaction history(Amount, Transaction type & Transaction ID).
    8. Users can check their account balance.
    9. Users can change their account password if needed.
   10. Users can set their details to their perspective account
       (i.e. Name, Gender, Nationality, Birth date).
   11. Users can see list of the people who use SafePay.
   12. Users can add SafePay users to their friend list.

*/

#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<conio.h>
#include <iomanip>
using namespace std;
#define RESET "\033[0m"
#define RED "\033[1;31m"    // Red
#define GREEN "\033[1;32m"  // Green
#define YELLOW "\033[1;33m" // Yellow
#define BLUE "\033[1;34m"   // Blue
#define WHITE "\033[1;37m"
#define CYAN "\033[1;36m"
#define underlinewhite "\033[4;37m"
class SafePay
{
public:
    vector<string>regusers;
    vector<string>passwords;
    int balance[105]= {0};
    int tranhistorytk[105][105];
    int tranhistoryid[105][105];
    int tracking[105]= {0};
    string username;
    string password;
    float payment_advance;
    string trackType[105][105];
    int freq[105]= {};
    string names[105];
    string gender[105];
    string nationality[105];
    string birthdate[105];
    string friends[105][105];
    int friendcount[105]= {};
    int friendsof[105]= {};
    void registration();
    void login();
    void cashin(int);
    void transaction(int);
    void sendmoney(int);
    void recharge(int);
    void cashout(int);
    void balancenquiry(int);
    void changepass(int);
    void mysafepay(int);
    void userlist();
    void myfriends(int);
    void sendingprocess(int,string);
};

void SafePay::registration()
{
    system("cls");
    cout<<YELLOW;
    cout<<"\n\t\t\t REGISTER\n";
    cout<<"\t\t\t~~~~~~~~~~\n\n";
    cout<<RESET;
    cout<<WHITE;
    cout<<"Enter your username: ";
    cin>>username;
    int it=-1;
    for(int i=0; i<regusers.size(); i++)
    {
        if(username==regusers[i])
        {
            it=i;
            break;
        }
    }
    if(it!=-1)
    {
        cout<<"\n\n\t\t\tUSERNAME ALREADY TAKEN!\n\n\n";
    }
    else
    {
        cout<<"Enter your password: ";
        cin>>password;
        regusers.push_back(username);
        passwords.push_back(password);
        cout<<WHITE;
        cout<<GREEN;
        cout<<"\n\n\t\tCongratulations, "<<username<<"! You have successfully registered to SafePay!\n\n\n";
        cout<<RESET;
    }
}

void SafePay::login()
{
    system("cls");
    cout<<YELLOW;
    cout<<"\n\t\t\tLOGIN\n";
    cout<<"\t\t\t~~~~~\n";
    cout<<RESET;
    cout<<WHITE;
    cout<<"\nEnter your username: ";
    cin>>username;
    int it=-1;
    for(int i=0; i<regusers.size(); i++)
    {
        if(username==regusers[i])
        {
            it=i;
            break;
        }
    }
    if(it!=-1)
    {
        cout<<"Enter your password: ";
        cin>>password;
        cout<<RESET;
        int x=it;
        if(passwords[it]==password)
        {
            cout<<GREEN;
            cout<<"\n\n\t\t"<<username<<", you have successfully logged in!\n\n\n";
            cout<<RESET;
            system("pause");
            while(1)
            {
                system("cls");
                cout<<'\n';
                cout<<WHITE;
                cout<<"\t\t\t\t  ================\n";
                cout<<"\t\t\t\t  ==            ==\n";
                cout<<"\t\t\t\t  ==   SafePay  ==\n";
                cout<<"\t\t\t\t  ==            ==\n";
                cout<<"\t\t\t\t  ================\n\n";
                cout<<RESET;
                cout<<CYAN;
                cout<<"\t\t\t__________________________________"<<'\n'<<'\n';
                cout<<RESET;
                cout<<WHITE;
                cout<<"\t\t\t\t 1. Cash in"<<'\n';
                cout<<"\t\t\t\t 2. Send Money"<<'\n';
                cout<<"\t\t\t\t 3. Mobile Recharge"<<'\n';
                cout<<"\t\t\t\t 4. Cash out"<<'\n';
                cout<<"\t\t\t\t 5. Transaction History"<<'\n';
                cout<<"\t\t\t\t 6. Balance Enquiry"<<'\n';
                cout<<"\t\t\t\t 7. Change Password"<<'\n';
                cout<<"\t\t\t\t 8. My SafePay"<<'\n';
                cout<<"\t\t\t\t 9. SafePay Users"<<'\n';
                cout<<"\t\t\t\t10. My Friends"<<'\n';
                cout<<"\t\t\t\t11. LOG OUT"<<'\n';
                cout<<RESET;
                cout<<CYAN;
                cout<<"\t\t\t__________________________________"<<'\n'<<'\n';
                int option;
                cout<<RESET;
                cout<<WHITE;
                cout<<"\nEnter your choice: ";
                cout<<RESET;
                cin>>option;
                switch(option)
                {
                case 1:
                    cashin(x);
                    break;
                case 2:
                    sendmoney(x);
                    break;
                case 3:
                    recharge(x);
                    break;
                case 4:
                    cashout(x);
                    break;
                case 5:
                    transaction(x);
                    break;
                case 6:
                    balancenquiry(x);
                    break;
                case 7:
                    changepass(x);
                    break;
                case 8:
                    mysafepay(x);
                    break;
                case 9:
                    userlist();
                    break;
                case 10:
                    myfriends(x);
                    break;
                case 11:
                    cout<<YELLOW;
                    cout<<"\n\t\t\tThank you for staying with SafePay!:D\n\n\n"<<endl;
                    cout<<RESET;
                    return;
                default:
                    cout<<RED;
                    cout<<"\n\n\t\t\tINVALID INPUT!\n\n\n";
                    cout<<RESET;
                }
                system("pause");
            }
        }
        else
        {
            cout<<CYAN;
            cout<<"\n\t\t\tOops! Wrong password."<<'\n'<<'\n';
            cout<<RESET;
        }

    }
    else
    {
        cout<<CYAN;
        cout<<"\n\t\t\tUSER NOT FOUND!\n\n";
        cout<<RESET;
    }
}

void SafePay::cashin(int x)
{
    system("cls");
    cout<<YELLOW;
    cout<<"\n\t\t\t CASH IN\n";
    cout<<"\t\t\t~~~~~~~~~\n\n";
    cout<<RESET;
    int amount;
    cout<<WHITE;
    cout<<"Enter amount for cash in: ";
    cin>>amount;
    balance[x]+=amount;
    cout<<RESET;
    cout<<GREEN;
    cout<<"\n\t\tCash In Done!"<<'\n';
    int tran=rand()%100000000+187261821;
    cout<<"\t\tTransaction ID: "<<tran<<'\n';
    cout<<"\t\tAmount Deposited: "<<amount<<'\n';
    cout<<"\t\tTotal balance: "<<balance[x]<<"\n\n";
    cout<<RESET;
    tranhistoryid[x][tracking[x]]=tran;
    tranhistorytk[x][tracking[x]]=amount;
    string ss="Amount Deposited";
    trackType[x][tracking[x]]=ss;
    tracking[x]++;
}

void SafePay::sendmoney(int x)
{
    system("cls");
    cout<<YELLOW;
    cout<<"\n\t\t\tSEND MONEY\n";
    cout<<"\t\t\t~~~~~~~~~~\n\n";
    cout<<RESET;
    cout<<WHITE;
    cout<<"\t\t\t1. Choose from your friendlist\n";
    cout<<"\t\t\t2. Another user\n\n";
    cout<<"Enter your choice: ";
    cout<<RESET;
    int option;
    cin>>option;
    string username;
    if(option==1)
    {
        system("cls");
        cout<<YELLOW;
        cout<<"\n\t\t\tSEND MONEY\n";
        cout<<"\t\t\t~~~~~~~~~~\n\n";
        cout<<RESET;
        cout<<WHITE;
        if(friendcount[x]==0)
        {
            cout<<CYAN;
            cout<<"\n\t\tSorry, NO FRIENDS YET...\n\n\n";
            cout<<RESET;
        }
        else
        {
            cout<<"\n\tChoose from your friendlist: \n\n";
            for(int i=0; i<friendcount[x]; i++)
            {
                cout<<"\t\t\t"<<i+1<<". "<<friends[x][i]<<'\n';
            }
            cout<<"\n\n";
            cout<<"\n\nEnter serial no: ";
            int serial;
            cin>>serial;
            for(int i=0; i<friendcount[x]; i++)
            {
                if(serial-1==i)
                {
                    username=friends[x][i];
                    break;
                }
            }
            cout<<RESET;
            sendingprocess(x,username);
        }
    }
    else if(option==2)
    {
        system("cls");
        cout<<YELLOW;
        cout<<"\n\t\t\tSEND MONEY\n";
        cout<<"\t\t\t~~~~~~~~~~\n\n";
        cout<<RESET;
        cout<<WHITE;
        cout<<"Enter receiver username: ";
        cin>>username;
        cout<<RESET;
        if(username==regusers[x])
        {
            cout<<CYAN;
            cout<<"\n\n\t\tYou can't send money to yourself :)\n\n\n";
            cout<<RESET;
        }
        else
        {
            int it=-1;
            for(int i=0; i<regusers.size(); i++)
            {
                if(username==regusers[i])
                {
                    it=i;
                    break;
                }
            }
            if(it!=-1)
            {
                sendingprocess(x,username);
            }
            else
            {
                cout<<CYAN;
                cout<<"\n\n\t\t\tUSER NOT FOUND!\n\n\n";
                cout<<RESET;
            }
        }
    }
    else
    {
        cout<<RED;
        cout<<"\n\n\t\t\tInvalid input!\n\n\n";
        cout<<RESET;
    }
}
void SafePay::sendingprocess(int x, string username)
{
    int it=-1;
    for(int i=0; i<regusers.size(); i++)
    {
        if(username==regusers[i])
        {
            it=i;
            break;
        }
    }
    system("cls");
    cout<<YELLOW;
    cout<<"\n\t\t\tSEND MONEY\n";
    cout<<"\t\t\t~~~~~~~~~~\n\n";
    cout<<RESET;
    cout<<WHITE;
    cout<<"Enter the amount of money you want to send to "<<username<<": ";
    int amount;
    cin>>amount;
    cout<<RESET;

    if(amount>balance[x])
    {
        cout<<CYAN;
        cout<<"\n\n\t\t\t\You don't have enough money! :')\n\n\n";
        cout<<RESET;
    }
    else
    {
        balance[x]-=amount;
        int y=it;
        balance[y]+=amount;
        cout<<GREEN;
        cout<<"\n\n\t\t\tYou have sent "<<username<<" "<<amount<<" tk.\n";
        cout<<"\t\t\tYou have left "<<balance[x]<<" tk.\n\n\n";
        cout<<RESET;
        string ss="Amount Sent";
        trackType[x][tracking[x]]=ss;
        int tran=rand()%100000000+187261821;
        tranhistoryid[x][tracking[x]]=tran;
        tranhistorytk[x][tracking[x]]=amount;
        tracking[x]++;
        tranhistoryid[y][tracking[y]]=tran;
        tranhistorytk[y][tracking[y]]=amount;
        ss="Amount Recieved";
        trackType[y][tracking[y]]=ss;
        tracking[y]++;
    }
}
void SafePay::recharge(int x)
{
    system("cls");
    cout<<YELLOW;
    cout<<"\n\t\t\t MOBILE RECHARGE\n";
    cout<<"\t\t\t~~~~~~~~~~~~~~~~~\n\n";
    cout<<RESET;
    cout<<WHITE;
    cout<<"Enter receiver number: ";
    string number;
    cin>>number;
    cout<<"Enter amount of money you want to recharge: ";
    int amount;
    cin>>amount;
    cout<<RESET;
    if(amount>balance[x])
    {
        cout<<CYAN;
        cout<<"\n\n\t\t\tYou don't have enough money! :')\n\n\n";
        cout<<RESET;
    }
    else
    {
        balance[x]-=amount;
        cout<<GREEN;
        cout<<"\n\n\t\t\tMobile Recharge Request Recieved for "<<number<<".";
        cout<<"\n\t\t\tRecharge amount: "<<amount<<"tk.\n";
        cout<<"\t\t\tYou have left "<<balance[x]<<" tk.\n\n\n";
        cout<<RESET;
        string ss="Mobile Recharge";
        trackType[x][tracking[x]]=ss;
        int tran=rand()%100000000+187261821;
        tranhistoryid[x][tracking[x]]=tran;
        tranhistorytk[x][tracking[x]]=amount;
        tracking[x]++;
    }
}

void SafePay::cashout(int x)
{
    system("cls");
    cout<<YELLOW;
    cout<<"\n\t\t\t CASH OUT\n";
    cout<<"\t\t\t~~~~~~~~~~\n\n";
    cout<<RESET;
    cout<<WHITE;
    cout<<"Enter the amount you want to withdraw: ";
    int amount;
    cin>>amount;
    cout<<RESET;
    if(amount>balance[x])
    {
        cout<<CYAN;
        cout<<"\n\n\t\t\tSorry, you don't have enough money! :')\n\n\n";
        cout<<RESET;
    }
    else
    {
        cout<<WHITE;
        cout<<"Type Agent: ";
        string s;
        cin>>s;
        cout<<RESET;
        if(s!="Agent")
        {
            cout<<CYAN;
            cout<<"\n\n\t\t\tYou haven't typed 'Agent'\n\t\t\tPlease type 'Agent'\n\n\n";
            cout<<RESET;
        }
        else
        {
            balance[x]-=amount;
            string ss="Amount Withdrawn";
            trackType[x][tracking[x]]=ss;
            cout<<GREEN;
            cout<<"\n\n\t\t\tYou have withdrawn "<<amount<<" tk.\n";
            cout<<"\t\t\tYou have left "<<balance[x]<<" tk.\n\n\n";
            cout<<RESET;
            int tran=rand()%100000000+187261821;
            tranhistoryid[x][tracking[x]]=tran;
            tranhistorytk[x][tracking[x]]=amount;
            tracking[x]++;
        }
    }
}

void SafePay::balancenquiry(int x)
{
    system("cls");
    cout<<YELLOW;
    cout<<"\n\t\t\t BALANCE ENQUIRY\n";
    cout<<"\t\t\t ~~~~~~~~~~~~~~~~\n\n";
    cout<<RESET;
    cout<<GREEN;
    cout<<"\t\t\tYour current Balance: "<<balance[x]<<"\n\n\n";
    cout<<RESET;
}

void SafePay::transaction(int x)
{
    system("cls");
    cout<<YELLOW;
    cout<<"\n\t\t\t\tTRANSACTION HISTORY\n";
    cout<<"\t\t\t\t~~~~~~~~~~~~~~~~~~~\n\n";
    cout<<RESET;
    if(tracking[x]==0)
    {
        cout<<CYAN;
        cout<<"\t\t\t\tNO TRANSACTION TO SHOW!\n\n\n";
        cout<<RESET;
    }
    else
    {
        cout<<GREEN;
        for(int i=0; i<tracking[x]; i++)
        {
            cout<<"\t\t\t   "<<i+1<<". "<<trackType[x][i]<<": "<<tranhistorytk[x][i]<<'\n';
            cout<<"\t\t\t      Transaction ID: "<<tranhistoryid[x][i]<<'\n'<<'\n';
        }
        cout<<"\n";
        cout<<RESET;
    }
}

void SafePay::changepass(int x)
{
    system("cls");
    cout<<YELLOW;
    cout<<"\n\t\t\tCHANGE PASSWORD\n";
    cout<<"\t\t\t~~~~~~~~~~~~~~~~\n\n";
    cout<<RESET;
    cout<<WHITE;
    cout<<"Enter previous password: ";
    string pass;
    cin>>pass;
    cout<<RESET;
    if(pass!=passwords[x])
    {
        cout<<CYAN;
        cout<<"\n\n\t\t\tYou have entered wrong password!\n\n\n";
        cout<<RESET;
    }
    else
    {
        cout<<WHITE;
        cout<<"Enter new password: ";
        string ps;
        cin>>ps;
        cout<<"Confirm new password: ";
        string nps;
        cin>>nps;
        cout<<RESET;
        if(ps!=nps)
        {
            cout<<CYAN;
            cout<<"\n\n\t\t\tPassword Doesn't Match!"<<'\n';
            cout<<"\t\t\tPlease Enter carefully!\n\n\n";
            cout<<RESET;
        }
        else
        {
            passwords[x]=ps;
            cout<<GREEN;
            cout<<"\n\n\t\t\tYou have changed your password successfully!\n\n\n";
            cout<<RESET;
        }
    }
}

void SafePay::mysafepay(int x)
{
    system("cls");
    cout<<YELLOW;
    cout<<"\n\t\t\t\t My SafePay\n";
    cout<<"\t\t\t\t~~~~~~~~~~~~\n\n";
    cout<<RESET;
    if(freq[x]==0)
    {
        cout<<YELLOW;
        cout<<"\n\n\t\t\tYou haven't set your details yet!\n\n";
        cout<<RESET;
        cout<<WHITE;
        cout<<"\nEnter your name(i.e. Tasmi Khair): ";
        string nm;
        string s;
        getline(cin,s);
        getline(cin,nm);
        freq[x]=1;
        names[x]=nm;
        cout<<"\nEnter your gender(F/M): ";
        string gen;
        cin>>gen;
        gender[x]=gen;
        cout<<"\nEnter your Nationality(i.e. Bangladeshi): ";
        string nati;
        cin>>nati;
        nationality[x]=nati;
        cout<<"\nEnter your Birth date(i.e. 02/12/2002): ";
        string birth;
        cin>>birth;
        birthdate[x]=birth;
        cout<<RESET;
        cout<<GREEN;
        cout<<"\n\n\t\t\t"<<regusers[x]<<", you have successfully changed your details!\n\n\n";
        cout<<RESET;
    }
    else
    {
        cout<<WHITE;
        cout<<"\n\t\t\tName: "<<names[x]<<"\n";
        cout<<"\t\t\tGender: "<<gender[x]<<"\n";
        cout<<"\t\t\tNationality: "<<nationality[x]<<"\n";
        cout<<"\t\t\tBirthDate: "<<birthdate[x]<<"\n";
        cout<<"\t\t\tTotal Transaction Made: "<<tracking[x]<<"\n";
        cout<<"\t\t\tBalance: "<<balance[x]<<"\n\n\n";
        cout<<RESET;
    }
}
void SafePay::userlist()
{
    system("cls");
    cout<<YELLOW;
    cout<<"\n\t\t\t\tSafePay Users\n";
    cout<<"\t\t\t\t~~~~~~~~~~~~~\n\n";
    cout<<RESET;
    cout<<WHITE;
    for(int i=0; i<regusers.size(); i++)
    {
        cout<<"\t\t\t"<<i+1<<". "<<regusers[i]<<'\n';
        cout<<"\t\t\t   Friends of: "<<friendsof[i]<<" users\n\n";
    }
    cout<<RESET;
}

void SafePay::myfriends(int x)
{
    system("cls");
    cout<<YELLOW;
    cout<<"\n\t\t\t\t  My Friends\n";
    cout<<"\t\t\t\t  ~~~~~~~~~~\n\n";
    cout<<RESET;
    if(friendcount[x]==0)
    {
        cout<<CYAN;
        cout<<"\n\n\t\t\t\tNO FRIENDS YET!\n\n\n";
        cout<<RESET;
    }
    else
    {
        cout<<WHITE;
        cout<<"\n\n\t\t\tYour Friends:\n";
        for(int i=0; i<friendcount[x]; i++)
        {
            cout<<"\t\t\t"<<i+1<<". "<<friends[x][i]<<'\n';
        }
        cout<<"\n\n";
        cout<<RESET;
    }
    cout<<WHITE;
    cout<<"\n\n\t\t\tWanna add more friends?";
    cout<<"\n\t\t\t1. YES"<<'\n';
    cout<<"\t\t\t2. NO"<<'\n';
    cout<<'\n';
    cout<<RESET;
    cout<<"\nEnter your choice: ";
    string option;
    cin>>option;
    int done=0;
    if(option=="1")
    {
        system("cls");
        cout<<YELLOW;
        cout<<"\n\t\t\t\t  My Friends\n";
        cout<<"\t\t\t\t  ~~~~~~~~~~\n\n";
        cout<<RESET;
        cout<<WHITE;
        cout<<underlinewhite;
        cout<<"\n\t\t\tAvailable Users";
        cout<<RESET;
        cout<<":\n\n";
        cout<<WHITE;
        for(int i=0; i<regusers.size(); i++)
        {
            cout<<"\t\t\t"<<i+1<<". "<<regusers[i]<<'\n';
        }
        cout<<"\n\n";
        cout<<"Select who you want to add(i.e. 1): ";
        int opt;
        cin>>opt;
        cout<<RESET;
        if(opt>regusers.size() || opt==0)
        {
            cout<<CYAN;
            cout<<"\n\n\t\t\tInvalid input!\n\n";
            cout<<RESET;
        }
        else
        {
            int j=friendcount[x];
            if(regusers[opt-1]==regusers[x])
            {
                cout<<CYAN;
                cout<<"\n\n\t\t\tYou can't add yourself in your friendlist! -_-\n\n\n";
                cout<<RESET;
            }
            else
            {
                int f=0;
                for(int i=0; i<friendcount[x]; i++)
                {
                    if(friends[x][i]==regusers[opt-1])
                    {
                        f=1;
                        break;
                    }
                }
                if(f)
                {
                    cout<<YELLOW;
                    cout<<"\n\n\t\t\tYou have already added "<<regusers[opt-1]<<" in your friendlist.\n\n";
                    cout<<RESET;
                }
                else
                {
                    friends[x][j]=regusers[opt-1];
                    friendcount[x]++;
                    friendsof[opt-1]++;
                    cout<<GREEN;
                    cout<<"\n\n\t\t\tYou have added "<<regusers[opt-1]<<" in your friendlist!\n\n\n";
                    cout<<RESET;
                }
            }
        }
    }
    else if(option=="2")
    {
        cout<<CYAN;
        cout<<"\n\t\t\tOK!:)\n\n\n";
        cout<<RESET;
    }
    else
    {
        cout<<RED;
        cout<<"\n\n\t\t\tINVALID INPUT!\n\n";
        cout<<RESET;
    }
}
int main()
{
    class SafePay sp;
    int option;
    while(1)
    {
        system("cls");
        cout<<WHITE;
        cout<<'\n';
        cout<<"\t\t\t==========================\n";
        cout<<"\t\t\t==                      ==";
        cout<<"\n\t\t\t==  Welcome to SafePay  =="<<'\n';
        cout<<"\t\t\t==                      ==\n";
        cout<<"\t\t\t==========================\n\n";
        cout<<"\t\t\t1. REGISTER"<<'\n';
        cout<<"\t\t\t2. LOGIN"<<'\n';
        cout<<"\t\t\t3. EXIT"<<'\n';
        cout<<"\n\nEnter your choice: ";
        cout<<RESET;
        cin>>option;
        switch(option)
        {
        case 1:
            sp.registration();
            break;
        case 2:
            sp.login();
            break;
        case 3:
            cout<<YELLOW;
            cout<<"\n\n\t\t\tThank you for using SafePay!\n\t\t\tDon't Forget to Come Back..:)\n\n\n";
            cout<<RESET;
            return 0;
        default:
            cout<<RED;
            cout<<"\n\n\t\t\tINVALID INPUT!\n\n\n";
            cout<<RESET;
        }
        system("pause");
    }
}
