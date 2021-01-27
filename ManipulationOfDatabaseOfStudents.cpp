#include <iostream>
#include <string>
#include<windows.h>
#include<fstream>
using namespace std;
//�������� ��������� student ��� �������� ���������:
struct student {
	//����� �� ��������
	string specialnost;
	string ime;
	string faknomer;
	int godina;
	int mesec;
	//������ �� ��� �� ��������� ��� � ����������� , ����� � ������ �����
	double mat;
	double bp;
	double fiz;
	double web;
	double el;
	double srus;






};//��������� �� ���������, ����� ��������
//������� �� ����� �� ����� �� ������
int entry();
//��������� �� 1 �������
void enterOneStudent(int& i, int& k, student studSIT[], student studKST[]);
//��������� �� ���������� ���� ��������
void enterManyStudents(int& i, int& k, student studSIT[], student studKST[]);
//��������� �� �������� �� �������� �����������
void output(int i, int k, student studSIT[], student studKST[]);
//��������� �� �������� ��� ������� �� ��
void outputWith6poBP(int i, int k, student studSIT[], student studKST[]);
//��������� �� ��������, ��������� �� �������
void outputpovuzrast(int i, int k, student studSIT[], student studKST[]);
//��������� �� ���-������ ������� �� ��� � ���
void outputNaiDoburStudent(int i, int k, student studSIT[], student studKST[]);
//������� �� �������� �� ������� �� ���������� ��� ����
void save(int i, int k, student studSIT[], student studKST[]);
//�������� �� �������� �� ������� �� ����� � ���������
void fromFile(int& i, int& k, student studSIT[], student studKST[]);
//��������� �� �������� � �ra���� ��� 5.50
void outputUspehNad5i50(int i, int k, student studSIT[], student studKST[]);
//��������� �� ��������, ��������� �� �����
void outputpouspeh(int i, int k, student studSIT[], student studKST[]);
//��������� �� ��������� ����� �� ������ �����������
void razpredelenieVGrupa(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int& grupiSIT, int& grupiKST);
//������� �� ������� �� 2 ��������, ���� ��������� �� ���. ������
void razmqnaNaGrupi(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[]);
//��������� �� ���������� �� �����
void grupiOutput(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int grupiSIT, int grupiKST);
//��������� �� ������� �� ����� ���� ����������� �� ���. �����
void iztrivaneNaStudent(int& i, int& k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int grupiSIT, int grupiKST);
void savebinary(int i, int k, student studSIT[], student studKST[]);

