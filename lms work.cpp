#include<iostream>
#include<iomanip>
#include <cstring>
#include <fstream>
#include <cmath>
#include <sstream>
using namespace std;

bool isValidCourseCode(string courseCode){
	bool isValid = false;
	if(courseCode.size() <= 5){
		if(courseCode[0] >= 'A' && courseCode[0] <= 'Z'){
				if(courseCode[1] >= 'A' && courseCode[1] <= 'Z'){
				
				if ((courseCode[2]<='9') && (courseCode[2]>='0')){
					if((courseCode[3]<='9') && (courseCode[3]>='0')) {
						if ((courseCode[4]<='9')&& (courseCode[4]>='0')){
						isValid = true;
						}
					}
				}
			}
		}
	}
	return isValid;
}
bool isValidCourseName(string name)
{ int flag=0; 
 char arr[50];
for(int i=0;i<50;i++)
{

arr[i]=name[i];
if((arr[i] >= 'a'&& arr[i]<='z')||(arr[i]<='Z'&& arr[i]>='A')||(arr[i]==' '))
{

flag =1;}
}
if (flag==1)
return 1;
else return 0;


}
bool IsCreditHours(int hours)
{ int flag=0;

 if (hours<=3)
 {
 
flag=1; }
if(flag=1)
return 1;
else return 0;


}
bool isValidSmester(int i)
{ int flag=0;
if (i<=8)
{ flag=1;
}
if (flag==1)
return 1;
else return 0;
}
int search(string ar[],int s,string name){
	int a1=-1;
	for(int i=0; i<s; i++)
	{
		if(name==ar[i])
		{ a1=i;
		break;
		}
		
	}
	return a1;
}

void AddCourse(string codeList[],string nameList[],int creditHours[],int smesterList[],int h)
	{ 
	 string courseCode,courseName;
	int  credithours,smester;
	bool t=false;
	while(t==false)
	{ cout<<"Enter the detial of course: ";
	cin>> courseCode>>credithours>>smester;
	cin.ignore('\n',' ');
	getline (cin,courseName);
	bool a= isValidCourseCode (courseCode);
	bool b= isValidCourseName(courseName);
	bool c= IsCreditHours(credithours);
	bool d= isValidSmester(smester);
	if (a==true && b==true && c==true && d==true)
	{ codeList[h]=courseCode;
	   nameList[h]=courseName;
	   creditHours[h]=credithours;
	   smesterList[h]=smester;
	   t=true;
	   cout<< "\n Course has been added successfully \n";
	}
	else{ "invalid information";
	}
	}
	}
	
