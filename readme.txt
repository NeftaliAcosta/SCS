Autor: 	Neftali Acosta
	hola@neftaliacosta.com
	www.neftaliacosta.com
	+52 2291391667
-----------------------------------------


Problem�tica: 
	Se busca crear un peque�o software a la medida que sea cap�s de controlar las peticiones diarias de soporte de una empresa. La empresa cuenta con diferentes canales de soporte y se desea obtener estad�sticas diarias, semanales, mensuales y anuales de cada una de las peticiones por los canales. Adicionalmente la empresa puede desactivar o agregar canales alternos para contingencias por lo tanto, el sistema debe de tener la capacidad de agregar m�s canales si as� se desea. Todos los reportes que se exporten deben de leer la configuraci�n actual de los canales de soporte, exportando solo los activos y los que se agregaron posteriormente.


Re querimientos: 
	* El sistema debe contar con una configuraci�n al servidor de base de datos.
	* El sistema debe contar con dos men�es. El principal y el de configuraci�n del sistema.
	* El sistema debe de detectar que la configuraci�n de a la base de dtos sea la correcta �ntes de inicializar, si no es correcta salir del sistema.
	


Versiones:
	Versi�n 1.0. Se crea el men� y se guarda la informaci�n temporal en matrices y arreglos
	[PENDEINTE]Versi�n 1.2. Se Agregan clumnas a las matrices para almacenar informaci�n extendida.
	[PENDEINTE]Versi�n 1.3. Se cambia la forma de almacenar la informaci�n, se hace uso de estructuras.
	[PENDEINTE]Versi�n 1.4. Se modifica parte del c�digo para utilizar conexi�n a base de datos.
	[PENDEINTE]Versi�n 1.4.2 Se crea una opci�n para ver los detalles de conexion a la BD.
	[PENDEINTE]Versi�n 1.4.2.2 Se Mejora los detalles de conexi�n. Se hace uso de banderas para mostrar error de conexion al inicio del programa y 	detalles de conexi�n en caso de que sean verdaderos.
	[PENDEINTE]Versi�n 1.5. Se modifica el c�digo y se divide en funciones.
	[PENDEINTE]Versi�n 1.6. Se agregan diferentes m�todos para imprimir reportes. Por rango de fecha, por canal de soporte, por sistema, o completo.
	[PENDEINTE]Versi�n 1.7. En las consultas se utilizar� un JOIN para imprimir las base de datos relaciones con sus nombres y no por ID.
	[PENDEINTE]Versi�n 1.8. Se busca agregar una opci�n de configuraci�n de conexi�n a la base de datos desde el programa, sin neceisdad de modificar el 	c�digo.
	[PENDEINTE]Versi�n 2.0 Guardar los reportes en un archivo TXT.