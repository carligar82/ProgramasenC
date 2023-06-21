/**
 * Halla el máximo común divisor y el mínimo común múltiplo de los números que tu quieras, hasta intoducir el '0'
 * @date 29-06-2021
 * @author Carlos Limeres
 * */
#include <stdio.h>
#include <string.h>
#include <dir.h>
#include <dos.h>
#include <io.h>
#include <conio.h>
void cop (char a[80],char b[80])
{
 char f;
 FILE *f1,*f2;
 f1=fopen (a,"rb");
 f2=fopen (b,"wb");
 do
 {
  fread (&f,1,1,f1);
  if (feof(f1)==0)
  {
   fwrite (&f,1,1,f2);
  }
 }
 while (feof(f1)==0);
 fclose (f1);
 fclose (f2);
}
int div (float a,float b)
{
 int c;
 while (a>=b)
 {
  a=a-b;
 }
 if (a==0)
 {
  c=1;
 }
 else
 {
  c=0;
 }
 return c;
}
float primo (float a)
{
 float b,d=0;
 int c;
 for (b=1;b<=a;b++)
 {
  c=div (a,b);
  if (c==1)
  {
   d++;
  }
 }
 return d;
}
void factorizar (float numero)
{
 FILE *f1;
 int a,p,b;
 float numero2,y=1,x2=2;
 numero2=numero;
 f1=fopen ("factor","a");
 while (y<numero2)
 {
  p=0;
  b=primo (x2);
  if (b==2)
  {
   do
   {
    a=div(numero,x2);
    if (a==1)
    {
     p++;
     y=y*x2;
     numero=numero/x2;
    }
   }
   while (a==1);
  }
  if (p!=0)
  {
   fprintf (f1,"%fp%d ",x2,p);
  }
  x2++;
 }
 fclose (f1);
}
float MCD (int n)
{
 float a,b,MCD=1;
 int x,y,z=0,r=1;
 FILE *f1,*f2;
 cop ("factor","fijo");
 while (r!=0)
 {
  r=0;
  f1=fopen ("factor","r");
  f2=fopen ("facto","w");
  fscanf (f1,"%fp%d ",&a,&x);
  z=1;
  while (feof(f1)==0)
  {
   fscanf (f1,"%fp%d ",&b,&y);
   if (a!=b)
   {
    r++;
    fprintf (f2,"%fp%d ",b,y);
   }
   else
   {
    z++;
    if (y<x)
    {
     x=y;
    }
   }
  }
  fclose (f1);
  fclose (f2);
  if (z==n)
  {
   for (y=1;y<=x;y++)
   {
    MCD=MCD*a;
   }
  }
  cop ("facto","factor");
 }
 cop ("fijo","factor");
 remove ("fijo");
 remove ("facto");
 return MCD;
}
float MCM (int n)
{
 float a,b,MCM=1;
 int x,y,z=0,j,r;
 FILE *f1,*f2;
 for (j=n;j>=1;j--)
 {
  r=1;
  cop ("factor","fijo");
  while (r!=0)
  {
   r=0;
   f1=fopen ("factor","r");
   f2=fopen ("facto","w");
   fscanf (f1,"%fp%d ",&a,&x);
   z=1;
   while (feof(f1)==0)
   {
    fscanf (f1,"%fp%d ",&b,&y);
    if (a!=b)
    {
     r++;
     fprintf (f2,"%fp%d ",b,y);
    }
    else
    {
     z++;
     if (y>x)
     {
      x=y;
     }
    }
   }
   fclose (f1);
   fclose (f2);
   if (z==j)
   {
    for (y=1;y<=x;y++)
    {
     MCM=MCM*a;
    }
   }
   cop ("facto","factor");
  }
  cop ("fijo","factor");
 }
 remove ("factor");
 remove ("facto");
 remove ("fijo");
 return MCM;
}
void main (void)
{
 FILE *f1;
 int n,r=5;
 float numero,mcd,mcm;
 while (r!=0)
 {
  f1=fopen("numeros","w");
  n=0;
  do
  {
   printf ("Dame un n£mero: ");
   scanf ("%f",&numero);
   if (numero!=0)
   {
    n++;
    factorizar (numero);
    fprintf (f1,"%f ",numero);
   }
  }
  while (numero!=0);
  fclose (f1);
  if (n!=0)
  {
   mcd=MCD(n);
   mcm=MCM(n);
   f1=fopen ("numeros","r");
   printf ("M.C.D. (");
   do
   {
    fscanf (f1,"%f ",&numero);
    if (feof(f1)==0)
    {
     printf ("%.0f,",numero);
    }
   }
   while (feof(f1)==0);
   printf ("%.0f) = %.0f\n",numero,mcd);
   fclose (f1);
   f1=fopen ("numeros","r");
   printf ("M.C.M. (");
   do
   {
    fscanf (f1,"%f ",&numero);
    if (feof(f1)==0)
    {
     printf ("%.0f,",numero);
    }
   }
   while (feof(f1)==0);
   printf ("%.0f) = %.0f\n",numero,mcm);
   fclose (f1);
  }
  printf ("M s ? ");
  remove ("numeros");
  scanf ("%d",&r);
 }
}


