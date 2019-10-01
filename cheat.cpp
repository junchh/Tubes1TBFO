#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define el '\n'

struct state {
    int hygiene;
    int energy;
    int fun;
};

struct transition {
    int hygieneChange;
    int energyChange;
    int funChange;
};

state playerState[65];
bool vis[65];
int dist[65];
map<string, int> commandString;
transition change[19];
string stringCommand[19];
vector<int> vc[65];
int previ[65];


int getIndex(int a, int b, int c){
    return 16*a + 4*b + c;
}

void generateState(){
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 3; j++){
            for(int k = 0; k <= 3; k++){
                state temp;
                temp.hygiene = 5*i;
                temp.energy = 5*j;
                temp.fun = 5*k;
                playerState[getIndex(i, j, k)] = temp;
            }
        }
    }
}

void generateValidCommand(){
    commandString["tidur siang"] = 1;
    change[1].hygieneChange = 0;
    change[1].energyChange = 10;
    change[1].funChange = 0;
    commandString["tidur malam"] = 2;
    change[2].hygieneChange = 0;
    change[2].energyChange = 15;
    change[2].funChange = 0;
    commandString["makan hamburger"] = 3;
    change[3].hygieneChange = 0;
    change[3].energyChange = 5;
    change[3].funChange = 0;
    commandString["makan pizza"] = 4;
    change[4].hygieneChange = 0;
    change[4].energyChange = 10;
    change[4].funChange = 0;
    commandString["makan steak and beans"] = 5;
    change[5].hygieneChange = 0;
    change[5].energyChange = 15;
    change[5].funChange = 0;
    commandString["minum air"] = 6;
    change[6].hygieneChange = -5;
    change[6].energyChange = 0;
    change[6].funChange = 0;
    commandString["minum kopi"] = 7;
    change[7].hygieneChange = -10;
    change[7].energyChange = 5;
    change[7].funChange = 0;
    commandString["minum jus"] = 8;
    change[8].hygieneChange = -5;
    change[8].energyChange = 10;
    change[8].funChange = 0;
    commandString["buang air kecil"] = 9;
    change[9].hygieneChange = 5;
    change[9].energyChange = 0;
    change[9].funChange = 0;
    commandString["buang air besar"] = 10;
    change[10].hygieneChange = 10;
    change[10].energyChange = -5;
    change[10].funChange = 0;
    commandString["bersosialisasi ke kafe"] = 11;
    change[11].hygieneChange = -5;
    change[11].energyChange = -10;
    change[11].funChange = 15;
    commandString["bermain media sosial"] = 12;
    change[12].hygieneChange = 0;
    change[12].energyChange = -10;
    change[12].funChange = 10;
    commandString["bermain komputer"] = 13;
    change[13].hygieneChange = 0;
    change[13].energyChange = -10;
    change[13].funChange = 15;
    commandString["mandi"] = 14;
    change[14].hygieneChange = 15;
    change[14].energyChange = -5;
    change[14].funChange = 0;
    commandString["cuci tangan"] = 15;
    change[15].hygieneChange = 5;
    change[15].energyChange = 0;
    change[15].funChange = 0;
    commandString["mendengarkan musik di radio"] = 16;
    change[16].hygieneChange = 0;
    change[16].energyChange = -5;
    change[16].funChange = 10;
    commandString["membaca koran"] = 17;
    change[17].hygieneChange = 0;
    change[17].energyChange = -5;
    change[17].funChange = 5;
    commandString["membaca novel"] = 18;
    change[18].hygieneChange = 0;
    change[18].energyChange = -5;
    change[18].funChange = 10;
}

void inverseValidCommand() {
    stringCommand[1] = "tidur siang";
    stringCommand[2] = "tidur malam";
    stringCommand[3] = "makan hamburger";
    stringCommand[4] = "makan pizza";
    stringCommand[5] = "makan steak and beans";
    stringCommand[6] = "minum air";
    stringCommand[7] = "minum kopi";
    stringCommand[8] = "minum jus";
    stringCommand[9] = "buang air kecil";
    stringCommand[10] = "buang air besar";
    stringCommand[11] = "bersosialisasi ke kafe";
    stringCommand[12] = "bermain media sosial";
    stringCommand[13] = "bermain komputer";
    stringCommand[14] = "mandi";
    stringCommand[15] = "cuci tangan";
    stringCommand[16] = "mendengarkan musik di radio";
    stringCommand[17] = "membaca koran";
    stringCommand[18] = "membaca novel";
}

void generatePath(){
    queue<int> q;
    q.push(8);
    vis[8] = 1;
    dist[8] = 0;
    previ[8] = -1;
    while(!q.empty()){
        int fr = q.front();
        state depan = playerState[fr];
        q.pop();
        for(int i = 1; i <= 18; i++){
            int hbaru = depan.hygiene + change[i].hygieneChange;
            int ebaru = depan.energy + change[i].energyChange;
            int fbaru = depan.fun + change[i].funChange;
            if((hbaru >= 0 && hbaru <= 15) && (ebaru >= 0 && ebaru <= 15) && (fbaru >= 0 && fbaru <= 15)){
                int idx = getIndex(hbaru / 5, ebaru / 5, fbaru / 5);
                if(!vis[idx]){
                    vis[idx] = 1;
                    dist[idx] = dist[fr] + 1; 
                    previ[idx] = fr;
                    q.push(idx);
                }
            }
        }
    }
}

void printOptimalPath(int t){
    vector<int> arr;
    while(t != -1){
        arr.push_back(t);
        t = previ[t];
    }
    reverse(arr.begin(), arr.end());
    int vectorSize = arr.size();
    for(int i = 1; i < vectorSize; i++){
        int a = playerState[arr[i]].hygiene - playerState[arr[i - 1]].hygiene;
        int b = playerState[arr[i]].energy - playerState[arr[i - 1]].energy;
        int c = playerState[arr[i]].fun - playerState[arr[i - 1]].fun;
        int ans = -1;

        for(int j = 1; j <= 18; j++){
            if(change[j].hygieneChange == a && change[j].energyChange == b && change[j].funChange == c){
                ans = j;
                break;
            }
        }
        if(i == vectorSize - 1){
            cout << stringCommand[ans] << endl;
        } else {
            cout << stringCommand[ans] << " -> ";
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    generateState();
    generateValidCommand();
    inverseValidCommand();
    generatePath();
    for(int i = 0; i < 64;i++){
        cout << dist[i] << endl;
    }
    cout << "--------------------------------------------------------------" << endl;
    cout << "|                                                            |" << endl;
    cout << "|                                                            |" << endl;
    cout << "|                     The Sims Simulator                     |" << endl;
    cout << "|                          Cheat!!!!                         |" << endl;
    cout << "|                                                            |" << endl;
    cout << "|                                                            |" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "hehehe selamat datang di program kami! disini kami bisa membantu anda menyelesaikan the sims simulator dengan cepat lho!!" << endl;
    cout << "petunjuk: state yang final (15,15,15) adalah state nomor 8, lalu (0,0,0) adalah state nomor 63" << endl;
    cout << "ketik -1 untuk keluar dari program" << endl;
    int t;
    cin >> t;
    if(t >= 0 && t <= 63){
        cout << "jalan paling optimal dari state awal ke state " << t << " adalah: " << endl;
        printOptimalPath(t);
    }
    while(t != -1){
        cin >> t;
        if(t >= 0 && t <= 63){
            cout << "jalan paling optimal dari state awal ke state " << t << " adalah: " << endl;
            printOptimalPath(t);
        }
    } 
    cout << "terima kasih sudah menggunakan program kami!" << endl;
    return 0;
}