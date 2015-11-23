Autor: 	Neftali Acosta
	hola@neftaliacosta.com
	www.neftaliacosta.com
	+52 2291391667
-----------------------------------------


Problemática: 
	Se busca crear un pequeño software a la medida que sea capás de controlar las peticiones diarias de soporte de una empresa. La empresa cuenta con diferentes canales de soporte y se desea obtener estadísticas diarias, semanales, mensuales y anuales de cada una de las peticiones por los canales. Adicionalmente la empresa puede desactivar o agregar canales alternos para contingencias por lo tanto, el sistema debe de tener la capacidad de agregar más canales si así se desea. Todos los reportes que se exporten deben de leer la configuración actual de los canales de soporte, exportando solo los activos y los que se agregaron posteriormente.


Re querimientos: 
	* El sistema debe contar con una configuración al servidor de base de datos.
	* El sistema debe contar con dos menúes. El principal y el de configuración del sistema.
	* El sistema debe de detectar que la configuración de a la base de dtos sea la correcta ántes de inicializar, si no es correcta salir del sistema.
	


Versiones:
	Versión 1.0. Se crea el menú y se guarda la información temporal en matrices y arreglos
	[PENDEINTE]Versión 1.2. Se Agregan clumnas a las matrices para almacenar información extendida.
	[PENDEINTE]Versión 1.3. Se cambia la forma de almacenar la información, se hace uso de estructuras.
	[PENDEINTE]Versión 1.4. Se modifica parte del código para utilizar conexión a base de datos.
	[PENDEINTE]Versión 1.4.2 Se crea una opción para ver los detalles de conexion a la BD.
	[PENDEINTE]Versión 1.4.2.2 Se Mejora los detalles de conexión. Se hace uso de banderas para mostrar error de conexion al inicio del programa y 	detalles de conexión en caso de que sean verdaderos.
	[PENDEINTE]Versión 1.5. Se modifica el código y se divide en funciones.
	[PENDEINTE]Versión 1.6. Se agregan diferentes métodos para imprimir reportes. Por rango de fecha, por canal de soporte, por sistema, o completo.
	[PENDEINTE]Versión 1.7. En las consultas se utilizará un JOIN para imprimir las base de datos relaciones con sus nombres y no por ID.
	[PENDEINTE]Versión 1.8. Se busca agregar una opción de configuración de conexión a la base de datos desde el programa, sin neceisdad de modificar el 	código.
	[PENDEINTE]Versión 2.0 Guardar los reportes en un archivo TXT.