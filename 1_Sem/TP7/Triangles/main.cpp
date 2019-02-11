/**

Для некоторого множества заданных координатами своих вершин треугольников найти
треугольник максимальной площади (если максимальную площадь имеют несколько
треугольников, то найти первый из них). Предусмотреть возможность
перемещения треугольников и проверки включения одного треугольника в другой

**/

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

#include "FileLib.h"
#include "Triangle.h"
#include "Point.h"

using namespace std;

const int MAX_STRING_LENGTH = 1024;
//change file paths to yours
const char* INPUT_FINDMAX_FILE = "Downloads/A/tests/findMax/input.txt";
const char* OUTPUT_FINDMAX_FILE = "Downloads/A/tests/findMax/output.txt";
const char* INPUT_INSIDE_FILE = "Downloads/A/tests/inside/input.txt";
const char* OUTPUT_INSIDE_FILE = "Downloads/A/tests/inside/output.txt";

bool readTriangle(Triangle* triangle, ifstream& fin){
    double x1, y1;
    double x2, y2;
    double x3, y3;
    if (fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
        triangle->setV1(*(new Point (x1, y1)));
        triangle->setV2(*(new Point (x2, y2)));
        triangle->setV3(*(new Point (x3, y3)));
        return true;
    } else {
        return false;
    }
}

void readTriangles(Triangle** triangles, int n, ifstream& fin){
    for (int i = 0; i < n; i++){
        readTriangle(triangles[i], fin);
    }
}

int findMaxIndex(Triangle** triangles, int n){
    int iMax = 0;
    double maxSquare = triangles[0]->calculateSquare();
    double currentSquare;
    for (int i = 1; i < n; i++){
        currentSquare = triangles[i]->calculateSquare();
        if (currentSquare > maxSquare){
            maxSquare = currentSquare;
            iMax = i;
        }
    }
    return iMax;
}

void printTriangle(Triangle triangle){
    cout << "Triangle" << endl;
    cout << "v1: " << triangle.getV1().getX() << " " << triangle.getV1().getY() << endl;
    cout << "v2: " << triangle.getV2().getX() << " " << triangle.getV2().getY() << endl;
    cout << "v3: " << triangle.getV3().getX() << " " << triangle.getV3().getY() << endl;
}

void testMove(){
    Triangle triangle;
    triangle.setV1(*(new Point(3, -1.4)));
    triangle.setV2(*(new Point(1, 4)));
    triangle.setV3(*(new Point(-4.1, 8.46)));
    printTriangle(triangle);
    triangle.move(1.5, -1);
    printTriangle(triangle);
}

void testInside(ifstream& fin, ofstream& fout){
    char error[MAX_STRING_LENGTH];

    Triangle* triangle1 = new Triangle();
    Triangle* triangle2 = new Triangle();

    fin.open(INPUT_INSIDE_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_INSIDE_FILE);

        while (readTriangle(triangle1, fin) && readTriangle(triangle2, fin)){
            if (triangle1->isInside(*triangle2)){
                fout << "triangle1 is inside triangle2" << endl;
            } else {
                fout << "triangle1 is NOT inside triangle2" << endl;
            }
        }
    } else {
        cout << error << endl;
    }


    fin.close();
    fout.close();
}

void testFindMax(ifstream& fin, ofstream& fout){
    char error[MAX_STRING_LENGTH];

    int n;
    int iMax;
    Triangle** triangles;

    fin.open(INPUT_FINDMAX_FILE);

    if(validateFile(fin, error)){
        fout.open(OUTPUT_FINDMAX_FILE);

        while (fin >> n){
            triangles = new Triangle*[n];
            for (int i = 0; i < n; i++){
                triangles[i] = new Triangle();
            }
            readTriangles(triangles, n, fin);
            iMax = findMaxIndex(triangles, n);

            fout << iMax << endl;
        }
    } else {
        cout << error << endl;
    }


    fin.close();
    fout.close();
}

int main()
{
    ifstream fin;
    ofstream fout;

    testFindMax(fin, fout);
    testInside(fin, fout);
    //testMove();
    return 0;

}
