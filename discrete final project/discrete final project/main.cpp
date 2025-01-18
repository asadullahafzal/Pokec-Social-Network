#include<iostream>
#include<string>
#include"Graph.h"
using namespace std;
void welcome();
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int main()
{
	welcome();
	system("pause");
	system("CLS");

	graph_imp obj;
	cout << "-------------------Extracting Data------------------ " << endl;
	obj.Read_From_file_profile();
	cout << "Success" << endl;
	obj.Read_From_file_relationship();
	cout << "Success" << endl;
	cout << endl;
	system("pause");
	system("CLS");


	bool x = true;
	string choice, choice2;
	int id1, id2;
	while (x == true)
	{
		SetConsoleTextAttribute(h, 11);
		cout << "\n\n\n";
		cout << "\t\tA) For Proposition (Implication and Biconditional )" << endl;
		cout << "\t\tB) Quantifiers " << endl;
		cout << "\t\tC) Sets (Union, Intersection, Complement)" << endl;
		cout << "\t\tD) Venn Diagrams:" << endl;
		cout << "\t\tE) Functions (Domain, Range, Inverse, Into, Onto) " << endl;
		cout << "\t\tF) Relations (Reflexive, Transitive, Symmetric)" << endl;
		cout << "\t\tG) Induction" << endl;
		cout << "\t\tH) Permutations and Combinations " << endl;
		cout << "\t\tI) Trees" << endl;
		cout << "\t\tJ) Graphs" << endl;
		cout << "\t\tK) To exit " << endl;

		cout << "\nEntrer : ";
		cin >> choice;
		if (choice == "A" || choice == "a")
		{

			Sleep(100);
			system("CLS");
			SetConsoleTextAttribute(h, 6);
			cout << "Please submit detalis to checck Implication and Biconditional" << endl;
			cout << "Enter Firsrt Id : ";
			cin >> id1;
			cout << "Enter Second ID : ";
			cin >> id2;
			SetConsoleTextAttribute(h, 2);
			cout << "\n-------------------Implication------------------------" << endl;
			obj.Check_implication(id1, id2);
			cout << endl << endl;
			cout << "\n-------------------Biconditional------------------------" << endl;
			obj.Check_biconditional(id1, id2);
			cout << endl << endl;
			system("pause");
			system("CLS");

		}
		else if (choice == "B" || choice == "b")
		{
			SetConsoleTextAttribute(h, 3);
			cout << "\n\n--------------Existentail Quantifier-----------------" << endl;
			obj.Check_existential_Quantifier();
			cout << "\n--------------Universal Quantifier-----------------" << endl;
			obj.Check_Universal_quantifier();
			cout << endl << endl;
			system("pause");
			system("CLS");
		}
		else if (choice == "C" || choice == "c")
		{
			SetConsoleTextAttribute(h, 7);
			obj.sets();
			cout << endl << endl;
			system("pause");
			system("CLS");
		}
		else if (choice == "D" || choice == "d")
		{
			SetConsoleTextAttribute(h, 4);
			obj.Venn_Diagram();
			cout << endl << endl;
			system("pause");
			system("CLS");
		}
		else if (choice == "E" || choice == "e")
		{
			SetConsoleTextAttribute(h, 2);
			cout << "1) To check domain and Range " << endl;
			cout << "2) To check Onto Function" << endl;
			cout << "3) To check one to one Function" << endl;
			cout << "Enter : ";
			cin >> choice2;

			if (choice2 == "1")
			{
				Sleep(300);
				system("CLS");
				cout << "--------------Domain and Range -----------------" << endl << endl;
				SetConsoleTextAttribute(h, 5);
				obj.Domain_range();
			}
			else if (choice2 == "2")
			{
				Sleep(300);
				system("CLS");
				cout << "--------------Onto Function Checking ---------------" << endl << endl;
				SetConsoleTextAttribute(h, 4);
				obj.onto_check();
			}
			else if (choice2 == "3")
			{
				Sleep(300);
				system("CLS");
				cout << "--------------One to One Checking ---------------" << endl << endl;
				SetConsoleTextAttribute(h, 1);
				obj.one_to_one();
			}
			else
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\nWrong Choice " << endl;
			}
			cout << endl << endl;
			system("pause");
			system("CLS");
		}
		else if (choice == "F" || choice == "f")
		{
			SetConsoleTextAttribute(h, 7);
			cout << "1) To check Reflexive  " << endl;
			cout << "2) To check Symmetric  " << endl;
			cout << "3) To check Transitive " << endl;
			cout << "Enter : ";
			cin >> choice2;
			if (choice2 == "1")
			{
				Sleep(300);
				system("CLS");
				cout << "--------------Reflexive-----------------" << endl << endl;
				SetConsoleTextAttribute(h, 6);
				obj.check_reflexive();
			}
			else if (choice2 == "2")
			{
				Sleep(300);
				system("CLS");
				cout << "----------------Symmetric ---------------" << endl << endl;
				SetConsoleTextAttribute(h, 2);
				obj.check_symmetric();
			}
			else if (choice2 == "3")
			{
				Sleep(300);
				system("CLS");
				cout << "------------------Transitive ---------------" << endl << endl;
				SetConsoleTextAttribute(h, 3);
				obj.check_transitive();
			}
			else
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\nWrong Choice " << endl;
			}

			cout << endl << endl;
			system("pause");
			system("CLS");
		}
		else if (choice == "G" || choice == "g")
		{
			SetConsoleTextAttribute(h, 5);
			Sleep(300);
			system("CLS");
			cout << "------------------ Induction -----------------" << endl << endl;
			obj.Induction();
			cout << endl << endl;
			system("pause");
			system("CLS");
		}
		else if (choice == "H" || choice == "h")
		{
			cout << "1) For Permutations  " << endl;
			cout << "2) For Counting      " << endl;
			cout << "Enter : ";
			cin >> choice2;
			if (choice2 == "1")
			{
				Sleep(300);
				system("CLS");
				cout << "------------------- Permutation-----------------" << endl << endl;
				obj.sub_group_permutations();
			}
			else if (choice2 == "2")
			{
				Sleep(300);
				system("CLS");
				cout << "------------------ Counting ---------------" << endl << endl;
				obj.counting();
			}
			else
			{
				cout << "\nWrong Choice " << endl;
			}

			cout << endl << endl;
			system("pause");
			system("CLS");

		}

		else if (choice == "I" || choice == "i")
		{
			SetConsoleTextAttribute(h, 7);
			int User_id;
			cout << "\nEnter the Id of user which you passsed as root and make tree of Friends " << endl;
			cout << "Enter : ";
			cin >> User_id;
			SetConsoleTextAttribute(h, 5);
			obj.Tree_implemnt(User_id);
			cout << endl << endl;
			system("pause");
			system("CLS");
		}
		else if (choice == "J" || choice == "j")
		{
			SetConsoleTextAttribute(h, 7);
			Sleep(300);
			system("CLS");
			cout << "--------------------Tree-------------------" << endl;
			cout << "1) For Bipartit Braph " << endl;
			cout << "2) For Minimum Spanning Tree  " << endl;
			cout << "Enter : ";
			cin >> choice2;
			if (choice2 == "1")
			{
				Sleep(300);
				system("CLS");
				cout << "------------------- Bipartit-----------------" << endl << endl;
				SetConsoleTextAttribute(h, 6);
				obj.IS_bipartite();
			}
			else if (choice2 == "2")
			{
				Sleep(300);
				system("CLS");
				cout << "------------------ Minimum Spanning Tree ---------------" << endl << endl;
				SetConsoleTextAttribute(h, 3);
				obj.prims_minimum_spanning_Tree();
			}
			else
			{
				SetConsoleTextAttribute(h, 4);
				cout << "\nWrong Choice " << endl;
			}

			cout << endl << endl;
			system("pause");
			system("CLS");
		}
		else if (choice == "K" || choice == "k")
		{
			x = false;
		}
		else
		{
			SetConsoleTextAttribute(h, 4);
			cout << "Wrong Choice : " << endl;
			cout << endl << endl;
			system("pause");
			system("CLS");
		}
	}
	system("pause");
	return 0;
}


