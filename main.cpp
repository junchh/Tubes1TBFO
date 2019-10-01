/**
** The Sims Simulator (Tugas Besar Teori Bahasa Formal & Automata)
** 
** @kelompok: cisitu0427
** @anggota : - 13518044 / Jun Ho Choi Hedyatmo
**            - 13518149 / Stefanus Gusega Gunawan
** @kelas   : IF2124 K-02
**/
#include <bits/stdc++.h>
#include <string>
#include <stdlib.h>

using namespace std;

/**
 * state merupakan struktur data yang dibuat untuk menggambarkan state yang mengandung tiga nilai: hygiene, energy, dan fun
 */
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
map<string, int> commandString;
transition change[19];
string stringCommand[19];


int getIndex(int a, int b, int c){
    //generate index dengan basis 4
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
    commandString["Tidur Siang"] = 1;
    change[1].hygieneChange = 0;
    change[1].energyChange = 10;
    change[1].funChange = 0;
    commandString["Tidur Malam"] = 2;
    change[2].hygieneChange = 0;
    change[2].energyChange = 15;
    change[2].funChange = 0;
    commandString["Makan Hamburger"] = 3;
    change[3].hygieneChange = 0;
    change[3].energyChange = 5;
    change[3].funChange = 0;
    commandString["Makan Pizza"] = 4;
    change[4].hygieneChange = 0;
    change[4].energyChange = 10;
    change[4].funChange = 0;
    commandString["Makan Steak and Beans"] = 5;
    change[5].hygieneChange = 0;
    change[5].energyChange = 15;
    change[5].funChange = 0;
    commandString["Minum Air"] = 6;
    change[6].hygieneChange = -5;
    change[6].energyChange = 0;
    change[6].funChange = 0;
    commandString["Minum Kopi"] = 7;
    change[7].hygieneChange = -10;
    change[7].energyChange = 5;
    change[7].funChange = 0;
    commandString["Minum Jus"] = 8;
    change[8].hygieneChange = -5;
    change[8].energyChange = 10;
    change[8].funChange = 0;
    commandString["Buang Air Kecil"] = 9;
    change[9].hygieneChange = 5;
    change[9].energyChange = 0;
    change[9].funChange = 0;
    commandString["Buang Air Besar"] = 10;
    change[10].hygieneChange = 10;
    change[10].energyChange = -5;
    change[10].funChange = 0;
    commandString["Bersosialisasi ke Kafe"] = 11;
    change[11].hygieneChange = -5;
    change[11].energyChange = -10;
    change[11].funChange = 15;
    commandString["Bermain Media Sosial"] = 12;
    change[12].hygieneChange = 0;
    change[12].energyChange = -10;
    change[12].funChange = 10;
    commandString["Bermain komputer"] = 13;
    change[13].hygieneChange = 0;
    change[13].energyChange = -10;
    change[13].funChange = 15;
    commandString["Mandi"] = 14;
    change[14].hygieneChange = 15;
    change[14].energyChange = -5;
    change[14].funChange = 0;
    commandString["Cuci Tangan"] = 15;
    change[15].hygieneChange = 5;
    change[15].energyChange = 0;
    change[15].funChange = 0;
    commandString["Mendengarkan Musik di Radio"] = 16;
    change[16].hygieneChange = 0;
    change[16].energyChange = -5;
    change[16].funChange = 10;
    commandString["Membaca Koran"] = 17;
    change[17].hygieneChange = 0;
    change[17].energyChange = -5;
    change[17].funChange = 5;
    commandString["Membaca Novel"] = 18;
    change[18].hygieneChange = 0;
    change[18].energyChange = -5;
    change[18].funChange = 10;
}

