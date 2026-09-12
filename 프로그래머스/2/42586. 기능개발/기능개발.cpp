#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    for(int t=0, i=0; i<progresses.size(); i++){
        if(progresses[i] + t * speeds[i] >= 100){
            answer.back() = answer.back() + 1;
        }
        else{
            t = (100 - progresses[i] + speeds[i] - 1) / speeds[i];
            answer.push_back(1);
        }
    }
    
    return answer;
}