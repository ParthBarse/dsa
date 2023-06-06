/*
Q7) Represent a given graph using adjacency matrix/list to perform DFS . Use the map of the
area around the college as the graph. Identify the prominent land marks as nodes and
perform DFS.
*/

#include <iostream>

#include <string>
using namespace std;
int G[10][10],visited[10],n;
string college[8];


void DFS(int i)
{
	int j;
	cout<<college[i]<<"->";
	visited[i]=1;
	for(j=0;j<n;j++)
	{
		if(!visited[j] && G[i][j]==1)
		{
			DFS(j);
		}
	}
}


int main()
{
	int i,j;
	cout<<"Enter no. of vertices: ";
	cin>>n;
	cout<<endl<<"Enter the locations of map in sequence: "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"Loc "<<i<<" :";
		cin>>college[i];
	}
	cout<<"\nEnter adjacency matrix of the graph: ";
	for(i=0;i<n;i++)
	{
		cout<<endl<<"Row ["<<i<<"]: ";
		for(j=0;j<n;j++)
		{
			cin>>G[i][j];
		}
	}
	
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	cout<<"Depth First Traversal of college map: "<<endl;
	DFS(2);
	return 0;
}

/*
Q8) Represent a given graph using adjacency list to perform BFS. Use the map of the area
around the college as the graph. Identify the prominent land marks as nodes and
perform BFS on that.
*/

#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define MAX 20

struct node
{
    node* next;
    int vertex;
    string name;
};

string places[MAX];
node* G[MAX];
int visited[MAX];
int n;

void insert(int, int);
void read_graph();
void BFS(int);

void read_graph()
{
    int i, vi, vj, edges;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout<<"Enter the name of the places as vertices: "<<endl;
    for(i=0;i<n;i++)
    {
    	cout<<"vertex "<<i<<": ";
    	cin>>places[i];
	}
    for (i = 0; i < n; i++)
    {
        G[i] = NULL;
    }
    cout << "\nEnter the number of edges: ";
    cin >> edges;

    for (i = 0; i < edges; i++)
    {
        cout << "\nEnter an edge (u,v): ";
        cin >> vi >> vj;
        insert(vi, vj);
        insert(vj, vi);
    }
}

void insert(int vi, int vj)
{
    node* p, * q;
    q = new node;
    q->vertex = vj;
    q->next = NULL;
    if (G[vi] == NULL)
    {
        G[vi] = q;
    }
    else
    {
        p = G[vi];
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = q;
    }
}

void BFS(int v)
{
    int i, w;
    queue<int> Q;
    node* p;
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    Q.push(v);
    cout << "\nVisited " << v<<" "<<places[v];
    visited[v] = 1;
    while (!Q.empty())
    {
        v = Q.front();
        Q.pop();
        for (p = G[v]; p != NULL; p = p->next)
        {
            w = p->vertex;
            if (visited[w] == 0)
            {
                Q.push(w);
                visited[w] = 1;
                cout << "\nVisited " <<w<<" "<<places[w];
            }
        }
    }
}

int main()
{
    int i;
    read_graph();
    BFS(0);
    return 0;
}


/*
Q9) There are flight paths between cities. If there is a flight between city A and city B then
there is an edge between the cities. The cost of the edge can be the time that flight takes
to reach city B from A, or the amount of fuel used for the journey. Represent this as a
graph. The node can be represented by airport name or name of the city. Use adjacency
list representation of the graph . Check whether the graph is connected or not.

and

Q12) There are flight paths between cities. If there is a flight between city A and city B then
there is an edge between the cities. The cost of the edge can be the time that flight takes
to reach city B from A, or the amount of fuel used for the journey. Represent this as a
graph. The node can be represented by airport name or name of the city. Use adjacency
matrix representation of the graph. Check whether the graph is connected or not.

*/

#include<iostream>
#include<string>
using namespace std;

int adj_mat[50][50];
string cities[50];

