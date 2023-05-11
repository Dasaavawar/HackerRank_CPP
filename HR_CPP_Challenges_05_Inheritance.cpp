/* HackerRank - C++ - Introduction - V - Inheritance */


/* 1. Inheritance - Inheritance Introduction */
/*
One of the important topics of Object Oriented Programming is Inheritance. Inheritance allows us to define a class in terms of another class, which allows us in the reusability of the code.Check out the code below:

class Triangle{
    public:
        void triangle(){
            cout<<"I am a triangle\n";
        }
};

The class Triangle has a function called triangle(). Now we create a class derived from the base class Triangle called Isosceles.

class Isosceles : public Triangle{
    public:
        void isosceles(){
            cout<<"I am an isosceles triangle\n";
        }
};

Now we can create a derived class object and use it to access the functions of the base class.

int main(){
    Isosceles isc;
    isc.isosceles();
    isc.triangle();
    return 0;
}

This code will print:

I am an isosceles triangle
I am a triangle

Now write a function in Isosceles class such that the output is as given below.

Sample Output

I am an isosceles triangle
In an isosceles triangle two sides are equal
I am a triangle

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Triangle{
    public:
    	void triangle(){
     		cout<<"I am a triangle\n";
    	}
};

class Isosceles : public Triangle{
    public:
    	void isosceles(){
    		cout<<"I am an isosceles triangle\n";
    	}
  		//Write your code here.
        void description(){
            cout<<"In an isosceles triangle two sides are equal\n";
        }
};

int main(){
    Isosceles isc;
    isc.isosceles();
  	isc.description();
    isc.triangle();
    return 0;
}


/* 2. Inheritance - Rectangle Area */
/*
In this challenge, you are required to compute the area of a rectangle using classes.

Create two classes:

Rectangle

The Rectangle class should have two data fields-width and height of int types. The class should have display() method, to print the width and height of the rectangle separated by space.

RectangleArea

The RectangleArea class is derived from Rectangle class, i.e., it is the sub-class of Rectangle class. The class should have read_input() method, to read the values of width and height of the rectangle. The RectangleArea class should also overload the display() method to print the area (width x height) of the rectangle.

Input Format

The first and only line of input contains two space separated integers denoting the width and height of the rectangle.

Constraints

  *  1 ≤ width, height ≤ 100

Output Format

The output should consist of exactly two lines:
In the first line, print the width and height of the rectangle separated by space.
In the second line, print the area of the rectangle.

Sample Input

10 5

Sample Output

10 5
50

Explanation

As, width = 10 and height = 5, so width x height = 50
*/
/* Solution */

#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */
class Rectangle{
    public:
        int width;
        int height;
        void display(){
            cout<<width<<" "<<height<<endl;
        }
};

class RectangleArea: public Rectangle{
    public:
    void read_input() {
        cin>>width;
        cin>>height;
    };
    void display() {
        cout<<height*width;
    }
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}


/* 3. Inheritance - Multi Level Inheritance  */
/*
This challenge is an extension of a previous challenge named Inheritance-Introduction. We highly recommend solving Inheritance-Introduction before solving this problem.

In the previous problem, we learned about inheritance and how can a derived class object use the member functions of the base class.

In this challenge, we explore multi-level inheritance. Suppose, we have a class A which is the base class and we have a class B which is derived from class A and we have a class C which is derived from class B, we can access the functions of both class A and class B by creating an object for class C. Hence, this mechanism is called multi-level inheritance. (B inherits A and C inherits B.)

Create a class called Equilateral which inherits from Isosceles and should have a function such that the output is as given below.

Sample Output

I am an equilateral triangle
I am an isosceles triangle
I am a triangle

*/
/* Solution */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Triangle{
	public:
		void triangle(){
			cout<<"I am a triangle\n";
		}
};

class Isosceles : public Triangle{
  	public:
  		void isosceles(){
    		cout<<"I am an isosceles triangle\n";
  		}
};

class Equilateral : public Isosceles{
      public:
          void equilateral(){
            cout<<"I am an equilateral triangle\n";
          }
};

//Write your code here.
int main(){
  
    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}


