#include <vector>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

int solution(vector<vector<int>> sizes) {
    int w = -1, h = -1;
    for(vector<int> curr : sizes){
        w = MAX(w, MAX(curr[0], curr[1]));
        h = MAX(h, MIN(curr[0], curr[1]));
    }
    
    return h * w;
}