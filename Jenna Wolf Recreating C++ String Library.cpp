//File: finalproject.cpp
//Purpose: This program replicated the string library and many of its functions
//Names: Jenna Wolf, Breno Tebet
//IDs: Jenna - 0347845, Breno - 0349046
//Date: May 11th, 2023

#include <iostream>

using namespace std;

class String
{
    private:
        char * ptr;             //holds the ptr data
    public:
        //function prototypes
        int length();
        String();
        String(const char*);
        String(String&);
        String(char, int);
        String(String&, int, int);
        void setString(char *);
        char* getString();
        void append(int, char);
        void append(String);
        void append(String, int);
        void append(String, int, int);
        bool compare(String);
        bool compare(int, int, String);
        void insert(int, int, char);
        void insert(int, String);
        void clear();
        char back();
        int size();
        bool palindrome();
        bool palindrome(int, int);
        friend ostream& operator<<(ostream&, String &);
        friend istream& operator>>(istream&, String &);
        String operator=(String);
        String operator+=(String);
        String &operator+(String &);
};

int main()
{
    
    String hello;
    String person("Micheal Scott");
    String two(person);
    String three('a', 7);
    String four(person, 6, 5);
    
    cout << hello << " " << person << " " << two << " " << three << " " << " " << four;
    

    return 0;
}

//purpose: gets the length of the string and returns it
//arguments: none
int String::length()
{
    int len = 0;        //holds the len data and sets it to 0
    
    //loop that goes until it finds \0
    while(ptr[len] != '\0')
    {
        len++;  //adds 1 to len
    }
    return len; //returns len
}

//prupose: constructor that sets the pointer to nullptr
//arguments: no arguments
String::String()
{
    ptr = nullptr;  //ptr is set to nullptr
}

//purpose::constructor that sets ptr to the string that is sent over to it (by iterating over each letter)
//arguments: words is the string that ptr will be set to
String::String(const char *words)
{
    //makes sure words is not a nullptr
    if(words != nullptr)
    {
        int len = 0;    //holds the len data and sets it to 0
        
        //for loop that iterates until it finds \0 in words
        for(int i = 0; words[i] != '\0'; i++)
            len++;  //adds one to len
            
        ptr = new char[len + 1];    //sets ptr to a new char array or len + 1
        
        //for loop that iterates until i is larger than the length
        for(int i = 0; i < len; i++)
        {
            ptr[i] = words[i];  //sets ptr[i] to words[i] (creates string character by character)
        }
        
        ptr[len] = '\0';    //sets ptr[len] (last chacter) to \0
    }
    else
        ptr = nullptr;  //sets ptr to nullptr
}

//purpose: sets the ptr to the string that is sent over to it
//arguments: words holds the data ptr will be set to
String::String(String &words)
{
    //makes sure words is not a nullptr
    if(words.ptr != nullptr)
    {
        int len = words.length();   //holds the len data and sets it to what is returned from the length function
        ptr = new char[len + 1];    //sets ptr to a new char array of size len + 1
        
        //for loop that iterates until i is bigger than len
        for(int i = 0; i < len; i++)
        {
            ptr[i] = words.ptr[i];  //sets ptr[i] to words.ptr[i] (creates string character by character)
        }
        
        ptr[len] = '\0';    //sets ptr[len] (the last character) to \0
    }
    else
        ptr = nullptr;  //sets ptr to nullptr
}

//purpose: Constructor that sets ptr to the same character a num times
//arguments: var is the charcter ptr will be set to, num is the number of times that character will be set
String::String(char var, int num)
{
    //makes sure var is not \0
    if(var != '\0')
    {
        ptr = new char[num + 1];    //sets ptr to a new char array of num + 1
        
        //for loop that iterates until i is bigger than num
        for(int i = 0; i < num; i++)
        {
            ptr[i] = var;   //sets ptr[i] to var (fills array with the character)
        }
        
        ptr[num + 1] = '\0';    //sets ptr[num + 1] (the last character) to \0
    }
    else
        ptr = nullptr;  //sets ptr to nullptr
}

