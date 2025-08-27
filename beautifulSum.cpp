#include<iostream>
using namespace std;
int beauty(int x){
    int cnt = 0;
    if (x % 10 == 0) x++;
    while ( x > 9){
        int uid = x%10;
        x = x /10;
        x =x +1;
        cnt += (10-uid);
        while ( x % 10 == 0){
            x = x/10;
        }
    }
    if (x < 10 ) cnt += 9;

    return cnt;
}
int main(){
    int x;
    cout<<"What's x: ";
    cin>>x;
    cout<<beauty(x)<<endl;
}