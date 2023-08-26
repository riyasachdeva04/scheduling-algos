#include <iostream>
#include<vector>
using namespace std;


vector<int> at;
vector<int> bt;
vector<int> ct;
vector<int> tat;
vector<int> wt;
vector<int> p;

void sort(vector<int>& p, vector<int>& at, vector<int>& bt)
{
  int size = at.size();

  for(int i=0; i<size-1; i++)
    {
      bool flag = 0;

      for(int j=0; j<size-1; j++)
        {
          if(at[j] > at[j+1])
          {
            swap(at[j], at[j+1]);
            swap(bt[j], bt[j+1]);
            swap(p[j], p[j+1]);
            flag = 1;
          }
        }

      if(flag == 0)
        break;
    }
}

void display(vector<int>& p, vector<int>& at, vector<int>& bt, vector<int>& ct, vector<int>& tat, vector<int>& wt)
{
  int n = p.size();

  cout << "Process Id     AT        BT      CT     TAT     WT" << endl;
  for(int i = 0; i < n; i++)
  {
    cout << p[i] << "              " << at[i] << "         " << bt[i] << "        " << ct[i] << "       " << tat[i] << "       " << wt[i] << endl;
  }
}

void fcfs(int n)
{ 
  at.resize(n);
  bt.resize(n);
  ct.resize(n);
  tat.resize(n);
  wt.resize(n);
  p.resize(n);
  
  for(int i=0; i<n; i++)
    {
      int a, b;
      cout << "Enter arrival time and burst time";
      cin >> a >> b;
      at[i] = a;
      bt[i] = b;
      p[i] = i+1;
    }

  sort(p, at, bt);

  for(int i=0; i<n; i++)
    {
      // completion time
      if(i == 0)
        ct[i] = at[i] + bt[i];
      else
        ct[i] = ct[i-1] + bt[i];

      // total arrival time
      tat[i] = ct[i] - at[i];

      // wait time
      wt[i] = tat[i] - bt[i];

    }
  display(p, at, bt, ct, tat, wt);
}






int main() {
  cout << "Enter no of processes";
  int n;
  cin >> n;
  fcfs(n);
}