//purpose: Constructor that sets ptr to a string starting from start and going num times through the string (part of a string)
//arguments: str is the data the ptr will be set to, start is the character ptr starts on, num is the number of characters
//ptr will hold
String::String(String &str, int start, int num)
{
    //makes sure str is not nullptr
    if(str.ptr != nullptr)
    {
        int len = num;  //holds the len data and sets it to num
        ptr = new char[len + 1];    //sets ptr to a new char array of len + 1
        
        //for loop that iterates until i is bigger than len
        for(int i = 0; i < len; i++)
        {
                //sets ptr[i] to str.ptr[start + 1] (sets ptr to the string starting from start until len is reached)
                ptr[i] = str.ptr[start + i];
        }
        
        ptr[len + 1] = '\0';    //sets ptr[len + 1] (the last character) to \0
    }
    else
        ptr = nullptr;      //sets ptr to nullptr
}

//purpose: sets ptr to the character pointer sent over
//arguments: a is a character pointer ptr will be set to
void String::setString(char * a)
{
    ptr = a;    //sets ptr to a 
}

//purpose: returns the value stored in ptr
//arguments: no arguments
char* String::getString()
{
    return ptr; //returns the data in ptr
}

//purpose: this function adds the character sent over to the end of a string n times
//arguments: n is the number of times z is added to the end of the string, z is the character being added on
void String::append(int n, char z)
{
    //makes sure ptr and z are not nullptr
    if(ptr != nullptr && z != '\0')
    {
        char * temp = ptr;          //holds the temp data and sets it to ptr
        int len = length() + n;     //holds the len data and sets it to the value length returns + n 
        ptr = new char[len + 1];    //sets ptr to a new char array of len + 1
        
        //for loop that iterates until i is bigger than len - n
        for(int i = 0; i < len - n; i++)
        {
            ptr[i] = temp[i];   //sets ptr[i] to temp[i] (sets it back to its original string)
        }
        
        //for loop that iterates until is is bigger than len
        for(int i = len - n; i < len; i++)
        {
            ptr[i] = z;     //sets ptr[i] to z (adds on the character to the array n times)
        }
        
        ptr[len + 1] = '\0';    //sets ptr[len + 1] (the last charcter) to \0
    }
}

//purpose: This function adds the string sent over to the string that called the function
//arguments: str is the string being added on to the string that called the function
void String::append(String str)
{
    //makes sure ptr and str.ptr is not nullptr
    if(ptr != nullptr && str.ptr != nullptr)
    {
        
        char * temp = ptr;              //holds the temp data and sets it to ptr
        int size = str.length();        //holds the size data and sets it to the data returned by length
        int len = length() + size;      //holds the len data and sets it to the data returned by length plus size
        ptr = new char[len + 1];        //sets ptr to a new char array of len + 1
        
        //for loop that iterates until i is bigger than len - size
        for(int i = 0; i < len - size; i++)
        {
            ptr[i] = temp[i];   //sets ptr[i] to temp[i] (sets the string back to its original string)
        }
        
        //for loop that iterates until i is bigger than len
        for(int i = len - size; i < len; i++)
        {
            //sets ptr[i] to str.ptr[i - (len - size)] (adds the argument string onto the end of the ptr string)
            ptr[i] = str.ptr[i - (len - size)];
        }
        
        ptr[len + 1] = '\0';    //sets ptr[len + 1] (the last character) to \0
    }
}

//purpose: this function adds on x characters of a string to the string that called the function 
//arguments: str is the string being added on to the string that called the function, x is how many characters of that
//string are being added on
void String::append(String str, int x)
{
    //makes sure ptr and str.ptr are not nullptr
    if(ptr != nullptr && str.ptr != nullptr)
        {
        char * temp = ptr;          //holds the temp data and sets it to ptr
        int len = length() + x;     //holds the len data and sets it to the value returned by length plus x
        ptr = new char[len + 1];    //sets ptr to a new char array of len + 1
        
        //for loop that iterates until i is bigger than len - x
        for(int i = 0; i < len - x; i++)
        {
            ptr[i] = temp[i];   //sets ptr[i] to temp[i] (sets the string back to its orignal string)
        }
        
        //for loop that iterates until i is bigger than len
        for(int i = len - x; i < len; i++)
        {
            //sets ptr[i] to str.ptr[i - (len - x)] (adds the str onto the end of the orignal string for x characters)
            ptr[i] = str.ptr[i - (len - x)];
        }
        
        ptr[len + 1] = '\0';    //sets ptr[len + 1] (the last character) to \0
    }
}

