// HackerRank - C++ - Introduction - III - Classes


/* 1. Classes - Structs */
/*
struct is a way to combine multiple fields to represent a composite data structure, which further lays the foundation for Object Oriented Programming. For example, we can store details related to a student in a struct consisting of his age (int), first_name (string), last_name (string) and standard (int).

struct can be represented as

struct NewType {
    type1 value1;
    type2 value2;
    .
    .
    .
    typeN valueN;
};

You have to create a struct, named Student, representing the student's details, as mentioned above, and store the data of a student.

Input Format

Input will consist of four lines.
The first line will contain an integer, representing age.
The second line will contain a string, consisting of lower-case Latin characters ('a'-'z'), representing the first_name of a student.
The third line will contain another string, consisting of lower-case Latin characters ('a'-'z'), representing the last_name of a student.
The fourth line will contain an integer, representing the standard of student.

Note: The number of characters in first_name and last_name will not exceed 50.

Output Format

Output will be of a single line, consisting of age, first_name, last_name and standard, each separated by one white space.

P.S.: I/O will be handled by HackerRank.

Sample Input

15
john
carmack
10

Sample Output

15 john carmack 10

*/
/* Solution */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
    add code for struct here.
*/
struct Student {
    int age;
    string first_name;
    string last_name;
    int standard;
};

int main() {
    Student st;
    
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
    
    return 0;
}


/* 2. Classes - Class */
/*
Classes in C++ are user defined types declared with keyword class that has data and functions . Although classes and structures have the same type of functionality, there are some basic differences. The data members of a class are private by default and the members of a structure are public by default. Along with storing multiple data in a common block, it also assigns some functions (known as methods) to manipulate/access them. It serves as the building block of Object Oriented Programming.

It also has access specifiers, which restrict the access of member elements. The primarily used ones are the following:

  *  public: Public members (variables, methods) can be accessed from anywhere the code is visible.
  *  private: Private members can be accessed only by other member functions, and it can not be accessed outside of class.

Class can be represented in the form of

class ClassName {
    access_specifier1:
        type1 val1;
        type2 val2;
        ret_type1 method1(type_arg1 arg1, type_arg2 arg2,...)
        ...
    access_specifier2:
        type3 val3;
        type4 val4;
        ret_type2 method2(type_arg3 arg3, type_arg4 arg4,...)
        ...
};

It's a common practice to make all variables private, and set/get them using public methods. For example:

class SampleClass {
    private:
        int val;
    public:
        void set(int a) {
            val = a;
        }
        int get() {
            return val;
        }
};

We can store details related to a student in a class consisting of his age (int), first_name (string), last_name (string) and standard (int).

You have to create a class, named Student, representing the student's details, as mentioned above, and store the data of a student. Create setter and getter functions for each element; that is, the class should at least have following functions:

  *  get_age, set_age
  *  get_first_name, set_first_name
  *  get_last_name, set_last_name
  *  get_standard, set_standard

Also, you have to create another method to_string() which returns the string consisting of the above elements, separated by a comma(,). You can refer to stringstream for this.

Input Format

Input will consist of four lines.
The first line will contain an integer, representing the age. The second line will contain a string, consisting of lower-case Latin characters ('a'-'z'), representing the first_name of a student.
The third line will contain another string, consisting of lower-case Latin characters ('a'-'z'), representing the last_name of a student.
The fourth line will contain an integer, representing the standard of student.

Note: The number of characters in first_name and last_name will not exceed 50.

Output Format

The code provided by HackerRank will use your class members to set and then get the elements of the Student class.

Sample Input

15
john
carmack
10

Sample Output

15
carmack, john
10

15,john,carmack,10

*/
/* Solution */

#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student {
    private:
    int age;
    string first_name;
    string last_name;
    int standard;
    public:
    void set_age(int a) {
        age = a;
    }
    int get_age() {
        return age;
    }
    
    void set_first_name(string b) {
        first_name = b;
    }
    string get_first_name() {
        return first_name;
    }
    
    void set_last_name(string c) {
        last_name = c;
    }
    string get_last_name() {
        return last_name;
    }
    
    void set_standard(int d) {
        standard = d;
    }
    int get_standard() {
        return standard;
    }
    
    string to_string() {
        return ::to_string(age) + "," + first_name + "," + last_name + "," + ::to_string(standard);
    }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}


