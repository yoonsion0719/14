#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct Book {
	int number;
	char title[10];
};


void main(void){
	int i;
	struct Book **bookshelf;
	
	bookshelf=(struct Book**)malloc(3*sizeof(struct Book*));
	//이놈은 2차원 포인터 & 구조체 3개 할당 
	for (i=0;i<3;i++)
		bookshelf[i]= (struct Book*)malloc(10*sizeof(struct Book));
		//이친구는 1차원 포인터 & 구조체 10개 할당 
		
	bookshelf[1][3].number=5;
	strcpy(bookshelf[1][3].title, "C++ Programming");
	
	(bookshelf[2]+4)->number=3;
	strcpy((bookshelf[2]+4)->title, "Communications Theory");
	
	printf("book (1,3): %i, %s\n",(bookshelf[1]+3)->number, (bookshelf[1]+3)->title);
	printf("book (2,4): %i, %s\n",bookshelf[2][4].number, bookshelf[2][4].title);
	
	for (i=0;i<3;i++){
		free(bookshelf[i]);
	}
	//각 행에 할당된 메모리 해제 & 구조체 포인터 3개가 각각 가르키는 주소 해제 
	free(bookshelf);
	//전체 배열에 대한 메모리 해제 & 구조체 이중 포인터가 가르키는 주소 해제 
	
	return;
}
