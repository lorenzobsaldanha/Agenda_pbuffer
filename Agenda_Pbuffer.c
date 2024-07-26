#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define NOME_TAMANHO 100
#define EMAIL_TAMANHO 100


#define NODO_TAMANHO ( NOME_TAMANHO + sizeof( int ) + EMAIL_TAMANHO )
 
void* AlocaNodo( void* pbuffer );
void* Remover( void* pbuffer );
void Buscar( void* pbuffer );
void Listar( void* pbuffer );

int main() {
    void *pbuffer;
    int *escolha, *contaNodos, *verificaSeLeuTudo;


    escolha = ( int* ) malloc( sizeof( int ) );
    if ( escolha == NULL ) {
        printf( "Erro de alocação da escolha" );
        exit( 1 );
    }
    
    *escolha = 0;

    contaNodos = ( int* ) malloc( sizeof( int ) );
    if ( contaNodos == NULL ) {
        printf( "Erro de alocação da escolha" );
        exit( 1 );
    }

*contaNodos = 0;

 verificaSeLeuTudo = ( int* ) malloc( sizeof( int ) );
    if ( verificaSeLeuTudo == NULL ) {
        printf( "Erro de alocação da escolha" );
        exit( 1 );
    }
*verificaSeLeuTudo = 0;

 
    pbuffer = ( void* ) malloc( sizeof( int ) );
    if ( pbuffer == NULL ) {
        printf( "Erro de alocação do buffer" );
        exit( 1 );
    }

memcpy( pbuffer, escolha, sizeof( int ) );
free( escolha );


    pbuffer = ( void* ) realloc( pbuffer, _msize( pbuffer ) + sizeof( int ) );
    if (pbuffer == NULL) {
        printf( "Erro de alocação do buffer" );
        exit( 1 );
    }
memcpy( pbuffer + sizeof( int ) ,contaNodos, sizeof( int ) );
free( contaNodos );


    pbuffer = ( void* ) realloc( pbuffer, _msize( pbuffer ) + sizeof( int ) );
    if ( pbuffer == NULL ) {
        printf( "Erro de alocação do buffer" );
        exit( 1 );
    }
memcpy( pbuffer + sizeof( int ) + sizeof( int ), verificaSeLeuTudo, sizeof( int ) );
free( verificaSeLeuTudo );


 printf( "Digite sua escolha:\n 1- Adicionar Pessoa (Nome, Idade, email)\n 2- Remover Pessoa\n 3- Buscar Pessoa\n 4- Listar todos\n 5- Sair\n" );
    scanf( "%d", ( int* )pbuffer );

while( *( int* ) pbuffer != 5 ){
switch( *( int* ) pbuffer ){
    case 1: {

   pbuffer = AlocaNodo( pbuffer );
   (*( int* ) ( pbuffer + sizeof( int ) ) ) ++ ; //contadoNodos++;

    }
      break;

    case 2: {
        if( *( int* ) ( pbuffer + sizeof( int ) ) <= 0 ){
            printf( "A lista esta vazia!\n" );
        }
        else{
        Remover( pbuffer );
        (*( int* )( pbuffer + sizeof( int ) ) ) -- ;
        }
        
    }
     break;

    case 3 :{
         if( *( int* ) ( pbuffer + sizeof( int ) ) <= 0 ){
            printf( "A lista esta vazia!\n" );
        }
        else{
        Buscar( pbuffer );
        }
    }
     break;

    case 4: {
        Listar( pbuffer );
        
    }
     break;

    default:{
        printf( "Numero invalido!\n" );
        
    }
      break;
}
printf( "Digite sua escolha:\n 1- Adicionar Pessoa (Nome, Idade, email)\n 2- Remover Pessoa\n 3- Buscar Pessoa\n 4- Listar todos\n 5- Sair\n" );
    scanf( "%d", ( int* )pbuffer );
}
 printf( "Adeus.\n" );
    
   
    free( pbuffer );

    return 0;
}





