 /*
Versi�n 0.1
Autor: NEFTALI MARCIANO ACOSTA
Universidad Abierta y a Distancia de M�xico
Materia:Fundamentos de programaci�n
Faclitiadora: Vanessa Avenda�o Trejo
ES1421008504@unadmexico.mx
Fecha de craci�n: 14/Agost/15
Ultima Actualizaci�n 25/09/15

====CONTROLADOR DE VERSIONES====
Versi�n 0.1
============DESCRIPCION=========
Funci�n validadora de la conexi�n de la base de datos. En caso de no existir configuraci�n
establecerla en ese momento y gudarlar en bloc de notas.

Una vez guardada la configuraci�n, leer la configuraci�n, establer conxi�n y abrir el men� principal.

*/

/*=========LIBRER�AS NECESARIAS=========*/
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
int ver = 1;


int main(int argc, char *argv[]) {
	int conex; /*file bandera para saber si el archivo se cre�*/
	
	SetConsoleTitle("Version: 1");
	system("pause");

}




