#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
  int ED_matrix[a.size()+1][b.size()+1];
  int i, j, insertion, deletion, match, mismatch;
  int lcs = 0;
  for(i = 0; i <= a.size(); i++){ED_matrix[i][0] = i;}
  for(j = 0; j <= b.size(); j++){ED_matrix[0][j] = j;}
  for(j = 1; j <= b.size(); j++){
    for(i = 1; i <= a.size(); i++){
      insertion = ED_matrix[i][j-1] + 1;
      deletion = ED_matrix[i-1][j] + 1;
      match = ED_matrix[i-1][j-1];
      mismatch = ED_matrix[i-1][j-1] + 1;
      if(a[i-1] == b[j-1]){ ED_matrix[i][j] = min( min(insertion, deletion), match); }
      else{ ED_matrix[i][j] = min( min(insertion, deletion), mismatch); }
    }
  }
/*   for(i = 0; i <= a.size(); i++){
    for(j = 0; j <= b.size(); j++){
      cout<<ED_matrix[i][j]<<" ";
    }
    cout<<endl;
  } */
  i--;
  j--;
/*   cout<<"before while loop i, j is "<<i<<" ,"<<j<<endl;*/
  if(a[i-1] == b[j-1]){lcs++;/* cout<<"same element at "<<i<<" ,"<<j<<endl; */}
  while(i > 0 && j > 0){
    /* cout<<"i, j is "<<i<<" ,"<<j<<endl; */
    if(ED_matrix[i][j] == ED_matrix[i-1][j] + 1){ i-- ; }
    else if(ED_matrix[i][j] == ED_matrix[i][j-1] + 1){ j-- ; }
    else{i--; j--;}
    if(a[i-1] == b[j-1] && i > 0 && j > 0){lcs++;/* cout<<"same element at "<<i<<" ,"<<j<<endl; */}
  }
  int ab_min = min( a.size(), b.size());
  lcs = min(ab_min, lcs);
  return lcs;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }
  std::cout << lcs2(a, b) << std::endl;
}
