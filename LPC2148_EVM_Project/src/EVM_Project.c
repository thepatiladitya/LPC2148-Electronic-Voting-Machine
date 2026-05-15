#include <lpc214x.h>
#include <stdio.h>

#define LED1    (1<<16)   // SW1 -> Candidate_01_PARTY_A
#define LED2    (1<<17)   // SW2 -> Candidate_02_PARTY_B
#define LED3    (1<<18)   // SW3 -> Candidate_03_PARTY_C
#define LED4    (1<<19)   // SW4 -> Candidate_04_INDEPENDENT

#define ALLLED  (LED1|LED2|LED3|LED4)   // All LEDs
#define BUZZER  (1<<9)                  // Buzzer Output

int Candidate_01_PARTY_A=0;      // PARTY A votes
int Candidate_02_PARTY_B=0;      // PARTY B votes
int Candidate_03_PARTY_C=0;      // PARTY C votes
int Candidate_04_INDEPENDENT=0;  // Independent votes

int total_votes=0, selected_party=0;   // Total votes + selected party

void delay(int d)                      // Delay Function
{
    int i,j;

    for(i=0;i<d;i++)
    {
        for(j=0;j<60000;j++);
    }
}

void UART0_Init()                      // UART0 Initialization
{
    PINSEL0 |= 0x00000005;             // Enable TXD0 and RXD0

    U0LCR = 0x83;                      // 8-bit, DLAB=1
    U0DLL = 97;                        // 9600 baud rate
    U0DLM = 0;
    U0LCR = 0x03;                      // DLAB=0
}

void UART0_TxChar(char ch)             // UART Send Character
{
    while(!(U0LSR & 0x20));

    U0THR = ch;
}

void UART0_String(char *str)           // UART Send String
{
    while(*str)
    {
        UART0_TxChar(*str++);
    }
}

void startup_animation()               // Power ON Animation
{
    IO0SET = LED1; delay(5); IO0CLR = LED1; 									// for few Hardware Boards LED options are alternate
    IO0SET = LED2; delay(5); IO0CLR = LED2;										// for keil : IOCLR=LED OFF and  IOSET = LED ON
    IO0SET = LED3; delay(5); IO0CLR = LED3;										// for hardware : IOSET=LED OFF and  IOCLR = LED ON
    IO0SET = LED4; delay(5); IO0CLR = LED4;
}

void result_mode()                     // Result Indication
{
    int i;

    for(i=0;i<3;i++)
    {
        IO0SET = ALLLED; delay(5);     // All LEDs ON
        IO0CLR = ALLLED; delay(5);     // All LEDs OFF
    }
}

void confirm_vote(unsigned int led)    // Vote Confirmation
{
    IO0SET = led | BUZZER;             // LED + buzzer ON

    delay(20);                         // ~2 sec indication

    IO0CLR = led | BUZZER;             // LED + buzzer OFF

    delay(150);                        // ~15 sec voting stop
}

void vote()                            // Vote Function
{
    switch(selected_party)
    {
        case 1: Candidate_01_PARTY_A++;     confirm_vote(LED1); break;
        case 2: Candidate_02_PARTY_B++;     confirm_vote(LED2); break;
        case 3: Candidate_03_PARTY_C++;     confirm_vote(LED3); break;
        case 4: Candidate_04_INDEPENDENT++; confirm_vote(LED4); break;
    }

    total_votes++;                     // Increase total votes
}

void send_result()                     // UART Result Display
{
    char buf[80];

    UART0_String("\n\r------ FINAL RESULT ------\n\r");

    sprintf(buf,"Candidate_01_PARTY_A : %d\n\r",Candidate_01_PARTY_A);
    UART0_String(buf);

    sprintf(buf,"Candidate_02_PARTY_B : %d\n\r",Candidate_02_PARTY_B);
    UART0_String(buf);

    sprintf(buf,"Candidate_03_PARTY_C : %d\n\r",Candidate_03_PARTY_C);
    UART0_String(buf);

    sprintf(buf,"Candidate_04_INDEPENDENT : %d\n\r",Candidate_04_INDEPENDENT);
    UART0_String(buf);

    sprintf(buf,"Total Votes : %d\n\r",total_votes);
    UART0_String(buf);

    UART0_String("--------------------------\n\r");
}

int main()
{
    IO0DIR = 0x00FF0000 | BUZZER;      // LEDs + buzzer output

    UART0_Init();                      // UART Start

    startup_animation();               // Startup LEDs

    selected_party = 1; vote();        // TC1
    selected_party = 2; vote();        // TC2
    selected_party = 3; vote();        // TC3
    selected_party = 4; vote();        // TC4

    selected_party = 1; vote();        // TC5
    selected_party = 1; vote();        // TC6
    selected_party = 2; vote();        // TC7
    selected_party = 3; vote();        // TC8
    selected_party = 4; vote();        // TC9

    selected_party = 2; vote();        // TC10
    selected_party = 3; vote();        // TC11
    selected_party = 1; vote();        // TC12

    result_mode();                     // Final LED Blink

    send_result();                     // UART Result Output

    while(1);
}