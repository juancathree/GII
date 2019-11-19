# Seguridad en los sistemas operativos

## 1. Control de acceso al sistema

Los sistemas operativos suelen proporcionar un mecanismo de control del acceso de los usuarios. Este suele constar de dos
pasos:
- Identificación del usuario.
- Autenticación del usuario.

### 1.1 Metodos de autenticacion

Los métodos de autenticación se suelen dividir en tres grandes categorías:
- Algo que el usuario sabe.
- Algo que el usuario posee.
- Una característica física del usuario (autenticación biométrica).

### 1.2 Eleccion de contraseñas

- Deben ser lo más largas posible (mínimo 8 caracteres).
- Conviene combinar caracteres numéricos y alfanuméricos, letras mayúsculas, minúsculas y caracteres especiales ( %, $, &, . . . )
- Deben evitarse las palabras de cualquier idioma y los nombres propios.
- No deben utilizarse combinaciones simples de datos personales: iniciales del nombre, fecha de nacimiento, DNI, teléfono, matrícula del coche, etc.
- Utilizar contraseñas fáciles de recordar, para evitar tenerlas apuntadas.
- Son especialmente recomendables los acrónimos de frases que uno recuerde fácilmente.

### 1.3 Proteccion de las contraseñas

- **Precauciones por parte del usuario:**
  - No compartir nunca su contraseña.
  - Cambiarla cada cierto tiempo.
  - No escribir ni teclear su contraseña delante de otras personas.
  - No enviar la contraseña por correo electrónico.
  - Si la contraseña se guarda por escrito, hacerlo en un lugar de difícil acceso para otras personas y de forma que no
  pueda ser adivinada su función.
  
- **Precauciones por parte del administrador:**
  - No debe crear nunca cuentas sin contraseña.
  - Cambiar la contraseña después de instalar el sistema.
  - Proteger de forma adecuada el fichero del sistema donde se almacenan las contraseñas.
  - Vigilar las cuentas de los usuarios accidentales, ya que son las más propensas a la penetración por parte de intrusos.

- **Proteccion automatizada:**
  - Número limitado de intentos de acceso.
  - Control de calidad de las contraseñas.
  - Caducidad de contraseñas.
  - Generación automática de contraseñas.
  - Bloqueo de cuentas.
  - Registro de entradas.

- **Proteccion del fichero de contraseñas:**
  - Las contraseñas tienen que guardarse cifradas. El método criptográfico utilizado debe ser irreversible para que no sea posible descifrarlas.
  - El fichero que contiene las contraseñas no debería ser visible a los usuarios.
  
### 1.4 Contraseñas en UNIX/Linux

Las contraseñas se guardaban cifradas en el fichero **`/etc/passwd`** (lectura pública).  

Formato del fichero: **`login:passwd:UID:GID:varios:dir-entrada:shell`**  

Problemas: Se podían adivinar contraseñas comparando palabras de un diccionario cifradas con las almacenadas en
el fichero /etc/passwd.

Para mejorar la seguridad el fichero **`etc/passwd`** no contiene la contraseña codificada, si no que se encuentra en
**`etc/shadow`** que no es de lectura publica.

### 1.5 Sistemas de autenticacion biometrica

Pueden utilizar cualquier característica única y mensurable del individuo. Se han utilizado:
- Iris del ojo.
- Retina del ojo.
- Huellas dactilares.
- Geometría de la mano.
- Firma.
- Voz.

Este sistema tiene unas determinadas **fases:**
- Captura o lectura de los datos que el usuario presenta para su validación.
- Extracción de ciertas características de la muestra.
- Comparación de tales características con las guardadas en una base de datos.
- Decisión de si el usuario es válido o no.

Este sistema puede tener dos principales fallos:
- **Tasa de falso rechazo:** Probabilidad de que el sistema de autenticación rechace a un usuario legítimo.
- **Tasa de falsa aceptación:** Probabilidad de que el sistema autentique correctamente a un usuario ilegítimo.

## 2. Control de acceso a los datos

### 2.1 Elementos basicos

- **Sujeto:** Es una entidad capaz de acceder a los objetos. En general, podemos equiparar el concepto de sujeto
con el de proceso.
- **Objeto:** Cualquier recurso cuyo acceso deba controlarse, por ejemplo, ficheros, partes de ficheros, segmentos
de memoria, etc.
- **Derecho de acceso:** La forma en que un sujeto accede a un objeto, por ejemplo, lectura, escritura y ejecución.

### 2.2 Listas de control de acceso

Existe una por cada objeto del sistema y enumera los usuarios y los derechos de acceso de éstos al objeto

### 2.3 Listas de capacidades

Hay una por cada sujeto y enumera los derechos de acceso de éste a los objetos del sistema.


### 2.4 Control por niveles de seguridad

