
	//Title			:HOSPITAL MANAGEMENT in Cpp
	#include<fstream.h>
	#include<conio.h>
	#include<stdio.h>
	#include<string.h>
	#include<process.h>
	/****************************
		 STRUCTURE:DATE
	****************************/
	struct date
		{
		int dd,mm,yy,da_day,da_mon,da_year;
		};
	/****************************
		 CLASS;DOCTOR
	****************************/
	class Doctor
		{
		int Doctor_Code;
		char name[30],FatherName[30],Address[30];
		char phone[10],Mobile[10];
		char Qualifications[20],Special[20];
		int experience;
		float doctor_fee;

	public:
	void Dgetdata();
	void Ddisplaydata();

	int Return_doctor_code()
	{
		return Doctor_Code;
	}

	char *return_name()
	{
		return name;
	}

	int return_doctor_fee()
	{
		return doctor_fee;
	}
	};
	/***************************************
	 TO ACCEPT THE DATA OF DOCTOR
	***************************************/
	void Doctor::Dgetdata()
	{
		cout<<"\n Accepting Doctor's Details:";
		cout<<"\n Enter Doctor Code:";
		cin>>Doctor_Code;
		cout<<"\n Enter Name: ";
		gets(name);
		cout<<"\n Enter Father's Name: ";
		gets(FatherName);
		cout<<"\n Enter Address : ";
		gets(Address);
		cout<<"\n Enter Phone Number : ";
		gets(phone);
		cout<<"\n Enter Mobile Number: ";
		gets(Mobile);
		cout<<"\n Enter Qualification: ";
		gets(Qualifications);
		cout<<"\n Enter Specialization: ";
		gets(Special);
		cout<<"\n Enter Experience(in years): ";
		cin>>experience;
		cout<<"\n Enter Doctor's Fee: ";
		cin>>doctor_fee;
	}
	/***************************************
	 TO DISPLAY THE DATA OF DOCTOR
	***************************************/
	void Doctor::Ddisplaydata()
	{
		cout<<"\n Doctor's Details:";
		cout<<"\n Doctor's name : "<<name;
		cout<<"\n Doctor's Code : "<<Doctor_Code;
		cout<<"\n Father's Name : "<<FatherName;
		cout<<"\n Address : "<<Address;
		cout<<"\n Phone Number : "<<phone;
		cout<<"\n Mobile Number : "<<Mobile;
		cout<<"\n Qualification : "<<Qualifications;
		cout<<"\n Specialization in : "<<Special;
		cout<<"\n Experience(in years) : "<<experience;
		cout<<"\n Doctor's Fee : "<<doctor_fee;
	}
	/***************************************
	 TO ADD THE DATA OF DOCTOR
	***************************************/
	void AddDoctor()
	{ Doctor D1;
		ofstream file("Doctor.dat",ios::out|ios::binary);
		char rep;
	do
	{
	D1.Dgetdata();
		file.write((char*)&D1,sizeof(D1));
		cout<<"\n Do you want add more data ?? (Y/N)";
		cin>>rep;
	}
	while(rep=='y'||rep=='Y');
		file.close();
	}
	/***************************************
	 TO DELETE THE DATA OF DOCTOR
	***************************************/
	void DeleteDoctor()
	{      ifstream file("Doctor.dat",ios::in|ios::binary);
		ofstream fout("Doctor.dat",ios::out|ios::binary);
	Doctor D1;
	int dcode;
		cout<<"\n Enter the doctor code to be deleted";
		cin>>dcode;
	while(file.read((char*)&D1,sizeof(D1)))
	{
		if(D1.Return_doctor_code()==dcode)
	{      cout<<"\n The following record is being deleted";
	D1.Ddisplaydata();
	}
	else
	{
		fout.write((char*)&D1,sizeof(D1));
	}
	}
	file.close();
	fout.close();
	remove("doctor.dat");
	rename("new.dat","doctor.dat");
	}
	/***************************************
	 QUERY: TO DISPLAY DOCTOR'S DETAIL
	***************************************/
	void Dquery()
	{ Doctor D1;
	int d;
		cout<<"\n Enter Doctor's code: ";
		cin>>d;
		ifstream fin("doctor.dat",ios::in|ios::binary);
	while(fin.read((char*)&D1,sizeof(D1)));
	{
		if(d==D1.Return_doctor_code())
	{
	D1.Ddisplaydata();
	getch();
	return;
	}
	else
		cout<<"\n No such Doctor";
	}
	}


	/***************************************
			CLASS:WARD
	***************************************/
	class Ward
	{
		int ward_no,floor;
		int no_beds,bed_bkd;
		float bed_charges;

	public:

	Ward()
	{
	ward_no=0;
	floor=0;
	no_beds=0;
	bed_bkd=0;
	bed_charges=0;
	}

	void Wgetdata();
	void Wdisplaydata();

	int Return_Ward_no()
	{
		return ward_no;
	}
	int Return_Bed_bkd()
	{
		return bed_bkd;
	}
	int return_ch()
	{
		if(bed_bkd<=no_beds)
		return 1;
	else
		return 0;
	}
	int return_bed_charges()
	{
		return bed_charges;
	}
	void update_bed_add()
	{
		bed_bkd++;
	}
	void update_bed_remove()
	{
		bed_bkd--;
	}
	};

	/***************************************
	 TO ACCEPT THE DATA OF NEW WARD
	***************************************/
	void Ward::Wgetdata()
	{
		cout<<"\n Accepting Ward's details :";
		cout<<"\n Enter Ward No :";
		cin>>ward_no;
		cout<<"\n Enter floor :";
		cin>>floor;
		cout<<"\n Enter number of Beds :";
		cin>>no_beds;
		cout<<"\n Enter number of bed booked :";
		cin>>bed_bkd;
		cout<<"\n Enter charges per bed( for 24 hours ) :";
		cin>>bed_charges;
	}
	/***************************************
	 TO DISPLAY THE DATA OF WARD
	***************************************/
	void Ward::Wdisplaydata()
	{
		cout<<"\n Ward Details :";
		cout<<"\n Ward Number :"<<ward_no;
		cout<<"\n Floor :"<<floor;
		cout<<"\n Number of beds :"<<no_beds;
		cout<<"\n Number of Beds booked :"<<bed_bkd;
		cout<<"\n Number of Beds unbooked/ Empty :"<<no_beds-bed_bkd;
		cout<<"\n Charger per bed (for 24 hours) :"<<bed_charges;
	}
	/***************************************
	 TO ADD THE DATA OF WARD
	***************************************/
	void Wadd()
	{
	Ward W1;
		fstream file("ward.dat",ios::out|ios::binary);
		char rep ;
	do
	{
		W1.Wgetdata();
		file.write((char*)&W1,sizeof(W1));
		cout<<"Do you want to add more records?(Enter Y for yes/N for no)";
		cin>>rep;
	}while(rep=='Y'||rep=='y');
	}
	/***************************************
	 TO DELETE THE DATA OF WARD
	***************************************/
	void Wdelete()
	{
		ifstream fin("ward.dat",ios::binary);
		ofstream fout("new.dat",ios::binary);
	Ward W1;
	int wno;
		cout<<"\n Enter the ward number to be deleted:";
		cin>>wno;
	while(fin.read((char*)&W1,sizeof(W1)));
	{
		if(W1.Return_Ward_no()==wno)
	{
	W1.Wgetdata();
		fout.write((char*)&W1,sizeof(W1));
	}
	fin.close();
	fout.close();
	remove("ward.dat");
	rename("new.dat","ward.dat");
	}
	}
	/***************************************
	 TO UPDATE THE NO. OF BEDS IN WARD
	***************************************/
	void Wupdate()
	{
	fstream fin("ward.dat",ios::in|ios::binary);
	fstream fout("new.dat",ios::out|ios::binary);
	Ward W1;
	int wno;
	char ans;
		cout<<"\nEnter the ward number to be modified  :";
		cin>>wno;
	while(fin.read((char*)&W1,sizeof(W1)))
	{
		if(W1.Return_Ward_no()==wno)
	{
		cout<<"\n Do you want to book a bed or unbook a bed??";
		cout<<"\n Enter B for booking and U for Unbooking) :";
		cin>>ans;
	if (ans=='b'|| ans=='B')
	{
	W1.update_bed_add();
		cout<<"\nBed Booked Successfully!!";
		cout<<"\nNew number of beds in the ward :"<<W1.Return_Bed_bkd()<<endl;
	}
	else if (ans=='u'|| ans=='U')
	{
	W1.update_bed_remove();
		cout<<"\nBed Unbooked Successfully!!";
		cout<<"\nNew number of beds in the ward :"<<W1.Return_Bed_bkd()<<endl;
	}
	}
	}
		fout.write((char*)&W1,sizeof(W1));
	fin.close();
	fout.close();
	remove("ward.dat");
	rename("new.dat","ward.dat");
	}
	/***************************************
	 QUERY:TO DISPLAY THE DETAILS OF WARD
	***************************************/
	void Wquery()
	{  Ward W1;
	int w;
		cout<<"\n Enter Ward Number: ";
		cin>>w;
		fstream fin("ward.dat",ios::in|ios::binary);
	while(fin.read((char*)&W1,sizeof(W1)))
	{
		if(w==W1.Return_Ward_no())
	{
	W1.Wdisplaydata();
	getch();
	return;
	}
	else
		cout<<"\n No such Ward.";
	}
	}


	/***************************************
		 CLASS:PATIENT
	***************************************/
	class Patient
	{
		int reg_no,doctor_code;
		char Patient_name[30],Paddress[30];
		char Pphone[10],Pmobile[10],Disease[20];
		date d;
		int Ward_no,Bed_No;
		float ad_fee,charges,doctor_fee;

	public:
	Patient()
	{
	reg_no=0;
	doctor_code=0;
	strcpy(Patient_name,"Null");
	strcpy(Paddress,"Null");
	strcpy(Pphone,"Null");
	strcpy(Pmobile,"Null");
	strcpy(Disease,"Null");
	ad_fee=0;
	charges=0;
	doctor_fee=0;
	}

	date Admit_dat;
	float Addn_fee,fee,Total_Bed_charges,Grand_Total;
	char AddnTest[20];
	void Pgetdata();
	void Pdisplaydata();

	int Return_reg_no()
	{
		return reg_no;
	}

	float Return_Addn_fee()
	{
		return Addn_fee;
	}

	int Return_ad_fee()
	{
		return ad_fee;
	}

	char *Return_Patient_Name()
	{
		return Patient_name;
	}

	float Return_Doctor_fee()
	{
		return doctor_fee;
	}
	float Return_charges()
	{
		return charges;
	}
	};
	/***************************************
	 TO ACCEPT THE DATA FOR PATIENT
	***************************************/
	void Patient::Pgetdata()
	{

		cout<<"\n Enter Registration Number: ";
		cin>>reg_no;
		cout<<"\n Enter Patient Name: ";
		gets(Patient_name);
		cout<<"\n Enter Patient Address: ";
		gets(Paddress);
		cout<<"\n Enter Phone Number: ";
		gets(Pphone);
		cout<<"\n Enter Mobile Number: ";
		gets(Pmobile);
		cout<<"\n Enter Additional fee charged(if any): ";
		cin>>Addn_fee;
		cout<<"\n Enter The Tests Done(if any)" ;
		gets(AddnTest);

	Ward W1;
	long offset;
	int x;
		cout<<"\n Enter Ward Number: ";
		cin>>Ward_no;
		fstream fout("ward.dat",ios::in|ios::out|ios::binary);
	while(fout.read((char*)&W1,sizeof(W1)))
	{
	if(W1.Return_Ward_no()==Ward_no)
	{
		cout<<"\n You are booking in ward number: "<<Ward_no<<endl;
		x=W1.return_ch();
	if(x==1)
	{
		cout<<"\n Beds are availible";
		offset=(fout.tellp()-sizeof(W1));
		fout.seekp(offset);
		W1.update_bed_add();
		fout.write((char*)&W1,sizeof(W1));
		charges=W1.return_bed_charges();
		cout<<"\n Enter Bed Number: ";
		cin>>Bed_No;
		cout<<"\n Bed charges are: "<<charges;
	break;
	}
	else if(x==0)
		cout<<"\n Beds are not availible";
	}
	}
	Doctor D1;
		cout<<"\n Enter Doctor Code: ";
		cin>>doctor_code;
	fstream fin1("doctor.dat",ios::in|ios::binary);
	while(fin1.read((char*)&D1,sizeof(D1)))
	{
		if(D1.Return_doctor_code()==doctor_code)
	{
		doctor_fee=D1.return_doctor_fee();
	break;
	}
	}
		cout<<"\n Doctor Fee: "<<doctor_fee;
		cout<<"\n Enter Disease: ";
		gets(Disease);
		cout<<"\n Enter Addmission Fee Charged: ";
		cin>>ad_fee;
		cout<<"\n Enter Today's Date:";
		cin>>d.dd;
		cout<<"/";
		cin>>d.mm;
		cout<<"/";
		cin>>d.yy;
		cout<<"\n Enter Admit Date:";
		cin>>Admit_dat.dd;
		cout<<"/";
		cin>>Admit_dat.mm;
		cout<<"/";
		cin>>Admit_dat.yy;
	}
	/***************************************
	 TO DISPLAY THE DATA OF A PATIENT
	***************************************/
	void Patient::Pdisplaydata()
	{
		cout<<"\n Registration Number:"<<reg_no;
		cout<<"\n Patient Name:"<<Patient_name;
		cout<<"\n Patient Address:"<<Paddress;
		cout<<"\n Phone Number:"<<Pphone;
		cout<<"\n Mobile Number:"<<Pmobile;
		cout<<"\n Disease:"<<Disease;
		cout<<"\n Date:"<<d.dd<<"/"<<d.mm<<"/"<<d.yy;
		cout<<"\n Doctor Code:"<<doctor_code;
		cout<<"\n Ward Number:"<<Ward_no;
		cout<<"\n Bed Number:"<<Bed_No;
		cout<<"\n Admit Date:"<<Admit_dat.dd<<"/"<<Admit_dat.mm<<"/"<<Admit_dat.yy;
		cout<<"\n Addmission Fee charged:"<<ad_fee;
		cout<<"\n Additional Test/Visit Name:"<<AddnTest;
		cout<<"\n Additional Fee Amount(if any):"<<Addn_fee;
	}
	/***************************************
		TO ADD DATA OF PATIENT
	***************************************/
	void Padd()
	{
	Patient P1;
		ofstream fout("Patient.dat",ios::out|ios::binary);
		char rep;
	do
	{
	P1.Pgetdata();
	fout.write((char*)&P1,sizeof(P1));
		cout<<"\n Do you want to add more data?(Y/N): ";
		cin>>rep;
	}while(rep=='y'||rep=='Y');
	fout.close();
	}
	/**************************************************
		TO ADD FEE AMOUNT WHEN A VISIT/TEST IS DONE
	**************************************************/

	void Pupdate()
	{
		fstream fin("Patient.dat",ios::in|ios::binary);
		fstream fout("new.dat",ios::out|ios::binary);
	Patient P1;
	int Rno;
		cout<<"\n Enter Patient's Registration Number: ";
		cin>>Rno;
	while(fin.read((char*)&P1,sizeof(P1)))
	{
	if(P1.Return_reg_no()==Rno)
	{
		cout<<"\n Additional Test/Visit Name:";
		gets(P1.AddnTest);
		cout<<"\n Additional Fee Amount Charges:";
		cin>>P1.Addn_fee;
		fout.write((char*)&P1,sizeof(P1));
	}
	else
	fout.write((char*)&P1,sizeof(P1));
	}
	fin.close();
	fout.close();
	remove("Patient.dat");
	rename("new.dat","Patient.dat");
	}
	/*********************************************
	 QUERY:TO DISPLAY THE DETAILS OF PATIENT
	**********************************************/
	void Pquery()
	{ Patient P1;
	int p;
		cout<<"\n Enter Patient's Registration Number: ";
		cin>>p;
	fstream fin("Patient.dat",ios::in|ios::binary);
	while(fin.read((char*)&P1,sizeof(P1)))
	{
	if(p==P1.Return_reg_no())
	{
	P1.Pdisplaydata();
	getch();
	return;
	}
	else
		cout<<"\n No such Patient.";
	}
	}


	/***************************************
			BILL GENERATION
	***************************************/
	void Bill()
	{
	Patient P1;
	Doctor D1;
	Ward W1;
	date Discharge_date;
	int dcode,reg_no,Days ;
	clrscr();
		cout<<"\n\t\t\t \4\4BILL GENERATION SYSTEM\4\4";
		cout<<"\nEnter Patient's Registration Code: ";
		cin>>reg_no;
	fstream f1("Patient.dat",ios::in|ios::binary);
	while (f1.read((char*)&P1,sizeof(P1)))
	{
	if(P1.Return_reg_no()==reg_no)
	{
		cout<<"\n Enter no. of days of stay: ";
		cin>>Days;
		cout<<"\nEnter Discharge date: ";
		cin>>Discharge_date.dd;
		cout<<".";
		cin>>Discharge_date.mm;
		cout<<".";
		cin>>Discharge_date.yy;
		cout<<"\n\t\t\tGenerating Bill for patient Reg.no: "<<P1.Return_reg_no();
		cout<<"In\t\t\tPATIENT NAME: "<<P1.Return_Patient_Name();
		cout<<"\n\t\t\tAddmission Fee: "<<P1.Return_ad_fee( );
		cout<<"\n\t\t\tAdditional Fee(if any): "<<P1.Return_Addn_fee();
		cout<<"\n\t\t\tDoctor Fee: "<<P1.Return_Doctor_fee();
		cout<<"\n\t\t\tBed Charges (per day): "<<P1.Return_charges();
		cout<<"\n\t\t\tNo of Days Spent:"<<Days;
	P1.Total_Bed_charges=P1.Return_charges()*Days;
		cout<< "\n\t\t\tDischarge Date: ";
		cout<<Discharge_date.dd;
		cout<<".";
		cout<<Discharge_date.mm;
		cout<<".";
		cout<<Discharge_date.yy;
		cout<<"\n\t\t\tTotal Bed Charges: "<<P1.Total_Bed_charges;
	P1.fee=P1.Return_ad_fee()+P1.Return_Addn_fee()+D1.return_doctor_fee()+P1.Total_Bed_charges;
		cout<<"\n\t\t\tTotal Fee: "<<P1.fee;
		cout<<"\n\t\t\tService Tax (10% of the total fee): "<<P1.fee*.1;
	P1.Grand_Total=P1.fee+0.1*P1.fee;
		cout<<"\n\t\n\tGRAND TOTAL(tax incl.) : "<<P1.Grand_Total;
	}
	else
	{
		cout<<"\n No such patient";
	}
	}
	}


	/***************************************
		 DOCTOR MANAGEMENT
	***************************************/
	void submenu1()
	{
	clrscr();
	int ch1;
	cout<<"\n\t\t\tDOCTOR MANAGEMENT"
	<<"\n\n\t\t\t1.Add a new doctor's details"
	<<"\n\n\t\t\t2.Delete a doctor's details"
	<<"\n\n\t\t\t3.Return to main menu";
	cout<<"\n\n\t\t\tENTER YOUR CHOICE:"<<endl;
	cin>>ch1;
	switch(ch1)
	{
	case 1: clrscr();
		AddDoctor();
	break;
	case 2: clrscr();
		DeleteDoctor();
	break;
	case 3: return;
	}
	getch();
	}



	/***************************************
		 WARD MANAGEMENT
	***************************************/
	void submenu2()
	{
	clrscr();
	int ch2;
	cout<<"\n\t\t\tWARD MANAGEMENT"
	<<"\n\n\t\t\t1.Add a new Ward's details"
	<<"\n\n\t\t\t2.Delete a Ward's details"
	<<"\n\n\t\t\t3.Modify a Ward's details"
	<<"\n\n\t\t\t3.Update a Ward(book or unbook a bed)"
	<<"\n\n\t\t\t4.Return to main menu";
	cout<<"\n\n\t\t\tENTER YOUR CHOICE: "<<endl;
	cin>>ch2;
	switch (ch2)
	{
	case 1: clrscr();
		Wadd();
	break;
	case 2: clrscr();
		Wdelete() ;
	break;
	case 3: clrscr();
		Wupdate();
	break;
	case 4: return;
	}
	getch();
	}



	/***************************************
		 PATIENT MANAGEMENT
	***************************************/
	void submenu3 ()
	{

	clrscr();
	int ch3;
	cout<<"\n\t\t\tPATIENT MANAGEMENT"
	<<"\n\n\t\t\t1.Add a new Patient's details"
	<<"\n\n\t\t\t2.Update a Patient's details (Additional Fee)"
	<<"\n\n\t\t\t3.Return to main menu";
	cout<<"\n\n\t\t\tENTER YOUR CHOICE: "<<endl;
	cin>>ch3;
	switch(ch3)
	{
	case 1: clrscr();
		Padd();
	break;
	case 2: clrscr();
		Pupdate();
	break;
	case 3: return;
	}
	getch();
	}




	/***************************************
			MANAGEMENT
	***************************************/
	void submenu4()
	{
	clrscr();
	int ch4;
	cout<<"\n\t\t\t MANAGEMENT"
	<<"\n\n\t\t\t1. Display a doctor's details"
	<<"\n\n\t\t\t2. Display a Ward's details"
	<<"\n\n\t\t\t3. Display a patient's dtails"
	<<"\n\n\t\t\t4. Display bill of a patient"
	<<"\n\n\t\t\t5. Return to main menu";
	cout<<"\n\n\t\t\tENTER YOUR CHOICE: "<<endl;
	cin>> ch4;
	switch(ch4)
	{
	case 1: clrscr();
		Dquery();
	break;
	case 2: clrscr();
		Wquery();
	break;
	case 3: clrscr();
		Pquery();
	break;
	case 4: clrscr();
		Bill();
	break;
	case 5: return;
	}
	getch();
	}



	/***************************************
			 MAIN MENU
	***************************************/
	void main()
	{
	int ch;
	do
	{
	clrscr();
	cout<<"\n\t\t\t\t WELCOME TO";
	cout<<"\n\t\t\t H0SPITAL MANAGEMENT PROGRAM";
	cout<<"\n\n\n\t\t\t\t  MAIN MENU"
	<<"\n\n\t\t\t1. Doctor Management"
	<<"\n\n\t\t\t2. Ward Management"
	<<"\n\n\t\t\t3. Patient Management"
	<<"\n\n\t\t\t4. Query"
	<<"\n\n\t\t\t5. Exit";
	cout<<"\n\n\t\t\tENTER YOUR CHOICE: ";
	cin>>ch;
	switch (ch)
	{
	case 1: submenu1();
	break;
	case 2: submenu2();
	break;
	case 3: submenu3 ();
	break;
	case 4: submenu4();
	break;
	case 5: exit(0);
	default:cout<<"\n INVALID OPTION";
	}
	}while(ch!=5);

	getch();
	}