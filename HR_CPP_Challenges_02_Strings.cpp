/* HackerRank - C++ - Challenges - II - Strings */


/* 1. Strings - Strings */
/*
C++ provides a nice alternative data type to manipulate strings, and the data type is conveniently called string. Some of its widely used features are the following:

  *  Declaration:

string a = "abc";

  *  Size:

int len = a.size();

  *  Concatenate two strings:

string a = "abc";
string b = "def";
string c = a + b; // c = "abcdef".

  *  Accessing ith element:

string s = "abc";
char   c0 = s[0];   // c0 = 'a'
char   c1 = s[1];   // c1 = 'b'
char   c2 = s[2];   // c2 = 'c'

s[0] = 'z';         // s = "zbc"

P.S.: We will use cin/cout to read/write a string.

Input Format

You are given two strings, a and b, separated by a new line. Each string will consist of lower case Latin characters ('a'-'z').

Output Format

In the first line print two space-separated integers, representing the length of a and b respectively.
In the second line print the string produced by concatenating a and b (a + b).
In the third line print two strings separated by a space, a' and b'. a' and b' are the same as a and b, respectively, except that their first characters are swapped.

Sample Input

abcd
ef

Sample Output

4 2
abcdef
ebcd af

Explanation

  *  a = "abcd"
  *  b = "ef"
  *  |a| = 4
  *  |b| = 2
  *  a + b = "abcdef"
  *  a' = "ebcd"
  *  b' = "af"
*/
/* Solution */

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Complete the program
    string a,b;
    cin >> a >> b;
    int lena,lenb;
    lena = a.size();
    lenb = b.size();
    cout << lena << " " << lenb << endl;
    cout << a+b << endl;
    char c=a[0];
    char d=b[0];
    a[0] = d;
    b[0] = c;
    cout << a << " " << b;
}


/* 2. Strings - StringStream */
/*
In this challenge, we work with string streams.

stringstream is a stream class to operate on strings. It implements input/output operations on memory (string) based streams. stringstream can be helpful in different type of parsing. The following operators/functions are commonly used here

  *  Operator >> Extracts formatted data.
  *  Operator << Inserts formatted data.
  *  Method str() Gets the contents of underlying string device object.
  *  Method str(string) Sets the contents of underlying string device object.

Its header file is sstream.

One common use of this class is to parse comma-separated integers from a string (e.g., "23,4,56").

stringstream ss("23,4,56");
char ch;
int a, b, c;
ss >> a >> ch >> b >> ch >> c;  // a = 23, b = 4, c = 56

Here ch is a storage area for the discarded commas.

If the >> operator returns a value, that is a true value for a conditional. Failure to return a value is false.

Given a string of comma delimited integers, return a vector of integers.

Function Description

Complete the parseInts function in the editor below.

parseInts has the following parameters:

  *  string str: a string of comma separated integers

Returns

  *  vector<int>: a vector of the parsed integers.

Note You can learn to push elements onto a vector by solving the first problem in the STL chapter.

Input Format

There is one line of n integers separated by commas.

Constraints

The length of str is less than 8 x 10^5.

Sample Input

23,4,56

Sample Output

23
4
56

*/
/* Solution */

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    stringstream ss(str);
    char ch;
    int a;
    vector<int> list;
    while(ss){
        ss >> a >> ch;
        list.push_back(a);
    }
    return list;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}


/* 3. Strings - Attribute Parser */
/*
This challenge works with a custom-designed markup language HRML. In HRML, each element consists of a starting and ending tag, and there are attributes associated with each tag. Only starting tags can have attributes. We can call an attribute by referencing the tag, followed by a tilde, '~' and the name of the attribute. The tags may also be nested.

The opening tags follow the format:

<tag-name attribute1-name = "value1" attribute2-name = "value2" ...>

The closing tags follow the format:

</tag-name>

The attributes are referenced as:

tag1~value  
tag1.tag2~name

Given the source code in HRML format consisting of N lines, answer Q queries. For each query, print the value of the attribute specified. Print "Not Found!" if the attribute does not exist.

Example

HRML listing
<tag1 value = "value">
<tag2 name = "name">
<tag3 another="another" final="final">
</tag3>
</tag2>
</tag1>

Queries
tag1~value
tag1.tag2.tag3~name
tag1.tag2~value

Here, tag2 is nested within tag1, so attributes of tag2 are accessed as tag1.tag2~<attribute>. Results of the queries are:

Query                 Value
tag1~value            "value"
tag1.tag2.tag3~name   "Not Found!"
tag1.tag2.tag3~final  "final"

Input Format

The first line consists of two space separated integers, N and Q. N specifies the number of lines in the HRML source program. Q specifies the number of queries.

The following N lines consist of either an opening tag with zero or more attributes or a closing tag. There is a space after the tag-name, attribute-name, '=' and value.There is no space after the last value. If there are no attributes there is no space after tag name.

Q queries follow. Each query consists of string that references an attribute in the source program.More formally, each query is of the form tag_i_1 , tag_i_2 , ... , tag_i_m ~ attr - name where m >= 1 and tag_i_1 , tag_i_2 , ... , tag_i_m are valid tags in the input.

Constraints

  *  1 ≤ N ≤ 20
  *  1 ≤ Q ≤ 20
  *  Each line in the source program contains, at most, 200 characters.
Every reference to the attributes in the Q queries contains at most 200 characters.
  *  All tag names are unique and the HRML source program is logically correct, i.e. valid nesting.
  *  A tag can may have no attributes.

Output Format

Print the value of the attribute for each query. Print "Not Found!" without quotes if the attribute does not exist.

Sample Input

4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value

Sample Output

Name1
Not Found!
HelloWorld

*/
/* Solution */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>  
using namespace std;

string find_val(vector<string> &s, string to_find, const char del){
    string ans;
    stringstream ss(to_find); 
    std::size_t pos = ss.str().find("~", 0);

    std::string search = ss.str().substr(0, pos);
    string val = ss.str().substr(pos + 1);

    stringstream subss(search);
    std::deque<std::string> tags;
    std::deque<std::string> live_tags;
    
    std::stringstream sssub (search);
    string item;
    while (getline(sssub, item, del)) {
        tags.push_back (item);
    }
    
    for (auto c:s){
        int tags_type = c.find("/",0);
        if (tags_type == string::npos) {
            live_tags.push_front( c.substr(1,  c.find(" ")-1));
        }

        if (c.find(' ' + val) != string::npos &&
            tags.size()==1 && 
            c.substr(1, tags[0].size()) == tags[0]  &&
            c.substr(c.find(val), val.size()) == val && 
            tags[0] == live_tags[0] &&
            std::count(search.begin(), search.end(), '.') + 1 == live_tags.size() )
        
        {
            string tmp;
            tmp = c.substr(c.find(val ) );
            tmp = tmp.substr(tmp.find('"') +1 );
            return tmp.substr(0, tmp.find('"'));
        }
        else if ( c.substr(1, tags[0].size()) == tags[0] && tags.size() > 1 ){
            tags.pop_front();
        }

         if (tags_type != string::npos) {
            live_tags.pop_front();
        }
    }
    
    return "Not Found!";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q ;cin >> n >> q; 
    cin >> ws;
    vector <string > v ;
    for (int i; i < n ; i++){
        string tmp;
        getline(cin, tmp);
        v.push_back(tmp);
    }
    const char  del = '.';
    for (int i; i < q ; i++){
        string tmp2;
        cin >> tmp2;
        string ans;
        ans = find_val(v, tmp2, del);
        cout<< ans + "\n";
    }
    return 0;
}


