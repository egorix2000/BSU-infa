/**
Двумерная матрица задает высоты соседствующих клеток местности. Переход
возможен в соседние клетки по горизонтали или по вертикали, если высота
соседа меньше (как стекает вода).

Определить все клетки, в которые можно попасть из заданной.
Определить самую удаленную клетку, в которую можно попасть из заданной.
Найти путь для подзадачи 2.

Выводятся 2 матрицы

Матрица нулей и единиц, где
1 - квадрат местности в который можно попасть из заданного
0 - квадрат местности в который нельзя попасть из заданного

Матрица нулей и единиц, где
единицами обозначается путь до самой удаленной клетки

input

4
1 6 1 0
4 5 0 -2
5 4 0 -1
4 3 1 0
1 1

output

1 0 0 0
1 1 1 1
0 1 1 1
0 1 1 1

0 0 0 0
0 1 0 0
0 1 0 0
0 1 1 1

-----------------------------------------

input

3
1 1 1
1 1 1
1 1 1
1 1

output

0 0 0
0 1 0
0 0 0

0 0 0
0 1 0
0 0 0

-----------------------------------------

input

20
 59 15 19 81 11 73 76  4 95  1 76 36 13 88 48 61 40 22 45 66
  5 73 85 26 53 19 22  2 68 83 70 23 97 57 57 20 97  6 61 49
 45 35 91 73 43 12 37  3 29 96 78 20 28 68 38 72 72 33 57 44
 66 25 84 78 52 77 48 62 72 50 12 75 40 51 97 72 51 74 75 85
 32 95 55  6 39 43 97 44 75 60  8 66 59 72 53 44 35 27 25 63
 72 49 66 47 95  0 11 21 59 45  3  4 37 36 12 86 30 89 60  9
 74 70 27 73 38 17  1 58 73 78  3 91  4 32 91 55 35 29 13 22
 76 21 14 57 67 45 62 46 83 43 33 77 76 16 50 54  7 31 80 26
 94  3 91 99 13 72 88 61 99 84 24 74 84 90 29 59 94 48 84 84
 11 51 53  0 30 39 93 43 86 26 57 33 58 80 78 54 80 59 84 93
 89 75 86 43 82 57 55 69 71 96 81 65 32 18 36 18 36 68 65 63
 57 33 53 55 96 31 58 93 38 13 12 69 28 98 16 22 41 91 82 18
 20 74 94 35 40 66 14 39 35 36 37 64 41 91 79 33  4 76  3 72
 99 17 72 32 40 53 50 13 71 73 33 94 50 90 99 48 86  1 11 26
 16 10 93 65  1 40 91 61 70 76 78 66 60 62 39 24 75 31 94 70
 61 42 52 77 34 92 17 97 27 54  0 53 90 68 77 60 52 51 20 63
 85 46 98 68 96 30  6 79 92 14 78  9 36 40 79  8 11 50 89 13
 36 55 72 42 42 51 45 48 21 30 57 49 87 95 33 15 79 50  2 23
 83 42 88 27 74 35 93 61  0  7 86  4 46 42 69 41 98 60 70 66
 84 18 29 27 28 70 45 10 55 63 93  3 79 33 75 38 87  8 43 94
8 16

output

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0


**/


#include <iostream>
#include <queue>
#include "TwoDimensionalArrayLib.h"

using namespace std;

struct square{
    int x;
    int y;
};

square findAllSquaresToGo(int **heightMap, int n, bool **whereWeCanGo, square start, square **ancestors){
    queue<square> squares;
    square mostDistant = {start.x, start.y};
    square next;
    square current;
    squares.push(start);

    while (!squares.empty()){
        current.x = squares.front().x;
        current.y = squares.front().y;
        if (current.x < n-1 && !whereWeCanGo[current.x+1][current.y] && heightMap[current.x+1][current.y] < heightMap[current.x][current.y]){
            next.x = current.x + 1;
            next.y = current.y;
            ancestors[next.x][next.y] = current;
            squares.push(next);
        }
        if (current.x > 0 && !whereWeCanGo[current.x-1][current.y] && heightMap[current.x-1][current.y] < heightMap[current.x][current.y]){
            next.x = current.x - 1;
            next.y = current.y;
            ancestors[next.x][next.y] = current;
            squares.push(next);
        }
        if (current.y < n-1 && !whereWeCanGo[current.x][current.y+1] && heightMap[current.x][current.y+1] < heightMap[current.x][current.y]){
            next.x = current.x;
            next.y = current.y + 1;
            ancestors[next.x][next.y] = current;
            squares.push(next);
        }
        if (current.y > 0 && !whereWeCanGo[current.x][current.y-1] && heightMap[current.x][current.y-1] < heightMap[current.x][current.y]){
            next.x = current.x;
            next.y = current.y - 1;
            ancestors[next.x][next.y] = current;
            squares.push(next);
        }
        whereWeCanGo[current.x][current.y] = true;
        if (abs(start.x - current.x) + abs(start.y - current.y) > abs(start.x - mostDistant.x) + abs(start.y - mostDistant.y)){
            mostDistant = current;
        }
        squares.pop();
    }
    return mostDistant;
}

void findRoute(bool **whereWeCanGo, square **ancestors, int n, square start, square mostDistant, bool **longestSquareRoute){
    square current = mostDistant;

    while(current.x != start.x || current.y != start.y){
        longestSquareRoute[current.x][current.y] = true;
        current = ancestors[current.x][current.y];
    }
    longestSquareRoute[current.x][current.y] = true;
}

int main()
{
    int n;
    square start;
    square mostDistant;
    int **heightMap;
    bool **whereWeCanGo;
    bool **longestSquareRoute;
    square **ancestors;

    cout << "Enter map size" << endl;
    cin >> n;

    heightMap = new int*[n];
    whereWeCanGo = new bool*[n];
    longestSquareRoute = new bool*[n];
    ancestors = new square*[n];
    for (int t = 0; t < n; t++){
        heightMap[t] = new int[n];
        whereWeCanGo[t] = new bool[n];
        ancestors[t] = new square[n];
        longestSquareRoute[t] = new bool[n];
        for (int i = 0; i < n; i++){
            whereWeCanGo[t][i] = false;
            longestSquareRoute[t][i] = false;
        }
    }

    cout << "Enter map" << endl;
    enterTwoDimensionalArray(heightMap, n);

    //if you want to generate maps
    /*cout << "Generated map" << endl;
    fillRandomTwoDimensionalArray(heightMap, n);
    printFormattedTwoDimensionalArray(heightMap, n, 3);*/

    cout << "Enter start square coordinates" << endl;
    cin >> start.x >> start.y;

    mostDistant = findAllSquaresToGo(heightMap, n, whereWeCanGo, start, ancestors);
    printTwoDimensionalBooleanArray(whereWeCanGo, n);

    cout << endl;

    findRoute(whereWeCanGo, ancestors, n, start, mostDistant, longestSquareRoute);
    printTwoDimensionalBooleanArray(longestSquareRoute, n);
    return 0;
}
