/**

В двумерном массиве размером n x n записано количество очков,
набранных той или иной командой во встречах с другими командами
(3 – если данная команда выиграла игру, 0 – если проиграла, 1 – если игра закончилась вничью).
Определить:
а) сколько очков набрала команда, ставшая чемпионом,
б) номер команды, занявшей последнее место.

**/

#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include "TwoDimensionalArrayLib.h"
#include "OneDimensionalArrayLib.h"
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;

int main()
{
    //change file paths to yours
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];
    int nTests;
    int maxPoints;
    int minPoints;
    int lastTeam;
    int n;
    int* teams;
    int** a;

    fin.open("Downloads/A/tests/tournament/input.txt");

    if(validateFile(fin, error)){
        fout.open("Downloads/A/tests/tournament/output.txt");

        fin >> nTests;

        for (int i = 0; i < nTests; i++){
            fin >> n;
            maxPoints = 0;
            minPoints = 3*n;
            teams = new int[n];
            a = new int*[n];
            for (int i = 0; i < n; i++){
                a[i] = new int[n];
            }

            enterTwoDimensionalArrayFromFile(a, n, n, fin);
            for (int i = 0; i < n; i++){
                teams[i] = sumInRow(a, n, i);
                if (teams[i] > maxPoints){
                    maxPoints = teams[i];
                }
                if (teams[i] < minPoints){
                    minPoints = teams[i];
                    lastTeam = i;
                }
            }

            fout << maxPoints << " " << lastTeam << endl;
        }
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
