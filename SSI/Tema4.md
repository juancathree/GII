# Notificacion y gestion de ciberincidentes

## Metodologia de notificacion y seguimiento

### Organismos de referencia

El Gobierno de España atribuye las competencias en materia de ciberseguridad a diversos organismos:
- **`CCN-CERT:`** Centro Criptológico Nacional del Centro Nacional de Inteligencia.
- **`INCIBE-CERT:`** Instituto Nacional de Ciberseguridad de España.
- **`CNPIC:`** Centro Nacional de Protección de Infraestructuras y Ciberseguridad.
- **`ESPDEF-CERT:`** Mando Conjunto de Ciberdefensa. Ámbito de redes y sistemas de información y telecomunicaciones de las Fuerzas Armadas, y otros que afecten a la Defensa Nacional.

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

5. Si procede, desde la Oficina de Coordinación Cibernética (CNPIC) se pone la información a disposición de las Fuerzas y Cuerpos de Seguridad del Estado y Ministerio Fiscal para iniciar la investigación policial y judicial (art. 14.3 RD Ley 12/2018).

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
    
### Nivel de impacto del ciberincidente

El indicador de impacto de un ciberincidente se determinará evaluando las consecuencias que tal ciberincidente ha tenido en:
- Las funciones y actividades de la organización afectada.
- En sus activos.
- En los individuos afectados.

Los criterios para determinar el nivel de impacto son:
- Impacto en la Seguridad Nacional o Seguridad Ciudadana.
- Efectos en la prestación de un servicio esencial o en una infraestructura crítica.
- Tipología de la información o sistemas afectados.
- Grado de afectación a las instalaciones de la organización.
- Posible interrupción en la prestación del servicio normal de la organización.
- Tiempo y costes propios y ajenos hasta la recuperación del normal funcionamiento de las instalaciones.
- Pérdidas económicas.
- Extensión geográfica afectada.
- Daños reputacionales asociados.


Los niveles son:

- **Critico:**
    - Afecta apreciablemente a la Seguridad Nacional.
    - Afecta a la seguridad ciudadana, con potencial peligro para la vida de las personas.
    - Afecta a una Infraestructura Crítica.
    - Afecta a sistemas clasificados SECRETO.
    - Afecta a más del 90 % de los sistemas de la organización.
    - Interrupción en la prestación del servicio superior a 24 horas y superior al 50 % de los usuarios.
    - El ciberincidente precisa para resolverse > 30 días/pers.
    - Impacto económico superior al 0,1 % del P.I.B. actual.
    - Extensión geográfica supranacional.
    - Daños reputacionales muy elevados y cobertura continua en medios de comunicación internacionales.

- **Muy alto:**
    - Afecta a la seguridad ciudadana con potencial peligro para bienes materiales.
    - Afecta apreciablemente a actividades ociales o misiones en el extranjero.
    - Afecta a un servicio esencial.
    - Afecta a sistemas clasificados RESERVADO.
    - Afecta a más del 75 % de los sistemas de la organización.
    - Interrupción en la prestación del servicio superior a 8 horas y superior al 35 % de los usuarios.
    - El ciberincidente precisa resolverse entre 10 y 30 días/pers.
    - Impacto económico entre el 0,07 % y el 0,1 % del P.I.B.
    - Extensión geográfica superior a 4 CC.AA. o 1 T.I.S.
    - Daños reputacionales a la imagen del país (marca España).
    - Daños reputacionales elevados y cobertura continua en medios de comunicación nacionales.

- **Alto:**
    - Afecta a más del 50 % de los sistemas de la organización.
    - Interrupción en la prestación del servicio superior a 1 hora y superior al 10 % de usuarios.
    - El ciberincidente precisa resolverse entre 5 y 10 días/pers.
    - Impacto económico entre el 0,03 % y el 0,07 % del P.I.B.
    - Extensión geográfica superior a 3 CC.AA.
    - Daños reputacionales de difícil reparación, con eco mediático (amplia cobertura en los medios de comunicación) y              afectando a la reputación de terceros.
    
- **Medio:**
    - Afecta a más del 20 % de los sistemas de la organización.
    - Interrupción en la presentación del servicio superior al 5 % de usuarios.
    - El ciberincidente precisa para resolverse entre 1 y 5 días/pers.
    - Impacto económico entre el 0,001 % y el 0,03 % del P.I.B.
    - Extensión geográfica superior a 2 CC.AA.
    - Daños reputacionales apreciables, con eco mediático (amplia cobertura en los medios de comunicación).
    
