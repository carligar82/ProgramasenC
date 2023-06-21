/**
 * Organiza las tomas y la compra de tus medicinas
 * Manual de instrucciones y fichero de configuración disponibles en LinkedIn o pedir en https://www.facebook.com/carlos.limeres.7
 * @date 09-01-2012
 * @author Carlos Limeres
 * */
#include <dos.h>
#include <stdio.h>
int disig (int vect[3],int dias)
{
 int i;
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
void main (void)
{
 FILE *f1;
 struct date d;
 int vect[3],vect2[3];
 int dias,caja,dias2,a,b,x;
 char medicina[80];
 float di,df,dosis,pastillas,pastillas2,pd,dosis2;
 a=0;
 puts ("Abriendo cuadro de medicinas...");
 while (a==0)
 {
  caja=-1;
  x=0;
  printf ("Nombre de la medicina: ");
  fflush (stdin);
  gets (medicina);
  f1=fopen ("cuadro.txt","a");
  fprintf (f1,"*%s:\n\n",medicina);
  fclose (f1);
  b=1;
  while (b!=0)
  {
   f1=fopen ("cuadro.txt","a");
   caja=caja+1;
   if (caja==0)
   {
    printf ("Pastillas disponibles (si hay): ");
    scanf ("%f",&pd);
    if (pd==0)
    {
     caja=1;
    }
    else
    {
     pastillas=pd;
     pd=0;
    }
   }
   if (caja==1)
   {
    printf ("Pastillas por caja: ");
    scanf ("%f",&pastillas);
   }
   printf ("Pastillas al d¡a: ");
   scanf ("%f",&dosis);
   if (x==0)
   {
    puts ("Fecha de comienzo tratamiento:");
    printf ("D¡a: ");
    scanf ("%d",&vect[0]);
    if (vect[0]==0)
    {
     getdate(&d);
     vect[2]=d.da_year;
     vect[0]=d.da_day;
     vect[1]=d.da_mon;
    }
    else
    {
     printf ("Mes: ");
     scanf ("%d",&vect[1]);
     printf ("A¤o: ");
     scanf ("%d",&vect[2]);
    }
    printf ("Dosis que se toma el 1§ d¡a: ");
    scanf ("%f",&di);
   }
   else
   {
    di=dosis-df;
   }
   if (caja==-1)
   {
    pastillas=pd;
   }
   vect2[0]=vect[0];
   vect2[1]=vect[1];
   vect2[2]=vect[2];
   dosis2=(int)dosis;
   if (caja>=1)
   {
    fprintf (f1," Caja %d (%.0f pastillas tomando %.0f",caja,pastillas,dosis2);
    printf ("Caja %d (%.0f pastillas tomando %.0f",caja,pastillas,dosis2);
    dosis2=(dosis-dosis2)*100;
    if (dosis2>1)
    {
     fprintf (f1,"'%.0f",dosis2);
     printf ("'%.0f",dosis2);
    }
    fprintf (f1," pastilla");
    printf (" pastilla");
    if (dosis>1)
    {
     fprintf (f1,"s");
     printf ("s");
    }
    fprintf (f1,"/dia):\n");
    printf ("/d¡a):\n");
   }
   else
   {
    fprintf (f1," %.0f pastillas disponibles (%.0f",pastillas,dosis2);
    printf ("%.0f pastillas disponibles (%.0f",pastillas,dosis2);
    dosis2=(dosis-dosis2)*100;
    if (dosis2>1)
    {
     fprintf (f1,"'%.0f",dosis2);
     printf ("'%.0f",dosis2);
    }
    fprintf (f1," pastilla");
    printf (" pastilla");
    if (dosis>1)
    {
     fprintf (f1,"s");
     printf ("s");
    }
    fprintf (f1,"/dia):\n");
    printf ("/d¡a):\n");
   }
   if (di==0)
   {
    vect[3]=disig (vect,1);
   }
   pastillas2=pastillas-di;
   printf (" D¡as de tratamiento:%02d/%02d/%d a ",vect[0],vect[1],vect[2]);
   fprintf (f1,"  Dias de tratamiento:%02d/%02d/%d a ",vect[0],vect[1],vect[2]);
   dias=0;
   if (pastillas2!=0)
   {
    if (di!=0)
    {
     vect[3]=disig (vect,1);
    }
    while (pastillas2>dosis)
    {
     if (pastillas2>dosis)
     {
      pastillas2=pastillas2-dosis;
      dias=dias+1;
     }
    }
    vect[3]=disig (vect,dias);
   }
   df=pastillas2;
   dias2=dias-6;
   printf ("%02d/%02d/%d.\a\n",vect[0],vect[1],vect[2]);
   fprintf (f1,"%02d/%02d/%d.\n",vect[0],vect[1],vect[2]);
   if (dias2>0)
   {
    vect2[3]=disig (vect2,dias2);
    printf (" Fecha siguiente compra:%02d/%02d/%d.\n",vect2[0],vect2[1],vect2[2]);
    fprintf (f1,"  Fecha siguiente compra:%02d/%02d/%d.\n",vect2[0],vect2[1],vect2[2]);
   }
   fprintf (f1,"\n");
   fclose (f1);
   printf ("M s cajas ? ");
   scanf ("%d",&b);
   if (b!=0)
   {
    x++;
   }
  }
  printf ("Fin de escritura de cuadro ? ");
  scanf ("%d",&a);
 }
}
