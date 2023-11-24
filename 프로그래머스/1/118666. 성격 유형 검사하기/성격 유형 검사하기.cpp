#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    map<char, int> m;

    for(int i=0; i<(int)survey.size(); i++){
        int score = abs(choices[i] - 4);

        if(choices[i] < 4) m[survey[i][0]] += score;
        else m[survey[i][1]] += score;
    }

    string Answer = "";

    // R/T
    if(m['R'] < m['T']) Answer.push_back('T');
    else Answer.push_back('R');

    // C/F
    if(m['C'] < m['F']) Answer.push_back('F');
    else Answer.push_back('C');

    // J/M
    if(m['J'] < m['M']) Answer.push_back('M');
    else Answer.push_back('J');

    // A/N
    if(m['A'] < m['N']) Answer.push_back('N');
    else Answer.push_back('A');

    return Answer;
}