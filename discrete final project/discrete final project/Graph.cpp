#include<iostream>
#include<string>
#include"Graph.h"
#include<queue>
#include<ctime>
#include<stack>
using namespace std;

//Node of Graph
Graph_node::Graph_node() :last_login(), registration()
{
	next = NULL;
	user_id = com_percentage = age = 0;
	public_r = gender = 0;
}

//Setter Function to set Graph node data
void Graph_node::set_grah_data(int id, int per, int ages, bool pub, bool gen, date_time LL, date_time regis, string reg)
{
	user_id = id;
	com_percentage = per;
	age = ages;
	public_r = pub;
	gender = gen;
	last_login = LL;
	registration = regis;
	region = reg;
	next = NULL;
}

//Main constructer of garph class
graph_imp::graph_imp()
{
	counter = 0;
	Graph_size = 100000;
	list = new Graph_node * [Graph_size];
	for (int i = 0; i < Graph_size; i++)
	{
		list[i] = NULL;
	}
	Id_list = new int[Graph_size];
	com_percenatge_list = new int[Graph_size];
	Person = 2;
	Edges = 2;
}

void graph_imp::display()
{
	cout << "AGE : " << "\t" << "Completion_percentage " << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << list[i]->age << "    " << list[i]->com_percentage << endl;
	}

}

//Function to add user as a vertex in the graph
void graph_imp::add_vertex(Graph_node* vertex)
{
	if (counter < Graph_size)
	{
		list[counter] = vertex;
		Id_list[counter] = vertex->user_id;
		com_percenatge_list[counter] = vertex->com_percentage;
		counter++;
	}
}

//Serach Function to serach a user in the graph
int graph_imp::search_id(int id)
{
	for (int i = 0; i < counter; i++)
	{
		if (list[i]->user_id == id)
		{
			return i;
		}
	}
	return -1;
}

//Function to add directed edge in the Graph
void graph_imp::add_edge(int from_id, int to_id)
{
	int from_index = search_id(from_id);
	int to_index = search_id(to_id);
	if (from_index == -1)
	{
		return;
	}
	if (to_index == -1)
	{
		return;
	}

	Graph_node* newnode = new Graph_node;
	newnode->set_grah_data(to_id, list[to_index]->com_percentage, list[to_index]->age, list[to_index]->public_r, list[to_index]->gender, list[to_index]->last_login, list[to_index]->registration, list[to_index]->region);
	newnode->next = list[from_index]->next;
	list[from_index]->next = newnode;
}

//Function to read the data of the POkec User from the txt file

void graph_imp::Read_From_file_profile()
{
	ifstream fin;
	fin.open("soc-pokec-profiles.txt");
	if (!fin.is_open())
	{
		cout << "File cannot be opened " << endl;
	}
	else
	{
		cout << "File is open " << endl;
	}

	int id, per, ages, day, mon, year, hour, min, sec;
	bool pub, gen;
	date_time LL, regis;
	string reg;
	string extra;
	char y;

	int cou = 0;

	for (int i = 0; i < Person; i++)
	{

		//Reading Id,Public,completion_percentage,generation 
		fin >> id;

			fin >> pub;
			fin >> per;
			fin >> gen;

			//Reding extra data like tab
			getline(fin, extra, '\t');

			/*Now Reading Region untill comma*/
			getline(fin, reg, ',');

			/*Now readoing extra information of region*/
			getline(fin, extra, '\t');


			extra = "\0";

			/*Now Reading Login date and time*/
			getline(fin, extra, '-');
			year = stoi(extra);

			getline(fin, extra, '-');
			mon = stoi(extra);

			getline(fin, extra, ' ');
			day = stoi(extra);

			getline(fin, extra, ':');
			hour = stoi(extra);

			getline(fin, extra, ':');
			min = stoi(extra);

			getline(fin, extra, '.');
			sec = stoi(extra);

			LL.set_date(day, mon, year, hour, min, sec);


			/*Now Rrading Registration Date*/
			getline(fin, extra, '\t');

			getline(fin, extra, '-');
			year = stoi(extra);

			getline(fin, extra, '-');
			mon = stoi(extra);

			getline(fin, extra, ' ');
			day = stoi(extra);

			getline(fin, extra, ':');
			hour = stoi(extra);

			getline(fin, extra, ':');
			min = stoi(extra);

			getline(fin, extra, '.');
			sec = stoi(extra);


			regis.set_date(day, mon, year, hour, min, sec);
			getline(fin, extra, '\t');
			//Reading age
			fin >> ages;
			getline(fin, extra, '\n');
			Graph_node* newnode = new Graph_node;

			/*Insert as a Vertex*/

			newnode->set_grah_data(id, per, ages, pub, gen, LL, regis, reg);
			add_vertex(newnode);
		}
}