Es apropiado para organizaciones que tienen requisitos elevados de seguridad y los usuarios operan de modo
jerárquico y disciplinado (organizaciones militares, agencias de inteligencia, empresas con altos requisitos de seguridad).

Cada sujeto y objeto tiene asociada una etiqueta. La etiqueta consta de dos partes: Clasificación y un
conjunto de Categorías. Ejemplo de etiqueta: **`Secreto [Armas-Químicas Oriente-Medio]`**

#### 2.4.1 Tipos de acceso

- **Acceso discrecional:** Deja en manos de los usuarios la decisión de qué tipos de acceso permite para los ficheros
que posee.
- **Acceso obligatorio:** Es el sistema el que toma todas las decisiones sobre el acceso a los datos basándose
en unas reglas fijas y en un esquema de clasificación que establece los niveles de seguridad de los distintos sujetos 
y objetos que comparten el sistema. Esta política puede ser implementada por medio del denominado control por 
niveles de seguridad.

#### 2.4.2 Niveles

**Niveles de seguridad en entorno militar:**
1. Alto secreto
2. Secreto
3. Confidencial
4. No clasificado

**Niveles de seguridad en entorno empresarial:**
1. Propietario
2. Directivo
3. Jefe de Departamento
4. Empleado
5. Público

#### 2.4.3 Reglas

**Regla de lectura:** Para leer un objeto, el nivel de seguridad del sujeto debe ser igual o superior al del objeto 
y además, el conjunto de categorías del sujeto debe incluir todas las del objeto.

**Regla de escritura:** Para poder escribir en un objeto, el nivel de seguridad del objeto debe ser igual o superior 
al del sujeto y además, el conjunto de categorías del sujeto deben estar incluidas en las del objeto.


## 3. Copias de seguridad

### 3.1 Casos en que son necesarias

- Un usuario o un administrador ha borrado de forma no intencionada alguna información que era importante.
- Un intruso ha borrado información importante.
- Fallo de hardware.
- Un robo.
- Desastres naturales: inundación, incendio. . .

### 3.2 ¿Que debemos copiar?

- **Copia completa:** copiamos todos los ficheros del sistema.
  - **`Ventajas:`** La recuperación del sistema, en caso de tener que recuperarlo completo, es más sencilla.
  - **`Inconvenientes:`** Consume más recursos (soporte y tiempo).

- **Copia parcial:** Copiamos aquello que sea especíco de nuestro sistema: cheros de usuarios, ficheros de 
configuración. . .
  - **`Ventajas:`** consume menos recursos
  - **`Inconvenientes:`** Si hay que recuperar todo el sistema, tendremos que empezar instalando el SO, todo el 
  software adicional instalado (más parches. . . ) y, por último, la copia de seguridad.

### 3.3 Tipos

- **Completas:** copia todos los ficheros de interes
- **Progresivas:** Solo se copian aquellos cheros que han sido creados o modificados desde la última copia 
completa o progresiva efectuada.
- **Diferenciales:** Solo se copian los cheros que han sido creados o modificados desde la última copia completa 
realizada.

## 4. Auditorias

Consiste en la monitorización del funcionamiento del sistema de forma automatizada y sistemática mediante el 
registro de los sucesos clave que se producen en este.

### 4.1 Objetivos

- Revisar accesos por usuarios a los objetos del sistema.
- Revisar la efectividad de los mecanismos de seguridad del sistema.
- Descubrir intentos de saltarse los mecanismos de seguridad.
- Descubrir usuarios con privilegios excesivos.
- Servir de elemento disuasor para los atacantes.
- Ayudar a la recuperación de desastres informáticos.
- Proporcionar pruebas materiales de los ataques.

### 4.2 Conceptos basicos

- **Evento auditable:** Acciones que queremos que queden registradas en el sistema de auditoría.
- **Informacion auditable:** Datos relacionados con el evento auditable que pueden ser útiles.

### 4.3 Mecanismos para la deteccion de ataques

**Perfil de usuario**
- Recoge las acciones que cada usuario realiza normalmente en el sistema.
- Si un intruso utiliza la cuenta de un usuario se puede detectar debido a que se aparta del perfil del usuario.
- Puede avisar de acciones legales que se aparten del perfil

**Perfil de intruso** Los intrusos suelen actuar de una forma similar cuando entran en un sistema ajeno: mirar 
quién está conectado al sistema, examinar el sistema de cheros, moverse por losdirectorios tratando de obtener 
información, no suelen estar conectado mucho tiempo.

Acciones puntuales que denuncian la presencia de un ataque o intento de ataque:
- Intento de acceso a la administración del sistema.
- Intento de explotación de agujeros de seguridad conocidos.
- Uso de herramientas que detectan agujeros de seguridad.
- Uso de órdenes de otros sistemas operativos.





