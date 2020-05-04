#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = a; i < b; i++)
#define PB push_back
typedef vector<int> vi;

int path(int n){
  int sum = 0;
  if(n <= 30){
    REP(i, 0, n){
      cout << i + 1 << ' ' << 1 << '\n';
      //sum += C(i, 0);
    }
  }
  else{
    n-= 30;
    int k = 0;
    bool left = 1;
    REP(i, 0, 30){ // we will be on the 30th row at most ever
      // move of the current row, we will always have a one on the left side
      cout << i + 1 << ' ' << left*1 + (1 - left)*(i + 1) << '\n';
      //sum += 1;
      // deciding if we should include the whole row here
      if((n >>i)&1){ // look at the bit in the ith place a_i and checking if its onc
        if(left == 1){
          REP(j, 1, i + 1){
            cout << i + 1<< ' ' << j + 1 << '\n';
            //sum += C(i, j);
          }
        }
          else{
            for(int j = i - 1; j >=0; j--){
            cout << i + 1<< ' ' << j + 1 << '\n';
            //sum += C(i, j);
          }
      }
      k++;
      left = 1 - left;
    }
  }
    int current = 31;
    REP(i, 0, k){
      if(left){
        cout << current << ' ' << 1 << '\n';
      }
      else{
        cout << current << ' ' << current << '\n';
      }
      current++;
      //sum += 1;
    }

}
return sum;
}

int main(){
  int T;
  cin >> T;
  vi ans(T);
  REP(i, 0, T){
    cin >> ans[i];
  }

  REP(i, 0, T){
    cout << "Case #" << i + 1 << ":" << '\n';
    path(ans[i]);
  }
  return 0;
}
