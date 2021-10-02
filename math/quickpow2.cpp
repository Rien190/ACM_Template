const int mod = 1e9 + 7;
struct Matrix{
  int n, m;
  int num[100][100];//矩阵规模最大为100*100
  Matrix(){}
  Matrix(int n, int m): n(n), m(m){
    memset(num, 0, sizeof num);
  }
  friend Matrix operator * (const Matrix &a, const Matrix &b){
    Matrix c(a.n, b.m);
    for(int i = 0; i < c.n; i++){
      for(int j = 0; j < c.m; j++){
        for(int k = 0; k < a.m; k++){
          c.num[i][j] = (c.num[i][j] + (long long)a.num[i][k] * b.num[k][j] % mod) % mod;
        }
      }
    }
    return c;
  }
};
Matrix ksm(Matrix a, long long b){
  Matrix s(a.n, a.n);
  for(int i = 0; i < a.n; i++) s.num[i][i] = 1;
  while(b){
    if(b & 1) s = s * a;
    a = a * a;
    b >>= 1;
  }
  return s;
}
int main(){
  int n;long long k;//n*n的矩阵,k次方
  scanf("%d%lld",&n,&k);
  Matrix M(n, n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d",&M.num[i][j]);
    }
  }
  M = ksm(M, k);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      printf("%d ",M.num[i][j]);
    }
    printf("\n");
  }
  return 0;
}