//Function to read all the relationship as a edges from the txt file
void graph_imp::Read_From_file_relationship()
{

	ifstream fin;
	fin.open("soc-pokec-relationships.txt");
	if (!fin.is_open())
	{
		cout << "File cannot be opened " << endl;
	}
	else
	{
		cout << "File is open " << endl;
	}
	int to_id, fr_id;
	string str;
	for (int i = 0; i < Edges; i++)
	{
		fin >> fr_id;
		fin >> to_id;
		add_edge(fr_id, to_id);

	}
}

//Test Function to displayn all the users data

void graph_imp::test_display()
{
	cout << counter << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << "-----------" << i << "-----------------------" << endl;
		cout << list[i]->user_id << "  " << list[i]->public_r << "  " << list[i]->com_percentage << "  " << list[i]->gender;
		cout << "  " << list[i]->region << "  ";
		list[i]->last_login.display();
		cout << "  ";
		list[i]->registration.display();
		cout << "  " << list[i]->age << endl;
	}
}

//Function to implemt Implication condition

void graph_imp::Check_implication(int First_UI, int Second_UI)
{
	int First_index = search_id(First_UI);
	int Second_index = search_id(Second_UI);
	if (First_index == -1)
	{
		cout << "First ID is incorrect : " << endl;
	}
	if (Second_index == -1)
	{
		cout << "Second ID is incorrect : " << endl;
	}
	if (First_index != -1)
	{
		if (!list[First_index]->age >= 30)
		{
			cout << "Fisrts user age is not greater than 30";
			cout << "That's Why implication not hold true for : " << First_UI << endl;
		}
		else
		{
			if (!list[First_index]->com_percentage >= 50)
			{
				cout << First_UI << " Its age greater than 30 but not complete profile 50 %" << endl;
				cout << "That's Why implication not hold true " << endl;
			}
			else
			{

				cout << "For " << First_UI << " Implication Holds True " << endl;
				cout << "User_Id    Age     Completion Percentage " << endl;
				cout << list[First_index]->user_id << "\t    " << list[First_index]->age << "\t   " << list[First_index]->com_percentage << endl << endl;
			}

		}
	}
	cout << endl;

	if (Second_index != -1)
	{
		if (!list[Second_index]->age >= 30)
		{
			cout << "Second user age is not greater than 30";
			cout << "That's Why implication not hold true for : " << Second_UI << endl;
		}
		else
		{
			if (!list[Second_index]->com_percentage >= 50)
			{
				cout << Second_UI << " Its age greater than 30 but not complete profile 50 %" << endl;
				cout << "That's Why implication not hold true " << endl;
			}
			else
			{
				cout << "For " << Second_UI << " Implication Holds True " << endl;
				cout << "User Id    Age     Completion Percentage " << endl;
				cout << list[Second_index]->user_id << "\t     " << list[Second_index]->age << "\t    " << list[Second_index]->com_percentage << endl << endl;
			}

		}
	}
}