void welcome()
{
	cout << endl;
	int row = 12;
	int col = 24;
	for (int i = 1; i <= row; i++)
	{
		cout << "\t\t\t";
		for (int j = 1; j <= col; j++)
		{
			if (i == 1 || j == 1 || i == row || j == col)
			{
				SetConsoleTextAttribute(h, 6);
				cout << "- ";
				Sleep(100);
			}
			else
				cout << "  ";

		}
		if (i == row / 2)
		{
			cout << endl;
			Sleep(200);
			SetConsoleTextAttribute(h, 7);
			cout << "\t\t\t|- - - - - - - - - - - - - - - - - - - - - - -|" << endl << endl;;
			Sleep(100);
			SetConsoleTextAttribute(h, 11);
			cout << "\t\t\t|          Social Network System              | " << endl << endl;
			Sleep(300);
			SetConsoleTextAttribute(h, 7);
			cout << "\t\t\t| - - - - - - - - - - - - - - - -  - - - - - -|" << endl;
			Sleep(100);

		}

		if (i == (row / 2))
		{
			cout << endl;
			Sleep(200);
			cout << endl;
			SetConsoleTextAttribute(h, 7);
			cout << "\t\t\t|- - - - - - - - - - - - - - - - - - - - - - -|" << endl << endl;
			Sleep(100);
			SetConsoleTextAttribute(h, 11);
			cout << "\t\t\t|              Designed by:  Ali Hassan       | " << endl;
			cout << "\t\t\t|                             Asadullah       |           " << endl << endl;
			Sleep(200);
			SetConsoleTextAttribute(h, 11);
			cout << "\t\t\t|              Roll no   : 23F-0660           | " << endl;
			cout << "\t\t\t|                           23F-0693          | " << endl;
			Sleep(300);
			SetConsoleTextAttribute(h, 7);
			cout << "\t\t\t| - - - - - - - - - - - - - - - -  - - - - - -|" << endl;



			Sleep(100);

		}
		cout << endl;

	}
}
