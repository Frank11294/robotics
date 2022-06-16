
#include <lib/aurebot.h>
#include <lib/motores.h>
#include <lib/flex_lcd.c>
#include <lib/bumper.h>
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


//Rutina principal
void main()
{
   int i, d, j, k;
  // aure_configurar();
  
  Set_tris_a(0b00001010);
  Set_tris_e(0b00001011);
  
  lcd_configurar();



 while(1)
{
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Bienvenido a");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"a mi fiesta");

      motores_palante();
      delay_ms(7000);


      motores_paizda();
      intermitentes(PIN_A1);
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
