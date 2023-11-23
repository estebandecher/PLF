#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>
#include <locale.h>
//#include <wchar.h>
#include <math.h>



char invalidos[100][3]={"ñ","Ñ","á","é","í","ó","ú","ý","Á","É","Í","Ú","@"};


char numeros[10]={'1','2','3','4','5','6','7','8','9','0'};
char letrasMin[28]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char letrasMayus[28]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char caracterDetectar[20]={'+','-','=','<','>',';',',','.','#','(',')','*','/'};
char terminales[80][10]={"const","var","procedure",":=","call","begin","end","if","then","while","do","odd","<=",">=","+","-","=","<",">",";",",",".","#","(",")","*","/"};


char arrayViejo[400][20]={'\0'};
char arrayNuevo[400][20]={'\0'};
char arrayValido[400][20]={'\0'};
int cantidadPalabrasViejo=0;
int cantidadPalabrasNuevo=0;
int cantidadPalabrasValido=0;



int esInvalido(char caracter){

	int i=0;
	int dif=0;	

	char str[3];

	//tranformar caracter a string

	while(i<13){

		//dif=strcmp(invalidos[i],caracter);

		//Distintos
		if (dif!=0){



			return 0;

		}


		i=i+1;


	}

	return 1;


}


int esNumero(char caracter){

	int i=0;
	int dif=0;
	while(i<10){
		//dif =strcmp(caracter,numeros[i]);
		if (caracter==numeros[i]){
			return i;
		}
		i=i+1;
	}
	return -1;
}


int esLetra(char caracter){

	int i=0;
	int dif=0;
	while(i<26){
		//dif =strcmp(caracter,letrasMin[i]);
		if (caracter==letrasMin[i] || caracter==letrasMayus[i]){
			return i;
		}
		i=i+1;
	}
	return -1;

}

int esCaracterDetectar(char caracter){

	int i=0;
	int dif=0;
	while(i<13){
		//dif =strcmp(caracter,numeros[i]);
		if (caracter==caracterDetectar[i]){
			return i;
		}
		i=i+1;
	}
	return -1;
}



//Caso de elimkinar
//crea un archivo sin los caracteres invalidos 
void leer(FILE *archivo,FILE *archivoSalida){


	char caracter;
	caracter=fgetwc(archivo);
	int i;
	//cantidadPalabras=cantidadPalabras+1;

	while (!feof(archivo)){		
		//cantidadPalabras=cantidadPalabras+1;

		

		fputwc(caracter,archivoSalida);

		//sig

		i=i+1;
		printf("\n%c",caracter);
		caracter=fgetwc(archivo);
		//fputwc(caracter,archivoSalida);
	}

	//imprimirArray();

}



//void arreglarNuevo

//imprimir todos los caracteres de un chart
int imprimirCaracteres(char *string){

	int i=0;
	char letra=string[0];
	printf("\n");
	while (letra!='\0'){
		printf("%c",letra);
		i=i+1;
		letra=string[i];
	}
	return i;
}


//imprime todas las palabra en el array
void imprimirArrayViejo(){

	int i=0;

	while(i<cantidadPalabrasViejo){
		printf("\nPalabra[%d]: %s",i+1,arrayViejo[i]);
		printf("		Largo[%d]: ",strlen(arrayViejo[i]));
		i=i+1;
	}
}


void crearArrayViejo(FILE *archivo){

	char palabra[20];
	int i=0;
	fscanf(archivo,"%s",arrayViejo[i]);
	cantidadPalabrasViejo=cantidadPalabrasViejo+1;

	while (!feof(archivo)){		
		cantidadPalabrasViejo=cantidadPalabrasViejo+1;
		i=i+1;
		fscanf(archivo,"%s",arrayViejo[i]);
	}

	//printf("\nPasa");	
	imprimirArrayViejo();

}



void imprimirArrayNuevo(){

	int i=0;

	while(i<cantidadPalabrasNuevo){
		printf("\nPalabra[%d]: %s",i+1,arrayNuevo[i]);
		printf("		Largo[%d]: ",strlen(arrayNuevo[i]));
		i=i+1;
	}
}


