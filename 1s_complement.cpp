#include<bits/stdc++.h>
using namespace std;

class State{
    private:
    struct item {
        char value;
        State *next;
    };
    item Input1;
    item Input2;
    char m_out;

    public:

    State():
    Input1{ ' ',nullptr},
    Input2{ ' ',nullptr},
    m_out{ ' ' }
    {
    }

    static State *m_ptr;
    void Initialize (item input1,item input2,char out);
    static char Transition(char x);
    static string Traverse(string &str,int n);
};

State *State :: m_ptr {nullptr};

void State::Initialize(item input1,item input2,char out)
{
    Input1 = input1;
    Input2 = input2;
    m_out = out;
}

char State::Transition(char x)
{
    char ch{};
    if ((*m_ptr).Input1.value == x)
    {
        // cout<<(*m_ptr).m_out;
        ch = (*m_ptr).m_out;

        m_ptr = (*m_ptr).Input1.next;
    }
    else
    {
        // cout<<(*m_ptr).m_out;
        ch = (*m_ptr).m_out;

        m_ptr = (*m_ptr).Input2.next;
    }
    return ch;
}

string State::Traverse(string &str,int n)
{
    string str1{};
    for (int i=0;i<n;i++)
    {
        str1 += Transition(str[i]);
    }

    str1 += (*m_ptr).m_out;
    // cout<<(*m_ptr).m_out<<endl;

    return str1;
}

string mooreout(string str,int n)
{
    State q1,q2,q3,q4;

    q1.Initialize({ '0', &q2 },{ '1', &q1 } ,'0');
    q2.Initialize({ '0', &q2 },{ '1', &q1 }, '1');
    // q3.Initialize({ '0', &q2 },{ '1', &q3 }, '0');
    // q4.Initialize({ 'a', &q2 },{ 'b', &q1 }, '1');

    State::m_ptr = &q1;

    string str1{ State::Traverse(str,n)};
    return str1;

}

// int countstr(string str1,int n1)
// {
//     int count{};
//     for(int i=0;i<n1;i++)
//     {
//         if(str1[i] == '1')
//         count++;
//     }
//     return count;
// }


int main()
{
    string str{ };
    string r;
    cout<<"Enter String in 0 and 1's format :";
    cin>>str;
    // reverse(str.begin(),str.end());

    int n{ static_cast<int> (str.length()) };
    string str1{ mooreout(str,n) };

    str1.erase(0,1);
    // reverse(str1.begin(),str1.end());
    cout<<"One's Complement of Number is :"<<"\t"<<str1<<endl;
    // int n1{ static_cast<int>(str.length()) };
    // cout<<"abb occurs "<<countstr(str1,n1)<<"times\n"; 
    return 0;
}