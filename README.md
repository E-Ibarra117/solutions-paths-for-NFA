bruh
|                       |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| :-------------------- | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Actores participantes | Iniciado por OperadorCM.<br>Secomunica con EnlaceDatos.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
| Flujo de eventos      | 1.  OperdarorMC activa la funcion de . <br>&emsp;	 2. El sistema extrae la informacion de configuracion correspondiente a la conexion inicializada.<br>	 3. El sitema utiliza la informacion extraida para seleccionar las funciones y herramientas adecuadas para establecer la conexion.<br>	 4. Se envia un mensaje de reconocimiento y espera a la respuesta por el puerto establecido en la configuracion.<br>	 5. Recibe el paquete de reconocimiento del EnalceDatos y establece el puente de datos.<br>	 6. El sistema intercambia paquetes con EnlaceDatos mediante el puente.<br>7. El OperadorCM  termina la conexion.<br>Condición de entrada:  |
|                       |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
|                       |                                                                                                                                                                                                                                                                                                                                                                                                                                                              |

## visualizarDatos
### Actores participantes: 
Iniciado por OperadorCM
comunicacion con EnlaceDatos

### Flujo de eventos: 
1. OperadorCM selecciona la UI de visualizcion.

3. El sistema lee el paquete de telemetria enviado por EnlaceDatos.

5. Extrae los datos de telemetria y lo estructura en el formato correcto para la visualizacion.

7. Actualiza los elementos del UI.

1. Utiliza los datos necesarios para actualizar el mapa.

### Condición de entrada: 
VA sincronizado

### Condiciones de salida: 
el OperadorCM cambia de UI

### Requerimientos de calidad:
lol
