#include<iostream>

using namespace std;//递归的排列组合

void Permutations(char *p,const int k,const int m){
    if(k==m){
        for(int i=0;i<=m;i++)
        cout<<p[i];
        cout<<endl;
    }
    else {
    for(int i=k;i<=m;i++){
        swap(p[k],p[i]);
        Permutations(p,k+1,m);
        swap(p[k],p[i]);
    }}
    // //a开头开始的序列
    // swap(p[0],p[0]);
    // Permutations(p,1,2);
    // swap(p[0],p[0]);
    // //b开头的序列
    // swap(p[0],p[1]);
    // Permutations(p,1,2);
    // swap(p[0],p[1]);
    // //c开头的序列
    // swap(p[0],p[2]);
    // Permutations(p,1,2);
    // swap(p[0],p[2]);
}
int main(){
    char s[]="abcde";
    Permutations(s,0,2);

    return 0;
}