/* 4. Inheritance - Accessing Inherited Functions */
/*
You are given three classes A, B and C. All three classes implement their own version of func.

In class A, func multiplies the value passed as a parameter by 2:

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

In class B, func multiplies the value passed as a parameter by 3:

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

In class C, func multiplies the value passed as a parameter by 5:

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};

You are given a class D:

class D 
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val = 1;
		 }


		 //Implement this function
		 void update_val(int new_val)
		 {

			
		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};

You need to modify the class D and implement the function update_val which sets D's val to new_val by manipulating the value by only calling the func defined in classes A, B and C.

It is guaranteed that new_val has only 2, 3 and 5 as its prime factors.

Input Format

Implement class D's function update_val. This function should update D's val only by calling A, B and C's func.

Constraints

  *  1 ≤ new_val ≤ 10000

Note: The new_val only has 2, 3 and 5 as its prime factors.

Sample Input

new_val = 30

Sample Output

A's func will be called once.
B's func will be called once.
C's func will be called once.

Explanation

Initially, val = 1.

A's func is called once:

val = val*2  
val = 2

B's func is called once:

val = val*3
val = 6

C's func is called once:

val = val*5
val = 30

*/
/* Solution */

#include<iostream>

using namespace std;

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};

class D : public A, public B, public C
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val = 1;
		 }


		 //Implement this function
		 void update_val(int new_val)
		 {
             while (new_val % 2 == 0)
            {  
                new_val /= 2;
                A::func(val);
            }
             
            while (new_val % 3 == 0)       
            {
                new_val /= 3;
                B::func(val);
            }
             
            while (new_val % 5 == 0)
            {
                new_val /= 5;
                C::func(val);
            }		
		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};



void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);

}


/* 5. Inheritance - Magic Spells */
/*
While playing a video game, you are battling a powerful dark wizard. He casts his spells from a distance, giving you only a few seconds to react and conjure your counterspells. For a counterspell to be effective, you must first identify what kind of spell you are dealing with.

The wizard uses scrolls to conjure his spells, and sometimes he uses some of his generic spells that restore his stamina. In that case, you will be able to extract the name of the scroll from the spell. Then you need to find out how similar this new spell is to the spell formulas written in your spell journal.

Spend some time reviewing the locked code in your editor, and complete the body of the counterspell function.

Check Dynamic cast (https://en.cppreference.com/w/cpp/language/dynamic_cast) to get an idea of how to solve this challenge.

Input Format

The wizard will read t scrolls, which are hidden from you.
Every time he casts a spell, it's passed as an argument to your counterspell function.

Constraints

  *  1 ≤ t ≤ 100
  *  1 ≤ |s| ≤ 1000, where s is a scroll name.
  *  Each scroll name, s, consists of uppercase and lowercase letters.

Output Format

After identifying the given spell, print its name and power.
If it is a generic spell, find a subsequence of letters that are contained in both the spell name and your spell journal. Among all such subsequences, find and print the length of the longest one on a new line.

Sample Input

3
fire 5
AquaVitae 999 AruTaVae
frost 7

Sample Output

Fireball: 5
6
Frostbite: 7

Explanation

Fireball and Frostbite are common spell types.
AquaVitae is not, and when you compare it with AruTaVae in your spell journal, you get a sequence: AuaVae
*/
/* Solution */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
   
  /* Enter your code here */
    if (Fireball *s = dynamic_cast<Fireball *>(spell))
    {
        s->revealFirepower();
    }
    else if (Frostbite *s = dynamic_cast<Frostbite *>(spell))
    {
        s->revealFrostpower();
    }
    else if (Thunderstorm *s = dynamic_cast<Thunderstorm *>(spell))
    {
        s->revealThunderpower();
    }
    else if (Waterbolt *s = dynamic_cast<Waterbolt *>(spell))
    {
        s->revealWaterpower();
    }
    else
    {
        string scroll_name = spell->revealScrollName();
        string journal = SpellJournal::read();
        size_t s_size = scroll_name.size();
        size_t j_size = journal.size();
        if (s_size == 1 && j_size == 1 && scroll_name == journal)
        {
            cout << 1 << endl;
        }
        else
        {
            vector<vector<size_t>> lcs_table(s_size + 1, vector<size_t>(j_size + 1));
            for (size_t i = 1; i <= s_size; ++i)
            {
                for (size_t j = 1; j <= j_size; ++j)
                {
                    if (scroll_name[i - 1] == journal[j - 1])
                    {
                        lcs_table[i][j] = lcs_table[i - 1][j - 1] + 1;
                    }
                    else
                    {
                        lcs_table[i][j] = max(lcs_table[i][j - 1], lcs_table[i - 1][j]);
                    }
                }
            }
          cout << lcs_table[s_size][j_size] << endl;
        }
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}


