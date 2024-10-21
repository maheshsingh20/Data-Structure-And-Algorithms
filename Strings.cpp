// #include <iostream>
// #include <cstring>
// using namespace std;


// int main(){
//     //character storing 
//     // char a='a';
//     // char b='b';
//     // cout<<int(a)<<endl;
//     // cout<<a<<endl<<b<<endl;
//     // char f='f';
//     // int pos=f-'a'+1;
//     // cout<<pos;


//     //char Arrays

//     // char str[5]={'c','o','d','e','\0'};
//     // char str1[]="hello";
//     // cout<<strlen(str1)<<endl;
//     // cout<<str;
    

//     char name[20];
//     cout<<"Enter name: ";
//     cin.getline(name,20,'g'); //name: arr name  20: size of array  g: limiter
//     // cout<<name<<endl;
//     // cout<<strlen(name);


//     //convert to uppercase
    
    
// }



#include <iostream>
#include <cstring>
using namespace std;

string mergealternatively(string a,string b){
    string result="";
    for(int i=0;i<a.length() && i<b.length();i++){
        result+=a[i];
        result+=b[i];
    }
    return result;
}

long long colorball(string s){
    int cnt=0;
    long long res=0;
    for(const char c:s){
        if(c=='1'){
            ++cnt;
        }else{
            res+=cnt;
        }
    }
    return res;
}

int main(){


//     string name="My name is Mahesh Singh";
//     cout<<name<<endl;

//     //length of string
//     cout<<name.length()<<endl;

//     //accessing a particular character
//     cout<<name[0]<<endl;

//     //changing a particular character
//     name[0]='m';
//     cout<<name<<endl;

//     //concatenation
//     string name1="Mahesh";
//     string name2="Singh";
//     string name3=name1+name2;
//     cout<<name3<<endl;

//     //compare
//     string name4="Mahesh";
//     string name5="Mahesh";
//     if(name4+name5==name5+name4){
//         cout<<"Strings are equal"<<endl;   
//     }
//     else{
//         cout<<"Strings are not equal"<<endl;
//     }


    string s="10111001";
    cout<<colorball(s);

    return 0;
}