int main()
{
	int n;
	cout<<"Enter number of cities : ";
	cin>>n;
	
	for (int i=0; i<n; i++){
		cout<<"Enter City : "<< i << " : ";
		cin>>cities[i];
	}
	
	for (int i=0; i<n; i++){
		for (int j=i+1; j<n; j++)
		{
			cout<<"Enter the fule consumed between "<<cities[i]<<" to "<<cities[j]<< " : ";
			cin>>adj_mat[i][j];
			adj_mat[j][i] = adj_mat[i][j];
		}
	}
	
	cout<<endl;
	
	cout<<"Matrix Representation : "<<endl<<endl;
	for (int i=0; i<n; i++){
		cout<<"\t"<<cities[i]<<"\t";
	}
	cout<<endl;
	
	for (int i=0; i<n; i++){
		cout<<cities[i];
		for (int j=0; j<n; j++){
			cout<<"\t"<<adj_mat[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<endl<<endl;
	
	cout<<"Adjacency List : "<<endl<<endl;
	
	int count = 0;
	for(int i=0; i<n; i++){
		cout<< cities[i]<<"->";
		for(int j=0; j<n; j++){
			if (i!=j && adj_mat[i][j] != 0){
				cout<<cities[j]<<"->";
			}
			else{
				count += 1;
			}
		}
		cout<<"NULL"<<endl;
	}
	
	if (count == n){
		cout<<"Graph is connected";
	}
	else{
		cout<<"Graph is not connected";
	}
	
	return 0;
}

/*
Q 10) Consider a scenario for Hospital to cater services to different kinds of patients as
Serious (top priority), b) non-serious (medium priority), c) General Checkup (Least
priority). Implement the priority queue to cater services to the patients
*/

#include<iostream>
#include<string>
#define SIZE 6
using namespace std;

typedef struct patient
{
	string name;
	int priority;
} patient;

class pqueue
{
public:
	patient line[SIZE];
	int front, rear;

	pqueue()
	{
		front = rear = -1;
	};

	void init()
	{
		front = rear = -1;
	}

	int empty()
	{
		if (front == -1)
			return 1;
		return 0;
	}                                   
	
	int full()
	{
		if ((rear+1)%SIZE==front)
			return 1;
		return 0;
	}

	void enqueue(patient& p)
	{
		int i;
		if (full())
		{
			cout << "Sorry, we can't admit the patient, the queue is already full, wait for some time: " << endl;
		}
		else
		{
			if (empty())
			{
				front = rear = 0;
				line[front] = p;
			}
			else
			{
				i = rear;
				while (p.priority < line[i].priority)
				{
					line[(i + 1) % SIZE] = line[i];
					i = (i - 1 + SIZE) % SIZE;
					if ((i + 1) % SIZE == front)
						break;
				}
				i = (i + 1) % SIZE;
				line[i] = p;
				rear = (rear + 1) % SIZE;
			}
		}
	}

	patient dequeue()
	{
		patient x;
		if (empty())
			cout << "\nUnderflow" << endl;
		else
		{
			x = line[front];
			if (rear == front)
				init();
			else
				front = (front + 1) % SIZE;
		}
		return x;
	}

	void display()
	{
		if(empty())
		{
			cout<<"\nNo patients yet, hospital is empty for now";
		}
		else
		{
		int i=front;
		while (i != rear)
		{
			cout << line[i].name << "->";
			i = (i + 1) % SIZE;
		}
		cout<< line[i].name << endl;
		}
	}
};



int main()
{
	pqueue o;
	int n;
	char ch;

	do
	{
		cout << "\n\nWhat do you want to do?\n1. Join queue\n2. Patient attended\n3. Display Patient queue\n4. Exit" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			{
			patient x;
			cout << "Enter the name of the patient: ";
			cin >> x.name;
			cout << "Enter the priority:\n(1.serious   2.Mild serious	3.General checkup)"<<endl;
			cout<<"Priority: ";
			cin >> x.priority;
			o.enqueue(x);
			}
			break;
			
		case 2:
			{
			patient x=o.dequeue();
			cout<<"\nThe patient just got atttended is: "<<x.name<<endl;
			}
		break;

		case 3:
			o.display();
			break;

		case 4:
			cout << "Exiting the program." << endl;
			ch = 'q';  // Set ch to 'q' to exit the loop
			break;

		default:
			cout << "\nInvalid input, please try again." << endl;
			break;
		}
	} while (n != 4);

	return 0;
}


/*
Q3) A book consists of chapters, chapters consist of sections and sections consist of

subsections. Construct a tree and print the nodes.
*/

#include <iostream>
using namespace std;

struct node
{
    char label[10];
    int ch_count;
    struct node *child[10];
} *root;

void Create()
{
    root = new node;
    cout << "\nEnter the Book Name :" << endl;
    cin >> root->label;
    cout << "\nEnter the number of chapters :" << endl;
    cin >> root->ch_count;
    for (int i = 0; i < root->ch_count; i++)
    {
        root->child[i] = new node;
        cout << "\nEnter the name of chapter " << (i + 1) << " :" << endl;
        cin >> root->child[i]->label;
        cout << "\nEnter the number of sections in this chapter :" << endl;
        cin >> root->child[i]->ch_count;
        for (int j = 0; j < root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new node;
            cout << "\nName of section " << (j + 1) << " :" << endl;
            cin >> root->child[i]->child[j]->label;
            cout << "\nThe number of sub sections in this section:" << endl;
            cin >> root->child[i]->child[j]->ch_count;
            for (int k = 0; k < root->child[i]->child[j]->ch_count; k++)
            {
                root->child[i]->child[j]->child[k] = new node;
                cout << "\nName of sub section " << (k + 1) << " :" << endl;
                cin >> root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}

void Display(node *r)
{
    if (r != NULL)
    {
    	
    	int chapter = r->ch_count;
    	int sections = r->child[0]->ch_count;
    	int sub = r->child[0]->child[0]->ch_count;
    	
        cout << "\n**Book Name** " << endl;
        cout << r->label << endl;
        for (int i = 0; i < chapter; i++)
        {
            cout << "\n**Chapter*" << endl;
            cout << r->child[i]->label << endl;
            cout << "\n*Sections**" << endl;
            for (int j = 0; j < sections; j++)
            {
                cout << r->child[i]->child[j]->label << endl;
                cout << "Sub Section" << endl;
                for (int k = 0; k < sub; k++)
                {
                    cout << r->child[i]->child[j]->child[k]->label << "\n"
                         << endl;
                }
            }
        }
    }
}

int main()
{
    while (1)
    {
        cout << "\n**MAIN MENU*" << endl;
        cout << " 1. Create \n 2. Display \n 3. Exit" << endl;
        int ch;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            Create();
            break;
        case 2:
            Display(root);
            break;
        case 3:
            exit(0);
        }
    }
    return 0;
}

/*
Q10) Consider a scenario for Hospital to cater services to different kinds of patients as
Serious (top priority), b) non-serious (medium priority), c) General Checkup (Least
priority). Implement the priority queue to cater services to the patients
*/

#include<iostream>
#include<string>
#define MAX 3
using namespace std;

typedef struct patient
{
	string name;
	int priority;
} patient;

class pqueue
{
public:
	patient line[MAX];
	int front, rear;

	pqueue()
	{
		front = rear = -1;
	};

	void init()
	{
		front = rear = -1;
	}

	int empty()
	{
		if (front == -1)
			return 1;
		return 0;
	}

	int full()
	{
		if ((rear+1)%MAX==front)
			return 1;
		return 0;
	}

	void enqueue(patient& p)
	{
		int i;
		if (full())
		{
			cout << "Sorry, we can't admit the patient, the queue is already full, wait for some time: " << endl;
		}
		else
		{
			if (empty())
			{
				front = rear = 0;
				line[0] = p;
			}
			else
			{
				i = rear;

				while (p.priority < line[i].priority)
				{
					line[(i + 1) % MAX] = line[i];
					i = (i - 1 + MAX) % MAX;
					if ((i + 1) % MAX == front)
						break;
				}
				i = (i + 1) % MAX;
				line[i] = p;
				rear = (rear + 1) % MAX;
			}
		}
	}

	patient dequeue()
	{
		patient x;
		if (empty())
			cout << "\nUnderflow" << endl;
		else
		{
			x = line[front];
			if (rear == front)
				init();
			else
				front = (front + 1) % MAX;
		}
		return x;
	}

	void display()
	{
		if(empty())
		{
			cout<<"\nNo patients yet, hospital is empty for now";
		}
		else
		{
		int i, x;
		i = front;
		while (i != rear)
		{
			cout << line[i].name << "->";
			i = (i + 1) % MAX;
		}
		cout<< line[i].name << endl;
		}
	}
};



int main()
{
	pqueue o;
	int n;
	char ch;

	do
	{
		cout << "\n\nWhat do you want to do?\n1. Join queue\n2. Patient attende\n3. Display Patient queue\n4. Exit" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			{
			patient x;
			cout << "Enter the name of the patient: ";
			cin >> x.name;
			cout << "Enter the priority:\n(1.serious   2.Mild serious	3.General checkup)"<<endl;
			cout<<"Priority: ";
			cin >> x.priority;
			o.enqueue(x);
			}
			break;
			
		case 2:
			{
			patient x=o.dequeue();
			cout<<"\nThe patient just got atttended is: "<<x.name<<endl;
			}
		break;


		case 3:
			o.display();
			break;

		case 4:
			cout << "Exiting the program." << endl;
			ch = 'q';  // Set ch to 'q' to exit the loop
			break;

		default:
			cout << "\nInvalid input, please try again." << endl;
			break;
		}
	} while (n != 4);

	return 0;
}

/*
Q11 Department maintains a student information. The file contains roll number, name,
division and address. Allow user to add, delete information of student. Display
information of particular employee. If record of student does not exist an appropriate
message is displayed. If it is, then the system displays the student details. Use sequential
file to main the data
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student 
{
    int rollNumber;
    string name;
    string division;
    string address;
};

void addStudent() 
{
    ofstream outFile("students.txt", ios::app);

    Student student;
    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter Division: ";
    getline(cin, student.division);
    cout << "Enter Address: ";
    getline(cin, student.address);

    outFile << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;

    cout << "Student information added successfully." << endl;

    outFile.close();
}

void deleteStudent() 
{
    int rollNumber;
    cout << "Enter Roll Number of the student to be deleted: ";
    cin >> rollNumber;

    ifstream inFile("students.txt");
   
    ofstream outFile("temp.txt");
    

    bool found = false;
    Student student;

    while (inFile >> student.rollNumber >> student.name >> student.division >> student.address) 
    {
        if (student.rollNumber != rollNumber) 
        {
            outFile << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;
        } 
		else 
		{
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    if (found) 
    {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        cout << "Student information deleted successfully." << endl;
    }
	 else 
    {
        remove("temp.txt");
        cout << "Student not found!" << endl;
    }
}

void displayStudent() 
{
    int rollNumber;
    cout << "Enter Roll Number of the student to display information: ";
    cin >> rollNumber;

    ifstream inFile("students.txt");
    

    bool found = false;
    Student student;

    while (inFile >> student.rollNumber >> student.name >> student.division >> student.address) 
    {
        if (student.rollNumber == rollNumber) 
        {
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }

    inFile.close();

    if (!found) 
    {
        cout << "Student not found!" << endl;
    }
}

int main() 
{
    int choice;
    do 
    {
    	
        cout << "-----------------------------" << endl;
        cout << "Student Information System" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display Student Information" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                displayStudent();
                break;
            case 4:
            	{
	            	ofstream outFile("students.txt", ios::trunc);
	            	outFile.close();
	                cout << "Exiting the program..." << endl;
	                break;
            	}
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}


/*
Q4 Beginning with an empty binary search tree, Construct binary search tree by inserting
the values in the order given. After constructing a binary tree –Insert new node, Find
number of nodes in longest path from root
Minimum data value found in the tree

and

Q5) Beginning with an empty binary search tree, Construct binary search tree by inserting
the values in the order given. After constructing a binary tree –Insert new node, Change
a tree so that the roles of the left and right pointers are swapped at every node
Search a value
*/

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    node *right,*left;
}node;

void Inorder(node *);
node* insert(node *,int );

node* insert(node *T,int x)
{
    if(T==NULL)
    {
        T=new node;
        T->data=x;
        T->left=NULL;
        T->right=NULL;
        return (T);
    }
    if(x>T->data)
    {
        T->right=insert(T->right,x);
        return (T);
    }
    T->left=insert(T->left,x);
    return (T);
}

void swap(node* T)
{
	node* temp;
	if(T!=NULL)
    {
        temp=T->right;
        T->right=T->left;
        T->left=temp;
        swap(T->left);     
	    swap(T->right);
    }	
}

void Inorder(node *T)
{
    if(T!=NULL)
    {
        Inorder(T->left);
        cout<<T->data<<"\t";
        Inorder(T->right);
    }
}

int longest_path(node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftPath = longest_path(root->left);
    int rightPath = longest_path(root->right);

    return 1 + max(leftPath, rightPath);
}

void minimum(node *T)
{
    if(T == NULL)
    {
        cout << "Tree is empty!";
        return;
    }
    
    if(T->left == NULL)
    {
        cout<<T->data;
        return;
    }
    
    minimum(T->left);
}

bool search(node* root, int value) {
    if (root == NULL) {
        return false;
    }

    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main()
{
    node *root=NULL;
    
    int x,n;
    char c='y';
    do
    {
    cout<<"What do you want to do?\n1.Insert Number\n2.Print Inorder traversal\n3.Swap the tree\n4.Minimum value\n5.longest path\n6.Search"<<endl;
    cin>>n;
    switch(n)
    {
        case 1:
        {
            cout<<"Enter the data part: ";
            cin>>x;
            root=insert(root,x);
        }
        break;

        case 2:
        {
        	cout<<"The Inorder traversal of the Binary Search Tree is: "<<endl;
            Inorder(root);
        }
        break;

        case 3:
        {
        	node* copy=root;
        	swap(copy);
        	cout<<"The swapped Binary Search Tree is: "<<endl;
            Inorder(copy);
        }
        break;
        
        case 4:
        {
			cout<<endl<<"The minimum value of the tree is: ";
			minimum(root);
        }
        break;        
        
        case 5:
        {
			cout<<endl<<"The longest path of the tree is: ";
			cout<<longest_path(root);
        }
        break;    
        
        case 6:
        {
        	int x;
			cout<<endl<<"Number to be searched: ";
			cin>>x;
			if(search(root,x))
				cout<<"\nNumber present";
			else
				cout<<"\nNumber not present";
        }
        break;

        default:
        {
            cout<<"Invalid choice, Please try again"<<endl;
        }
        break;
    }
    cout<<endl<<"Do you want to continue? If yes enter 'y'"<<endl;
    cin>>c;
    }while(c=='y');
	return 0;
}

/*
Q6) Construct an expression tree from the given prefix expression eg. +--a*bc/def and
traverse it using post order traversal (non recursive) and then delete the entire tree.
*/
#include<iostream>
#include<string>
using namespace std;

typedef struct node
{
	char data;
	struct node *left, *right;	
}node;

class stack
{
	public:
		int top;
		node *pile[30];
		
		stack()
		{
			top=-1;
		}
		
		void push(node *T)
		{
			pile[++top]=T;
		}
		
		node* topn()
		{
			return(pile[top]);
		}
		
		node* pop()
		{
			return(pile[top--]);
		}
};

node* prefix_to_tree(string prefix)
{
	stack o;
	for(int i=prefix.length()-1;i>=0;i--)
	{
		if(isalnum(prefix[i]))
		{
			node* P=new node;
			P->data=prefix[i];
			P->left=NULL;
			P->right=NULL;
			o.push(P);	
		}
		else if(prefix[i]=='+'|| prefix[i]=='*'||prefix[i]=='/' ||prefix[i]=='-' || prefix[i]=='^')
		{
			node* L=o.pop();
			node* R=o.pop();
			node* P=new node;
			P->data=prefix[i];
			P->left=L;
			P->right=R;
			o.push(P);
		}
	}
	return (o.topn());
}

void Inorder(node *T)
{
	if(T!=NULL)
	{
		Inorder(T->left);
		cout<<T->data<<"\t";
		Inorder(T->right);
	}
}

int main()
{
	string prefix;
	cout<<"Enter a prefix string: ";
	cin>>prefix;
	cout<<endl;
	node* root=prefix_to_tree(prefix);
	cout<<endl<<"post order traversal: ";
	Inorder(root);
	return 0;
}