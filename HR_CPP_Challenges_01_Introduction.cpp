/* HackerRank - C++ - Challenges - I - Introduction */


/* 0. Algorithms - Solve Me First in C++ */
/*
Complete the function solveMeFirst to compute the sum of two integers.

Example

a = 7
b = 3

Return 10.

Function Description

Complete the solveMeFirst function in the editor below.

solveMeFirst has the following parameters:

  1.  int a: the first value
  2.  int b: the second value

Returns

- int: the sum of a and b

Constraints

1 ≤ a, b ≤ 1000

Sample Input

a = 2
b = 3

Sample Output

5

Explanation

2 + 3 = 5.
*/
/* Solution */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solveMeFirst(int a, int b) {
    return a+b;
}

int main() {
    int num1, num2;
    int sum;
    cin>>num1>>num2;
    sum = solveMeFirst(num1,num2);
    cout<<sum;
    return 0;
}


/* 1. Introduction - Say "Hello, World!" With C++ */
/*
Objective

This is a simple challenge to help you practice printing to stdout (https://en.wikipedia.org/wiki/Standard_streams#Standard_output_.28stdout.29). You may also want to complete Solve Me First in C++ before attempting this challenge.

We're starting out by printing the most famous computing phrase of all time! In the editor below, use either printf (https://cplusplus.com/reference/cstdio/printf/) or cout (https://cplusplus.com/reference/iostream/cout/) to print the string Hello World! to stdout.

The more popular command form is cout. It has the following basic form:

cout<<value_to_print<<value_to_print;

Any number of values can be printed using one command as shown.

The printf command comes from C language. It accepts an optional format specification and a list of variables. Two examples for printing a string are:

printf("%s", string); printf(string);

Note that neither method adds a newline. It only prints what you tell it to.

Output Format

Print Hello, World! to stdout.

Sample Output

Hello, World!

*/
/* Solution */

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    printf("Hello, World!");
    return 0;
}


/* 2. Introduction - Input and Output */
/* 
Objective

In this challenge, we practice reading input from stdin and printing output to stdout.

In C++, you can read a single whitespace-separated token of input using cin (https://cplusplus.com/reference/iostream/cin/), and print output to stdout using cout (https://cplusplus.com/reference/cstdio/printf/). For example, let's say we declare the following variables:

string s;
int n;

and we want to use cin to read the input "High 5" from stdin. We can do this with the following code:

cin >> s >> n;

This reads the first word ("High") from stdin and saves it as string s, then reads the second word ("5") from stdin and saves it as integer n. If we want to print these values to stdout, separated by a space, we write the following code:

cout << s << " " << n << endl;

This code prints the contents of string s, a single space (" "), then the integer n. We end our line of output with a newline using endl (https://cplusplus.com/reference/ostream/endl/). This results in the following output:

High 5

Task

Read 3 numbers from stdin and print their sum to stdout.

Input Format

One line that contains 3 space-separated integers: a, b, and c.

Constraints

1 ≤ a, b, c ≤ 1000

Output Format

Print the sum of the three numbers on a single line.

Sample Input

1 2 7

Sample Output

10

Explanation

The sum of the three numbers is 1 + 2 + 7 = 10.
*/
/* Solution */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a;
    int b;
    int c;
    cin >> a >> b >> c;
    cout << a+b+c;    
    return 0;
}


