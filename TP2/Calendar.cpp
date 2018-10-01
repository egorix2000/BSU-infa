/*2.	В восточном календаре принят 60 - летний цикл, состоящий из 12 - летних подциклов,
обозначаемых названиями цвета : зеленый, красный, желтый, белый и черный.В каждом подцикле
годы носят названия животных : крысы, быка, тигра, кролика, дракона, змеи, лошади, козы,
обезьяны, петуха, собаки и свиньи.По номеру года вывести его название, если 1984 год был
нача¬лом цикла— годом зеленой крысы.



Egor Bychenok

input				output
--------------------------------------------
1984                green rat
2010                white tiger
1900                while rat

*/

#include <iostream>

using namespace std;


//void main()
int main()
{
    int year;
    int color;
    int animal;
    cout << "enter year" << endl;
    cin >> year;
    color = year%10;
    animal = year%12;

    switch(color){
        case 0:
        case 1:
        {
            cout << "white ";
            break;
        }
        case 2:
        case 3:
        {
            cout << "black ";
            break;
        }
        case 4:
        case 5:
        {
            cout << "green ";
            break;
        }
        case 6:
        case 7:
        {
            cout << "red ";
            break;
        }
        case 8:
        case 9:
        {
            cout << "yellow ";
            break;
        }
    }

    switch(animal){
        case 0:
        {
            cout << "monkey" << endl;
            break;
        }
        case 1:
        {
            cout << "rooster" << endl;
            break;
        }
        case 2:
        {
            cout << "dog" << endl;
            break;
        }
        case 3:
        {
            cout << "pig" << endl;
            break;
        }
        case 4:
        {
            cout << "rat" << endl;
            break;
        }
        case 5:
        {
            cout << "bull" << endl;
            break;
        }
        case 6:
        {
            cout << "tiger" << endl;
            break;
        }
        case 7:
        {
            cout << "rabbit" << endl;
            break;
        }
        case 8:
        {
            cout << "dragon" << endl;
            break;
        }
        case 9:
        {
            cout << "snake" << endl;
            break;
        }
        case 10:
        {
            cout << "horse" << endl;
            break;
        }
        case 11:
        {
            cout << "goat" << endl;
            break;
        }
    }
    return 0;
	//system("pause");
}
