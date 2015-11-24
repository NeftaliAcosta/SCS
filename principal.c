 /*
Versión 0.1
Autor: NEFTALI MARCIANO ACOSTA
Universidad Abierta y a Distancia de México
Materia:Fundamentos de programación
Faclitiadora: Vanessa Avendaño Trejo
ES1421008504@unadmexico.mx
Fecha de cración: 14/Agost/15
Ultima Actualización 25/09/15

====CONTROLADOR DE VERSIONES====
Versión 0.1
============DESCRIPCION=========
Función validadora de la conexión de la base de datos. En caso de no existir configuración
establecerla en ese momento y gudarlar en bloc de notas.

Una vez guardada la configuración, leer la configuración, establer conxión y abrir el menú principal.

*/

/*=========LIBRERÍAS NECESARIAS=========*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <mysql.h>
#include <windows.h>


/*=========VARIABLES GLOBALES=========*/
MYSQL *conn, mysql;
MYSQL_RES *res;
MYSQL_ROW row;
char *server;
char *user;
char *password;
char *database;
char a[20]="";
char b[20]="";
char c[20]="";
char d[20]="";
char consulta0[1024];
int contador;
int canal;



int main(int argc, char *argv[]) {
	int conex; /*file bandera para saber si el archivo se creó*/
	
	SetConsoleTitle("Version: 1");
	conex=loadfile(conex);  /*Se dectecta si el archivo config existe al iniciar el programa*/
	if (conex==0){ /*Valido si la conexión fue exitosa, si no es exitosa salgo del programa*/
		goto exit;
	}
	
	system("cls");
	menu();
	
	exit:
		printf("\nSaliendo del Sistema...");
		Sleep(2000);

}


int loadfile(int conex){
	FILE *fp;
	char crear;
	char resp;
	int con;

	 fp = fopen ("config.txt", "r");
	  if (fp==NULL){
	  	
	  	do{
		  system("cls");
	  	printf("============ERROR============\n");
   			printf("El archivo de configuracin no existe \nDesea crearlo?\n");
   			printf("A=Crear archivo \t B.Salir");
   			printf("\nEsperando opcion: >");
   			resp=getche();
  	
   			switch(resp){
   				case 'a':
				   		conex=newfile(con); /*Si el archivo no existe se  manda a crear*/
				   		resp='b';
				   		break;
				case 'b':
					 	resp='b';
						break;
				default:   	
						printf("\nOpcion Invalida\n");
						break;
   				
			   }

		  }while(resp!='b');
	  		
	  			}
				  else{ 
   					printf("\nArchivo config encontrado\n");
   					Sleep(100);
   					conex=readfile(con);  /*Si el archivo existe lee la configuración*/
   					
   					}

		 Sleep(100);
			return conex;
}




int testconex(int con){
	
	conn = mysql_init(NULL);
	if (!mysql_real_connect(conn,server,user,password,database,0,NULL,0)){
		
		/*fprintf(stderr,"\n%s\n",mysql_error(conn));*/
		printf("\n La conexion al servidor fallo :( ...\n");
		con=0;
		Sleep(100);
	}
	else{
		printf("\nConexion establecida D: ... \n");
		con=1;
		Sleep(100);
	} 		
 	
	 return con;
}

/*LEE LA CONFIGURACION DE CONEXION A LA BD*/
int readfile(int con){
	 
	 FILE *fp;
	 char caracteres[20];
	 int i,x;
	
	 fp = fopen ("config.txt", "r");
	 
	 if (fp == NULL)
 		exit(1);
 	x=0;
 	 printf("\nleyendo configuracion...\n");
 	 Sleep(100);
	 while (feof(fp) == 0)
	    {
		fgets(caracteres,20,fp);
		/*printf("%c",caracter);*/
		 i=0;
		 
		    if (x==0){
			while(caracteres[i]!='\n'){
		  			a[i]=caracteres[i];
		  			i++;
		  }
			}
			
			
			
			if (x==1){
			while(caracteres[i]!='\n'){
		  			b[i]=caracteres[i];
		  			i++;
		  }
			}
			
			if (x==2){
			while(caracteres[i]!='\n'){
		  			c[i]=caracteres[i];
		  			i++;
		  }
			}
			
			
			if (x==3){
			while(caracteres[i]!='\n'){
		  			d[i]=caracteres[i];
		  			i++;
		  }
			}
			
		i=0;
		x++;	
	    }
	    
	 printf("\nIntentando conexion con el seridor...\n");
 	 Sleep(1000);
 	 server = a;
     user = b;
     password= c;
     database= d;
     
	 con=testconex(con);	
	 return con;	
}


/*CREA ARCHIVO DE CONFIGURACION A LA BD*/
int newfile(int con){
	
int cone;
	  FILE *fp;
	  system("cls");
	  printf("\nCreando configuracion del Servidor\n");
	  Sleep(1000);
	  printf("\nIngrese la ip del servidor: ");
	  scanf("%s", &a);
	  printf("\nIngrese el nombre de usuario: ");
	  scanf("%s", &b);
	  printf("\nIngrese el password: ");
	  scanf("%s", &c);
	  printf("\nIngrese el nombre de la BD: ");
	  scanf("%s", &d);

  	  fp = fopen ("config.txt", "w");
  	
   	  fprintf(fp, "%s\n%s\n%s\n%s\n",a,b,c,d);
	  fclose(fp);
	  printf("\n El archivo se creo correctamente...\n");
	  Sleep(1000);
	
     server = a;
     user = b;
     password= c;
     database= d;
     	  
		con=testconex(con);
 	
 	return con;
}


menu(int conex){ /*Inicio del nenú*/

 char resp;
 int consul;
 int con;
	

	
	/*ESTADISTICAS DEL SISTEMA*/

	do{
	system("cls");
	
	printf("\t\t-----------MENU------------\n\n");

	printf("\t\t---------------------------\n");
	printf("\t\t a. Ingresar Registro	\n\t\t b. Registros \n\t\t c. Estadisticas \n\t\t d. Configuracion \n\t\t x. Salir");
	printf("\n\t\t Esperando respuesta->");
	resp=getche();
	
	switch(resp){
		case 'a':
				system("cls");
			/*	alta();*/
				system("pause");
				break;
				
		case 'b':
				system("cls");
						
				/*consulta();*/
				system("pause");
				break;
		
		case 'c':			
				system("cls");
				
			/*	registros();*/
				system("pause");
				break;
				
		case 'd':
				system("cls");	
				conex=newfile(con); /*Sobre escribe el archivo config y leeo la conexion*/
		
				if (conex==0){ /*Valido si la conexión fue exitosa, si no es exitosa salgo del programa*/
					resp='x';
				}
				system("pause");
				break;
				
		case 'x':
				system("cls");
				break;	
					
				
		default:
				system("cls");
				printf("\n Opcipon Incorrecta\n");
				system("pause");
				break;			
	}
	
	}while(resp!='x');
} /*Fin del menú*/

