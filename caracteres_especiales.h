/*
 * (C) Copyright 2017 MartInez Ortiz Saul UNAM
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*************************************************************/
/* Biblioteca : caracteres_espaciales.                       */
/* DescripciOn: Define un conjunto de macros que             */
/*              representan los carActeres especiales de     */
/*              uso frecuente en el espaniol. Principalmente */
/*              las vocales acentuadas y tambiEn algunos     */
/*              simbolos de dibujo de calas. La definiciOn   */
/*              se hace tomando en cuenta el sistema.        */
/*************************************************************/

#ifndef _CARACTERES_ESPECIALES_H
#define _CARACTERES_ESPECIALES_H

/*=============================*
 * Caracteres para el espaniol *
 *=============================*/

#ifdef _WIN32

    /*-* Comando para limpiar la pantalla *-*/
    #define CLEAR "cls"

    /*-* Letras minusculas acentuadas *-*/
    #define A "\xA0"
    #define E "\x82"
    #define I "\xA1"
    #define O "\xA2"
    #define U "\xA3"
    #define N "\xA4"

    /*-* Letras mayusculas acentuadas *-*/
    #define MA "\xB5"
    #define ME "\x90"
    #define MI "\xD6"
    #define MO "\xE0"
    #define MU "\xE9"
    #define MN "\xA5"

    /*-* Signo de pregunta inicial *-*/
    #define Q  "\xA8"

    /*-* Signo de exclamaciOn inicial *-*/
    #define X  "\xAD"

#else // unix

    /*-* Comando para limpiar la pantalla *-*/
    #define CLEAR "clear"

    /*-* Letras minusculas *-*/
    #define A "\u00E1"
    #define E "\u00E9"
    #define I "\u00ED"
    #define O "\u00F3"
    #define U "\u00FA"
    #define N "\u00F1"

    /*-* Letras mayusculas *-*/
    #define MA "\u00C1"
    #define ME "\u00C9"
    #define MI "\u00CD"
    #define MO "\u00D3"
    #define MU "\u00DA"
    #define MN "\u00D1"

    /*-* Signo de pregunta abierto *-*/
    #define Q  "\u00BF"

    /*-* Signo de exclamaciOn inicial *-*/
    #define X  "\u00A1"

#endif // Fin _WIN32

/*========================*
 * CarActeres para dibujo *
 *========================*/

/** 
 * Dibujo de cajas:
 *
 *      0    8     4          1
 *      +----------+----------+     0 - Esquina superior izquierda
 *      |          |          |     1 - Esquina superior derecha
 *      |          |          |     2 - Esquina inferior derecha
 *      |          |          |9    3 - Esquina inferior izquierda
 *      |          |          |     4 - Truncamiento superior
 *     7|----------+10--------|5    5 - Truncamiento derecho
 *      |          |          |     6 - Truncamiento inferior
 *      |          |          |     7 - Truncamiento izquierdo
 *      |          |          |     8 - Barra horizontal
 *      |          |          |     9 - Barra vertical
 *      +---------------------+     10- Centro
 *      3          6          2
 */

#define ESQUINA_SUPERIOR_IZQUIERDA  0
#define ESI                         0

#define ESQUINA_SUPERIOR_DERECHA    1
#define ESD                         1

#define ESQUINA_INFERIOR_DERECHA    2
#define EID                         2

#define ESQUINA_INFERIOR_IZQUIERDA  3
#define EII                         3

#define TRUNCAMIENTO_SUPERIOR       4
#define TSU                         4

#define TRUNCAMIENTO_DERECHO        5
#define TDE                         5

#define TRUNCAMIENTO_INFERIOR       6
#define TIN                         6

#define TRUNCAMIENTO_IZQUIERDO      7
#define TIZ                         7

#define BARRA_HORIZONTAL            8
#define BHZ                         8

#define BARRA_VERTICAL              9
#define BVE                         9

#define CENTRO                      10
#define CEN                         10

#ifdef _WIN32

// Caja con lineas simples
const char * CAJA1[11] = {
    "\xDA", "\xBF", "\xD9", "\xC0",
    "\xC2", "\xB4", "\xC1", "\xC3",
    "\xC4", "\xB3", "\xC5"
};

// Caja con lineas dobles
const char * CAJA2[11] = {
    "\xC9", "\xBB", "\xBC", "\xC8",
    "\xCB", "\xB9", "\xCB", "\xCC",
    "\xCD", "\xCA", "\xCA"
};

// La caja con esquinas redondeadas no existe en windows
// simplemente se pusieron simbolos de suma y resta en su lugar
const char * CAJA3[11] = {
    "+", "+", "+", "+",
    "+", "+", "+", "+",
    "-", "|", "+"
};

#else // else _WIN32

// Caja con lineas simples
const char * CAJA1[11] = {
    "\u250C", "\u2512", "\u2518", "\u2514",
    "\u252C", "\u2524", "\u2534", "\u251C",
    "\u2500", "\u2502", "\u253C"
};

// Caja con lineas dobles
const char * CAJA2[11] = {
    "\u2554", "\u2557", "\u255D", "\u255A",
    "\u2566", "\u2563", "\u2569", "\u2560",
    "\u2550", "\u2551", "\u256C"
};

