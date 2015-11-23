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


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <mysql.h>
#include <windows.h>

#Define VER SCS v. 0.1 (Sistema Control de Soporte )
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
	
	SetConsoleTitle("");
	conex=loadfile(conex);  /*Se dectecta si el archivo config existe al iniciar el programa*/
	if (conex==0){ /*Valido si la conexión fue exitosa, si no es exitosa salgo del programa*/
		goto exit;
	}
	

	system("cls");
	menu();
		
	



	exit:
		printf("\nSaliendo del Sistema...");
		Sleep(2000);
	
	
	mysql_close(conn); /*Cierro la conecion a la base de datos*/
}/*End main*/







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
	    
	    

	    
	 printf("\nEstableciendo conexion con el server...\n");
 	 Sleep(1000);
 	 server = a;
     user = b;
     password= c;
     database= d;
     
	 conn = mysql_init(NULL);
	 
	if (!mysql_real_connect(conn,server,user,password,database,0,NULL,0)){
		
		fprintf(stderr,"\n%s\n",mysql_error(conn));
		con=0;
		Sleep(100);
	}
	else{
		printf("\nConexion establecida...\n");
		con=1;
		Sleep(100);
	} 		
 		
 	
	 	
	 return con;	
}


/*CREA ARCHIVO DE CONFIGURACION A LA BD*/
int newfile(int con){
	

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
	  		 printf("\n El archivo se creo correctamente\n");
	  		 Sleep(1000);
		   
	  	 
	
     server = a;
     user = b;
     password= c;
     database= d;
     
    /* printf("\n%s\n",server);
     printf("\n%s\n",user);
     printf("\n%s\n",password);
     printf("\n%s\n",database);
	  system("pause");
	  */
	  
	  
	  	 conn = mysql_init(NULL);
	 
	if (!mysql_real_connect(conn,server,user,password,database,0,NULL,0)){
		
		fprintf(stderr,"\n%s\n",mysql_error(conn));
		con=0;
		system("pause");
	}
	else{
		printf("\nConexion establecida...\n");
		con=1;
		Sleep(400);
	} 		
 	
 	return con;
}

