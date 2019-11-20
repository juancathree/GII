# Principios Generales de la Concurrencia

## Conceptos

- **Concurrencia:** Se da cuando dos o más procesos existen simultáneamente y hay que distinguir entre existencia y ejecución simultánea.

- **Proceso:** es un programa en ejecución. Esta formado por:
    - El código que ejecuta el procesador.
    - El estado (valores registros CPU).
    - La pila de llamadas.
    - La memoria de trabajo.
    - Información de la planificación.

- **Hebra:** es una secuencia de instrucciones dentro de un proceso, que ejecuta sus instrucciones de forma independiente.
- Un proceso puede tener varios hebras.
- Los hebras de un proceso no comparten
    - La pila (cada una posee la suya).
    - El contador de programa (ídem).
- Los hebras de un proceso comparten
    - Memoria de proceso (datos).
    - Recursos de sistema.

- **Paralelismo:** se tiene cuando se produce la ejecución simultánea de dos procesos concurrentes.

- **Sistema concurrente:** sistema informático donde la concurrencia desempeña un papel importante. Distinguir entre:
    - Sistemas inherentemente concurrentes: el entorno con el que interactuan, o el entorno que modelan tienen forzosamente actividades simultaneas.
    - Sistemas potencialmente concurrentes: no es estrictamente necesario que haya concurrencia, pero se puede sacar partido de ella.

- **Programacion concurrente:** Conjunto de notaciones y técnicas utilizadas para describir mediante programas el paralelismo potencial de los problemas, resolviendo los problemas de sincronización y comunicación que pueden plantearse.

- **Interbloqueo:** situación en que todos los procesos quedan a la espera de una condición que nunca se dará.

- **Secciones criticas:** zonas de código de las entidades concurrentes desde las que se accede a recursos comunes.

- **Exclusion mutua:** Consiste en evitar la condición de concurso sobre un recurso compartido forzando la ejecución atómica de las secciones críticas de las entidades concurrentes que lo usan. Elimina el entrelazado.

## Speedup

Podemos definir el concepto de speedup como el coeficiente entre el tiempo necesario para completar una tarea secuencialmente y el tiempo necesario para hacerlo en paralelo.

S = tiempo en secuencial / tiempo en paralelo

Clasificacion de speedup:
- Si S < 1, la paralelización ha hecho que la solución empeore.

- Si 1 < S  número de núcleos, hemos conseguido mejorar la solución en un rango normal.

- Si S > número de núcleos, la mejora obtenida ha sido hiperlineal.

