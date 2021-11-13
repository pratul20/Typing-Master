# OOPL Project : Typing Master

## Introduction :
>Add introduction here

## Description :
>Add description here
## Classes defined :

1. Users
2. Menu
>2. Add rest of the classes here


### 1. Users class :

**Class variables :**
* ***users***:  It is a vector holding the names of the registered users in the Database.
* ***scores***: It is a vector holding the scores of an individual player along with the *average accuracy*, *wpm (words per minute)* & *number of test taken*

**Class functions :**
* ***Users()***: It is the constructor and is used to intialize the users vector if a vector is passed as a parameter.
* ***menu()***: It displays the available *User Reports* sub options to the users like : User Data, User List, Register User.
* ***getUsers()***: This function injects the number of users in the users vector after traversing through the Database files.
* ***printUsers()***: This function prints all the registered users list on the screen.
* ***getUserData()***: This function injects the scores of a particular user in the scores vector after traversing through that user's .txt file.
* ***printUserData()***: This function prints all the information along with the users scores on the screen.
* ***addUserStarting()***: This function prompts an upcoming user to register before the game starts
* ***updateUserInfo()***: This function updates the user informations like average accuracy, wpm and no. of tests taken.
* ***updateScores()***: This function updates the scores in all the levels of Classic and TimeAttack game mode.
* ***pressEnter***: This function just prompts the user to press the Enter key wherever required. It has been implemented as a *friend function*.

### 2. Menu class :

**Class variables :**
* ***choice***: Variable that stores the users choice in the menu.
* ***playerName***: Variable that stores the name entered by the user for storing scores.
* ***userObj***: An object of the Users class that is responsible for managing the scores of the various users.

**Class functions :**
* ***logo()***: It displays the intro banner for the program.
* ***start()***: This function sets the username of the player in the userObj object.
* ***menu()***: This function displays the application menu and allows the user to select the mode, view user data or quit.
* ***modes()***: This function is responsible for selecting and initializing the game mode as selected by the user.

### 3. Time class :

**Class variables :**
* ***start***: Static inline variable of the clock instance in C++ used to set starting time.
* ***stop***: Static inline variable of the clock instance in C++ used to set stoping time.
* ***target***: Variable that stores the time limit for time attack mode.

**Class functions :**
* ***Time()***: It is the constructor and is used to initialize the class variables.
* ***startClock()***: Static function to set the start time to the current time.
* ***stopClock()***: Static function to set the stop time to the current time.
* ***lap()***: Static function to lap over the current elapsed time and set the stop time to current time.
* ***getTime()***: Static function to get the elapsed time between start and stop.
* ***getTarget()***: Static funciton to get the target value.
* ***setTarget()***: Static function to set the target value.
* ***startIn()***: Static function that informs the user about the selected mode being started.

### 4. UserInput class (inherits from Time class in public mode) :

**Class variables :**
* ***errors***: Variable to store the count of errors made.
* ***mode***: Variable to store the mode selected by the user.
* ***timeFinished***: Variable to check if the time is up.
* ***wpm***: Variable to store the words per minute of the user.
* ***total***: Variable to store the total count.
* ***fixed***: Variable to store the fixed errors.
* ***position***: Variable that stores the current typing position.
* ***s***:  Variable that stores the string to be typed.
* ***typed***: Variable that stores the typed string.
* ***current***: Variable that stores the current character.
* ***accuracy***: Variable that stores the accuracy of the user.
* ***terminate***: Variable to check program termination.

**Class functions :**
* ***UserInput()***: It is the constructor and is used to initialize the class variables to the default values as well as set s and mode based on passed arguments.
* ***type()***: This function is responsible for managing the typing interface.
* ***isTimeFinished()***: This function returns the finish time of the application.
* ***isTerminated()***: This function returns if the program is to be terminated or not.
* ***getErrors()***: This function returns the count of errors made during typing.
* ***getTotal()***: This function returns the position till which has been typed.
* ***getAccuracy()***: This function returns the accuracy of the user.
* ***getFixedErrors()***: This function returns the count of the errors that were fixed.
* ***getWordCount()***: This function returns the number of words typed.
* ***~UserInput()***: It is the destructor and is used to free the memory once the object is no longer needed.

## Results :

### Functionalities:

**1. Classic Mode :**
```
Classic Mode
|--- Easy
|--- Medium
|--- Hard
```

**2. Time Attack Mode :**
```
Time Attack Mode
|--- 30 seconds
|--- 60 seconds
|--- 90 seconds
```

**3. User Reports :**
```
User Reports
|--- User Data
|--- Users List
|--- Register User
```