/* 3. Introduction - Basic Data Types */
/*
Some C++ data types, their format specifiers, and their most common bit widths are as follows:

  1.  Int ("%d"): 32 Bit integer
  2.  Long ("%ld"): 64 bit integer
  3.  Char ("%c"): Character type
  4.  Float ("%f"): 32 bit real value
  5.  Double ("%lf"): 64 bit real value

Reading
To read a data type, use the following syntax:

scanf("`format_specifier`", &val)

For example, to read a character followed by a double:

char ch;
double d;
scanf("%c %lf", &ch, &d);

For the moment, we can ignore the spacing between format specifiers.

Printing
To print a data type, use the following syntax:

printf("`format_specifier`", val)

For example, to print a character followed by a double:

char ch = 'd';
double d = 234.432;
printf("%c %lf", ch, d);

Note: You can also use cin and cout instead of scanf and printf; however, if you are taking a million numbers as input and printing a million lines, it is faster to use scanf and printf.

Input Format

Input consists of the following space-separated values: int, long, char, float, and double, respectively.

Output Format

Print each element on a new line in the same order it was received as input. Note that the floating point value should be correct up to 3 decimal places and the double to 9 decimal places.

Sample Input

3 12345678912345 a 334.23 14049.30493

Sample Output

3
12345678912345
a
334.230
14049.304930000

Explanation

  *  Print int 3,
  *  followed by long 12345678912345,
  *  followed by char a,
  *  followed by float 334.23,
  *  followed by double 14049.30493.
*/
/* Solution */

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    int a;
    int long b;
    char c;
    float d;
    double e;
    scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);
    printf("%d\n%ld\n%c\n%f\n%lf", a, b, c, d, e);
    return 0;
}


/* 4. Introduction - Conditional Statements */
/* 
if and else are two of the most frequently used conditionals in C/C++, and they enable you to execute zero or one conditional statement among many such dependent conditional statements. We use them in the following ways:

  1.  if: This executes the body of bracketed code starting with statement1 if statement2 evaluates to true.

if (condition) {
    statement1;
    ...
}

  2.  if - else: This executes the body of bracketed code starting with statement1 if condition evaluates to true, or it executes the body of code starting with statement2 if condition evaluates to false. Note that only one of the bracketed code sections will ever be executed.

if (condition) {
    statement1;
    ...
}
else {
    statement2;
    ...
}

  3.  if - else if - else: In this structure, dependent statements are chained together and the condition for each statement is only checked if all prior conditions in the chain evaluated to false. Once a condition evaluates to true, the bracketed code associated with that statement is executed and the program then skips to the end of the chain of statements and continues executing. If each condition in the chain evaluates to false, then the body of bracketed code in the else block at the end is executed.

if(first condition) {
    ...
}
else if(second condition) {
    ...
}
.
.
.
else if((n-1)'th condition) {
    ....
}
else {
    ...
}

Given a positive integer n, do the following:

  *  If 1 ≤ n ≤ 9, print the lowercase English word corresponding to the number (e.g., one for 1, two for 2., etc.).
  *  If n > 9, print Greater than 9.

Input Format

A single integer, n.

Constraints

1 ≤ n ≤ 10^9

Output Format

If 1 ≤ n ≤ 9, then print the lowercase English word corresponding to the number (e.g., one for 1, two for 2, etc.); otherwise, print Greater than 9.

Sample Input 0

5

Sample Output 0

five

Explanation 0

five is the English word for the number 5.

Sample Input 1

8

Sample Output 1

eight

Explanation 1

eight is the English word for the number 8.

Sample Input 2

44

Sample Output 2

Greater than 9

Explanation 2

n = 44 is greater than 9, so we print Greater than 9.
*/
/* Solution */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    // Write your code here
    if(n==1) {
        cout << "one";
    } else if(n==2) {
        cout << "two";
    } else if(n==3) {
        cout << "three";
    } else if(n==4) {
        cout << "four";
    } else if(n==5) {
        cout << "five";
    } else if(n==6) {
        cout << "six";
    } else if(n==7) {
        cout << "seven";
    } else if(n==8) {
        cout << "eight";
    } else if(n==9) {
        cout << "nine";
    } else {
        cout << "Greater than 9";
    }
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}


