#include<iostream>
#include<fstream> // for creating file

using namespace std;

class temp{
    // kind of different variable
    string userName,Email,password;
    string searchName,searchPass,searchEmail;
    fstream file;
    public:
    // 3 function to declare
    void login();
    void signUP();
    void forgot();
}obj;

int main(){

    char choice; //variable declaration
    //Creating aa menu which is gonna diplay to user
    cout<<"\n1- Login";
    cout<<"\n2- Sign-Up";
    cout<<"\n3- Forgot Password";
    cout<<"\n4- Exit";
    cout<<"\nEnter Your Choice :: ";

    cin>>choice; // here for entering a choice of user

    switch(choice){

        //As per choice it shows a various options
        case '1':
            cin.ignore();
            obj.login();
        break;
        case '2':
            cin.ignore();
            obj.signUP();
        break;
        case '3':
            cin.ignore();
            obj.forgot();
        break;
        // After selecting a last choice the function repeat the whole process
        case '4':
            return 0;
        break;
        defualt:
            cout<<"Invalid Selection.....!";
    }
}

/* for calling the function
for signUp user has to put his UserName and email with passkey*/

void temp :: signUP(){
    cout<<"\nEnter Your User Name :: ";
    getline(cin,userName);
    cout<<"Enter Your Email Address :: ";
    getline(cin,Email);
    cout<<"Enter Your Password :: ";
    getline(cin,password);

    /*Send this all data to the file for this you have to call
    this below function*/

    file.open("loginData.txt",ios :: out | ios :: app);
    file<<userName<<"*"<<Email<<"*"<<password<<endl;
    file.close();
    /*diff data got in diff rows to us*/
}
void temp :: login(){

    /*if we choose option 2 then it is for login*/
 
    cout<<"*****------LOGIN------*****"<<endl;
    cout<<"Enter Your User Name :: "<<endl;
    getline(cin,searchName);
    cout<<"Enter Your Password :: "<<endl;
    getline(cin,searchPass);

    /* if the user is resistered already in this then code is open this file
     and by data we get login automatically*/

    file.open("loginData.txt",ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');

    /*While loop is for to open file again and again*/
    while(!file.eof()){
        if(userName == searchName){
            if(password == searchPass){
                cout<<"\nAccount Login Succesfull...!";
                cout<<"\nUsername :: "<<userName<<endl;
                cout<<"\nEmail :: "<<Email<<endl;
            }else{
                cout<<"Password is Incorrect...!";
            }
        }
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    }
    file.close();
}
void temp :: forgot(){
    /*In case of forgot the passsword just neet to choose option 4 and then 
    it will show your password within just few simple steps*/
    cout<<"\nEnter Your UserName :: ";
    getline(cin,searchName);
    cout<<"\nEnter Your Email Address :: ";
    getline(cin,searchEmail);

    file.open("loginData.txt",ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    
    while(!file.eof()){
        if(userName == searchName){
            if(Email == searchEmail){
                cout<<"\nAccount Found...!"<<endl;
                cout<<"Your Password :: "<<password<<endl;
            }else{
                cout<<"Not found...!\n";
            }
        }else{
            cout<<"\nNot fount...!\n";
        }
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    }
    file.close();
}