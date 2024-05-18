#include <bits/stdc++.h>
using namespace std;
int dayvs[12]={31,60,91,121,152,182,213,244,274,305,335,366};
int daynvs[12]={31,59,90,120,151,181,212,243,273,304,334,365};
int a,b;
struct Date{
    int day, month, year,dayd, monthd, yeard;
    
    bool isValidDate(){
        if(day>0&&day<32&&month>0&&month<13){
            if(year%4==0){
                if(month==2&&day>29)
                    return false;
            }
            else
                if(month==2&&day>28)
                    return false;  
        }
		if(dayd>0&&dayd<32&&monthd>0&&monthd<13){
				if(year%4==0){
					if(monthd==2&&dayd>29)
						return false;
				}
				else
					if(monthd==2&&dayd>28)
						return false;
		return true;    
		}
		else
		return false;
	}; 
    int calculateDifference(int day1, int month1,int year1){
        int dayb=0, dayb1=0;
        if(year>=year1){
            if(year%4==0&&month!=1)
                dayb+=dayvs[month-2];
            if(year%4!=0&&month!=1)
                dayb+=daynvs[month-2];
            if(year1%4==0&&month1!=1)
                dayb1+=dayvs[month1-2];
            if(year1%4!=0&&month1!=1)
                dayb1+=daynvs[month1-2];
        return (day-day1+dayb-dayb1+abs(year-year1)*365)+2;    
        }
        else{
            if(year%4==0&&month!=1)
                dayb+=dayvs[month-2];
            if(year%4!=0&&month!=1)
                dayb+=daynvs[month-2];
            if(year1%4==0&&month1!=1)
                dayb1+=dayvs[month1-2];
            if(year1%4!=0&&month1!=1)
                dayb1+=daynvs[month1-2];
        return (day1-day+dayb1-dayb+abs(year-year1)*365)+2; 
        }
	};
	void coutDate(){
	if(year!=yeard)	
	cout<<day<<"."<<month<<"."<<year<<"-"<<dayd<<"."<<monthd<<"."<<yeard;
	else
	cout<<day<<"."<<month<<"-"<<dayd<<"."<<monthd<<"."<<yeard;
	};
};
bool operator==(Date &BirthDate,Date &Fs){
    return Fs.day==BirthDate.day&&Fs.month==BirthDate.month&&Fs.year==BirthDate.year;
}
bool operator<(Date BirthDate,Date Fs){
    if(Fs.year>BirthDate.year)
    return true;
    else if(Fs.year<BirthDate.year)
    return false;
    if(Fs.month>BirthDate.month)
    return true;
    else if(Fs.month<BirthDate.month)
    return false;
    if(Fs.day>BirthDate.day)
    return true;
    else
    return false;
}
bool operator>(Date Fs,Date BirthDate){
    if(Fs.year>BirthDate.year)
    return true;
    else if(Fs.year<BirthDate.year)
    return false;
    if(Fs.month>BirthDate.month)
    return true;
    else if(Fs.month<BirthDate.month)
    return false;
    if(Fs.day>BirthDate.day)
    return true;
    else
    return false;
}

Date insert;
int duration;

struct Car{
	string model;
	int price;
	vector<Date> Rdates;
	int count;
	int number;
	
	bool overlap(Date st1, Date ins){
		int start1,start2,end1,end2;
		if(st1.year%4==0)
			start1=abs(2024-st1.year)*366+dayvs[st1.month-1]+st1.day;
		else
			start1=abs(2024-st1.year)*365+daynvs[st1.month-1]+st1.day;
		if(ins.year%4==0)
			start2=abs(2024-ins.year)*366+dayvs[ins.month-1]+ins.day;
		else
			start2=abs(2024-ins.year)*365+daynvs[ins.month-1]+ins.day;
		if(st1.year%4==0)
			end1=abs(2024-st1.yeard)*366+dayvs[st1.monthd-1]+st1.dayd;
		else
			end1=abs(2024-st1.yeard)*365+daynvs[st1.monthd-1]+st1.dayd;
		if(ins.year%4==0)
			end2=abs(2024-ins.yeard)*366+dayvs[ins.monthd-1]+ins.dayd;
		else
			end2=abs(2024-ins.yeard)*365+daynvs[ins.monthd-1]+ins.dayd;
		
		if((start2==start1||end1==end2) ||
	       (start1<start2&&end1>start2) ||
		   (start1>start2&&end2>start1) ||
		   (start1<start2&&end2<end1) ||
		   (start1>start2&&end2>end1))
		return true;
		
	return false;														
	};
	
