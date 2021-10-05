#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int **aloca(int **mat, int n){
  mat =  malloc (n * sizeof(int*));
  for (int k=0;k<n;k++){
    mat[k] = malloc(n * sizeof(n));
  }
  
  return mat;
}

int **recebe(int **mat, int n){
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (j>i){
        mat[i][j]=0;
      }
      else{  
        printf("Digite o componente a%d%d da matriz: ",i,j);
        scanf("%d",&mat[i][j]);
      }  
    }
  }
  return mat;
}

int *adiciona(int **mat, int *vet, int n){
  int aux=0;
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (j>=i){
        vet[aux]=mat[j][i];  
        aux++;
      }
    }
  }
  return vet;
}

void posicao (int n){
  int i=0, j=0, indice=0;
  printf("\nDigite os valores de i e j da posicao na matriz: ");
  scanf("%d%d", &i,&j);
  int aux=j;
  while(aux>=0){
    indice += n-aux;
    aux--;
  }
  
  indice = indice-(n-i);
  printf("\nA posicao a%d%d na matriz, corresponde ao indice %d do vetor",i,j,indice);
}

void imprime(int *vet, int p){
  int i=0;
  printf("\nV={%d",vet[i]);
  for ( i=1;i<p;i++){
    printf(",%d",vet[i]);
  }
  printf("}");
}

void LiberaMatriz(int **mat, int n){
  for(int i=0;i<n;i++)
    free(mat[i]);
  free(mat);
}

int main(){
  int **mat, *vet, n, p=0, aux, i, j;
  
  printf("\nDigite a dimensão n da matriz: ");
  scanf("%d",&n);
  aux=n;
  while(aux!=-1){
    p+=aux;
    aux--;
  }
  vet = malloc(p * sizeof(int));
  mat = aloca(mat,n);
  mat=recebe(mat,n);
  vet=adiciona(mat,vet,n);
  imprime(vet,p);
  posicao(n);
  LiberaMatriz(mat,n);
  free(vet);
  return 0;
}