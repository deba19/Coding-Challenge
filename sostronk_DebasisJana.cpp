/*                              So Stronk Assignment
This program is made by Debasis Jana, Lovely Professional University
University Reg No: 11701186
Email ID: debasisjana93@gmail.com
Mobile Number: 9609624692 / 8918470674
*/

#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
int main()
{
    fastio;
    string m;
    getline(cin,m);
    vector<pair<string,int>> player;
    string line, name;
    int score;
    while (getline(cin, line) && !line.empty())
    {
        istringstream iss(line);
        if (iss >> name >> score)
        player.push_back(make_pair(name, score));
    }

    //we need at least m*2 numbers of players to make 2 teams of size m each
    if(player.size()<stoi(m)*2)
    {
        cout<<"\nTeam making is not possible\n";
    }
    else
    {
        //team declaration
        vector<pair<vector<string>,double>>teamA;
        vector<pair<vector<string>,double>>teamB;
        int k=1,totrun=0;
        double avgrun=0;

        for(int i=0;i<=stoi(m);i++)
        {
            vector<string>plyr;
            totrun=0,avgrun=0;
            //Creating possible team A
             
            //adding the first teammate in the list
            plyr.push_back(player[0].first);
            //counting total run of this team players
            totrun+=player[0].second;
            int j;
            for(j=k;j<stoi(m)+k-1;++j)
            {
                //adding other m-1 teammates in a team
                plyr.push_back(player[j].first);
                //counting total run of this team players
                totrun+=player[j].second;
            }  
            
            avgrun=totrun/(double)plyr.size();
            //Added one possible team A with average score of the team mates
            teamA.push_back(make_pair(plyr,avgrun));
           
            //clearing all data from the temporary team list
            plyr.clear(), totrun=0,avgrun=0;
            int count1=0;

            //creating possible team B
            for(int w=1;w<k;w++)
            {
                count1++;
                plyr.push_back(player[w].first);
                totrun+=player[w].second;
            }
            for(int w=j;w<stoi(m)-count1+j;w++)
            {
                plyr.push_back(player[w].first);
                totrun+=player[w].second;
            }
            avgrun=totrun/(double)plyr.size();
            //Added one possible team B with average score of the team mates
            teamB.push_back(make_pair(plyr,avgrun));
            k++;

        }

        //Activate these lines if you want to see players team wise

       /* for(auto xx:teamA)
            {
                vector<string>ss=xx.first;
                for(auto yy:ss)
                cout<<yy<<" ";
                cout<<xx.second<<"\n";
            }
            cout<<"\n";
         for(auto xx:teamB)
            {
                vector<string>ss=xx.first;
                for(auto yy:ss)
                cout<<yy<<" ";
                cout<<xx.second<<"\n";
            }*/

        //making a vector pair of difference of two teams average score and the two teams
        vector<pair<double,pair<pair<vector<string>,double>,pair<vector<string>,double>>>>answer;
        for(int i=0;i<teamA.size();i++)
        {
            //Match i+1, team one player list 
            vector<string>t1=teamA[i].first;
            //Match i+1, team two player list 
            vector<string>t2=teamB[i].first;
            //Match i+1, team one average score 
            double avg1=teamA[i].second;
            //Match i+1, team two average score 
            double avg2=teamB[i].second;
            //difference of their average score
            double diff=abs(avg1-avg2);
            //pushing them all in a vector 
            answer.push_back(make_pair(diff,make_pair(make_pair(teamA[i].first,avg1),make_pair(teamB[i].first,avg2))));
        }
        //sorting difference of average scores from best to worst
        sort(answer.begin(),answer.end());
        for(int i=0;i<answer.size();i++)
        {
            //Match i+1, team one player list 
            vector<string>t1=answer[i].second.first.first;
            //Match i+1, team two player list 
            vector<string>t2=answer[i].second.second.first;
             //Match i+1, team one average score 
            double avg1=answer[i].second.first.second;
            //Match i+1, team two average score 
            double avg2=answer[i].second.second.second;

            //printing possible matches with given format 

            cout<<t1[0];
            for(int j=1;j<t1.size();j++)
            cout<<","<<t1[j];
            cout<<" ("<<avg1<<")";
            cout<<" vs ";

            cout<<t2[0];
            for(int j=1;j<t2.size();j++)
            cout<<","<<t2[j];
            cout<<" ("<<avg2<<")";

            cout<<"\n";

        }

    }
    return 0;
}