void* AlocaNodo( void* pbuffer ) {
    void *nodo = NULL;
    char *nome = NULL, *email = NULL;
    int *idade = NULL;

    
    nodo = ( void* ) malloc( NODO_TAMANHO );
    if (nodo == NULL) {
        printf( "Erro de alocação do nodo" );
        exit(1);
    }
    

   
    nome = ( char* ) malloc( NOME_TAMANHO * sizeof( char ) );
    if (nome == NULL) {
        printf( "Erro de alocação do nome" );
        exit( 1 );
    }
 while ( ( getchar() ) != '\n' );
   
    printf( "Digite o nome:\n" );
    scanf( "%[^\n]s", nome );

 
    while ( ( getchar() ) != '\n' );

  
    idade = ( int* ) malloc( sizeof( int ) );
    if (idade == NULL) {
        printf( "Erro de alocação da idade" );
        exit( 1 );
    }

   
    printf( "Digite a idade:\n" );
    scanf( "%d", idade );

 
    while ( ( getchar() ) != '\n' );

  
    email = ( char* ) malloc( EMAIL_TAMANHO * sizeof( char ) );
    if (email == NULL) {
        printf( "Erro de alocação do email" );
        exit( 1 );
    }

   
    printf( "Digite o email:\n" );
    scanf( "%[^\n]s", email );

  
    while ( ( getchar() ) != '\n' );


   
    memcpy( nodo, nome, NOME_TAMANHO ); 
    memcpy( nodo + NOME_TAMANHO, idade, sizeof( int ) ); 
    memcpy( nodo + NOME_TAMANHO + sizeof( int ), email, EMAIL_TAMANHO ); 


  //se o contador é zero, aloca nodo no final do pbuffer
if( *( int* )( pbuffer + sizeof( int ) ) == 0 ){

        pbuffer = ( void* ) realloc ( pbuffer, sizeof( int ) * 3 + NODO_TAMANHO );
    if ( pbuffer == NULL ) {
        printf( "Erro de realocação do buffer" );
        exit( 1 );
    }

    // Copia o nodo para o buffer
    memcpy( pbuffer + _msize( pbuffer ) - NODO_TAMANHO, nodo, NODO_TAMANHO );
    
}

if(*( int* ) (pbuffer + sizeof( int ) ) > 0 ){//Se já tiver 1 nodo alocado no pbuffer, coloca em ordem
void* atual;

int *vaiDepoisDe;
vaiDepoisDe = ( int* ) malloc ( sizeof( int ) );
if( vaiDepoisDe == NULL ){
    printf( "Erro na alocacao do contador.\n" );
    exit( 1 );
}
*vaiDepoisDe = 0;
 for ( atual = ( pbuffer + ( sizeof( int ) * 3) ); atual < ( pbuffer + _msize( pbuffer ) - ( sizeof( int ) * 3) ); atual = atual + NODO_TAMANHO ) {
        if( strcmp( nodo , atual ) > 0 ){

           //se o nome vier depois do nodo atual, verificaSeLeuTudo = 1
         *( int* )( pbuffer + sizeof( int ) * 2 ) = 1; 
        ( *vaiDepoisDe ) ++;// conta quantos nodos o novo nodo vai depois
        
        }
        
 }

    if( *( int* ) ( pbuffer + sizeof( int ) * 2 ) == 1 ){
        if( *vaiDepoisDe == *( int* )( pbuffer + sizeof( int ) ) ){//se for depois de todos os nodos na ordem alfabética, coloca no fim do pbuffer
                pbuffer = ( void* ) realloc ( pbuffer, _msize( pbuffer ) + NODO_TAMANHO );
    if ( pbuffer == NULL ) {
        printf( "Erro de realocação do buffer" );
        exit( 1 );
    }
      memcpy( pbuffer + _msize( pbuffer ) - NODO_TAMANHO, nodo, NODO_TAMANHO );
        }

        if( *vaiDepoisDe != *( int* )( pbuffer + sizeof( int ) ) ){//se for entre dois nodos, copia o que vem depois, coloca no meio e recoloca o que vem depois
        void *copiaPbuffer;
        copiaPbuffer = ( void* ) malloc ( _msize( pbuffer ) - 3 * sizeof( int ) - NODO_TAMANHO * ( *vaiDepoisDe ) );//copia o que vem depois
        memcpy( copiaPbuffer, ( pbuffer + sizeof( int ) * 3 + NODO_TAMANHO * ( *vaiDepoisDe ) ), _msize( pbuffer ) - 3 * sizeof( int ) - NODO_TAMANHO * ( *vaiDepoisDe ) );
        
        pbuffer = ( void* ) realloc ( pbuffer, ( ( sizeof( int ) * 3 ) + ( NODO_TAMANHO * ( *( int* ) vaiDepoisDe ) ) + NODO_TAMANHO ) );//retira tudo que vem depois e aloca pro novo nodo
        memcpy( pbuffer + _msize( pbuffer ) - NODO_TAMANHO, nodo, NODO_TAMANHO );//coloca novo nodo

        pbuffer = ( void* ) realloc ( pbuffer, _msize( pbuffer ) + _msize( copiaPbuffer ) );//realoca espaco pra copia que foi retirada do fim do pbuffer
        memcpy( ( pbuffer + sizeof( int ) * 3 + NODO_TAMANHO * ( *vaiDepoisDe ) + NODO_TAMANHO ), copiaPbuffer, _msize( copiaPbuffer ) );//coloca a copia de volta
        free( copiaPbuffer );
        }
        *( int* )( pbuffer + sizeof( int ) * 2 ) = 2; // *verificaSeLeuTudo = 2;
            free( vaiDepoisDe );
    }


        if( *( int* ) ( pbuffer + sizeof( int ) * 2 ) != 2 ){//se leu tudo e não colocou o nodo depois de nenhum, então o novo nodo vai na primeira posição
           void *copiaPbuffer;
           copiaPbuffer = ( void* ) malloc ( _msize( pbuffer ) - 3 * sizeof( int ) );// aloca só o espaço dos nodos (aloca tudo - o que eu não quero na cópia)
           memcpy( copiaPbuffer, pbuffer + 3 * sizeof( int ), _msize( pbuffer ) - 3 * sizeof( int ) );// copia só os nodos do pbuffer (aloca só o que eu quero na cópia)
           
           pbuffer = ( void* ) realloc ( pbuffer , ( sizeof( int ) * 3 ) + NODO_TAMANHO );// removeu todos os nodos, e alocou espaço pra um novo nodo
           memcpy( pbuffer + (3 * sizeof( int ) ), nodo, NODO_TAMANHO ); //passa o nodo pra primeira posiçao dos nodos
           pbuffer = ( void* ) realloc ( pbuffer, _msize( pbuffer ) + _msize( copiaPbuffer ) );//aumenta o espaço pros nodos copiados
           memcpy( pbuffer + ( 3 * sizeof( int ) ) + NODO_TAMANHO, copiaPbuffer ,_msize( copiaPbuffer ) );//coloca de novo todos os nodos, na frente do novo nodo
           free( copiaPbuffer );
        
        }
    
}

*( int* )( pbuffer + sizeof( int ) * 2 ) = 0; //reseta o verificaSeLeuTudo

  
    free( nome );
    free( idade );
    free( email );
    free( nodo );


  
return ( pbuffer );

}

