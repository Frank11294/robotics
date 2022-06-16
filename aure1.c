/*
          _____                    _____                    _____                    _____
         /\    \                  /\    \                  /\    \                  /\    \
        /::\    \                /::\____\                /::\    \                /::\    \
       /::::\    \              /:::/    /               /::::\    \              /::::\    \
      /::::::\    \            /:::/    /               /::::::\    \            /::::::\    \
     /:::/\:::\    \          /:::/    /               /:::/\:::\    \          /:::/\:::\    \
    /:::/__\:::\    \        /:::/    /               /:::/__\:::\    \        /:::/__\:::\    \
   /::::\   \:::\    \      /:::/    /               /::::\   \:::\    \      /::::\   \:::\    \
  /::::::\   \:::\    \    /:::/    /      _____    /::::::\   \:::\    \    /::::::\   \:::\    \
 /:::/\:::\   \:::\    \  /:::/____/      /\    \  /:::/\:::\   \:::\____\  /:::/\:::\   \:::\    \
/:::/  \:::\   \:::\____\|:::|    /      /::\____\/:::/  \:::\   \:::|    |/:::/__\:::\   \:::\____\
\::/    \:::\  /:::/    /|:::|____\     /:::/    /\::/   |::::\  /:::|____|\:::\   \:::\   \::/    /
 \/____/ \:::\/:::/    /  \:::\    \   /:::/    /  \/____|:::::\/:::/    /  \:::\   \:::\   \/____/
          \::::::/    /    \:::\    \ /:::/    /         |:::::::::/    /    \:::\   \:::\    \
           \::::/    /      \:::\    /:::/    /          |::|\::::/    /      \:::\   \:::\____\
           /:::/    /        \:::\__/:::/    /           |::| \::/____/        \:::\   \::/    /
          /:::/    /          \::::::::/    /            |::|  ~|               \:::\   \/____/
         /:::/    /            \::::::/    /             |::|   |                \:::\    \
        /:::/    /              \::::/    /              \::|   |                 \:::\____\
        \::/    /                \::/____/                \:|   |                  \::/    /
         \/____/                  ~~                       \|___|                   \/____/

   Programa de ejemplo para la AureBoard
   Requerido: Aureboard Versión>2.0

   - El programa configura el puerto Serie por USB.
   - Cada programa deberá ir en su carpeta al mismo nivel de la carpeta lib




   A.U.R.E. 2010
*/

#include <lib/aurebot.h>
#include <lib/motores.h>
#include <lib/flex_lcd.c>
#include <lib/servos.h>
#include <lib/sonido.h>


/*#include <../lib/ldr.h>
#include <../lib/cny70.h>
#include <../lib/bumper.h>
#include <../lib/2leds.h>*/

void intermitentes(int pin){
 int cont=0;
 for (cont=0;cont<10;cont+=1){
      output_high(pin);
      delay_ms(200);
      output_low(pin);
      delay_ms(200);
 }
       output_low(pin);
}
void sonido(int altavoz)
{
int i=0;
for(i=;i<10;i+=1)
{
output_high(altavoz);
delay_ms(200);
output_low(altavoz);
delay_ms(200);
}
output_low(altavoz);

}

//Rutina principal
void main()
{
   int i, d, j, k;
  // aure_configurar();
  // aure_configurar_usb_sinespera();
  
  Set_tris_a(0b00001010);
  Set_tris_e(0b00001011);

  lcd_configurar();


/*  
while (input(PIN_A1)) {
   output_toggle(LED);
   delay_ms(50);
 }
 */

 while(1)
{
      servos_mover_a(30,PIN_A4);

      lcd_gotoxy(1,1);
      printf(lcd_putc,"Bienvenido a");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"a mi fiesta");
      
      motores_palante();
      delay_ms(7000);
      
      
      motores_paizda();
      intermitentes(PIN_A1);
      sonido(PIN_A3)
      delay_ms(3000);
      

         
      motores_palante();
      delay_ms(7000);
      
      motores_paderecha();
      intermitentes(PIN_A2);
      delay_ms(3000);

      
      
      motores_palante();
      delay_ms(7000);
      
      motores_parar();

//LAVE DE ABAJO, MAIN
}

}



