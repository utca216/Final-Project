# Car rental managing system
## Some general information
| Model | Price |
|-----:|-----------|
| ML350| 200 |
| E320| 150 |
| Eclipse| 110 |
In current configuration car park consists of a 3 cars: ML350, E320, Eclipse.
Each car has it own price respectively:200, 150, 110.
Program implements 2 structures 'Car' and 'Date'.
Each member of class 'Car' has vector Rdates inside of it which contains information about reservations for a specific car.
Each member 'Car' also has it's ID number for identification during the program.
For convinience program uses vector of 'Cars'.
As program has functionality to store reservation parameters in file, it reads information from a file once before starting the program, and writes reservation to Rdates vector. Program updates Rdates.txt file every iteration cycle of a program(every time user gets in main menu).

## Project Requierment list
###Program main goal is to manage reservations of a rental car park.
It has to implement CRUD operations: Users should be able to create, read, update, and delete records. 
It has to detect and prevent from being saved overlaping car appointments. 
Handle invalid inputs.
Program functionality includes reading and writing records from a file.
It has to calculate price according to number of day being rented and price rate of a rented car.
Program's interface must be intuitive and user friendly.

## Program documentation
