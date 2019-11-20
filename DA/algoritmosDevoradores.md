# Algoritmos devoradores

Los algoritmos devoradores o voraces (greedy) se emplean normalmente en problemas de optimización, y responden al
siguiente esquema general:

```
devorador : C → S
S ← ∅
mientras ¬solución(S) ∧ C != ∅
  p ← selección(C)
  C ← C − {p}
  si factible(S ∪ {p})
    S ← S ∪ {p}
```

Se distinguen los siguientes elementos:

- Un conjunto de candidatos. **C**

- Un conjunto de candidatos seleccionados. **S**

- Una función solución que comprueba si un conjunto de
candidatos es una solución (posiblemente no óptima). **solucion(S)**

- Una función de selección que indica el candidato más
prometedor de los que quedan. **seleccion(C)**

- Una función de factibilidad que comprueba si un conjunto de
candidatos se puede ampliar para obtener una solución (no
necesariamente óptima). **factible(S u {p})**

- Una función objetivo que asocia un valor a una solución, y que
queremos optimizar. **cellValue()**

- Un objetivo, minimizar o maximizar.

Hay que tener en cuenta que el candidato más prometedor no tiene porqué ser único, se pueden producir **empates**. Además, hay que tener en cuenta que **un candidato, una vez considerado, nunca vuelve a estar disponible**. Se entiende que el algoritmo busca la solución rápida sin “visión de futuro”. 

Asimismo, si **un candidato entra en la selección, ya nunca sale de esta**. En caso de que, tras aplicar el algoritmo, **S no sea solución**, hay dos razones posibles; bien el algoritmo no ha sido capaz de encontrarla o, no existe solución. Habría que
buscar la causa responsable, lo cual se dificulta ya que **cada problema o algoritmo particular precisa de un estudio propio.**

Tener en cuenta además que este algoritmo busca una solución de forma rápida y no es total, luego **la solución aportada NO tiene por que ser óptima**. Todo sea dicho, existen problemas los cuales sí disponen de un Algoritmo devorador óptimo, pero no son todos.

Por regla general, deberemos conformarnos con **Algoritmos devoradores aproximados, los cuales no garantizan una solución óptima**.

Cuando usamos un algoritmo no óptimo, el objetivo es que el **error**, siendo este, la diferencia entre los valores de la función objetivo para la solución óptima y la solución obtenida, bien sea lo menor posible o al menos, esté acotada.


## Problema de la mochila

Dado un conjunto **O de objetos**, cada uno con un **valor v** y un **peso p**, y una mochila con una
**capacidad c**, que limita el peso total que puede transportar, se desea hallar la composición
de la mochila que maximiza el valor de la carga.

Existen tres posibles estrategias de selección de objetos:
- En orden decreciente de valor
- En orden creciente de peso
- En orden decreciente de relación valor/peso **(solucion optima)**

Un desglose del problema en sus elementos sería el siguiente (Aplicando el paradigma de los algoritmos voraces):
- **`Conjunto de los candidatos:`** Los objetos a introducir en la mochila. **O**
- **`Función solución:`** ¿Está la mochila llena? **c != 0**
- **`Función de selección:`** Elección del elemento con mayor proporción valor/peso. **seleccion-objeto(C)**
- **`Función de factibilidad:`** Si introduzco este objeto en la mochila, ¿Me paso de peso? **p <= c**
- **`Función objetivo:`** Valor total de los objetos devueltos 
- **`Objetivo:`** Maximizar

```
mochila : O × c → S
C ← O
S ← ∅
mientras c != 0 ∧ C != ∅
  {v,p} ← selecciona-objeto(C)
  C ← C − {v, p}
  si p ≤ c
    S ← S ∪ {v, p}
    c ← c − p
  si no
    S ← S ∪ {v*c/p, c}
    c ← 0

selecciona-objeto : C → v × p
r ← −∞
para todo {a, b} ∈ C
  si a/b > r
    r ← a/b
    {v, p} ← {a, b}
```