//Function to implemnt Biconditional
void graph_imp::Check_biconditional(int First_UI, int Second_UI)
{
	int First_index = search_id(First_UI);
	int Second_index = search_id(Second_UI);
	if (First_index == -1)
	{
		cout << "First ID is incorrect : " << endl;
	}
	if (Second_index == -1)
	{
		cout << "Second ID is incorrect : " << endl;
	}

	if (First_index != -1)
	{
		if (list[First_index]->public_r)
		{
			int login_year = list[First_index]->last_login.year;
			if (login_year == 2012)
			{
				cout << "Yes For " << First_UI << " Biconditional is hold true " << endl;
				cout << "User_Id    Public     Last Login" << endl;
				cout << list[First_index]->user_id << "\t     " << list[First_index]->public_r << "\t     ";
				list[First_index]->last_login.display();
				cout << endl << endl;
			}
			else
			{
				cout << list[First_index]->user_id << "\t     " << list[First_index]->public_r << "\t     ";
				list[First_index]->last_login.display();
				cout << First_UI << " is public but not login last year " << endl;
				cout << "So For " << First_UI << " Biconditional is not hold true " << endl;
			}
		}
		else
		{
			cout << "User_Id    Public     Last Login" << endl;
			cout << list[First_index]->user_id << "\t     " << list[First_index]->public_r << "\t     ";
			list[First_index]->last_login.display();
			cout << First_UI << " is not public " << endl;
			cout << "So For " << First_UI << " Biconditional is not hold true " << endl;

		}
	}
	cout << endl;
	if (Second_index != -1)
	{
		if (list[Second_index]->public_r)
		{
			int login_year = list[Second_index]->last_login.year;
			if (login_year == 2012)
			{
				cout << "Yes For " << Second_UI << " Biconditional is hold true " << endl;
				cout << "User Id    Public     Last Login" << endl;
				cout << list[Second_index]->user_id << "\t     " << list[Second_index]->public_r << "\t     ";
				list[Second_index]->last_login.display();
				cout << endl << endl;
			}
			else
			{
				cout << "User Id    Public     Last Login" << endl;
				cout << list[Second_index]->user_id << "\t     " << list[Second_index]->public_r << "\t     ";
				list[Second_index]->last_login.display();
				cout << endl << endl;
				cout << Second_UI << " is public but not login last year " << endl;
				cout << "So For " << Second_UI << " Biconditional is not hold true " << endl;
			}
		}
		else
		{
			cout << "User Id    Public     Last Login" << endl;
			cout << list[Second_index]->user_id << "\t     " << list[Second_index]->public_r << "\t     ";
			list[Second_index]->last_login.display();
			cout << endl << endl;
			cout << Second_UI << " is not public " << endl;
			cout << "So For " << Second_UI << " Biconditional is not hold true " << endl;

		}
	}

}

//Function to check existential Quantifier as given
void graph_imp::Check_existential_Quantifier()
{
	for (int i = 0; i < counter; i++)
	{
		if (list[i]->region == "zilinsky kraj" && list[i]->com_percentage > 70)
		{
			cout << "As " << list[i]->user_id << "  his region is zilinsky kraj and its profile is complete graeter than 70";
			cout << "\nUser Id : " << list[i]->user_id << endl;
			cout << "Completion Percentage : " << list[i]->com_percentage << endl;
			cout << "\nSo Existential Quantifier is hold true" << endl;
			return;
		}
	}

	cout << "As No meet the condition of Existential Quantifier";
	cout << "\nSo Existential Quantifier is not hold true" << endl;
}
//Function to check Universal  Quantifier as given
void graph_imp::Check_Universal_quantifier()
{
	for (int i = 0; i < counter; i++)
	{
		if (list[i]->age > 18)
		{
			if (list[i]->com_percentage < 50)
			{

				cout << "As " << list[i]->user_id << " is greater than 18 but profile not complete at least 50 % of profile  ";
				cout << "\nIts completion Percntage : " << list[i]->com_percentage << endl;
				cout << "Its age : " << list[i]->age << endl;
				cout << "\nSo Universal Quantifier is not hold true" << endl;
				return;
			}
		}
	}

	cout << "As All the Pokec user Graeter than 18 complete at least 50 % of profile ";
	cout << "\nSo Universal Quantifier is hold true" << endl;
}

