/****** Hospital Management System Application is a menu based application which takes the input of new patient being admitted in a hospital and saves the details in arrays and simultaneously display all the patient details on the basis of automatically generated registration number, starting with 1 and so on. ****/
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
/** Main class for Hospital Management System **/
class ClassHospital
{
    struct PatientAddressDetails
    {
        char House_StreetAddress[30];

        char City[30];
        char State[30];
	};

    struct PatientPersonalInfo
    {
        char p_name[70];
        PatientAddressDetails p_add;
		int marital_status;
        int p_regno;
        int p_bloodgroup;
        int p_gender;
		char p_symtoms[100];
		char wardno[5];
		char bedno[5];
    
	}PPI[182];
    int option;
    protected:
        void AddPatientInfo();
        void ViewPatientDetails();

    public:
        void ShowMenu();
        char chAdd;
        char chView;
        char ch;
        int num;
}; // End of Class ClassHospital

class ValidateDate	/* Class meant for Date Validation */
{
    private:
 		int date;
        int month;
        int year;

    public:
        void EnterDate();
        void ShowDate();
}; // End of Class DateHandle

class DOB	/* Class for taking input of the DOB of the patient */
{
    private:
      struct PatientDOB
      {
          int p_day;
          int p_month;
          int p_year;
          int tempdob;

      }PatientDOB[100];

    public:
        void EnterDate();
        void ShowDate();
};  //End of Class DOB

    ClassHospital hos;
    ValidateDate dh1;
    DOB dob1;
    int count=0;
    int i=0;
    int tempdob;
    int registration_num;
    int temp;

int main() /** The main function **/
{
    hos.ShowMenu();
	return 0;
}

void ClassHospital :: ShowMenu()
{    
	do
    {	fflush(stdin);
		// clrscr();
		cout<<"\n  Hospital Management System"<<"\n ";
		cout<<"	 *******************"<<"\n    ";
		cout<<" Please select an option to: "<<"\n\n";
		cout<<" 1. Enter New Patient Information."<<"\n";
		cout<<" 2. View Details of Existing Patients."<<"\n";
		cout<<" 3. Exit Applcation."<<"\n\n";
		cout<<" Enter your option : "<<"   ";
		cin>>option;
		switch(option)
		{
		  case 1:
			hos.AddPatientInfo();
			break;
		  case 2:
			hos.ViewPatientDetails();
			break;
		  case 3:
		   cout<<" Thanks for using this application. \n";     
		   cout<<" Press any key to exit."<<"  ";
		   getch();
		   exit(0);
		   break;
		  default:
		   cout<<" Invalid Option."<<"  \n   ";
		   cout<<" Press any key to exit."<<"  ";
		   getch();
		   break;
		} //end of switch(option)
    }while(option!=3);
}
/* AddPatientInfo function allows to add new patient records */
void ClassHospital :: AddPatientInfo()
{
    // clrscr();
    chAdd='y';
    if(count==0)
    {
     num=1;
    } else {
     i=num;
    }
    for(i=num;chAdd=='y'||chAdd=='Y';i++)
    {
        // clrscr();
        PPI[i].p_regno=i;
        temp=num;
        cout<<"\n\nADDING INFORMATION FOR PATIENT (REGISTRATION NUMBER  " << i << ")***"<<" \n\n      ";
        cin.get(ch);
        cout<<" Registration Number : "<<PPI[i].p_regno<<"\n\n";
        cout<<" Enter Name of the Patient :"<<"   ";
        cin.getline(PPI[i].p_name,70);

		cout<<" Gender (1-Male / 2-Female)   :"<<"   ";
        cin>>PPI[i].p_gender;
        if(PPI[i].p_gender!= 1 && PPI[i].p_gender!= 2)
        {
            cout<<" Invalid value for gender of patient."<<" \n      ";
			cout<<" Reenter Gender :"<<"  ";
            cin>>PPI[i].p_gender;
        }
		cin.get(ch);
        cout<<"\n Add Patient's Address Details -"<<" \n";
        cout<<" House/Street Address                 :"<<"   ";
        cin.getline(PPI[i].p_add.House_StreetAddress,30);
        cout<<" City Name                       :"<<"   ";
        cin.getline(PPI[i].p_add.City,30);
		cout<<" State                          :"<<"   ";
        cin.getline(PPI[i].p_add.State,30);

		/** From Class DOB **/
		dob1.EnterDate();
        cin.get(ch);

		cout<<" Marital status(Enter 1 for Single, 2 for Married): "<<"   ";
        cin>>PPI[i].marital_status;
        if(PPI[i].marital_status != 1 && PPI[i].marital_status != 2)
        {
            cout<<" Invalid value for marital status ."<<"    \n        ";
            cout<<" Enter a valid marital status :"<<"    ";
            cin>>PPI[i].marital_status;
        }
        cin.get(ch);

        cout<<"\nPATIENT DETAILS"<<"\n";
		cout<<" Admitted for Disease having symtoms : "<<"  ";
        cin.getline(PPI[i].p_symtoms,100);
		cout<<" Admit to Ward No.          :"<<"  ";
        cin.getline(PPI[i].wardno,10);
		cout<<" Bed No.                    :"<<"  ";
        cin.getline(PPI[i].bedno,10);
        cout<<"\n Patient's Blood Group    :"<<"\n";
        cout<<"1. A+ "<<" \n ";
        cout<<"2. A- "<<" \n ";
        cout<<"3. B+ "<<" \n ";
        cout<<"4. B- "<<" \n ";
        cout<<"5. AB+ "<<" \n ";
        cout<<"6. AB- "<<" \n ";
        cout<<"7. O+ "<<" \n ";
        cout<<"8. O- "<<" \n ";
        cout<<"Enter the value                   :"<<"  ";
        cin>>PPI[i].p_bloodgroup;
        switch(PPI[i].p_bloodgroup)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:{ break; }
            default:{
                if(PPI[i].p_bloodgroup!=1 || PPI[i].p_bloodgroup!=2 || PPI[i].p_bloodgroup!=3 ||
                PPI[i].p_bloodgroup!=4 || PPI[i].p_bloodgroup!=5 || PPI[i].p_bloodgroup!=6 ||
                PPI[i].p_bloodgroup!=7 || PPI[i].p_bloodgroup!=8)
                {
                    cout<<" Invalid input for Blood Group."<<"                 \n ";
                    cout<<" Enter a valid Blood Group :"<<"                    ";
                    cin>>PPI[i].p_bloodgroup;
                }cin.get(ch);
            }
        }
        cin.get(ch);
        cout<<"\n Do you want to enter information for another patient(press y to continue or n to return to main menu)? "<<"";
        cin>>chAdd;
        count++;
        num++;
    } hos.ShowMenu(); 
}

