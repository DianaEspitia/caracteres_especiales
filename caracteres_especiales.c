/*
 * (C) Copyright 2017 MartInez Ortiz Saul UNAM
 *
 * This program is free software: you can redistribute it and/or modify
 * Tt under the terms of the GNU General Public License as published by
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

/**********************************************************/
/* Biblioteca : caracteres_espaciales.                    */
/* DescripciOn: Define un conjunto de macros que          */
/*              representan los carActeres especiales de  */
/*              uso frecuente en el espaniol.             */
/*              las vocales acentuadas. La definiciOn     */
/*              se hace tomando en cuenta el sistema.     */
/**********************************************************/

#ifndef _CARACTERES_ESPECIALES_H
#define _CARACTERES_ESPECIALES_H

#ifdef _WIN32

    /*-* Comando para limpiar la pantalla *-*/
    #define CLEAR "cls"

    /*-* Letras minusculas *-*/
    #define A "\xA0"
    #define E "\x82"
    #define I "\xA1"
    #define O "\xA2"
    #define U "\xA3"
    #define N "\xA4"

    /*-* Letras mayusculas *-*/
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

#endif // Fin _CARACTERES_ESPECIALES_H

