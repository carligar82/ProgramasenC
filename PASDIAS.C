/**
 * Los dias que han pasado desde cierta fecha
 * @date 11-01-2012
 * @author Carlos Limeres
 * */
#include <dos.h>
#include <stdio.h>
int disig (int vect[3],float dias)
{
 float i;
 for (i=1;i<=dias;i++)
 {
  vect[0]=vect[0]+1;
  if (vect[0]==29)
  {
   if (vect[1]==2)
   {
    if ((vect[2]%4!=0)||(vect[2]%100==0))
    {
     vect[0]=1;
     vect[1]=3;
    }
   }
  }
  if (vect[0]==30)
  {
   if (vect[1]==2)
   {
    vect[0]=1;
    vect[1]=3;
   }
  }
  if (vect[0]==31)
  {
   if ((vect[1]==4)||(vect[1]==6)||(vect[1]==9)||(vect[1]==11))
   {
    vect[0]=1;
    vect[1]=vect[1]+1;
   }
  }
  if (vect[0]==32)
  {
   if (vect[1]==12)
   {
    vect[0]=1;
    vect[1]=1;
    vect[2]=vect[2]+1;
   }
   else
   {
    vect[0]=1;
    vect[1]=vect[1]+1;
   }
  }
 }
 return vect[3];
}
void main(void)
{
 struct date d;
 int vect[3],x;
 float dias;
 getdate(&d);
 vect[2]=d.da_year;
 vect[0]=d.da_day;
 vect[1]=d.da_mon;
 printf ("Dame los d¡as pasados a partir de hoy : ");
 scanf ("%f",&dias);
 printf ("Incluido el d¡a de hoy ? ");
 scanf ("%d",&x);
 printf ("Hoy es %02d/%02d/%d.\n",vect[0],vect[1],vect[2]);
 printf ("Dentro de %.0f d¡a",dias);
 if (dias>1)
 {
  printf ("s");
 }
 if (x!=0)
 {
  dias=dias-1;
 }
 vect[3]=disig (vect,dias);
 printf (" ser  %02d/%02d/%d.\n",vect[0],vect[1],vect[2]);
}
