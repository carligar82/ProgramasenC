/**
 * Sencillo cronómetro para controlor el tiempo de tus actividades en el ordenador (con señal acústica)
 * @date 23-07-2007
 * @author Carlos Limeres
 * */
#include <stdio.h>
#include <dos.h>
void main (void)
{
 struct time t;
 int a,b,d,e,x;
 float h,j,s,k,i;
 d=0;
 e=0;
 printf ("Configuraci¢n reloj (<24h):\n");
 do
 {
  printf ("Horas:");
  scanf ("%d",&a);
  printf ("Minutos:");
  scanf ("%d",&b);
  h=(a*60)+b;
 }
 while (h>24*60);
 gettime(&t);
 i=t.ti_hour*60+t.ti_min;
 do
 {
  printf ("%02d:%02d\r",d,e);
  gettime(&t);
  e=0;
  d=0;
  j=t.ti_hour*60+t.ti_min;
  k=j-i;
  for (s=1;s<=k;s++)
  {
   e++;
   if (e==60)
   {
    e=0;
    d=d+1;
   }
  }
 }
 while (k!=h);
 for (x=1;x<=20;x++)
 {
  printf ("\a");
  delay (1000);
 }
}
