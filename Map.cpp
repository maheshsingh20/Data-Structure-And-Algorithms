/*#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, int>pre;
    pre[1]=10;//inserting value
    pre[2]=20;
    
    pre.insert(pair<int,int>(3,30)); //inserting valueee
    pre.insert(pair<int,int>(4,40));
    pre.insert(pair<int,int>(5,50));
    pre.insert(pair<int,int>(6,60));
    pre.

    // while(it!=pre.end()){
    //     cout<<it->first<<" ";//use first here to access key
    //     cout<<it->second<<" ";// use second here to access valuee
    //     cout<<endl;
    //     ++it;
    // }


    // cout<<pre.size();    // this will return size of map
    // auto itt=pre.begin();   //
    // for(int i=0;i<3;i++){
    //     ++itt;
    // }


    // pre.erase(pre.begin(),itt);  //erasing elements from bigin to itt ehich is pointing third element here 


    // cout<<endl;
    // cout<<endl;
    // for(it=pre.begin();it!=pre.end();++it){
    //     cout<<it->first<<" ";
    //     cout<<it->second<<" ";
    //     cout<<endl;
    // }

    // cout<<pre.size()<<endl;
    
    //pre.clear();   //clear whole map
    
    //cout<<pre.size();


    cout<<pre.size()<<endl;


    // for(int i=0;i<2;i++){
    //     cout<<"The element that is deleted is: "<<pre.begin()->second<<endl;   //clearing first two elements of the map
    //     pre.erase(pre.begin()->first);
    // }



    // cout<<pre.size()<<endl;


    map<int,int>::iterator it=pre.begin();  
    cout<<"Elements after deletion is: "<<endl;
    while(it!=pre.end()){
        cout<<it->first<<" "<<it->second<<endl;
        ++it;
    }
    
    pre.erase(pre.find(2),pre.find(5));//deleting elements in this range 2 to 4 

    map<int,int>::iterator itt=pre.begin();  
    cout<<"Elements after deletion is: "<<endl;
    while(itt!=pre.end()){
        cout<<itt->first<<" "<<itt->second<<endl;
        ++itt;
    }

    // cout<<"Element we find is: "<<endl;
    // map<int,int> ::iterator iter =pre.find(5);   //finding element by passing its key
 
    // cout<<iter->first<<" "<<iter->second<<endl;



}

*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;



int num(vector<int>& arr1, vector<int> &arr2){
    map<int ,int>pre;
    map<int ,int>pre1;
    int s2=arr2.size();
    for(int i=0;i<arr1.size();i++){
        pre[i]=arr1[i];
    }
    for(int i=0;i<arr2.size();i++){
        //map<int, int>::iterator it=pre.begin();
        if(pre.find(arr2[i])==pre.end()){
            pre1[i+s2]=arr2[i];
        }
    }
    return pre.size()+pre1.size();
}




int main(){
    vector <int>arr1= {1,2,3,4,5,2,3};
    vector <int> arr2={1,3,8,9,11,16,11};
    cout<<num(arr1,arr2);
    return 0;
}