#include <iostream>
#include <string>
#include<windows.h>
#include<fstream>
using namespace std;
//създавам структура student със следните параметри:
struct student {
	//данни за студента
	string specialnost;
	string ime;
	string faknomer;
	int godina;
	int mesec;
	//оценки по мат бп физическо уеб и електроника , както и среден успех
	double mat;
	double bp;
	double fiz;
	double web;
	double el;
	double srus;






};//прототипи на функциите, които използам
//фунцкия за избор на номер от менюто
int entry();
//въвеждане на 1 студент
void enterOneStudent(int& i, int& k, student studSIT[], student studKST[]);
//въвеждане на произволен брой студенти
void enterManyStudents(int& i, int& k, student studSIT[], student studKST[]);
//извеждане на студенти по въведена специалност
void output(int i, int k, student studSIT[], student studKST[]);
//извеждане на студенти със отличен по БП
void outputWith6poBP(int i, int k, student studSIT[], student studKST[]);
//извеждане на студенти, подредени по възраст
void outputpovuzrast(int i, int k, student studSIT[], student studKST[]);
//извеждане на най-добрия студент от КСТ И СИТ
void outputNaiDoburStudent(int i, int k, student studSIT[], student studKST[]);
//фунцкия за вкарване на данните от програмата във файл
void save(int i, int k, student studSIT[], student studKST[]);
//фунцкция за вкарване на данните от файла в програмта
void fromFile(int& i, int& k, student studSIT[], student studKST[]);
//извеждане на студенти с уraспех над 5.50
void outputUspehNad5i50(int i, int k, student studSIT[], student studKST[]);
//извеждане на студенти, подредени по успех
void outputpouspeh(int i, int k, student studSIT[], student studKST[]);
//създаване на отделните групи от дадена специалност
void razpredelenieVGrupa(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int& grupiSIT, int& grupiKST);
//размяна на групите на 2 студента, след въвеждане на фак. номера
void razmqnaNaGrupi(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[]);
//извеждане на студентите по групи
void grupiOutput(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int grupiSIT, int grupiKST);
//изтриване на студент от група след въвеждането на фак. номер
void iztrivaneNaStudent(int& i, int& k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int grupiSIT, int grupiKST);
void savebinary(int i, int k, student studSIT[], student studKST[]);

