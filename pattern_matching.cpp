#include <bits/stdc++.h>
//g++ -std=c++14 -O2 -Wall 1.cpp -o 1
using namespace std;

#define REP(i,a,b) for (int i = a; i < b; i++)
#define PB push_back
typedef vector<int> vi;
typedef long long ll;

//will be possible when all prefixes and all suffixes are pre/post of the longest one
string smallest(vector<string> given){
  vector<string> suffixes;
  vector<string> prefixes;
  string longest_suf = "";
  string longest_pre = "";
  vector<string> middles;
  for(string elem: given){
    string identical = elem;
    int firstind = elem.find('*');
    string prefix = elem.substr(0, firstind);
    prefixes.push_back(prefix);
    if(prefix.size() >= longest_pre.size()) longest_pre = prefix;

    reverse(identical.begin(), identical.end());
    int secondind = identical.find('*');
    string suffix = identical.substr(0, secondind);
    cout << suffix <<'\n';
    reverse(suffix.begin(), suffix.end());
    suffixes.push_back(suffix);
    if(suffix.size() > longest_pre.size()) longest_suf = suffix;

    string middle = elem.substr(firstind + 1, secondind - firstind );
    middle.erase(remove(middle.begin(), middle.end(), '*'), middle.end());
    middles.push_back(middle);
  }
  cout << '\n';
  cout << "longest suf " << longest_suf << '\n';

  for(string elem: prefixes){
    int n = elem.size();
    if(longest_pre.substr(0, n) != elem) return "*";
  }
  for(string elem: suffixes){
     int n = elem.size();
    if(longest_suf.substr(0, n) != elem) return "*";
  }
  string to_return = "";
  to_return += longest_pre;
  for(string elem: middles){
    to_return += elem;
  }
  to_return += longest_suf;
  return to_return;
}



int main(){
  int T; cin >> T;
  vector<string> ans(T);
  REP(i, 0, T){
    int N;
    cin >> N;
    vector<string> patterns(N);
    REP(i, 0, N)
      cin >> patterns[i];

    ans[i] = smallest(patterns);
  }

  REP(Case_num, 1, T + 1){
    cout << "Case #" << Case_num << ": " << ans[Case_num - 1] << '\n';

}
return 0;
}