// Caja con esquinas redondeadas
const char * CAJA3[11] = {
    "\u256D", "\u256E", "\u256F", "\u2570",
    "\u252C", "\u2524", "\u2534", "\u251C",
    "\u2500", "\u2502", "\u253C"
};

#endif // Fin _WIN32

/*
 * CarActeres de bloque
 */

#ifdef _WIN32

#define BDB "\xB0"        // Bloque Densidad Baja
#define BDM "\xB1"        // Bloque Densidad Media
#define BDA "\xB2"        // Bloque Densidad Alta

#else // else _WIN32

#define BDB "\u2591"      // Bloque Densidad Baja
#define BDM "\u2592"      // Bloque Densidad Media
#define BDA "\u2593"      // Bloque Densidad Alta

#endif // _WIN32

/*
 * Otros carActeres de dibujo
 */

#ifdef _WIN32 

#define EQUIS                   "\x9E"
#define CIRCULO_TRANSPARENTE    "\x4F"
#define CIRCULO_NEGRO           "\x9D"
#define CUADRO_TRANSPARENTE     "\xB0"
#define CUADRO_NEGRO            "\xDC"

// En windows solo hay un corazOn aceptado por la terminal
// por lo que todos son el mismo
#define CORAZON1                "\x03"
#define CORAZON2                "\x03"
#define CORAZON3                "\x03"
#define CORAZON4                "\x03"
#define CORAZON5                "\x03"
#define CORAZON6                "\x03"

#define INFINITO                "\xEC"

#define CRUZ1                   "\x86"
#define CRUZ2                   "\x87"
#define CRUZ3                   "\x86"
#define CRUZ5                   "\x86"
#define CRUZ6                   "\x86"
#define CRUZ7                   "\x86"
#define CRUZ8                   "\x86"
#define CRUZ9                   "\x86"
#define CRUZ10                  "\x86"
#define CRUZ11                  "\x86"
#define CRUZ12                  "\x86"

// Simbolos de gEnero
#define FEMENINO                "\x0C"
#define MASCULINO               "\x0D"

// Estos simbolos no estAn es ascii
// por lo que se pueso algo que se
// pareciera
#define SIMBOLO_PAZ             "\xBC"
#define AMOR_Y_PAZ              "\x59"

#define ESTRELLA1               "\x2A"
#define ESTRELLA2               "\x2A"
#define ESTRELLA3               "\x2A"
#define ESTRELLA4               "\x2A"
#define ESTRELLA5               "\x2A"
#define ESTRELLA6               "\x2A"
#define ESTRELLA7               "\x2A"
#define ESTRELLA8               "\x2A"
#define ESTRELLA9               "\x2A"
#define ESTRELLA10              "\x2A"
#define ESTRELLA11              "\x2A"
#define ESTRELLA12              "\x2A"
#define ESTRELLA13              "\x2A"
#define ESTRELLA14              "\x2A"
#define ESTRELLA15              "\x2A"
#define ESTRELLA16              "\x2A"
#define ESTRELLA17              "\x2A"
#define ESTRELLA18              "\x2A"

#define LUNA1                   "\x28"
#define LUNA1                   "\x29"

#else // else _WIN32

#define EQUIS                   "\u00D7"
#define CIRCULO_TRANSPARENTE    "\u25CB"
#define CIRCULO_NEGRO           "\u25CF"
#define CUADRO_TRANSPARENTE     "\u25A1"
#define CUADRO_NEGRO            "\u25A0"

#define CORAZON1                "\u2764"
#define CORAZON2                "\u2765"
#define CORAZON3                "\u2661"
#define CORAZON4                "\u2766"
#define CORAZON5                "\u2767"
#define CORAZON6                "\u10E6"

#define INFINITO                "\u221E

#define CRUZ1                   "\u2020"
#define CRUZ2                   "\u2021"
#define CRUZ3                   "\u271D"
#define CRUZ4                   "\u2628"
#define CRUZ5                   "\u271E"
#define CRUZ6                   "\u2626"
#define CRUZ7                   "\u2629"
#define CRUZ8                   "\u2720"
#define CRUZ9                   "\u271B"
#define CRUZ10                  "\u271C"
#define CRUZ11                  "\u2720"
#define CRUZ12                  "\u271A"

// Simbolos de gEnero
#define FEMENINO                "\u2640"
#define MASCULINO               "\u2642"

#define SIMBOLO_PAZ             "\u262E"
#define AMOR_Y_PAZ              "\u270C"

#define ESTRELLA1               "\u272C"
#define ESTRELLA2               "\u272D"
#define ESTRELLA3               "\u272E"
#define ESTRELLA4               "\u272F"
#define ESTRELLA5               "\u2730"
#define ESTRELLA6               "\u2721"
#define ESTRELLA7               "\u22C6"
#define ESTRELLA8               "\u2722"
#define ESTRELLA9               "\u2723"
#define ESTRELLA10              "\u2724"
#define ESTRELLA11              "\u2725"
#define ESTRELLA12              "\u274B"
#define ESTRELLA13              "\u2726"
#define ESTRELLA14              "\u2727"
#define ESTRELLA15              "\u2729"
#define ESTRELLA16              "\u272A"
#define ESTRELLA17              "\u272B"
#define ESTRELLA18              "\u2605"

#define LUNA1                   "\u263E"
#define LUNA2                   "\u263D"

#endif // fin _WIN32

#endif // Fin _CARACTERES_ESPECIALES_H
