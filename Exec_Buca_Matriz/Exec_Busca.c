#include<stdio.h> 
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

///// Preenche um vetor com numeros aleatorios de 0 a 10000
int *preenche(int *vet,int n){
    
    vet = malloc(n * sizeof(int*));
    
    for(int i=0;i<n;i++){
        vet[i] = rand()%10000;
        //printf("%d ",vet[i]); --->Opcao de visualizar os elementos dos vetores 
    }
    return vet;
}

///// Realiza a busca sequencial de uma chave em um vetor
int buscaSequencial(int *vet, int key,int n){
    int count=0;
    for (int i=0;i<n;i++){
      if (vet[count]==key){
         break;
      }
      else{
         count++;     
      }        
    }
    if(vet[count]!=key)
        return -1;
    else 
      return count;    
}

///// Realiza a busca binaria de uma chave em um vetor
int buscaBinaria(int *vet, int n, int key){
    int inicio = 0, fim = n, meio; 
    bool encontrado=false;
    while (inicio < fim-1 && !encontrado) {  
        meio = (inicio + fim)/2;
        if (vet[meio] == key){
            encontrado = true;
        }    
        else if(vet[meio]>key){
            fim = meio-1; 
        }
        else
            inicio = meio+1;
    }
    if (encontrado==true)
        return meio;
    else
        return -1;    
}

///// Ordena um vetor 
int *ordena(int *vet,int n){
    int aux=0, menor=0;
    for (int i=0;i<n-1;i++) {
        menor=i;
        for (int j=i+1;j<n;j++){
            if (vet[j]<vet[menor]){  
                menor = j;
            }
        }
        aux=vet[i];
        vet[i]=vet[menor];
        vet[menor]=aux;
    }
    return vet;
}

int main(){
    int key=0, *vetAux, *vet, auxSeq=0, auxBin=0, n=1000, **VET, N=10, indiceSeq=0, indiceBin=0;
    clock_t tempo1, tempo2;
    
    ///// Alocacao do vetor VET que contém os demais vetores
    VET=malloc(N * sizeof(int*));
    for (int i=0;i<N;i++){
        vet=preenche(vet,n);
        VET[i] = vet;
    }
    
    scanf("%d",&key); 
    
    ///// Faz a busca sequencial, e imprime a posicao da chave e em qual vetor ela se encontra  
    tempo1 = clock();
    for (int i=0;i<N;i++){
        vetAux = VET[i];
        auxSeq=buscaSequencial(vetAux,key,n);
        indiceSeq = i;
        if(auxSeq>=0)
            break;
    }
    if (auxSeq<0)
        printf("\nValor não encontrado");
    else  
        printf("\nposicao: %d\nvetor: %d", auxSeq, indiceSeq);
    tempo1 -= clock();

    ///// Ordena os vetores de VET, e imprime a posicao da chave e em qual vetor ela se encontra
    tempo2 = clock();
    for (int i=0;i<N;i++){
        VET[i]=ordena(VET[i],n);
    }  
    for (int i=0;i<N;i++){
      auxBin=buscaBinaria(VET[i],n,key);
      if (auxBin>=0){
        indiceBin=i;
        break; 
      }
    }
    
    if (auxBin<0)
        printf("\nValor não encontrado");
    else  
        printf("\nposicao: %d\nvetor: %d", auxBin, indiceBin);
    tempo2 -= clock();
    
    ///// Imprime o tempo de execução de ambas as funções
    printf("\n\nTempo de execucao: %lf", ((double)tempo1)/((CLOCKS_PER_SEC/1000)));
    printf("\nTempo de execucao: %lf", ((double)tempo2)/((CLOCKS_PER_SEC/1000)));
    
    free(VET);
    free(vet);
    return 0; 
}