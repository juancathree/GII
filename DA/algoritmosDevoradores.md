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