//purpose: this function adds on a string starting from x and going for n characters to the string that called the function
//arguments: str is the string being added to the string that called the function, x is the starting character for str,
//n is how many characters of str that are being added
void String::append(String str, int x, int n)
{
    //makes sure ptr and str.ptr are not nullptr
    if(ptr != nullptr && str.ptr != nullptr)
    {
        char * temp = ptr;          //holds the temp data and sets it to ptr
        int len = length() + n;     //holds the len data and sets it to the value returned by length plus n
        ptr = new char[len + 1];    //sets ptr to a new char array of size len + 1
        
        //for loop that iterates until i is bigger than len - n
        for(int i = 0; i < len - n; i++)
        {
            ptr[i] = temp[i];   //sets ptr[i] to temp[i] (sets the string to its original string)
        }
        
        //for loop that iterates until i is bigger than len
        for(int i = len - n; i < len; i++)
        {
            ptr[i] = str.ptr[x];    //sets ptr[i] to str.ptr[x] (adds on the string to the end of ptr starting from x)
            x++;                    //adds one to x
        }
        
        ptr[len + 1] = '\0';    //sets ptr[len + 1] (the last character) to \0
    }
}

//purpose: this function compare the string that called it to the string that was sent over. If they are the same,
//true is sent back. if not, false is sent back
//arguments: str is the string being compared to the string that called the function
bool String::compare(String str)
{
    //makes sure ptr and str.ptr are not nullptr
    if(ptr != nullptr && str.ptr != nullptr)
    {
        bool comp = true;   // holds the comp data and is set to true
        
        //for loop  that iterates until i is bigger than length
        for(int i = 0; i < length(); i++)
        {
            //checks to see if ptr[i] does not match str.ptr[i].
            if(ptr[i] != str.ptr[i])
                comp = false;   //sets comp to false
        }
        return comp;    //returns comp
    }
    else
        return false;   //returns false
}

//purpose: this function compare the string that called it to the string that was sent over starting at position x
// and going for n characters. if they are the same, true is sent back. if not, false is sent back
//arguments: str is the string being compared to the string that called the function, x is the starting position
//for both strings, n is how many characters are checked
bool String::compare(int x, int n, String str)
{
    //makes sure ptr and str.ptr are not nullptr
    if(ptr != nullptr && str.ptr != nullptr)
    {
        bool comp = true;   //holds the comp data and is set to true
        
        //for loop that iterates until i is bigger than n
        for(int i = 0; i < n; i++)
        {
            //checks to see if ptr[i + x] is not equal to str.ptr[i + x]
            if(ptr[i + x] != str.ptr[i + x])
                comp = false;   //sets comp to false
        }
        return comp;    //returns comp
    }
    else
        return false;   //returns false
}

//purpose: this function insets the character sent over at position x of the string that called the function. it is
//added n times
//arguments: x is the position the characters are added, n is the amount of times the characters are added, z is
//the character added
void String::insert(int x, int n, char z)
{
    //makes sure ptr and z is not nullptr
    if(ptr != nullptr && z != '\0')
    {
        char * temp = ptr;          //holds the temp data and is set to ptr
        int len = length() + n;     //holds the len data and is set to the value returned by length plus n
        ptr = new char[len + 1];    //sets ptr to a new char array of len + 1
        
        //for loop that iterates until i is larger then len
        for(int i = 0; i < len; i++)
        {
            //if loop that does different action based on what i is
            if(i < x + 1)
                ptr[i] = temp[i];       //sets ptr[i] to temp[i]
            else if (i > x + n)
                ptr[i] = temp[i - n];   //sets ptr[i] to temp[i - n]
            else
                ptr[i] = z;             //sets ptr[i] to z
        }
        ptr[len + 1] = '\0';    //sets ptr[len + 1] (the last character) to \0
    }
}

//purpose: this function insets the string sent over at position x of the string that called the function.
//arguments: x is the position the characters are added, str is the string being inserted into the string that called the function
void String::insert(int x, String str)
{
    //makes sure str.ptr and ptr does not equal nullptr
    if(str.ptr != nullptr && ptr != nullptr)
    {
        char * temp = ptr;                  //holds the temp data and sets it to ptr
        int size = str.length();            //holds the size data and sets it to the amount returned by length
        int len = length() + size;          //holds the len data and sets it to  the amount returned by length plus size
        ptr = new char[len + 1];            //sets ptr to a new char array of size len + 1
        
        //for loop that iterates until i is bigger than x
        for(int i = 0; i < x; i++)
                ptr[i] = temp[i];       //sets ptr[i] to temp[i] (sets it to begining of origanl string)
                
        //for loop that iterates until i is bigger than size + x
        for(int i = x; i < size + x; i++)
            ptr[i] = str.ptr[i - x];    //sets ptr[i] to str.ptr[i - x] (inserts the string)
            
        //for loop that iterates until is is bigger than len
        for(int i = size + x; i < len; i++)
            ptr[i] = temp[i - size];    //sets ptr[i] to temp[i - size] (sets it to the end of orignal string)

        ptr[len + 1] = '\0';    //sets ptr[len + 1] (the last character) to \0
    }
}

