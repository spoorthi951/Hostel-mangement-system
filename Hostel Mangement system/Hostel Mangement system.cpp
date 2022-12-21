#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class hostel
{
    int room_no;
    char name[30];
    char address[50];
    char phone[10];
    public:
    void main_menu();
    void admin();
    void student();
    void add();
    void display();
    void rooms();
    void edit();
    int check(int);
    void modify(int);
    void delete_rec(int);
	void reg();
	void login();
	int isLoggedIn();
	void student_menu();
	void payment();
	int pay();
	void login1();
	void edit1();
};
string u="admin123";
string p="srm123";
string name;
string pw;

int hostel::pay()
{
	int am;
	cout<<"ENTER THE AMOUNT AT A TIME:"<<endl<<endl;
	int m=65000,h=100000;
    cout<<"\tMESS FEE:"<<m<<endl;
    cout<<"\tHOSTEL FEE:"<<h<<endl;
    cout<<"\tTOTAL AMOUNT:"<<"("<<m+h<<")"<<endl;
	cin>>am;
	int b=165000-am;
	ofstream file("fees.txt");
	cout<<"\tBALANCE DUE:"<<b<<endl;
	if(b==0)
	{
		int fee=1;
		file<<fee<<endl;
		return -1;
	}
	file.close();
    return 0;
}

void hostel::add()

{
    int r,flag;
    ofstream fout("Record.txt",ios::app);

    cout<<"\n Enter Student Detalis:\t";
    cout<<"\n\n Room no:";
    cin>>r;

    flag=check(r);



    if(flag)

        cout<<"\n Sorry..!!!Room is already booked";

    else

    {
        room_no=r;
        cout<<"\n Name:";
        cin>>name;
        cout<<"\n Address:";
        cin>>address;
        cout<<"\n Phone No:";
        cin>>phone;
        cout<<endl;
        int n=pay();
        if(n==-1)
        {
        fout.write((char*)this,sizeof(*this));
        cout<<"\n Room is booked!!!";
        }
        else
        {
            cout<<"\nPlease COMPLETE YOUR PAYMENT"<<endl;
        }
    }
    fout.close();
    student_menu();
}

void hostel::display()

{
    ifstream file("Record.txt");
    int r;
    cout<<"\n Enter room no: ";
    cin>>r;
    while(true)
    {
        file.read((char*)this,sizeof(*this));
        if(file.eof())
           break;
        if(room_no == r)
        {
            cout<<"\n Student Details:"<<endl;


            cout<<"\n\n Room no: "<<room_no;

            cout<<"\n Name: "<<name;

            cout<<"\n Address: "<<address;

            cout<<"\n Phone no: "<<phone;

       }
       else
       {
           cout<<".......................";
       }

    }
    file.close();
}



void hostel::rooms()

{
    ifstream fin;
    fin.open("Record.txt");

    cout<<"\n\t\t\tList Of Rooms Allotted:";

    cout<<"\n\t\t\t***";

    cout<<"\n\n Room No.\tName\t\tAddress\t\tPhone No.\n";

        // fin.eof();

    while(true)

    {

        fin.read((char*)this,sizeof(*this));

        if(fin.eof())
            break;

        cout<<"\n\n "<<room_no<<"\t\t"<<name;

        cout<<"\t\t"<<address<<"\t\t"<<phone;


    }
    fin.close();
    hostel::admin();

}
void hostel::edit1()

{

    int choice,r;



    cout<<"\n EDIT MENU:";


    cout<<"\n\n 1.Modify Student Record";

    cout<<"\n 2.Delete Student Record";



    cout<<"\n Enter your choice: ";

    cin>>choice;


    cout<<"\n Enter room no: ";

    cin>>r;


    switch(choice)

    {

        case 1: modify(r);

                break;

        case 2: delete_rec(r);

                break;

        default: cout<<"\n Wrong Choice!!";

    }

    admin();

}




void hostel::edit()

{
    int choice,r;
    cout<<"\n EDIT MENU:";
    cout<<"\n\n 1.Modify Student Record";
    cout<<"\n 2.Delete Student Record";
    cout<<"\n Enter your choice: ";
    cin>>choice;
    cout<<"\n Enter room no: ";
    cin>>r;

    switch(choice)

    {

        case 1: modify(r);

                break;

        case 2: delete_rec(r);

                break;

        default: cout<<"\n Wrong Choice!!";

    }
    student_menu();

}



int hostel::check(int r)

{

    int flag=0;

    ifstream fin("Record.txt",ios::in);

    while(!fin.eof())

    {

        fin.read((char*)this,sizeof(*this));

        if(room_no==r)

        {

            flag=1;

                break;

        }

    }



    fin.close();

    return(flag);

}


void hostel::modify(int r)

{

    long pos , flag;

    fstream file("Record.txt",ios::in|ios::out|ios::binary);

    flag=0;

    while(!file.eof())

       {

         pos=file.tellg();

        file.read((char*)this,sizeof(*this));

        if(room_no==r)
        {

            cout<<"\n Enter New Details:"<<endl;


            cout<<"\n Name: ";

            cin>>name;

            cout<<" Address: ";

            cin>>address;

            cout<<" Phone no: ";

            cin>>phone;

            file.seekg(pos);



            file.write((char*)this,sizeof(*this));

            cout<<"\n Record is modified!!"<<endl;

               flag=1;

            break;

              }}



    if(flag==0)
           cout<<"\n Sorry Room no. not found or vacant!!";
              file.close();

}



