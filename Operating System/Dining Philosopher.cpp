#include<iostream>
using namespace std;
int stick[5] = {1, 1, 1, 1, 1};
int Wait(int s)  
{
    return (--s);
}
int Signal(int s)
{
    return(++s);
}
void Eat(int i)
{
    if(stick[i] == 1 && stick[(i + 1) % 5] == 1)            //if both chopsticks available
    {
        cout << "\nPhilosopher " << i << " has picked up chopstick " << i;
        cout << "\nPhilosopher " << i << " has picked up chopstick " << (i + 1) % 5;
        stick[i] = Wait(stick[i]);
        stick[(i + 1) % 5] = Wait(stick[(i + 1) % 5]);              
    }
    else
    {
        if(stick[i] == 1 && stick[(i + 1) % 5] == 0)
        {
            cout << "\nPhilosopher " << i << " has picked up chopstick " << i;
            cout << "\nPhilosopher " << i << " is waiting for chopstick " << (i + 1) % 5;
        }
        else if(stick[i] == 0 && stick[(i + 1) % 5] == 1)
        {
            cout << "\nPhilosopher " << i << " is waiting for chopstick " << i;
            cout << "\nPhilosopher " << i << " is has picked up " << (i + 1) % 5;
        }
        else 
        {
            cout << "\nPhilosopher " << i << " is waiting for chopstick " << i;
            cout << "\nPhilosopher " << i << " is waiting for chopstick " << (i + 1) % 5;
        }
    }
    cout << "\n+-------------------------------------------------+\n";
}
void Think(int i)
{
    stick[i] = Signal(stick[i]);
    stick[(i + 1) % 5] = Signal(stick[(i + 1) % 5]);
    cout << "\nPhilosopher " << i << " has started thinking";
    cout << "\n+-------------------------------------------------+\n";
}
int main()
{
    int ch1, ch2;
    cout << "Menu\n1.Eat\n2.Think\n3.Exit";
    while(1)
    {
        cout << "\nChoose an option : ";
        cin >> ch1;
        switch(ch1)
        {
            case 1 : cout << "\nEnter philosopher : ";
                     cin >> ch2;
                     Eat(ch2);
                        break;
            case 2 : cout << "\nEnter philosopher : ";
                     cin >> ch2;
                     Think(ch2);
                        break;
            case 3 : exit(0);
        }
    }
    return 0;
}
