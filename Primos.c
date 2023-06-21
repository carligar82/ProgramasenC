/**
 * Nos dice si un número es primo (sólo divisible por si mismo y por 1)
 * @date 29-06-2021
 * @author Carlos Limeres
 * */
#include <stdio.h>
void primo (unsigned long a)
{
 unsigned long b;
 int c=0;
 for (b=2;b<=a-1;b++)
 {
  if (a%b==0)
  {
   c=1;
  }
 }
 if (c==1)
 {
  printf ("El numero dado no es primo.\n");
 }
 else
 {
  printf ("El numero dado es primo.\n");
 }
 printf ("\a");
}
void main (void)
{
 unsigned long a;
 do
 {
  printf ("Dame el numero: ");
  scanf ("%lu",&a);
  if (a!=0)
  {
   primo (a);
  }
 }
 while (a!=0);
}