//purpose: This function clears out ptr and sets it to a new char array of size 0
//arguments: no arguments
void String::clear()
{
    delete []ptr;       //clears the data in the curret ptr
    ptr = new char[0];  //sets ptr to a new char array of size 0
}

//purpose: returns the char stored in the back of the string
//arguements: no arguments
char String::back()
{
    //makes sure ptr is not nullptr
    if(ptr != nullptr)
        return ptr[length() - 1];   //returns the last char of the array
    else
        return '\0';    //returns \0
}

//purpose: finds the size of the string sent over
//arguments: no arguments
int String::size()
{
    if(ptr != nullptr)
    {
        int len = 0;    //holds the len data and sets it to 0
        
        //while loop that iterates until ptr[len] equals \0
        while(ptr[len] != '\0')
        {
            len++;  //adds 1 to len
        }
        return len; //returns len
    }
    else
        return 0;   //returns 0 (or empty)
}

//purpose: this funcrion checks to see if the string sent over to it is a palindrome
//arguments: no arguments
bool String::palindrome()
{
    //makes sure ptr is not nullptr
    if(ptr != nullptr)
    {
        int start = 0;              //holds the start data and sets it to 0
        int end = length() - 1;     //holds the end data and sets it to that value returned by length minus 1
        bool palin = true;          //holds the palin data and sets it to true
        
        //while loop that iterates until start is larger than end or palin is set to false
        while(start < end && palin != false)
        {
            //makes sure the characters being checked are alphabetical
            if(!isalpha(ptr[start]) || !isalpha(ptr[end]))
            {
                //checks to see if ptr[start] is alphabetical
                if(!isalpha(ptr[start]))
                    start++;    //adds one to start
                else
                    end--;      //subtracts one from end
            }
            else
            {
                //checks to see is ptr[start] and ptr[end] match
                if(ptr[start] != ptr[end])
                    palin = false;      //sets palin to false
                start++;                //adds one to start
                end--;                  //subtracts one from end
            }
        }
        return palin;   //returns palin
    }
    else
        return false;   //returns false
}

//purpose: this funcrion checks to see if the string sent over to it is a palindrome starting from x and going n characters
//arguments: x is where the function starts checking the string, n is how many character it goes for
bool String::palindrome(int x, int n)
{
    //makes sure ptr is not nullptr
    if(ptr != nullptr)
    {
        int start = x;          //holds the start data and sets it to x
        int end = x + n;        //holds the end data and sets to to x plus n
        bool palin = true;      //holds the palin data and sets it to true
        
        //while loop that repeats until start is larger than end or palin is set to false
        while(start < end && palin != false)
        {
            //makes sure the characters being checked are alphabetical
            if(!isalpha(ptr[start]) || !isalpha(ptr[end]))
            {
                //checks to see if ptr[start] is alphabetical
                if(!isalpha(ptr[start]))
                    start++;        //adds one to start
                else
                    end--;          //subtracts one from end
            }
            else
            {
                //checks to see is ptr[start] and ptr[end] match
                if(ptr[start] != ptr[end])
                    palin = false;      //sets palin to false
                start++;                //adds one to start
                end--;                  //subtracts one from end
            }
        }
        return palin;       //returns palin
    }
    else
        return false;       //returns false
}

//purpose: outputs the data stored in obj onto the screen
//arguments: out allows obj to be output, obj is what is being output
ostream& operator<<(ostream& out, String &obj)
{
    //makes sure obj.ptr is not nullptr
    if(obj.ptr != nullptr)
    {
        int len = obj.length();         //holds the len data and is set to the value returned by length
        
        //for loop that iterates until i is bigger than length
        for(int i = 0; i < len; i++)
            out << obj.ptr[i];      //shows the character from obj.ptr[i] on the screen
    }
    return out; //returns out
}

