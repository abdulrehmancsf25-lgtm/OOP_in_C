// BCSF25M_521
// ABDUL REHMAN ARSHAD

#include <iostream>
#include "CharString.h"
using namespace std;
int main()
{
    //   CharString s1("Hasasanas") ;
    //   CharString s2;
    //   s2.copyFrom(s1) ;
    //   s2.print() ;

    // s1.concat(" i am a programmer") ;
    // s1.concat(s2) ;
    // s1.print() ;

    // cout << s1.isEqualTo(s2) << endl ;

    // CharString p("anna") ;
    // if(p.checkPalindrome())
    //   cout << "Palindrome string" << endl;
    // else
    // cout << "Not a palindrome string" << endl;

    //    CharString r_s1 = s1.reverseStr() ;
    //    r_s1.print() ;

    // CharString sub_s1 = s1.SubString(0,20) ;
    // sub_s1.print() ;
    // cout << "Ocurrence of as  is :" << s1.countOccurrenceOf("as") ;

    // cout << mystrlen("hello") ;
    CharString s1("hello world");
    CharString s2;
    s2.copyFrom(s1.SubString(0, 5));
    s2.print();

    return 0;
}