void inverseValidCommand () {
    stringCommand[1] = "Tidur Siang";
    stringCommand[2] = "Tidur Malam";
    stringCommand[3] = "Makan Hamburger";
    stringCommand[4] = "Makan Pizza";
    stringCommand[5] = "Makan Steak and Beans";
    stringCommand[6] = "Minum Air";
    stringCommand[7] = "Minum Kopi";
    stringCommand[8] = "Minum Jus";
    stringCommand[9] = "Buang Air Kecil";
    stringCommand[10] = "Buang Air Besar";
    stringCommand[11] = "Bersosialisasi ke Kafe";
    stringCommand[12] = "Bermain Media Sosial";
    stringCommand[13] = "Bermain Komputer";
    stringCommand[14] = "Mandi";
    stringCommand[15] = "Cuci Tangan";
    stringCommand[16] = "Mendengarkan Musik di Radio";
    stringCommand[17] = "Membaca Koran";
    stringCommand[18] = "Membaca Novel";
}

bool isActionValid(state current, transition x){
    int a = current.hygiene + x.hygieneChange;
    int b = current.energy + x.energyChange;
    int c = current.fun + x.funChange;
    return (a >= 0 && a <= 15) && (b >= 0 && b <= 15) && (c >= 0 && c <= 15);
}

void showStatus(state player){
    cout << "Hygiene = " << player.hygiene << endl;
    cout << "Energy = " << player.energy << endl;
    cout << "Fun = " << player.fun << endl;
}

void doTransition(state * player, transition x){
    if(isActionValid(*player, x)){
        (*player).hygiene += x.hygieneChange;
        (*player).energy += x.energyChange;
        (*player).fun += x.funChange;
        showStatus(*player);
    } else {
        cout << "Aksi tidak valid" << endl;
        showStatus(*player);
    }
}

int getCurrentState(state player){
    int a = player.hygiene / 5;
    int b = player.energy / 5;
    int c = player.fun / 5;
    return getIndex(a, b, c);
}


bool IsStateEqual (state player, state player1) {
    return (player.energy == player1.energy && player.fun == player1.fun && player.hygiene == player1.hygiene);
}

bool IsFinalState (state player) {
    return (IsStateEqual(player, playerState[0]) || IsStateEqual(player,playerState[63]));
}


int main() {
    state player;
    string str,nama;
    generateState();
    generateValidCommand();
    inverseValidCommand();
    system("CLS");
    cout << "Selamat datang di The Sims Simulator. Pertama-tama, siapa namamu?" << endl;
    cout << "Nama : ";
    getline(cin,nama);
    system("CLS");
    cout << "Halo, selamat datang " << nama << "!" << endl;
    /*for (int i = 0;i<=63;i++) {
        cout << "q" << i << " " << playerState[i].hygiene << " " << playerState[i].energy << " " << playerState[i].fun << endl ;
    }*/
    /*cout << "State";
    for(int i = 1; i <= 18; i++){
        cout << "," << i;
    } 
    cout << endl;
    for(int i = 0; i <= 63; i++){
        cout << "q" << i;
        for(int j = 1; j <= 18; j++){
            if(isActionValid(playerState[i], change[j])){
                int hbaru = playerState[i].hygiene + change[j].hygieneChange;
                int ebaru = playerState[i].energy + change[j].energyChange;
                int fbaru = playerState[i].fun + change[j].funChange;
                cout << ",q" << getIndex(hbaru / 5, ebaru / 5, fbaru / 5);
            } else {
                cout << ",q" << i;
            }
        }
        cout << endl;
    }*/
    player.hygiene = 0;
    player.energy = 10;
    player.fun = 0;
    showStatus(player);
    cout << "Ah, enaknya habis bangun tidur. Enaknya ngapain ya?" << endl;
    while (!IsFinalState(player)) {
        cout << "Masukkan aksi : ";
        getline(cin, str);
        doTransition(&player, change[commandString[str]]);
    }
    if (IsStateEqual(player,playerState[0])) {
        cout << "Mati jir" << endl;
    }
    else if (IsStateEqual(player,playerState[63])) {
        cout << "Masuk surga, gan!" << endl;
    }
    return 0;
}