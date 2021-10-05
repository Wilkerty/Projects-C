#include<stdio.h>
#include<stdlib.h>
#define Tam 10

float **preenche(float **mat){
  int Lin=Tam, Col=Tam;
  mat =  malloc (Lin * sizeof(float*));
  for (int k=0;k<Tam;k++){
    mat[k] = malloc(Col * sizeof(float));
  }
  for (int i=0;i<Tam;i++){
    for (int j=0;j<Tam;j++){
      mat[i][j] = rand()%100; 
    }  
  }
  return mat;
}

float *diagonal (float **mat){
  float *vet; 
  vet = malloc(Tam * sizeof(float));
  for (int i=0;i<Tam;i++){
    vet[i]=mat[i][i];  
  }
  return vet;
}

void imprime(float *vet){
  for (int i=0;i<Tam;i++){
    printf("matriz[%d][%d]=%2f - ",i,i,vet[i]);
  }
}

void LiberaMatriz(float **mat){
  for(int i=0;i<Tam;i++)
    free(mat[i]);
  free(mat);
}

int main(){
  float **mat, *vet;
  vet = malloc(Tam * sizeof(float));
  mat = preenche(mat);
  vet = diagonal(mat);
  imprime(vet);
  LiberaMatriz(mat);
  free(vet);
  return 0;
}