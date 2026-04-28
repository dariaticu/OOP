#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>

using namespace std;
ifstream fin("input.txt");

struct ComparaCuv 
{
    // a, b sunt perechi <cuv,frecv>
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) 
    {
        string cuv1 = a.first;
        string cuv2 = b.first;
        int frecv1 = a.second;
        int frecv2 = b.second;
        if (frecv1 != frecv2)
        {
            if (frecv1 < frecv2)
                return true;
            else return false;
        }
        else
        {
            if (cuv1 > cuv2)
                return true;
            else return false;
        }
    }
};
int main() 
{
    string text = "";
    string line;
    while (getline(fin, line))
        text=text+line+" "; 
  
    fin.close();

    string separators = " ,.!?";

    map< string, int > dictionar;

    size_t start = text.find_first_not_of(separators);

    while (start != string::npos) 
    {
        size_t end = text.find_first_of(separators, start);
        string cuv = text.substr(start, end - start);

        for (char& c : cuv) 
            c = tolower(c);

        dictionar[cuv]++;
        start = text.find_first_not_of(separators, end);
    }

    priority_queue< pair<string, int>, vector< pair<string, int>>, ComparaCuv> pq;

    map<string, int>::iterator it;

    for (it = dictionar.begin(); it != dictionar.end(); it++) 
        pq.push(*it);

    cout << "Rezultatul final:" << endl;
    while (!pq.empty()) 
    {
        cout << "    " << pq.top().first << " => " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}