void editCourse(string codeList[],string nameList[],int creditHours[],int smesterList[],int h)
	{ 
	 string courseCode,courseName;
	int  credithours,smester;
	bool t=false;
	 cout<<"Enter course code:";
	cin>> courseCode;
	  int c=search(codeList,50,courseCode);
	  if(c!=-1){
	  	h=c;
	  	while(t==false){
	  		cout<< "enter new detail of course: ";
	cin>> courseCode>>credithours>>smester;
	cin.ignore('\n',' ');
	getline (cin,courseName);
	bool a= isValidCourseCode (courseCode);
	bool b= isValidCourseName(courseName);
	bool c= IsCreditHours (credithours);
	bool d= isValidSmester (smester);
	if (a==true && b==true && c==true && d==true)
	{ codeList[h]=courseCode;
	   nameList[h]=courseName;
	   creditHours[h]=credithours;
	   smesterList[h]=smester;
	   t=true;
	   cout<< "\n Course has been editted successfully " << endl;
	}
	else{ "invalid information\n"; }
}
}
}
	void deleteCourse(string codeList[],string nameList[],int creditHours[],int smesterList[],int h)
	{ 	 string courseCode,courseName;
	int  credithours,smester,e;
	bool t=false;
	cout<< "Enter the course to delete \n";
	cin>>courseCode;
    e=search(codeList,50,courseCode);
   {
     if(e==1||e==3){
	codeList[e]='\0';
	   nameList[e]='\0';
       creditHours[e]='\0';
	   smesterList[e]='\0';
	   cout<< "\n Course has been deleted successfully " << endl;
              }
       
    }
	}
	void viewCourse(string codeList[],string nameList[],int creditHours[],int smesterList[],int h)
	{cout<< left<<setw(15)<<"courseCode"<<setw(50)<<"CourseName"<<setw(15)<<"creditHours"<<setw(15)<<"smester"<< endl;
	for(int i=0;i<h;i++){
	if(creditHours[i]==1||creditHours[i]==2||creditHours[i]==3)
	{ 	cout<<left<< setw(15)<< codeList[i]<< setw(50)<< nameList[i]<< setw(15)<<creditHours[i]<<setw(15)<<smesterList[i]<< endl;
	} 
                        }
	}
		void viewsmester(string codeList[],string nameList[],int creditHours[],int smesterList[],int h){
			int na;
		cout<<"Enter the Semester: ";
		cin>>na;
		cout<<left<<setw(15)<<"CourseCode"<<setw(50)<<"Name"<<setw(15)<<"CreditHours"<< endl;
		for(int i=0; i<h; i++){
			if(smesterList[i]==na){
				cout<<left<<setw(15)<<codeList[i]<<setw(50)<<nameList[i]<<setw(15)<<creditHours[i]<<endl;
			}
		}
}
	bool savecourse(string codeList[],string nameList[],int creditHours[],int smesterList[] ,int h)
	{
		ofstream outdata;
		outdata.open("Course.txt");
		for(int i=0;i<h;i++)
		{
	outdata<< codeList[i];
	outdata<<",";
	outdata<<	nameList[i];
	outdata<<",";
	outdata<<	creditHours[i];
	outdata<<",";
	outdata<<	 smesterList[i] ;
	outdata<< endl;

		}
		outdata.close();
      	}
		int str_int(string str)
	{
		int n=0;
		int size;
		 size=str.size();
		for(int i=0;i<size;i++)
		{
		 n+=(str[--size]-'0')*pow(10,i);
	   	}
   	}
		bool loadcourse(string codeList[],string nameList[],int creditHours[],int smesterList[] ,int &h)
		{   
		ifstream input;
		input.open("Course.txt");
		string n,crd,s,c,line;
		int c1,s1;
		while(getline(input,line))
		{ int i=0;
			
			{
				while(line[i]!=',')
				{
					codeList[h]+=line[i];
					i++;
				}
				i++;
				while(line[i]!=',')
				{
					nameList[h]+=line[i];
					i++;
				}
				i++;
				creditHours[h]=(line[i]%48);
				i++;
				smesterList[h]=(line[i+1]%48);
				
			}

	   h++;	 
		}
		input.close();
		}
	bool loadUsers(string userlist[],string passwordlist[])
	{ 
	bool f=false;
	int h=0;
  	string u_n,pa,u,p,line;
	ifstream set;
	set.open("user.txt");
	while(getline(set,line))
	{ userlist[h]="";
	passwordlist[h]="";
	int i=0;
	while(line[i]!=',')
	{
		userlist[h]+=line[i];
		i++;
	}
			cout<<userlist[h]<<endl;

	i++;
	while(line[i]!='\0')
	{
		passwordlist[h]+=line[i];
		i++;
	}

    h++;
	}
	set.close();
	
	 cout << "Dear User, current software is intended for authorized users only"<<endl<<" Login to the system to get access"<< endl;
	 cout<< "username"<<endl;
	 cin>> u_n;
	 cout<< "password"<< endl;
	 cin>> pa;
	 for(int i=0;i<h;i++)
	 { 
	 if(u_n==userlist[i] && pa==passwordlist[i])
	 {
	        f=true;
	       
	  }
	 
	 }
return f;
	}
		bool isvalidregnum(string num)
	{  if(num.size()==11)
	{

	if(num[0]== '2'&& num[1]== '0'&& num[2]== '1'&& isdigit(num[3]) && num[4]=='-'&&num[5]<='Z' && num[5]>='A' && num[6]<='Z'&& num[6]>='A'&& num[7]=='-'&& isdigit(num[8]) && isdigit(num[9]) && isdigit(num[10]))
    {    
	 	return true;
    }
	else
	return false;
    }
	}
	bool isstudentname(string x)
	{  
	{ int flag=0; 
 int s=x.size();
for(int i=0;i<s;i++)
{


if(isalpha(x[i])||(x[i]==' '))
{

flag++;}
}
if (flag==s)
return true;
else
 return false;

}
	}
	 void addstudent(string studentnamelist[],string registrationlist[],string name,string regno,int &h)
	 {  
	  if (isstudentname(name)&&isvalidregnum(regno))
	           {
				 studentnamelist[h]=name;
				 registrationlist[h]=regno;
				 h++; 
				 cout<< "Student has been added successfully"<< endl<<endl;
			}
		cout<<"Invalid details\n";
	 }
	  void updatestudent(string studentnamelist[],string registrationlist[],string name,string regno,int &h)
	  {  cout<<"Enter the regestrition no to edit";
	  cin>> regno;
	  	int c;
	    c=search( registrationlist,50,regno);
	    h=c;
	    cout<<"Enter new details of student: ";
	    cin>> regno;
	    getline(cin,name);
	    if(h!=-1)
	    {  if (isstudentname(name)&&isvalidregnum(regno))
	           {
				 studentnamelist[h]=name;
				 registrationlist[h]=regno;
				 h++; 
				 cout<< "Student has been editted successfully"<< endl<<endl;
		    	}
		}
	
	  }
	  	void deletestudent(string studentnamelist[],string registrationlist[],string regno,int &h)
	{ 	 
       cout<<"Enter the regestrition no to delete";
	  cin>> regno;
	  	int c;
	    c=search( registrationlist,50,regno);
	    h=c;
   {
     if(h!=-1){
      studentnamelist[h]='\0';
	  registrationlist[h]='\0';

	   cout<< "\n student has been deleted successfully " << endl;
              }
       
    }
	}
	void registerCourse(string codeList[],string registrationlist[],string courselist[][2],string regno,string courseCode,int& c)
	{ cout<<" Enter registration Number of the student for course registration: "<< endl;
	  cin>>regno;
	  cout<< endl; 
	  cout<<" Enter Course Code to register: ";
	  cin>> courseCode;
	  if(isvalidregnum(regno))
	  {
	  	if(isValidCourseCode( courseCode))
	  	{
	  		courselist[c][0]=regno;
	  		courselist[c][1]=courseCode;
	  		c++;
		  }
	  }
	  cout<< endl;
	  c++;
	  "Course has been regestered successfully /n";
		
	}
	void unregisterCourse(string codeList[],string registrationlist[],string courselist[][2],string regno,string courseCode,int& c)
	{ cout<<" Enter registration Number of the student : "<< endl;
	  cin>>regno;
	  cout<< endl; 
	  cout<<" Enter Course Code to unregister: ";
	  cin>> courseCode;
	    if(isvalidregnum(regno))
	  {
	  	if(isValidCourseCode( courseCode))
	  	{
	  	//	courselist[c][0]='/0';
	  	//	courselist[c][1]='/0';
	  	//	c++;
		  }
	  }
	  cout<< endl;
	  c++;
	  cout<< "Course has been unregestered successfully /n";
		
	}
	int index;
	bool StdLoginID(string stdRegNoList[], string stdNamesList[], int& h)
{
	string regNo, pass;
	cout<<"RegNo: ";
	cin>>regNo;
	cout<<"Password: ";
	cin>>pass;
	for(int i=0;i<h;i++)
	{
		if(regNo==stdRegNoList[i])
		{
			int a=stdNamesList[i].size();
			if(stdNamesList[i][a-3]==pass[0] && stdNamesList[i][a-2]==pass[1] && stdNamesList[i][a-1]==pass[2])
			{
				index=i;
				return true;
			}
			
		}
	}
	return false;
}

