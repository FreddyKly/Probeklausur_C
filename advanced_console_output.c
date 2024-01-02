/*
 * HINWEIS: Schauen Sie sich bitte die Erläuterungen 
 *          in der Header-Datei (advanced_console_output.h)
 *          an.
 *
 * (c) Thomas Gabel, 2019
 */

#include "advanced_console_output.h"
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

void get_screen_dimension(int* w, int* h)
{
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
    *w = ws.ws_col;
    *h = ws.ws_row;
}

int get_screen_width()
{
    int w, dum;
    get_screen_dimension( &w, &dum);
    return w;
}

int get_screen_height()
{
    int h, dum;
    get_screen_dimension( &dum, &h );
    return h;
}

void locate(int x, int y) // x = row, y = col
{
    printf("\033[%d;%dH", y, x);
}

void clear()
{
    printf("\033[%dJ", 2);
}

void set_color(int bg, char* str)
{
    int v=30; //black in case of no match
    int bg_delta = (bg?10:0);
    if (strcmp(str, "xtermwhite")==0)
    {
        set_color_rgb(bg, 240, 240, 240);
    }
    else
    {
      if (strcmp(str, "black")==0) v=30;
      else if (strcmp(str, "red")==0) v=31;
      else if (strcmp(str, "green")==0) v=32;
      else if (strcmp(str, "yellow")==0) v=33;
      else if (strcmp(str, "blue")==0) v=34;
      else if (strcmp(str, "magenta")==0) v=35;
      else if (strcmp(str, "cyan")==0) v=36;
      else if (strcmp(str, "faintgray")==0) v=37;
      else if (strcmp(str, "default")==0) v=39;
      printf("\033[%dm", v+bg_delta);
    }
}

void set_fg_color(char* str)
{
    set_color( 0, str );
}

void set_bg_color(char* str)
{
    set_color( 1, str );
}

void set_color_rgb(int bg, int r, int g, int b)
{
    int bg_delta = (bg?10:0);
    printf("\033[%d;2;%d;%d;%dm", 38+bg_delta, r, g, b);
}

void set_fg_color_rgb(int r, int g, int b)
{
    set_color_rgb( 0, r, g, b );
}

void set_bg_color_rgb(int r, int g, int b)
{
    set_color_rgb( 1, r, g, b );
}

void set_text_bold()
{
    printf("\033[1m");
}

void unset_text_bold()
{
    printf("\033[22m");
}

void set_text_italic()
{
    printf("\033[3m");
}

void unset_text_italic()
{
    printf("\033[23m");
}

void set_text_underlined()
{
    printf("\033[4m");
}

void unset_text_underlined()
{
    printf("\033[24m");
}

void set_text_blinking()
{
    printf("\033[5m");
}

void unset_text_blinking()
{
    printf("\033[25m");
}

void set_text_crossedout()
{
    printf("\033[9m");
}

void unset_text_crossedout()
{
    printf("\033[29m");
}

void set_text_normal()
{
    printf("\033[0m");
}