void hostel::delete_rec(int r)
{
    int flag=0;
    char ch;
    ifstream fin("Record.txt",ios::in);
    ofstream fout("temp.txt",ios::out);
    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(*this));
        if(room_no==r)
        {
            cout<<"\n Name: "<<name;
            cout<<"\n Address: "<<address;
            cout<<"\n Pone No: "<<phone;
            cout<<"\n\n Do you want to delete this record(y/n): ";
            cin>>ch;
            if(ch=='n')
            {


                fout.write((char*)this,sizeof(*this));

            }
            flag=1;

        }
        else
            fout.write((char*)this,sizeof(*this));

    }
    fin.close();
    fout.close();
    if(flag==0)
        cout<<"\n Sorry room no. not found in the record!!";
    else
    {
        remove("Record.txt");
        rename("temp.txt","Record.txt");

    }

}
void hostel::login1()
{

	flag:
	cout<<"\nEnter the username:"<<endl;
	cin>>name;
	cout<<"Enter the password:"<<endl;
	cin>>pw;
	if(name==u && pw==p)
	{
		cout<<"LOGIN SUCCESSFUL!";
		admin();
	}
	else
	{
		cout<<"LOGIN ERROR! Please try again!"<<endl;
        goto flag;

	}
}
void hostel::admin()
{

    int choice=-1;
    cout<<"\n*****Admin Menu***"<<endl<<endl;
    if(name!=u || pw!=p ){
    	return;
	}
    while(choice!=4){
        cout<<"\n\t\t\t1.Search for room allocation details";

        cout<<"\n\t\t\t2.Rooms Allotted";

        cout<<"\n\t\t\t3.Edit Record";

        cout<<"\n\t\t\t4.Exit";

        cout<<"\n\n\t\t\tEnter Your Choice: ";
        //cin>>choice;
        cin>>choice;
          switch(choice)
        {
            case 1: display();
                    break;
            case 2: rooms();
                    break;
            case 3: edit1();
                    break;
            case 4: main_menu();
                    break;
            default:
                    {
                        cout<<"\nPlease enter a valid choice\n";
                    }
        }
   }
}

void hostel::reg(){
    string username, password,fname;
        cout << endl<<"-----------------Registration:-------------------- " << endl<<endl;
        cout << "Enter a username: ";
        cin >> username;
        cout << "Enter the password: ";
        cin >> password;

        ofstream file;
        fname="data\\"+username+".txt";
        file.open(fname.c_str());
        file << username << endl << password<<endl;
        file.close();
        cout << "Registration Successful " << username << "!" << endl;
}

int hostel::isLoggedIn(){
    string finame;
    string username, password,un,pw;
    cout <<endl<<endl<<"Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

     ifstream file;
        finame="data\\"+username+".txt";
        file.open(finame.c_str());
    getline(file, un);
    getline(file, pw);

    if(un == username && pw == password)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    file.close();
}

void hostel::payment()
{
	int f;
    ifstream fin("fees.txt");
	fin>>f;
	if(f==1)
	{
	int m=65000,h=100000;
	cout<<"--------------------PAYMENT STATUS---------------------"<<endl<<endl;
    cout<<"MESS FEE:"<<m<<endl;
    cout<<"HOSTEL FEE:"<<h<<endl;
    cout<<"TOTAL AMOUNT PAID"<<endl;
    cout<<m+h;
    }
    else{
    	cout<<"FEE NOT PAID"<<endl;
	}
	fin.close();
	student_menu();
}
void hostel::student_menu(){
	int ch;
	cout<<"\n\n****Student Menu****";
	cout<<"\n\n1.Book a room\n2.Edit the details\n3.Payment details\n4.Exit"<<endl;
	cin>>ch;
	switch(ch){
		case 1:hostel::add();
		        break;
		case 2:hostel::edit();
		        break;
		case 3:hostel::payment();
		        break;
		case 4:hostel::main_menu();
		default:cout<<"Enter a valid option";
		        break;
	}


}

void hostel::login(){
            int status = hostel::isLoggedIn();
            if(status) {
                cout << endl;
                cout << "Invalid login!" << endl;
                hostel::student();
            }
            else{
                int choiceTwo;
                cout <<endl<< "Successfully logged in!" << endl;
                cout << "Welcome back!"<< endl;
                cout << endl;
                hostel::student_menu();
            }
}


void hostel::student(){
	int ch;
	while(1){
	cout<<endl;
	cout<<"------------------------"<<endl;
    cout<<"|1.Register|\n|2.Login"<<"   |"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"Enter your choice:"<<endl;
	cin>>ch;
	switch(ch){
		case 1:hostel::reg();
		        break;
		case 2:hostel::login();
		        break;
		default:cout<<"Please enter a valid choice\n";
	}
    }
}

void hostel::main_menu()
{
    int ch;
    cout<<endl;
    cout<<"\t\t\t\t\t******************************"<<endl;
    cout<<"\t\t\t\t\t* SRM HOSTEL MANAGEMENT SYSTEM *"<<endl;
    cout<<"\t\t\t\t\t******************************"<<endl<<endl;
    cout<<"------------------------"<<endl;
    cout<<"|1.Student|\n|2.Admin"<<"  |"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"Enter your choice:"<<endl;
    cin>>ch;
    switch(ch)
    {
       case 1: hostel::student();
               break;
       case 2:hostel::login1();
               break;
       default:cout<<"Please enter a valid choice\n";
    }
}
int main()

{
	system("color F2");
    hostel h;
    h.main_menu();
}
