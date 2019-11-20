# Notificacion y gestion de ciberincidentes

## Metodologia de notificacion y seguimiento

### Organismos de referencia

El Gobierno de España atribuye las competencias en materia de ciberseguridad a diversos organismos:
- CCN-CERT: Centro Criptológico Nacional del Centro Nacional de Inteligencia.
- INCIBE-CERT: Instituto Nacional de Ciberseguridad de España.
- CNPIC: Centro Nacional de Protección de Infraestructuras y Ciberseguridad.
- ESPDEF-CERT: Mando Conjunto de Ciberdefensa. Ámbito de redes y sistemas de información y telecomunicaciones de las Fuerzas Armadas, y otros que afecten a la Defensa Nacional.

### Metodologia de reporte

1. El sujeto afectado enviará un correo electrónico (o ticket) al CSIRT de referencia (INCIBE-CERT o CCN-CERT) notificando el incidente.

2. El CSIRT de referencia, dependiendo del incidente, pone en conocimiento del mismo al organismo receptor implicado o la autoridad nacional competente:
    - Si afecta a la Defensa Nacional, al ESPDEF-CERT.
    - Si afecta a Infraestructura Crítica de la Ley PIC 8/2011, al CNPIC.
    - Si afecta al RGPD, a la AEPD.
    - Si es un incidente de AAPP bajo el ENS de peligrosidad MUY ALTA o CRÍTICA, al CCN-CERT.
    - Si es un incidente de obligatorio reporte según el RD Ley 12/2018, a la autoridad nacional competente correspondiente.

3. El Organismo receptor implicado o autoridad nacional competente se pone en contacto con el sujeto afectado para recabar datos del incidente.

4. El sujeto afectado comunica las datos necesarios al organismo receptor implicado o autoridad nacional competente.

5. Si procede, desde la Ocina de Coordinación Cibernética (CNPIC) se pone la información a disposición de las Fuerzas y Cuerpos de Seguridad del Estado y Ministerio Fiscal para iniciar la investigación policial y judicial (art. 14.3 RD Ley 12/2018).

## Taxonomia de los ciberincidentes

### Contenido abusivo

- **Spam:** Correo electrónico masivo no solicitado.

- **Delito de odio:** Contenido difamatorio o discriminatorio.

- **Pornografía infantil, contenido sexual o violento inadecuado:** Material que represente de manera visual contenido relacionado con pornografía infantil, apología de la violencia, entre otros.

### Contenido dañino

- **Sistema infectado:** Sistema infectado con malware.

- **Servidos C&C (Mando y Control):** Conexión con servidor de mando y control mediante malware o sistemas infectados.

- **Distribucion de malware:** Recurso usado para distribución de malware.

- **Configuracion de malware:** Recurso que aloje ficheros de configuración de malware.

- **Malware dominio DGA:** Nombre de dominio generado mediante DGA (Algoritmo de Generación de Dominio), empleado por malware para contactar con un servidor de mando y control.

### Obtencion de informacion

- **Escaneo de redes (scanning):** Envío de peticiones a un sistema para descubrir posibles debilidades.

- **Analisis de paquetes (sniffing):** Observación y grabación del tráco de redes.

- **Ingenieria social:** Recopilación de información personal sin el uso de la tecnología.

### Intento de intrusion

- **Explotación de vulnerabilidades conocidas:** Intento de compromiso de un sistema o de interrupción de un servicio mediante la explotación de vulnerabilidades con un identicador estandarizado (véase CVE).

- **Intento de acceso con vulneración de credenciales:** Múltiples intentos de vulnerar credenciales.

- **Ataque desconocido:** Ataque empleando un exploit desconocido.

### Intrusion

- **Compromiso de cuenta con privilegios:** Compromiso de un sistema en el que el atacante ha adquirido privilegios.

- **Compromiso de cuenta sin privilegios:** Compromiso de un sistema empleando cuentas sin privilegios.

- **Compromiso de aplicaciones:** Compromiso de una aplicación mediante la explotación de vulnerabilidades de software.

- **Robo:** Intrusión física.

### Disponibilidad

- **DoS (Denegación de servicio):** Ataque de denegación de servicio.