//Function to display all the Venn Diagram Information 

void graph_imp::Venn_Diagram()
{
	int age_count = 0;
	int Public_count = 0;
	int region_count = 0;
	int Venn_count = 0;
	int A_U_B = 0;
	int A_U_C = 0;
	int A_U_B_U_C = 0;
	int B_U_C = 0;

	for (int i = 0; i < counter; i++)
	{
		if (list[i]->age > 30)
		{
			age_count++;
		}
		if (list[i]->public_r)
		{
			Public_count++;
		}
		if (list[i]->region == "zilinsky kraj")
		{
			region_count++;
		}

		if (list[i]->age > 30 && list[i]->public_r && list[i]->region == "zilinsky kraj")
		{
			A_U_B_U_C++;
		}
		if (list[i]->age > 30 && list[i]->public_r && list[i]->region != "zilinsky kraj")
		{
			A_U_B++;
		}
		if (list[i]->age > 30 && list[i]->region == "zilinsky kraj" && !list[i]->public_r)
		{
			A_U_C++;
		}
		if (list[i]->public_r && list[i]->region == "zilinsky kraj" && !(list[i]->age > 30))
		{
			B_U_C++;
		}
	}
	Sleep(500);
	system("CLS");
	cout << "-------------- Venn Diagram Information-------------------- : " << endl << endl;

	cout << "Age_geater than 30 set count is : " << age_count << endl;
	cout << "Public user set count is : " << Public_count << endl;
	cout << "Zilinsky region user set count is : " << region_count << endl;
	cout << "Lies in all sets are : " << A_U_B_U_C << endl;
	cout << "Lies in A,b set are  :" << A_U_B << endl;
	cout << "Lies in A,C set are  : " << A_U_C << endl;
	cout << "Lies in B,C set are  : " << B_U_C << endl;

	int A_user = age_count - A_U_B_U_C - A_U_B - A_U_C;
	int B_user = Public_count - A_U_B_U_C - A_U_B - B_U_C;
	int C_user = region_count - A_U_B_U_C - A_U_C - B_U_C;

	cout << "\nLies in only A set are : " << A_user << endl;
	cout << "\nLies in only B set are : " << B_user << endl;
	cout << "\nLies in only C set are : " << C_user << endl;
}


//Function to implemnt all the sets Information

void graph_imp::sets()
{
	graph_imp A_set;
	graph_imp B_set;
	int A_count = 0;
	int B_count = 0;
	/*Finding User for A set  */
	for (int i = 0; i < counter; i++)
	{
		if (list[i]->public_r)
		{
			A_set.add_vertex(list[i]);
			A_count++;
		}
	}

	/*Finding Users for B set*/
	for (int i = 0; i < counter; i++)
	{
		if (list[i]->region == "bratislavsky kraj")
		{
			B_set.add_vertex(list[i]);
			B_count++;
		}
	}
	string choice;
	cout << "Press A) To find A U B : " << endl;
	cout << "Press B) To find A intersection B : " << endl;
	cout << "Press C) To find A compliment : " << endl;
	cout << "Enter : ";
	cin >> choice;
	if (choice == "A" || choice == "a")
	{
		for (int i = 0; i < B_count; i++)
		{
			if (A_set.search_id(B_set.list[i]->user_id) == -1)
			{
				A_set.add_vertex(B_set.list[i]);

			}
		}
		Sleep(200);
		system("CLS");
		A_set.test_display();
		cout << endl;
		cout << "A uers  : " << A_count << endl;
		cout << "B users : " << B_count << endl;
		cout << "A U B users are : " << A_set.counter << endl;

	}
	else if (choice == "B" || choice == "b")
	{
		Sleep(200);
		system("CLS");
		graph_imp A_intersect_B;
		for (int i = 0; i < A_count; i++)
		{
			if (B_set.search_id(A_set.list[i]->user_id) != -1)
			{
				A_intersect_B.add_vertex(A_set.list[i]);
			}
		}
		Sleep(200);
		system("CLS");
		A_intersect_B.test_display();
		cout << endl;
		cout << "A uers  : " << A_count << endl;
		cout << "B users : " << B_count << endl;
		cout << "A intersection B users are : " << A_intersect_B.counter << endl;
	}
	else if (choice == "C" || choice == "c")
	{
		graph_imp U_set;
		U_set.list = list;
		U_set.counter = counter;
		graph_imp A_com;
		for (int i = 0; i < counter; i++)
		{
			if (A_set.search_id(U_set.list[i]->user_id) == -1)
			{
				A_com.add_vertex(U_set.list[i]);

			}
		}
		Sleep(200);
		system("CLS");
		A_com.test_display();
		cout << endl;
		cout << "Total in U : " << U_set.counter << endl;
		cout << "A uers  : " << A_count << endl;
		cout << "A compliment users are : " << A_com.counter << endl;
	}
	else
	{
		cout << "\nWrong Choice " << endl;
		cout << "Better LUck next time : " << endl;
	}

}
//
//Function to find the maximum number from the ARRAY
int graph_imp::Find_max(int* arr, int size)
{
	int maximun = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > maximun)
		{
			maximun = arr[i];
		}
	}
	return maximun;
}