//purpose: takes in the data the user enteres and sets obj to it
//argument: in is what allows data to be input, obj is what holds the data inputed
istream& operator>>(istream& in, String & obj)
{
    char * temp;                //holds the temp data
    int len = 0;                //holds the len data and sets it to 0
    temp = new char [10000];    //temp is set to a new char array of size 10000
    in.getline(temp,10000);     //gets the line entered from the user and stored it in temp
    
    //while loop that iterates until temp[len] equals \0
    while(temp[len] != '\0')
    {
        len++;  //adds one to len
    }

    obj.ptr = new char[len + 1];    //sets obj.ptr to a new char array of len + 1
    
    //for loop that iterates until i is bigger than len
    for(int i = 0; i < len; i++)
        obj.ptr[i] = temp[i];       //sets obj.ptr[i to temp[i] (sets it to the string entered)
        
    obj.ptr[len + 1] = '\0';        //sets obj.ptr[len + 1] (the last character) to \0
    
    return in;  //returns in
}


//purpose: sets the string that called the operator to the argument string
//arguments:
String String::operator=(String str)
{
    //makes sure str.ptr is not nullptr
    if(str.ptr != nullptr)
    {
        delete []ptr;               //deletes the data in ptr
        int len = str.length();     //holds the len data and sets it to the value returned by length
        ptr = new char[len + 1];    //sets ptr to a new char array of len + 1
        
        //for loop that iterates until i is bigger than len
        for(int i = 0; i < len; i++)
            ptr[i] = str.ptr[i];    //sets ptr[i] to str.ptr[i] (sets it to the string help by str)
            
        ptr[len + 1] = '\0';    //sets ptr[len + 1] (the last character) to \0
        
        return *this;   //returns the string that called the function
    }
    else
    {
        delete []ptr;   //deletes the data in ptr
        ptr = nullptr;  //sets ptr to nullptr
        return *this;   //returns the string that called the function
    }
}

//purpose: adds the argument string to the string that called the operator
//arguments: str is the string being added onto the string that called the function
String String::operator+=(String str)
{
    //makes sure ptr and str.ptr are not nullptr
    if(ptr != nullptr && str.ptr != nullptr)
    {
        char * temp = ptr;                      //holds the temp data and sets it to ptr
        //holds the len data and sets it to the value returned by length plus the other value returned by length
        int len = length() + str.length(); 
        ptr = new char[len + 1];                //sets ptr to a new char array of size len + 1
        
        //for loop that iterates until i is bigger than len minus the value returned by length
        for(int i = 0; i < len - str.length(); i++)
            ptr[i] = temp[i];       //sets ptr[i] to temp[i] (sets ptr to its original string)
            
        //for loop that iterates until is is bigger than len
        for(int i = len - str.length(); i < len; i++)
            ptr[i] = str.ptr[i - (len - str.length())];     //sets ptr[i] to str.ptr[i - (len - str.length())]
            
        ptr[len + 1] = '\0';    //sets ptr[len + 1] (the last character) to \0
        
        return *this;   //returns the string that called the operator
    }
    else if(ptr == nullptr)  //checks to see if ptr is equal to nullptr
    {   
        ptr = str.ptr;  //sets ptr to the data in str.ptr
        return *this;   //returns the string that called the function
    }
    else
        return *this;   //returns the string that called the function
}

//purpose: adds the argument string to the string that called the operator
//arguments: str is the string being added onto the string that called the function
String &String::operator+(String &str)
{
    
    if(ptr != nullptr && str.ptr != nullptr)
    {
        //holds the len data and sets it to the value returned by length plus the other value returned by length
        int len = length() + str.length(); 
        String temp;                        //holds the temp data
        temp.ptr = new char[len + 1];       //sets the temp.ptr to a new char array of [len + 1]
        
        //for loop that iterates until i is bigger then len minus the value returned by length
        for(int i = 0; i < len - str.length(); i++)
            temp.ptr[i] = ptr[i];       //temp.ptr[i] is set to ptr[i] (sets temp to the first string)
            
        //for loop that iterates until i is bigger than len
        for(int i = len - str.length(); i < len; i++)
            temp.ptr[i] = str.ptr[i - (len - str.length())];    //temp.ptr[i] is set to str.ptr[i - (len - str.length())]
            
        temp.ptr[len + 1] = '\0';   //sets temp.ptr[len + 1] (the last character) to \0
        ptr = temp.ptr;             //sets ptr to temp
        return *this;               //returns the string that called the function
    }
    else if(ptr == nullptr)  //checks to see if ptr is equal to nullptr
    {   
        ptr = str.ptr;  //sets ptr to the data in str.ptr
        return *this;   //returns the string that called the function
    }
    else
        return *this;   //returns the string that called the function
}