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

state playerState[65];

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

int getNextState(string cmd, int * player, int current){

}

int main() {
    generateState();
    c
    return 0;
}