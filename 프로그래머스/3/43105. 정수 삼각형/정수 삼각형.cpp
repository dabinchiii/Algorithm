#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int N = triangle.size();
    vector<int> v(triangle[N - 1]);
    
    for(int i=N - 2; i>=0; i--){
        for(int j=0; j<=i; j++){
            v[j] = max(v[j], v[j + 1]) + triangle[i][j];
        }
    }
    
    return v[0];
}