/* 5. Introduction - For Loop */
/* 
A for loop is a programming language statement which allows code to be repeatedly executed.

The syntax is

for ( <expression_1> ; <expression_2> ; <expression_3> )
    <statement>

  1.  expression_1 is used for intializing variables which are generally used for controlling the terminating flag for the loop.
  2.  expression_2 is used to check for the terminating condition. If this evaluates to false, then the loop is terminated.
  3.  expression_3 is generally used to update the flags/variables.

A sample loop is

for(int i = 0; i < 10; i++) {
    ...
}

In this challenge, you will use a for loop to increment a variable through a range.

Input Format

You will be given two positive integers, a and b (a ≤ b), separated by a newline.

Output Format

For each integer n in the inclusive interval [a, b]:

  *  If 1 ≤ n ≤ 9, then print the English representation of it in lowercase. That is "one" for 1, "two" for 2, and so on.
  *  Else if n > 9 and it is an even number, then print "even".
  *  Else if n > 9 and it is an odd number, then print "odd".

Note:

[a, b] = {x ∈ ℤ | a ≤ x ≤ b} = {a, a + 1, ..., b}

Sample Input

8
11

Sample Output

eight
nine
even
odd

*/
/* Solution */

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    // Complete the code.
    std::string num_words[] = {"", "one", "two", "three", "four","five", "six", "seven","eight","nine","ten"};
    int a;
    int b;
    std::cin >> a;
    std::cin >> b;
    
    for (int n=a; n<=b; n++) {
        if (n>=1 && n<=9) {
            std::cout << num_words[n] << '\n';            
        } else if(n>9) {
            (n&0b1)? std::cout << "odd\n": std::cout << "even\n";            
        }
}
    
    return 0;
}


/* 6. Introduction - Functions */
/* 
Functions are a bunch of statements glued together. A function is provided with zero or more arguments, and it executes the statements on it. Based on the return type, it either returns nothing (void) or something.

The syntax for a function is

return_type function_name(arg_type_1 arg_1, arg_type_2 arg_2, ...) {
    ...
    ...
    ...
    [if return_type is non void]
        return something of type `return_type`;
}

For example, a function to return the sum of four parameters can be written as

int sum_of_four(int a, int b, int c, int d) {
    int sum = 0;
    sum += a;
    sum += b;
    sum += c;
    sum += d;
    return sum;
}

Write a function int max_of_four(int a, int b, int c, int d) which returns the maximum of the four arguments it receives.

+= : Add and assignment operator. It adds the right operand to the left operand and assigns the result to the left operand.
a += b is equivalent to a = a + b;

Input Format

Input will contain four integers -a, b, c, d, one per line.

Output Format

Return the greatest of the four integers.
PS: I/O will be automatically handled.

Sample Input

3
4
6
5

Sample Output

6

*/
/* Solution */

#include <iostream>
#include <cstdio>
using namespace std;

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/
int max_of_four(int a, int b, int c, int d) {
    int max_num=0;
    if (a>b && a>c && a>d) {
        max_num=a;
    } else if (b>a && b>c && b>d) {
        max_num=b;
    } else if (c>a && c>b && c>d) {
        max_num=c;
    } else {
        max_num=d;
    } 
    return max_num;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}


/* 7. Introduction - Pointer */
/* 
A pointer (https://en.wikipedia.org/wiki/Pointer_%28computer_programming%29) in C++ is used to share a memory address among different contexts (primarily functions). They are used whenever a function needs to modify the content of a variable, but it does not have ownership.

In order to access the memory address of a variable, val, prepend it with & sign. For example, &val returns the memory address of val.

This memory address is assigned to a pointer and can be shared among functions. For example, int*p = &val assigns the memory address of val to pointer p. To access the content of the memory pointed to, prepend the variable name with a *. For example, *p will return the value stored in val and any modification to it will be performed on val.

void increment(int *v) {
    (*v)++;
}

int main() {
    int a;
    scanf("%d", &a);
    increment(&a);
    printf("%d", a);
    return 0;
}  

Function Description

Complete the update function in the editor below.

update has the following parameters:

  *  int *a: an integer
  *  int *b: an integer

Returns

  1.  The function is declared with a void return type, so there is no value to return. Modify the values in memory so that a contains their sum and b contains their absoluted difference.
  2.  a' = a + b
  3.  b' = |a - b|


Input Format

Input will contain two integers, a and b, separated by a newline.

Sample Input

4
5

Sample Output

9
1

Explanation

  *  a' = 4 + 5 = 9
  *  b' = |4 - 5| = 1
*/
/* Solution */

