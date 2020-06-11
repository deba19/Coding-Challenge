# Coding-Challenge

#### Made BY: 
#### Debasis Jana
#### Lovely Professional University
#### Registration No: 11701186
#### Email ID: debasisjana93@gmail.com

## Commands to run the program in Linux based environment 

### Method 1 : By running the .sh file
Write the following command after opening terminal in project folder

    1. chmod +x run.sh
    2. ./run.sh
    3. Enter required inputs of the program

### Method 2 : By directly running .cpp file (if you have g++ installed in your pc)
Write the following command after opening terminal in project folder

    1. g++ sostronk_DebasisJana.cpp
    2. ./a.out
    3. Enter required inputs of the program

### Please note that, this program gives perfect output only when value of N (number of total players) is less than or equal to 2*M, i.e N<=2*M, (M denotes number of players in a team in one particular match)

#### Demo of the program with given sample inputs
![Output File] (https://drive.google.com/file/d/1VJRhjS0iPmMfBIN6bh-NDd_2xKPwV3X9/view?usp=sharing)
Format: ![Alt Text](url)
#### Basic Idea of the program
Below explanation is based on the constraints: N<=2*M

The basic idea is, when we have less than (2*M) numbers of players we never can form a team of M unique players in each team. We will be able to make the team only when we have at least 2*M numbers of total players. (This prgram does not give perfect output when total numbers of players is greater than 2*M)

So, we have to make two teams of M players in each team. If we look carefully, we can make team with the 1st player of the list with other M-1 players. And then, we can make another team with remaining N-M players. Thus, this program creates all possible matches by making two teams of M unique players in each.

#### Program explanation
As mentioned above, I have first created two vector pairs (one for possible team A and one for possible team B with respect to team A) which can store players name and their average score. 
Then I have instered required data in the vector pairs.

Then I have calculated differece of average scores of one match so that I can sort the matches from best to worst.
To do this, I have created one vector pair of pair of pair,

    'vector<pair<double,pair<pair<vector<string>,double>,pair<vector<string>,double>>>>answer;'

Means in the last pair we are storing one team with player name and average scores, then second last pair stores two teams Team A and Team B with their data, and the first pair stores Match Details and Difference of average score.

At last I have printed the required answer.

Thank You
