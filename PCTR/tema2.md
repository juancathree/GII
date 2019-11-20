# Creación y Control de Threads en Java

## Clase Thread

```java
public class Hola_Adios extends Thread {

    private String Cadena ;

    public Hola_Adios(String   Palabra){
        Cadena = Palabra ;
    }

    private void otrometodo () {
        System . out . println (" otro metodo ");
    }
    public void run () {
        for (;;) {
            System . out . println ( Cadena );
            this . otrometodo (); // run puede invocar otros metodos de la clase
            Integer p = new Integer (3); //o crear los objetos que necesita
        }
    }

    public static void main ( String [] args ) {
        new Hola_Adios(" Hola ").start();
        new Hola_Adios(" Adios ").start();
    }
```