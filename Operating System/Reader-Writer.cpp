#include<iostream>
#include<conio.h>
#include <unistd.h>
using namespace std;

int wait(int s)
{
    return(--s);
}

int signal(int s)
{
    return(++s);
}
int main()
{
    int rw_mutex = 1;
    int mutex = 1;
    int read_count = 0;
    int writer = 0;
    int choice;

    cout<<endl<<"CHOOSE AN ACTION:"<<endl;
    cout<<"1. Add reader"<<endl<<"2. Remove Reader"<<endl<<"3. Add writer"<<endl<<"4. Remove writer"<<endl<<"5. Exit"<<endl<<"6. Do Nothing"<<endl;

    while(1)
    {
        cout<<endl<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: if(writer==0)
                    {
                        mutex = wait(mutex);
                        read_count++;
                        if(read_count == 1)
                            rw_mutex = wait(rw_mutex);
                        
                        mutex = signal(mutex);
                        cout<<"Reader "<<read_count<<" Added!"<<endl;
                    }
                    else 
                        cout<<"Cannot read. Writer on duty!"<<endl;
                    
                    break;
            
            case 2: if((read_count>0) && (writer == 0))
                    {
                        mutex = wait(mutex);
                        cout<<"Reader "<<read_count<<" removed!"<<endl;
                        read_count--;
                        if(read_count == 0)
                            rw_mutex = signal(rw_mutex);
                        
                        mutex = signal(mutex);
                        if(read_count == 0)
                            cout<<"All Readers removed! Critical section is empty!"<<endl;
                        break;
                    }
                    if(read_count == 0)
                    {
                        cout<<"No Readers Active!"<<endl;
                        break;
                    }
                        

                    if(writer > 0)
                    {
                        cout<<"Writer on duty! No reader present to remove!"<<endl;
                        break;
                    }
                    
                    else
                        cout<<"Invalid operation! "<<endl;

                    break;

            case 3: if((read_count == 0) && (rw_mutex == 1))
                    {
                        rw_mutex = wait(rw_mutex);
                        cout<<"Writer Added!"<<endl;
                        writer++;
                        break;
                    }

                    if(read_count != 0)
                    {
                        cout<<"Readers present! Cannot Add writer. Remove all readers first."<<endl;
                        break;
                    }
                    
                    else
                        cout<<"Invalid operation! "<<endl;

                    break;

            case 4: if((rw_mutex == 0) && (read_count == 0))
                    {
                        rw_mutex = signal(rw_mutex);
                        cout<<"Removed Writer! You can now add other readers or another writer. Critical section is empty!"<<endl;
                        writer--;
                        break;
                    }
                    if (rw_mutex != 0)
                    {
                        cout<<"No Writers Active! "<<endl;
                        break;
                    }
                    
                    if(read_count != 0)
                    {
                        cout<<"No writer to remove! Other readers exist in critical section"<<endl;
                        break;
                    }

                    else 
                        cout<<"Invalid operation! "<<endl;

                    break;
            
            case 5: 
                    exit(0);
                    break;
            
            case 6: 
                    sleep(1);
                    cout<<"N - ";
                    sleep(1);
                    cout<<"O - ";
                    sleep(1);
                    cout<<"T - ";
                    sleep(1);
                    cout<<"H - ";
                    sleep(1);
                    cout<<"I - ";
                    sleep(1);
                    cout<<"N - ";
                    sleep(1);
                    cout<<"G"<<endl;
                    break;

            default: cout<<"Action Doesn't Exist! WAKE UP!!"<<endl;

        }
    }

    return 0;

}