void crearArrayNuevo(FILE *archivo){

	char palabra[20];
	int i=0;
	fscanf(archivo,"%s",arrayNuevo[i]);
	cantidadPalabrasNuevo=cantidadPalabrasNuevo+1;

	while (!feof(archivo)){		
		cantidadPalabrasNuevo=cantidadPalabrasNuevo+1;
		i=i+1;
		fscanf(archivo,"%s",arrayNuevo[i]);
	}

	//printf("\nPasa");	
	imprimirArrayNuevo();

}



void imprimirArrayValido(){

	int i=0;

	while(i<cantidadPalabrasValido){
		printf("\nPalabra[%d]: %s",i+1,arrayValido[i]);
		printf("		Largo[%d]: ",strlen(arrayValido[i]));
		i=i+1;
	}
}


void crearArrayValido(FILE *archivo){

	char palabra[20];
	int i=0;
	fscanf(archivo,"%s",arrayValido[i]);
	cantidadPalabrasValido=cantidadPalabrasValido+1;

	while (!feof(archivo)){		
		cantidadPalabrasValido=cantidadPalabrasValido+1;
		i=i+1;
		fscanf(archivo,"%s",arrayValido[i]);
	}

	imprimirArrayValido();

}




//pendiente
int separarPalabrasInvalidas(char *palabraCorta,char *palabraLarga,FILE *archivoSalida){

	if (strcmp(palabraCorta,palabraLarga)==0){
		printf("\nIdenticas");
		return 0;
	}

	int c=0;
	int l=0;

	int countMaximo=0;
	int countMinimo=0;

	int escritos=0;
	//recorrer
	while(c<strlen(palabraCorta) && l<strlen(palabraLarga)){

		//si los caracteres son distintos 
		if (palabraCorta[c]!=palabraLarga[l]){
			//aumentar contador de palabra larga
			printf("\nDistintas: [%c]==[%c]",palabraCorta[c],palabraLarga[l]);
			fputc(' ',archivoSalida);
			
			l=l+1;
		}else{
			printf("\nIguales: [%c]==[%c]",palabraCorta[c],palabraLarga[l]);
			fputc(palabraCorta[c],archivoSalida);
			escritos=escritos+1;
			c=c+1;
			l=l+1;
		}

	}

	return escritos;
	//REVISAR
	/*
	if(disintas==0){
		fprintf(archivoSalida, "%s",palabraCorta);
	} 
	*/

}


void fixInvalidas(FILE *archivoSalida){
	int v=0;
	int n=0;

	int escritos;
	while (n<cantidadPalabrasNuevo && v<cantidadPalabrasViejo){

		//char algo=getchar();
		printf("\nAnalizando: 	[%s]	[%s]",arrayViejo[v],arrayNuevo[n]);
		//Si las palabras son iguales, estos no se deben separar y tiene que quedar igual
		if (strcmp(arrayNuevo[n],arrayViejo[v])!=0){
			//Ver que palabra tiene el mayor largo
			printf("\nentra");
			if (strlen(arrayNuevo[n])>strlen(arrayViejo[v])){
				escritos=separarPalabrasInvalidas(arrayViejo[v],arrayNuevo[n],archivoSalida);
			}else{
				escritos=separarPalabrasInvalidas(arrayNuevo[n],arrayViejo[v],archivoSalida);
			}
			
			//si no se encontraron caractees iguales
			/*
			if (diferentes!=0){
				fprintf(archivoSalida, "%s", arrayNuevo[n]);
			}
			*/
			if (escritos>0){
				fprintf(archivoSalida, "%s"," ");
				v=v+1;
				n=n+1;	
			}else{
				v=v+1;
			}
			

		}else{
			fprintf(archivoSalida, "%s",arrayNuevo[n]);
			fprintf(archivoSalida, "%s"," ");
			v=v+1;
			n=n+1;
		}

	}

}



//si la palabra pertenece a los terminales 
int pertenece(char *palabra){
	int i=0;
	int dif=0;
	while(i<29){
		dif =strcmp(palabra,terminales[i]);
		if (dif==0){
			return i;
		}
		i=i+1;
	}
	return -1;
}