- **DDoS (Denegación distribuida de servicio):** Ataque de denegación distribuida de servicio.

- **Sabotaje:** sabotaje fisico.

- **Interrupciones:** interrupciones por causas ajenas.

### Compromiso de la informacion

- **Acceso no autorizado a información:** Acceso no autorizado a información.

- **Modificación no autorizada de información:** Modificación no autorizada de información.

- **Pérdida de datos:** Pérdida de información.

### Fraude

- **Uso no autorizado de recursos:** Uso de recursos para propósitos inadecuados, incluyendo acciones con ánimo de lucro.

- **Derechos de autor:** Ofrecimiento o instalación de software carente de licencia u otro material protegido por derechos de autor.

- **Suplantación:** Tipo de ataque en el que una entidad suplanta a otra para obtener beneficios ilegítimos.

- **Phishing:** Suplantación de otra entidad con la finalidad de convencer al usuario para que revele sus credenciales privadas.

### Vulnerable

- **Criptografía débil:** Servicios accesibles públicamente que puedan presentar criptografía débil.

- **Amplificador DDoS:** Servicios accesibles públicamente empleados para la reflexión o amplificación de ataques DDoS.

- **Servicios con acceso potencial no deseado**

- **Revelación de información:** Acceso público a servicios en los que potencialmente pueda relevarse información sensible.

- **Sistema vulnerable**

### Otros

- **APT:** Ataques dirigidos contra organizaciones concretas, sustentados en mecanismos muy sofisticados de ocultación, anonimato y persistencia. Esta amenaza habitualmente emplea técnicas de ingeniería social para conseguir sus objetivos junto con el uso de procedimientos de ataque conocidos o genuinos.

- **Ciberterrorismo:** Uso de redes o sistemas de información con fines de carácter terrorista.

- **Daños informáticos PIC:** Borrado, dañado, alteración, supresión o inaccesibilidad de datos, programas informáticos o documentos electrónicos de una infraestructura crítica. Conductas graves relacionadas con los términos anteriores que afecten a la prestación de un servicio esencial.

## Notificaion de incidentes

### Criterios para la notificacion

Para la notificación de los incidentes de ciberseguridad a la autoridad competente o CSIRT de referencia se utilizará como criterio de referencia el **nivel de peligrosidad** que se asigne a un incidente.  

El **nivel de impacto** en que se categorice un incidente podría aconsejar la comunicación del incidente.  

Cuando un determinado suceso pueda asociarse a más de un tipo de incidente, este se asociará a aquel que tenga un nivel de peligrosidad superior.

### Nivel de peligrosidad del ciberincidente

- **Critico:**
    - APT
    - Ciberterrorismo
    - Daños informáticos PIC.

- **Muy alto:**
    - Codigo dañino: Distribución de malware y configuración de malware.
    - Intento de intrusión: Ataque desconocido.
    - Intrusión: Robo.
    - Disponibilidad: Sabotaje e interrupciones.

- **Alto:**
    - Contenido abusivo: Pornografía infantil, contenido sexual o violento inadecuado.
    - Código dañino: Sistema infectado, servidor C&C (Mando y Control) y malware dominio DGA.
    - Intento de intrusión: Compromiso de aplicaciones.
    - Disponibilidad: DoS (Denegación de servicio) y DDoS (Denegación distribuida de servicio).
    - Compromiso de la información: Acceso no autorizado a información, modificación no autorizada de información y pérdida de datos.
    - Fraude: Phishing.

- **Medio:**
    - Contenido abusivo: Discurso de odio.
    - Obtención de información: Ingeniería social.
    - Intento de intrusión: Explotación de vulnerabilidades conocidas e intento de acceso con vulneración de credenciales.
    - Intrusión: Compromiso de cuentas con privilegios.
    - Fraude: Uso no autorizado de recursos, derechos de autor y suplantación.
    - Vulnerable: Criptografía débil, amplificador DDoS, servicios con acceso potencial no deseado, revelación de información y sistema vulnerable.

- **Bajo:**
    - Contenido abusivo: Spam.
    - Obtención de información: Escaneo de redes (scanning) y análisis de paquetes (sniffing).
    - Intrusión:Compromiso de cuenta sin privilegios.
    - Otros: Otros.