#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int temp = *a;
    *a = *a + *b;
    *b = temp - *b;
    if(*b < 0) {
        *b = -(*b);
    }
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}


/* 8. Introduction - Arrays Introduction */
/* 
An array is a series of elements of the same type placed in contiguous memory locations that can be individually referenced by adding an index to a unique identifier.

For arrays of a known size, 10 in this case, use the following declaration:

int arr[10]; //Declares an array named arr of size 10, i.e, you can 
store 10 integers.

Note Unlike C, C++ allows dynamic allocation of arrays at runtime without special calls like malloc(). If n = 10, int arr[n] will create an array with space for 10 integers.

Accessing elements of an array:

Indexing in arrays starts from 0.So the first element is stored at 
arr[0],the second element at arr[1] and so on through arr[9].

You will be given an array of N integers and you have to print the integers in the reverse order.

Input Format

The first line of the input contains N, where N is the number of integers.The next line contains N space-separated integers.

Constraints

  *  1 <= N <= 1000
  *  1 <= A[i] <= 10000, where A[i] is the ith integer in the array.

Output Format

Print the N integers of the array in the reverse order, space-separated on a single line.

Sample Input

4
1 4 3 2

Sample Output

2 3 4 1

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
    int arr[N];
    for (int i = 0; i<N; i++) {
        cin >> arr[i];
    }
    for (int i = N-1; i>=0; i--) {
        cout << arr[i] << " ";
    }
    return 0;
}


/* 9. Introduction - Variable Sized Arrays */
/* 
Consider an n-element array, a, where each index i in the array contains a reference to an array of k_i integers (where the value of k_i varies from array to array). See the Explanation section below for a diagram.

Given a, you must answer q queries. Each query is in the format i j, where i denotes an index in array a and j denotes an index in the array located at a[i]. For each query, find and print the value of element j in the array at location a[i] on a new line.

Click here to know more about how to create variable sized arrays in C++.

Input Format

  *  The first line contains two space-separated integers denoting the respective values of n (the number of variable-length arrays) and q (the number of queries).
  *  Each line i of the n subsequent lines contains a space-separated sequence in the format k a[i]0 a[i]1 … a[i]k-1 describing the k-element array located at a[i].
  *  Each of the q subsequent lines contains two space-separated integers describing the respective values of i (an index in array a) and j (an index in the array referenced by a[i]) for a query.

Constraints

  *  1 ≤ n ≤ 10^5
  *  1 ≤ q ≤ 10^5
  *  1 ≤ k ≤ 3 * 10^5
  *  n ≤ Σ k ≤ 3 * 10^5
  *  0 ≤ i < n
  *  0 ≤ j < k
  *  All indices in this challenge are zero-based.
  *  All the given numbers are non negative and are not greater than 10^6

Output Format

For each pair of i and j values (i.e., for each query), print a single integer that denotes the element located at index j of the array referenced by a[i]. There should be a total of q lines of output.

Sample Input

2 2
3 1 5 4
5 1 2 8 9 3
0 1
1 3

Sample Output

5
9

Explanation

The diagram below depicts our assembled Sample Input:

[/data/Variable_Sized_Arrays.png]

(https://s3.amazonaws.com/hr-challenge-images/14507/1476906485-2c93045320-variable-length-arrays.png)

We perform the following q = 2 queries:

  1.  Find the array located at index i = 0, which corresponds to a[0] = [1, 5, 4]. We must print the value at index j = 1 of this array which, as you can see, is 5.
  2.  Find the array located at index i = 1, which corresponds to a[1] = [1, 2, 8, 9, 3]. We must print the value at index j = 3 of this array which, as you can see, is 9.
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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n);
    
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
    }
    
    for (int query = 0; query < q; query++) {
        int i, j;
        cin >> i >> j;
        cout << a[i][j] << endl;
    }
     
    return 0;
}