//Function to find the mimnimum number from the ARRAY
int graph_imp::Find_min(int* arr, int size)
{
	int minimum = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < minimum)
		{
			minimum = arr[i];
		}
	}
	return minimum;
}

//Function to find the Domain and Range of the Function

void graph_imp::Domain_range()
{

	int id_min = Find_min(Id_list, counter);
	int id_max = Find_max(Id_list, counter);
	int Completion_min = Find_min(com_percenatge_list, counter);
	int Completion_max = Find_max(com_percenatge_list, counter);
	cout << endl << endl;
	cout << "Its Domain : " << id_min << "<_ x <_ " << id_max << endl;
	cout << "Its Range : " << Completion_min << " <_  y <_ " << Completion_max << endl;
}

//Function to check Onto Function as given
bool graph_imp::onto_check()
{
	for (int i = 0; i < counter; i++)
	{
		for (int j = 0; j < counter; j++)
		{
			if (list[j]->user_id != list[i]->user_id)
			{
				if (list[j]->com_percentage == list[i]->com_percentage)
				{
					cout << "AS user " << list[i]->user_id << " and " << list[j]->user_id << " are maped on same profile completion " << endl;
					cout << "\nUser ID    Completion Percatnge " << endl;
					cout << list[i]->user_id << "\t    " << list[i]->com_percentage << endl;
					cout << list[j]->user_id << "\t     " << list[j]->com_percentage << endl;
					cout << "Given Function is Onto : " << endl;
					return true;
				}

			}

		}
	}
	cout << "So the given function is not onto " << endl;
	return false;

}


//Function to check the one to one Function as Given
bool graph_imp::one_to_one()
{
	for (int i = 0; i < counter; i++)
	{
		for (int j = 0; j < counter; j++)
		{
			if (list[j]->user_id != list[i]->user_id)
			{
				if (list[j]->com_percentage == list[i]->com_percentage)
				{
					cout << "AS user " << list[i]->user_id << " and " << list[j]->user_id << " are maped on same profile completion " << endl;
					cout << "\nUser ID    Completion Percatnge " << endl;
					cout << list[i]->user_id << "\t     " << list[i]->com_percentage << endl;
					cout << list[j]->user_id << "\t     " << list[j]->com_percentage << endl;
					cout << "So Function is not one_to_one  " << endl;
					return false;
				}

			}

		}
	}
	cout << "AS all the inputs are mapped on unique outputs  \n so the function is one_to_one" << endl;
	return true;
}

//Function to check that a user follow other user or not

bool graph_imp::check_follower(int from_id, int to_id)
{
	int From_ind = search_id(from_id);
	if (From_ind == -1)
	{
		return false;
	}
	Graph_node* current = list[From_ind]->next;
	int x = 0;
	while (current)
	{
		if (current->user_id == to_id)
			return true;
		current = current->next;
	}
	return false;
}

