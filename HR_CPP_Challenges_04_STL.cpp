/* HackerRank - C++ - Challenges - IV - STL */


/* 1. STL - Sets-STL */
/*
Sets are a part of the C++ STL. Sets are containers that store unique elements following a specific order. Here are some of the frequently used member functions of sets:

  *  Declaration:

set<int>s; //Creates a set of integers.

  *  Size:

int length=s.size(); //Gives the size of the set.

  *  Insert:

s.insert(x); //Inserts an integer x into the set s.

  *  Erasing an element:

s.erase(val); //Erases an integer val from the set s.

  *  Finding an element:

set<int>::iterator itr=s.find(val); //Gives the iterator to the element val if it is found otherwise returns s.end() .
Ex: set<int>::iterator itr=s.find(100); //If 100 is not present then it==s.end().

  *  To know more about sets click Here (https://cplusplus.com/reference/set/set/). Coming to the problem, you will be given Q queries. Each query is of one of the following three types:

1x: Add an element to the set x.
2x: Delete an element from the set x. (If the number x is not present in the set, then do nothing).
3x: If the number x is present in the set, then print "Yes"(without quotes) else print "No"(without quotes).

Input Format

The first line of the input contains Q where Q is the number of queries. The next Q lines contain 1 query each. Each query consists of two integers y and x where y is the type of the query and x is an integer.

Constraints

  *  1 <= Q <= 10^5
  *  1 <= y <= 3
  *  1 <= x <= 10^9

Output Format

For queries of type 3 print "Yes"(without quotes) if the number x is present in the set and if the number is not present, then print "No"(without quotes).
Each query of type 3 should be printed in a new line.

Sample Input

8
1 9
1 6
1 10
1 4
3 6
3 14
2 6
3 6

Sample Output

Yes
No
No

*/
/* Solution */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q,x,y;
    cin >> q;
    
    set<int> s;
    set<int> :: iterator iter;
    
    while(q>0){
        cin >> y >> x;
        q--;

        switch (y) {
            case 1:
            s.insert(x);  
            break;

            case 2:
            s.erase(x);
            break;

            case 3:
            iter = s.find(x);
            if(iter!=s.end()) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    } 
    return 0;
}


/* 2. STL - Vector-Sort */
/*
You are given N integers.Sort the N integers and print the sorted order.
Store the N integers in a vector.Vectors are sequence containers representing arrays that can change in size.

  *  Declaration:

vector<int>v; (creates an empty vector of integers)

  *  Size:

int size=v.size();

  *  Pushing an integer into a vector:

v.push_back(x);(where x is an integer.The size increases by 1 after this.)

  *  Popping the last element from the vector:

v.pop_back(); (After this the size decreases by 1)

  *  Sorting a vector:

sort(v.begin(),v.end()); (Will sort all the elements in the vector)

To know more about vectors, Click Here (https://cplusplus.com/reference/vector/vector/)

Input Format

The first line of the input contains N where N is the number of integers. The next line contains N integers.

Constraints

  *  1 <= N <= 10^5
  *  1 <= V_i <= 10^9, where V_i is the ith integer in the vector.

Output Format

Print the integers in the sorted order one by one in a single line followed by a space.

Sample Input

5
1 6 10 8 4

Sample Output

1 4 6 8 10

*/
/* Solution */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    vector<int>v(N);
    
    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<N; i++) {
        cout << v[i] << " ";
    }
    
    return 0;
}


/* 3. STL - Vector-Erase */
/*
You are provided with a vector of N integers. Then, you are given 2 queries. For the first query, you are provided with 1 integer, which denotes a position in the vector. The value at this position in the vector needs to be erased. The next query consists of 2 integers denoting a range of the positions in the vector. The elements which fall under that range should be removed. The second query is performed on the updated vector which we get after performing the first query.
The following are some useful vector functions:

  *  erase(int position):

Removes the element present at position.  
Ex: v.erase(v.begin()+4); (erases the fifth element of the vector v)

  *  erase(int start,int end):

Removes the elements in the range from start to end inclusive of the start and exclusive of the end.
Ex:v.erase(v.begin()+2,v.begin()+5);(erases all the elements from the third element to the fifth element.)

Input Format

The first line of the input contains an integer N.The next line contains N space separated integers(1-based index).The third line contains a single integer x, denoting the position of an element that should be removed from the vector. The fourth line contains two integers a and b denoting the range that should be erased from the vector inclusive of a and exclusive of b.

Constraints

  *  1 ≤ N ≤ 10^5
  *  1 ≤ x ≤ N
  *  1 ≤ a < b ≤ N

Output Format

Print the size of the vector in the first line and the elements of the vector after the two erase operations in the second line separated by space.

Sample Input

6
1 4 6 2 8 9
2
2 4

Sample Output

3
1 8 9

Explanation

The first query is to erase the 2nd element in the vector, which is 4. Then, modifed vector is {1 6 2 8 9}, we want to remove the range of 2~4, which means the 2nd and 3rd elements should be removed. Then 6 and 2 in the modified vector are removed and we finally get {1 8 9}
*/
/* Solution */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    
    cin >> N;
    
    vector <int> v(N);
    
    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
    
    int x;
    cin >> x;
    
    int a;
    int b;
    
    cin >> a;
    cin >> b;
    
    v.erase(v.begin()+(x-1));
    v.erase(v.begin()+(a-1), v.begin()+(b-1));
    
    cout << v.size() << endl;
    
    for(int j=0; j<v.size(); j++) {
        cout << v[j] << " ";
    }
    
    return 0;
}


