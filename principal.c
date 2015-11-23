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
int ver = 1;


int main(int argc, char *argv[]) {
	int conex; /*file bandera para saber si el archivo se creó*/
	
	SetConsoleTitle("Version: 1");
	system("pause");

}




