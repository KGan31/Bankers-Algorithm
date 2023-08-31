#include <iostream>
#include <iomanip>
using namespace std;


int main(){
    int res, n;
    cout<<"Enter number of Resources: ";
    cin>>res;
    cout<<"Enter number of processes: ";
    cin>>n;
    int proc[n][res];
    int alloc[n][res];
    int completed[n] = {0};
    int seq[n];
    for(int i = 0; i<n; i++){
        cout<<"Enter maximum resources needed for process "<<i+1<<": ";
        for(int j = 0; j<res; j++){
            cin>>proc[i][j];
        }
        cout<<"Enter resources allocated for process "<<i+1<<": ";
        for(int j = 0; j<res; j++){
            cin>>alloc[i][j];
        }
        completed[i]=0;
        seq[i]=0;
    }
    int init_res[res];
    cout<<"Enter initially available resources: ";
    for(int i=0; i<res; i++){
        cin>>init_res[i];
    }
    cout<<endl;
    int flag = 0;
    int i = 0;
    int count = 0;
    int av_res[n][res];
    int s = 0;
    while(flag!=n && count<n){
        int flag1 = 0;
        for(int j = 0; j<res; j++){
            if(proc[i][j]-alloc[i][j]>init_res[j]){
                flag1=1;
            }
        }
        if(flag1==0 && completed[i]==0){
            for(int j = 0; j<res; j++){
                init_res[j]+=alloc[i][j];
                av_res[i][j]=init_res[j];
            }
            flag++;
            completed[i]=1;
            seq[s]=i+1;
            s++;
        }
        i=(i+1)%n;
        if(i==0){
            count++;
        }
    }
    if(count == n){
        cout<<"There can be a deadlock"<<endl;
    }
    else{
        cout
            <<left
            <<setw(12)
            <<"Process"
            <<left
            <<setw(21)
            <<"Maximum_Required"
            <<left
            <<setw(24)
            <<"Resources_Allocated"
            <<left
            <<setw(21)
            <<"Resources_Needed"
            <<left
            <<setw(17)
            <<"Resources_Available"
            <<endl;
        for(i = 0; i<n; i++){
            cout
            <<left
            <<setw(12)
            <<i+1;
            for(int j = 0; j<res-1; j++){
                cout
                <<left
                <<setw(2)
                <<proc[i][j];
            }
            cout
            <<left
            <<setw(17)
            <<proc[i][res-1];
            for(int j = 0; j<res-1; j++){
                cout
                <<left
                <<setw(2)
                <<alloc[i][j];
            }
            cout
            <<left
            <<setw(20)
            <<alloc[i][res-1];
            for(int j = 0; j<res-1; j++){
                cout
                <<left
                <<setw(2)
                <<proc[i][j]-alloc[i][j];
            }
            cout
            <<left
            <<setw(17)
            <<proc[i][res-1]-alloc[i][res-1];
            for(int j = 0; j<res-1; j++){
                cout
                <<left
                <<setw(3)
                <<av_res[i][j];
            }
            cout
            <<left
            <<setw(13)
            <<av_res[i][res-1];
            cout<<"\t";
            cout<<"\n";
        }
        cout<<endl;
        cout<<"Sequence of processes: ";
        for(i=0; i<n-1; i++){
            cout<<"P"<<seq[i]<<"->";
        }
        cout<<"P"<<seq[n-1]<<endl;
        cout<<"\n";
    }

}