/* 3. Classes - Classes and Objects */
/*
A class defines a blueprint for an object. We use the same syntax to declare objects of a class as we use to declare variables of other basic types. For example:

Box box1;          // Declares variable box1 of type Box
Box box2;          // Declare variable box2 of type Box

Kristen is a contender for valedictorian of her high school. She wants to know how many students (if any) have scored higher than her in the 5 exams given during this semester.

Create a class named Student with the following specifications:

  *  An instance variable named scores to hold a student's 5 exam scores.
  *  A void input() function that reads 5 integers and saves them to scores.
  *  An int calculateTotalScore() function that returns the sum of the student's scores.

Input Format

Most of the input is handled for you by the locked code in the editor.

In the void Student::input() function, you must read 5 scores from stdin and save them to your scores instance variable.

Constraints

  *  0 ≤ n ≤ 100
  *  0 ≤ examscore ≤ 50

Output Format

In the int Student::calculateTotalScore() function, you must return the student's total grade (the sum of the values in scores).

The locked code in the editor will determine how many scores are larger than Kristen's and print that number to the console.

Sample Input

The first line contains n, the number of students in Kristen's class. The n subsequent lines contain each student's 5 exam grades for this semester.

3
30 40 45 10 10
40 40 40 10 10
50 20 30 10 10

Sample Output

1

Explanation

Kristen's grades are on the first line of grades. Only 1 student scored higher than her.
*/
/* Solution */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here
class Student {
    private:
    vector<int> scores;
    public:
    Student() : scores(5) {};
    void input() {
        for (int i = 0; i < scores.size(); i++) {
            cin >> scores[i];
        }
    }
    int calculateTotalScore() {
        int total = 0;
        for (int i = 0; i < scores.size(); i++) {
            total += scores[i];
        }
        return total;
    }    
};

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}


/* 4. Classes - Box It! */
/*
Design a class named Box whose dimensions are integers and private to the class. The dimensions are labelled: length l, breadth b, and height h.

The default constructor of the class should initialize l, b, and h to 0.

The parameterized constructor Box(int length, int breadth, int height) should initialize Box's l, b and h to length, breadth and height.

The copy constructor Box (Box B) should set l, b and h to B's l, b and h, respectively.

Apart from the above, the class should have 4 functions:

  *  int getLength() - Return box's length
  *  int getBreadth() - Return box's breadth
  *  int getHeight() - Return box's height
  *  long long CalculateVolume() - Return the volume of the box

Overload the operator < for the class Box. Box A < Box B if:

  1.  A.l < B.l
  2.  A.b < B.b and A.l == B.l
  3.  A.h < B.h and A.b == B.b and A.l == B.l

Overload operator << for the class Box().

If B is an object of class Box:
cout << B should print B.l, B.b and B.h on a single line separated by spaces.

For example,

Box b1; // Should set b1.l = b1.b = b1.h = 0;
Box b2(2, 3, 4); // Should set b1.l = 2, b1.b = 3, b1.h = 4;
b2.getLength();	// Should return 2
b2.getBreadth(); // Should return 3
b2.getheight();	// Should return 4
b2.CalculateVolume(); // Should return 24
bool x = (b1 < b2);	// Should return true based on the conditions given
cout<<b2; // Should print 2 3 4 in order.

Constraints

  *  0 ≤ l, b, h ≤ 10^5
  *  Two boxes being compared using the operator will not have all three dimensions equal.
*/
/* Solution */

#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);

// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box {
    private:
    
    int l;
    int b;
    int h;
    
    public:
    
    Box() {
        l=0;
        b=0;
        h=0;        
    }
    
    Box(int length, int breadth, int height) {
        l = length;
        b = breadth;
        h = height;
    }
    
    Box(Box &B) {
        l = B.l;
        b = B.b;
        h = B.h;
    }
    
    int getLength() {
        return l;
    }
    
    int getBreadth() {
        return b;
    }
    
    int getHeight() {
        return h;
    }
    
    long CalculateVolume() {
        return (long)l*b*h;
    }
    
    friend bool operator < (Box& B1, Box& B2) {
        if ((B1.l < B2.l) || (B1.b < B2.b && B1.l == B2.l) || (B1.h < B2.h && B1.b == B2.b && B1.l == B2.l)) {
            return true;
        } else {
            return false;
        }
    }
    
    friend ostream& operator << (ostream& out, Box& B1) {
        out << B1.l << " " << B1.b << " " << B1.h;
        return out;
    }
};


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}


/* 5. Classes - Inherited Code */
/*
You inherited a piece of code that performs username validation for your company's website. The existing function works reasonably well, but it throws an exception when the username is too short. Upon review, you realize that nobody ever defined the exception.

The inherited code is provided for you in the locked section of your editor. Complete the code so that, when an exception is thrown, it prints Too short: n (where n is the length of the given username).

Input Format

The first line contains an integer, t, the number of test cases.
Each of the t subsequent lines describes a test case as a single username string, u.

Constraints

  *  1 ≤ t ≤ 1000
  *  1 ≤ |u| ≤ 100
  *  The username consists only of uppercase and lowercase letters.

Output Format

You are not responsible for directly printing anything to stdout. If your code is correct, the locked stub code in your editor will print either Valid (if the username is valid), Invalid (if the username is invalid), or Too short: n (where n is the length of the too-short username) on a new line for each test case.

Sample Input

3
Peter
Me
Arxwwz

Sample Output

Valid
Too short: 2
Invalid

Explanation

Username Me is too short because it only contains 2 characters, so your exception prints Too short: 2.
All other validation is handled by the locked code in your editor.
*/
/* Solution */

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Define the exception here */
class BadLengthException {
    private:
    int n;
    
