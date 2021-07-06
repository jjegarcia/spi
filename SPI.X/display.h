/* 
 * File:   display.h
 * Author: jgarc609
 *
 * Created on June 22, 2021, 10:52 AM
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

unsigned char ledValue;

void setupDisplayIo(void);
void displaySerial(void);
void displaySPI(void);
void displayRequestHandle(void);
void displayCallback(void);
#endif	/* DISPLAY_H */