- **Bajo:**
    - Afecta a los sistemas de la organización.
    - Interrupción de la prestación de un servicio.
    - El ciberincidente precisa para resolverse menos de 1 día/pers.
    - Impacto económico entre el 0,0001 % y el 0,001 % del P.I.B.
    - Extensión geográfica superior a 1 CC.AA.
    - Daños reputacionales puntuales, sin eco mediático.
    
Es obligatorio la notificación de todos aquellos incidentes que se categoricen con un nivel CRÍTICO (inmediata), MUY ALTO (12 horas) O ALTO (48 horas).

### Informacion a notificar

- **Asunto:** Frase que describe de forma general el incidente.
- **Descripción:** Describir con detalle lo sucedido.
- **Afectado:** Indicar si el afectado es empresa o particular.
- **Fecha y hora del incidente:** Indicar cuándo ha ocurrido el ciberincidente.
- **Fecha y hora de detección del incidente:** Indicar cuándo se ha detectado el ciberincidente.
- **Taxonomía del incidente:** Posible clasificación y tipo de incidente en función de la taxonomía descrita.
- **Recursos afectados:** Indicar la información técnica sobre el número y tipo de activos afectados por el ciberincidente, incluyendo direcciones IP, S.O., aplicaciones, versiones.
- **Origen del incidente:** Indicar la causa del incidente si se conoce. Apertura de un fichero sospechoso, conexión de un
dispositivo USB, acceso a una página web maliciosa, etc.
- **Contramedidas:** Actuaciones realizadas para resolver el ciberincidente hasta el momento de la notificación a la
autoridad competente o CSIRT de referencia.
- **Impacto:** Impacto estimado en la entidad, en función del nivel de afectación del ciberincidente.
- **Adjuntos:** Incluir documentos adjuntos que puedan aportar información que ayude a conocer la causa del problema o a su resolución (capturas de pantalla, ficheros de registro de información, correos electrónicos, etc.).
- **Regulación afectada:** ENS/RGPD/NIS/PIC/Otros.

### Estados de los ciberincidentes

- **Cerrado (Resuelto y sin respuesta):** No hay respuesta por parte del organismo afectado en un periodo determinado.
- **Cerrado (Resuelto y con respuesta):** El organismo afectado ha solventado la amenaza y notifica a su CSIRT de referencia el cierre del ciberincidente.
- **Cerrado (Sin impacto):** La detección ha resultado positiva pero el organismo no es vulnerable o no se ve afectado por el ciberincidente.
- **Cerrado (Falso positivo):** La detección ha sido errónea.
- **Cerrado (Sin resolución y sin respuesta):** Pasado un periodo de 60 días, si el ciberincidente no ha sido cerrado por el organismo afectado, es cerrado por el CSIRT de referencia.
- **Cerrado (Sin resolución y con respuesta):** No se ha alcanzado una solución al problema o el afectado indica que no sabe solventarlo incluso con las indicaciones proporcionadas por el CSIRT.
- **Abierto:** Estado que va desde que el organismo afectado notifica la amenaza al CSIRT de referencia, o bien este
último lo comunica al afectado, hasta que se produce el cierre del mismo.


## Gestion de incidentes de ciberseguridad

- **Fase de preparacion:**
    - Fase inicial en la que toda entidad debe estar preparada para cualquier suceso que pudiera ocurrir.
    - Debe tenerse en cuenta tres pilares fundamentales: las personas, los procedimientos y la tecnología.
    - Los puntos más relevantes a tener en cuenta son:
        - Disponer de información actualizada de contacto.
        - Mantener las políticas y procedimientos actualizados.
        - Herramientas a utilizar en todas las fases.
        - Formación del equipo humano para mejorar las capacidades técnicas y operativas.
        - Realizar análisis de riesgos que permita disponer de un plan de tratamiento de riesgos que permita controlarlos.
        - Ejecución de ciberejercicios a fin de entrenar las capacidades y procedimientos técnicos, operativos, de gestión y         coordinación.