//Function to Check Symmetric Relation

bool graph_imp::check_symmetric()
{
	cout << endl << endl;
	for (int i = 0; i < counter; i++)
	{
		Graph_node* current = list[i]->next;
		while (current)
		{
			if (!check_follower(current->user_id, list[i]->user_id))
			{
				cout << "AS relation " << list[i]->user_id << "--> " << current->user_id << " Exist " << endl;
				cout << "But  " << current->user_id << "--> " << list[i]->user_id << " not Exist " << endl;
				cout << "So the realtion is not symmetric " << endl;
				return false;
			}
			current = current->next;

		}
	}
	cout << "AS for every (A,B) the (B,A) is exist " << endl;
	cout << "So the given Relation is not symmetric " << endl;

}

//Function to Check Reflexive Relation
bool graph_imp::check_reflexive()
{
	for (int i = 0; i < counter; i++)
	{
		if (!(check_follower(list[i]->user_id, list[i]->user_id)))
		{
			cout << "( " << list[i]->user_id << " , " << list[i]->user_id << " ) " << "  not exist ";
			cout << "So the given realtion is not Reflexive " << endl;
			return false;
		}
	}
	cout << "As for all (A,A) relation  exist \n so the given Function is Reflexive " << endl;
	return true;
}

////Function to Check Transitive Relation

bool graph_imp::check_transitive()
{
	for (int i = 0; i < counter; i++)
	{

		Graph_node* Fol_A = list[i]->next;
		while (Fol_A)
		{
			/*Follower of A index*/
			int fol_A_ind = search_id(Fol_A->user_id);
			Graph_node* Fol_B = list[fol_A_ind]->next;
			/*Getting Follower of B*/
			while (Fol_B)
			{
				if (!check_follower(list[i]->user_id, Fol_B->user_id))
				{
					cout << "AS " << list[i]->user_id << "---> " << Fol_A->user_id << " Exist " << endl;
					cout << Fol_A->user_id << "---> " << Fol_B->user_id << " Exist " << endl;
					cout << list[i]->user_id << "---> " << Fol_B->user_id << " do not Exist " << endl;
					cout << "\n So the relation is not Transitive " << endl;
					return false;
				}
				Fol_B = Fol_B->next;

			}
			Fol_A = Fol_A->next;
		}
	}
	cout << "\nAS All the Realtions Fllows property (A,B),(B,C),(A,C) " << endl;
	cout << "So the  given Relation is Transitive " << endl;
	return true;
}

//Function To calculate Factorial
int graph_imp::factorial(int n)
{
	if (n == 0 || n == 1)
	{
		return 1;
	}
	return n * factorial(n - 1);
}

//Function to Implement Factorial

void graph_imp::sub_group_permutations()
{
	int count_users = 0;
	for (int i = 0; i < counter; i++)
	{
		if (list[i]->age > 25 && list[i]->region == "bratislavsky kraj")
		{
			count_users++;
		}
	}
	bool x = true;
	int num;
	cout << "Users from specific region and age  are  : " << count_users << endl;
	while (x == true)
	{
		cout << "\nEnter the Number which you want to make the subgroup : ";
		cin >> num;
		if (num > count_users)
		{
			cout << "You pick subgroup number more than they exist ..." << endl;
			cout << "Pleae Enter Less " << endl;
		}
		else
			x = false;

	}
	/*Calculating n-r*/
	int n_r = count_users - num;
	int result = factorial(count_users) / factorial(n_r);

	cout << "Permutation Resukt is : " << result << endl;
}

//Function for counting

void graph_imp::counting()
{
	int Com_count = 0;
	int region_count = 0;
	int public_count = 0;
	for (int i = 0; i < counter; i++)
	{
		if (list[i]->com_percentage >= 80)
		{
			Com_count++;
		}
		if (list[i]->region == "zilinsky kraj")
		{
			region_count++;
		}
		if (list[i]->public_r)
		{
			public_count++;
		}
	}
	cout << "Users graeter than complete 80 % profile are : " << Com_count << endl;
	cout << "Users in a specific region zilinsky kraj are : " << region_count << endl;
	cout << "Users who are public : " << public_count << endl;
}