/*MENU PRINCIPAL DEL SISTEMA*/
menu(){
	char resp;
	int consul;
	

	
	/*ESTADISTICAS DEL SISTEMA*/

	do{
	system("cls");
	
	printf("\t\t-----------MENU------------\n\n");

	printf("\t\t---------------------------\n");
	printf("\t\t a. Ingresar Registro	\n\t\t b. Registros \n\t\t c. Estadisticas \n\t\t x. Salir");
	printf("\n\t\t Esperando respuesta->");
	resp=getche();
	
	switch(resp){
		case 'a':
				system("cls");
				alta();
				system("pause");
				break;
				
		case 'b':
				system("cls");
						
				consulta();
				system("pause");
				break;
		
		case 'c':			
				system("cls");
				
				registros();
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
	
}/*Fin Menú*/

registros(){	
	conn = mysql_init(NULL);
	if (!mysql_real_connect(conn,server,user,password,database,0,NULL,0)){
		
		fprintf(stderr,"%s\n",mysql_error(conn));
		
		return 1;		
	}else{
		printf("\n\t ---ESTADISTICAS DEL SISTEMA---");
		printf("\n\t --consultas realizadas por canal--");
		sprintf(consulta0,"select * from ticket where idCanal=1;");
		if(mysql_query(conn,consulta0)==0){
			res=mysql_use_result(conn);
			canal=0;
			while((row=mysql_fetch_row(res)))
			{	
			 canal++;
			}
				printf("\nTelefono: %i\n",canal);
		}
	}
	
	
	
	
	/*segunda consulta DE CORREO*/
		sprintf(consulta0,"select * from ticket where idCanal=2;");
		if(mysql_query(conn,consulta0)==0){
			res=mysql_use_result(conn);
			canal=0;
			while((row=mysql_fetch_row(res)))
			{	
			 canal++;
			}
				printf("\nCorreo: %i\n",canal);
		}
		
			/*segunda consulta DE WHATSAPP*/
		sprintf(consulta0,"select * from ticket where idCanal=3;");
		if(mysql_query(conn,consulta0)==0){
			res=mysql_use_result(conn);
			canal=0;
			while((row=mysql_fetch_row(res)))
			{	
			 canal++;
			}
				printf("\nWhatsapp: %i\n",canal);
		}
		
		/*segunda consulta DE Livezilla*/
		sprintf(consulta0,"select * from ticket where idCanal=4;");
		if(mysql_query(conn,consulta0)==0){
			res=mysql_use_result(conn);
			canal=0;
			while((row=mysql_fetch_row(res)))
			{	
			 canal++;
			}
				printf("\nLivezilla: %i\n",canal);
		}
		/*segunda consulta DE ALU*/
		sprintf(consulta0,"select * from ticket where idCanal=5;");
		if(mysql_query(conn,consulta0)==0){
			res=mysql_use_result(conn);
			canal=0;
			while((row=mysql_fetch_row(res)))
			{	
			 canal++;
			}
				printf("\nAlu: %i\n",canal);
		}
		
		/*segunda consulta DE SKYPE*/
		sprintf(consulta0,"select * from ticket where idCanal=5;");
		if(mysql_query(conn,consulta0)==0){
			res=mysql_use_result(conn);
			canal=0;
			while((row=mysql_fetch_row(res)))
			{	
			 canal++;
			}
				printf("\nSkype: %i\n\n",canal);
		}
		

	
	
	
}

consulta(){
	
	conn = mysql_init(NULL);

	
	 if (!mysql_real_connect(conn,server,user,password,database,0,NULL,0)){
		
		fprintf(stderr,"%s\n",mysql_error(conn));
		
		return 1;		
	}else{
	
	  sprintf(consulta0,"select idTicket as 'Ticket',p.tNombre as 'Cliente',(select pp.tNombre from personas as pp where pp.idPersonas = t.idSoporte) as 'Agente',s.tNombre as 'Sistema', c.sNombre as 'Canal', t.dFecha as 'Fecha',tObservaciones as 'Notas' from	ticket as t inner join personas as p on t.idCliente = p.idPersonas inner join software as s on t.idSoftware = s.idSoftware inner join canales as c on t.idCanal = c.idCanales where t.bStatus = 1 order by Ticket;");
		if(mysql_query(conn,consulta0)==0){
			res=mysql_use_result(conn);
			 
			printf("\n  ID \tCliente \tAgente  \tSistema \tCanal \n");
			contador=0;
			while((row=mysql_fetch_row(res)))
			{
				printf("  %s",row[0]);
				printf("  \t%s",row[1]);
				printf("  \t%s",row[2]);
				printf("  \t%s",row[3]);
				printf("  \t%s",row[4]);
				printf("\n");
				contador++;
			
			}
				printf("\nTotal de registros %i\n\n",contador);
		}
		
			
	}
	
	mysql_close(conn);
	
}



alta(){
		
	conn = mysql_init(NULL);

	int iteracion;
	int inicio=1;
	char consulta[1024];
	struct ticket
  {
      int idCliente;
      int idSoporte;
      int idSistema;
      int idCanal;
      char sfecha[10];
      int iStatus;
      char tObservaciones[200];
      
  } persona;
  
  
  printf("Cliente de Cliente= 17  Cliente EFH=18");
  printf("\nIngrese el ID del Cliente: ");
  scanf("%d",&persona.idCliente);
  system("cls");
  printf("\nGilberto= 7 | Neftali= 14");
  printf("\nIngrese el ID del Agente de Soporte");
  scanf("%d",&persona.idSoporte);
  system("cls");
  printf("\nPsicosof:1 LPC:2 psicoweb:3 MEOL:4 ");
  printf("\nIngrese el ID del Sistema de Soporte ");
  scanf("%d",&persona.idSistema);
  system("cls");
  printf("\nTelefono:1 Correo:2 Whatsapp:3 Livezilla:4 ALU:5 Skype:6");
  printf("\nIngrese el ID del Canal Solicitado");
  scanf("%d",&persona.idCanal);
  system("cls");
  printf("\n 15/02/25");
  printf("\nIngrese la Fecha del soporte");
  scanf("%s",&persona.sfecha);
  /*system("cls");
  printf("\nAgrege un comentario");
  scanf("%s", persona.tObservaciones);*/
  
  
  persona.iStatus=1;
  
   if (!mysql_real_connect(conn,server,user,password,database,0,NULL,0)){
		
		fprintf(stderr,"%s\n",mysql_error(conn));
		return 1;	
		
	}
 
	printf("\n NUMERO DE VECES QUE SE REPITE ESTA ITERACION (0= 1 VEZ): "); 
	scanf("%i",&iteracion);
	if (iteracion==0){
		iteracion=1;
	}
  		
  		for(inicio=1;inicio<=iteracion;inicio++){
  			
  			 
			
		sprintf(consulta,"insert into ticket (idCliente,idSoporte, idSoftware,idCanal,dFecha,bStatus,tObservaciones) values ('%i','%i','%i','%i','%s','%i','Comentario de prueba')",persona.idCliente,persona.idSoporte,persona.idSistema,persona.idCanal, persona.sfecha, persona.iStatus);
   if(mysql_query(conn,consulta)==0){
   	system("cls");
   		fprintf(stdout,"\n Datos insertados correctamente \n");
   		
   }
   else{printf("\n Error al insertar los datos\n");
   }
	
		

  			
		  }
  		
	  	persona.idCliente=0;
      	persona.idSoporte=0;
      	persona.idSistema=0;
        persona.idCanal=0;
      	persona.iStatus=0;
	  
	  
	 
}/*End Alta*/

