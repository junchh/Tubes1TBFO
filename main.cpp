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
    commandString["Makan Hamburger"] = 3;
    commandString["Makan Pizza"] = 4;
    commandString["Makan Steak and Beans"] = 5;
    commandString["Minum Air"] = 6;
    commandString["Minum Kopi"] = 7;
    commandString["Minum Jus"] = 8;
    commandString["Buang Air Kecil"] = 9;
    commandString["Buang Air Besar"] = 10;
    commandString["Bersosialisasi ke Kafe"] = 11;
    commandString["Bermain Media Sosial"] = 12;
    commandString["Bermain komputer"] = 13;
    commandString["Mandi"] = 14;
    commandString["Cuci Tangan"] = 15;
    commandString["Mendengarkan Musik di Radio"] = 16;
    commandString["Membaca Koran"] = 17;
    commandString["Membaca Novel"] = 18;
}

int getNextState(string cmd, int * player, int current){

}

int main() {
    generateState();
    
    return 0;
}