//Function To implemnt Tree Functionalities as Given
void graph_imp::Tree_implemnt(int id)
{
	int index = search_id(id);
	if (index == -1)
	{
		cout << "This iD is not exist " << endl;
		return;
	}
	/*Inserting the followeres of this Id into the tree by one by one */
	Graph_node* current = list[index];
	tree obj;
	while (current)
	{
		node* rot = obj.getRoot();
		obj.insert(current->user_id, rot);
		current = current->next;
	}
	Sleep(100);
	system("CLS");
	cout << "Pre Traversal of  " << id << " Friends " << endl;
	obj.preorder(obj.getRoot());
	cout << "\n\nPost Traversal of  " << id << " Friends " << endl;
	obj.postorder(obj.getRoot());
	cout << "\n\nBFS Traversal of  " << id << " Friends " << endl;
	obj.BFS();
	cout << endl;
}

//Function To implemnt Induction

void graph_imp::Induction()
{
	int threshold;
	cout << "Enter the threshold of completion Percentage : ";
	cin >> threshold;
	int X;
	cout << "Set X : ";
	cin >> X;
	int count = 0;
	for (int i = 0; i < counter; i++)
	{
		if (list[i]->com_percentage >= threshold)
		{
			count++;
		}
	}
	if (count >= X)
	{
		cout << "Since number of users with thrrshold are : " << count << endl;
		cout << "So Induction is proved to True " << endl;
	}
}

//Function to check bipartite or not
bool graph_imp::IS_bipartite()
{
	/*Intializing a color list to check*/
	int* color = new int[counter] {-1};
	queue<int> obj;
	for (int i = 0; i < counter; i++)
	{
		if (color[i] == -1)
		{
			obj.push(i);
			color[i] = 0;

			while (!obj.empty())
			{
				int current = obj.front();
				obj.pop();
				Graph_node* adjacent = list[current]->next;
				while (adjacent)
				{
					int ind = search_id(adjacent->user_id);
					if (color[ind] == -1)
					{
						color[ind] = (color[current] + 1) % 2;
						obj.push(ind);
					}
					else
					{
						if (color[ind] == color[current])
						{
							cout << "As user " << list[ind]->user_id << " and " << list[current]->user_id << " Cannot be divide " << endl;
							cout << "Mismatch Occur not a Bipartit Graph " << endl;
							return false;
						}

					}
					adjacent = adjacent->next;
				}
			}
		}
	}


	cout << "The graph is a Bipartit Graph" << endl;
	cout << "Because we are able to split it into two groups" << endl;
	return true;
}

//Function To find MSt
void graph_imp::prims_minimum_spanning_Tree()
{

	bool* visited = new bool[counter] {false};
	visited[0] = true;

	int count = 0;
	int totalCost = 0;
	int cost = 0;
	bool exist = true;

	while (count < counter - 1 && exist)
	{
		int from = -1, to = -1;
		for (int i = 0; i < counter; i++)
		{
			if (visited[i])
			{
				Graph_node* adjacent = list[i]->next;
				while (adjacent)
				{
					int adjacnet_index = search_id(adjacent->user_id);
					if (check_follower(adjacent->user_id, list[i]->user_id))
					{
						if (!visited[adjacnet_index])
						{
							cout << list[i]->user_id << " -> " << adjacent->user_id << "  ";
							cost++;
						}
					}
					else
					{
						cout << "As user " << list[i]->user_id << " edge to " << adjacent->user_id << endl;
						cout << "As user " << adjacent->user_id << " not edge to " << list[i]->user_id << endl;
						cout << "So Spanning tree condition violate " << endl;
						cout << "Spanning tree cannot be created" << endl;
						exist = false;
						break;
					}
					adjacent = adjacent->next;
				}
			}
		}
	}
	if (exist)
	{
		cout << "Minimum Cost using Prim's Algorithm is: " << cost << endl;
	}
}








