#include <iostream>
#include <string>
#include<windows.h>
#include<fstream>
using namespace std;
struct student {
	string specialnost;
	string ime;
	string faknomer;
	int godina;
	int mesec;
	double mat;
	double bp;
	double fiz;
	double web;
	double el;
	double srus;






};
int entry();
void enterOneStudent(int& i, int& k, student studSIT[], student studKST[]);
void enterManyStudents(int& i, int& k, student studSIT[], student studKST[]);
void output(int i, int k, student studSIT[], student studKST[]);

void outputWith6poBP(int i, int k, student studSIT[], student studKST[]);

void outputpovuzrast(int i, int k, student studSIT[], student studKST[]);

void outputNaiDoburStudent(int i, int k, student studSIT[], student studKST[]);

void save(int i, int k, student studSIT[], student studKST[]);

void fromFile(int& i, int& k, student studSIT[], student studKST[]);

void outputUspehNad5i50(int i, int k, student studSIT[], student studKST[]);

void outputpouspeh(int i, int k, student studSIT[], student studKST[]);

void razpredelenieVGrupa(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int& grupiSIT, int& grupiKST);

void razmqnaNaGrupi(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[]);

void grupiOutput(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int grupiSIT, int grupiKST);

void iztrivaneNaStudent(int& i, int& k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int grupiSIT, int grupiKST);
void savebinary(int i, int k, student studSIT[], student studKST[]);

