
////В игре 2 кубика и на каждом из них может выпасть от 1 до 6 очков.
//Реализовать определение программой первого ходящего.
//Каждый делает по четыре броска.
//После бросков показать, нарисованные символами кубики и количество очков, выпавших на них.
//После  пары бросков(бросок компьютера + бросок пользователя) выводить на экран промежуточный результат  
// – количество набранных очков игроком и компьютером.
//В конце сообщить о том, кто выиграл по итогам всех бросков.


#include<iostream>
#include <ctime>

using namespace std;

bool whofirst();//Выбор первого ходящего

int throwcube();//Броски кубиков
void drowcube(int cube);


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	int playerscore = 0; // для записи очков игрока

	int pcscore = 0;// для записи очков комп

	char var;//Нарисовать кубики

	if (whofirst())
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "ходишь ты" << endl;
			cout << "нажми любую букву, чтобы бросить кубики: ";
			cin >> var;
			
			cout << "бросаем..." << endl;

			playerscore += throwcube();

			cout << endl;

			cout << "ходит компьютер" << endl;
			cout << "бросаем..." << endl;

			pcscore += throwcube();

			cout << endl;

			if (j != 3)
			{
				cout << "твой промежуточный результат = " << playerscore << endl;
				cout << "у компьютера = " << pcscore << endl << endl;
			}
		}

	}

	else
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "ходит компьютер" << endl;
			cout << "бросаем..." << endl;

			pcscore += throwcube();
			

			cout << endl;

			cout << "ходишь ты" << endl;
			cout << "нажми y, чтобы бросить кубики: ";
			cin >> var;
			cout << "бросаем..." << endl;

			playerscore += throwcube();

			cout << endl;

			if (j != 3)
			{
				cout << "твой промежуточный результат = " << playerscore << endl;
				cout << "у компьютера = " << pcscore << endl << endl;
			}
		}
	}

	cout << "итого у тебя: " << playerscore << endl;
	cout << "итого у компьютера: " << pcscore << endl;

	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	if (pcscore > playerscore) cout << "ты проиграл, неудачник " << endl;
	if (playerscore > pcscore) cout << "победа за тобой! " << endl;
	if (playerscore == pcscore) cout << "ничья " << endl;
}

//Выбор первого ходящего
bool whofirst()
	{

		int whofirst = rand() % +2;

		return whofirst;
	}

//Броски кубиков
int throwcube()
{
	    int cube1 = 0, cube2 = 0;

		int minscore = 1;
		int maxscore = 6;

		cube1 = minscore + rand() % (maxscore - minscore + 1);
		cube2 = minscore + rand() % (maxscore - minscore + 1);

		drowcube(cube1);
		cout << "на 1ом кубике выпало " << cube1 << endl;

		drowcube(cube2);
		cout << "на 2ом кубике выпало " << cube2 << endl;

		return cube1 + cube2;
}

//Нарисовать кубики
void drowcube(int cube)
{
		switch (cube)
		{
		case 1: 
			cout << "@@@@@" << endl;
			cout << "@@ @@" << endl;
			cout << "@@@@@" << endl;
			
			break;
		case 2:
			cout << "@ @@@" << endl;
			cout << "@@@@@" << endl;
			cout << "@@@ @" << endl;

			break;
		case 3:
			cout << "@ @@@" << endl;
			cout << "@@ @@" << endl;
			cout << "@@@ @" << endl;

			break;
		case 4:
			cout << "@ @ @" << endl;
			cout << "@@ @@" << endl;
			cout << "@@@ @" << endl;

			break;
		case 5:
			cout << "@ @ @" << endl;
			cout << "@@ @@" << endl;
			cout << "@ @ @" << endl;

			break;
		case 6:
			cout << "@ @ @" << endl;
			cout << " @ @@" << endl;
			cout << "@ @ @" << endl;

			break;

		default:
			break;
		}
}