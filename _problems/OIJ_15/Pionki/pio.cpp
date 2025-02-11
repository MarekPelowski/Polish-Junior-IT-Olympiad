#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<char>> B(N, vector<char>(M));
  vector <int> rows(N), cols(M);
  int maxRows = 0, maxCols = 0, hash = 0;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> B[i][j];
      if(B[i][j] == '#') {
        hash++;
        rows[i]++;
        cols[j]++;
        maxRows = max(maxRows, rows[i]);
        maxCols = max(maxCols, cols[j]);
      }
    }
  }

  int row = 0, col = 0;
  bool exit = false;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(rows[i] == maxRows && cols[j] == maxCols) {
        row = i;
        col = j;
        if(B[i][j] == '#') {
          exit = true;
          break;
        }
      }
    }
    if(exit)
      break;
  }

  int rowCnt = 0, colCnt = 0;

  for(int i = 0; i < M; i++)
    if(B[row][i] == '#') rowCnt++;
  for(int i = 0; i < N; i++)
    if(B[i][col] == '#') colCnt++;

  if(exit)
    cout << (rowCnt + colCnt - 2) + 2 * (hash - (rowCnt + colCnt - 1)) << "\n";
  else
    cout << rowCnt + colCnt + 2 * (hash - (rowCnt + colCnt)) << "\n";

  return 0;
}