/* 4. STL - Lower Bound-STL */
/*
You are given N integers in sorted order. Also, you are given Q queries. In each query, you will be given an integer and you have to tell whether that integer is present in the array. If so, you have to tell at which index it is present and if it is not present, you have to tell the index at which the smallest integer that is just greater than the given number is present.

Lower bound is a function that can be used with a sorted vector. Learn how to use lower bound to solve this problem by clicking here. (https://cplusplus.com/reference/algorithm/lower_bound/)

Input Format

The first line of the input contains the number of integers N. The next line contains N integers in sorted order. The next line contains Q, the number of queries. Then Q lines follow each containing a single integer Y.

Note: If the same number is present multiple times, you have to print the first index at which it occurs. Also, the input is such that you always have an answer for each query.

Constraints

  *  1 ≤ N ≤ 10^5
  *  1 ≤ X_i ≤ 10^9, where X_i is ith element in the array.
  *  1 ≤ Q ≤ 10^5
  *  1 ≤ Y ≤ 10^9

Output Format

For each query you have to print "Yes" (without the quotes) if the number is present and at which index(1-based) it is present separated by a space.

If the number is not present you have to print "No" (without the quotes) followed by the index of the next smallest number just greater than that number.

You have to output each query in a new line.

Sample Input

 8
 1 1 2 2 6 9 9 15
 4
 1
 4
 9
 15

Sample Output

 Yes 1
 No 5
 Yes 6
 Yes 8

*/
/* Solution */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    
    vector<int>v(N);
    for(int i=0; i<N; i++) {
        cin >> v[i];
    }
    
    int Q;
    cin >> Q;
        
    while (Q > 0) {
        int y;
        cin >> y;
        
        auto it = lower_bound(v.begin(), v.end(), y);
        
        if( *it == y ) {
            cout << "Yes" <<" " << it - v.begin() + 1 <<endl; 
        }
        else{
            cout << "No" <<" " << it - v.begin() + 1 <<endl; 
        }
        Q--;
    }
    
    return 0;
}


/* 5. STL - Maps-STL */
/*
Maps are a part of the C++ STL.Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.The mainly used member functions of maps are:

  *  Map Template:

std::map <key_type, data_type>

  *  Declaration:

map<string,int>m; //Creates a map m where key_type is of type string and data_type is of type int.

  *  Size:

int length=m.size(); //Gives the size of the map.

  *  Insert:

m.insert(make_pair("hello",9)); //Here the pair is inserted into the map where the key is "hello" and the value associated with it is 9.

  *  Erasing an element:

m.erase(val); //Erases the pair from the map where the key_type is val.

  *  Finding an element:

map<string,int>::iterator itr=m.find(val); //Gives the iterator to the element val if it is found otherwise returns m.end() .
Ex: map<string,int>::iterator itr=m.find("Maps"); //If Maps is not present as the key value then itr==m.end().

  *  Accessing the value stored in the key:

To get the value stored of the key "MAPS" we can do m["MAPS"] or we can get the iterator using the find function and then by itr->second we can access the value.

To know more about maps click Here (https://cplusplus.com/reference/map/map/).

You are appointed as the assistant to a teacher in a school and she is correcting the answer sheets of the students.Each student can have multiple answer sheets.So the teacher has Q queries:

1 X Y:Add the marks Y to the student whose name is X.

2 X: Erase the marks of the students whose name is X.

3 X: Print the marks of the students whose name is X. (If X didn't get any marks print 0.)

Input Format

The first line of the input contains Q where Q is the number of queries. The next Q lines contain 1 query each. The first integer, type of each query is the type of the query. If query is of type 1, it consists of one string and an integer X and Y where is the name of the student and Y is the marks of the student. If query is of type 2 or 3, it consists of a single string X where X is the name of the student.

Constraints

  *  1 ≤ Q ≤ 10^5
  *  1 ≤ type ≤ 3
  *  1 ≤ ∣X∣ ≤ 6
  *  1 ≤ Y ≤ 10^3

Output Format

For queries of type 3 print the marks of the given student.

Sample Input

7
1 Jesse 20
1 Jess 12
1 Jess 18
3 Jess
3 Jesse
2 Jess
3 Jess

Sample Output

30
20
0

*/
/* Solution */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map <string,int> m;
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int q = 0;
        cin >> q;
        string x;
        if (q == 1)
        {
            int y = 0;
            cin >> x;
            cin >> y;
            m[x] += y;
        }
        else if (q == 2)
        {
            cin >> x;
            m.erase(x);
        }
        else
        {
            cin >> x;
            map<string,int>::iterator itr=m.find(x);
            if (itr != m.end())
                cout << m[x] << endl;
            else
                cout << 0 << endl;
        }
    }
}