void ViewStdCourses(string stdNamesList[], string stdRegNoList[], string stdCourseList[][2], int& c)
{
	cout<<left<<setw(20)<<"Reg. No"<<setw(50)<<"Name"<<setw(50)<<"Courrses\n";
	cout<<left<<setw(20)<<stdRegNoList[index]<<setw(50)<< stdNamesList[index];
	for(int i=0;i<c;i++)
	{
		if(stdRegNoList[index]==stdCourseList[i][0])
		{
			cout<<stdCourseList[i][1]<<" ";
		}
		cout<<endl;
	}
}

bool saveStudents(string stdRegNoList[], string stdNamesList[], string stdCourseList[][2],int& c,int& h)
{
	bool save=false;
	ofstream f;
	f.open("Students.txt");
	for(int i=0;i<h;i++)
	{
		cout<<stdRegNoList[i]<<","<<stdNamesList[i]<<endl;
		for(int j=0;j<c;j++)
		{
			if(stdRegNoList[i]==stdCourseList[c][0])
			{
				cout<<stdCourseList[c][1];
				if(j==c-1)
				cout<<endl;
				else
				cout<<",";
			}
		}
		save=true;
	}
	f.close();
	return save;
}
int main()
{ 
  string codeList[50];
string nameList[50];
int creditHours[50];
int smesterList[50];
string courseNmae,courseCode,regesno,name;
int credithours,smester,repeat=0,h=0, a,b=1,c=0,opt;
string userlist[50];
string passwordList[50];
string studentnamelist[50];
string registrationlist[50];
string courselist[200][2];
loadcourse(codeList,nameList,creditHours,smesterList ,repeat);
cout << "Choose the option for Login\n";
	cout << "1    for Student\n";
	cout << "2   for Admin\n";
	cout << "Enter option: ";
	cin>>opt;
	switch (opt)
	{
		case 1:
	{
	
do
{
  cout  << endl<<"** Welcome to the University Learning Managment System"<< endl;
  if(loadUsers(userlist,passwordList))
{

  cout<<"YOU have succesfully login "<< endl;
  
  do{
  
  cout<< "Choose the following option"<< endl
  << "1 Add Course"<< endl
  << "2 Update Course "  <<endl;
  cout<< "3 Delete Course"<< endl
  << "4 view All Course"<< endl
  <<"5 View All Course Of a smester"<< endl 
  << "6 Add new student"<< endl
  << "7 Update student"<< endl
  << "8 delete student"<< endl
  << "9 view all student"<< endl
  << "10 Register the course for student"<< endl
  << "11 UNregister the course for student"<< endl
  << "12 Logout the system"<< endl
  << "13 Exit Program";
  cout<< endl
<< "choose the option: ";
	
	cin>> a;
	switch(a)
	{ 
	
            	case 1:
	 
                 	AddCourse (codeList, nameList, creditHours, smesterList, repeat);
                	repeat++;
                 	break;
     	
            	case 2:
     	        	editCourse (codeList, nameList, creditHours, smesterList, repeat);
     		
     		
     	        	break;
     	    	case 3:
     	           	deleteCourse( codeList, nameList, creditHours, smesterList,repeat);
     	       
     	             break;
     	       case 4:
     	        	 viewCourse( codeList, nameList, creditHours, smesterList,repeat);
     	       	
     	             break;
     	        case 5:
     	       	 	 viewsmester(codeList, nameList,creditHours, smesterList,repeat);
     	       	 	 
     	       	 	 break;
     		    case 6:
                  cout<< "Enter detail of student"<< endl;
                  cin>> regesno;
                  getline(cin,name);
     	    	addstudent( studentnamelist,registrationlist,name ,regesno, h);
     	    	
     	        	break;
     	    	case 7:  		
     	    	updatestudent(studentnamelist,registrationlist,name, regesno,h);
     
     	    		break;
     	    	case 8:
     	    			deletestudent( studentnamelist,registrationlist,regesno,h);
     	    	    break;
     	    	case 9:
     	    			cout<< left<<setw(30)<<"Registration no "<< setw(50)<< "Student Name"<<endl;
     	    			for(int i=0;i<h;i++)
     	    		{
						 	cout<< left<<setw(30)<< registrationlist[i]<<setw(50)<<studentnamelist[i]<<endl;
					 }
					break;
					 case 10:
					 registerCourse(codeList, registrationlist,courselist,regesno,courseCode,c);
					 break;
					 case 11:
					 	unregisterCourse(codeList,registrationlist,courselist, regesno, courseCode,c);
					 	break;
     	    	case 12:
     	    			
     		cout<<"You have successfully Loged out.\n";
     		 break;
     	
     	case 13:
     		savecourse( codeList, nameList,creditHours,smesterList, repeat); 
     		saveStudents( registrationlist, studentnamelist, courselist,c,h);
     		b=0;
     		break;
     		
		 default :
     	cout<<	" no program"; 
     	
     }}while(b!=13 && a!=12);
 }
 else
   { 
     cout<<"Sorry, we are unable to run the program ,as user do not exist";
   }

 } while(b!=13);
 break;
}
case 2:
	{
		do{
		
		if(	StdLoginID( registrationlist, studentnamelist, h))
		{
			cout << "Enter 1 to view registered course\n";
			cout << "Enter 2 to logout of the system\n";
			cout << "Enter 3 to exit\n";
			do{
				cout<<"Enter the option: ";
				cin>>b;
				switch (b)
				{
					case 1:
						 ViewStdCourses(  studentnamelist, registrationlist, courselist, c);
						 break;
					case 2:
						cout<<"Log Out\n";
						break;
					case 3:
						cout<<"program exited\n";
						break;
							default:
						cout<<"Wrong input\n";
							break;
				}
			}while(b!=3 && b!=2);
		}
	}while(b!=3);
	break;
	}
	default:
		cout<<"Wrong input\n";
		break;
}
     return 0;
 }
