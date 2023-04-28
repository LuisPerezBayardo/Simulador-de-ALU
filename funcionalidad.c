#include "definicion.h"


int resultado=0;

/***************************** Operaciones *****************************/


int convertidor(bool b[10]){
	int i, num=0;
	for(i=0; i<10; i++){
		if(b[i]) num+=pow(2, i); 
	}
	return num;
}


/***************************** Métodos *****************************/


int zero(void){
	printf("000000000");
	return 0;
}


int one(void){
	printf("000000001");
	return 1;
}


int minus_one(void){
	printf("100000001");
	return -1;
}


int x_input(bool x[9]){
	char temp[9];
	int i;
	for(i=0; i<9; i++){		// Reordenar el string para imprimir
		if(x[i]) temp[8-i]=49;
		else temp[8-i]=48;
	}
	printf("%s", temp);		// Imprimir
	return convertidor(x);	// Resultado en decimal
}


int y_input(char y[9]){
	char temp[9];
	int i;
	for(i=0; i<9; i++){		// Reordenar el string para imprimir
		if(y[i]) temp[8-i]=49;
		else temp[8-i]=48;
	}
	printf("%s", temp);		// Imprimir
	return convertidor(y);	// Resultado en decimal
}


int not_x(bool x[9]){
	char temp[9];
	int i;
	for(i=0; i<9; i++){
		x[i]=!x[i];
	}
	for(i=0; i<9; i++){
		if(x[i]) temp[8-i]=49;
		else temp[8-i]=48;
	}
	printf("%s", temp);
	return convertidor(x);
}


int not_y(bool y[9]){
	char temp[9];
	int i;
	for(i=0; i<9; i++){
		y[i]=!y[i];
	}
	for(i=0; i<9; i++){
		if(y[i]) temp[8-i]=49;
		else temp[8-i]=48;
	}
	printf("%s", temp);
	return convertidor(y);
}


int minus_x(bool x[9]){
	x[8]!=x[8];
	char temp[9];
	int i;
	for(i=0; i<9; i++){		// Ordenar el string para imprimir
		if(x[i]) temp[8-i]=49;
		else temp[8-i]=48;
	}
	if(!x[8]) temp[0]=49;
	else temp[0]=48;
	printf("%s", temp);		// Imprimir
	return convertidor(x);	// Resultado en decimal
}


int minus_y(bool y[9]){
	y[8]!=y[8];
	char temp[9];
	int i;
	for(i=0; i<9; i++){		// Ordenar el string para imprimir
		if(y[i]) temp[8-i]=49;
		else temp[8-i]=48;
	}
	if(!y[8]) temp[0]=49;
	else temp[0]=48;
	printf("%s", temp);		// Imprimir
	return convertidor(y);	// Resultado en decimal
}


int x_plus_one(bool x[9], bool sum_res){
	int i;
	char temp[9];
	bool flag=sum_res;	// false: suma; true: resta
	///////////////////////// x++
	if(!sum_res){
		if(x[8]){	// Si es negativo
			for(i=0; i<8; i++){
				if(!flag){
					if(x[i]){
						flag=true;
						i=7-i;
					}
				}
				else x[7-i]!=x[7-i];
			}
		}
		else{		// Si es positivo
			for(i=0; i<8; i++){ // Suma
				if(!x[i]){
					x[i]^=1;
					i=8;
				}
			}
		}
	}
	else{
		if(!x[8]){	// Si es negativo
			for(i=0; i<8; i++){
				if(!flag){
					if(x[i]){
						flag=true;
						i=7-i;
					}
				}
				else x[7-i]!=x[7-i];
			}
		}
		else{		// Si es positivo
			for(i=0; i<8; i++){ // Suma
				if(!x[i]){
					x[i]^=1;
					i=8;
				}
			}
		}
	}
	///////////////////////// Ordenamiento String
	for(i=0; i<9; i++){
		if(x[i]) temp[8-i]=49;
		else temp[8-i]=48;
	}
	///////////////////////// Imprimir
	printf("%s", temp);
	///////////////////////// Resultado decimal
	return convertidor(x);
}


int y_plus_one(bool y[9], bool sum_res){
	int i;
	char temp[9];
	bool flag=sum_res;	// false: suma; true: resta
	///////////////////////// y++
	if(!sum_res){
		if(y[8]){	// Si es negativo
			for(i=0; i<8; i++){
				if(!flag){
					if(y[i]){
						flag=true;
						i=7-i;
					}
				}
				else y[7-i]!=y[7-i];
			}
		}
		else{		// Si es positivo
			for(i=0; i<8; i++){ // Suma
				if(!y[i]){
					y[i]^=1;
					i=8;
				}
			}
		}
	}
	//////////////////////// y--
	else{
		if(!y[8]){	// Si es negativo
			for(i=0; i<8; i++){
				if(!flag){
					if(y[i]){
						flag=true;
						i=7-i;
					}
				}
				else y[7-i]!=y[7-i];
			}
		}
		else{		// Si es positivo
			for(i=0; i<8; i++){ // Suma
				if(!y[i]){
					y[i]^=1;
					i=8;
				}
			}
		}
	}
	///////////////////////// Ordenamiento String
	for(i=0; i<9; i++){
		if(y[i]) temp[8-i]=49;
		else temp[8-i]=48;
	}
	///////////////////////// Imprimir
	printf("%s", temp);
	///////////////////////// Resultado decimal
	return convertidor(y);
}


int sum(bool x[9], bool y[9]){
	int i;
	bool c=false; // Carry
	bool out[10];
	
	printf("\n\nx[i]\ty[i]\tCarry\t\tOut\tCarry siguiente");
	for(i=0; i<8; i++){		//////////////////////////// Suma
		printf("\n%d\t%d\t%d\t=\t", x[i], y[i], c);
		if(x[i]==y[i]){
			out[i]=c;
			c=x[i];
		}
		else out[i]=!c; // 'c' queda igual
		printf("%d\t%d", out[i], c);
	}
	printf("\n0\t0\t%d\t=\t%d\t0", c, c);
	out[8]=c;
	out[9]=x[8];
	
	printf("\n\nSalida: ");
	for(i=0; i<10; i++) printf("%d", out[9-i]);
	return convertidor(out);
}


int substraction(bool x[9], bool y[9]){
	int i;
	bool c=false; // Carry
	bool out[9];
	
	for(i=0; i<8; i++){
		out[i]=(x[i]^y[i]^c);
		c=(y[i]&&c)||(!x[i]&&(y[i]||c));
	}
	out[8]=x[8];
	
	for(i=0; i<9; i++) printf("%d", out[8-i]);
	return convertidor(out);
}


int and_(bool x[9], bool y[9]){
	int i;
	bool out[9];
	for(i=0; i<9; i++) out[i]=(x[i]&&y[i]);
	for(i=0; i<9; i++){
		if(out[8-i]) printf("1");
		else printf("0");
	}
	return convertidor(out);
}


int or_(bool x[9], bool y[9]){
	int i;
	bool out[9];
	for(i=0; i<9; i++) out[i]=(x[i]||y[i]);
	for(i=0; i<9; i++){
		if(out[8-i]) printf("1");
		else printf("0");
	}
	
	/****** Debugging *******
	printf("\n\nDebugging:\n");		// Debugging
	printf("\nx: ");
	for(i=0; i<9; i++) printf("%d", x[8-i]);
	printf("\ny: ");
	for(i=0; i<9; i++) printf("%d", y[8-i]);
	printf("\nout: ");
	for(i=0; i<9; i++) printf("%d", out[8-i]);
	************************/
	
	return convertidor(out);
}