/* This function takes Date of Birth as input and validates the date value. */
void DOB :: EnterDate()
{
    cout<<" Enter Date of Birth"<<"\n";
    cout<<" Year : ";
    cin>>PatientDOB[temp].p_year;
    if(PatientDOB[temp].p_year <= 1900 || PatientDOB[temp].p_year > 2008)
    {
       cout<<" Invalid Year."<<"        \n";
       cout<<" Please enter a valid Year(between 1900 and 2008) : "<<"            ";
       cin>>PatientDOB[temp].p_year;
    }
    cout<<" Month : ";
    cin>>PatientDOB[temp].p_month;

    if(PatientDOB[temp].p_month <=0 || PatientDOB[temp].p_month > 12)
    {
         cout<<" Invalid Month of the Year."<<"     \n       ";
         cout<<" Please enter a valid month(between 1 and 12) : "<<"    ";
         cin>>PatientDOB[temp].p_month;
    }
    cout<<" Date : ";
    switch(PatientDOB[temp].p_month)
    {
      case 1:{
          cin>>PatientDOB[temp].p_day;
          if(PatientDOB[temp].p_day < 1 || PatientDOB[temp].p_day > 31)
          {
            cout<<" Invalid Day of the month."<<" \n  ";
            cout<<" Please enter a valid date(between 1 and 31) :"<<"     ";
            cin>>PatientDOB[temp].p_day;
          }
          break;
      }
	  case 2:{
          cin>>PatientDOB[temp].p_day;
          if(PatientDOB[temp].p_year%4==0)
          {
            while(PatientDOB[temp].p_day < 0 || PatientDOB[temp].p_day > 29)
            {
              cout<<" Invalid Day."<<" \n  ";
              cout<<" Please enter a valid date(between 1 and 29) :"<<"      ";
              cin>>PatientDOB[temp].p_day;
            }
          }
          else
          {
            if(PatientDOB[temp].p_day < 0 || PatientDOB[temp].p_day > 28)
            {
              cout<<" Invalid Day value."<<" \n  ";
              cout<<" Please enter a valid date(between 1 and 28) :"<<"        ";
              cin>>PatientDOB[temp].p_day;
            }
          }
          break;
      }
      default:{
      cin>>PatientDOB[temp].p_day;
      if(PatientDOB[temp].p_day < 1 || PatientDOB[temp].p_day > 30)
      {
        cout<<" Invalid Day value."<<" \n  ";
        cout<<" Please enter a valid date(between 1 and 30) :"<<"                ";
        cin>>PatientDOB[temp].p_day;
      } break;
      }
    } 
}

