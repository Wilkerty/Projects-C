#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int countSoma=0, countMulti=0;

void imprime(double **mat, int n){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        printf("%f ",mat[i][j]);
      }  
      printf("\n");
    }
  
}

double **aloca (double **mat, int n){
  mat =  malloc (n * sizeof(double*)); 
  for (int i=0;i<n;i++){
    mat[i] =  malloc (n * sizeof(double*)); 
  }
  return mat;
}

double **preencher(double **mat, int n){
  mat = aloca(mat,n);  
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      mat[i][j]=rand()%100; 
      printf("%f ",mat[i][j]);
    }  
    printf("\n");
  }
  return mat;
}


double **SomaMatriz(double **soma, double **matA, double **matB, int n){

  for(int i=0;i<n;i++){ //--->O(n^2)
    for(int j=0;j<n;j++){ //--->O(n^2)
      soma[i][j]=matA[i][j]+matB[i][j]; //--->O(1)  
      countSoma++;
    }
  }    
  return soma; //--->O(1)
} //--->O(n^2)*O(n^2)+O(1)+O(1) => O(n^4)

double **MultiMatriz(double **multi, double **matA, double **matB, int n){
 
  for (int i=0;i<n;i++){ //--->O(n^2)
    for (int j=0;j<n;j++){ //--->O(n^2)
      for(int k=0;k<n;k++){ //--->O(n^2)
        multi[i][j]+=matA[i][k]*matB[k][j]; //--->O(1)  
        countMulti++;
      }
    }
  }

  return multi; //--->O(1)
  
} //--->O(n^2)*O(n^2)*O(n^2)+O(1)+O(1) => O(n^6)

int main(){
  double **soma, **matA, **matB, **multi;
  int n, operacao;
  n = rand()%100;
  printf("Matriz A\n");
  matA = preencher(matA,n);
  printf("\nMatriz B\n");
  matB = preencher(matB,n);
  soma = aloca(soma,n);
  multi = aloca(multi,n);
  printf("------------------------------------\n 1.Soma       2.Multiplicacao\n\n Qual operação deseja realizar? ");
  scanf("%d",&operacao);
  printf("\n");
  if (operacao==1){
    soma = SomaMatriz(soma,matA,matB,n);
    imprime(soma,n);
    printf("\n\nNúmero de passos necessários para realizar a soma: %d",countSoma);
  }
  if (operacao==2){
    multi = MultiMatriz(multi,matA,matB,n);
    imprime(multi,n);
    printf("\nNúmero de passos necessários para realizar a multiplicação:%d",countMulti);
  }

  free(multi);
  free(matA);
  free(matB);
  free(soma);
  return 0;
}