    public:
    BadLengthException(int shortnumber){
        n = shortnumber;
    }
    int what(){
        return n;
    }
};


bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}


/* 6. Classes - Exceptional Server */
/*
In this challenge, you are required to handle error messages while working with small computational server that performs complex calculations.
It has a function that takes 2 large numbers as its input and returns a numeric result. Unfortunately, there are various exceptions that may occur during execution.

Complete the code in your editor so that it prints appropriate error messages, should anything go wrong. The expected behavior is defined as follows:

  *  If the compute function runs fine with the given arguments, then print the result of the function call.
  *  If it fails to allocate the memory that it needs, print Not enough memory.
  *  If any other standard C++ exception occurs, print Exception: S where S is the exception's error message.
  *  If any non-standard exception occurs, print Other Exception.

Input Format

The first line contains an integer, T, the number of test cases.
Each of the T subsequent lines describes a test case as 2 space-separated integers, A and B, respectively.

Constraints

  *  1 ≤ T ≤ 10^3
  *  0 ≤ A, B ≤ 2^60

Output Format

For each test case, print a single line containing whichever message described in the Problem Statement above is appropriate. After all messages have been printed, the locked stub code in your editor prints the server load.

Sample Input

2
-8 5
1435434255433 5

Sample Output

Exception: A is negative
Not enough memory
2

Explanation

-8 is negative, hence 'Exception: A is negative' is thrown. Since the second input is too large, 'not enough memory' is displayed. 2 is the server load.
*/
/* Solution */

#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if(A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if(B == 0) throw 0;
		real = (A/B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; cin >> T;
	while(T--) {
		long long A, B;
		cin >> A >> B;

		/* Enter your code here. */
        try {
            cout << Server::compute(A,B) << endl;
        } catch (invalid_argument ex) {
            cout << "Exception: " << ex.what() << endl;
        }catch(bad_alloc ex){
            cout << "Not enough memory" << endl;
        }catch(exception& ex){
            cout << "Exception: " << ex.what() << endl;
        }catch(...)
        {
            cout << "Other Exception" << endl;
        }

	}
	cout << Server::getLoad() << endl;
	return 0;
}


/* 7. Classes - Abstract Classes - Polymorphism */
/*
This problem is to get you familiar with virtual functions. Create three classes Person, Professor and Student. The class Person should have data members name and age. The classes Professor and Student should inherit from the class Person.

The class Professor should have two integer members: publications and cur_id. There will be two member functions: getdata and putdata. The function getdata should get the input from the user: the name, age and publications of the professor. The function putdata should print the name, age, publications and the cur_id of the professor.

The class Student should have two data members: marks, which is an array of size 6 and cur_id. It has two member functions: getdata and putdata. The function getdata should get the input from the user: the name, age, and the marks of the student in 6 subjects. The function putdata should print the name, age, sum of the marks and the cur_id of the student.

For each object being created of the Professor or the Student class, sequential id's should be assigned to them starting from 1.

Solve this problem using virtual functions, constructors and static variables. You can create more data members if you want.

Note: Expand the main function to look at how the input is being handled.

Input Format

The first line of input contains the number of objects that are being created. If the first line of input for each object is 1, it means that the object being created is of the Professor class, you will have to input the name, age and publications of the professor.

If the first line of input for each object is 2, it means that the object is of the Student class, you will have to input the name, age and the marks of the student in 6 subjects.

Constraints

  *  1 ≤ len_name ≤ 100, where len_name is the length of the name.
  *  1 ≤ age ≤ 80
  *  1 ≤ publications ≤ 1000
  *  0 ≤ marks ≤ 100, where marks is the marks of the student in each subject.

Output Format

There are two types of output depending on the object.

If the object is of type Professor, print the space separated name, age, publications and id on a new line.

If the object is of the Student class, print the space separated name, age, the sum of the marks in 6 subjects and id on a new line.

Sample Input

4
1
Walter 56 99
2
Jesse 18 50 48 97 76 34 98
2
Pinkman 22 10 12 0 18 45 50
1
White 58 87

Sample Output

Walter 56 99 1
Jesse 18 403 1
Pinkman 22 135 2
White 58 87 2

*/
/* Solution */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int pro=0,stu=0;

