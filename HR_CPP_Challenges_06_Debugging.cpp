/* HackerRank - C++ - Challenges - VI - Debugging */


/* 1. Debugging - Hotel Prices */
/*
In this challenge, the task is to debug the existing code to successfully execute all provided test files.

The given code defines two classes HotelRoom and HotelApartment denoting respectively a standard hotel room and a hotel apartment. An instance of any of these classes has two parameters: bedrooms and bathrooms denoting respectively the number of bedrooms and the number of bathrooms in the room.

The prices of a standard hotel room and hotel apartment are given as:

  *  Hotel Room: 50 * bedrooms + 100 * bathrooms.
  *  Hotel Apartment: The price of a standard room with the same number bedrooms and bathrooms plus 100.

For example, if a standard room costs 200, then an apartment with the same number of bedrooms and bathrooms costs 300.

In hotel's codebase, there is a piece of code reading the list of rooms booked for today and calculates the total profit for the hotel. However, sometimes calculated profits are lower than they should be.

Debug the existing HotelRoom and HotelApartment classes' implementations so that the existing code computing the total profit returns a correct profit.

Your function will be tested against several cases by the locked template code.

Input Format

The input is read by the provided locked code template.
In the first line, there is a single integer n denoting the number of rooms booked for today.
After that n lines follow. Each of these lines begins with a room_type which is either standard or apartment, and is followed by the number of bedrooms and the number of bathrooms in this room.

Constraints

  *  1 ≤ n ≤ 100
  *  There is at least 1 and at most 5 bedrooms in a room
  *  There is at least 1 and at most 5 bathrooms in a room

Output Format

The output is produced by the provided and locked code template. It calculates the total profit by iterating through the vector of all rooms read from the input.

Sample Input 0

2
standard 3 1
apartment 1 1

Sample Output 0

500

Explanation 0

In the sample we have one standard room with 3 bedrooms and 1 bathroom, and one apartment with one 1 bedrooms and 1 bathroom. The price for the room is 3*50 + 100 = 250. The price for the apartment is 50 + 100 + 100 = 250. Thus the hotel profit is 250 + 250 = 500 as the sum of prices of both rooms.
*/
/* Solution */

#include <iostream>
#include <vector>

using namespace std;

class HotelRoom {
public:
    HotelRoom(int bedrooms, int bathrooms) 
    : bedrooms_(bedrooms), bathrooms_(bathrooms) {}
    
    int get_price() {
        return 50*bedrooms_ + 100*bathrooms_;
    }
private:
    int bedrooms_;
    int bathrooms_;
};

class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms) 
    : HotelRoom(bedrooms + 2, bathrooms) {}

    int get_price() {
        return HotelRoom::get_price() + 100;
    }
};

int main() {
    int n;
    cin >> n;
    vector<HotelRoom*> rooms;
    for (int i = 0; i < n; ++i) {
        string room_type;
        int bedrooms;
        int bathrooms;
        cin >> room_type >> bedrooms >> bathrooms;
        if (room_type == "standard") {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        } else {
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
        }
    }

    int total_profit = 0;
    for (auto room : rooms) {
        total_profit += room->get_price();
    }
    cout << total_profit << endl;

    for (auto room : rooms) {
        delete room;
    }
    rooms.clear();
    
    return 0;
}


/* 2. Debugging - Cpp exception handling */
/*
In this challenge, the task is to debug the existing code to successfully execute all provided test files.

You are required to extend the existing code so that it handles std::invalid_argument exception properly. More specifically, you have to extend the implementation of process_input function. It takes integer n as an argument and has to work as follows:

  *  It calls function largest_proper_divisor(n).
  *  If this call returns a value without raising an exception, it should print in a single line result=d where d is the returned value.
  *  Otherwise, if the call raises a std::invalid_argument exception, it has to print in a single line the string representation of the raised exception, i.e. its message.
  *  Finally, no matter if the exception is raised or not, it should print in a single line returning control flow to caller after any other previously printed output.

To keep the code quality high, you are advised to have exactly one line printing returning control flow to caller in the body of process_input function.

Your function will be tested against several cases by the locked template code.

Input Format

The input is read by the provided locked code template. In the only line of the input, there is a single integer n, which is going to be the argument passed to function process_input.

Constraints

  *  0 ≤ n ≤ 100

Output Format

The output should be produced by function process_input as described in the statement.

Sample Input 0

0

Sample Output 0

largest proper divisor is not defined for n=0
returning control flow to caller

Explanation 0

In the first sample, n = 0, so the call largest_proper_divisor(0) raises an exception. In this case, the function process_input prints two lines. In the first of them it prints the string representation of the raised exception, and in the second line it prints returning control flow to caller.

Sample Input 1

9

Sample Output 1

result=3
returning control flow to caller

Explanation 1

In the first sample, n = 9, so the call largest_proper_divisor(9) doesn't raise an exception and returns value 3. In this case, the function process_input prints two lines. In the first of them it prints result=3 because the returned value by largest_proper_divisor(9) is 3, and in the second line it prints returning control flow to caller.
*/
/* Solution */

#include <iostream>
#include <stdexcept>

using namespace std;

