#include<iostream>
#include<iomanip>
#include<limits>
#include<string>
using namespace std;

const int SUBJECT_COUNT=5;
const int MAX_MARKS=100;
struct Student{
    string name;
    int marks[SUBJECT_COUNT]{};
    int total=0;
    double average=0.0;
    char grade='F';
};
int readInteger(const string &prompt,int min,int max ){
    int value;
    while(true){
        cout<<prompt;
        if(cin>>value && value>=min&&value<=max){
            return value;
        }
        cout<<"Invalid input. Enter an integer between "<<min<<"and"<<max<<".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
}
void enterStudentDetails(Student& student){
    cout<<"Enter student name:";
    getline(cin>>ws,student.name);
    for(int i=0;i<SUBJECT_COUNT;++i){
        student.marks[i]=readInteger("Enter marks for subject"+to_string(i+1)+"(0-100)"
        ,0,MAX_MARKS);
     
    }
}
void calculateResults(Student& student){
    student.total=0;
    for(int mark:student.marks){
        student.total+=mark;
    }
    student.average=static_cast<double>(student.total)/SUBJECT_COUNT;
    if(student.average>=90)
        student.grade='A';
    else if(student.average>=75)
        student.grade='B';
    else if(student.average>=60)
        student.grade='C';
    else if(student.average>=50)
        student.grade='D';
    else
        student.grade='F';   
}
void displayResults(const Student& student){
    cout<<"\n======Student Report=====\n";
    cout<<"Name:"<<student.name<<"\n";
    for(int i=0;i<SUBJECT_COUNT;++i){
        cout<<"Subject"<<i+1<<":"<<student.marks[i]<<"/"<<MAX_MARKS<<"\n";

    }
    cout<<"--------------\n";
    cout<<"Total:"<<student.total<<"/"<<SUBJECT_COUNT*MAX_MARKS<<"\n";
    cout<<fixed<<setprecision(2);
    cout<<"Average:"<<student.average<<"\n";
    cout<<"Grade:"<<student.grade<<"\n";
    cout<<"========================\n";
}
int main(){
    Student student;
    bool detailsEntered=false;
    int choice;
    cout<<"+++++++++++++++Student Marks Manager+++++++++++++++\n";
    do{
        cout<<"1.Enter Student Details\n";
        cout<<"2.Calculate and view Results\n";
        cout<<"3.Exit\n";
        choice=readInteger("Enter your choice(1-3):",1,3);
        switch(choice){
            case 1:
                enterStudentDetails(student);
                detailsEntered=true;
                cout<<"Student details saved successfully.\n";
                break;
            case 2:
                if(detailsEntered){
                    calculateResults(student);
                    displayResults(student);
                }else{
                    cout<<"Please enter student details first.\n";

                }
                break;
            case 3:
               cout<<"Thank you for using Student Marks Manager!\n";
               break;
        }
     
    }while(choice!=3);

    return 0;
}