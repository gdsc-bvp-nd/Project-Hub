#include <iostream>
using namespace std;

template <class T>
class largest
{
    private:
        T a, b;
    public:
        
        largest(T n1, T n2)
        {
            a = n1;
            b = n2;
        }
        T larger()
        {
            return ( a > b ) ? a : b;
        }
        void input()
        {
            cout << "\nEnter first number : ";
            cin >> a;
            cout << "\nEnter second number : ";
            cin >> b;
        }
        void display()
        {
            if(a == b)
                cout << "\n" << a << " and " << b << " are equal.\n";
            else
                cout << "\nLarger number is " << larger() << "\n";
        }
        ~largest()
        {
            cout << "\nAll Objects destroyed!\n";
        }
};

int main()
{
    int n1, n2;
    largest<int> c(n1,n2);
    c.input();
    c.display();
    return 0;
}

