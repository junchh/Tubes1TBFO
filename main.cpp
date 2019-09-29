/**
** The Sims Simulator (Tugas Besar Teori Bahasa Formal & Automata)
** 
** @kelompok: cisitu0427
** @anggota : - 13518044 / Jun Ho Choi Hedyatmo
**            - 13518149 / Stefanus Gusega Gunawan
** @kelas   : IF2124 K-02
**/
#include <bits/stdc++.h>

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


int getIndex(int a, int b, int c){
    //generate index dengan basis 4
    return 16*a+4*b+c;
}

void generateState(){
    for(int i=0;i<=3;i++){
        for(int j=0;j<=3;j++){
            for(int k=0;k<=3;k++){
                state temp;
                temp.hygiene = 5*i;
                temp.energy = 5*j;
                temp.fun = 5*k;
                playerState[getIndex(i, j, k)]=temp;
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

int getNextState(string cmd, int * player, int current){

}

int main() {
    generateState();
    
    return 0;
}