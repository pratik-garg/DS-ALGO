#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int k,n;
    cout<<"ENTER THE CHARACTERS BY WHICH YOU WanT TO ROTATTE THE STRING:";
    cin>>k;
    n = str.size();
    //algorithm for rotating the string by n characters assuming n is less than length
    //of the string
    //this is left rotation...
   /* reverse(str.begin(),str.begin()+k);
    reverse(str.begin()+k,str.end());
    reverse(str.begin(),str.end());
    cout<<str<<endl;*/
    //right rotation
    reverse(str.begin(),str.begin()+n-k);
    reverse(str.begin()+n-k,str.end());
    reverse(str.begin(),str.end());

    cout<<str<<endl;
}
