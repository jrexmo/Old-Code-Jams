#include <iostream>
#include <string>
using namespace std;


string solution(string path){
  string new_path = "";
  for(int i = 0; i < path.size(); i++){
    if(path.at(i) == 'S'){
      new_path = new_path + 'E';
    }
    else{
      new_path = new_path + 'S';

    }
  }
  return(new_path);
}

int main(){
  int T;
  cin >> T;
  int j = 0;
  int n = 0;
  string s;
  string stringlist[T];
  for(j = 0; j < T; j++){
    cin >> n;
    cin >> s;
    stringlist[j] = solution(s);
  }
  for(j = 0;j < T; j++){
    cout << "Case #" << j + 1 << ": " << stringlist[j] << '\n';
  }
return 0;
}