	void book(Date insert){
		Rdates.push_back(insert);
	};
	
	int totalPrice(Date ins){
		int start2,end2;
		if(ins.year%4==0)
			start2=abs(2024-ins.year)*366+dayvs[ins.month-1]+ins.day;
		else
			start2=abs(2024-ins.year)*365+daynvs[ins.month-1]+ins.day;
		if(ins.year%4==0)
			end2=abs(2024-ins.yeard)*366+dayvs[ins.monthd-1]+ins.dayd;
		else
			end2=abs(2024-ins.yeard)*365+daynvs[ins.monthd-1]+ins.dayd;
		return price*(end2-start2);	
	}
	
	bool dateAvailable(Date insert){
		for(int i=0;i<Rdates.size();i++){
				if(overlap(Rdates[i],insert))
					return false;
		}
		return true;	
	};
	
	void coutDates(){
		for(int i=0;i<Rdates.size();i++){
			cout<<i+1<<". ";
			Rdates[i].coutDate();
			cout<<endl;
		}
	};
	
	void eraseDates(int b){
	auto itr = Rdates.begin(); 
	Rdates.erase(itr+b);
	}
	
	
};

void cindate(){
	while(true){
		cin>>insert.day;
		cin>>insert.month;
		cin>>insert.year;
		cin>>insert.dayd;
		cin>>insert.monthd;
		cin>>insert.yeard;
		if(!insert.isValidDate())
		cout<<"Invalid Date, write properly!!!!"<<endl;
		else{
			if(insert.year<insert.yeard)
			break;
			else if(insert.year==insert.yeard&&insert.month<insert.monthd)
				break;
				else if(insert.day<insert.dayd&&insert.month==insert.monthd)
					break;
		cout<<"Invalid Date, write properly!!!!"<<endl;					
		} 
	}
}	