int main() {
	setlocale(LC_ALL, "Bulgarian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);


	int i = 0;

	int k = 0;

	int grupiSIT = 0;

	int grupiKST = 0;


	student SIT[6][5];
	student KST[6][5];

	student studSIT[30];
	student studKST[30];

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


	while (true) {
		cout << endl;
		cout << "Âúâåäåòå:" << endl;
		cout << "1 çà äîáàâÿíå íà åäèí ñòóäåíò." << endl;
		cout << "2 çà äîáàâÿíå íà n íà áðîé ñòóäåíòè." << endl;
		cout << "3 çà èçâåæäàíå íà ñòóäåíòè îò äàäåíà ñïåöèàëíîñò." << endl;
		cout << "4 çà èçâåæäàíå íà ñòóäåíòè ñ Îòëè÷åí ïî ÁÏ." << endl;
		cout << "5 çà ñúçäàâàíå íà ãðóïèòå îò ñòóäåíòè." << endl;
		cout << "Çà îïöèè 6,7 è 8 ïúðâî ñúçäàéòå ãðóïèòå ÷ðåç îïöèÿ 5" << endl;
		cout << "6 çà ðàçìÿíà íà ãðóïèòå íà äâàìà ñòóäåíòè." << endl;
		cout << "7 çà èçòðèâàíå íà ñòóäåíò" << endl;
		cout << "8 çà èçâåæäàíå íà ñòóäåíòèòå ïî ãðóïè." << endl;
		cout << "9 çà èçâåæäàíå íà ñòóäåíòèòå, ïîäðåäåíè ïî ñðåäåí óñïåõ." << endl;
		cout << "10 çà èçâåæäàíå íà ñòóäåíòèòå, ïîäðåäåíè ïî âúçðàñò â ìåñåöè." << endl;
		cout << "11 çà èçâåæäàíå íà ñòóäåíòèòå ñ íàé-äîáúð ñðåäåí óñïåõ îò ÊÑÒ è ÑÈÒ." << endl;
		cout << "12 çà èçâåæäàíå íà ñòóäåíòèòå ñ óñïåõ íàä 5.50." << endl;
		cout << "13 çà çàïàçâàíå íà äàííèòå âúâ ôàéë." << endl;
		cout << "14 çà âêàðâàíå íà äàííèòå îò ôàéëà â ïðîãðàìàòà " << endl;
		cout << "15 çà èçëèçàíå îò ïðîãðàìàòà." << endl;
		
		int entered = entry();
	
		if (entered == 15) {
			break;
		}
	
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


void iztrivaneNaStudent(int& i, int& k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int grupiSIT, int grupiKST) {
	string spec;
	
	cout << "Âúâåäåòå ñïåöèàëíîñò, îò êîÿòî ùå èçòðèâàòå ñòóäåíò: " << endl;
	cin >> spec;
	if (spec == "ÑÈÒ") {

		cout << "Âúâåäåòå ôàê. íîìåð íà ñòóäåíòà: " << endl;
		string fakn;
		cin >> fakn;

		int index1 = -1;
		int index2 = -1;

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

		
		if (index1 >= 0) {


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


			//ïîíåæå ñëåä êàòî ñòóäåíò ñå èçòðèå îò ãðóïà, òîé òðÿáâà äà ñå èçòðèå è îò öåëèÿ ïîòîê, çà äà áúäàò ïðàâèëíî ñúçäàäåíè ãðóïèòå
			int index = -1;
			for (int y = 0; y < i; y++) {
				if (studSIT[y].faknomer == fakn) {
					index = y;
					break;
				}
			}
			
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
			cout << "Ìîëÿ âúâåäåòå 7 îòíîâî è ñëåä òîâà âúâåäåòå ÂÀËÈÄÅÍ ôàê.íîìåð." << endl;


		}









	}


	//ñúùîòî ïðàâÿ è çà ñïåöèàëíîñò ÊÑÒ
	else if (spec == "ÊÑÒ") {

		cout << "Âúâåäåòå ôàê. íîìåð íà ñòóäåíòà: " << endl;
		string fakn;
		cin >> fakn;
		
		int index1 = -1;
		int index2 = -1;
		
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

		
		if (index1 >= 0) {
		

			for (int y = index2; y <= 4; y++) {
				if (y < 4) {
					KST[index1][y] = KST[index1][y + 1];
					
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


		
			int index = -1;
			for (int y = 0; y < k; y++) {
				if (studKST[y].faknomer == fakn) {
					index = y;
					break;
				}
			}
		
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
					studKST[y]= studKST[y + 1];
					
				}

			}
			
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
			cout << "Ìîëÿ âúâåäåòå 7 îòíîâî è ñëåä òîâà âúâåäåòå ÂÀËÈÄÅÍ ôàê.íîìåð." << endl;


		}

	}
	
	else {
		cout << "Ìîëÿ âúâåäåòå 7 îòíîâî è ñëåä òîâà âúâåäåòå ÂÀËÈÄÍÀ  ñïåöèàëíîñò." << endl;


	}

	








}



void grupiOutput(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int grupiSIT, int grupiKST) {
	

	if (i > 0) {
		cout << "Ñïåöèàëíîñò ÑÈÒ: " << endl;
	
		for (int y1 = 0; y1 < grupiSIT; y1++) {
		
			cout << "Ãðóïà " << y1 + 1 << endl;
			cout << endl;
		
			for (int y = 0; y < 5; y++) {
		
		
		
				if (SIT[y1][y].mesec != 0) {
					cout << "Ñòóäåíò " << y + 1 << endl;
					cout << "Ñïåöèàëíîñò:";
					cout << SIT[y1][y].specialnost << endl;
					cout << "Èìå è ôàìèëèÿ:";
					cout << SIT[y1][y].ime << endl;
					cout << "Ôàêóëòåòåí íîìåð:";
					cout << SIT[y1][y].faknomer << endl;
					cout << "Ìåñåö è ãîäèíà íà ðàæäàíå (ôîðìàò ìåñåö.ãîäèíà):";
					cout << SIT[y1][y].mesec << "." << SIT[y1][y].godina << endl;
					cout << "Îöåíêà ïî ìàòåìàòèêà:";
					cout << SIT[y1][y].mat << endl;
					cout << "Îöåíêà ïî ÁÏ:";
					cout << SIT[y1][y].bp << endl;
					cout << "Îöåíêà ïî ôèçè÷åñêî:";
					cout << SIT[y1][y].fiz << endl;
					cout << "Îöåíêà ïî ÓÅÁ:";
					cout << SIT[y1][y].web << endl;
					cout << "Îöåíêà ïî åëåêòðîíèêà:";
					cout << SIT[y1][y].el << endl;
					cout << endl;



				}
			}


		}
	}

	
	if (k > 0) {
		cout << "Ñïåöèàëíîñò ÊÑÒ: " << endl;

		for (int y1 = 0; y1 < grupiKST; y1++) {
			cout << "Ãðóïà " << y1 + 1 << endl;
			cout << endl;
			for (int y = 0; y < 5; y++) {
				if (KST[y1][y].mesec != 0) {
					cout << "Ñòóäåíò " << y + 1 << endl;
					cout << "Ñïåöèàëíîñò:";
					cout << KST[y1][y].specialnost << endl;
					cout << "Èìå è ôàìèëèÿ:";
					cout << KST[y1][y].ime << endl;
					cout << "Ôàêóëòåòåí íîìåð:";
					cout << KST[y1][y].faknomer << endl;
					cout << "Ìåñåö è ãîäèíà íà ðàæäàíå (ôîðìàò ìåñåö.ãîäèíà):";
					cout << KST[y1][y].mesec << "." << KST[y1][y].godina << endl;
					cout << "Îöåíêà ïî ìàòåìàòèêà:";
					cout << KST[y1][y].mat << endl;
					cout << "Îöåíêà ïî ÁÏ:";
					cout << KST[y1][y].bp << endl;
					cout << "Îöåíêà ïî ôèçè÷åñêî:";
					cout << KST[y1][y].fiz << endl;
					cout << "Îöåíêà ïî ÓÅÁ:";
					cout << KST[y1][y].web << endl;
					cout << "Îöåíêà ïî åëåêòðîíèêà:";
					cout << KST[y1][y].el << endl;
					cout << endl;



				}
			}


		}

	}
}

void razmqnaNaGrupi(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[]) {

	string purvi, vtori, spec;
	student help;
	
	cout << "Âúâåäåòå îò êîÿ ñïåöèàëíîñò ñà ñòóäåíòèòå: ";
	cin >> spec;

	cout << "Âúâåäåòå ôàê. íîìåð íà ïúðâè ñòóäåíò: ";
	
	cin >> purvi;
	cout << "Âúâåäåòå ôàê. íîìåð íà âòîðè ñòóäåíò: ";
	cin >> vtori;
	
	int indexpurvi1 = -1;
	int indexpurvi2 = -1;
	int indexvtori1 = -1;
	int indexvtori2 = -1;
	
	if (spec == "ÑÈÒ") {


		
		for (int y1 = 0; y1 < 6; y1++) {
			for (int y = 0; y < 5; y++) {
				
				
				if (SIT[y1][y].faknomer == purvi) {
					indexpurvi1 = y1;
					indexpurvi2 = y;


				}

				if (SIT[y1][y].faknomer == vtori) {
					indexvtori1 = y1;
					indexvtori2 = y;


				}

				//àêî è äâàòà èíäåêñèòå è íà äâàòà ñòóäåíòà ñà íàé-ìàëêî 0 , òî çíà÷è, ÷å è çà äâàòà âúâåäåíè ôàêóëòåòíè íîìåðà å íàìåðåí ñòóäåíò è ñå ñïèðà òúðñåíåòî
				if (indexpurvi1 >= 0 && indexvtori1 >= 0) {
					y1 = 6;
					break;
				}



			}
		}
		
		if (indexpurvi1 >= 0 && indexvtori1 >= 0) {
			
			help = SIT[indexpurvi1][indexpurvi2];



			SIT[indexpurvi1][indexpurvi2] = SIT[indexvtori1][indexvtori2];



			SIT[indexvtori1][indexvtori2] = help;




			
			int index1 = -1;
			int index2 = -1;
			
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
			
			studSIT[index1] = studSIT[index2];


			
			studSIT[index2] = help;




			cout << "Ñòóäåíòèòå ñà ðàçìåíåíè óñïåøíî" << endl;
		}

		
		else {
			cout << "Ìîëÿ âúâåäåòå 6 îòíîâî ,ñëåä êîåòî âúâåäåòå ÂÀËÈÄÍÈ ôàêóëòåòíè íîìåðà" << endl;


		}






	}



	
	else if (spec == "ÊÑÒ") {



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

			cout << "Ñòóäåíòèòå ñà ðàçìåíåíè óñïåøíî" << endl;

		}


		else {

			cout << "Ìîëÿ âúâåäåòå 6 îòíîâî ,ñëåä êîåòî âúâåäåòå ÂÀËÈÄÍÈ ôàêóëòåòíè íîìåðà" << endl;


		}






	}



	else {
		cout << "Ìîëÿ âúâåäåòå 6 îòíîâî è ñëåä òîâà âúâåäåòå ÂÀËÈÄÍÀ ñïåöèàëíîñò" << endl;
	}







}



void razpredelenieVGrupa(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int& grupiSIT, int& grupiKST) {

	cout << "Ãðóïèòå áÿõà ñúçäàäåíè óñïåøíî." << endl;

	int left = i;



	if (i <= 5) {

		grupiSIT = 1;
		
		for (int y = 0; y < i; y++) {

			SIT[0][y] = studSIT[y];


		}


	}
	
	else if (i > 5 && i < 8) {
	
		grupiSIT = 2;
	
		for (int y = 0; y < 3; y++) {

			SIT[0][y] = studSIT[y];


		}
	
		int br3 = 2;
	
		for (int y = 0; y < i - 3; y++) {
			br3++;

			SIT[1][y] = studSIT[br3];


		}



	}
	
	if (i == 11) {
		grupiSIT = 3;
		int br3 = -1;
	
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

	
	else if (i > 7 && i <= 27 && i != 11) {
	
		grupiSIT = i / 4;
		int br3 = -1;
		for (int y1 = 0; y1 < grupiSIT + 1; y1++) {

	
			if (left >= 4) {
				left -= 4;

				for (int y = 0; y < 4; y++) {
					br3++;

					SIT[y1][y] = studSIT[br3];


				}


			}

			
			else if (left > 0) {
			
				for (int y1 = 0; y1 < left; y1++) {
					br3++;

					SIT[y1][4] = studSIT[br3];

				}

			}

		}



	}
	
	else if (i >= 28 && i <= 30) {
	
		grupiSIT = 6;
	
		int ostatuk = i - 27;
		int br3 = -1;
	
		for (int y1 = 0; y1 < grupiSIT; y1++) {




			for (int y = 0; y < 4; y++) {
				br3++;

				SIT[y1][y] = studSIT[br3];

			}


		}

		
		
		for (int y1 = 0; y1 < 3 + ostatuk; y1++) {
			br3++;

			SIT[y1][4] = studSIT[br3];




		}



	}
	
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



void outputpouspeh(int i, int k, student studSIT[], student studKST[]) {

	student studobshto[60];
	student help;
	boolean flag = true;

	for (int y = 0; y < i; y++) {

		studobshto[y] = studSIT[y];


		studobshto[y].srus = (studSIT[y].bp + studSIT[y].mat + studSIT[y].fiz + studSIT[y].el + studSIT[y].web) / 5.0;
	}
	int br3 = 0;
	for (int y = i; y < i + k; y++) {

		studobshto[y] = studKST[br3];

		studobshto[y].srus = (studKST[br3].bp + studKST[br3].mat + studKST[br3].fiz + studKST[br3].el + studKST[br3].web) / 5.0;
		br3++;
	}

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





	for (int y = 0; y < i + k; y++) {

		cout << "Ñïåöèàëíîñò:";
		cout << studobshto[y].specialnost << endl;
		cout << "Èìå è ôàìèëèÿ:";
		cout << studobshto[y].ime << endl;
		cout << "Ñðåäåí óñïåõ:";
		cout << studobshto[y].srus << endl;
		cout << "Ôàêóëòåòåí íîìåð:";
		cout << studobshto[y].faknomer << endl;
		cout << "Ìåñåö è ãîäèíà íà ðàæäàíå (ôîðìàò ìåñåö.ãîäèíà):";
		cout << studobshto[y].mesec << "." << studobshto[y].godina << endl;
		cout << "Îöåíêà ïî ìàòåìàòèêà:";
		cout << studobshto[y].mat << endl;
		cout << "Îöåíêà ïî ÁÏ:";
		cout << studobshto[y].bp << endl;
		cout << "Îöåíêà ïî ôèçè÷åñêî:";
		cout << studobshto[y].fiz << endl;
		cout << "Îöåíêà ïî ÓÅÁ:";
		cout << studobshto[y].web << endl;
		cout << "Îöåíêà ïî åëåêòðîíèêà:";
		cout << studobshto[y].el << endl;
		cout << endl;
	}














}








void outputUspehNad5i50(int i, int k, student studSIT[], student studKST[]) {


	for (int y = 0; y < i; y++) {
		double current = (studSIT[y].bp + studSIT[y].mat + studSIT[y].fiz + studSIT[y].el + studSIT[y].web) / 5.0;
		if (current > 5.499) {
			cout << "Ñïåöèàëíîñò:";
			cout << studSIT[y].specialnost << endl;
			cout << "Èìå è ôàìèëèÿ:";
			cout << studSIT[y].ime << endl;
			cout << "Ñðåäåí óñïåõ:";
			cout << current << endl;
			cout << "Ôàêóëòåòåí íîìåð:";
			cout << studSIT[y].faknomer << endl;
			cout << "Ìåñåö è ãîäèíà íà ðàæäàíå (ôîðìàò ìåñåö.ãîäèíà):";
			cout << studSIT[y].mesec << "." << studSIT[y].godina << endl;
			cout << "Îöåíêà ïî ìàòåìàòèêà:";
			cout << studSIT[y].mat << endl;
			cout << "Îöåíêà ïî ÁÏ:";
			cout << studSIT[y].bp << endl;
			cout << "Îöåíêà ïî ôèçè÷åñêî:";
			cout << studSIT[y].fiz << endl;
			cout << "Îöåíêà ïî ÓÅÁ:";
			cout << studSIT[y].web << endl;
			cout << "Îöåíêà ïî åëåêòðîíèêà:";
			cout << studSIT[y].el << endl;
			cout << endl;

		}
	}

	//ñúùîòî ñå ñëó÷âà è çà ÊÑÒ
	for (int y = 0; y < k; y++) {
		double current = (studKST[y].bp + studKST[y].mat + studKST[y].fiz + studKST[y].el + studKST[y].web) / 5.0;
		if (current >= 5.499) {
			cout << "Ñïåöèàëíîñò:";
			cout << studKST[y].specialnost << endl;
			cout << "Èìå è ôàìèëèÿ:";
			cout << studKST[y].ime << endl;
			cout << "Ñðåäåí óñïåõ:";
			cout << current << endl;
			cout << "Ôàêóëòåòåí íîìåð:";
			cout << studKST[y].faknomer << endl;
			cout << "Ìåñåö è ãîäèíà íà ðàæäàíå (ôîðìàò ìåñåö.ãîäèíà):";
			cout << studKST[y].mesec << "." << studKST[y].godina << endl;
			cout << "Îöåíêà ïî ìàòåìàòèêà:";
			cout << studKST[y].mat << endl;
			cout << "Îöåíêà ïî ÁÏ:";
			cout << studKST[y].bp << endl;
			cout << "Îöåíêà ïî ôèçè÷åñêî:";
			cout << studKST[y].fiz << endl;
			cout << "Îöåíêà ïî ÓÅÁ:";
			cout << studKST[y].web << endl;
			cout << "Îöåíêà ïî åëåêòðîíèêà:";
			cout << studKST[y].el << endl;
			cout << endl;

		}








	}
}








void fromFile(int& i, int& k, student studSIT[], student studKST[]) {
	fstream f;

	f.open("FailSDanni.txt", ios::out | ios::in | ios::app);

	if (f.peek() == ifstream::traits_type::eof()) {
		cout << "Ôàéëúò å ïðàçåí." << endl;
	}

	else {
		cout << "Äàííèòå áÿõà ïðåõâúðëåíè óñïåøíî." << endl;

		f >> i;
		f >> k;
		int brsit = 0;
		int brkst = 0;

		for (int y = 0; y < i + k; y++) {
			string c = "";
			f >> c;
			if (c == "ÑÈÒ") {
				studSIT[brsit].specialnost = "ÑÈÒ";
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



			if (c == "ÊÑÒ") {
				studKST[brkst].specialnost = "ÊÑÒ";
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





void save(int i, int k, student studSIT[], student studKST[]) {
	cout << "Ôàéëúò áåøå çàïèñàí óñïåøíî." << endl;
	cout << endl;
	fstream f;
	
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
	cout << "Äâóè÷íèÿò ôàéë áåøå çàïèñàí óñïåøíî." << endl;
	cout << endl;
	fstream f;
	
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

void outputNaiDoburStudent(int i, int k, student studSIT[], student studKST[]) {
	double maxSIT = 0;
	double maxKST = 0;
	
	for (int y = 0; y < i; y++) {
		double current = (studSIT[y].bp + studSIT[y].mat + studSIT[y].fiz + studSIT[y].el + studSIT[y].web) / 5;
		if (current > maxSIT) {
			maxSIT = current;

		}

	}
	
	for (int y = 0; y < i; y++) {
		double current = (studSIT[y].bp + studSIT[y].mat + studSIT[y].fiz + studSIT[y].el + studSIT[y].web) / 5;
		if (current == maxSIT) {
			cout << "Ñïåöèàëíîñò:";
			cout << studSIT[y].specialnost << endl;
			cout << "Èìå è ôàìèëèÿ:";
			cout << studSIT[y].ime << endl;
			cout << "Ñðåäåí óñïåõ:";
			cout << current << endl;
			cout << "Ôàêóëòåòåí íîìåð:";
			cout << studSIT[y].faknomer << endl;
			cout << "Ìåñåö è ãîäèíà íà ðàæäàíå (ôîðìàò ìåñåö.ãîäèíà):";
			cout << studSIT[y].mesec << "." << studSIT[y].godina << endl;
			cout << "Îöåíêà ïî ìàòåìàòèêà:";
			cout << studSIT[y].mat << endl;
			cout << "Îöåíêà ïî ÁÏ:";
			cout << studSIT[y].bp << endl;
			cout << "Îöåíêà ïî ôèçè÷åñêî:";
			cout << studSIT[y].fiz << endl;
			cout << "Îöåíêà ïî ÓÅÁ:";
			cout << studSIT[y].web << endl;
			cout << "Îöåíêà ïî åëåêòðîíèêà:";
			cout << studSIT[y].el << endl;
			cout << endl;

		}

	}


	

	for (int y = 0; y < k; y++) {
		double current = (studKST[y].bp + studKST[y].mat + studKST[y].fiz + studKST[y].el + studKST[y].web) / 5;
		if (current > maxKST) {
			maxKST = current;

		}

	}


	for (int y = 0; y < k; y++) {
		double current = (studKST[y].bp + studKST[y].mat + studKST[y].fiz + studKST[y].el + studKST[y].web) / 5;
		if (current == maxKST) {

			cout << "Ñïåöèàëíîñò:";
			cout << studKST[y].specialnost << endl;
			cout << "Èìå è ôàìèëèÿ:";
			cout << studKST[y].ime << endl;
			cout << "Ñðåäåí óñïåõ:";
			cout << current << endl;
			cout << "Ôàêóëòåòåí íîìåð:";
			cout << studKST[y].faknomer << endl;
			cout << "Ìåñåö è ãîäèíà íà ðàæäàíå (ôîðìàò ìåñåö.ãîäèíà):";
			cout << studKST[y].mesec << "." << studKST[y].godina << endl;
			cout << "Îöåíêà ïî ìàòåìàòèêà:";
			cout << studKST[y].mat << endl;
			cout << "Îöåíêà ïî ÁÏ:";
			cout << studKST[y].bp << endl;
			cout << "Îöåíêà ïî ôèçè÷åñêî:";
			cout << studKST[y].fiz << endl;
			cout << "Îöåíêà ïî ÓÅÁ:";
			cout << studKST[y].web << endl;
			cout << "Îöåíêà ïî åëåêòðîíèêà:";
			cout << studKST[y].el << endl;
			cout << endl;

		}

	}







}


void outputpovuzrast(int i, int k, student studSIT[], student studKST[]) {
	
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
	
	for (int y = 0; y < i + k; y++) {

		cout << "Ñïåöèàëíîñò:";
		cout << studobshto[y].specialnost << endl;
		cout << "Èìå è ôàìèëèÿ:";
		cout << studobshto[y].ime << endl;
		cout << "Ôàêóëòåòåí íîìåð:";
		cout << studobshto[y].faknomer << endl;
		cout << "Ìåñåö è ãîäèíà íà ðàæäàíå (ôîðìàò ìåñåö.ãîäèíà):";
		cout << studobshto[y].mesec << "." << studobshto[y].godina << endl;
		cout << "Îöåíêà ïî ìàòåìàòèêà:";
		cout << studobshto[y].mat << endl;
		cout << "Îöåíêà ïî ÁÏ:";
		cout << studobshto[y].bp << endl;
		cout << "Îöåíêà ïî ôèçè÷åñêî:";
		cout << studobshto[y].fiz << endl;
		cout << "Îöåíêà ïî ÓÅÁ:";
		cout << studobshto[y].web << endl;
		cout << "Îöåíêà ïî åëåêòðîíèêà:";
		cout << studobshto[y].el << endl;
		cout << endl;
	}


}










void outputWith6poBP(int i, int k, student studSIT[], student studKST[]) {


	for (int y = 0; y < i; y++) {
		if (studSIT[y].bp >= 5.499) {

			cout << "Ñïåöèàëíîñò:";
			cout << studSIT[y].specialnost << endl;
			cout << "Èìå è ôàìèëèÿ:";
			cout << studSIT[y].ime << endl;
			cout << "Ôàêóëòåòåí íîìåð:";
			cout << studSIT[y].faknomer << endl;
			cout << "Ìåñåö è ãîäèíà íà ðàæäàíå (ôîðìàò ìåñåö.ãîäèíà):";
			cout << studSIT[y].mesec << "." << studSIT[y].godina << endl;
			cout << "Îöåíêà ïî ìàòåìàòèêà:";
			cout << studSIT[y].mat << endl;
			cout << "Îöåíêà ïî ÁÏ:";
			cout << studSIT[y].bp << endl;
			cout << "Îöåíêà ïî ôèçè÷åñêî:";
			cout << studSIT[y].fiz << endl;
			cout << "Îöåíêà ïî ÓÅÁ:";
			cout << studSIT[y].web << endl;
			cout << "Îöåíêà ïî åëåêòðîíèêà:";
			cout << studSIT[y].el << endl;
			cout << endl;
		}

	}


	
	for (int y = 0; y < k; y++) {
		if (studKST[y].bp >= 5.499) {
			cout << "Ñïåöèàëíîñò:";
			cout << studKST[y].specialnost << endl;
			cout << "Èìå è ôàìèëèÿ:";
			cout << studKST[y].ime << endl;
			cout << "Ôàêóëòåòåí íîìåð:";
			cout << studKST[y].faknomer << endl;
			cout << "Ìåñåö è ãîäèíà íà ðàæäàíå (ôîðìàò ìåñåö.ãîäèíà):";
			cout << studKST[y].mesec << "." << studSIT[y].godina << endl;
			cout << "Îöåíêà ïî ìàòåìàòèêà:";
			cout << studKST[y].mat << endl;
			cout << "Îöåíêà ïî ÁÏ:";
			cout << studKST[y].bp << endl;
			cout << "Îöåíêà ïî ôèçè÷åñêî:";
			cout << studKST[y].fiz << endl;
			cout << "Îöåíêà ïî ÓÅÁ:";
			cout << studKST[y].web << endl;
			cout << "Îöåíêà ïî åëåêòðîíèêà:";
			cout << studKST[y].el << endl;
			cout << endl;
		}
	}

}

void enterManyStudents(int& i, int& k, student studSIT[], student studKST[]) {
	cout << "Âúâåäåòå áðîé ñòóäåíòè, êîèòî èñêàòå äà âúâåäåòå:";
	int n;

	cin >> n;


	for (int br = 1; br <= n; br++) {

		cout << "Ñòóäåíò " << br << endl;
		cout << "Âúâåäåòå ñïåöèàëíîñò íà ñòóäåíòà (ÑÈÒ èëè ÊÑÒ)(Âúâåäåòå 0 àêî èñêàòå äà ñå ñïðå âúâåæäàíåòî íà ñòóäåíòè) : " << endl;
		string s;

		cin >> s;
	
		if (s == "0") {
			cout << "Ïðåêðàòèõòå âúâåæäàíåòî íà ñòóäåíòè." << endl;
			break;
		}
		
		else if (s == "ÑÈÒ") {
			
			if (i < 30) {

				
				studSIT[i].specialnost = s;
				cin.ignore();
				cout << "Âúâåäåòå èìå è ôàìèëèÿ: ";
				getline(cin, studSIT[i].ime);
				cout << "Âúâåäåòå ôàêóëòåòåí íîìåð:";
				cin >> studSIT[i].faknomer;
				cout << "Âúâåäåòå ãîäèíà íà ðàæäàíå:";
				cin >> studSIT[i].godina;
				cout << "Âúâåäåòå ìåñåö íà ðàæäàíå ñ öèôðè (íàïðèìåð çà ÿíóàðè âúâåäåòå 1, çà ôåâðóàðè 2 è ò.í.) :";
				cin >> studSIT[i].mesec;
				cout << "Âúâåäåòå îöåíêà ïî ìàòåìàòèêà: ";
				cin >> studSIT[i].mat;
				cout << "Âúâåäåòå îöåíêà ïî ÁÏ: ";
				cin >> studSIT[i].bp;
				cout << "Âúâåäåòå îöåíêà ïî ôèçè÷åñêî: ";
				cin >> studSIT[i].fiz;
				cout << "Âúâåäåòå îöåíêà ïî ÓÅÁ: ";
				cin >> studSIT[i].web;
				cout << "Âúâåäåòå îöåíêà ïî åëåêòðîíèêà: ";
				cin >> studSIT[i].el;
				i++;
			}
			
			else {
				cout << "Ñïåöèàëíîñò ÑÈÒ âå÷å èìà 30 ó÷åíèöè." << endl;

			}
		}
		
		else if (s == "ÊÑÒ") {
			if (k < 30) {


				studKST[k].specialnost = s;
				cin.ignore();
				cout << "Âúâåäåòå èìå è ôàìèëèÿ:";
				getline(cin, studKST[k].ime);
				cout << "Âúâåäåòå ôàêóëòåòåí íîìåð:";
				cin >> studKST[k].faknomer;
				cout << "Âúâåäåòå ãîäèíà íà ðàæäàíå:";
				cin >> studKST[k].godina;
				cout << "Âúâåäåòå ìåñåö íà ðàæäàíå ñ öèôðè (íàïðèìåð çà ÿíóàðè âúâåäåòå 1, çà ôåâðóàðè 2 è ò.í.) :";
				cin >> studKST[k].mesec;
				cout << "Âúâåäåòå îöåíêà ïî ìàòåìàòèêà: ";
				cin >> studKST[k].mat;
				cout << "Âúâåäåòå îöåíêà ïî ÁÏ: ";
				cin >> studKST[k].bp;
				cout << "Âúâåäåòå îöåíêà ïî ôèçè÷åñêî: ";
				cin >> studKST[k].fiz;
				cout << "Âúâåäåòå îöåíêà ïî ÓÅÁ: ";
				cin >> studKST[k].web;
				cout << "Âúâåäåòå îöåíêà ïî åëåêòðîíèêà: ";
				cin >> studKST[k].el;
				k++;
			}
			else {
				cout << "Ñïåöèàëíîñò ÊÑÒ âå÷å èìà 30 ó÷åíèöè." << endl;
			}

		}
		
		else {
			cout << "Âúâåäåòå âàëèäíà ñïåöèàëíîñò." << endl;
			cout << endl;
			br--;
		}



	}

}


void output(int i, int k, student studSIT[], student studKST[]) {
	cout << "Âúâåäåòå çà êîÿ ñïåöèàëíîñò èñêàòå äà èçâåäåòå ñòóäåíòèòå (ÑÈÒ èëè ÊÑÒ): " << endl;
	string s;
	cin >> s;


	if (s == "ÑÈÒ") {
		int y = 0;
		while (y < i) {
			
			for (int y1 = 0; y1 < 5; y1++) {
				
				if (y >= i) {
					break;
				}

				cout << "Ñïåöèàëíîñò:";
				cout << studSIT[y].specialnost << endl;
				cout << "Èìå è ôàìèëèÿ:";
				cout << studSIT[y].ime << endl;
				cout << "Ôàêóëòåòåí íîìåð:";
				cout << studSIT[y].faknomer << endl;
				cout << "Ìåñåö è ãîäèíà íà ðàæäàíå (ôîðìàò ìåñåö.ãîäèíà):";
				cout << studSIT[y].mesec << "." << studSIT[y].godina << endl;
				cout << "Îöåíêà ïî ìàòåìàòèêà:";
				cout << studSIT[y].mat << endl;
				cout << "Îöåíêà ïî ÁÏ:";
				cout << studSIT[y].bp << endl;
				cout << "Îöåíêà ïî ôèçè÷åñêî:";
				cout << studSIT[y].fiz << endl;
				cout << "Îöåíêà ïî ÓÅÁ:";
				cout << studSIT[y].web << endl;
				cout << "Îöåíêà ïî åëåêòðîíèêà:";
				cout << studSIT[y].el << endl;
				cout << endl;
				y++;
			}
			
			if (y >= i) {
				break;
			}
			
			cout << "Âúâåäåòå n çà äà îòèäåòå íà ñëåäâàùàòà ñòðàíèöà, èëè êàêúâòî è äà å ñìèâîë îñâåí n, çà äà ïðèêëþ÷èòå ñ èçâåæäàíåòî:";
			string s1;
			cin >> s1;

			if (s1 == "n") {
				continue;
			}
			else {
				cout << "Âèå ïðèêëþ÷èõòå ñ èçâåæäàíåòî." << endl;
				break;
			}


		}
	}
	
	else if (s == "ÊÑÒ") {
		int y = 0;

		while (y < k) {
			for (int y1 = 0; y1 < 5; y1++) {
				if (y >= k) {
					break;
				}
				cout << "Ñïåöèàëíîñò:";
				cout << studKST[y].specialnost << endl;
				cout << "Èìå è ôàìèëèÿ:";
				cout << studKST[y].ime << endl;
				cout << "Ôàêóëòåòåí íîìåð:";
				cout << studKST[y].faknomer << endl;
				cout << "Ìåñåö è ãîäèíà íà ðàæäàíå (ôîðìàò ìåñåö.ãîäèíà):";
				cout << studKST[y].mesec << "." << studKST[y].godina << endl;
				cout << "Îöåíêà ïî ìàòåìàòèêà:";
				cout << studKST[y].mat << endl;
				cout << "Îöåíêà ïî ÁÏ:";
				cout << studKST[y].bp << endl;
				cout << "Îöåíêà ïî ôèçè÷åñêî:";
				cout << studKST[y].fiz << endl;
				cout << "Îöåíêà ïî ÓÅÁ:";
				cout << studKST[y].web << endl;
				cout << "Îöåíêà ïî åëåêòðîíèêà:";
				cout << studKST[y].el << endl;
				cout << endl;
				y++;
			}
			if (y >= k) {
				break;
			}

			cout << "Âúâåäåòå n çà äà îòèäåòå íà ñëåäâàùàòà ñòðàíèöà, èëè êàêúâòî è äà å ñìèâîë îñâåí n, çà äà ïðèêëþ÷èòå ñ èçâåæäàíåòî:";
			string s1;
			cin >> s1;

			if (s1 == "n") {
				continue;
			}
			else {
				cout << "Âèå ïðèêëþ÷èõòå ñ èçâåæäàíåòî." << endl;
				break;
			}
		}
	}
	
	else {
		cout << "Âúâåäåòå âàëèäíà ñïåöèàëíîñò." << endl;
		output(i, k, studSIT, studKST);
	}
}


void enterOneStudent(int& i, int& k, student studSIT[], student studKST[]) {
	cout << "Âúâåäåòå ñïåöèàëíîñò íà ñòóäåíòà (ÑÈÒ èëè ÊÑÒ): " << endl;
	string s;

	cin >> s;
	
	if (s == "ÑÈÒ") {
		if (i < 30) {


			studSIT[i].specialnost = s;
			cin.ignore();
			cout << "Âúâåäåòå èìå è ôàìèëèÿ: ";
			getline(cin, studSIT[i].ime);
			cout << "Âúâåäåòå ôàêóëòåòåí íîìåð:";
			cin >> studSIT[i].faknomer;
			cout << "Âúâåäåòå ãîäèíà íà ðàæäàíå:";
			cin >> studSIT[i].godina;
			cout << "Âúâåäåòå ìåñåö íà ðàæäàíå ñ öèôðè (íàïðèìåð çà ÿíóàðè âúâåäåòå 1, çà ôåâðóàðè 2 è ò.í.) :";
			cin >> studSIT[i].mesec;
			cout << "Âúâåäåòå îöåíêà ïî ìàòåìàòèêà: ";
			cin >> studSIT[i].mat;
			cout << "Âúâåäåòå îöåíêà ïî ÁÏ: ";
			cin >> studSIT[i].bp;
			cout << "Âúâåäåòå îöåíêà ïî ôèçè÷åñêî: ";
			cin >> studSIT[i].fiz;
			cout << "Âúâåäåòå îöåíêà ïî ÓÅÁ: ";
			cin >> studSIT[i].web;
			cout << "Âúâåäåòå îöåíêà ïî åëåêòðîíèêà: ";
			cin >> studSIT[i].el;
			i++;
		}
		else {
			cout << "Ñïåöèàëíîñò ÑÈÒ âå÷å èìà 30 ó÷åíèöè." << endl;

		}
	}
	else if (s == "ÊÑÒ") {
		if (k < 30) {


			studKST[k].specialnost = s;
			cin.ignore();
			cout << "Âúâåäåòå èìå è ôàìèëèÿ: ";
			getline(cin, studKST[i].ime);
			cout << "Âúâåäåòå ôàêóëòåòåí íîìåð:";
			cin >> studKST[k].faknomer;
			cout << "Âúâåäåòå ãîäèíà íà ðàæäàíå:";
			cin >> studKST[k].godina;
			cout << "Âúâåäåòå ìåñåö íà ðàæäàíå ñ öèôðè (íàïðèìåð çà ÿíóàðè âúâåäåòå 1, çà ôåâðóàðè 2 è ò.í.) :";
			cin >> studKST[k].mesec;
			cout << "Âúâåäåòå îöåíêà ïî ìàòåìàòèêà: ";
			cin >> studKST[k].mat;
			cout << "Âúâåäåòå îöåíêà ïî ÁÏ: ";
			cin >> studKST[k].bp;
			cout << "Âúâåäåòå îöåíêà ïî ôèçè÷åñêî: ";
			cin >> studKST[k].fiz;
			cout << "Âúâåäåòå îöåíêà ïî ÓÅÁ: ";
			cin >> studKST[k].web;
			cout << "Âúâåäåòå îöåíêà ïî åëåêòðîíèêà: ";
			cin >> studKST[k].el;
			k++;
		}
		else {
			cout << "Ñïåöèàëíîñò ÊÑÒ âå÷å èìà 30 ó÷åíèöè." << endl;
		}

	}
	
	else {
		cout << "Âúâåäåòå âàëèäíà ñïåöèàëíîñò." << endl;
		enterOneStudent(i, k, studSIT, studKST);
	}

}


int entry() {
	int n = 0;
	while (true) {
		
		cout << "Âàøèÿò èçáîð:";
		cin >> n;
		if (n < 1 || n>15) {
			cout << "Âúâåäåòå âàëèäåí íîìåð" << endl;
		}
		
		else {
			return n;
		}

	}



}