int main() {
	setlocale(LC_ALL, "Bulgarian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	//���������� �� ���� �������� �������� �� ����. ���
	int i = 0;
	//���������� �� ���� �������� �������� �� ����. ���
	int k = 0;
	//���������� �� ����� ����� �� ��������� �� ���
	int grupiSIT = 0;
	//���������� �� ����� ����� �� ��������� �� ���
	int grupiKST = 0;
	//������ �� ����������� student
	//������� ��� �� �� ��������� ����� - ���� �� ��� ����. 5 �������� � ����� � ���� 30/5=6 �����.
	student SIT[6][5];
	student KST[6][5];
	//������� ������ �� ������ �� ������� �� ������ �������� �� ����� ������������ (���� 30)
	student studSIT[30];
	student studKST[30];
	//������� ������ ������ �� �������� �� ����������� � ��� double � int,  ������ default ����������� �� �� �� 0
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

	//����� ����, �� ������ �� �� ������� ������ ���� ���������� �� ����������, ����� � ���� ���� ������ �������� � ��������� ������������ ��.
	while (true) {
		cout << endl;
		cout << "��������:" << endl;
		cout << "1 �� �������� �� ���� �������." << endl;
		cout << "2 �� �������� �� n �� ���� ��������." << endl;
		cout << "3 �� ��������� �� �������� �� ������ �����������." << endl;
		cout << "4 �� ��������� �� �������� � ������� �� ��." << endl;
		cout << "5 �� ��������� �� ������� �� ��������." << endl;
		cout << "�� ����� 6,7 � 8 ����� �������� ������� ���� ����� 5" << endl;
		cout << "6 �� ������� �� ������� �� ����� ��������." << endl;
		cout << "7 �� ��������� �� �������" << endl;
		cout << "8 �� ��������� �� ���������� �� �����." << endl;
		cout << "9 �� ��������� �� ����������, ��������� �� ������ �����." << endl;
		cout << "10 �� ��������� �� ����������, ��������� �� ������� � ������." << endl;
		cout << "11 �� ��������� �� ���������� � ���-����� ������ ����� �� ��� � ���." << endl;
		cout << "12 �� ��������� �� ���������� � ����� ��� 5.50." << endl;
		cout << "13 �� ��������� �� ������� ��� ����." << endl;
		cout << "14 �� �������� �� ������� �� ����� � ���������� " << endl;
		cout << "15 �� �������� �� ����������." << endl;
		//�������� ���������� ����� � ����������
		int entered = entry();
		//��� � ����� �� 15 ���������� �����
		if (entered == 15) {
			break;
		}
		//��� � ����� ����� ����� ���������, ����� ����������� �� ���������� �����
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
//��������� �� ������� �� �����- ������� ��� �-��� i � k �� �������, �� �� ���� ���� �� �������� �� �� �������� ����������� �� � ������ ��������, � �� ���� ������� ��
//������� �������� �� ��������� �� ������� � �� ������ ��������, ����� � ���� ����� ����� �� ���������� �� ����� ������������
void iztrivaneNaStudent(int& i, int& k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int grupiSIT, int grupiKST) {
	string spec;
	//������� �� �����������, �� ����� �� �� ����
	cout << "�������� �����������, �� ����� �� ��������� �������: " << endl;
	cin >> spec;
	if (spec == "���") {

		cout << "�������� ���. ����� �� ��������: " << endl;
		string fakn;
		cin >> fakn;
		//���������� ��� ����������, ����� �������� ��������� �� ��������� �����
		int index1 = -1;
		int index2 = -1;
		//���������� �� ������ �������� �� ������ ����� ���� ����� ��� ����� ���. ����� � ���� �� ������ ������ ������
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

		//��� � �������, index1 ���� ���� �� � -1, � �� � >=0
		if (index1 >= 0) {
			//���� ��������, ���� �������� ��� ����� ������� ���� ����, ����������� � ����, ��������� ������� �� ��� ( ���� �������� ������� �� �������� � ������ �������� �� ���������� � ������� ������)

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


			//������ ���� ���� ������� �� ������ �� �����, ��� ������ �� �� ������ � �� ����� �����, �� �� ����� �������� ��������� �������
			int index = -1;
			for (int y = 0; y < i; y++) {
				if (studSIT[y].faknomer == fakn) {
					index = y;
					break;
				}
			}
			//����� ������ ���� � �������
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
			//������ ���� �� ���������� � ������ � 1
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
			cout << "���� �������� 7 ������ � ���� ���� �������� ������� ���.�����." << endl;


		}









	}


	//������ ����� � �� ����������� ���
	else if (spec == "���") {

		cout << "�������� ���. ����� �� ��������: " << endl;
		string fakn;
		cin >> fakn;
		//���������� ��� ����������, ����� �������� ��������� �� ��������� �����
		int index1 = -1;
		int index2 = -1;
		//���������� �� ������ �������� �� ������ ����� ���� ����� ��� ����� ���. ����� � ���� �� ������ ������ ������
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

		//��� � �������, index1 ���� ���� �� � -1, � �� � >=0
		if (index1 >= 0) {
			//���� ��������, ���� �������� ��� ����� ������� ���� ����, ����������� � ����, ��������� ������� �� ��� ( ���� �������� ������� �� �������� � ������ �������� �� ���������� � ������� ������)

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


			//������ ���� ���� ������� �� ������ �� �����, ��� ������ �� �� ������ � �� ����� �����, �� �� ����� �������� ��������� �������
			int index = -1;
			for (int y = 0; y < k; y++) {
				if (studKST[y].faknomer == fakn) {
					index = y;
					break;
				}
			}
			//����� ������ ���� � �������
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
			//������ ���� �� ���������� � ������ � 1
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
			cout << "���� �������� 7 ������ � ���� ���� �������� ������� ���.�����." << endl;


		}

	}
	//��� �� � ������� ���� ���, ���� ���  ������� ���� ���������
	else {
		cout << "���� �������� 7 ������ � ���� ���� �������� �������  �����������." << endl;


	}

	//����� ��������� �� ������������� � �����, �� �� ���� �� �� ����������� ���������� � ������� �� �������� � ���������








}


//��������� �� ���������� �� �����
void grupiOutput(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int grupiSIT, int grupiKST) {
	//��� ��� �������� �� ���

	if (i > 0) {
		cout << "����������� ���: " << endl;
		//����� ������ �������
		for (int y1 = 0; y1 < grupiSIT; y1++) {
			//������� �� ������ �� �������
			cout << "����� " << y1 + 1 << endl;
			cout << endl;
			//����� ������ ���������� � ������ �����
			for (int y = 0; y < 5; y++) {
				//������ �������� �� ���������� �� ��������, ��� �������� �� ����������, �� �� ����������� ������� ������ �� ����� ��� ��������� ���� �� � 0
				//������ �������� ���� ����������, �� ����� �� �� � 0 ������ �� ������
				//�������� ���������� ���� �� ����
				if (SIT[y1][y].mesec != 0) {
					cout << "������� " << y + 1 << endl;
					cout << "�����������:";
					cout << SIT[y1][y].specialnost << endl;
					cout << "��� � �������:";
					cout << SIT[y1][y].ime << endl;
					cout << "���������� �����:";
					cout << SIT[y1][y].faknomer << endl;
					cout << "����� � ������ �� ������� (������ �����.������):";
					cout << SIT[y1][y].mesec << "." << SIT[y1][y].godina << endl;
					cout << "������ �� ����������:";
					cout << SIT[y1][y].mat << endl;
					cout << "������ �� ��:";
					cout << SIT[y1][y].bp << endl;
					cout << "������ �� ���������:";
					cout << SIT[y1][y].fiz << endl;
					cout << "������ �� ���:";
					cout << SIT[y1][y].web << endl;
					cout << "������ �� �����������:";
					cout << SIT[y1][y].el << endl;
					cout << endl;



				}
			}


		}
	}

	//������ ����� �� ���
	if (k > 0) {
		cout << "����������� ���: " << endl;

		for (int y1 = 0; y1 < grupiKST; y1++) {
			cout << "����� " << y1 + 1 << endl;
			cout << endl;
			for (int y = 0; y < 5; y++) {
				if (KST[y1][y].mesec != 0) {
					cout << "������� " << y + 1 << endl;
					cout << "�����������:";
					cout << KST[y1][y].specialnost << endl;
					cout << "��� � �������:";
					cout << KST[y1][y].ime << endl;
					cout << "���������� �����:";
					cout << KST[y1][y].faknomer << endl;
					cout << "����� � ������ �� ������� (������ �����.������):";
					cout << KST[y1][y].mesec << "." << KST[y1][y].godina << endl;
					cout << "������ �� ����������:";
					cout << KST[y1][y].mat << endl;
					cout << "������ �� ��:";
					cout << KST[y1][y].bp << endl;
					cout << "������ �� ���������:";
					cout << KST[y1][y].fiz << endl;
					cout << "������ �� ���:";
					cout << KST[y1][y].web << endl;
					cout << "������ �� �����������:";
					cout << KST[y1][y].el << endl;
					cout << endl;



				}
			}


		}

	}
}
//������� �� ������� �� ����� �������� �� �������� ���. ������
void razmqnaNaGrupi(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[]) {

	string purvi, vtori, spec;
	student help;
	//������ ���� �� �� ������ ������� ���� �� �������� �� ���� � ���� �����������, ����� �� �� �������
	cout << "�������� �� ��� ����������� �� ����������: ";
	cin >> spec;

	cout << "�������� ���. ����� �� ����� �������: ";
	//�������� ����� ���������� ������
	cin >> purvi;
	cout << "�������� ���. ����� �� ����� �������: ";
	cin >> vtori;
	//���������� ����� ������� �� ����� ��������
	int indexpurvi1 = -1;
	int indexpurvi2 = -1;
	int indexvtori1 = -1;
	int indexvtori2 = -1;
	//��� ���������� ����������� � ���
	if (spec == "���") {


		//��������� �� ����� ������� �� ����� �����
		for (int y1 = 0; y1 < 6; y1++) {
			for (int y = 0; y < 5; y++) {
				//��� �� ������ �� �������, ����� ���. ����� � ����� ���� ����������
				//��������� �� �� �������� � �������������� ����������
				if (SIT[y1][y].faknomer == purvi) {
					indexpurvi1 = y1;
					indexpurvi2 = y;


				}

				if (SIT[y1][y].faknomer == vtori) {
					indexvtori1 = y1;
					indexvtori2 = y;


				}

				//��� � ����� ��������� � �� ����� �������� �� ���-����� 0 , �� �����, �� � �� ����� �������� ���������� ������ � ������� ������� � �� ����� ���������
				if (indexpurvi1 >= 0 && indexvtori1 >= 0) {
					y1 = 6;
					break;
				}



			}
		}
		//��� �� �������� �������� �� ����� ���������� ������
		if (indexpurvi1 >= 0 && indexvtori1 >= 0) {
			//��������� ������� �� ����� �������� � �������� �� ������� ���� ������� ����������
			help = SIT[indexpurvi1][indexpurvi2];



			SIT[indexpurvi1][indexpurvi2] = SIT[indexvtori1][indexvtori2];



			SIT[indexvtori1][indexvtori2] = help;




			//���������� ��� ����������, � ����� �� �������� ��������� �� ���������� � ����� �����
			int index1 = -1;
			int index2 = -1;
			//����� ������ ������� �� ����� ����� �� ���
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
			//������ ������� �� ������ ������� � �������� �� ������
			studSIT[index1] = studSIT[index2];


			//���� ���� ����� �� ����� ������� ����������, ������ �� ���� �� ��������� ��-����
			studSIT[index2] = help;




			cout << "���������� �� ��������� �������" << endl;
		}

		//��� ���� ��� ��� �� ������������ ������, ����� �� �������� �� ����������� � ��������, �� ������� �������� ���������
		else {
			cout << "���� �������� 6 ������ ,���� ����� �������� ������� ���������� ������" << endl;


		}






	}



	//������ ����� � �� ���� ���
	else if (spec == "���") {



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

			cout << "���������� �� ��������� �������" << endl;

		}


		else {

			cout << "���� �������� 6 ������ ,���� ����� �������� ������� ���������� ������" << endl;


		}






	}



	else {
		cout << "���� �������� 6 ������ � ���� ���� �������� ������� �����������" << endl;
	}







}


//������� �� ������������� �� ���������� � �����
void razpredelenieVGrupa(int i, int k, student SIT[][5], student KST[][5], student studSIT[], student studKST[], int& grupiSIT, int& grupiKST) {

	cout << "������� ���� ��������� �������." << endl;
	//����������, ����� ������� ����� �������� ������� �� �� ���������� � �����
	int left = i;

	//����� ����������� ���������� �� ���
	//��� �� �� ��-����� �� 6
	if (i <= 5) {
		//������� �� �� 1
		grupiSIT = 1;
		//����� �����, ����� �� ������� ���� �� ���������� ���� � �������� � ������� ����� ���������� �� ����� �����
		for (int y = 0; y < i; y++) {

			SIT[0][y] = studSIT[y];


		}


	}
	//��� ���������� �� 6 ��� 7
	else if (i > 5 && i < 8) {
		//������� �� 2
		grupiSIT = 2;
		//������� ����� �� ��� 3�� �������� � �� �������� ����� �� ������
		for (int y = 0; y < 3; y++) {

			SIT[0][y] = studSIT[y];


		}
		//���������� ����������, ����� ���������� ����������� �� ���������� �� ����� ����� �� ������� ������ � ������� ������ �����
		int br3 = 2;
		//� ���������� ���� �� 6 ��� 7, �� ���������� ��� ������� ����� �� �� 3 ��� 4
		for (int y = 0; y < i - 3; y++) {
			br3++;

			SIT[1][y] = studSIT[br3];


		}



	}
	//����� �������� ��� ���������� �� ����� 11, ������ � ���������� � ���� ������ �� ��� 3 ����� � � ������ �� ��� ���� 3 ��������
	if (i == 11) {
		grupiSIT = 3;
		int br3 = -1;
		//�������� �������
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

	//������ ���������� �� ���� 7 � 27
	else if (i > 7 && i <= 27 && i != 11) {
		//������� �� �������, ������ �� �������� ������� � 4 ������
		grupiSIT = i / 4;
		int br3 = -1;
		for (int y1 = 0; y1 < grupiSIT + 1; y1++) {

			//������ ������ ����� �� �������� �� �� ������ � ����� �� ������ �� 3, �� ������� �������� ����� � 4 �������� � �� ��������� ��� ����������
			if (left >= 4) {
				left -= 4;

				for (int y = 0; y < 4; y++) {
					br3++;

					SIT[y1][y] = studSIT[br3];


				}


			}

			//��� �� �������� ��-����� �� 4, �� ��� ��� ��� �������� �� �������� � �����
			else if (left > 0) {
				//����� �����, ����� ������� ������� �� �� 4�� �������� � 5-��
				for (int y1 = 0; y1 < left; y1++) {
					br3++;

					SIT[y1][4] = studSIT[br3];

				}

			}

		}



	}
	//��� ���������� �� ��� 27
	else if (i >= 28 && i <= 30) {
		//������� ������������ ���� �� 6
		grupiSIT = 6;
		//�������� ��������� �� ���� �� ���������� � 27 � ����������
		int ostatuk = i - 27;
		int br3 = -1;
		//����� ����� � �������� ��� �� 4 �������� � ���� ������������ �� ���� ����� �� �������� 24 �������� � �������
		for (int y1 = 0; y1 < grupiSIT; y1++) {




			for (int y = 0; y < 4; y++) {
				br3++;

				SIT[y1][y] = studSIT[br3];

			}


		}

		//3+�������� ������������ ���� �� ���������� ����� ������ �� �� �������
		//������ ���� ����� ������� 3+������� �� 6-�� ������� � 5�� �������
		for (int y1 = 0; y1 < 3 + ostatuk; y1++) {
			br3++;

			SIT[y1][4] = studSIT[br3];




		}



	}
	//������ ����� � �� ����������� ���
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


//������� �� ����������� �� ���������� �� ����� ������������ �� �����
void outputpouspeh(int i, int k, student studSIT[], student studKST[]) {
	//���������� �����, � ����� �� ������ ������ �������� �� ����� ������
	student studobshto[60];
	student help;
	boolean flag = true;
	//�������� ������ �������� �� ��� � ��� � ����� �����
	for (int y = 0; y < i; y++) {

		studobshto[y] = studSIT[y];

		//�������� � ������ �����
		studobshto[y].srus = (studSIT[y].bp + studSIT[y].mat + studSIT[y].fiz + studSIT[y].el + studSIT[y].web) / 5.0;
	}
	int br3 = 0;
	for (int y = i; y < i + k; y++) {

		studobshto[y] = studKST[br3];

		studobshto[y].srus = (studKST[br3].bp + studKST[br3].mat + studKST[br3].fiz + studKST[br3].el + studKST[br3].web) / 5.0;
		br3++;
	}
	//� ������ �� ��������� �������� ������ �������� �� ����� �����
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




	//�������� ������� �� �������
	for (int y = 0; y < i + k; y++) {

		cout << "�����������:";
		cout << studobshto[y].specialnost << endl;
		cout << "��� � �������:";
		cout << studobshto[y].ime << endl;
		cout << "������ �����:";
		cout << studobshto[y].srus << endl;
		cout << "���������� �����:";
		cout << studobshto[y].faknomer << endl;
		cout << "����� � ������ �� ������� (������ �����.������):";
		cout << studobshto[y].mesec << "." << studobshto[y].godina << endl;
		cout << "������ �� ����������:";
		cout << studobshto[y].mat << endl;
		cout << "������ �� ��:";
		cout << studobshto[y].bp << endl;
		cout << "������ �� ���������:";
		cout << studobshto[y].fiz << endl;
		cout << "������ �� ���:";
		cout << studobshto[y].web << endl;
		cout << "������ �� �����������:";
		cout << studobshto[y].el << endl;
		cout << endl;
	}














}






//������� �� ��������� ���� �� ���������� � ������� ������ �����

void outputUspehNad5i50(int i, int k, student studSIT[], student studKST[]) {

	//�� ����� ������� (� ������ �� ����. ���) ��  ������ ������� ����� � ��� � ��� 5.499 ( �� �� �� ����� ������� � double), ��� �� �������
	for (int y = 0; y < i; y++) {
		double current = (studSIT[y].bp + studSIT[y].mat + studSIT[y].fiz + studSIT[y].el + studSIT[y].web) / 5.0;
		if (current > 5.499) {
			cout << "�����������:";
			cout << studSIT[y].specialnost << endl;
			cout << "��� � �������:";
			cout << studSIT[y].ime << endl;
			cout << "������ �����:";
			cout << current << endl;
			cout << "���������� �����:";
			cout << studSIT[y].faknomer << endl;
			cout << "����� � ������ �� ������� (������ �����.������):";
			cout << studSIT[y].mesec << "." << studSIT[y].godina << endl;
			cout << "������ �� ����������:";
			cout << studSIT[y].mat << endl;
			cout << "������ �� ��:";
			cout << studSIT[y].bp << endl;
			cout << "������ �� ���������:";
			cout << studSIT[y].fiz << endl;
			cout << "������ �� ���:";
			cout << studSIT[y].web << endl;
			cout << "������ �� �����������:";
			cout << studSIT[y].el << endl;
			cout << endl;

		}
	}

	//������ �� ������ � �� ���
	for (int y = 0; y < k; y++) {
		double current = (studKST[y].bp + studKST[y].mat + studKST[y].fiz + studKST[y].el + studKST[y].web) / 5.0;
		if (current >= 5.499) {
			cout << "�����������:";
			cout << studKST[y].specialnost << endl;
			cout << "��� � �������:";
			cout << studKST[y].ime << endl;
			cout << "������ �����:";
			cout << current << endl;
			cout << "���������� �����:";
			cout << studKST[y].faknomer << endl;
			cout << "����� � ������ �� ������� (������ �����.������):";
			cout << studKST[y].mesec << "." << studKST[y].godina << endl;
			cout << "������ �� ����������:";
			cout << studKST[y].mat << endl;
			cout << "������ �� ��:";
			cout << studKST[y].bp << endl;
			cout << "������ �� ���������:";
			cout << studKST[y].fiz << endl;
			cout << "������ �� ���:";
			cout << studKST[y].web << endl;
			cout << "������ �� �����������:";
			cout << studKST[y].el << endl;
			cout << endl;

		}








	}
}







//������� �� �������� �� ������� �� ����� � ����������
void fromFile(int& i, int& k, student studSIT[], student studKST[]) {
	fstream f;

	f.open("FailSDanni.txt", ios::out | ios::in | ios::app);
	//��� ������ � ������ ����� � ������� if
	if (f.peek() == ifstream::traits_type::eof()) {
		cout << "������ � ������." << endl;
	}
	//��� �� � ������, ��� �� ��� �� ������� ������� �� ����� � �������� �� ����� ������������
	else {
		cout << "������� ���� ����������� �������." << endl;

		f >> i;
		f >> k;
		int brsit = 0;
		int brkst = 0;

		for (int y = 0; y < i + k; y++) {
			string c = "";
			f >> c;
			if (c == "���") {
				studSIT[brsit].specialnost = "���";
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



			if (c == "���") {
				studKST[brkst].specialnost = "���";
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




//������� �� ��������� �� ������������ �� ���������� ��� ����
void save(int i, int k, student studSIT[], student studKST[]) {
	cout << "������ ���� ������� �������." << endl;
	cout << endl;
	fstream f;
	//������ �� ����� ���� , ������� �� ���� ������� ���� �� ��������
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
	cout << "��������� ���� ���� ������� �������." << endl;
	cout << endl;
	fstream f;
	//������ �� ����� ���� , ������� �� ���� ������� ���� �� ��������
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
//��������� �� ���-������� �������� �� ��� � ���
void outputNaiDoburStudent(int i, int k, student studSIT[], student studKST[]) {
	double maxSIT = 0;
	double maxKST = 0;
	//������� ����������� ������ �����
	for (int y = 0; y < i; y++) {
		double current = (studSIT[y].bp + studSIT[y].mat + studSIT[y].fiz + studSIT[y].el + studSIT[y].web) / 5;
		if (current > maxSIT) {
			maxSIT = current;

		}

	}
	//�������� ������ �������� �� ������ � ��� ������� ����� �� � ����� �� ����������� �� ��������( ��� ��� ������� ������ � ������� �����, ����� ���� �� ��� �� �������)
	for (int y = 0; y < i; y++) {
		double current = (studSIT[y].bp + studSIT[y].mat + studSIT[y].fiz + studSIT[y].el + studSIT[y].web) / 5;
		if (current == maxSIT) {
			cout << "�����������:";
			cout << studSIT[y].specialnost << endl;
			cout << "��� � �������:";
			cout << studSIT[y].ime << endl;
			cout << "������ �����:";
			cout << current << endl;
			cout << "���������� �����:";
			cout << studSIT[y].faknomer << endl;
			cout << "����� � ������ �� ������� (������ �����.������):";
			cout << studSIT[y].mesec << "." << studSIT[y].godina << endl;
			cout << "������ �� ����������:";
			cout << studSIT[y].mat << endl;
			cout << "������ �� ��:";
			cout << studSIT[y].bp << endl;
			cout << "������ �� ���������:";
			cout << studSIT[y].fiz << endl;
			cout << "������ �� ���:";
			cout << studSIT[y].web << endl;
			cout << "������ �� �����������:";
			cout << studSIT[y].el << endl;
			cout << endl;

		}

	}


	//������ ����� � �� ���

	for (int y = 0; y < k; y++) {
		double current = (studKST[y].bp + studKST[y].mat + studKST[y].fiz + studKST[y].el + studKST[y].web) / 5;
		if (current > maxKST) {
			maxKST = current;

		}

	}


	for (int y = 0; y < k; y++) {
		double current = (studKST[y].bp + studKST[y].mat + studKST[y].fiz + studKST[y].el + studKST[y].web) / 5;
		if (current == maxKST) {

			cout << "�����������:";
			cout << studKST[y].specialnost << endl;
			cout << "��� � �������:";
			cout << studKST[y].ime << endl;
			cout << "������ �����:";
			cout << current << endl;
			cout << "���������� �����:";
			cout << studKST[y].faknomer << endl;
			cout << "����� � ������ �� ������� (������ �����.������):";
			cout << studKST[y].mesec << "." << studKST[y].godina << endl;
			cout << "������ �� ����������:";
			cout << studKST[y].mat << endl;
			cout << "������ �� ��:";
			cout << studKST[y].bp << endl;
			cout << "������ �� ���������:";
			cout << studKST[y].fiz << endl;
			cout << "������ �� ���:";
			cout << studKST[y].web << endl;
			cout << "������ �� �����������:";
			cout << studKST[y].el << endl;
			cout << endl;

		}

	}







}

//��������� �� �������� ��������� �� �������
void outputpovuzrast(int i, int k, student studSIT[], student studKST[]) {
	//����� ��� �����, � ����� ������ ������ �������� �� ����� ������
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
	//�� ������ �� ��������� �������� ���������� ����� �� ������
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
	//���� ���� �� �������� �� ������ � ��� ���� ���� �� ��������� �� ������ ������������, �� ������������ � ���������� �������
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
	//�������� ����������
	for (int y = 0; y < i + k; y++) {

		cout << "�����������:";
		cout << studobshto[y].specialnost << endl;
		cout << "��� � �������:";
		cout << studobshto[y].ime << endl;
		cout << "���������� �����:";
		cout << studobshto[y].faknomer << endl;
		cout << "����� � ������ �� ������� (������ �����.������):";
		cout << studobshto[y].mesec << "." << studobshto[y].godina << endl;
		cout << "������ �� ����������:";
		cout << studobshto[y].mat << endl;
		cout << "������ �� ��:";
		cout << studobshto[y].bp << endl;
		cout << "������ �� ���������:";
		cout << studobshto[y].fiz << endl;
		cout << "������ �� ���:";
		cout << studobshto[y].web << endl;
		cout << "������ �� �����������:";
		cout << studobshto[y].el << endl;
		cout << endl;
	}


}
//const int PI 3.14
//#define PI 3.14
//#define ����� ������������ �� ������ ����������� ��� ����������� ��������� � ������������ ��������(3.14) �� ����� �� �����������.
//cout<<hex<<10;








//��������� �� ���������� � ������� �� ��
void outputWith6poBP(int i, int k, student studSIT[], student studKST[]) {

	//���������� �� ����� ������� ���� �������� �� � >=5.499 � ��� ��, �� ��������
	for (int y = 0; y < i; y++) {
		if (studSIT[y].bp >= 5.499) {

			cout << "�����������:";
			cout << studSIT[y].specialnost << endl;
			cout << "��� � �������:";
			cout << studSIT[y].ime << endl;
			cout << "���������� �����:";
			cout << studSIT[y].faknomer << endl;
			cout << "����� � ������ �� ������� (������ �����.������):";
			cout << studSIT[y].mesec << "." << studSIT[y].godina << endl;
			cout << "������ �� ����������:";
			cout << studSIT[y].mat << endl;
			cout << "������ �� ��:";
			cout << studSIT[y].bp << endl;
			cout << "������ �� ���������:";
			cout << studSIT[y].fiz << endl;
			cout << "������ �� ���:";
			cout << studSIT[y].web << endl;
			cout << "������ �� �����������:";
			cout << studSIT[y].el << endl;
			cout << endl;
		}

	}


	//������ ����� � �� ���
	for (int y = 0; y < k; y++) {
		if (studKST[y].bp >= 5.499) {
			cout << "�����������:";
			cout << studKST[y].specialnost << endl;
			cout << "��� � �������:";
			cout << studKST[y].ime << endl;
			cout << "���������� �����:";
			cout << studKST[y].faknomer << endl;
			cout << "����� � ������ �� ������� (������ �����.������):";
			cout << studKST[y].mesec << "." << studSIT[y].godina << endl;
			cout << "������ �� ����������:";
			cout << studKST[y].mat << endl;
			cout << "������ �� ��:";
			cout << studKST[y].bp << endl;
			cout << "������ �� ���������:";
			cout << studKST[y].fiz << endl;
			cout << "������ �� ���:";
			cout << studKST[y].web << endl;
			cout << "������ �� �����������:";
			cout << studKST[y].el << endl;
			cout << endl;
		}
	}

}
//��������� �� n �� ���� ��������
void enterManyStudents(int& i, int& k, student studSIT[], student studKST[]) {
	cout << "�������� ���� ��������, ����� ������ �� ��������:";
	int n;
	//������� �� ���� �� ����������
	cin >> n;

	//������ �� ����� n ����
	for (int br = 1; br <= n; br++) {

		cout << "������� " << br << endl;
		cout << "�������� ����������� �� �������� (��� ��� ���)(�������� 0 ��� ������ �� �� ���� ����������� �� ��������) : " << endl;
		string s;

		cin >> s;
		//��� ������ ����������� �� ������ 0 , ����������� �� ����������
		if (s == "0") {
			cout << "����������� ����������� �� ��������." << endl;
			break;
		}
		//��� ���������� ����������� � ���:
		else if (s == "���") {
			//������ ���� �� ��� ���������� 30 �������, ��� �� ���� �� �� ������ 31 ������� ��� else
			if (i < 30) {

				//�� �������� � ���������� ������ � �������� �� ������� � ������ �� ���
				studSIT[i].specialnost = s;
				cin.ignore();
				cout << "�������� ��� � �������: ";
				getline(cin, studSIT[i].ime);
				cout << "�������� ���������� �����:";
				cin >> studSIT[i].faknomer;
				cout << "�������� ������ �� �������:";
				cin >> studSIT[i].godina;
				cout << "�������� ����� �� ������� � ����� (�������� �� ������ �������� 1, �� �������� 2 � �.�.) :";
				cin >> studSIT[i].mesec;
				cout << "�������� ������ �� ����������: ";
				cin >> studSIT[i].mat;
				cout << "�������� ������ �� ��: ";
				cin >> studSIT[i].bp;
				cout << "�������� ������ �� ���������: ";
				cin >> studSIT[i].fiz;
				cout << "�������� ������ �� ���: ";
				cin >> studSIT[i].web;
				cout << "�������� ������ �� �����������: ";
				cin >> studSIT[i].el;
				i++;
			}
			//��� �� �������� �� ������� 31 ������ �� ������� ��������:
			else {
				cout << "����������� ��� ���� ��� 30 �������." << endl;

			}
		}
		//������ � �� ���
		else if (s == "���") {
			if (k < 30) {


				studKST[k].specialnost = s;
				cin.ignore();
				cout << "�������� ��� � �������:";
				getline(cin, studKST[k].ime);
				cout << "�������� ���������� �����:";
				cin >> studKST[k].faknomer;
				cout << "�������� ������ �� �������:";
				cin >> studKST[k].godina;
				cout << "�������� ����� �� ������� � ����� (�������� �� ������ �������� 1, �� �������� 2 � �.�.) :";
				cin >> studKST[k].mesec;
				cout << "�������� ������ �� ����������: ";
				cin >> studKST[k].mat;
				cout << "�������� ������ �� ��: ";
				cin >> studKST[k].bp;
				cout << "�������� ������ �� ���������: ";
				cin >> studKST[k].fiz;
				cout << "�������� ������ �� ���: ";
				cin >> studKST[k].web;
				cout << "�������� ������ �� �����������: ";
				cin >> studKST[k].el;
				k++;
			}
			else {
				cout << "����������� ��� ���� ��� 30 �������." << endl;
			}

		}
		//��� �������� ����������� �� � ��� ���� ��� , ���� � � ���������� ����������� �� ������� �������� ��������� � ������ �� ������ �� ����� � 1
		else {
			cout << "�������� ������� �����������." << endl;
			cout << endl;
			br--;
		}



	}

}

//��������� �� �������� �� �������� �����������
void output(int i, int k, student studSIT[], student studKST[]) {
	cout << "�������� �� ��� ����������� ������ �� �������� ���������� (��� ��� ���): " << endl;
	string s;
	cin >> s;


	if (s == "���") {
		int y = 0;
		while (y < i) {
			//����� ����, �� �� �� ����� ����� �� 5 � �� �� �������� ���� 5 �������� �� ��������
			for (int y1 = 0; y1 < 5; y1++) {
				//��� ������ ����� ��-����� �� ���� �� ���������� ����������� �����
				if (y >= i) {
					break;
				}

				cout << "�����������:";
				cout << studSIT[y].specialnost << endl;
				cout << "��� � �������:";
				cout << studSIT[y].ime << endl;
				cout << "���������� �����:";
				cout << studSIT[y].faknomer << endl;
				cout << "����� � ������ �� ������� (������ �����.������):";
				cout << studSIT[y].mesec << "." << studSIT[y].godina << endl;
				cout << "������ �� ����������:";
				cout << studSIT[y].mat << endl;
				cout << "������ �� ��:";
				cout << studSIT[y].bp << endl;
				cout << "������ �� ���������:";
				cout << studSIT[y].fiz << endl;
				cout << "������ �� ���:";
				cout << studSIT[y].web << endl;
				cout << "������ �� �����������:";
				cout << studSIT[y].el << endl;
				cout << endl;
				y++;
			}
			//��� ������ ����� ��-����� �� ���� �� ����������, �������� ���� ���� �� �� �������
			if (y >= i) {
				break;
			}
			//������� �� n, �� �� �� ����� �� ���������� �������� �� ��������, ��� ����� ���� ���� ������� ������ ��������, �� �� ��������� � �����������
			cout << "�������� n �� �� ������� �� ���������� ��������, ��� ������� � �� � ������ ����� n, �� �� ���������� � �����������:";
			string s1;
			cin >> s1;

			if (s1 == "n") {
				continue;
			}
			else {
				cout << "��� ����������� � �����������." << endl;
				break;
			}


		}
	}
	//������ ����� � �� ����. ���
	else if (s == "���") {
		int y = 0;

		while (y < k) {
			for (int y1 = 0; y1 < 5; y1++) {
				if (y >= k) {
					break;
				}
				cout << "�����������:";
				cout << studKST[y].specialnost << endl;
				cout << "��� � �������:";
				cout << studKST[y].ime << endl;
				cout << "���������� �����:";
				cout << studKST[y].faknomer << endl;
				cout << "����� � ������ �� ������� (������ �����.������):";
				cout << studKST[y].mesec << "." << studKST[y].godina << endl;
				cout << "������ �� ����������:";
				cout << studKST[y].mat << endl;
				cout << "������ �� ��:";
				cout << studKST[y].bp << endl;
				cout << "������ �� ���������:";
				cout << studKST[y].fiz << endl;
				cout << "������ �� ���:";
				cout << studKST[y].web << endl;
				cout << "������ �� �����������:";
				cout << studKST[y].el << endl;
				cout << endl;
				y++;
			}
			if (y >= k) {
				break;
			}

			cout << "�������� n �� �� ������� �� ���������� ��������, ��� ������� � �� � ������ ����� n, �� �� ���������� � �����������:";
			string s1;
			cin >> s1;

			if (s1 == "n") {
				continue;
			}
			else {
				cout << "��� ����������� � �����������." << endl;
				break;
			}
		}
	}
	//��� ���������� ����������� �� ����������, ��������� �� �������� ��������
	else {
		cout << "�������� ������� �����������." << endl;
		output(i, k, studSIT, studKST);
	}
}

//��������� �� ���� 1 �������
void enterOneStudent(int& i, int& k, student studSIT[], student studKST[]) {
	cout << "�������� ����������� �� �������� (��� ��� ���): " << endl;
	string s;

	cin >> s;
	//������� �� ������������� � �� �������� ����������� �������� �� �������� � ���������� �����
	if (s == "���") {
		if (i < 30) {


			studSIT[i].specialnost = s;
			cin.ignore();
			cout << "�������� ��� � �������: ";
			getline(cin, studSIT[i].ime);
			cout << "�������� ���������� �����:";
			cin >> studSIT[i].faknomer;
			cout << "�������� ������ �� �������:";
			cin >> studSIT[i].godina;
			cout << "�������� ����� �� ������� � ����� (�������� �� ������ �������� 1, �� �������� 2 � �.�.) :";
			cin >> studSIT[i].mesec;
			cout << "�������� ������ �� ����������: ";
			cin >> studSIT[i].mat;
			cout << "�������� ������ �� ��: ";
			cin >> studSIT[i].bp;
			cout << "�������� ������ �� ���������: ";
			cin >> studSIT[i].fiz;
			cout << "�������� ������ �� ���: ";
			cin >> studSIT[i].web;
			cout << "�������� ������ �� �����������: ";
			cin >> studSIT[i].el;
			i++;
		}
		else {
			cout << "����������� ��� ���� ��� 30 �������." << endl;

		}
	}
	else if (s == "���") {
		if (k < 30) {


			studKST[k].specialnost = s;
			cin.ignore();
			cout << "�������� ��� � �������: ";
			getline(cin, studKST[i].ime);
			cout << "�������� ���������� �����:";
			cin >> studKST[k].faknomer;
			cout << "�������� ������ �� �������:";
			cin >> studKST[k].godina;
			cout << "�������� ����� �� ������� � ����� (�������� �� ������ �������� 1, �� �������� 2 � �.�.) :";
			cin >> studKST[k].mesec;
			cout << "�������� ������ �� ����������: ";
			cin >> studKST[k].mat;
			cout << "�������� ������ �� ��: ";
			cin >> studKST[k].bp;
			cout << "�������� ������ �� ���������: ";
			cin >> studKST[k].fiz;
			cout << "�������� ������ �� ���: ";
			cin >> studKST[k].web;
			cout << "�������� ������ �� �����������: ";
			cin >> studKST[k].el;
			k++;
		}
		else {
			cout << "����������� ��� ���� ��� 30 �������." << endl;
		}

	}
	//��� ���������� ����������� �� ����������, ��������� �� �������� ������
	else {
		cout << "�������� ������� �����������." << endl;
		enterOneStudent(i, k, studSIT, studKST);
	}

}

//������� �� ����� �� ������
int entry() {
	int n = 0;
	while (true) {
		//������ �� �� ������ ������� �����, ��������� ����� ����������� ��� �����������
		cout << "������ �����:";
		cin >> n;
		if (n < 1 || n>15) {
			cout << "�������� ������� �����" << endl;
		}
		//��� ������ � �������, ��� �� ����� ��� main ���������
		else {
			return n;
		}

	}



}


//const int PI 3.14
//#define PI 3.14
//#define ����� ������������ �� ������ ����������� ��� ����������� ��������� � ������������ ��������(3.14) �� ����� �� �����������.
//cout<<hex<<10;