//funcion para analizar una palabra 
//MAIN
void analizarPalabra(char *palabra,FILE *archivoSalida){

	int i=0;
	int estado=1;

	char palabraDetectar[20];
	int p=0;

	printf("\nLargo: %d",strlen(palabra));

	while(i<strlen(palabra)){

		//Se lee el 
		char simbolo=palabra[i];

		printf("\nEstado:%d 		palabra[%d]=[%c]",estado,i,simbolo);


		switch(estado){

			//Estado 1: es es el estado inicial
			case 1:

				//si es un caracter terminal
				if (esCaracterDetectar(simbolo)!=-1){
					printf("\n%c",simbolo);
					fprintf(archivoSalida, "%c\n",simbolo);
					estado=1;
					i=i+1;
				}
				else if(simbolo=='<' || simbolo=='>' || simbolo==':'){
					estado=3;
				}
				else if(esNumero(simbolo)!=-1){
					estado=2;
					i=i+1;
				}
				else if(esLetra(simbolo)!=-1){	
					estado=4;
					i=i+1;

					palabraDetectar[0]=simbolo;
					p=1;
					palabraDetectar[p]='\0';
				}				
				else{
					//FDP
					//return 0;
					//printf("\nEntra");
					estado=1;
					i=i+1;
					//printf("\nPasa");
				}
				break;



			//estados donde solo hay numeros
			case 2:
				if (esNumero(simbolo)!=-1){
					//return 1;
					estado=2;
					i=i+1;
				}else{
					printf("\nNUMERO");
					fprintf(archivoSalida,"%s\n","NUMERO");
					estado=1;

				}
			break;

			//estado donde ya entro < > o =
			case 3:
				if (simbolo=='='){
					printf("%c%c\n",palabra[i-1],palabra[i]);
					fprintf(archivoSalida,"%c%c\n",palabra[i-1],palabra[i]);
					i=i+1;
					estado=1;
				}

			break;

			//Si estaba en letras
			case 4:

				printf("\nPalabra detectar: [%s]\n",palabraDetectar);
				if (pertenece(palabraDetectar)!= -1){

					printf("%s\n",palabraDetectar);
					fprintf(archivoSalida, "%s\n",palabraDetectar);

					palabraDetectar[0]='\0';
					p=1;
					palabraDetectar[p]='\0';

					estado=1;
					//i=i+1;
				}
				else if(esLetra(simbolo)!=-1){

					palabraDetectar[p]=simbolo;
					p=p+1;
					palabraDetectar[p]='\0';

					estado=4;
					i=i+1;
				}else{

					printf("\nIDENTIFICADOR");
					fprintf(archivoSalida, "%s\n","IDENTIFICADOR");
					estado=1;

					palabraDetectar[0]='\0';
					p=1;
					palabraDetectar[p]='\0';
				}


			break;

		}

		


	}



	//FDS
	//si ya no hay mas simbolos

	printf("\nSALE");
	if (estado==1){
		//return 0;	
	}else if (estado==2){
		if (esNumero(palabra[i])!=-1){
			//return 1;
			estado=2;
			i=i+1;
		}else{
			printf("\nNUMERO");
			fprintf(archivoSalida,"%s\n","NUMERO");
			estado=1;

		}
	}
	else if(estado==3){
		if (palabra[i]=='='){
			printf("%c%c\n",palabra[i-1],palabra[i]);
			fprintf(archivoSalida,"%c%c\n",palabra[i-1],palabra[i]);
			i=i+1;
			estado=1;
		}
	}
	else if(estado==4){
		printf("\nPalabra detectar: [%s]\n",palabraDetectar);
		if (pertenece(palabraDetectar)!= -1){

			printf("%s\n",palabraDetectar);
			fprintf(archivoSalida, "%s\n",palabraDetectar);

			palabraDetectar[0]='\0';
			p=1;
			palabraDetectar[p]='\0';

			estado=1;
			//i=i+1;
		}
		else if(esLetra(palabra[i])!=-1){

			palabraDetectar[p]=palabra[i];
			p=p+1;
			palabraDetectar[p]='\0';

			estado=4;
			i=i+1;
		}else{

			printf("\nIDENTIFICADOR");
			fprintf(archivoSalida, "%s\n","IDENTIFICADOR");
			estado=1;

			palabraDetectar[0]='\0';
			p=1;
			palabraDetectar[p]='\0';
		}



	}
	 


}



