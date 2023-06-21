/**
 * Expresión de potencias hasta 17 de funciones tirgonométricas SEN o COS
 * @date 31-10-2020
 * @author Carlos Limeres
 * */
#include <stdio.h>
float fact (int num)
{
 if (num<=1)
 {
  return 1;
 }
 else
 {
  return (num*fact(num-1));
 }
}
int nc (int a,int b)
{
 float c,d,e;
 c=fact (a);
 d=fact (a-b);
 e=fact (b);
 return c/(d*e);
}
int signoi (int a)
{
 int i;
 int b=1;
 for (i=3;i<=a;i++)
 {
  b=b*(-1);
  i=i+1;
 }
 return (b);
}
int signor (int a)
{
 int i;
 int b=-1;
 for (i=4;i<=a;i++)
 {
  b=b*(-1);
  i=i+1;
 }
 return (b);
}
void cosp (int a)
{
 int i,b;
 for (i=2;i<=a-2;i++)
 {
  if (signor(i)==1)
  {
   printf ("-");
  }
  else
  {
   printf ("+");
  }
  b=nc (a,i);
  printf ("%dcos^%d(x)*sen^%d(x)",b,a-i,i);
  i=i+1;
 }
}
void cosi (int a)
{
 int i,b;
 for (i=2;i<=a-1;i++)
 {
  if (signor(i)==1)
  {
   printf ("-");
  }
  else
  {
   printf ("+");
  }
  b=nc (a,i);
  printf ("%dcos^%d(x)*sen^%d(x)",b,a-i,i);
  i=i+1;
 }
}
void senp (int a)
{
 int i,b;
 for (i=2;i<=a-2;i++)
 {
  if (signor(i)==1)
  {
   printf ("+");
  }
  else
  {
   printf ("-");
  }
  b=nc (a,i);
  printf ("%dcos^%d(x)*sen^%d(x)",b,a-i,i);
  i=i+1;
 }
}
void seni1 (int a)
{
 int i,b;
 for (i=1;i<=a-2;i++)
 {
  if (signoi(i)==1)
  {
   printf ("-");
  }
  else
  {
   printf ("+");
  }
  b=nc (a,i);
  printf ("%dcos^%d(x)*sen^%d(x)",b,a-i,i);
  i=i+1;
 }
}
void seni2 (int a)
{
 int i,b;
 for (i=1;i<=a-2;i++)
 {
  if (signoi(i)==1)
  {
   printf ("-");
  }
  else
  {
   printf ("+");
  }
  b=nc (a,i);
  printf ("%dcos^%d(x)*sen^%d(x)",b,a-i,i);
  i=i+1;
 }
}
void main (void)
{
 int c,a;
 do
 {
  printf ("Funci¢n:1-sen.\n");
  printf ("        2-cos.\n");
  scanf ("%d",&c);
  if ((c==1)||(c==2))
  {
   do
   {
    printf ("Potencia (hasta 17) : ");
    scanf ("%d",&a);
   }
   while (a>17);
   if (c==2)
   {
    if (a%2==0)
    {
     if (signor (a)==1)
     {
      printf ("cos^%d(x)=cos(%dx)-sen^%d(x)",a,a,a);
      cosp(a);
     }
     else
     {
      printf ("cos^%d(x)=cos(%dx)+sen^%d(x)",a,a,a);
      cosp(a);
     }
    }
    else
    {
     printf ("cos^%d(x)=cos(%dx)",a,a);
     cosi(a);
    }
   }  
   if (c==1)
   {
    if (a%2==0)
    {
     if (signor(a)==1) 
     {
      printf ("sen^%d(x)=cos%(dx)-cos^%d(x)",a,a,a);
      cosp(a);
     }
     else
     {
      printf ("sen^%d(x)=cos^%d(x)-cos(%dx)",a,a,a);
      senp(a);
     }
    }
    else
    {
     if (signoi(a)==1)
     {
      printf ("sen^%d(x)=sen(%dx)",a,a);
      seni1(a);
     }
     else
     {
      printf ("sen^%d(x)=",a);
      seni2(a);
      printf ("-sen(%dx)",a);
     }
    }
   }
  }
  printf ("\n\a");
 }
 while ((c==1)||(c==2));
}



