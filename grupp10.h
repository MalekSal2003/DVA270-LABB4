#include "nrfx.h"
#include "nrfx_uarte.h"
#include "nrfx_systick.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <nrf5340_application.h> // nRF5340 Application bibliotek f�r applikationsspecifika inst�llningar
#include <nrfx_config.h> // nRFx konfigurationsfil f�r inst�llningar
#include <nrf.h> // nRF bibliotek f�r enhetsspecifika definitioner
#include <nrf_gpio.h> // nRF GPIO bibliotek f�r GPIO-hantering
#include <stdint.h> // Standard C bibliotek f�r heltalstyper

#ifndef LIST_H
#define LIST_H
// Definitioner f�r stift
#define PIN_TXD 20
#define PIN_RXD 22
#define CLEAR_SCREEN "\033c"
static int user_score = 0;
static int computer_score = 0;
static int running = 1;
static uint8_t uarte_buffer;

// Kontrollerar om UARTE �r aktiverat
#if NRFX_CHECK(NRFX_UARTE_ENABLED)
    // Kontrollerar om UARTE �r aktiverat i konfigurationen
#if !NRFX_FEATURE_PRESENT(NRFX_UARTE, _ENABLED)
#error "No enable UARTE instance. Check <nrfx_config.h>"
#endif
#endif


// Extern deklaration av UARTE-instans
//extern nrfx_uarte_t instance;

// Funktionsprototyper f�r UARTE och LED-funktioner
void stop_running(void);
int is_running(void);
void uarte_handler(nrfx_uarte_event_t const* p_event, void* p_context);
void send_message(const char* message);
void play_game(char user_choice);
void start_game_grupp10(void);


/*******************************************************/
/* DVA270 - Interface f�r dubbell�nkad lista           */
/* Anpassad efter interface fr�n DVA244                */
/* av Stefan Bygde och Caroline Upps�ll                */
/* Vid fel eller fr�gor, kontakta jonas.larsson@mdu.se */
/*******************************************************/

#define LIST_LEN 20





#endif  