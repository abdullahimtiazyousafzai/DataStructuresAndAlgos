#include<iostream>
#include<list>
using namespace std;

class Hashing{
private:
    list <string>* hashtable;
    int Size;
    int hash_function(string input)//this hashfunction returns the index of the value to be stored
    {
        int hash = 0;

        for(auto i : input)
        {
            hash += static_cast<unsigned int>(i);//here typecasting is done to change the datatype
        }                                        //of every character of a string to positive integer.
        hash = hash % Size;

        return hash;
    }
public:
    Hashing(int size)
    {
        Size = size;
        hashtable = new list <string> [size];
    }
    void insert(string val)
    {
        int index = hash_function(val);
        hashtable[index].push_back(val);
    }
    void display()
    {
        for(int i = 0 ; i < Size ; i++)
        {
            cout<<i<<" : ";
            for( auto j : hashtable[i])
            {
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
    void duplicates()
    {// this function checks for duplicates in the hashtable
        for(int i = 0 ; i < Size ; i++)
        {
            for(auto j : hashtable[i])
            {
                 auto it2 = next(hashtable[i].begin());
                 while(it2 != hashtable[i].end())
                 {
                    if(j == *it2)
                    {
                        cout<<*it2<<" is a duplicate!\n";
                    }
                    it2++;
                 }
            }
        }
    }
    
};

int main()
{
    Hashing H(10);
    H.insert("this is a test string!");
    H.insert("this is another string1!");
    H.insert("this is another string2!");
    H.insert("this is another string3!");
    H.insert("this is another string1!");
    H.duplicates();
    H.display();   

    return 0;
}
