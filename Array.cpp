#include <iostream>
#include <vector>
using namespace std;

int maxsubarray(vector <int> arr){
    int maxsum=0;
    int len=arr.size();
    for(int i=0;i<len;i++){
        int sum=0;
        for(int j=i;j<len;j++){
            sum+=arr[j];
            maxsum=max(sum,maxsum);
        }
    }
    return maxsum;

}

int kadaneMaxsumarray(vector<int> &arr){
    int len=arr.size();
    int currsum=arr[0];
    int maxsum=arr[0];
    for(int i=1;i<len;i++){
        currsum+=arr[i];
        maxsum=max(maxsum,currsum);
        if(currsum<0){
            currsum=0;
        }
    }
    return maxsum;
}

int buyAndSellStock(vector<int> &arr){
    int len=arr.size();
    
}

int main(){
    vector <int> arr={7,1,5,3,6,4};
    int res=maxsubarray(arr);
    int res1=kadaneMaxsumarray(arr);
    cout<<res1<<endl;
    cout<<res;
    return 0;
}