void analizar(FILE *archivoSalida){
	int i=0;
	int found;

	while(i<cantidadPalabrasValido){
		found=pertenece(arrayValido[i]);

		//si no esta en encontradpos 
		if (found!=-1){
			fprintf(archivoSalida, "%s\n",terminales[found]);
			i=i+1;
		}else{
			
			analizarPalabra(arrayValido[i],archivoSalida);
			//fprintf(archivoSalida, "%s\n","IDENTIFICADOR");
			i=i+1;
		}

		

	}



}



int main (int argc ,char* argv[]){



	//***************************************VALORES DE ENTRADA**************************************************
	//printf("\nEntrada %s",argv[1] );
	//printf("\nSalida: %s",argv[2] );
	//Se pasan los guardan los datos ingresados
	char* n_entrada=argv[1]; 
	char* n_salida=argv[2]; 
	char* n_otro=argv[3]; 
	
	if ( (n_entrada && n_salida && n_otro)){
		printf("\nMas parametros de los solicitados");
	}else{
		if (argv[1] && (argv[2])){
		printf("\nTodos los parametros");	
		//***********************************

		//Ver si los archivos son validos o no
		//archivo de entrada no existe 
		//archivo de salida ya 
		FILE *archivoEntrada;
		FILE *archivoSalida;

		archivoEntrada=fopen(n_entrada,"r");
		archivoSalida=fopen(n_salida,"r");

		if(archivoEntrada==NULL){
			printf("\nNo existe el archivo de entrada");
			return 0;
		}
		/*
		if(archivoSalida!=NULL){
			printf("\nArchivo de salida ya existe");
			return 0;
		}
		*/
		free(archivoEntrada);
		free(archivoSalida);
		//abrir como de escritura archivo de salida
		archivoSalida=fopen(n_salida,"w");
		free(archivoSalida);

		//-------------------------
		//Hacer las funciones principales
		//crea un archivo de salida con las palabras cortadas
		leer(archivoEntrada,archivoSalida);
		fclose(archivoSalida);

		//se abre el archivo con las palabras cortadas
		archivoSalida=fopen(n_salida,"r");
		//Crear el array con las palabras cortadas
		crearArrayNuevo(archivoSalida);
		fclose(archivoSalida);

		//se crea el array con las palabras originales 
		rewind(archivoEntrada);
		crearArrayViejo(archivoEntrada);
		fclose(archivoEntrada);

	

		printf("\nLargo Viejo: %d",cantidadPalabrasViejo);
		printf("\nLargo Nuevo: %d",cantidadPalabrasNuevo);

		

		//Separar las palabras que tenian espacios

		/*
		rewind(archivoEntrada);
		separarPalabras(archivoEntrada);
		fclose(archivoEntrada);
		*/ 



		//Determinar maxima y minima
		//Separa palabras que tenian caracteres invalidos
		archivoSalida=fopen(n_salida,"w");
		fixInvalidas(archivoSalida);
		fclose(archivoSalida);

		archivoSalida=fopen(n_salida,"r");
		crearArrayValido(archivoSalida);
		fclose(archivoSalida);

		
		
		archivoSalida=fopen(n_salida,"w");
		//analizarPalabra(arrayValido[2],archivoSalida);
		//analizarPalabra(arrayValido[6],archivoSalida);
		//analizarPalabra(arrayValido[17],archivoSalida);

		analizar(archivoSalida);
		fclose(archivoSalida);





		//---------------------
		//*******************************
	}else{
		if (argv[1] && !(argv[2])){
			printf("\nFalta 1 parametro");
		}else{
			printf("\nFaltan  parametros");
			
		}
	}
		
		
	}





	//****************************************************************************************************+


	return 0;
} 