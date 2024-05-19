# Car rental managing system
## Some general information
In current configuration car park consists of a 3 cars: ML350, E320, Eclipse.
Each car has it own price respectively:200, 150, 110.
| Model | Price |
|-----:|-----------|
| ML350| 200 |
| E320| 150 |
| Eclipse| 110 |

Program implements 2 structures 'Car' and 'Date'.
Each member of class 'Car' has vector Rdates inside of it which contains information about reservations for a specific car.
Each member 'Car' also has it's ID number for identification during the program.
For convinience program uses vector of 'Cars'.
As program has functionality to store reservation parameters in file, it reads information from a file once before starting the program, and writes reservation to Rdates vector. Program updates Rdates.txt file every iteration cycle of a program(every time user gets in main menu).

## Insturction
### Main menu:

  ![Снимок экрана 2024-05-19 151758](https://github.com/utca216/Final-Project/assets/151619685/6a15e6aa-6047-467d-b565-87e2ff9aeeb1)
  
  There is 4 option available:
  + Book car - for booking car type into console 1 and follow instruction on the screen. You will be asked to type desired date of rent to console in format day/month/year. After that program will show list of available cars for your date. You must type in console number of one you want to rent and car will be reserved. Total price will be calculated and displayed in console.

  ![Снимок экрана 2024-05-19 151919](https://github.com/utca216/Final-Project/assets/151619685/1eb0d7db-c469-4a6d-b02b-9d96b5ecb764)

  + Delete reservation - for deleting reservation you type in console 2. After that you choose a car which reservations you want to delete, by entering corresponding number into console. The list of dates will be shown from which you pick one you want to delete and program will delete it.

![Снимок экрана 2024-05-19 152916](https://github.com/utca216/Final-Project/assets/151619685/f681cc8a-6980-4d7a-a16c-afc28eb174da)




## Project Requierment list
### Purpose 
+ Program main goal is to manage reservations of a rental car park.
+ To nake easy to use convinient program where user can store and edit records.
### Intendent Audience 
+ Managers of a car rental companies
### Features
+ Program does implement CRUD operations: Users is able to create, read, update, 
and delete records. 
+ It detects and prevents overlaping car appointments from being saved. 
+ Handles invalid inputs.
+ Program functionality includes reading and writing records from a file.
+ It calculates price according to number of day being rented and price rate of a rented car.
+ Program's interface is intuitive and user friendly. Because of showing only available cars interaction with program has as less error messages occur as possible.

## Program documentation
### Date structure
Date structure is crucial program class it used to store, update, show car reservations. Every Date member has date of start and date of end in (day/month/year) format. Every variable inside this class named respecrively(day/month/year) for start of reservation and (dayd/monthd/yeard). It also uses two massives of integers: dayvs, daynvs. They contain information about number of days since start of a year to end of a given month. One massive for intercalary year and one for non-intercalary year.

Date structure have also several functions:
+ IsValidDate - checks if date is valid and not out of bounds. Returns bool.
+ CalculateDifference - returns int number of difference between two dates. Used to calculate total price of a rent.
+ CoutDate - printing transmitted date to the console.

### Car structure
Car structure is used to store all information about a rented car, including reservation dates. For this purposes 'Car' has vector of 'Date's inside of it. Car member has several parameters: model, price rate, Rdates vector(reservations), ID number.

Car structure have also several functions:
+ book - pushing new member to Rdates vector(Saving reservation).
+ coutDates - printing all reserved dates for Car.
+ dateAvailable - chaeck if given date interval is available for a specific car. Returns bool.
+ eraseDates - erase given date from Rdates vector.
+ overlap - checks if given dates overlap for a specific car. Used in dateAvailable function.
+ totalPrice - calculating total price for a given 'Date' interval.

  

## Test Files
Program include only one operating file called 'Rdates.txt'.
For demonstrational purposes 5 reservation were created and inserted among 3 cars.
Values in that file stored according to this logic:

First line contains ID of a car which reservation is below. ![Снимок экрана 2024-05-19 000050](https://github.com/utca216/Final-Project/assets/151619685/7943aecd-b421-4e29-a9b7-2421e6cc4802)

First half ofsecond line contains information about starting date of reservation,(day/month/year) 

![Снимок экрана 2024-05-19 000240](https://github.com/utca216/Final-Project/assets/151619685/755a9c54-b7b5-4d5f-a96d-3623d804b099) 

While the second half describes the end of reservation.(day/month/year)

![Снимок экрана 2024-05-19 000333](https://github.com/utca216/Final-Project/assets/151619685/6833f21e-576f-4194-bf98-4d38e3311399) 

Each reservation consumes 2 lines.
