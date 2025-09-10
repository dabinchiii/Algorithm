#include <iostream>

#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

#define SIZE 50

using namespace std;

struct loc {
    int r, c;
};

bool operator==(loc &a, loc &b){
    return (a.r == b.r && a.c == b.c);
}

string strdata[SIZE + 1][SIZE + 1]; // root들만 데이터값 가짐
loc parent[SIZE + 1][SIZE + 1];

void print() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
        }
        cout << endl;
    }
}
void init() {
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            parent[i][j] = {i, j}; // 자기자신
            strdata[i][j] = "";
        }
    }
    
    return;
}

loc findRoot(loc x){
    if(parent[x.r][x.c] == x) return parent[x.r][x.c];
    return parent[x.r][x.c] = findRoot(parent[x.r][x.c]);
}
void makeUnion(loc rootA, loc rootB){ // b를 a에
    if(rootA == rootB) return;
    
    strdata[rootB.r][rootB.c] = "";
    //parent[rootB.r][rootB.c] = rootA;
    
    for(int i=1; i<=SIZE; i++){
        for(int j=1; j<=SIZE; j++){
            if(parent[i][j] == rootB) parent[i][j] = rootA;
        }
    }
    
    return;
}
vector<string> solution(vector<string> commands) {
    init();

    vector<string> answer;

    for (string line : commands) {
        vector<string> tokens;
        istringstream iss(line);
        
        string token;
        while (iss >> token) {
            tokens.push_back(token);
        }

        string command = tokens[0];

        if (command == "UPDATE") {
            if (tokens.size() == 4) { // UPDATE r c value
                int r = stoi(tokens[1]);
                int c = stoi(tokens[2]);
                string value = tokens[3];

                loc p = parent[r][c];
                strdata[p.r][p.c] = value;
            }
            else { // UPDATE value1 value2
                string value1 = tokens[1];
                string value2 = tokens[2];

                for(int i=1; i<=SIZE; i++){
                    for(int j=1; j<=SIZE; j++){
                        if(strdata[i][j] == value1) strdata[i][j] = value2;
                    }
                }

            }
        }
        else if (command == "MERGE") { // MERGE r1 c1 r2 c2
            int r1 = stoi(tokens[1]);
            int c1 = stoi(tokens[2]);
            int r2 = stoi(tokens[3]);
            int c2 = stoi(tokens[4]);
            
            loc root1 = findRoot({r1, c1});
            loc root2 = findRoot({r2, c2});
            
            if(strdata[root1.r][root1.c].empty()){ // (r1, c1)을 (r2, c2)에
                makeUnion(root2, root1);
            }
            else{
                makeUnion(root1, root2);
            }

        }
        else if (command == "UNMERGE") { // UNMERGE r c
            int r = stoi(tokens[1]);
            int c = stoi(tokens[2]);
            
            loc root = findRoot({r, c});
            string origin = strdata[root.r][root.c];
            strdata[root.r][root.c] = "";
            strdata[r][c] = origin;
            
            for(int i=1; i<=SIZE; i++){
                for(int j=1; j<=SIZE; j++){
                    if(parent[i][j] == root){
                        parent[i][j] = {i, j};
                    }
                }
            }
        }
        else if (command == "PRINT") { // PRINT r c
            int r = stoi(tokens[1]);
            int c = stoi(tokens[2]);
            
            loc p = findRoot({r, c});
            string res = strdata[p.r][p.c];
            answer.push_back(res.empty() ? "EMPTY" : res);
        }

        //cout << line << endl;
        //print();
    }


    
    return answer;
}
/*
int main() {
    vector<string> commands = { "UPDATE 1 1 menu", "UPDATE 1 2 category", "UPDATE 2 1 bibimbap", "UPDATE 2 2 korean", "UPDATE 2 3 rice", "UPDATE 3 1 ramyeon", "UPDATE 3 2 korean", "UPDATE 3 3 noodle", "UPDATE 3 4 instant", "UPDATE 4 1 pasta", "UPDATE 4 2 italian", "UPDATE 4 3 noodle", "MERGE 1 2 1 3", "MERGE 1 3 1 4", "UPDATE korean hansik", "UPDATE 1 3 group", "UNMERGE 1 4", "PRINT 1 3", "PRINT 1 4" };
    //vector<string> commands = { "UPDATE 1 1 a", "UPDATE 1 2 b", "UPDATE 2 1 c", "UPDATE 2 2 d", "MERGE 1 1 1 2", "MERGE 2 2 2 1", "MERGE 2 1 1 1", "PRINT 1 1", "UNMERGE 2 2", "PRINT 1 1" };
    
    vector<string> ans = solution(commands);
    for (string curr : ans) cout << curr << endl;
    return 0;
}
*/
