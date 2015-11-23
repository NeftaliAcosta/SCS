/*
Versión 1.4.2.2
Autor: NEFTALI MARCIANO ACOSTA
Universidad Abierta y a Distancia de México
Materia:Fundamentos de programación
Faclitiadora: Vanessa Avendaño Trejo
ES1421008504@unadmexico.mx
Fecha de cración: 14/Agost/15
Ultima Actualización 25/09/15

====CONTROLADOR DE VERSIONES====
Versión 1.0. Se crea el menú y se guarda la información temporal en matrices y arreglos
Versión 1.2. Se Agregan clumnas a las matrices para almacenar información extendida.
Versión 1.3. Se cambia la forma de almacenar la información, se hace uso de estructuras.
Versión 1.4. Se modifica parte del código para utilizar conexión a base de datos.
Versión 1.4.2 Se crea una opción para ver los detalles de conexion a la BD.
Versión 1.4.2.2 Se Mejora los detalles de conexión. Se hace uso de banderas para mostrar error de conexion al inicio del programa y detalles de conexión en caso de que sean verdaderos.
[EN MARCHA]Versión 1.5. Se modifica el código y se divide en funciones.
[PENDIENTE]Versión 1.6. Se agregan diferentes métodos para imprimir reportes. Por rango de fecha, por canal de soporte, por sistema, o completo.
[PENDIENTE]Versión 1.7. En las consultas se utilizará un JOIN para imprimir las base de datos relaciones con sus nombres y no por ID.
[PENDIENTE]Versión 1.8. Se busca agregar una opción de configuración de conexión a la base de datos desde el programa, sin neceisdad de modificar el código.

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <mysql.h>
#include <windows.h>


	
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int consul;
	SetConsoleTitle("SCS v. 1.4.2.2 (Sistema Control de Soporte )");
	
	consul=0;
	bd(consul);
	system("cls");
	menu();

	
	
}/*End main*/

menu(){
	char resp;
	int consul;
	
	do{
	system("cls");
	printf("\t\t---------------------------\n");
	printf("\t\t a. Ingresar Registro	\n\t\t b. Imprimir Reporte \n\t\t c. Configuracion \n\t\t x. Salir");
	printf("\n\t\t Esperando respuesta->");
	resp=getche();
	
	switch(resp){
		case 'a':
				system("cls");
				alta();
				printf("\nAgregando registro\n");
				system("pause");
				break;
				
		case 'b':
				system("cls");
						
				consulta();
				system("pause");
				break;
		
		case 'c':			
				system("cls");
				consul=1;
				bd(consul);
				if (consul==0){
					system("pause");
				}
				
				break;
				
		case 'x':
				system("cls");
				printf("\nSaliendo...\n");
				system("pause");
				break;			
				
		default:
				system("cls");
				printf("\n Opcipon Incorrecta\n");
				system("pause");
				break;			
	}
	
	}while(resp!='x');
	
}/*Fin Menú*/



bd(int consul){
	MYSQL *conn, mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	
	char *server = "127.0.0.1";
	char *user = "root";
	char *password = "";
	char *database = "soporte";
	
	conn = mysql_init(NULL);
	
	if (!mysql_real_connect(conn,server,user,password,database,0,NULL,0)){
		
		fprintf(stderr,"%s\n",mysql_error(conn));
		system("pause");
		
		
		
		
		
		
		consul=0;
	} 
	if (consul==1){
	
		printf("\n servidor : %s", server);
		printf("\n Usuario: %s", user);
		printf("\n Password: %s", password);
		printf("\n Base de datos: %s\n", database);
		system("pause");
	}

	
	return consul;	
}



consulta(){
	
	MYSQL *conn, mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;

	
	char *server = "127.0.0.1";
	char *user = "root";
	char *password = "";
	char *database = "soporte";
	char consulta0[1024];
	conn = mysql_init(NULL);
	
	 if (!mysql_real_connect(conn,server,user,password,database,0,NULL,0)){
		
		fprintf(stderr,"%s\n",mysql_error(conn));
		
		return 1;		
	}else{
	
	  sprintf(consulta0,"SElECT * FROM ticket");
		if(mysql_query(conn,consulta0)==0){
			res=mysql_use_result(conn);
			printf("\n ID Ticket idCliente idSistema idCanal Fecha Observaciones \n");
			while((row=mysql_fetch_row(res)))
			{
				printf("| %s \t |",row[0]);
				printf("%s \t |",row[1]);
				printf("%s \t |",row[2]);
				printf("%s \t |",row[3]);
				printf("%s \t |",row[4]);
				printf("%s \t |",row[5]);
				printf("%s \t |\n",row[6]);
				
			}
		}
	}
	
	mysql_close(conn);
	
}







alta(){
	

	
	MYSQL *conn, mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;

	
	char *server = "localhost";
	char *user = "root";
	char *password = "";
	char *database = "soporte";
	
	conn = mysql_init(NULL);

	
	char consulta[1024];
	struct ticket
  {
      int idCliente;
      int idSoporte;
      int idSistema;
      int idCanal;
      char sfecha[10];
      int iStatus;
      
  } persona;
  
  printf("Ingrese el ID del Cliente");
  scanf("%d",&persona.idCliente);
  printf("Ingrese el ID del Agente de Soporte");
  scanf("%d",&persona.idSoporte);
  printf("Ingrese el ID dei Sistema de Soporte ");
  scanf("%d",&persona.idSistema);
  printf("Ingrese el ID del Canal Solicitado");
  scanf("%d",&persona.idCanal);
  printf("Ingrese la Fecha del soporte");
  scanf("%s",&persona.sfecha);
  
  
  persona.iStatus=1;
  
  /*insert into ticket (idCliente,idSoporte, idSoftware,idCanal,dFecha,bStatus,tObservaciones) values (2,7,1,1,'14-02-25',1,"Observaciones")*/

  
  if (!mysql_real_connect(conn,server,user,password,database,0,NULL,0)){
		
		fprintf(stderr,"%s\n",mysql_error(conn));
		return 1;	
		
	}else{
		printf("\n Coneccion establecida a la base de datos\n");
		/*system("pause");*/
		/*mysql_close(conn);*/
		/*rewind(stdin);*/	
		
		/*sprintf(consulta,"INSERT INTO ticket VALUES('%i', '%i', '%i', '%i','%s', '%i', '%s')", persona.idCliente, persona.idSoporte, persona.idCanal, persona.sfecha, persona.iStatus, persona.sObservaciones);*/
		sprintf(consulta,"insert into ticket (idCliente,idSoporte, idSoftware,idCanal,dFecha,bStatus,tObservaciones) values ('%i','%i','%i','%i','%s','%i','Observacion de ejemplo')",persona.idCliente,persona.idSoporte,persona.idSistema,persona.idCanal, persona.sfecha, persona.iStatus);
 		
   if(mysql_query(conn,consulta)==0){
   		fprintf(stdout,"\n Datos insertados correctamente \n");
   }
   
		return 1;
		
	}
  	mysql_close(conn);
}/*End Alta*/

