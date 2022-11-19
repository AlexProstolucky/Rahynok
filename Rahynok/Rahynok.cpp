#include <iostream>
#include <windows.h>
using namespace std;



enum Curency 
{
    USD = 1,
    EUR,
    UAH
};

enum Type 
{
    current = 1,
    card,
    deposit,
    credit
};

string printc(Curency c)
{
    if (c == USD) return "USD";
    if (c == EUR) return "EUR";
    if (c == UAH) return "UAH";
    return "-";
}

string printty(Type c)
{
    if (c == current) return "current";
    if (c == card) return "card";
    if (c == deposit) return "deposit";
    if (c == credit) return "credit";
    return "-";
}


class Score 
{
protected:
    static int IDSORCES;
    string title;
    Curency value;
    string bank;
    Type type;
    int balance;
    int ID;

public:
    Score(string tit, Curency value, string bank, Type t, unsigned int balance) :
        title(tit), value(value), bank(bank), type(t), balance(balance)
    {
        system("cls");
        IDSORCES++;
        this->ID = IDSORCES;
        cout << "Score created:\n";
        info();
    }

    virtual void info() 
    {
        cout << "ID -> " << ID << endl;
        cout << "Title -> " << title << endl;
        cout << "Curency -> " << printc(value) << endl;
        cout << "Bank -> " << bank << endl;
        cout << "Type -> " << printty(type) << endl;
        cout << "Balance -> " << balance << endl;
    }

    void add(int value) 
    {
        if (value < 0)
        {
            cout << "value can`t be negative!\n";
            return;
        }
        balance += value;
        cout << "Current balance -> " << balance << endl;
    }

    virtual void withdraw(int value) 
    {
        if (value < 0) 
        {
            cout << "value can`t be negative!\n";
            return;
        }
        if (balance - value < 0) 
        {
            cout << "The input value is greater than the balance, try again!\n";
            return;
        }
        else 
        {
            balance -= value;
            cout << "Current balance -> " << balance << endl;
            return;
        }
    }
};
int Score::IDSORCES = 0;

class Deposit :public Score 
{
private:
    string f_data;
    string l_data;
    const double procent = 0.05;
public:
    Deposit(string tit, Curency value, string bank, unsigned int balance, string f_data, string l_data) :
        Score(tit, value, bank, deposit, balance), f_data(f_data), l_data(l_data)
    {
        info();
    }

    void info() override
    {
        cout << "ID -> " << ID << endl;
        cout << "Title -> " << title << endl;
        cout << "Curency -> " << printc(value) << endl;
        cout << "Bank -> " << bank << endl;
        cout << "Type -> " << printty(type) << endl;
        cout << "Balance -> " << balance << endl;
        cout << "Date of creation -> " << f_data << endl; 
        cout << "Date of end -> " << l_data << endl;
        cout << "Annual percentage -> " << procent << endl;
        cout << "Amount of increase -> " << balance + balance * procent << endl;
    }
};

class Credit :public Score
{
private:
    const double procent = 0.08;

public:
    Credit(string tit, Curency value, string bank, int balance) :
        Score(tit, value, bank, credit, balance)
    {
        info();
    }
   
    void creditinfo() 
    {
        if (balance < 0)
        {
            balance -= abs(balance) * procent;
            cout << "The amount of addition to the loan -> " << abs(balance) * procent << endl;
            cout << "Result -> " << balance << endl;
        }
        else return;
    }
    
    void info() override
    {
        cout << "ID -> " << ID << endl;
        cout << "Title -> " << title << endl;
        cout << "Curency -> " << printc(value) << endl;
        cout << "Bank -> " << bank << endl;
        cout << "Type -> " << printty(type) << endl;
        cout << "Balance -> " << balance << endl;
        cout << "Annual percentage -> " << procent << endl;
        creditinfo();
    }
};

void loading()
{
    system("Color 0B");
    char x = 219;
    cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\tLoading...";
    for (size_t i = 0; i < 35; i++)
    {
        cout << x;
        if (i < 10) Sleep(200);
        if (i >= 10 && i < 30) Sleep(150);
        if (i >= 30) Sleep(75);
    }
    cout << "\n\n\n\n\n\n\n\n\n\n";
    system("Color 7");
    system("cls");
}

int main()
{
    try
    {
        int val;
        int buffer;
        string title;
        Curency value;
        string bank;
        unsigned int balance;
        loading();
        cout << "\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\tCreating a bank account";
        cout << "\n\n\nInput value (1:Current, 2:Card, 3:Deposit, 4:Credit) -> ";
        cin >> buffer;
        cout << "\nInput title of account -> ";
        cin >> title;
        cout << "\nInput value (1:USD, 2:EUR, 3:UAH) -> ";
        cin >> val;
        value = static_cast<Curency>(val);
        cout << "\nInput name of bank -> ";
        cin >> bank;
        cout << "\nInput value of balance -> ";
        cin >> balance;

        switch (buffer)
        {
        case 1:
        {
            Score ac(title, value, bank, current, balance);
        }break;
        case 2:
        {
            Score ac(title, value, bank, card, balance);
        }break;
        case 3:
        {
            string f_data, l_data;
            cout << "Input date of creation(ex 20.03.2007) -> ";
            cin >> f_data;
            cout << "Input date of end(ex 20.05.2020) -> ";
            cin >> l_data;
            Deposit ac(title, value, bank, balance, f_data, l_data);
        }break;
        case 4:
        {
            Credit ac(title, value, bank, balance);
        }break;
        }
    }
    catch (...)
    {

    }
}