/* 6. STL - Print Pretty */
/*
Given a text file with many lines of numbers to format and print, for each row of 3 space-separated doubles, format and print the numbers using the specifications in the Output Format section below.

Input Format

The first line contains an integer, T, the number of test cases.
Each of the T subsequent lines describes a test case as 3 space-separated floating-point numbers: A, B, and C, respectively.

Constraints

  *  1 T 1000
  *  Each number will fit into a double.

Output Format

For each test case, print 3 lines containing the formatted A, B, and C, respectively. Each A, B, and C must be formatted as follows:

  *  1. A: Strip its decimal (i.e., truncate it) and print its hexadecimal representation (including the 0x prefix) in lower case letters.
  *  2. B: Print it to a scale of 2 decimal places, preceded by a + or - sign (indicating if it's positive or negative), right justified, and left-padded with underscores so that the printed result is exactly 15 characters wide.
  *  3. C: Print it to a scale of exactly nine decimal places, expressed in scientific notation using upper case.

Sample Input

1  
100.345 2006.008 2331.41592653498

Sample Output

0x64             
_______+2006.01  
2.331415927E+03

Explanation

For the first line of output, (100)_10 -> (64)_16 (in reverse, 6 x 16^1 + 4 x 16^0 = (100)_10).
The second and third lines of output are formatted as described in the Output Format section.
*/
/* Solution */

#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */
        cout << std::hex << std::left << std::showbase << std::nouppercase;
        cout << (long long) A << endl;
        cout << std::dec << std::right << std::setw(15) << std::setfill('_') << std::showpos << std::fixed << std::setprecision(2);
        cout << B << endl;
        cout << std::scientific << std::uppercase << std::noshowpos << std::setprecision(9);
        cout << C << endl;

	}
	return 0;

}


/* 7. STL - Deque-STL */
/*
Double ended queue or Deque(part of C++ STL) are sequence containers with dynamic sizes that can be expanded or contracted on both ends (either its front or its back). The member functions of deque that are mainly used are:

  *  Deque Template:

std::deque<value_type>

  *  Declaration:

deque<int> mydeque; //Creates a double ended queue of deque of int type

  *  Size

int length = mydeque.size(); //Gives the size of the deque

  *  Push

mydeque.push_back(1); //Pushes element at the end
mydeque.push_front(2); //Pushes element at the beginning

  *  Pop

mydeque.pop_back(); //Pops element from the end
mydeque.pop_front(); //Pops element from the beginning

  *  Empty

mydeque.empty() //Returns a boolean value which tells whether the deque is empty or not

To know more about deque, click here (https://cplusplus.com/reference/deque/deque/)

Given a set of arrays of size N and an integer K, you have to find the maximum integer for each and every contiguous subarray of size K for each of the given arrays.

Input Format

First line of input will contain the number of test cases T. For each test case, you will be given the size of array N and the size of subarray to be used K. This will be followed by the elements of the array Ai.

Constraints

  *  1 <= T <= 1000
  *  1 <= N <= 10000
  *  1 <= K <= N
  *  1 <= A_i <= 10000, where A_i is the ith element in the array A.

Output Format

For each of the contiguous subarrays of size K of each array, you have to print the maximum integer.

Sample Input

2
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10

Sample Output

4 6 6 4
8 8 8 10

Explanation

For the first case, the contiguous subarrays of size 2 are {3,4},{4,6},{6,3} and {3,4}. The 4 maximum elements of subarray of size 2 are: 4 6 6 4.

For the second case,the contiguous subarrays of size 4 are {3,4,5,8},{4,5,8,1},{5,8,1,4} and {8,1,4,10}. The 4 maximum element of subarray of size 4 are: 8 8 8 10.
*/
/* Solution */

#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k) {
    //Write your code here.
    deque<int> Qi(k);
    int i;
    for (i = 0; i < k; i++) {
        while ((!Qi.empty()) && (arr[i] >= arr[Qi.back()]))
            Qi.pop_back();
        Qi.push_back(i);
    }
    for ( ; i < n; i++) {
        cout << arr[Qi.front()] << " ";
        while ((!Qi.empty()) && (Qi.front() <= i - k))
            Qi.pop_front();
        while ((!Qi.empty()) && (arr[i] >= arr[Qi.back()]))
            Qi.pop_back();
        Qi.push_back(i);
    }
    cout << arr[Qi.front()] << endl;
}

int main() {
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}


