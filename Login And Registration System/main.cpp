#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void login();
void reg();
void forgot();
int main(){
    int c;
    cout<<"\t\t\t____________________________________________________"<<endl<<endl;
    cout<<"\t\t\t                   Welcome to Login Page             "<<endl;
    cout<<"\t\t\t_____________________________________________________"<<endl<<endl;
    cout<<"\t----------- Menu ----------\n";
    cout<<"\tPress 1 for Login: "<<endl;
    cout<<"\tPress 2 for Registration: "<<endl;
    cout<<"\tPress 3 for Forgot Password: "<<endl;
    cout<<"\tPress 4 for Exit: "<<endl;
    cout<<"\tEnter Your Choice:";
    cin>>c;

    switch(c){
        case 1:
        login();
        break;

        case 2:
        reg();
        break;

        case 3:
        forgot();
        break;

        case 4:
        cout<<"\t\t\t Thankyou!!!\n\n   "<<endl;
        break;

        default:
        system("cls");
        cout<<"\t\t Please Select Valid Option:"<<endl;
        main();
    }
    return 0;
}
void login(){
    int count;
    string userId,password,id,pass;
    system("cls");
    cout<<"---------------------------------------------------------------------------------\n";
    cout<<"\t\t\tPlease Enter UserName and Password:"<<endl;
    cout<<"---------------------------------------------------------------------------------\n";
    cout<<"UserName:";
    cin>>userId;
    cout<<"Password:";
    cin>>password;
    
    ifstream input("records.txt");
    while(input>>id>>pass){
        if(id==userId && pass ==password){
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1){
        cout<<"\t\t\t Your Login is Successfull\n Thanks for logging in !"<<endl;
    }
    else{
        cout<<"\t\t\t You Enter Wrong Password Or Username"<<endl;
    }
    main();
}
void reg(){
    string rUserid,rpassword,rid,rpass;
    cout<<"---------------------------------------------------------------------------------\n";
    cout<<"\t\tEnter the UserName and Password for Register\n";
    cout<<"---------------------------------------------------------------------------------\n";
    cout<<"Enter the UserName:";
    cin>>rUserid;
    cout<<"Enter the Password:";
    cin>>rpassword;

    ofstream f1("records.txt",ios::app);
    f1<<rUserid<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\t Registration is Successfull !\n";
    main();
}
void forgot(){
    int option;
    system("cls");
    cout<<"---------------------------------------------------------------------------------\n";
    cout<<"\t\tYour forgot the Password no worries! Please Select Option: \n";
    cout<<"---------------------------------------------------------------------------------\n";
    cout<<"\t\tPress 1 for search your id from username\n";
    cout<<"\t\tPress 2 for go back to main menu\n";
    cin>>option;
    switch(option){
        case 1:
        {
            int count=0;
            string userid,id,pass;
            cout<<"Enter the username which you remembered:";
            cin>>userid;
            
            ifstream f2("records.txt");
            while(f2>>id>>pass){
                if(id==userid){
                    count=1;
                }
            }
            f2.close();
            if(count==1){
                cout<<"\t\tYour account is found !\n ";
                cout<<"\t\tYour password is: "<<pass<<endl;
            }
            else{
                cout<<"\t\t\tSorry your account is not found!\n";
            }
            system("cls");
            main();
        }
        break;

        case 2:
        main();
        break;

        default:
        cout<<"\t\t\tWrong Choice Please try again!\n";
        forget();

    }
}