void* Remover( void* pbuffer ){
char *nome;
void *copiaPbuffer;
void* atual;

    nome = ( char* ) malloc ( NOME_TAMANHO * sizeof( char ) );
    if ( nome == NULL ) {
        printf( "Erro de alocação do nome" );
        exit( 1 );
    }

   while ( ( getchar() ) != '\n' );
    printf( "Digite o nome da pessoa a ser removida:\n" );
    scanf( "%[^\n]s", nome );

   
    while ( ( getchar() ) != '\n' );

int *contador;
contador = ( int* ) malloc ( sizeof( int ) );
*contador = 0;

   for ( atual = ( pbuffer + ( sizeof( int ) * 3 ) ); atual < ( pbuffer + _msize( pbuffer ) - ( sizeof( int ) * 3 ) ); atual = atual + NODO_TAMANHO ) {
        if(strcmp( nome , atual ) == 0){//se os nomes forem iguais, copia tudo depois do nodo a ser removido, retira ele, coloca a cópia de volta
      
         copiaPbuffer = ( void* ) malloc ( _msize( pbuffer ) - ( ( sizeof( int ) * 3 ) + ( NODO_TAMANHO * ( *contador ) ) ) - NODO_TAMANHO );//aloca tudo - o que leu até chegar ali (os inteiros e os nodos junto com o nodo a ser removido)
         memcpy( copiaPbuffer , pbuffer + sizeof( int ) * 3 + ( NODO_TAMANHO * ( *contador ) ) + NODO_TAMANHO, _msize( pbuffer ) - ( sizeof( int ) * 3 ) - ( NODO_TAMANHO * ( *contador ) ) - NODO_TAMANHO );//copia à partir do que não foi alocado, o espaço de tudo o que foi alocado em cópia
                                                                                //pula ele aqui em cima
         pbuffer = ( void* ) realloc ( pbuffer, ( sizeof( int ) * 3 ) + ( NODO_TAMANHO * ( *contador ) ) );//remove o nodo
         pbuffer = ( void* ) realloc ( pbuffer, ( sizeof( int ) * 3 ) + ( NODO_TAMANHO * ( *contador ) ) + _msize( copiaPbuffer ) );//aloca só o espaço do que foi lido até o no removido + o que foi copiado (deixa o removido de fora)
         memcpy( pbuffer + sizeof( int ) * 3 + ( NODO_TAMANHO * ( *contador ) ) ,copiaPbuffer , _msize( copiaPbuffer ) );//vai até antes do removido, coloca o que foi copiado
        free( copiaPbuffer );
        }
  ( *contador ) ++ ;
 }

 free( contador );
 free( nome );

 return ( pbuffer );
}


