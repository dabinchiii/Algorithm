#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    
    for(int curr : arr){
        if(answer.back() == curr) continue;
        answer.push_back(curr);
    }

    return answer;
}