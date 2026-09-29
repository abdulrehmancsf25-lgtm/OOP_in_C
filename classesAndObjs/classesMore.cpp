#include <iostream>
#include <cstring>
using namespace std;
class person
{
public:
    string name;
    int age;
};

void hi(const char *arr)
{
    char *name = new char[strlen(arr) + 1];
    name = strcpy(name, arr);
    cout << name << endl;
}
int main()
{
    hi("how are you");
    char arr[] = {'h', 'o', 'w', '\0'};
    //  cout << "size of char array {h,o,w,\\0}: " << sizeof(arr) << endl; // includes '\0'
    string s = "how";
    // cout << "size of string how : " << sizeof(s) << endl;
    cout << "strlen('how') : " << strlen("how") << endl; // '\0' is not included
    cout << strlen(arr);

    // string s1 = "";
    // string s2 = "how";
    // string s3 = "a very long sentence with many words";

    // cout << sizeof(s1) << endl ;// 32
    // cout << sizeof(s2)<< endl ; // 32
    // cout << sizeof(s3)<< endl ; // 32
    return 0;
}