* ***User Data*** : It allows the users to get information about any users registered in the Database.
>***Output :***
<!-- <a href="https://ibb.co/QHx6yfs"><img src="https://i.ibb.co/NNGLcsw/Image-1.jpg" alt="Image-1" border="0"></a> -->
```
************************************************************************************************
  _______                   _                     __  __                 _
 |__   __|                 (_)                   |  \/  |               | |
    | |     _   _   _ __    _   _ __     __ _    | \  / |   __ _   ___  | |_    ___   _ __      
    | |    | | | | | '_ \  | | | '_ \   / _` |   | |\/| |  / _` | / __| | __|  / _ \ | '__|     
    | |    | |_| | | |_) | | | | | | | | (_| |   | |  | | | (_| | \__ \ | |_  |  __/ | |        
    |_|     \__, | | .__/  |_| |_| |_|  \__, |   |_|  |_|  \__,_| |___/  \__|  \___| |_|        
             __/ | | |                   __/ |
            |___/  |_|                  |___/
************************************************************************************************

                                  Welcome to Typing Master

Welcome gurpreet!

Select the Mode:-

1. Classic Mode
2. Time Attack Mode
3. User Reports
4. Exit
Enter Your Choice: 3

Select from the follwing choice:-
1. User Data
2. Users List
3. Register User
Enter your choice: 1
Enter the player's name you want to search:- gurpreet
***************************************
        gurpreet's Scoreboard :        
***************************************
              Classic Mode
            Easy   |      12
          Medium   |     100
            Hard   |   34.81

           Time Attack Mode
      30 seconds   |      90
      60 seconds   |      65
      90 seconds   |      79

                 Stats
        Accuracy   | 49.4899
Words per Minute   |      49
     Tests Taken   |      49
***************************************

Press Enter to continue.
```

* ***Users List*** : It allows the users to get the list of all the registered users in the Database.
>***Output :***
<!-- <a href="https://ibb.co/zrnJfVK"><img src="https://i.ibb.co/xDCH5qV/User-List.png" alt="User-List" border="0"></a> -->
```
************************************************************************************************
  _______                   _                     __  __                 _
 |__   __|                 (_)                   |  \/  |               | |
    | |     _   _   _ __    _   _ __     __ _    | \  / |   __ _   ___  | |_    ___   _ __      
    | |    | | | | | '_ \  | | | '_ \   / _` |   | |\/| |  / _` | / __| | __|  / _ \ | '__|     
    | |    | |_| | | |_) | | | | | | | | (_| |   | |  | | | (_| | \__ \ | |_  |  __/ | |        
    |_|     \__, | | .__/  |_| |_| |_|  \__, |   |_|  |_|  \__,_| |___/  \__|  \___| |_|        
             __/ | | |                   __/ |
            |___/  |_|                  |___/
************************************************************************************************

                                  Welcome to Typing Master

Welcome gurpreet!

Select the Mode:-

1. Classic Mode
2. Time Attack Mode
3. User Reports
4. Exit
Enter Your Choice: 3

Select from the follwing choice:-
1. User Data
2. Users List
3. Register User
Enter your choice: 2

1. anant
2. anonymous
3. gurpreet
4. pratul

Press Enter to continue.
```

* ***Register User*** : One can freshly register a new user by choosing this option.
>***Output :***
<!-- <a href="https://ibb.co/XXQjWSg"><img src="https://i.ibb.co/dBTjfGq/Register-User.png" alt="Register-User" border="0"></a> -->
```
************************************************************************************************
  _______                   _                     __  __                 _
 |__   __|                 (_)                   |  \/  |               | |
    | |     _   _   _ __    _   _ __     __ _    | \  / |   __ _   ___  | |_    ___   _ __
    | |    | | | | | '_ \  | | | '_ \   / _` |   | |\/| |  / _` | / __| | __|  / _ \ | '__|
    | |    | |_| | | |_) | | | | | | | | (_| |   | |  | | | (_| | \__ \ | |_  |  __/ | |
    |_|     \__, | | .__/  |_| |_| |_|  \__, |   |_|  |_|  \__,_| |___/  \__|  \___| |_|
             __/ | | |                   __/ |
            |___/  |_|                  |___/
************************************************************************************************

                                  Welcome to Typing Master

Welcome gurpreet!

Select the Mode:-

1. Classic Mode
2. Time Attack Mode
3. User Reports
4. Exit
Enter Your Choice: 3

Select from the follwing choice:-
1. User Data
2. Users List
3. Register User
Enter your choice: 3
Enter your user name:- test101
test101 has been registered succesfully
Press Enter to continue.
```
As you can see, a new `test101.txt` file has been created in `Database/HighScores` folder, whenever a new un-registered user register and all the scores and userInfo has been intialised "0" be default\
<br/>
<a href="https://ibb.co/PwccQSS"><img src="https://i.ibb.co/yW66S33/test101-User-created.png" alt="test101-User-created" border="0"></a>
## Conclusions:
> Add conclusion here






