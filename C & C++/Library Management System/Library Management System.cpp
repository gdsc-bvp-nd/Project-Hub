#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

int train_total = 1;
int pas_total = 0;
char c[100] = "password";

struct trainData
{
    int tNumber[10];
    char tName[10][100];
    char b_loc[10][100];
    char d_loc[10][100];
    int noOf_seats[10];
    float cost[10];
} tD;

struct passengerData
{
    char pName[10][100];
    int tiNumber[10];
    int ptNumber[10];
} pD;

class login
{
private:
    char pass[100] = "";

public:
    void insertPass(char c[])
    {
        strcpy(pass, c);
    }
    void changePass()
    {
        cout << "\nEnter current password : ";
        cin >> c;
        if (this->checkPass(c))
        {
            cout << "\nEnter new password : ";
            cin >> c;
            bool m = true;
            while (m)
            {
                char v[100] = "";
                cout << "\nConfirm new password : ";
                cin >> v;
                if (strcmp(v, c) == 0)
                {
                    this->updatePass(c);
                    m = false;
                }
                else
                {
                    cout << "\nDo not match!!  \n Enter again!";
                }
            }
        }
        else
        {
            cout << "\nWrong Password !!";
        }
    }
    bool checkPass(char c[])
    {
        if (strcmp(pass, c) == 0)
            return true;
        else
            return false;
    }
    bool updatePass(char c[])
    {
        strcpy(pass, c);
        cout << "\nPassword updated !!";
    }
};

class train
{
public:
    void addTrain(int i)
    {
        cout << "\nEnter number id of the train : ";
        cin >> tD.tNumber[i];
        cout << "Enter name of the train : ";
        cin >> tD.tName[i];
        cout << "Enter starting location of the train : ";
        cin >> tD.b_loc[i];
        cout << "Enter destination location of the train : ";
        cin >> tD.d_loc[i];
        cout << "Enter number of tickets left and price per ticket : ";
        cin >> tD.noOf_seats[i] >> tD.cost[i];
    }
    
    void showTrains(int i)
    {
        cout << "\nNumber of the train : ";
        cout << tD.tNumber[i];
        cout << "\nName of the train : ";
        cout << tD.tName[i];
        cout << "\nStarting location of the train : ";
        cout << tD.b_loc[i];
        cout << "\nDestination location of the train : ";
        cout << tD.d_loc[i];
        cout << "\nNumber of tickets left : ";
        cout << tD.noOf_seats[i];
        cout << "\nPrice per ticket : ";
        cout << tD.cost[i];
        cout << endl;

        getch();
    }
};

class passenger
{
public:
    void addFair(int i)
    {
        cout << "\nEnter name of the passenger : ";
        cin >> pD.pName[i];
        cout << "\nEnter train number id you want to buy ticket for : ";
        cin >> pD.ptNumber[i];
        pD.tiNumber[i] = tD.noOf_seats[pD.ptNumber[i]] - (tD.noOf_seats[pD.ptNumber[i]] - i - 1);
        if (pD.tiNumber[i] == tD.noOf_seats[pD.ptNumber[i]] + 1)
        {
            cout << "\n\nFULLY BOOKED !!\n";
            pD.tiNumber[i] = -1;
            return;
        }
    }
    void showFairs(int i)
    {
        cout << "\nName of the passenger : ";
        cout << pD.pName[i];
        cout << "\nTicket Number of the passenger : ";
        cout << pD.tiNumber[i];
        cout << "\nTrain number of the passenger : ";
        cout << pD.ptNumber[i];
        cout << "\nPrice of the ticket : ";
        int cash = tD.cost[pD.ptNumber[i]];
        cout << cash;
        cout << endl;
        getch();
        cout << endl;
    }
};

class Railway_booking : public login,
                        public train,
                        public passenger
{
private:
    int entry = 0;
    train T;
    passenger P;
    login L;

public:
    void start()
    {
        L.insertPass(c);

        while (entry != 3)
        {
            cout << "\t\t\n ---- RAILWAY TICKET BOOKING SYSTEM ----";
            cout << "\t\t\n\n 1. Administration portal\n 2. Ticket booking portal\n 3. Exit\n  Enter your choice >>  ";
            cin >> entry;
            switch (entry)
            {
            case 1:
            {
                cout << "\n\n ---- Welcome to Administration Login Page ----\n";
                cout << "\nEnter Password : ";
                char c[100] = "";
                cin >> c;
                if (L.checkPass(c))
                {
                    int entry2 = 0;
                    while (entry2 != 5)
                    {
                        cout << "\t\t\n ---- RAILWAY TICKET BOOKING SYSTEM ----";
                        cout << "\t\t\n\n ---- Welcome to Administration Portal ----";
                        cout << "\n 1. Update password\n 2. Add Train \n 3. Display Trains\n 4. Display passengers travelling\n 5. Exit\n  Enter your choice >>  ";

                        cin >> entry2;
                        switch (entry2)
                        {
                        case 1:
                        {
                            L.changePass();

                            break;
                        }
                        case 2:
                        {
                            T.addTrain(train_total);
                            train_total++;
                            break;
                        }
                        case 3:
                        {
                            for (int k = 1; k < train_total; k++)
                            {
                                T.showTrains(k);
                                cout << endl;
                            }
                            break;
                        }
                        case 4:
                        {
                            for (int k = 0; k < pas_total; k++)
                            {
                                P.showFairs(k);
                                cout << endl;
                            }
                            break;
                        }
                        case 5:
                        {
                            cout << "\n\nTHANK YOU !!\n\n";
                            break;
                        }
                        default:
                            break;
                        }
                    }
                }
                else
                {
                    cout << "\n\n  WRONG PASSWORD!\n \n";
                    break;
                }
                break;
            }
            case 2:
            {
                int entry2 = 0;
                while (entry2 != 4)
                {
                    cout << "\t\t\n ---- RAILWAY TICKET BOOKING SYSTEM ----";
                    cout << "\t\t\n\n ---- Welcome to Ticket Booking Portal ----";
                    cout << "\n 1. Book fair tickets\n 2. Display current train details\n 3. Display my tickets\n 4. Exit\n  Enter your choice >>  ";
                    cin >> entry2;
                    switch (entry2)
                    {
                    case 1:
                    {
                        cout << "\nEnter number of passengers : ";
                        int no;
                        cin >> no;
                        for (int i = pas_total; i < pas_total + no; i++)
                        {
                            P.addFair(i);
                            if (pD.tiNumber[i] == -1)
                            {
                                i--;
                            }
                            cout << endl;
                        }
                        pas_total += no;
                        break;
                    }
                    case 2:
                    {
                        for (int k = 1; k < train_total; k++)
                        {
                            T.showTrains(k);
                            cout << endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        for (int k = 0; k < pas_total; k++)
                        {
                            P.showFairs(k);
                            cout << endl;
                        }
                        break;
                    }
                    case 4:
                    {
                        cout << "\n\nTHANK YOU !!\n\n";
                        break;
                    }
                    default:
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                cout << "\n\nTHANK YOU !!\n\n";
                break;
            }
            default:
                cout << "\n\n INVALID INPUT!!";
            }
        }
    }
};

int main()
{
    Railway_booking R;
    R.start();

    return 0;
}