#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int main(){



void *pBuffer, *pbuffer2;
	
	printf("Digite sua escolha:\n 1)Adicionar pessoa\n 2)Remover pessoa\n 3)Buscar pessoa\n 4)Listar todos\n 5)Sair\n");
	pBuffer= ( void * ) malloc (sizeof(void) *10 );
	scanf("%s",(char*)pBuffer);
	printf("%s\n",(char*)pBuffer);
	pbuffer2= ( void * ) malloc (sizeof(void) *10 );
	scanf("%d", (int)&pbuffer2);
	printf("idade: %d\n",(int)pbuffer2);
}
