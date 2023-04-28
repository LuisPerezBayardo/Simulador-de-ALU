#include "definicion.h"


int main(int argc, char *argv[]) {
	
	bool zx, nx, zy, ny, f, no, resultado[8], x_[9], y_[9];
	int temp, i, resultado_;
	char x[9], y[9];
	
	
	while(1){
		printf("\n\n\n\n\n\t\tALU");
		
		printf("\n\n\n\tIngrese las entradas\n");		//////////////////////////////////////////////////////////////////////// Entrada de datos
		
		printf("\n\n1. Presetting de la entrada x:");		// zx
		printf("\n\nzx: ");
		fflush(stdin);
		scanf("%d", &temp);
		zx=temp;
		
		printf("\nnx: ");									// nx
		fflush(stdin);
		scanf("%d", &temp);
		nx=temp;
		
		printf("\n\n2. Presetting de la entrada y:");		// zy
		printf("\n\nzy: ");
		fflush(stdin);
		scanf("%d", &temp);
		zy=temp;
		
		printf("\nny: ");									// ny
		fflush(stdin);
		scanf("%d", &temp);
		ny=temp;
		
		printf("\n\n3. Seleccion entre computar 1 o 2:");	// nf
		printf("\n\nf: ");
		fflush(stdin);
		scanf("%d", &temp);
		f=temp;
		
		printf("\n\n4. Postsetting de la salida:");			// no
		printf("\n\nno: ");
		fflush(stdin);
		scanf("%d", &temp);
		no=temp;
		
		
		temp=0;												// X y Y
		while(temp==0){		// Validación
			printf("\n\n5. Ingrese las entradas (8 bits mas 1 de signo):\n");
			
			printf("\nx: ");
			fflush(stdin);
			scanf("%s", &x);
			
			printf("\ny: ");
			fflush(stdin);
			scanf("%s", &y);
			
			/************* DEBUGGING *************
			printf("\n\n\n\nDebugging\n\n");	// Debugging
			printf("x: %s\ny: %s\n\n", x, y);
			for(i=0; i<9; i++){
				if(x[8-i]==49) printf("1"); // =="1"
				else if(x[8-i]==48) printf("0"); // =="0"
				else printf("x");
			}
			*************************************/
			
			temp=1;
			for(i=0; i<9; i++){		// Validación
				if(!(((x[i]==48)||(x[i]==49)) && ((y[i]==48)||(y[i]==49)))){
					printf("\n\n\nNumero binario invalido en las entradas");
					temp=0;
					i=9;
				}
			}
		}
		
		
		for(i=0; i<9; i++){		// Reordenamiento correcto en X y Y (en booleano)
			if(x[i]==49) x_[8-i]=true;
			else x_[8-i]=false;
			if(y[i]==49) y_[8-i]=true;
			else y_[8-i]=false;
		}
		
		for(i=0; i<9; i++){		// Reordenamiento correcto en X y Y (en char)
			if(x_[i]) x[i]="1";
			else x[i]="0";
			if(y_[i]) y[i]="1";
			else y[i]="0";
		}
		
		/************* Debugging *************
		printf("\n\n\nDebugging antes de la funcion:"); 	// Debugging
		printf("\n\nx: ");
		for(i=0; i<9; i++) printf("%d", x_[8-i]);
		printf("\n\ny: ");
		for(i=0; i<9; i++) printf("%d", y_[8-i]);
		*************************************/
		
		printf("\n\n\nSalida: ");		//////////////////////////////////////////////////////////////////////////////////////// Procesamiento y salida de datos
		if(zx && !nx && zy && !ny && f && !no) resultado_=zero();								// 0
		else if(zx && nx && zy && ny && f && no) resultado_=one();								// 1
		else if(zx && nx && zy && !ny && f && !no) resultado_=minus_one();						// -1
		else if(!zx && !nx && zy && ny && !f && !no) resultado_=x_input(x_);					// x
		else if(zx && nx && !zy && !ny && !f && !no) resultado_=y_input(y_);					// y
		else if(!zx && !nx && zy && ny && !f && no) resultado_=not_x(x_);						// !x
		else if(zx && nx && !zy && !ny && !f && no) resultado_=not_y(y_);						// !y
		else if(!zx && !nx && zy && ny && f && no) resultado_=minus_x(x_);						// -x
		else if(zx && nx && !zy && !ny && f && no) resultado_=minus_y(y_);						// -y
		else if(!zx && nx && zy && ny && f && no) resultado_=x_plus_one(x_, add_one);			// x+1
		else if(zx && nx && !zy && ny && f && no) resultado_=y_plus_one(y_, add_one);			// y+1
		else if(!zx && !nx && zy && ny && f && !no) resultado_=x_plus_one(x_, substract_one);	// x-1
		else if(zx && nx && !zy && !ny && f && !no) resultado_=y_plus_one(y_, substract_one);	// y-1
		else if(!zx && !nx && !zy && !ny && f && !no){											// x+y
			if(x_[8]!=y_[8]) resultado_=substraction(x_, y_);	// Signos diferentes
			else resultado_=sum(x_, y_);						// Signos iguales
		}
		else if(!zx && nx && !zy && !ny && f && no){											// x-y
			if(x_[8]==y_[8]) resultado_=substraction(x_, y_);	// Signos iguales
			else resultado_=sum(x_, y_);						// Signos diferentes
		}
		else if(!zx && !nx && !zy && ny && f && no){											// y-x
			if(x_[8]==y_[8]) resultado_=substraction(y_, x_);	// Signos iguales
			else resultado_=sum(y_, x_);						// Signos diferentes
		}
		else if(!zx && !nx && !zy && !ny && !f && !no) resultado_=and_(x_, &y_);				// x&y
		else if(!zx && nx && !zy && ny && !f && no) resultado_=or_(x_, y_);						// x|y
		
		printf("\n\nSalida en decimal: %d", resultado_);
		
		
		printf("\n\n");					//////////////////////////////////////////////////////////////////////////////////////// Salir o nueva operación
		system("PAUSE");
		printf("\n\n\nSi desea realizar una nueva operacion, ingrese '1'. Si desea salir, ingrese cualquier otro numero: ");
		fflush(stdin);
		scanf("%d", &temp);
		if(temp!=1) break;
		
	}
	return 0;
}