void Buscar( void* pbuffer ){
char *nome;
void *atual;


    nome = ( char* ) malloc( NOME_TAMANHO * sizeof( char ) );
    if ( nome == NULL ) {
        printf( "Erro de alocação do nome" );
        exit( 1 );
    }

    
    printf( "Digite o nome:\n" );
    scanf( "%[^\n]s", nome );

   
    while ( ( getchar() ) != '\n' );

  
    for ( atual = ( pbuffer + ( sizeof( int ) * 3) ); atual < ( pbuffer + _msize( pbuffer ) - ( sizeof( int ) * 3) ); atual = atual + NODO_TAMANHO ) {

        if( strcmp( nome , atual ) == 0 ){
        printf( "Nome: %s\n", ( char* )( atual ) );
        printf( "Idade: %d\n", *( int* )( atual + NOME_TAMANHO ) );
        printf( "Email: %s\n", ( char* ) (atual + NOME_TAMANHO + sizeof( int ) ) );
        }
}

}


void Listar( void* pbuffer ) {
   
    void *atual;

  
    for ( atual = ( pbuffer +( sizeof( int ) * 3) ); atual < ( pbuffer + _msize( pbuffer ) - ( sizeof( int ) * 3 ) ); atual = atual + NODO_TAMANHO ) {

        printf( "Nome: %s\n", (char*)( atual ) );
        printf( "Idade: %d\n", *(int*)( atual + NOME_TAMANHO) );
        printf( "Email: %s\n", (char*)( atual + NOME_TAMANHO + sizeof( int ) ) );

       
        
    }
}

