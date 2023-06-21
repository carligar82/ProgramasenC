/**
 * Convierte un nº periódico (con infinitos decimales) en fracción
 * @date 29-06-2021
 * @author Carlos Limeres
 * */
#include <stdio.h>
#include <math.h>
#include <string.h>
int num (char f)
{
 int x=0;
 char e= '0';
 while (e!=f)
 {
  e++;
  x++;
 }
 return x;
}
double CAN (char cad[80])
{
 int i,j,l,k,x;
 double CAN=0;
 i=strlen (cad);
 k=i;
 for (j=0;j<=i-1;j++)
 {
  if (cad[j]=='.')
  {
   k=j;
  }
 }
 l=k-1;
 for (j=0;j<=i-1;j++)
 {
  if (j!=k)
  {
   x=num(cad[j]);
   CAN=CAN+x*pow(10,l);
   l=l-1;
  }
 }
 return CAN;
}
int div (double a,double b)
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
double MCD (double n,double min)
{
 double a,MCD=1,x;
 int y,z;
 for (x=min;x>=1;x--)
 {
  y=div (n,x);
  z=div (min,x);
  if ((y==1)&&(z==1))
  {
   MCD=x;
   x=0;
  }
 }
 return MCD;
}
int per (char decx[80])
{
 int d=0;
 FILE *f1;
 char dec[80],dec2[80],dec3[80],dec4[80];
 int aa,x,l,y,j,b;
 l=strlen(decx);
 strcpy (dec,decx);
 for (aa=0;aa<=l-2;aa++)
 {
  f1=fopen ("casa","w");
  for (b=aa;b<=l-1;b++)
  {
   fprintf (f1,"%c",dec[b]);
  }
  fclose (f1);
  f1=fopen ("casa","r");
  fscanf (f1,"%s",&dec2);
  fclose (f1);
  y=l-aa;
  for (j=1;j<=y-1;j++)
  {
   if (div(y,j)==1)
   {
    x=y/j;
    f1=fopen ("casa","w");
    for (b=0;b<=j-1;b++)
    {
     fprintf (f1,"%c",dec2[b]);
    }
    fclose (f1);
    f1=fopen ("casa","r");
    fscanf (f1,"%s",&dec3);
    fclose (f1);
    strcpy (dec4,dec3);
    for (b=2;b<=x;b++)
    {
     strcat (dec4,dec3);
    }
    b=strcmp (dec2,dec4);
    if (b==0)
    {
     f1=fopen ("casa","w");
     fprintf (f1,"%d",aa);
     fclose (f1);
     d=j;
     j=y+1;
     aa=l-1;
    }
   }
  }
 }
 return d;
}
void main (void)
{
 int d,a,s=0,c=1;
 double x,den,num,mcd;
 FILE *f1;
 char dec[80];
 while (c!=0)
 {
  printf ("Dame el n£mero peri¢dico : ");
  scanf ("%s",&dec);
  x=CAN(dec);
  f1=fopen ("casa","w");
  for (a=0;a<=strlen(dec)-1;a++)
  {
   if (s==1)
   {
    fprintf (f1,"%c",dec[a]);
   }
   if (dec[a]=='.')
   {
    s=1;
   }
  }
  fclose (f1);
  s=0;
  f1=fopen ("casa","r");
  fscanf (f1,"%s",&dec);
  fclose (f1);
  d=per(dec);
  f1=fopen ("casa","r");
  fscanf (f1,"%d",&a);
  fclose (f1);
  remove ("casa");
  if (d==0)
  {
   puts ("Error.");
  }
  else
  {
   den=pow(10,d+a)-pow(10,a);
   num=x*den;
   mcd=MCD(num,den);
   den=den/mcd;
   num=num/mcd;
   printf ("La fracci¢n generatriz del n£mero %.4lf es :\n",x);
   printf ("%.0lf/%.0lf\n",num,den);
  }
  printf ("Alg£n n£mero m s ? ");
  scanf ("%d",&c);
 }
}