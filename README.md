# caracteres_especiales
Un conjunto de macros para el manejo en consola de símbolos especiales.

## Justificación

En las primeras clases de programación en C, es bastante común que para imprimir
cualquier carácter fuera del código ASCII tengamos que usar su código numérico
proveniente de tablas en Internet de forma similar a:

    printf("C%cdigo num%crico", 163, 131);

Esta forma de imprimir los llamados "caracteres especiales", sin embargo, cuenta
con una serie de problemas:
* Los códigos numéricos parecen arbitrarios ante nuestros ojos. La única forma
    de usarlos correctamente es aprenderlos de memoria o estar constantemente
    revisando una tabla.
* La codificación de la consola es relevante. Los códigos anteriores funcionarán
    correctamente en la "cmd.exe" de windows (si esta mantiene la configuración
    por defecto), pero no funcionarán probablemente en la consola de git,
    en cygwin así como en cualquier consola de Linux o Mac las cuales requieren
    códigos distintos.
* Esta aproximación solo funciona con un máximo de 256 caracteres dado que %c
    imprime un dato de tipo char cuyo tamaño es 1 byte.

Entonces cabe preguntarse: ¿Hay formas mejores de imprimir caracteres especiales?
La respuesta como no podría ser de otra forma es un rotundo si. De hecho, hay
tantas aproximaciones más a este problema que a veces parecería que cada persona
cuenta con su propia respuesta en este asunto. Esta situación en lugar de ser
ventajosa para el principiante simplemente suele ser confusa en especial porque
muchas de las respuestas alternativas son tan malas como la antes mencionada.

Ahí es donde entra este pequeño proyecto, que si bien no representa la respuesta
definitiva, más extensible, más legible, ni mucho menos la más fácil, por lo
menos si es:
* Una respuesta lo suficientemente extensible.
* Una respuesta lo suficientemente fácil que no requiere de conocimientos sobre
    diferentes codificaciones o de las diferencias entre sistemas operativos
    para funcionar.
* Más legible que usar especificadores de formato y códigos numéricos.
* No requiere interacción con el compilador o la consola de comandos.

## Uso

Esta pequeña biblioteca está contenida por completo en la cabecera
"caracteres_especiales.h", la cual contiene poco más que una serie de macros
y constantes representando códigos de ciertos símbolos (En especial los
símbolos de uso común en el español como acentos y ñ's).
Para usar las macros bastará con hacer:

    #include "ruta/hacia/caracteres_especiales.h"

Por ejemplo, las macros correspondientes a los caracteres acentuados usan los
nombres A, E, I, O y U para representar a la á, é, í, ó y ú respectivamente.
Mediante dichas macros se podrá sustituir una llamada del estilo:

    printf("C%cdigo num%crico", 163, 131);

por esto:

    printf("C" O "digo num" E "rico");

Nótense que las múltiples cadenas y macros dentro de los argumentos del printf
no están separadas por más que un espacio. Si hubiera una coma separando las
diferentes partes, el único argumento se convertiría en varios que nuevamente
requerirían usar modificadores "%s" o "%c" para funcionar.

En resumidas cuentas, el resultado a la salida será:

    Código numérico

Esto es así gracias a una característica de las cadenas en ANSI C que dicta que
las cadenas contiguas separadas solo por caracteres blancos son concatenadas en
tiempo de compilación. En otras palabras, esto:

    "Hola" "mundo"

pasa a ser esto:

    "Holamundo"

De tal forma que cada vez que quieras hacer uso de un carácter especial dentro
de una literal de texto solo debes partir la cadena en dos cadenas distintas y
poner entre las dos la macro correspondiente al carácter que quieres imprimir.

Por ejemplo, para representar año tendrías que pasar por los siguientes pasos:

    "ao"    // Poner el texto (sin la ñ)
    "a" "o" // Partír la cadena en dos en el lugar que le corresponde a la ñ
    "a" N "o" // Poner la macro N que se espande en una ñ enmedio

Mientras tanto, la cabecera se encargará de expandir la macro al código
correspondiente sin importar si se está en windows, linux o mac.

La lista de macros para imprimir símbolos de español es la siguiente:

| Nombre de la macro | Carácter  que representa |
|:------------------:|:------------------------:|
| A                  | á                        |
| E                  | é                        |
| I                  | í                        |
| O                  | ó                        |
| U                  | ú                        |
| N                  | ñ                        |
| MA                 | Á                        |
| ME                 | É                        |
| MI                 | Í                        |
| MO                 | Ó                        |
| MU                 | Ú                        |
| MN                 | Ñ                        |
| Q                  | ¿                        |
| X                  | ¡                        |

También hay algunos códigos más categorizados como "experimentales". Para ver
una lista completa (y de paso poder observar cuales funcionan y cuales no)
puedes hacer uso del código de ejemplo "prueba_caracteres_especiales.c". Puedes
crear un proyecto en tu IDE preferido e incluir tanto
"prueba_caracteres_especiales.c" como "caracteres_especiales.h" para compilarlos
o simplemente compilarlos desde consola.
Incluso se incluye un makefile que te permite compilar el código de ejemplo
mediante el comando "make" (si es que cuentas con el) y produce un ejecutable de
nombre "prueba".

## Alternativas

Una vez más, el uso de esta biblioteca no es la mejor solución para poder usar
acentos en el lenguaje C.
La mejor solución suele ser siempre conocer la codificación en que guardamos
nuestro código fuente y especificar la misma al momento de la compilación. El
problema en esta ocasión es que cada compilador define mecanismos y banderas
distintas para especificar la codificación. Por ejemplo, para gcc se usan las
dos opciones "-finput-charset" y "-fexec-charset", la primera para representar
la codificación del archivo y la segunda para la consola, de modo que para
solucionar el problema de los acentos en cualquier plataforma que use gcc
simplemente se tendría que compilar el código fuente con:

    gcc <archivos .c>... -finput-charset=<cod_archivo> -fexec-charset=<cod_consola>

La codificación del archivo siempre seria la misma. Por ejemplo, si el archivo
fuente se creó en windows es muy probable que su codificación sea iso8859-1
(latin1) y si se creó en linux/mac probablemente será utf-8. En cuanto a la
codificación de la consola, esa cambiará en cada ocasión, siendo generalmente
cp437 o cp850 en windows y utf-8 u otros en linux/mac.

Es por eso que esta solución, a pesar de ser la más optima a la larga, suele ser
bastante más complicada en un principio.

Otra solución sencilla es usar la función setlocale() de la cabecera "locale.h"
para indicar que los parámetros de localización. Una forma sencilla de hacer que
los acentos funcionen en un programa es la siguiente:

    #include <locale.h>
    ...
    int main()
    {
       setlocale(LC_ALL, "Spanish_Mexico");
        ... // Impresiones con acentos
    }

Mediante una simple llamada a la función setlocal() se puede lograr que todas
las impresiones en pantalla de caracteres especiales funcionen correctamente...
al menos al principio. Más tarde es probable que nos encontremos con la amarga
sorpresa de que esta aproximación da por sentadas muchas configuraciones locales
al sistema, y nos limita a trabajar con una codificación específica por lo que
la magia no funcionará una vez que probemos el código en otra plataforma.
Resolverlo pasaría nuevamente por manejar manualmente los parámetros de
codificación lo cual a fin de cuentas terminaría siendo tan problemático o más
como la aproximación anterior.