int largest_proper_divisor(int n) {
    if (n == 0) {
        throw invalid_argument("largest proper divisor is not defined for n=0");
    }
    if (n == 1) {
        throw invalid_argument("largest proper divisor is not defined for n=1");
    }
    for (int i = n/2; i >= 1; --i) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1; // will never happen
}

void process_input(int n) {
    try {
        int d = largest_proper_divisor(n);
        cout << "result=" << d << endl;        
    } catch (invalid_argument& e) {
        cout << e.what() << endl;
    }
    cout << "returning control flow to caller" << endl;
}

int main() {
    int n;
    cin >> n;
    process_input(n);
    return 0;
}


/* 3. Debugging - Overloading Ostream Operator */
/*
The task is to overload the << operator for Person class in such a way that for p being an instance of class Person the result of:

std::cout << p << " " << <some_string_value> << std::endl;

produces the following output:

first_name=<first_name>,last_name=<last_name> <some_string_value>

where:

  *  <first_name> is the value of p's first_name_
  *  <last_name> is the value of p's last_name_
  *  <some_string_value> is an arbitrary std::string value

Input Format

The input is read by the provided locked code template. In the only line of the input there are 3 space-separated strings first_name, last_name, event. The values of first_name and last_name will be used to create an object p of type Person. The value of event will be used by the provided code to produce the output.

Constraints

  *  Each word in the input contains only English letters and is no longer than 15 characters

Output Format

The output should be produced by the provided locked code template. This code will use the implementation of Person public methods and the overloaded << operator to produce the output. Specifically, the output wiil be produced by the following code:

cout << p << " " << event << endl;

Sample Input 0

john doe registered

Sample Output 0

first_name=john,last_name=doe registered

*/
/* Solution */

#include <iostream>

using namespace std;

class Person {
public:
    Person(const string& first_name, const string& last_name) : first_name_(first_name), last_name_(last_name) {}
    const string& get_first_name() const {
      return first_name_;
    }
    const string& get_last_name() const {
      return last_name_;
    }
private:
    string first_name_;
    string last_name_;
};

// Enter your code here.
ostream& operator<<(ostream& os, const Person& p) {
    os << "first_name=" << p.get_first_name() << ",last_name=" << p.get_last_name();
    return os;
}

int main() {
    string first_name, last_name, event;
    cin >> first_name >> last_name >> event;
    auto p = Person(first_name, last_name);
    cout << p << " " << event << endl;
    return 0;
}


/* 4. Debugging - Messages Order */
/*
In real life applications and systems, a common component is a messaging system. Thea idea is that a sender sends messages to the recipient. The messages might be sent for example over the network. However, some network protocols don't guarantee to preserve the order of sent messages while they are received by the recipient. For example, if someone sends a text messages hello, hi and what's up, they might be received in the order what's up, hello, hi. In many systems the expected behavior is to preserve the order, so the order of sent messages is the same as the order of received messages.

In this problem, the task is to implement a software layer over the top of a network protocol sending messages in arbitrary order, in such a way that the sent messages are printed by the recipient in the order they were sent.

In the template code below, there are implementations of classes Recipient and Network.

Your task is to implement classes Message and MessageFactory according to the below specification:

Class Message is required to store a text value of type std::string and provide a public getter const string& get_text() which is expected to return this text value. Besides that, it should implement the < operator that will be used in fix_order() method of the recipient to fix the order of received messages. Feel free to implement any other methods and class/instance variables. In particular, you can implement any additional constructors, but make sure that you provide an empty constructor, i.e. the one without arguments.

Class MessageFactory is required to have an empty constructor, and implement a method Message create_message(const string& text) that is expected to return a Message object storing the value of text argument. Feel free to implement any other methods and class/instance variables of this class.

The locked code template will act as follows. First, it creates objects message_factory and recipient. These objects are of types MessageFactory and Recipient respectively. Then, it reads messages from the standard input, and then it will use the provided Network class to simulate sending the messages to the recipient. The Network class randomly shuffles the passes messages and then it passes them to the recipient using recipient.receive(const Message&) method. After all messages are delivered, the recipient uses its own method print_messages to print all the received messages to the standard output, and just before doing that, it uses its own fix_order method to fix the order of retrieved messages. For that purpose, it uses std::sort() algorithm to sort the std::vector of received messages and this is the reason your Message class implementation has to provide the < operator.

Input Format

The input is read by the provided locked code template. It contains several lines of text messages in the order that they will be sent over the network.

Constraints

  *  There will be at most 10 lines in the input
  *  Each line will contain at most 20 characters

Output Format

The output should be produced by the provided locked code template and it is produced as described in details in the statement. The expected order of printed messages is the same as the one in the input.

Sample Input 0

Alex
Hello Monique!
What'up?
Not much :(

Sample Output 0

Alex
Hello Monique!
What'up?
Not much :(

*/
/* Solution */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {
public: 
    Message() {}
    string _text;
    int _num;
    const string& get_text() {
        return _text;
    }
    Message(int num, string text): _text(text), _num(num) {}
    bool operator <(const Message &o) {return _num<o._num;}
};

class MessageFactory {
    static int _num;
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        return Message(_num++, text);        
    }
};

int MessageFactory::_num(0);

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};

int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}

