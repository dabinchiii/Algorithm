#include <bits/stdc++.h>

using namespace std;

void solve(int idx, string str){
    string protocol, host, port, path;
    string defaultStr = "<default>";

    // protocol
    for(int i=0; i<str.length(); i++){
        if(str[i] != ':') continue;
        if(str[i + 1] != '/') continue;
        if(str[i + 2] != '/') continue;

        protocol = str.substr(0, i);
        str = str.substr(i + 3);
        break;
    }

    host = str;
    for(int i=0; i<host.length(); i++){
        if(host[i] != '/') continue;

        path = host.substr(i + 1);
        host = host.substr(0, i);
        break;
    }

    for(int i=0; i<host.length(); i++){
        if(host[i] != ':') continue;

        port = host.substr(i + 1);
        host = host.substr(0, i);
        break;
    }

    cout << "URL #" << idx << '\n';
    cout << "Protocol = " << protocol << '\n';
    cout << "Host     = " << host << '\n';
    cout << "Port     = " << (port.length() == 0 ? defaultStr : port) << '\n';
    cout << "Path     = " << (path.length() == 0 ? defaultStr : path) << '\n';
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string str;
    for(int i=1; i<=n; i++){
        cin >> str;
        solve(i, str);
    }

    return 0;
}
