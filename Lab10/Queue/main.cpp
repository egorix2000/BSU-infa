/**

Пусть даны две очереди X и Y, содержащие целые числа. Из каждой очереди
одновременно извлекается по одному числу x и y соответственно. Если
x<y, то число (x + y) помещается в конец очереди X, иначе число
(x – y) помещается в конец очереди Y. Необходимо определить
число шагов, через которые одна из очередей станет пустой.

**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

#include "Queue.h"
#include "FileLib.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;
//change file paths to yours
const char* INPUT_FILE = "Downloads/A/tests/input.txt";
const char* OUTPUT_FILE = "Downloads/A/tests/output.txt";

int findWhichWillBecomeEmptyFirst(Queue<int>& q1, Queue<int>& q2){
    int x;
    int y;
    while(!q1.isEmpty() && !q2.isEmpty()){
        cout << "do";
        x = q1.getFront();
        y = q2.getFront();
        q1.pop_front();
        q2.pop_front();
        if (x < y){
            q1.push_back(x + y);
        } else {
            q2.push_back(x - y);
        }
    }
    cout << endl;
    if (q1.isEmpty()){
        return 1;
    } else{
        return 2;
    }
}

int main()
{
    ifstream fin;
    ofstream fout;
    char error[MAX_STRING_LENGTH];

    int n;
    int m;
    int x;
    int ans;
    Queue<int> q1;
    Queue<int> q2;

    fin.open(INPUT_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FILE);

        while (fin >> n >> m){
            q1.reset();
            q2.reset();
            for (int i = 0; i < n; i++){
                fin >> x;
                q1.push_back(x);
            }
            for (int i = 0; i < m; i++){
                fin >> x;
                q2.push_back(x);
            }
            ans = findWhichWillBecomeEmptyFirst(q1, q2);
            if (ans == 1){
                fout << "q1" << endl;
            } else{
                fout << "q2" << endl;
            }
        }
    } else {
        cout << error << endl;
    }

    fin.close();
    fout.close();
    return 0;

}