int main() {
	setlocale(LC_ALL, "Bulgarian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	//променлива за броя студенти въведени от спец. СИТ
	int i = 0;
	//променлива за броя студенти въведени от спец. КСТ
	int k = 0;
	//променлива за колко групи са създадени от СИТ
	int grupiSIT = 0;
	//променлива за колко групи са създадени от СИТ
	int grupiKST = 0;
	//масиви от структурата student
	//първите два са за отделните групи - може да има макс. 5 студента в група и макс 30/5=6 групи.
	student SIT[6][5];
	student KST[6][5];
	//вторите служат за пазене на данните за всички студенти от двете специалности (макс 30)
	student studSIT[30];
	student studKST[30];
	//нулирам всички полета от масивите от структурата с тип double и int,  защото default стойностите им не са 0
	for (int y = 0; y < 30; y++) {

		studSIT[y].godina = 0;
		studSIT[y].mesec = 0;
		studSIT[y].mat = 0.0;
		studSIT[y].bp = 0.0;
		studSIT[y].fiz = 0.0;
		studSIT[y].web = 0.0;
		studSIT[y].el = 0.0;
		studSIT[y].srus = 0.0;
		studKST[y].godina = 0;
		studKST[y].mesec = 0;
		studKST[y].mat = 0.0;
		studKST[y].bp = 0.0;
		studKST[y].fiz = 0.0;
		studKST[y].web = 0.0;
		studKST[y].el = 0.0;
		studKST[y].srus = 0.0;
	}

	for (int y1 = 0; y1 < 6; y1++) {
		for (int y = 0; y < 5; y++) {
			SIT[y1][y].godina = 0;
			SIT[y1][y].mesec = 0;
			SIT[y1][y].mat = 0.0;
			SIT[y1][y].bp = 0.0;
			SIT[y1][y].fiz = 0.0;
			SIT[y1][y].web = 0.0;
			SIT[y1][y].el = 0.0;
			SIT[y1][y].srus = 0.0;
			KST[y1][y].godina = 0;
			KST[y1][y].mesec = 0;
			KST[y1][y].mat = 0.0;
			KST[y1][y].bp = 0.0;
			KST[y1][y].fiz = 0.0;
			KST[y1][y].web = 0.0;
			KST[y1][y].el = 0.0;
			KST[y1][y].srus = 0.0;
		}
	}

	//правя така, че менюто да се изкарва винаги след стартиране на програмата, както и след като дадено действие е завършило изпълнението си.
	while (true) {
		cout << endl;
		cout << "Въведете:" << endl;
		cout << "1 за добавяне на един студент." << endl;
		cout << "2 за добавяне на n на брой студенти." << endl;
		cout << "3 за извеждане на студенти от дадена специалност." << endl;
		cout << "4 за извеждане на студенти с Отличен по БП." << endl;
		cout << "5 за създаване на групите от студенти." << endl;
		cout << "За опции 6,7 и 8 първо създайте групите чрез опция 5" << endl;
		cout << "6 за размяна на групите на двама студенти." << endl;
		cout << "7 за изтриване на студент" << endl;
		cout << "8 за извеждане на студентите по групи." << endl;
		cout << "9 за извеждане на студентите, подредени по среден успех." << endl;
		cout << "10 за извеждане на студентите, подредени по възраст в месеци." << endl;
		cout << "11 за извеждане на студентите с най-добър среден успех от КСТ и СИТ." << endl;
		cout << "12 за извеждане на студентите с успех над 5.50." << endl;
		cout << "13 за запазване на данните във файл." << endl;
		cout << "14 за вкарване на данните от файла в програмата " << endl;
		cout << "15 за излизане от програмата." << endl;
		//записвам въведеното число в променлива
		int entered = entry();
		//ако е равно на 15 програмата спира
		if (entered == 15) {
			break;
		}
		//ако е друго число викам функцията, която съответсвта на съотвеното число
		switch (entered) {
		case 1:enterOneStudent(i, k, studSIT, studKST);
			break;
		case 2:enterManyStudents(i, k, studSIT, studKST); break;
		case 3: output(i, k, studSIT, studKST); break;
		case 4:outputWith6poBP(i, k, studSIT, studKST); break;
		case 5:razpredelenieVGrupa(i, k, SIT, KST, studSIT, studKST, grupiSIT, grupiKST); break;
		case 6: razmqnaNaGrupi(i, k, SIT, KST, studSIT, studKST); break;
		case 7:iztrivaneNaStudent(i, k, SIT, KST, studSIT, studKST, grupiSIT, grupiKST); break;
		case 8:grupiOutput(i, k, SIT, KST, studSIT, studKST, grupiSIT, grupiKST); break;
		case 9: outputpouspeh(i, k, studSIT, studKST); break;
		case 10:outputpovuzrast(i, k, studSIT, studKST); break;
		case 11:outputNaiDoburStudent(i, k, studSIT, studKST);  break;
		case 12:outputUspehNad5i50(i, k, studSIT, studKST); break;
		case 13:save(i, k, studSIT, studKST); savebinary(i, k, studSIT, studKST); break;
		case 14:fromFile(i, k, studSIT, studKST); break;


		}

	}








	return 0;
}
//изтриване на студент от група- вкарвам във ф-ята i и k по локация, за да може като ги променям да се променят стойностите им в цялата програма, а не само копията им
//вкарвам масивите от структура за групите и за всички студенти, както и броя групи които са запълнение за двете специалности
void iztrivaneNaStudent(int& i, int& k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int grupiSIT, int grupiKST) {
	string spec;
	//въвежда се специалност, от която ще се трие
	cout << "Въведете специалност, от която ще изтривате студент: " << endl;
	cin >> spec;
	if (spec == "СИТ") {

		cout << "Въведете фак. номер на студента: " << endl;
		string fakn;
		cin >> fakn;
		//декларирам две променливи, които показват индексите на двумерния масив
		int index1 = -1;
		int index2 = -1;
		//проверявам за всички студенти от всички групи дали някой има същия фак. номер и като го намеря спирам цикъла
		for (int y1 = 0; y1 < grupiSIT; y1++) {
			for (int y = 0; y < 5; y++) {
				if (SIT[y1][y].faknomer == fakn) {
					index1 = y1;
					index2 = y;
					y1 = grupiSIT;
					break;
				}
			}
		}

		//ако е намерен, index1 вече няма да е -1, а ще е >=0
		if (index1 >= 0) {
			//трия студента, като записвам във всеки студент след него, включително и него, следващия студент по ред ( така изтрития студент се заличава и всички останали се преместват с позиция наляво)

			for (int y = index2; y <= 4; y++) {
				if (y < 4) {
					SIT[index1][y] = SIT[index1][y + 1];

				}

				if (y == 4) {
					SIT[index1][4].specialnost = "";
					SIT[index1][4].ime = "";
					SIT[index1][4].faknomer = "";
					SIT[index1][4].godina = 0;
					SIT[index1][4].mesec = 0;
					SIT[index1][4].mat = 0;
					SIT[index1][4].bp = 0;
					SIT[index1][4].fiz = 0;
					SIT[index1][4].web = 0;
					SIT[index1][4].el = 0;

				}



			}


			//понеже след като студент се изтрие от група, той трябва да се изтрие и от целия поток, за да бъдат правилно създадени групите
			int index = -1;
			for (int y = 0; y < i; y++) {
				if (studSIT[y].faknomer == fakn) {
					index = y;
					break;
				}
			}
			//правя същото като с групите
			for (int y = index; y <= i - 1; y++) {
				if (y == 29) {
					studSIT[y].specialnost = "";
					studSIT[y].ime = "";
					studSIT[y].faknomer = "";
					studSIT[y].godina = 0;
					studSIT[y].mesec = 0;
					studSIT[y].mat = 0;
					studSIT[y].bp = 0;
					studSIT[y].fiz = 0;
					studSIT[y].web = 0;
					studSIT[y].el = 0;
				}
				else {
					studSIT[y] = studSIT[y + 1];

				}

			}
			//свалям броя на студентите в потока с 1
			i--;

			if (SIT[index1][4].mesec == 0 && SIT[index1][3].mesec == 0) {
				for (int y1 = 0; y1 < 6; y1++) {
					for (int y = 0; y < 5; y++) {
						SIT[y1][y].godina = 0;
						SIT[y1][y].mesec = 0;
						SIT[y1][y].mat = 0.0;
						SIT[y1][y].bp = 0.0;
						SIT[y1][y].fiz = 0.0;
						SIT[y1][y].web = 0.0;
						SIT[y1][y].el = 0.0;
						SIT[y1][y].srus = 0.0;

					}
				}



				razpredelenieVGrupa(i, k, SIT, KST, studSIT, studKST, grupiSIT, grupiKST);
			}

		}







		else {
			cout << "Моля въведете 7 отново и след това въведете ВАЛИДЕН фак.номер." << endl;


		}









	}


	//същото правя и за специалност КСТ
	else if (spec == "КСТ") {

		cout << "Въведете фак. номер на студента: " << endl;
		string fakn;
		cin >> fakn;
		//декларирам две променливи, които показват индексите на двумерния масив
		int index1 = -1;
		int index2 = -1;
		//проверявам за всички студенти от всички групи дали някой има същия фак. номер и като го намеря спирам цикъла
		for (int y1 = 0; y1 < grupiKST; y1++) {
			for (int y = 0; y < 5; y++) {
				if (KST[y1][y].faknomer == fakn) {
					index1 = y1;
					index2 = y;
					y1 = grupiKST;
					break;
				}
			}
		}

		//ако е намерен, index1 вече няма да е -1, а ще е >=0
		if (index1 >= 0) {
			//трия студента, като записвам във всеки студент след него, включително и него, следващия студент по ред ( така изтрития студент се заличава и всички останали се преместват с позиция наляво)

			for (int y = index2; y <= 4; y++) {
				if (y < 4) {
					KST[index1][y].specialnost = KST[index1][y + 1].specialnost;
					KST[index1][y].ime = KST[index1][y + 1].ime;
					KST[index1][y].faknomer = KST[index1][y + 1].faknomer;
					KST[index1][y].godina = KST[index1][y + 1].godina;
					KST[index1][y].mesec = KST[index1][y + 1].mesec;
					KST[index1][y].mat = KST[index1][y + 1].mat;
					KST[index1][y].bp = KST[index1][y + 1].bp;
					KST[index1][y].fiz = KST[index1][y + 1].fiz;
					KST[index1][y].web = KST[index1][y + 1].web;
					KST[index1][y].el = KST[index1][y + 1].el;
				}

				if (y == 4) {
					KST[index1][4].specialnost = "";
					KST[index1][4].ime = "";
					KST[index1][4].faknomer = "";
					KST[index1][4].godina = 0;
					KST[index1][4].mesec = 0;
					KST[index1][4].mat = 0;
					KST[index1][4].bp = 0;
					KST[index1][4].fiz = 0;
					KST[index1][4].web = 0;
					KST[index1][4].el = 0;

				}



			}


			//понеже след като студент се изтрие от група, той трябва да се изтрие и от целия поток, за да бъдат правилно създадени групите
			int index = -1;
			for (int y = 0; y < k; y++) {
				if (studKST[y].faknomer == fakn) {
					index = y;
					break;
				}
			}
			//правя същото като с групите
			for (int y = index; y <= k - 1; y++) {
				if (y == 29) {
					studSIT[y].specialnost = "";
					studSIT[y].ime = "";
					studSIT[y].faknomer = "";
					studSIT[y].godina = 0;
					studSIT[y].mesec = 0;
					studSIT[y].mat = 0;
					studSIT[y].bp = 0;
					studSIT[y].fiz = 0;
					studSIT[y].web = 0;
					studSIT[y].el = 0;
				}
				else {
					studKST[y].specialnost = studKST[y + 1].specialnost;
					studKST[y].ime = studKST[y + 1].ime;
					studKST[y].faknomer = studKST[y + 1].faknomer;
					studKST[y].godina = studKST[y + 1].godina;
					studKST[y].mesec = studKST[y + 1].mesec;
					studKST[y].mat = studKST[y + 1].mat;
					studKST[y].bp = studKST[y + 1].bp;
					studKST[y].fiz = studKST[y + 1].fiz;
					studKST[y].web = studKST[y + 1].web;
					studKST[y].el = studKST[y + 1].el;
				}

			}
			//свалям броя на студентите в потока с 1
			k--;

			if (KST[index1][4].mesec == 0 && KST[index1][3].mesec == 0) {
				for (int y1 = 0; y1 < 6; y1++) {
					for (int y = 0; y < 5; y++) {
						KST[y1][y].godina = 0;
						KST[y1][y].mesec = 0;
						KST[y1][y].mat = 0.0;
						KST[y1][y].bp = 0.0;
						KST[y1][y].fiz = 0.0;
						KST[y1][y].web = 0.0;
						KST[y1][y].el = 0.0;
						KST[y1][y].srus = 0.0;

					}
				}



				razpredelenieVGrupa(i, k, SIT, KST, studSIT, studKST, grupiSIT, grupiKST);
			}


		}

		else {
			cout << "Моля въведете 7 отново и след това въведете ВАЛИДЕН фак.номер." << endl;


		}

	}
	//ако не е въведен нито КСТ, нито СИТ  изписва това съобщение
	else {
		cout << "Моля въведете 7 отново и след това въведете ВАЛИДНА  специалност." << endl;


	}

	//викам функцията за разпределение в група, за да може да се разпределят студентите в групите по павилата в условието








}


//извеждане на студентите по групи
void grupiOutput(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int grupiSIT, int grupiKST) {
	//ако има студенти от СИТ

	if (i > 0) {
		cout << "Специалност СИТ: " << endl;
		//цикъл въртящ групите
		for (int y1 = 0; y1 < grupiSIT; y1++) {
			//извежда се номера на групата
			cout << "Група " << y1 + 1 << endl;
			cout << endl;
			//цикъл въртящ студентите в дадена група
			for (int y = 0; y < 5; y++) {
				//понеже полетата на студентите са нулирани, ако студента на съществува, то за съществуващ студент полето за месец със сигурност няма да е 0
				//затова извеждам само студентите, на които не им е 0 полето за месеца
				//извеждам студентите поле по поле
				if (SIT[y1][y].mesec != 0) {
					cout << "Студент " << y + 1 << endl;
					cout << "Специалност:";
					cout << SIT[y1][y].specialnost << endl;
					cout << "Име и фамилия:";
					cout << SIT[y1][y].ime << endl;
					cout << "Факултетен номер:";
					cout << SIT[y1][y].faknomer << endl;
					cout << "Месец и година на раждане (формат месец.година):";
					cout << SIT[y1][y].mesec << "." << SIT[y1][y].godina << endl;
					cout << "Оценка по математика:";
					cout << SIT[y1][y].mat << endl;
					cout << "Оценка по БП:";
					cout << SIT[y1][y].bp << endl;
					cout << "Оценка по физическо:";
					cout << SIT[y1][y].fiz << endl;
					cout << "Оценка по УЕБ:";
					cout << SIT[y1][y].web << endl;
					cout << "Оценка по електроника:";
					cout << SIT[y1][y].el << endl;
					cout << endl;



				}
			}


		}
	}

	//същото правя за КСТ
	if (k > 0) {
		cout << "Специалност КСТ: " << endl;

		for (int y1 = 0; y1 < grupiKST; y1++) {
			cout << "Група " << y1 + 1 << endl;
			cout << endl;
			for (int y = 0; y < 5; y++) {
				if (KST[y1][y].mesec != 0) {
					cout << "Студент " << y + 1 << endl;
					cout << "Специалност:";
					cout << KST[y1][y].specialnost << endl;
					cout << "Име и фамилия:";
					cout << KST[y1][y].ime << endl;
					cout << "Факултетен номер:";
					cout << KST[y1][y].faknomer << endl;
					cout << "Месец и година на раждане (формат месец.година):";
					cout << KST[y1][y].mesec << "." << KST[y1][y].godina << endl;
					cout << "Оценка по математика:";
					cout << KST[y1][y].mat << endl;
					cout << "Оценка по БП:";
					cout << KST[y1][y].bp << endl;
					cout << "Оценка по физическо:";
					cout << KST[y1][y].fiz << endl;
					cout << "Оценка по УЕБ:";
					cout << KST[y1][y].web << endl;
					cout << "Оценка по електроника:";
					cout << KST[y1][y].el << endl;
					cout << endl;



				}
			}


		}

	}
}
//размяна на групите на двама студенти по въведени фак. номера
void razmqnaNaGrupi(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[]) {

	string purvi, vtori, spec;
	student help;
	//понеже може да се сменят групите само на студенти от една и суща специалност, първо тя се въвежда
	cout << "Въведете от коя специалност са студентите: ";
	cin >> spec;

	cout << "Въведете фак. номер на първи студент: ";
	//въвеждам двата факултетни номера
	cin >> purvi;
	cout << "Въведете фак. номер на втори студент: ";
	cin >> vtori;
	//декларирам двата индекса на двата студента
	int indexpurvi1 = -1;
	int indexpurvi2 = -1;
	int indexvtori1 = -1;
	int indexvtori2 = -1;
	//ако въведената специалност е СИТ
	if (spec == "СИТ") {


		//проверява се всеки студент от всяка група
		for (int y1 = 0; y1 < 6; y1++) {
			for (int y = 0; y < 5; y++) {
				//ако се стигне до студент, чийто фак. номер е същия като въведените
				//индексите му се записват в горезаписаните променливи
				if (SIT[y1][y].faknomer == purvi) {
					indexpurvi1 = y1;
					indexpurvi2 = y;


				}

				if (SIT[y1][y].faknomer == vtori) {
					indexvtori1 = y1;
					indexvtori2 = y;


				}

				//ако и двата индексите и на двата студента са най-малко 0 , то значи, че и за двата въведени факултетни номера е намерен студент и се спира търсенето
				if (indexpurvi1 >= 0 && indexvtori1 >= 0) {
					y1 = 6;
					break;
				}



			}
		}
		//ако за намерени студенти за двата факултетни номера
		if (indexpurvi1 >= 0 && indexvtori1 >= 0) {
			//разменяме данните на двата студента в масивите на групите чрез помощни променливи
			help = SIT[indexpurvi1][indexpurvi2];



			SIT[indexpurvi1][indexpurvi2] = SIT[indexvtori1][indexvtori2];



			SIT[indexvtori1][indexvtori2] = help;




			//декларирам две променливи, в които ще записвам индексите на студентите в целия поток
			int index1 = -1;
			int index2 = -1;
			//правя същото търсене за целия поток на СИТ
			for (int y = 0; y < i; y++) {
				if (studSIT[y].faknomer == purvi) {
					index1 = y;
				}
				if (studSIT[y].faknomer == vtori) {
					index2 = y;
				}
				if (index1 >= 0 && index2 >= 0) {

					break;
				}
			}
			//слагам данните на втория студент в полетата на първия
			studSIT[index1] = studSIT[index2];


			//вече няма нужда да правя помощни променливи, защото те вече са направени по-горе
			studSIT[index2] = help;




			cout << "Студентите са разменени успешно" << endl;
		}

		//ако един или два от факултетните номера, които са въведени не съществуват в масивите, се извежда следното съобщение
		else {
			cout << "Моля въведете 6 отново ,след което въведете ВАЛИДНИ факултетни номера" << endl;


		}






	}



	//същото правя и за спец КСТ
	else if (spec == "КСТ") {



		for (int y1 = 0; y1 < 6; y1++) {
			for (int y = 0; y < 5; y++) {
				if (KST[y1][y].faknomer == purvi) {
					indexpurvi1 = y1;
					indexpurvi2 = y;


				}

				if (KST[y1][y].faknomer == vtori) {
					indexvtori1 = y1;
					indexvtori2 = y;


				}


				if (indexpurvi1 >= 0 && indexvtori1 >= 0) {
					y1 = 6;
					break;
				}



			}
		}

		if (indexpurvi1 >= 0 && indexvtori1 >= 0) {
			student help = KST[indexpurvi1][indexpurvi2];



			KST[indexpurvi1][indexpurvi2] = KST[indexvtori1][indexvtori2];



			KST[indexvtori1][indexvtori2] = help;






			int index1 = -1;
			int index2 = -1;

			for (int y = 0; y < i; y++) {
				if (studKST[y].faknomer == purvi) {
					index1 = y;
				}
				if (studKST[y].faknomer == vtori) {
					index2 = y;
				}
				if (index1 >= 0 && index2 >= 0) {
					break;
				}
			}

			studKST[index1] = studKST[index2];


			studKST[index2] = help;

			cout << "Студентите са разменени успешно" << endl;

		}


		else {

			cout << "Моля въведете 6 отново ,след което въведете ВАЛИДНИ факултетни номера" << endl;


		}






	}



	else {
		cout << "Моля въведете 6 отново и след това въведете ВАЛИДНА специалност" << endl;
	}







}


//функция за разпределение на студентите в група
void razpredelenieVGrupa(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int& grupiSIT, int& grupiKST) {

	cout << "Групите бяха създадени успешно." << endl;
	//променлива, която показва колко студенти остават да се разпреелят в групи
	int left = i;

	//първо разпределям студентите от СИТ
	//ако те са по-малко от 6
	if (i <= 5) {
		//групите ще са 1
		grupiSIT = 1;
		//въртя цикил, които се завърта броя на студентите пъти и записвам в групата поред студентите от целия поток
		for (int y = 0; y < i; y++) {

			SIT[0][y] = studSIT[y];


		}


	}
	//ако студентите са 6 или 7
	else if (i > 5 && i < 8) {
		//групите са 2
		grupiSIT = 2;
		//първата група ще има 3ма студенти и ги записвам поред от потока
		for (int y = 0; y < 3; y++) {

			SIT[0][y] = studSIT[y];


		}
		//декларирам променлива, която продължава обхождането на студентите от целия поток от мястото където е стигнал горния цикъл
		int br3 = 2;
		//в зависимост дали са 6 или 7, то студентите във втората група ще са 3 или 4
		for (int y = 0; y < i - 3; y++) {
			br3++;

			SIT[1][y] = studSIT[br3];


		}



	}
	//правя проверка ако студентите са точно 11, защото е изключение и само тогава ще има 3 групи и в едната ще има само 3 студента
	if (i == 11) {
		grupiSIT = 3;
		int br3 = -1;
		//запълвам групите
		for (int y1 = 0; y1 < 3; y1++) {
			for (int y = 0; y < 4; y++) {
				br3++;
				if (y1 == 2 && y == 3) {
					break;
				}

				SIT[y1][y] = studSIT[br3];



			}

		}





	}

	//когато студентите са межу 7 и 27
	else if (i > 7 && i <= 27 && i != 11) {
		//групите са толкова, защото ги запълвам минимум с 4 човека
		grupiSIT = i / 4;
		int br3 = -1;
		for (int y1 = 0; y1 < grupiSIT + 1; y1++) {

			//докато хората които са останали да се вкарат в група са повече от 3, се запълва текущата група с 4 студента и се преминава към следващата
			if (left >= 4) {
				left -= 4;

				for (int y = 0; y < 4; y++) {
					br3++;

					SIT[y1][y] = studSIT[br3];


				}


			}

			//ако са останали по-малко от 4, но все още има студенти за вкарваме в група
			else if (left > 0) {
				//правя цикъл, който запълва групите от по 4ма студенти с 5-ти
				for (int y1 = 0; y1 < left; y1++) {
					br3++;

					SIT[y1][4] = studSIT[br3];

				}

			}

		}



	}
	//ако студентите са над 27
	else if (i >= 28 && i <= 30) {
		//групите задължително вече са 6
		grupiSIT = 6;
		//записвам разликата на броя на студентите и 27 в променлива
		int ostatuk = i - 27;
		int br3 = -1;
		//всяка група я запълвам със по 4 студента и след изпълнението на този цикъл са въведени 24 студента в гурпите
		for (int y1 = 0; y1 < grupiSIT; y1++) {




			for (int y = 0; y < 4; y++) {
				br3++;

				SIT[y1][y] = studSIT[br3];

			}


		}

		//3+остатъка представлява броя на студентите които остава да се въведат
		//затова този цикъл запълва 3+остатък от 6-те функции с 5ти студент
		for (int y1 = 0; y1 < 3 + ostatuk; y1++) {
			br3++;

			SIT[y1][4] = studSIT[br3];




		}



	}
	//същото правя и за специалност КСТ
	int leftKST = k;


	if (k <= 5) {
		grupiKST = 1;
		for (int y = 0; y < k; y++) {

			KST[0][y] = studKST[y];

		}


	}

	else if (k > 5 && k < 8) {
		grupiKST = 2;
		for (int y = 0; y < 3; y++) {

			KST[0][y] = studKST[y];


		}
		int br3 = 2;
		for (int y = 0; y < k - 3; y++) {
			br3++;

			KST[1][y] = studKST[br3];


		}



	}

	if (k == 11) {
		grupiKST = 3;
		int br3 = -1;
		for (int y1 = 0; y1 < 3; y1++) {
			for (int y = 0; y < 4; y++) {
				br3++;
				if (y1 == 2 && y == 3) {
					break;
				}

				KST[y1][y] = studKST[br3];


			}

		}





	}


	else if (k > 7 && k <= 27 && k != 11) {
		grupiKST = k / 4;
		int br3 = -1;
		for (int y1 = 0; y1 < grupiKST + 1; y1++) {


			if (leftKST >= 4) {
				leftKST -= 4;

				for (int y = 0; y < 4; y++) {
					br3++;

					KST[y1][y] = studKST[br3];

				}


			}

			else if (leftKST > 0) {
				for (int y1 = 0; y1 < leftKST; y1++) {
					br3++;

					KST[y1][4] = studKST[br3];


				}

			}

		}



	}
	else if (k >= 28 && k <= 30) {
		grupiKST = 6;
		int ostatuk = k - 27;
		int br3 = -1;
		for (int y1 = 0; y1 < grupiKST; y1++) {




			for (int y = 0; y < 4; y++) {
				br3++;

				KST[y1][y] = studKST[br3];

			}


		}


		for (int y1 = 0; y1 < 3 + ostatuk; y1++) {
			br3++;

			KST[y1][4] = studKST[br3];




		}



	}




}


//фунцкия за извеждането на студентите от двете специалности по успех
void outputpouspeh(int i, int k, student studSIT[], student studKST[]) {
	//декларирам масив, в който ще събера всички студенти от двата потока
	student studobshto[60];
	student help;
	boolean flag = true;
	//записвам всички студенти от СИТ и КСТ в новия масив
	for (int y = 0; y < i; y++) {

		studobshto[y] = studSIT[y];

		//записвам и среден успех
		studobshto[y].srus = (studSIT[y].bp + studSIT[y].mat + studSIT[y].fiz + studSIT[y].el + studSIT[y].web) / 5.0;
	}
	int br3 = 0;
	for (int y = i; y < i + k; y++) {

		studobshto[y] = studKST[br3];

		studobshto[y].srus = (studKST[br3].bp + studKST[br3].mat + studKST[br3].fiz + studKST[br3].el + studKST[br3].web) / 5.0;
		br3++;
	}
	//с метода на балончето сортирам всички студенти от новия масив
	for (int br1 = i + k; br1 > 1; br1--) {
		if (!flag) {
			break;
		}
		flag = false;
		for (int br2 = 0; br2 < i + k - 1; br2++) {

			if (studobshto[br2].srus < studobshto[br2 + 1].srus) {
				help = studobshto[br2];


				studobshto[br2] = studobshto[br2 + 1];


				studobshto[br2 + 1] = help;

				flag = true;

			}
		}

	}




	//извеждам студент по студент
	for (int y = 0; y < i + k; y++) {

		cout << "Специалност:";
		cout << studobshto[y].specialnost << endl;
		cout << "Име и фамилия:";
		cout << studobshto[y].ime << endl;
		cout << "Среден успех:";
		cout << studobshto[y].srus << endl;
		cout << "Факултетен номер:";
		cout << studobshto[y].faknomer << endl;
		cout << "Месец и година на раждане (формат месец.година):";
		cout << studobshto[y].mesec << "." << studobshto[y].godina << endl;
		cout << "Оценка по математика:";
		cout << studobshto[y].mat << endl;
		cout << "Оценка по БП:";
		cout << studobshto[y].bp << endl;
		cout << "Оценка по физическо:";
		cout << studobshto[y].fiz << endl;
		cout << "Оценка по УЕБ:";
		cout << studobshto[y].web << endl;
		cout << "Оценка по електроника:";
		cout << studobshto[y].el << endl;
		cout << endl;
	}














}






//функция за извеждане само на студентите с отличен среден успех

void outputUspehNad5i50(int i, int k, student studSIT[], student studKST[]) {

	//за всеки студент (в случая за спец. СИТ) се  намира средния успех и ако е над 5.499 ( за да не стане проблем с double), той се извежда
	for (int y = 0; y < i; y++) {
		double current = (studSIT[y].bp + studSIT[y].mat + studSIT[y].fiz + studSIT[y].el + studSIT[y].web) / 5.0;
		if (current > 5.499) {
			cout << "Специалност:";
			cout << studSIT[y].specialnost << endl;
			cout << "Име и фамилия:";
			cout << studSIT[y].ime << endl;
			cout << "Среден успех:";
			cout << current << endl;
			cout << "Факултетен номер:";
			cout << studSIT[y].faknomer << endl;
			cout << "Месец и година на раждане (формат месец.година):";
			cout << studSIT[y].mesec << "." << studSIT[y].godina << endl;
			cout << "Оценка по математика:";
			cout << studSIT[y].mat << endl;
			cout << "Оценка по БП:";
			cout << studSIT[y].bp << endl;
			cout << "Оценка по физическо:";
			cout << studSIT[y].fiz << endl;
			cout << "Оценка по УЕБ:";
			cout << studSIT[y].web << endl;
			cout << "Оценка по електроника:";
			cout << studSIT[y].el << endl;
			cout << endl;

		}
	}

	//същото се случва и за КСТ
	for (int y = 0; y < k; y++) {
		double current = (studKST[y].bp + studKST[y].mat + studKST[y].fiz + studKST[y].el + studKST[y].web) / 5.0;
		if (current >= 5.499) {
			cout << "Специалност:";
			cout << studKST[y].specialnost << endl;
			cout << "Име и фамилия:";
			cout << studKST[y].ime << endl;
			cout << "Среден успех:";
			cout << current << endl;
			cout << "Факултетен номер:";
			cout << studKST[y].faknomer << endl;
			cout << "Месец и година на раждане (формат месец.година):";
			cout << studKST[y].mesec << "." << studKST[y].godina << endl;
			cout << "Оценка по математика:";
			cout << studKST[y].mat << endl;
			cout << "Оценка по БП:";
			cout << studKST[y].bp << endl;
			cout << "Оценка по физическо:";
			cout << studKST[y].fiz << endl;
			cout << "Оценка по УЕБ:";
			cout << studKST[y].web << endl;
			cout << "Оценка по електроника:";
			cout << studKST[y].el << endl;
			cout << endl;

		}








	}
}







//фунцкия за вкарване на данните от файла в програмата
void fromFile(int& i, int& k, student studSIT[], student studKST[]) {
	fstream f;

	f.open("FailSDanni.txt", ios::out | ios::in | ios::app);
	//ако файлът е празен влиза в следния if
	if (f.peek() == ifstream::traits_type::eof()) {
		cout << "Файлът е празен." << endl;
	}
	//ако не е празен, ред по ред се вкарват данните от файла в масивите на двете специалности
	else {
		cout << "Данните бяха прехвърлени успешно." << endl;

		f >> i;
		f >> k;
		int brsit = 0;
		int brkst = 0;

		for (int y = 0; y < i + k; y++) {
			string c = "";
			f >> c;
			if (c == "СИТ") {
				studSIT[brsit].specialnost = "СИТ";
				f.ignore();
				getline(f, studSIT[brsit].ime);
				f >> studSIT[brsit].faknomer;
				f >> studSIT[brsit].godina;
				f >> studSIT[brsit].mesec;
				f >> studSIT[brsit].mat;
				f >> studSIT[brsit].bp;
				f >> studSIT[brsit].fiz;
				f >> studSIT[brsit].web;
				f >> studSIT[brsit].el;
				brsit++;
			}



			if (c == "КСТ") {
				studKST[brkst].specialnost = "КСТ";
				f.ignore();
				getline(f, studKST[brkst].ime);
				f >> studKST[brkst].faknomer;
				f >> studKST[brkst].godina;
				f >> studKST[brkst].mesec;
				f >> studKST[brkst].mat;
				f >> studKST[brkst].bp;
				f >> studKST[brkst].fiz;
				f >> studKST[brkst].web;
				f >> studKST[brkst].el;
				brkst++;
			}

		}








	}

}




//функция за изкарване на информацията от програмата във файл
void save(int i, int k, student studSIT[], student studKST[]) {
	cout << "Файлът беше записан успешно." << endl;
	cout << endl;
	fstream f;
	//когато се прави това , данните от вече записан файл се изтриват
	f.open("FailSDanni.txt", std::ofstream::out | std::ofstream::trunc);
	f.close();
	f.open("FailSDanni.txt", ios::out | ios::in | ios::app);

	f << i << endl;

	f << k << endl;
	for (int y = 0; y < i; y++) {
		f << studSIT[y].specialnost << endl;
		f << studSIT[y].ime << endl;
		f << studSIT[y].faknomer << endl;
		f << studSIT[y].godina << endl;
		f << studSIT[y].mesec << endl;
		f << studSIT[y].mat << endl;
		f << studSIT[y].bp << endl;
		f << studSIT[y].fiz << endl;
		f << studSIT[y].web << endl;
		f << studSIT[y].el << endl;





	}



	for (int y = 0; y < k; y++) {


		f << studKST[y].specialnost << endl;
		f << studKST[y].ime << endl;
		f << studKST[y].faknomer << endl;
		f << studKST[y].godina << endl;
		f << studKST[y].mesec << endl;
		f << studKST[y].mat << endl;
		f << studKST[y].bp << endl;
		f << studKST[y].fiz << endl;
		f << studKST[y].web << endl;
		f << studKST[y].el << endl;


	}







}


void savebinary(int i, int k, student studSIT[], student studKST[]) {
	cout << "Двуичният файл беше записан успешно." << endl;
	cout << endl;
	fstream f;
	//когато се прави това , данните от вече записан файл се изтриват
	f.open("dvuich.txt", ios::out | ios::trunc);
	f.close();
	f.open("dvuich.txt", ios::binary | ios::out);


	f.write((char*)&i, sizeof(int));

	f.write((char*)&k, sizeof(int));
	for (int y = 0; y < i; y++) {
		int siz = studSIT[y].specialnost.length();
		f.write((char*)&studSIT[y].specialnost, siz);

		f.write((char*)&studSIT[y].ime, siz);

		siz = studSIT[y].faknomer.length();
		f.write((char*)&studSIT[y].faknomer, siz);
		f.write((char*)&studSIT[y].godina, sizeof(int));

		f.write((char*)&studSIT[y].mesec, sizeof(int));

		f.write((char*)&studSIT[y].mat, sizeof(double));

		f.write((char*)&studSIT[y].bp, sizeof(double));

		f.write((char*)&studSIT[y].fiz, sizeof(double));

		f.write((char*)&studSIT[y].web, sizeof(double));

		f.write((char*)&studSIT[y].el, sizeof(double));





	}



	for (int y = 0; y < k; y++) {

		int siz = studKST[y].specialnost.length();
		f.write((char*)&studKST[y].specialnost, siz);

		f.write((char*)&studKST[y].ime, siz);

		siz = studKST[y].faknomer.length();
		f.write((char*)&studKST[y].faknomer, siz);
		f.write((char*)&studKST[y].godina, sizeof(int));

		f.write((char*)&studKST[y].mesec, sizeof(int));

		f.write((char*)&studKST[y].mat, sizeof(double));

		f.write((char*)&studKST[y].bp, sizeof(double));

		f.write((char*)&studKST[y].fiz, sizeof(double));

		f.write((char*)&studKST[y].web, sizeof(double));

		f.write((char*)&studKST[y].el, sizeof(double));


	}







}
//извеждане на най-добрите студенти от СИТ и КСТ
void outputNaiDoburStudent(int i, int k, student studSIT[], student studKST[]) {
	double maxSIT = 0;
	double maxKST = 0;
	//намирам максималния среден успех
	for (int y = 0; y < i; y++) {
		double current = (studSIT[y].bp + studSIT[y].mat + studSIT[y].fiz + studSIT[y].el + studSIT[y].web) / 5;
		if (current > maxSIT) {
			maxSIT = current;

		}

	}
	//обхождам всички студенти от потока и ако средния успех им е равен на максималния се извеждат( ако има няколко човека с еднакъв успех, всеки един от тях се извежда)
	for (int y = 0; y < i; y++) {
		double current = (studSIT[y].bp + studSIT[y].mat + studSIT[y].fiz + studSIT[y].el + studSIT[y].web) / 5;
		if (current == maxSIT) {
			cout << "Специалност:";
			cout << studSIT[y].specialnost << endl;
			cout << "Име и фамилия:";
			cout << studSIT[y].ime << endl;
			cout << "Среден успех:";
			cout << current << endl;
			cout << "Факултетен номер:";
			cout << studSIT[y].faknomer << endl;
			cout << "Месец и година на раждане (формат месец.година):";
			cout << studSIT[y].mesec << "." << studSIT[y].godina << endl;
			cout << "Оценка по математика:";
			cout << studSIT[y].mat << endl;
			cout << "Оценка по БП:";
			cout << studSIT[y].bp << endl;
			cout << "Оценка по физическо:";
			cout << studSIT[y].fiz << endl;
			cout << "Оценка по УЕБ:";
			cout << studSIT[y].web << endl;
			cout << "Оценка по електроника:";
			cout << studSIT[y].el << endl;
			cout << endl;

		}

	}


	//същото правя и за КСТ

	for (int y = 0; y < k; y++) {
		double current = (studKST[y].bp + studKST[y].mat + studKST[y].fiz + studKST[y].el + studKST[y].web) / 5;
		if (current > maxKST) {
			maxKST = current;

		}

	}


	for (int y = 0; y < k; y++) {
		double current = (studKST[y].bp + studKST[y].mat + studKST[y].fiz + studKST[y].el + studKST[y].web) / 5;
		if (current == maxKST) {

			cout << "Специалност:";
			cout << studKST[y].specialnost << endl;
			cout << "Име и фамилия:";
			cout << studKST[y].ime << endl;
			cout << "Среден успех:";
			cout << current << endl;
			cout << "Факултетен номер:";
			cout << studKST[y].faknomer << endl;
			cout << "Месец и година на раждане (формат месец.година):";
			cout << studKST[y].mesec << "." << studKST[y].godina << endl;
			cout << "Оценка по математика:";
			cout << studKST[y].mat << endl;
			cout << "Оценка по БП:";
			cout << studKST[y].bp << endl;
			cout << "Оценка по физическо:";
			cout << studKST[y].fiz << endl;
			cout << "Оценка по УЕБ:";
			cout << studKST[y].web << endl;
			cout << "Оценка по електроника:";
			cout << studKST[y].el << endl;
			cout << endl;

		}

	}







}

//извеждане на студенти подредени по възраст
void outputpovuzrast(int i, int k, student studSIT[], student studKST[]) {
	//правя общ масив, в който слагам всички студенти от двата потока
	student studobshto[60];
	student help;
	boolean flag = true;

	for (int y = 0; y < i; y++) {

		studobshto[y] = studSIT[y];

	}
	int br3 = 0;
	for (int y = i; y < i + k; y++) {

		studobshto[y] = studKST[br3];

		br3++;
	}
	//по метода на мехурчето сортирам студентите първо по месеци
	for (int br1 = i + k; br1 > 1; br1--) {
		if (!flag) {
			break;
		}
		flag = false;
		for (int br2 = 0; br2 < i + k - 1; br2++) {
			if (studobshto[br2].mesec > studobshto[br2 + 1].mesec) {
				help = studobshto[br2];


				studobshto[br2] = studobshto[br2 + 1];


				studobshto[br2 + 1] = help;
				flag = true;


			}
		}

	}
	//след това ги сортирам по години и тъй като вече са сортирани по месеци първоначално, то сортировката е приключена успешно
	flag = true;
	for (int br1 = i + k; br1 > 1; br1--) {
		if (!flag) {
			break;
		}
		flag = false;
		for (int br2 = 0; br2 < i + k - 1; br2++) {
			if (studobshto[br2].godina > studobshto[br2 + 1].godina) {
				help = studobshto[br2];


				studobshto[br2] = studobshto[br2 + 1];


				studobshto[br2 + 1] = help;
				flag = true;

			}
		}

	}
	//извеждам студентите
	for (int y = 0; y < i + k; y++) {

		cout << "Специалност:";
		cout << studobshto[y].specialnost << endl;
		cout << "Име и фамилия:";
		cout << studobshto[y].ime << endl;
		cout << "Факултетен номер:";
		cout << studobshto[y].faknomer << endl;
		cout << "Месец и година на раждане (формат месец.година):";
		cout << studobshto[y].mesec << "." << studobshto[y].godina << endl;
		cout << "Оценка по математика:";
		cout << studobshto[y].mat << endl;
		cout << "Оценка по БП:";
		cout << studobshto[y].bp << endl;
		cout << "Оценка по физическо:";
		cout << studobshto[y].fiz << endl;
		cout << "Оценка по УЕБ:";
		cout << studobshto[y].web << endl;
		cout << "Оценка по електроника:";
		cout << studobshto[y].el << endl;
		cout << endl;
	}


}
//const int PI 3.14
//#define PI 3.14
//#define служи компилаторът да замени препратките към съответната константа с определената стойност(3.14) по време на компилиране.
//cout<<hex<<10;








//извеждане на студентите с отличен по БП
void outputWith6poBP(int i, int k, student studSIT[], student studKST[]) {

	//проверявам за всеки студент дали оценката му е >=5.499 и ако да, го извеждам
	for (int y = 0; y < i; y++) {
		if (studSIT[y].bp >= 5.499) {

			cout << "Специалност:";
			cout << studSIT[y].specialnost << endl;
			cout << "Име и фамилия:";
			cout << studSIT[y].ime << endl;
			cout << "Факултетен номер:";
			cout << studSIT[y].faknomer << endl;
			cout << "Месец и година на раждане (формат месец.година):";
			cout << studSIT[y].mesec << "." << studSIT[y].godina << endl;
			cout << "Оценка по математика:";
			cout << studSIT[y].mat << endl;
			cout << "Оценка по БП:";
			cout << studSIT[y].bp << endl;
			cout << "Оценка по физическо:";
			cout << studSIT[y].fiz << endl;
			cout << "Оценка по УЕБ:";
			cout << studSIT[y].web << endl;
			cout << "Оценка по електроника:";
			cout << studSIT[y].el << endl;
			cout << endl;
		}

	}


	//същото правя и за КСТ
	for (int y = 0; y < k; y++) {
		if (studKST[y].bp >= 5.499) {
			cout << "Специалност:";
			cout << studKST[y].specialnost << endl;
			cout << "Име и фамилия:";
			cout << studKST[y].ime << endl;
			cout << "Факултетен номер:";
			cout << studKST[y].faknomer << endl;
			cout << "Месец и година на раждане (формат месец.година):";
			cout << studKST[y].mesec << "." << studSIT[y].godina << endl;
			cout << "Оценка по математика:";
			cout << studKST[y].mat << endl;
			cout << "Оценка по БП:";
			cout << studKST[y].bp << endl;
			cout << "Оценка по физическо:";
			cout << studKST[y].fiz << endl;
			cout << "Оценка по УЕБ:";
			cout << studKST[y].web << endl;
			cout << "Оценка по електроника:";
			cout << studKST[y].el << endl;
			cout << endl;
		}
	}

}
//въвеждане на n на брой студенти
void enterManyStudents(int& i, int& k, student studSIT[], student studKST[]) {
	cout << "Въведете брой студенти, които искате да въведете:";
	int n;
	//въвежда се броя на студентите
	cin >> n;

	//цикъла се върти n пъти
	for (int br = 1; br <= n; br++) {

		cout << "Студент " << br << endl;
		cout << "Въведете специалност на студента (СИТ или КСТ)(Въведете 0 ако искате да се спре въвеждането на студенти) : " << endl;
		string s;

		cin >> s;
		//ако вместо специалност се въведе 0 , въвеждането се прекратява
		if (s == "0") {
			cout << "Прекратихте въвеждането на студенти." << endl;
			break;
		}
		//ако въведената специалност е СИТ:
		else if (s == "СИТ") {
			//понеже може да има максимално 30 ученици, ако се иска да се въведе 31 отиваме във else
			if (i < 30) {

				//се въвеждат и останалите полета и студента се записва в потока на СИТ
				studSIT[i].specialnost = s;
				cin.ignore();
				cout << "Въведете име и фамилия: ";
				getline(cin, studSIT[i].ime);
				cout << "Въведете факултетен номер:";
				cin >> studSIT[i].faknomer;
				cout << "Въведете година на раждане:";
				cin >> studSIT[i].godina;
				cout << "Въведете месец на раждане с цифри (например за януари въведете 1, за февруари 2 и т.н.) :";
				cin >> studSIT[i].mesec;
				cout << "Въведете оценка по математика: ";
				cin >> studSIT[i].mat;
				cout << "Въведете оценка по БП: ";
				cin >> studSIT[i].bp;
				cout << "Въведете оценка по физическо: ";
				cin >> studSIT[i].fiz;
				cout << "Въведете оценка по УЕБ: ";
				cin >> studSIT[i].web;
				cout << "Въведете оценка по електроника: ";
				cin >> studSIT[i].el;
				i++;
			}
			//ако се опитваме да въведем 31 ученик се изкарва следното:
			else {
				cout << "Специалност СИТ вече има 30 ученици." << endl;

			}
		}
		//същото и за КСТ
		else if (s == "КСТ") {
			if (k < 30) {


				studKST[k].specialnost = s;
				cin.ignore();
				cout << "Въведете име и фамилия:";
				getline(cin, studKST[k].ime);
				cout << "Въведете факултетен номер:";
				cin >> studKST[k].faknomer;
				cout << "Въведете година на раждане:";
				cin >> studKST[k].godina;
				cout << "Въведете месец на раждане с цифри (например за януари въведете 1, за февруари 2 и т.н.) :";
				cin >> studKST[k].mesec;
				cout << "Въведете оценка по математика: ";
				cin >> studKST[k].mat;
				cout << "Въведете оценка по БП: ";
				cin >> studKST[k].bp;
				cout << "Въведете оценка по физическо: ";
				cin >> studKST[k].fiz;
				cout << "Въведете оценка по УЕБ: ";
				cin >> studKST[k].web;
				cout << "Въведете оценка по електроника: ";
				cin >> studKST[k].el;
				k++;
			}
			else {
				cout << "Специалност КСТ вече има 30 ученици." << endl;
			}

		}
		//ако въведена специалност не е КСТ нито СИТ , нито е е прекратено въвеждането се извежда следното съобщение и брояча на цикъла се връща с 1
		else {
			cout << "Въведете валидна специалност." << endl;
			cout << endl;
			br--;
		}



	}

}

//извеждане на студенти от въведена специалност
void output(int i, int k, student studSIT[], student studKST[]) {
	cout << "Въведете за коя специалност искате да изведете студентите (СИТ или КСТ): " << endl;
	string s;
	cin >> s;


	if (s == "СИТ") {
		int y = 0;
		while (y < i) {
			//правя така, че да се върти цикъл до 5 и да се извеждат само 5 студенти на страница
			for (int y1 = 0; y1 < 5; y1++) {
				//ако брояча стане по-голям от броя на студентите извеждането спира
				if (y >= i) {
					break;
				}

				cout << "Специалност:";
				cout << studSIT[y].specialnost << endl;
				cout << "Име и фамилия:";
				cout << studSIT[y].ime << endl;
				cout << "Факултетен номер:";
				cout << studSIT[y].faknomer << endl;
				cout << "Месец и година на раждане (формат месец.година):";
				cout << studSIT[y].mesec << "." << studSIT[y].godina << endl;
				cout << "Оценка по математика:";
				cout << studSIT[y].mat << endl;
				cout << "Оценка по БП:";
				cout << studSIT[y].bp << endl;
				cout << "Оценка по физическо:";
				cout << studSIT[y].fiz << endl;
				cout << "Оценка по УЕБ:";
				cout << studSIT[y].web << endl;
				cout << "Оценка по електроника:";
				cout << studSIT[y].el << endl;
				cout << endl;
				y++;
			}
			//ако брояча стане по-голям от броя на студентите, редовете долу няма да се изведат
			if (y >= i) {
				break;
			}
			//въвежда се n, за да се отиде на следващата страница от студенти, ако всеки един друг въведен символ означава, че се приключва с извеждането
			cout << "Въведете n за да отидете на следващата страница, или какъвто и да е смивол освен n, за да приключите с извеждането:";
			string s1;
			cin >> s1;

			if (s1 == "n") {
				continue;
			}
			else {
				cout << "Вие приключихте с извеждането." << endl;
				break;
			}


		}
	}
	//същото правя и за спец. КСТ
	else if (s == "КСТ") {
		int y = 0;

		while (y < k) {
			for (int y1 = 0; y1 < 5; y1++) {
				if (y >= k) {
					break;
				}
				cout << "Специалност:";
				cout << studKST[y].specialnost << endl;
				cout << "Име и фамилия:";
				cout << studKST[y].ime << endl;
				cout << "Факултетен номер:";
				cout << studKST[y].faknomer << endl;
				cout << "Месец и година на раждане (формат месец.година):";
				cout << studKST[y].mesec << "." << studKST[y].godina << endl;
				cout << "Оценка по математика:";
				cout << studKST[y].mat << endl;
				cout << "Оценка по БП:";
				cout << studKST[y].bp << endl;
				cout << "Оценка по физическо:";
				cout << studKST[y].fiz << endl;
				cout << "Оценка по УЕБ:";
				cout << studKST[y].web << endl;
				cout << "Оценка по електроника:";
				cout << studKST[y].el << endl;
				cout << endl;
				y++;
			}
			if (y >= k) {
				break;
			}

			cout << "Въведете n за да отидете на следващата страница, или какъвто и да е смивол освен n, за да приключите с извеждането:";
			string s1;
			cin >> s1;

			if (s1 == "n") {
				continue;
			}
			else {
				cout << "Вие приключихте с извеждането." << endl;
				break;
			}
		}
	}
	//ако въведената специалност не съществува, фунцкяита се стартира отначало
	else {
		cout << "Въведете валидна специалност." << endl;
		output(i, k, studSIT, studKST);
	}
}

//въвеждане на само 1 студент
void enterOneStudent(int& i, int& k, student studSIT[], student studKST[]) {
	cout << "Въведете специалност на студента (СИТ или КСТ): " << endl;
	string s;

	cin >> s;
	//въвежда се специалността и за дадената специалност полетата се записват в съответния масив
	if (s == "СИТ") {
		if (i < 30) {


			studSIT[i].specialnost = s;
			cin.ignore();
			cout << "Въведете име и фамилия: ";
			getline(cin, studSIT[i].ime);
			cout << "Въведете факултетен номер:";
			cin >> studSIT[i].faknomer;
			cout << "Въведете година на раждане:";
			cin >> studSIT[i].godina;
			cout << "Въведете месец на раждане с цифри (например за януари въведете 1, за февруари 2 и т.н.) :";
			cin >> studSIT[i].mesec;
			cout << "Въведете оценка по математика: ";
			cin >> studSIT[i].mat;
			cout << "Въведете оценка по БП: ";
			cin >> studSIT[i].bp;
			cout << "Въведете оценка по физическо: ";
			cin >> studSIT[i].fiz;
			cout << "Въведете оценка по УЕБ: ";
			cin >> studSIT[i].web;
			cout << "Въведете оценка по електроника: ";
			cin >> studSIT[i].el;
			i++;
		}
		else {
			cout << "Специалност СИТ вече има 30 ученици." << endl;

		}
	}
	else if (s == "КСТ") {
		if (k < 30) {


			studKST[k].specialnost = s;
			cin.ignore();
			cout << "Въведете име и фамилия: ";
			getline(cin, studKST[i].ime);
			cout << "Въведете факултетен номер:";
			cin >> studKST[k].faknomer;
			cout << "Въведете година на раждане:";
			cin >> studKST[k].godina;
			cout << "Въведете месец на раждане с цифри (например за януари въведете 1, за февруари 2 и т.н.) :";
			cin >> studKST[k].mesec;
			cout << "Въведете оценка по математика: ";
			cin >> studKST[k].mat;
			cout << "Въведете оценка по БП: ";
			cin >> studKST[k].bp;
			cout << "Въведете оценка по физическо: ";
			cin >> studKST[k].fiz;
			cout << "Въведете оценка по УЕБ: ";
			cin >> studKST[k].web;
			cout << "Въведете оценка по електроника: ";
			cin >> studKST[k].el;
			k++;
		}
		else {
			cout << "Специалност КСТ вече има 30 ученици." << endl;
		}

	}
	//ако въведената специалност не съществува, функцията се стартира наново
	else {
		cout << "Въведете валидна специалност." << endl;
		enterOneStudent(i, k, studSIT, studKST);
	}

}

//функция за избор от менюто
int entry() {
	int n = 0;
	while (true) {
		//докато не се въведе валиден номер, фунцкията връща потребителя към въвеждането
		cout << "Вашият избор:";
		cin >> n;
		if (n < 1 || n>15) {
			cout << "Въведете валиден номер" << endl;
		}
		//ако номера е валиден, той се връща към main функцията
		else {
			return n;
		}

	}



}


//const int PI 3.14
//#define PI 3.14
//#define служи компилаторът да замени препратките към съответната константа с определената стойност(3.14) по време на компилиране.
//cout<<hex<<10;








