 #include<algorithm>
 #include<cmath>
 #include<cstdio>

   using namespace std;

   int N;
   int esquina[20000];
   int sum[20000];

   int main() {
       for(;;) {
           if(scanf("%d", &N) != 1) break;
           int num_esquina = pow(2, N);
           int max_sum = 0;
           for(int i = 0; i < num_esquina; i++)
               scanf("%d", &esquina[i]);
           for(int i = 0; i < num_esquina; i++) {
               int esquina_sum = 0;
               for(int j = 0; j < N; j++) {
                   int b = i ^ (1<< j);
                   esquina_sum += esquina[b];
                }
               sum[i] = esquina_sum;
           }
           for(int i = 0; i < num_essquina; i++) {
               for(int j = 0; j < N; j++) {
                   int b = i ^ (1 << j);
                   max_sum = max(max_sum, sum[i] + sum[b]);
               }
           }
           printf("%d\n", max_sum);
       }
}


