class Person {
    protected:
    string name;
    int age;
    public:
    virtual void getdata(){}
    virtual void putdata(){}
};

class Professor: public Person {
    protected:
    int Publication;
    static int cur_id;
    
    public:
    void getdata(){cin>>name>>age>>Publication;}
    void putdata()
    {   cout<<name<<" "<<age<<" "<<Publication<<" ";
        pro+=1;
        cout<<pro<<endl;
    }
};
class Student: public Person
{
 protected:
    int marks[6];
    static int cur_id;

 public:
    void getdata()
    {
        cin >> name >> age;
        for(int i=0; i<6; i++)
        {
            cin>>marks[i];
        }
    }
    void putdata()
    {
        int sum=0;
        for(int i=0; i<6; i++)
        {
            sum=sum+marks[i];
        }
        cout << name << " " << age << " " << sum << " ";
        stu+=1;
        cout << stu << endl;
    }
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}


/* 8. Classes - Abstract Classes - Polymorphism */
/*
Abstract base classes in C++ can only be used as base classes. Thus, they are allowed to have virtual member functions without definitions.

A cache is a component that stores data so future requests for that data can be served faster. The data stored in a cache might be the results of an earlier computation, or the duplicates of data stored elsewhere. A cache hit occurs when the requested data can be found in a cache, while a cache miss occurs when it cannot. Cache hits are served by reading data from the cache which is faster than recomputing a result or reading from a slower data store. Thus, the more requests that can be served from the cache, the faster the system performs.

One of the popular cache replacement policies is: "least recently used" (LRU). It discards the least recently used items first.

For example, if a cache with a capacity to store 5 keys has the following state(arranged from most recently used key to least recently used key) -

5 3 2 1 4

Now, If the next key comes as 1(which is a cache hit), then the cache state in the same order will be -

1 5 3 2 4

Now, If the next key comes as 6(which is a cache miss), then the cache state in the same order will be -

6 1 5 3 2

You can observe that 4 has been discarded because it was the least recently used key and since the capacity of cache is 5, it could not be retained in the cache any longer.

Given an abstract base class Cache with member variables and functions:

mp - Map the key to the node in the linked list
cp - Capacity
tail - Double linked list tail pointer
head - Double linked list head pointer
set() - Set/insert the value of the key, if present, otherwise add the key as the most recently used key. If the cache has reached its capacity, it should replace the least recently used key with a new key.
get() - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.

You have to write a class LRUCache which extends the class Cache and uses the member functions and variables to implement an LRU cache.

Input Format

First line of input will contain the N number of lines containing get or set commands followed by the capacity M of the cache.
The following N lines can either contain get or set commands.
An input line starting with get will be followed by a key to be found in the cache. An input line starting with set will be followed by the key and value respectively to be inserted/replaced in the cache.

Constraints

  *  1 <= N <= 500000
  *  1 <= M <= 1000
  *  1 <= key <= 20
  *  1 <= value <= 2000

Output Format

The code provided in the editor will use your derived class LRUCache to output the value whenever a get command is encountered.

Sample Input

3 1
set 1 2
get 1
get 2

Sample Output

2
-1

Explanation

Since, the capacity of the cache is 1, the first set results in setting up the key 1 with it's value 2. The first get results in a cache hit of key 1, so 2 is printed as the value for the first get. The second get is a cache miss, so -1 is printed.
*/
/* Solution */

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
    
    public:
    LRUCache(int c) {
        cp = c;       
    }
    
    void set (int k, int v) {
        Node*N;
        if (mp.empty()) {
            N = new Node(k, v);
            tail = head = N;
            mp[k]= N;
            return;
        }
        
        auto it = mp.find(k);
        
         if ( it != mp.end() ) {
            it -> second -> value = v;
            if ( head == it -> second ) {
                return;
            }

        it -> second -> prev -> next = it -> second -> next;

        if ( tail == it -> second ) {
            tail = tail -> prev;
        } else {
            it -> second -> next -> prev = it -> second -> prev;
        }

        it -> second -> next = head;
        it -> second -> prev = nullptr;
        head -> prev = it -> second;
        head = it -> second;
        
    } else {
        N = new Node(head -> prev, head, k, v);
        head -> prev = N; 
        head = N;
        mp[k] = N;

        if ( mp.size() > cp ) {
            tail = tail -> prev;
            mp.erase(tail -> next -> key);
            delete tail -> next; 
            tail -> next = nullptr;
        }
    }
}

int get(int k) {
    
    auto it = mp.find(k);
    
    if ( it != mp.end() ) {
        return it -> second -> value;
    }
    return -1;
    }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}


