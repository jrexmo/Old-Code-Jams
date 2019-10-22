#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


int solution(long num){
  int digit = num%10;
  int num1 = num;
  vector<int> digits;


  while(num1 != 0){
    digits.push_back(digit);
    num1 = (num1 - digit)/10;
    digit = num1%10;
  }
int j;
int A = 0;
int B = 0;
for(j = 0; j < digits.size() ; j++){
  if(digits[j] == 4){
    A = A + 2*pow(10, j);
  }
}
  return A;
}

int main(){
  int T;
  cin >> T;
  int i = 0;
  long N;
  vector<int> a;
  for(i = 0; i < T; i++ ){
    cin >> N;
    a.push_back(N);
  }
  for(i = 0;i < T; i++){
    cout << "Case #" << i + 1 << ": " << solution(a[i]) << " " << a[i] - solution(a[i]) << '\n';
  }
return 0;
}
