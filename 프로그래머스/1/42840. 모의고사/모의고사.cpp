#include <vector>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

vector<vector<int>> ptn = {
    {1, 2, 3, 4, 5},
    {2, 1, 2, 3, 2, 4, 2, 5},
    {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
};

vector<int> solution(vector<int> answers) {
    int score[3] = {0};
    for(int i=0; i<answers.size(); ++i){
        for(int j=0; j<3; j++){
            if(answers[i] == ptn[j][i % ptn[j].size()]) ++score[j];
        }
    }
    
    vector<int> ans;
    int maxScore = MAX(score[0], MAX(score[1], score[2]));
    for(int i=0; i<3; ++i){
        if(maxScore == score[i]) ans.push_back(i + 1);
    }
    
    return ans;
}