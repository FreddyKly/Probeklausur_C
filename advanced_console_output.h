/*
 * ADVANCED CONSOLE OUTPUT 
 * Datei: advanced_console_output.h
 * 
 * Diese Bibliothek dient der effizienten Bildschirmausgabe
 * im Terminal (xterm, konsole etc.). 
 * 
 * Während "normalerweise" mit formatierter und unformatierter
 * Ausgabe Informationen nur zeilenweise ausgegeben werden 
 * können, ermöglicht es diese Bibliothek, den gesamten Bereich
 * des Terminals zu nutzen, und dabei insbesondere
 * - den Cursor beliebig zu versetzen,
 * - Text- und Hintergrundfarben zu verändern,
 * - Texthervorherbungen vorzunehmen.
 * 
 * Die vorliegende Header-Datei listet alle Funktionen der
 * Bibliothek advanced_console_output auf; die zugehörige 
 * Implementierung findet sich in der gleichnamigen c-Datei.
 * 
 * Diese Bibliothek ist Lehr- und Übungsmaterial für die 
 * Lehrveranstaltung "Einführung in die Programmierung" von 
 * Prof. Dr. Thomas Gabel an der Frankfurt University of 
 * Applied Sciences.
 * 
 * (c) Thomas Gabel, 2019
 */

#ifndef __ADVANCED_CONSOLE_OUTPUT__
#define __ADVANCED_CONSOLE_OUTPUT__

#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

// Breite und Höhe des Terminals abfragen (Breite wird in 
// den Referenzparameter w geschrieben, Höhe in h)
void get_screen_dimension(int* w, int* h);
// Abfrage der Breite des Terminals (Anzahl Spalten)
int get_screen_width();
// Abfrage der Höhe des Terminals (Anzahl Zeilen)
int get_screen_height();

// Cursor an Position (x,y) versetzen, wobei x die Spalte 
// bezeichnet und y die Zeile. Zählung beginnt bei 1
void locate(int x, int y);

// Bildschirm löschen (Terminalinhalt leeren)
void clear();

// Ändern der Textfarbe (Vordergrundfarbe, foreground)
// Parameter ist die Farbe, zur Auswahl stehen:
// black, red, green, yellow, blue, magenta, cyan, faintgray,
// default (Standardvordergrundfarbe des Systems) sowie 
// xtermwhite (ein sehr helles grau)
void set_fg_color(char* str);
// Ändern der Hintergrundfarbe (background), zur Auswahl
// stehende Farbnamen wie zuvor
void set_bg_color(char* str);

// Ändern der Textfarbe durch Spezifikation des RGB-Werts
// der gewünschten Farbe
void set_fg_color_rgb(int r, int g, int b);
// Ändern der Hintergrundfarbe durch Spezifikation des RGB-Werts
// der gewünschten Farbe
void set_bg_color_rgb(int r, int g, int b);

// Hilfsfunktionen zum Farbsetzen
void set_color(int bg, char* str);
void set_color_rgb(int bg, int r, int g, int b);

// Text fett ausgeben
void set_text_bold();
// Text normal dick (nicht fett) ausgeben
void unset_text_bold();

// Text kursiv ausgeben
void set_text_italic();
// Text normal ausgerichtet (nicht kursiv) ausgeben
void unset_text_italic();

// Text unterstrichen ausgeben
void set_text_underlined();
// Text ohne Unterstreichung ausgeben
void unset_text_underlined();

// Text blinkend ausgeben
void set_text_blinking();
// Text nicht blinkend ausgeben
void unset_text_blinking();

// Text durchgestrichen ausgeben
void set_text_crossedout();
// Text nicht durchgestrichen ausgeben
void unset_text_crossedout();

// alle Textattribute auf normal zurücksetzen 
// (nicht fett, nicht kursiv, nicht unterstrichen, nicht
// blinkend, nicht durchgestrichen)
void set_text_normal();

#endif