/* This function takes date input from the user and validates the date. */
void ValidateDate :: EnterDate()
{
    cout<<"\n Please enter the current date."<<"\n";
    cout<<" Year: ";
    cin>>year;
    if(year <=1900 ||year > 2008)
    {
      cout<<" Invalid Year."<<"            \n";
      cout<<" Please enter a valid year(between 1900 and 2008) : "<<"            ";
      cin>>year;
    }
    cout<<" Month: ";
    cin>>month;
    if(month<=0||month>12)
    {
      cout<<" Invalid Month."<<"            \n";
      cout<<" Please enter a valid month(between 1 and 12) : "<<"            ";
      cin>>month;
    }
    cout<<" Date: ";
    switch(month)
    {
        case 1:{
             cin>>date;
				 if(date < 1|| date > 31)
				 {
					cout<<" Invalid Day."<<"                \n";
					cout<<" Please enter a valid day(between 1 and 31) : "<<"                ";
					cin>>date;
				 } break;
				}
        case 2:{
             cin>>date;
				 if(year%4==0) {
					  while(date < 0|| date > 29)
					  {
						cout<<" Invalid Day."<<"                \n";
						cout<<" Please enter a valid day(between 1 and 29) : "<<"                ";
						cin>>date;
					  }
				  } else {
					  if(date < 0 || date > 28)
					  {
						cout<<" Invalid Day."<<"                \n";
						cout<<" Please enter a valid day(between 1 and 28) : "<<"                ";
						cin>>date;
					  }
				} break;
        }
        default:{
          cin>>date;
			  if(date < 1 || date > 30)
			  {
				  cout<<" Invalid Day."<<"                \n";
				  cout<<" Please enter a valid day(between 1 and 30) : "<<"                ";
				  cin>>date;
			  } break;
		}
    } //close of switch case(month)
} // close of Validate Date
/* This function outputs the data according to desired format*/
void ValidateDate :: ShowDate()
{
    // clrscr();
    cout<<date;
    tempdob=date%10;
    switch(date)
    {
      case 20:{ cout<<"th ";
      goto daysuffix;
     }
    }
    switch(tempdob)
    {
      case 1:{
           cout<<"st ";
           break; }
      case 2:{
           cout<<"nd ";
           break; }
      case 3:{
           cout<<"rd ";
           break; }
      default:{
           cout<<"th ";
           break;  }
    }
    daysuffix:
      switch(month)
      {
        case 1:{
             cout<<"Jan. , ";
             break; }
        case 2:{
             cout<<"Feb. , ";
             break; }
        case 3:{
             cout<<"Mar. , ";
             break; }
        case 4:{
             cout<<"Apr. , ";
             break; }
        case 5:{
             cout<<"May , ";
             break; }
        case 6:{
             cout<<"Jun. , ";
             break; }
        case 7:{
             cout<<"Jul. , ";
             break; }
        case 8:{
             cout<<"Aug. , ";
             break; }
        case 9:{
             cout<<"Sep. , ";
             break; }
        case 10:{
             cout<<"Oct. , ";
             break;  }
        case 11:{
             cout<<"Nov. , ";
             break;  }
        case 12:{
             cout<<"Dec. , ";
             break;  }
      }
      cout<<year<<"       ";
}
/* This function shows details about a particular patient based on the registration number.*/
void ClassHospital :: ViewPatientDetails()
{
    do
    {  
      // clrscr();
       cout<<"Please enter the Registration number to search data for :"<<"        ";
       cin>>registration_num;
       cin.get(ch);
       if(registration_num > 0 & registration_num < num)
       {
        cout<<"\n\n--Details for Patient's Registration  Number: "<< registration_num << " --\n";
        cout<<" Patient Name                 : "<<PPI[registration_num].p_name<<"\n";
		cout<<" Gender                  : ";
        if(PPI[registration_num].p_gender== 1)
        {
            cout<<"Male "<<"\n";
        } 
        else if(PPI[registration_num].p_gender== 2)
        {
            cout<<"Female "<<"\n";
        }
        cout<<" Disease/Symtoms admitted for : "<<PPI[registration_num].p_symtoms;
		cout<<"\n Ward No. admitted to       : "<<PPI[registration_num].wardno;
		cout<<"\n Bed No.              : "<<PPI[registration_num].bedno;
        cout<<"\n Blood Group          : ";
        switch(PPI[registration_num].p_bloodgroup)
        {
          case 1:{
            cout<<"A+ \n";
            break; }
          case 2:{
            cout<<"A- \n";
            break; }
          case 3:{
            cout<<"B+ \n";
            break; }
          case 4:{
            cout<<"B- \n";
            break; }
          case 5:{
            cout<<"AB+ \n";
            break; }
          case 6:{
            cout<<"AB- \n";
            break; }
          case 7:{
            cout<<"O+ \n";
            break; }
          case 8:{
            cout<<"O- \n";
            break; }
        }
        cout<<" Date of birth        : ";
        dob1.ShowDate();
        cout<<"\n Marital Status       : ";
        if(PPI[i].marital_status== 1)
        {
         cout<<"Single "<<"\n";
        } else {
         cout<<"Married "<<"\n\n";
        }
        cout<<"- Patient Address Details -"<<" \n";
        cout<<"\n Street    : "<<PPI[registration_num].p_add.House_StreetAddress;
        cout<<"\n City      : "<<PPI[registration_num].p_add.City;
        cout<<"\n State   : "<<PPI[registration_num].p_add.State;
      } else {
        if(registration_num==1)
        {
          cout<<" No records available in the database."<<"  \n";
          cout<<" Press any key to exit to main menu."<<" \n";
          getch();
          // clrscr();
          hos.ShowMenu();
        }
        cout<<" The registration number is invalid."<<"  \n";
        cout<<" Press any key to continue."<<" \n";
        getch();

        hos.ViewPatientDetails();
      }
      cout<<" \nWant to see information of another patient? (Press Y or N): "<<"  ";
      cin>>chView;

   }while(chView=='y'||chView=='Y');

   hos.ShowMenu();
}
/* Shows the date output in the desired format*/
void DOB :: ShowDate()
{
    cout<<PatientDOB[registration_num].p_day;
    tempdob=PatientDOB[registration_num].p_day%10;

    switch(PatientDOB[registration_num].p_day)
    {
        case 20:{
        cout<<"th ";
        goto daysuffix;
        }
    }
    switch(tempdob)
    {
      case 1:
      {
       cout<<"st ";
       break;
      }
      case 2:
      {
       cout<<"nd ";
       break;
      }
      case 3:
      {
       cout<<"rd ";
       break;
      }
      default:
      {
       cout<<"th ";
       break;
      }
    }
    daysuffix:
      switch(PatientDOB[registration_num].p_month)
      {
        case 1:{
             cout<<"January , ";
             break; }
        case 2:{
             cout<<"February , ";
             break; }
        case 3:{
             cout<<"March , ";
             break; }
        case 4:{
             cout<<"April , ";
             break; }
        case 5:{
             cout<<"May , ";
             break; }
        case 6:{
             cout<<"June , ";
             break; }
        case 7:{
             cout<<"July , ";
             break; }
        case 8:{
             cout<<"August , ";
             break; }
        case 9:{
             cout<<"September , ";
             break; }
        case 10:{
             cout<<"October , ";
             break;  }
        case 11:{
             cout<<"November , ";
             break;  }
        case 12:{
             cout<<"December , ";
             break;  }
      }
      cout<<PatientDOB[registration_num].p_year<<"     ";
}