- **Fase de identificacion:**
    - El objetivo es identificar o detectar un ciberincidente; es importante realizar una monitorización lo más completa
    posible.
    - Una correcta identificación se basa en:
        - Registrar y monitorizar los eventos de las redes, sistemas y aplicaciones.
        - Recolectar información situacional que permita detectar anomalías.
        - Disponer de capacidades para descubrir ciberincidentes y comunicarlos a los contactos apropiados.
        - Recopilar y almacenar de forma segura todas las evidencias.
        - Compartir información con otros equipos internos y externos de forma bidireccional para mejorar las capacidades de         detección.
        
- **Fase de contencion:**
    - Tras la identificación de un ciberincidente, la máxima prioridad es contener su impacto en la organización para evitar     la propagación a otros sistemas o redes.
    - Debe realizarse el triage (evaluar toda la información disponible para realizar una clasificación y priorización del       ciberincidente en función del tipo y de la criticidad de la información y los sistemas afectados).
    - Adicionalmente se identifican posibles impactos en el negocio.
    - Se debe:
        - Registrar y monitorizar los eventos de las redes, sistemas y aplicaciones.
        - Recolectar información situacional que permita detectar anomalías.
        - Disponer de capacidades para descubrir ciberincidentes y comunicarlos a los contactos apropiados.
        - Recopilar y almacenar de forma segura todas las evidencias.
        - Compartir información con otros equipos internos y externos de forma bidireccional para mejorar las capacidades de         detección.
        
- **Fase de mitigacion:**
    - Las medidas de mitigación dependen del tipo de ciberincidente y la afectación que haya tenido.
    - Algunas recomendaciones en esta fase son:
        - Determinar las causas y los síntomas del ciberincidente para determinar las medidas de mitigación más eficaces.
        - Identificar y eliminar todo el software utilizado por los atacantes.
        - Recuperación de la última copia de seguridad limpia.
        - Identificar servicios utilizados durante el ataque, ya que en ocasiones los atacantes utilizan servicios legítimos         de los sistemas atacados.
        
- **Fase de recuperacion:**
    - Consiste en devolver el nivel de operación a su estado normal y que las áreas de negocio afectadas puedan retomar su       actividad.
    - Es importante no precipitarse en la puesta en producción de sistemas que se han visto implicados en ciberincidentes.
    - Debe definirse un periodo de tiempo con medidas adicionales de monitorización de los sistemas puestos en producción.
    
- **Fase de post-incidente:**
    - Aprender de lo sucedido, analizando las causas del problema, cómo se ha desarrollado la actividad durante la gestión       del ciberincidente y todos los problemas asociados.
    - Tomar las medidas adecuadas para evitar que una situación similar se pueda volver a repetir, además de mejorar los
    procedimientos.
    - Realizar un informe del ciberincidente que deberá detallar la causa del ciberincidente y coste, y las medidas que la       organización debe tomar para prevenir futuros ciberincidentes de naturaleza similar.
    
## Metricas e indicadores

Métricas e indicadores de referencia recomendados para medir el nivel de implantación y eficacia del proceso de gestión de
incidentes de cada organización.

- **Metricas de implantacion**
    - **`Indicador:`**  Alcance del sistema de gestión de incidentes.
    - **`Objetivo:`** Saber si todos los sistemas de información están adscritos al servicio.
    
- **Metricas de eficacia**
    - **`Indicador:`** Resolución de ciberincidentes de nivel de impacto ALTO / MUY ALTO / CRÍTICO.
    - **`Objetivo:`** Resolver rápidamente incidentes de alto impacto.
    - **`Indicador:`** Resolución de ciberincidentes de nivel de impacto BAJO / MEDIO.
    - **`Objetivo:`** Resolver rápidamente incidentes de impacto medio.
    
- **Metricas de eficiencia**
    - **`Indicador:`** Recursos consumidos.
    - **`Objetivo:`** Conocer si es necesario aumentar la fuerza de trabajo.
    
- **Metricas de gestion de incidentes**
    - **`Indicador:`** Estado de cierre de los incidentes.
    - **`Objetivo:`** Ser capaces de gestionar incidentes de seguridad.
    - **`Indicador:`** Estado de cierre de los incidentes de peligrosidad MUY ALTA / CRÍTICA.
    - **`Objetivo:`** Ser capaces de gestionar incidentes de seguridad de alta peligrosidad.