int main(){
	//initializing cars
	int CarsNumber=3;
	
	Car mlka;
	mlka.model="Mercedes ML350";
	mlka.price=200;
	mlka.count=0;
	mlka.number=1;
	
	Car eshka;
	eshka.model="Mercedes E320";
	eshka.price=150;
	eshka.count=0;
	eshka.number=2;
	
	Car sunshine;
	sunshine.model="Mitsubishi Eclipse";
	sunshine.price=110;
	sunshine.count=0;
	sunshine.number=3;
	
	vector<Car> Cars = {mlka, eshka, sunshine};
	vector<Car> AvailableCars;
	
	//start reading file
	
	ifstream fin("Rdates.txt");//read start
	string line;
	int o, choice;
	long long lin;
	if(!fin){
		cerr<<"Error oppening file!"<<endl;
	}
	while(fin>>o){
		int num;
		fin>>lin;
			num=lin%10000;
			lin=lin/10000;
			insert.yeard=num;
			num=lin%100;
			lin=lin/100;
			insert.monthd=num;
			num=lin%100;
			lin=lin/100;
			insert.dayd=num;
			num=lin%10000;
			lin=lin/10000;
			insert.year=num;
			num=lin%100;
			lin=lin/100;
			insert.month=num;
			num=lin%100;
			lin=lin/100;
			insert.day=num;
			Cars[o].Rdates.push_back(insert);		
	}
	fin.close();
	
	//read end
	
	cout<<"Hello, welcome to car rental service!!!"<<endl;
	while(true){
			
			cout<<"1. Book car"<<endl<<"2. Delete reservation"<<endl<<"3. Update reservation for a car"<<endl<<"4. See reservations for a car"<<endl;
			cin>>a;
			switch(a){
			case 1:	
				cout<<"Which date you want to reserve?"<<endl<<"Enter date of start and end in a following format: day|month|year"<<endl;
				cindate();
				cout<<"List of cars available for your date:"<<endl;
				
				for(int i=0;i<CarsNumber;i++){
					if(Cars[i].dateAvailable(insert))
						AvailableCars.push_back(Cars[i]);
				}
				for(int i=0;i<AvailableCars.size();i++){//showing available cars
						cout<<i+1<<". "<<AvailableCars[i].model<<endl;
				}
				cout<<endl<<"Choose one!"<<endl;
				cin>>choice;
				cout<<"Nice choice "<<AvailableCars[choice-1].model<<endl;
					Cars[AvailableCars[choice-1].number-1].book(insert);
					cout<<"total price:"<<Cars[AvailableCars[choice-1].number-1].totalPrice(insert)<<endl<<endl;
				AvailableCars.clear();
			break;
			case 2:
				cout<<"Which car reservation you want to delete?"<<endl<<"1. Mercedes ML350"<<endl<<"2. Mercedes E320"<<endl<<"3. Mitsubishi Eclipse"<<endl;
				cin>>a;
					cout<<"Choose date you want to delete:"<<endl;
					Cars[a-1].coutDates();
					cin>>b;
					if(b<=Cars[a-1].Rdates.size()){
						Cars[a-1].eraseDates(a-1);
						cout<<"Deleted succefully!"<<endl<<endl;
					}	
					else
						cout<<"No cush date";
			break;
			
			case 3:
				cout<<"Which car reservation you want to update?"<<endl<<"1. Mercedes ML350"<<endl<<"2. Mercedes E320"<<endl<<"3. Mitsubishi Eclipse"<<endl<<"4. Cancel"<<endl;
				cin>>a;
					Cars[a-1].coutDates();
					cout<<"Chose date you want to update"<<endl;
					cin>>b;
					Cars[a-1].eraseDates(b-1);
					cout<<"New date:"<<endl;
					cindate();
					if(Cars[a-1].dateAvailable(insert)){
						Cars[a-1].Rdates.push_back(insert);
						cout<<"Date updated succesfullly!"<<endl<<endl;
					}	
					else
						cout<<"Date is reserved"<<endl;
			break;
			case 4:
				cout<<"Which car reservation you want to see?"<<endl<<"1. Mercedes ML350"<<endl<<"2. Mercedes E320"<<endl<<"3. Mitsubishi Eclipse"<<endl;
				cin>>a;
				cout<<endl;
				Cars[a-1].coutDates();
				cout<<endl;		
			}
	
	//writing to file
			
	ofstream fout("Rdates.txt");
	if (!fout) {
        	cerr << "Error opening output file!" << endl;
    	}
    	for(int i=0;i<3;i++){
			for(int k=0;k<Cars[i].Rdates.size();k++){
				fout<<i<<endl;
				if(Cars[i].Rdates[k].day<10)
					fout<<0<<Cars[i].Rdates[k].day;
				else	
					fout<<Cars[i].Rdates[k].day;
				if(Cars[i].Rdates[k].month<10)
					fout<<0<<Cars[i].Rdates[k].month;
				else	
					fout<<Cars[i].Rdates[k].month;
						
				fout<<Cars[i].Rdates[k].year;
				
				if(Cars[i].Rdates[k].dayd<10)
					fout<<0<<Cars[i].Rdates[k].dayd;
				else	
					fout<<Cars[i].Rdates[k].dayd;
				if(Cars[i].Rdates[k].monthd<10)
					fout<<0<<Cars[i].Rdates[k].monthd;
				else	
					fout<<Cars[i].Rdates[k].monthd;
				
				fout<<Cars[i].Rdates[k].yeard<<endl;		
			}
		}		
	fout.close();		
	//writing to file end
	
	}
	
	
			
}
