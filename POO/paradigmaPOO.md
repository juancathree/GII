# Paradigma de la programacion orientada a objetos

En POO un programa se organiza como un conjunto finito de objetos que contienen datos y operaciones y que se comunican entre sí mediante mensajes.

Proceso de desarrollo orientado a objetos:
1. Identificar los objetos que intervienen.
2. Agrupar en clases los objetos con características y comportamientos comunes.
3. Identificar los datos y operaciones de cada clase.
4. Identificar las relaciones que puedan existir entre las clases.

Los principios en que se fundamenta la POO: **`Abstracción, encapsulamiento, ocultación de información, generalización, polimorfismo.`**

## Objetos

Un **objeto:**

- es una entidad individual del problema que se está resolviendo, formada por la unión de un estado y un comportamiento.

- es una entidad individual del programa que posee un conjunto de datos **`(atributos)`** y un conjunto de operaciones **`(métodos)`** que trabajan sobre ellos.

**`Estado:`** Conjunto de valores de todos los atributos de un objeto en un instante. Tiene un carácter dinámico,
evoluciona con el tiempo.

**`Comportamiento:`** Agrupa todas las compentencias del objeto y queda definido por las operaciones que posee. Actúan tras la recepción de un mensaje enviado por otro objeto.

**`Identidad:`** Caracteriza la existencia de un objeto como ente
individual. La identidad permite distinguir los objetos sin ambigüedad.

## Clases

Una **clase** agrupa un conjunto de objetos de las mismas características y es la descripción mediante el lenguaje de programación de las propiedades del conjunto de objetos que la forman.


## Construccion y uso de objetos

### Mutable

A traves de esta palabra reservada, conseguimos que el atributo sea modificable en metodos **`const`**.

```c++
mutable bool revisado;
```

### Static

Un atributo o metodo estático es compartido por todos los objetos de la clase.

```c++
static bool revisado;
```

## Const

## Sobrecarga de operadores

```c++
class Matriz{
    public:
        Matriz operator +();
        Matriz operator -();
        Matriz operator +(const Matriz& b);
        Matriz operator -(const Matriz& b);
        Matriz operator *(const Matriz& b);
        Matriz operator *(const Matriz& b);

        // r = a + b; // equivale a r = a.operator +(b);
        
        // r = -a * b; // equivale a r = a.operator −(). operator ∗(b);
        
        // r = a * -b; // equivale a r = a.operator ∗(b. operator −());
        
        // r = a + x; // equivale a r = a.operator +(Matriz{x});
        
        // r = x + a; // Error : Matriz operator +(unsigned, Matriz) no definido

        Matriz operator +(const Matriz& a);
        Matriz operator -(const Matriz& a);
        Matriz operator +(const Matriz& a, const Matriz& b);
        Matriz operator -(const Matriz& a, const Matriz& b);
        Matriz operator *(const Matriz& a, const Matriz& b);
        Matriz operator *(const Matriz& a, double k); // producto escalar
        Matriz operator *(double k, const Matriz& a); // conmutativo

        // r = a + b; // equivale a r = operator +(a, b );
        
        // r = -a * b; // equivale a r = operator ∗( operator −(a), b );
        
        // r = a * -b; // equivale a r = operator ∗(a, operator −(b));
        
        // r = a + x; // equivale a r = operator +(a, Matriz{x});
        
        // r = x + a; // equivale a r = operator +(Matriz{x}, a );
}
```

### Clases y funciones amigas

```c++
class A {
    public:
        friend class B; // la clase «B» es amiga de «A»
        // ...
    private:
        int d;
        // ...
};

class B {
    public:
        void f(A& a) { ++a.d; } // modifica «a.d», que es privado
        // ...
};
```

### Constructores

Un **constructor** es llamado:
- Cuando se define un objeto (declaración + inicialización).
- Al crear dinámicamente un objeto (con new y new[ ]).
- Para realizar ciertas conversiones.
- En la transferencia por valor de parámetros y resultados de funciones.
    - Copia
    - Movimiento

#### Constructor predeterminado

```c++
class Punto {
    public:
        Punto() : x_{}, y_{} {} // constructor predeterminado
        Punto(double x, double y) : x_{x}, y_{y} {} // constructor
        // ...
    private:
        double x_, y_;
};
```

#### Constructor de copia

El constructor de copia recibe una referencia constante a un objeto de la clase.

Se llama implícitamente cuando:
- Un objeto se inicializa con otro de la misma clase.
- Un objeto se pasa por valor.
- Un objeto se devuelve por valor.

```c++
Punto(const Punto& p) : x_{p.x_}, y_{p.y_}{}

Punto& operator =(const Punto& p){
    if(this != &p){
        x_ = p.x_;
        y_ = p.y_;
    }
    return *this;
}
```

#### Constructor de movimiento

```c++
Punto(Punto&& p) : x_{p.x_}, y_{p.y_}{
    p.x_ = 0;
    p.y_ = 0;
}
```

#### Constructor de conversion




