#include <bits/stdc++.h>
using namespace std;
int dayvs[12]={31,60,91,121,152,182,213,244,274,305,335,366};
int daynvs[12]={31,59,90,120,151,181,212,243,273,304,334,365};
struct Date{
    int day, month, year,dayd, monthd, yeard;
    
    bool isValidDate(){
        if(day>0&&day<31&&month>0&&month<12){
            if(year%4==0){
                if(month==2&&day>29)
                    return false;
            }
            else
                if(month==2&&day>28)
                    return false;  
        }
		if(dayd>0&&dayd<31&&monthd>0&&monthd<12){
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
	Date Rdates[100];
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
		bool ovrlp=false;
		if(count==0){
		Rdates[0]=insert;
		count++;
		}
		else{	
			for(int i=0;i<count;i++){
				if(overlap(Rdates[i],insert))
					ovrlp=true;
			}
			if(ovrlp)
			cout<<"This date is reserved!";
			else 
			Rdates[count]=insert;	
		}	
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
		for(int i=0;i<count;i++){
				if(overlap(Rdates[i],insert))
					return false;
		}
		return true;	
	};
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
	else
	break;
	}
}	

int main(){
	//initializing cars
	int CarsNumber=3;
	
	Car mlka;
	mlka.model="Mercedes ML350";
	mlka.price=500;
	mlka.count=0;
	mlka.number=1;
	
	Car eshka;
	eshka.model="Mercedes E320";
	eshka.price=300;
	eshka.count=0;
	eshka.number=2;
	
	Car sunshine;
	sunshine.model="Mitsubishi Eclipse";
	sunshine.price=450;
	sunshine.count=0;
	sunshine.number=3;
	
	vector<Car> Cars = {mlka, eshka, sunshine};
	vector<Car> AvailableCars;
	cout<<"Hello, welcome to car rental service!!!"<<endl
	while(true){
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
		
		int choice;
		cout<<endl<<"Choose one!"<<endl;
		cin>>choice;
		cout<<"Nice choice "<<AvailableCars[choice-1].model<<endl;
		switch(AvailableCars[choice-1].number){
			case 1:
			Cars[0].book(insert);
			cout<<"total price:"<<Cars[0].totalPrice(insert)<<endl<<endl;
			break;
			case 2:
			Cars[1].book(insert);
			cout<<"total price:"<<Cars[1].totalPrice(insert)<<endl<<endl;
			break;
			case 3:
			Cars[2].book(insert);
			cout<<"total price:"<<Cars[2].totalPrice(insert)<<endl<<endl;
			break;
		}
		AvailableCars.clear();
	}
}
