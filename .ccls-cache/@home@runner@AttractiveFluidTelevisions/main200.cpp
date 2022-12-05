
// Pig (pig)
// Abdullah Alrawi
// 01/28/2022
//cisp 400
  
 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string>
  using namespace std;

void ShowOptions ();

int UserRoll (int UserPoints);

int AIRoll (int AIpoints);

int DiceRandom ();

void programGreeting ();

int NumberGenerate (int RandNumber, int Hi, int Lo);

int
main ()
{
  
programGreeting ();
  
int RandNumber;
  
int Hi;
  
int Lo;
  
    // Specification C1 - Fixed Seed
    srand (12332);
  
int UserPoints = 0;
  
int AIScore = 0;
  
int TotalPoints;
  
int highscore;
  
int *p = new int;
  
bool Winner = false;
  
string UserName;
  
    // Specification C2 - Student Name
    cout << "Please enter your name: ";
  
getline (cin, UserName);
  
  do
    
    {
      
        cout << endl;
        cout << "Player's points : " << UserPoints
        <<endl;
        cout << endl;
        cout << " AI's points : " << AIScore << endl ;
        cout << endl;
      
cout << UserName << " turn : " << endl;
        cout << endl;
      
TotalPoints = UserRoll (UserPoints);
      
UserPoints += TotalPoints;
      
if (UserPoints >= 100)
    
    {
      
Winner = true;
    
}
      
      else
    {
      
        cout << endl;
        cout << "Player's points : " << UserPoints
        <<endl;
        cout << endl;
        cout << " AI's points : " << AIScore << endl ;
        cout << endl;
      
cout << "AI turn : " << endl;
        cout << endl;
      
TotalPoints = AIRoll (AIScore);
      
AIScore += TotalPoints;
      
if (AIScore >= 100)
        {
          
Winner = true;
        
}
    
}
    
 
}
  while (!Winner);
  
if (UserPoints > AIScore)
    {
      
highscore = UserPoints;
      
        cout << endl;
       cout << UserName << " WINS!!!" << endl;
        cout << endl;
      
    // Specification B3 - Hi Score on Heap
    *p = highscore;
      
    // Specification B4- Display High Score
    cout << "The highest score is " << *p << endl;
        cout << endl;
    
}
  
  else
    {
      
highscore = AIScore;
      
        cout << endl;
        cout << "AI wins!" << endl;
        cout << endl;
      
*p = highscore;
      
cout << "The highest score is " << *p << endl;
        cout << endl;
    
}
  
delete p;
  
NumberGenerate (RandNumber, Hi, Lo);
  
return 0;

}


void
ShowOptions ()
{
  
    // Specification C3 - Numeric Menu
    cout << endl;
    cout << "1 - ROLL" << endl;
    cout << endl;
    cout << "2 - HOLD" << endl;
    cout << endl;
    cout << "3 - QUIT" << endl;
    cout << endl;
    
    

}
int

UserRoll (int UserPoints)
{
  
int TotalPoints = 0;
  
int UserPick;
  
int DiceNumber;
  
 
  do
    {
      
ShowOptions ();
      
cin >> UserPick;
      
if (UserPick == 1)
    {
      
DiceNumber = DiceRandom ();
      
cout << "ROLL : " << DiceNumber << endl;
        cout << endl;
      
if (DiceNumber == 1)
        {
          
UserPick = 3;
          
TotalPoints = 0;
        
}
      
      else
        {
          
TotalPoints += DiceNumber;
          
        // Specification B1 - Display Turn Stats
        cout << "Turn Score : " << TotalPoints << endl;
            cout << endl;
          
if ((TotalPoints + UserPoints) >= 100)
        
return TotalPoints;
        
}
    
}
      
      else if (UserPick == 2)
    {
      
break;
    
}
      
      else if (UserPick == 3)
    {
      
break;
    
}
      
      else
    {
      
        // Specification C4 - Bulletproof Menu
        ShowOptions ();
      
cout << "Invalid input! please pick between the options: ";
        cout << endl;
      
cin >> UserPick;
    
 
}
    
 
}
  while (UserPick != 3);
  
cout << "Total Turn Score : " << TotalPoints << endl;
cout << endl;
  
return TotalPoints;

 
}


int
AIRoll (int AIpoints)
{
  
int TotalPoints = 0;
  
int DiceNumber;
  
bool done = false;
  
while (!done)
    {
      
DiceNumber = DiceRandom ();
      
cout << "ROLL : " << DiceNumber << endl;
cout << endl;
      
if ((DiceNumber == 1) || (DiceNumber == 2) || (DiceNumber == 3))
    {
      
break;
    
 
}
      
      else
    {
      
TotalPoints += DiceNumber;
      
if ((TotalPoints >= 20) || ((TotalPoints + AIpoints) >= 100))
        
done = true;
    
 
}
      
cout << "Turn Score : " << TotalPoints << endl;
cout << endl;
    
}
  
cout << "Total Turn Score : " << TotalPoints << endl;
  cout << endl;
return TotalPoints;

}


// Specification A1 - D6() function
  int
DiceRandom ()
{
  
cout << rand () % 6 + 1 << endl;
  
return rand () % 6 + 1;

}


// Specification A2 - RandomNumber() function
  int
NumberGenerate (int RandNumber, int Hi, int Lo)
{
  
cout << " please enter the max of the range (must be lower than 100):" <<
    endl;
  cout << endl;
cin >> Hi;
  
cout << " please enter the min of the range (must be bigger than 1):" <<
    endl;
  cout << endl;
cin >> Lo;
  
    // Specification A3 - Protect RandomNumber() input
    if ((Lo < Hi) && (1 < Lo) && (Hi < 100))
    {
      
RandNumber = rand () % Hi + Lo;
    
}
  
  else
    {
      
cout << " Invalid input!! NO RANDOM NUMBER WILL BE GENERATED." << endl;
      cout << endl;
return -1;
    
}
  
// Specification A4 - Protect RandomNumber() output
    if ((1 < RandNumber) && (RandNumber < 100))
    {
      
cout << "The generater chose " << RandNumber << endl;
      cout << endl;
return RandNumber;
    
}
  
  else
    {
      
return -2;
    
}

}


void
programGreeting ()
{
  
 
 
cout <<
    
"my greetings everyone, this program will run a dice rolling game against an AI to see who can reach a 100 first."
    
 <<endl;
  
 
 
cout << endl;
  
 
 
cout << "Abdullah Alrawi" << endl;
  
 
 
cout << endl;
  
 
    //Specification B2 - Display Due Date
    cout << "JAN 30, 2022" << endl;
  
 
 
cout << endl;

 
 
}
 
 
 
