//Main Class To implemnt all the functionalities
#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
#include"Date_time.h"
#include"BST.h"
#include<queue>
#include<stack>

using namespace std;
class Graph_node
{
public:
	int user_id, com_percentage, age;
	bool public_r, gender;
	date_time last_login;
	date_time registration;
	string region;
	Graph_node* next;
	Graph_node();
	void set_grah_data(int id, int per, int ages, bool pub, bool gen, date_time LL, date_time regis, string reg);
};


class graph_imp
{

	Graph_node** list;
	int* Id_list;
	int* com_percenatge_list;
	int counter;
	int Graph_size;
	int Person, Edges;
public:
	graph_imp();
	void add_vertex(Graph_node* vertex);
	void add_edge(int from_id, int to_id);
	int search_id(int id);
	void Read_From_file_profile();
	void Read_From_file_relationship();
	void test_display();
	void Check_implication(int First_UI, int Second_UI);
	void Check_biconditional(int First_UI, int Second_UI);
	void Check_existential_Quantifier();
	void Check_Universal_quantifier();
	void Venn_Diagram();
	void sets();
	void Domain_range();
	int Find_max(int* arr, int size);
	int Find_min(int* arr, int size);
	bool onto_check();
	bool one_to_one();
	bool check_follower(int from_id, int to_id);
	bool check_symmetric();
	bool check_reflexive();
	bool check_transitive();
	void sub_group_permutations();
	int factorial(int n);
	void counting();
	void Tree_implemnt(int id);
	void Induction();
	bool IS_bipartite();
	void display();
	void prims_minimum_spanning_Tree();

};





