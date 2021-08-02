//MINI PROJECT ON SERVICES OF A GENERAL STORE
#include<stdio.h>
#include<string.h>
int totitems;
//structures to store all the items based on different categories 
struct medical
{
  char item_name[20];
  char item_no[10];
  int p, q;
  float dp;
};

struct grocery
{
  char item_name[20];
  char item_no[10];
  int p, q;
  float dp;
};

struct cosmetics
{
  char item_name[20];
  char item_no[10];
  int p, q;
  float dp;
};

struct daily_essential
{
  char item_name[20];
  char item_no[10];
  int p, q;
  float dp;
};

struct stationery
{
  char item_name[20];
  char item_no[10];
  int p, q;
  float dp;
};

struct general
{
  struct medical m[10];
  struct grocery g[10];
  struct cosmetics c[10];
  struct daily_essential d[10];
  struct stationery s[10];
} item;
//function to store all the items
void stock (struct general *item);
//function to display all the items
void display (struct general *item);
//function for coupon code
float offer (struct general *item, float b);
//functions to calculate bill amount
float medical_bill (struct general *item);
float grocery_bill (struct general *item);
float cosmetics_bill (struct general *item);
float daily_essential_bill (struct general *item);
float stationery_bill (struct general *item);
//function to pay bill on cash
void bill (float bi);
//function to ship to an address
void ship (float bi);
//function to take review from the customer
void review ();
void file (struct general *item);
//---------------------------main---------------------
int
main ()
{
  int j, n;
  float mb, gb, cb, db, sb, tot;
  struct general *ptr;
  FILE *dis;
  ptr = &item;
  printf ("\tWELCOME TO OUR GENERAL STORE \n");
  stock (&item);
  display (&item);
  printf ("EXCLUSIVE 5 percent DISCOUNTS ON TOMATOES AND NAIL POLISH \n");
  printf
    ("10 PERCENT DISCOUNTS ON THERMOMETER, HAIRGEL, CANOLA OIL AND CALCULATORS\n\n");

  mb = medical_bill (&item);
  gb = grocery_bill (&item);
  cb = cosmetics_bill (&item);
  db = daily_essential_bill (&item);
  sb = stationery_bill (&item);
  tot = mb + gb + cb + db + sb;
  printf ("\nBILL:\nTOTAL NUMBER OF ITEMS PURCHASED=%d\n", totitems);
  printf ("TOTAL PRICE=%f\n", tot);
  tot = offer (&item, tot);

  printf ("How do you want to take your Items?\n");
  printf ("1.At the Counter\n2.To Ship them to an address\n\t");
  scanf ("%d", &n);
  if (n == 1)
    {
      bill (tot);
    }
  else
    {
      ship (tot);
    }

  review ();
  dis = fopen ("display.txt", "w");
  if (dis == NULL)
    printf ("file doesn't exist\n");
  else
    {
      fprintf (dis, "   MEDICAL PRODUCTS:  \n");
      for (j = 0; j < 5; j++)
	fprintf (dis, "quantity of %s=%d\n", item.m[j].item_name,
		 item.m[j].q);

      fprintf (dis, "\n");

      fprintf (dis, "   GROCERY PRODUCTS:  \n");
      for (j = 0; j < 5; j++)
	fprintf (dis, "quantity of %s=%d\n", item.g[j].item_name,
		 item.g[j].q);

      fprintf (dis, "\n");


      fprintf (dis, "   COSMETIC PRODUCTS:  \n");
      for (j = 0; j < 5; j++)
	fprintf (dis, "quantity of %s= %d\n", item.c[j].item_name,
		 item.c[j].q);
      fprintf (dis, "\n");


      fprintf (dis, "   DAILY ESSENTIALS:  \n");
      for (j = 0; j < 5; j++)
	fprintf (dis, "quantity of %s=%d \n", item.d[j].item_name,
		 item.d[j].q);
      fprintf (dis, "\n");

      fprintf (dis, "   STATIONERY PRODUCTS:  \n");
      for (j = 0; j < 5; j++)
	fprintf (dis, "quantity of %s=%d\n", item.s[j].item_name,
		 item.s[j].q);
      fprintf (dis, "\n");
    }
  fclose (dis);


  return 0;
}
//---------------------------stock:to define all the stock---------------------
void
stock (struct general *ptr)
{
  strcpy (item.m[0].item_name, "Syringes");
  strcpy (item.m[0].item_no, "m1");
  item.m[0].p = 20;
  item.m[0].q = 20;
  item.m[0].dp = item.m[0].p;

  strcpy (item.m[1].item_name, "Thermometer");
  strcpy (item.m[1].item_no, "m2");
  item.m[1].p = 60;
  item.m[1].q = 10;
  item.m[1].dp = item.m[1].p - item.m[1].p / 10.0;

  strcpy (item.m[2].item_name, "Aspro_Tablet");
  strcpy (item.m[2].item_no, "m3");
  item.m[2].p = 10;
  item.m[2].q = 50;
  item.m[2].dp = item.m[2].p;

  strcpy (item.m[3].item_name, "paracetamol");
  strcpy (item.m[3].item_no, "m4");
  item.m[3].p = 40;
  item.m[3].q = 25;
  item.m[3].dp = item.m[3].p;

  strcpy (item.m[4].item_name, "Rapid_Insulin");
  strcpy (item.m[4].item_no, "m5");
  item.m[4].p = 50;
  item.m[4].q = 15;
  item.m[4].dp = item.m[4].p;


  strcpy (item.g[0].item_name, "Madhur_Sugar");
  strcpy (item.g[0].item_no, "g1");
  item.g[0].p = 50;
  item.g[0].q = 15;
  item.g[0].dp = item.g[0].p;

  strcpy (item.g[1].item_name, "Basmati_Rice");
  strcpy (item.g[1].item_no, "g2");
  item.g[1].p = 100;
  item.g[1].q = 20;
  item.g[1].dp = item.g[1].p;

  strcpy (item.g[2].item_name, "Canol_Oil");
  strcpy (item.g[2].item_no, "g3");
  item.g[2].p = 80;
  item.g[2].q = 40;
  item.g[2].dp = item.g[2].p - item.g[2].p / 10.0;

  strcpy (item.g[3].item_name, "Tomatoes");
  strcpy (item.g[3].item_no, "g4");
  item.g[3].p = 30;
  item.g[3].q = 30;
  item.g[3].dp = item.g[3].p - item.g[3].p / 20.0;

  strcpy (item.g[4].item_name, "potatoes");
  strcpy (item.g[4].item_no, "g5");
  item.g[4].p = 20;
  item.g[4].q = 60;
  item.g[4].dp = item.g[4].p;

  strcpy (item.c[0].item_name, "Lakme_Cream");
  strcpy (item.c[0].item_no, "c1");
  item.c[0].p = 25;
  item.c[0].q = 15;
  item.c[0].dp = item.c[0].p;

  strcpy (item.c[1].item_name, "Nail_Polish");
  strcpy (item.c[1].item_no, "c2");
  item.c[1].p = 15;
  item.c[1].q = 30;
  item.c[1].dp = item.c[1].p - item.c[1].p / 10.0;

  strcpy (item.c[2].item_name, "Hair_Gel");
  strcpy (item.c[2].item_no, "c3");
  item.c[2].p = 65;
  item.c[2].q = 20;
  item.c[2].dp = item.c[2].p;

  strcpy (item.c[3].item_name, "Body_Lotion");
  strcpy (item.c[3].item_no, "c4");
  item.c[3].p = 30;
  item.c[3].q = 50;
  item.c[3].dp = item.c[3].p;

  strcpy (item.c[4].item_name, "Lip_Balm");
  strcpy (item.c[4].item_no, "c5");
  item.c[4].p = 5;
  item.c[4].q = 40;
  item.c[4].dp = item.c[4].p - item.c[4].p / 20.0;

  strcpy (item.d[0].item_name, "Tooth_brush");
  strcpy (item.d[0].item_no, "d1");
  item.d[0].p = 25;
  item.d[0].q = 30;
  item.d[0].dp = item.d[0].p;

  strcpy (item.d[1].item_name, "   Milk");
  strcpy (item.d[1].item_no, "d2");
  item.d[1].p = 20;
  item.d[1].q = 30;
  item.d[1].dp = item.d[1].p;

  strcpy (item.d[2].item_name, "Shampoo");
  strcpy (item.d[2].item_no, "d3");
  item.d[2].p = 5;
  item.d[2].q = 40;
  item.d[2].dp = item.d[2].p;

  strcpy (item.d[3].item_name, "    Soaps");
  strcpy (item.d[3].item_no, "d4");
  item.d[3].p = 20;
  item.d[3].q = 50;
  item.d[3].dp = item.d[3].p;

  strcpy (item.d[4].item_name, "Tooth_paste");
  strcpy (item.d[4].item_no, "d5");
  item.d[4].p = 10;
  item.d[4].q = 40;
  item.d[4].dp = item.d[4].p;

  strcpy (item.s[0].item_name, "     Books");
  strcpy (item.s[0].item_no, "s1");
  item.s[0].p = 30;
  item.s[0].q = 80;
  item.s[0].dp = item.s[0].p;

  strcpy (item.s[1].item_name, "      Pens");
  strcpy (item.s[1].item_no, "s2");
  item.s[1].p = 5;
  item.s[1].q = 100;
  item.s[1].dp = item.s[1].p;

  strcpy (item.s[2].item_name, "Calculator");
  strcpy (item.s[2].item_no, "s3");
  item.s[2].p = 120;
  item.s[2].q = 30;
  item.s[2].dp = item.s[2].p - item.s[2].p / 10.0;

  strcpy (item.s[3].item_name, "Envelopes");
  strcpy (item.s[3].item_no, "s4");
  item.s[3].p = 5;
  item.s[3].q = 50;
  item.s[3].dp = item.s[3].p;

  strcpy (item.s[4].item_name, "      Dolls");
  strcpy (item.s[4].item_no, "s5");
  item.s[4].p = 150;
  item.s[4].q = 10;
  item.s[4].dp = item.s[4].p;

}
//---------------------------display:to display all the items---------------------
void
display (struct general *ptr)
{
  int j;
  printf ("   MEDICAL PRODUCTS:  \n");
  printf ("itemname        item no  price  quantity price_after_discount \n");
  for (j = 0; j < 5; j++)
    printf (" %s\t %s %10d %10d %10f \n", item.m[j].item_name,
	    item.m[j].item_no, item.m[j].p, item.m[j].q, item.m[j].dp);

  printf ("\n");

  printf ("   GROCERY PRODUCTS:  \n");
  printf ("itemname        item no  price  quantity price_after_discount \n");
  for (j = 0; j < 5; j++)
    printf (" %s\t %s %10d %10d %10f \n", item.g[j].item_name,
	    item.g[j].item_no, item.g[j].p, item.g[j].q, item.g[j].dp);

  printf ("\n");


  printf ("   COSMETIC PRODUCTS:  \n");
  printf ("itemname        item no  price  quantity price_after_discount \n");
  for (j = 0; j < 5; j++)
    printf (" %s\t %s %10d %10d %10f \n", item.c[j].item_name,
	    item.c[j].item_no, item.c[j].p, item.c[j].q, item.c[j].dp);
  printf ("\n");


  printf ("   DAILY ESSENTIALS:  \n");
  printf ("itemname        item no  price  quantity price_after_discount \n");
  for (j = 0; j < 5; j++)
    printf (" %s\t %s %10d %10d %10f \n", item.d[j].item_name,
	    item.d[j].item_no, item.d[j].p, item.d[j].q, item.d[j].dp);
  printf ("\n");

  printf ("   STATIONERY PRODUCTS:  \n");
  printf ("itemname        item no  price  quantity price_after_discount \n");
  for (j = 0; j < 5; j++)
    printf (" %s\t %s %10d %10d %10f \n", item.s[j].item_name,
	    item.s[j].item_no, item.s[j].p, item.s[j].q, item.s[j].dp);
  printf ("\n");


  return;
}
//---------------------------offer:for coupon codes---------------------
float
offer (struct general *ptr, float b)
{
  int x, y, i = 0, x1;
  printf
    ("\n Would you like to avail some discount on your bill using coupon code? \n");
label1:printf ("type \n 1.YES \n 2.NO\n");
  scanf ("%d", &x);
  if (x != 1 && x != 2)
    {
      printf (" \nINVALID INPUT \n");
      goto label1;
    }
  if (x == 2)
    {
      printf ("Your bill amount is %f \n ", b);
      return b;
    }
  if (x == 1)
    {
    label:printf ("\n Enter your 5 digit coupon code \n ");
      scanf ("%d", &y);
      if (y == 12345 || y == 13579 || y == 24680 || y == 98765)
	{
	  printf
	    ("\n You have availed a discount of 20 percent through your coupon code \n");
	  b = b - b / 5;
	  printf ("The bill amount is %f\n", b);
	  return b;
	}
      else
	{
	  if (i == 0 || i == 1)
	    {
	      printf ("INVALID coupon code \n");
	    label2:printf ("WOULD YOU LIKE TO TRY AGAIN? \n");
	      printf ("type \n 1.YES \n 2.NO\n ");
	      scanf ("%d", &x1);
	      if (x1 != 1 && x1 != 2)
		{
		  printf ("\n INVALID INPUT \n");
		  goto label2;
		}
	      if (x1 == 1)
		{
		  i++;
		  goto label;
		}
	      else
		{
		  printf ("Your bill amount is %f", b);
		  return b;
		}
	    }
	  printf
	    ("\nYou have inputed wrong code 3 times in a row \n.You cannot use your coupon code again to avail benefits \n");
	  printf (" \n Your bill amount is %f", b);
	  return b;
	}
    }
}
//---------------------------medical_bill---------------------
float
medical_bill (struct general *ptr)
{
  char name[2];
  int a, b, c, d, e, n, i;
  float bill = 0;
label6:
  printf
    ("Enter number of items if you want to buy in medical else enter 0: ");
  scanf ("%d", &n);
  totitems = n;
  if (n == 0)
    return bill;
  else if (n > 5)
    {
      printf ("please enter valid number\n");
      goto label6;
    }
  else
  label:
    {
      for (i = 0; i < n; i++)
	{
	  printf ("Enter item number %d you would like to buy in medical: ",
		  i + 1);
	  scanf ("%s", name);
	  if (strcmp (name, "m1") != 0 && strcmp (name, "m2") != 0
	      && strcmp (name, "m3") != 0 && strcmp (name, "m4") != 0
	      && strcmp (name, "m5") != 0)
	    {
	      printf ("please enter valid item number\n");
	      goto label;
	    }
	  else if (strcmp (name, "m1") == 0)
	    {
	    label1:
	      printf ("Enter quantity of syringes: ");
	      scanf ("%d", &a);
	      if (a > item.m[0].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label1;
		}
	      else
		{
		  bill = bill + a * 20;
		  item.m[0].q -= a;
		}
	    }
	  else if (strcmp (name, "m2") == 0)
	    {
	    label2:
	      printf ("Enter quantity of thermometers: ");
	      scanf ("%d", &b);
	      if (b > item.m[1].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label2;
		}
	      else
		{
		  bill = bill + b * 57;
		  item.m[1].q -= b;
		}
	    }
	  else if (strcmp (name, "m3") == 0)
	    {
	    label3:
	      printf ("Enter quantity of Aspro tablets: ");
	      scanf ("%d", &c);
	      if (c > item.m[2].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label3;
		}
	      else
		{
		  bill = bill + c * 10;
		  item.m[2].q -= c;
		}
	    }
	  else if (strcmp (name, "m4") == 0)
	    {
	    label4:
	      printf ("Enter quantity of Paracetamol: ");
	      scanf ("%d", &d);
	      if (d > item.m[3].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label4;
		}
	      else
		{
		  bill = bill + d * 40;
		  item.m[3].q -= d;
		}
	    }
	  else if (strcmp (name, "m5") == 0)
	    {
	    label5:
	      printf ("Enter quantity of Rapid Insulin: ");
	      scanf ("%d", &e);
	      if (e > item.m[4].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label5;
		}
	      else
		{
		  bill = bill + e * 50;
		  item.m[4].q -= e;
		}
	    }
	}
      return bill;
    }
}

//---------------------------grocery_bill---------------------

float
grocery_bill (struct general *ptr)
{
  char name[2];
  int n, i;
  float bill = 0, a, b, c, d, e;
label6:
  printf
    ("Enter number of items if you want to buy in grocery else enter 0: ");
  scanf ("%d", &n);
  totitems += n;
  if (n == 0)
    return bill;
  else if (n > 5)
    {
      printf ("please enter valid number\n");
      goto label6;
    }
  else
  label:
    {
      for (i = 0; i < n; i++)
	{
	  printf ("Enter item number %d you would like to buy in grocery: ",
		  i + 1);
	  scanf ("%s", name);
	  if (strcmp (name, "g1") != 0 && strcmp (name, "g2") != 0
	      && strcmp (name, "g3") != 0 && strcmp (name, "g4") != 0
	      && strcmp (name, "g5") != 0)
	    {
	      printf ("please enter valid item number\n");
	      goto label;
	    }
	  else if (strcmp (name, "g1") == 0)
	    {
	    label1:
	      printf ("Enter quantity of Madhur sugar(in kgs): ");
	      scanf ("%f", &a);
	      if (a > item.g[0].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label1;
		}
	      else
		{
		  bill = bill + a * 50;
		  item.g[0].q -= a;
		}
	    }
	  else if (strcmp (name, "g2") == 0)
	    {
	    label2:
	      printf ("Enter quantity of Basmati rice(in kgs): ");
	      scanf ("%f", &b);
	      if (b > item.g[1].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label2;
		}
	      else
		{
		  bill = bill + b * 60;
		  item.g[1].q -= b;
		}
	    }
	  else if (strcmp (name, "g3") == 0)
	    {
	    label3:
	      printf ("Enter quantity of canol oil(in litres): ");
	      scanf ("%f", &c);
	      if (c > item.g[2].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label3;
		}
	      else
		{
		  bill = bill + c * 72;
		  item.g[2].q -= c;
		}
	    }
	  else if (strcmp (name, "g4") == 0)
	    {
	    label4:
	      printf ("Enter quantity of tomatoes(in kgs): ");
	      scanf ("%f", &d);
	      if (d > item.g[3].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label4;
		}
	      else
		{
		  bill = bill + d * 28.5;
		  item.g[3].q -= d;
		}
	    }
	  else if (strcmp (name, "g5") == 0)
	    {
	    label5:
	      printf ("Enter quantity of Potatoes(in kgs): ");
	      scanf ("%f", &e);
	      if (e > item.g[4].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label5;
		}
	      else
		{
		  bill = bill + e * 20;
		  item.g[4].q -= e;
		}
	    }
	}
      return bill;
    }
}

//---------------------------cosmetics_bill---------------------
float
cosmetics_bill (struct general *ptr)
{
  char name[2];
  int a, b, c, d, e, i, n;
  float bill = 0;
label6:
  printf
    ("Enter number of items if you want to buy in cosmetics else enter 0: ");
  scanf ("%d", &n);
  totitems += n;
  if (n == 0)
    return bill;
  else if (n > 5)
    {
      printf ("please enter valid number\n");
      goto label6;
    }
  else
  label:
    {
      for (i = 0; i < n; i++)
	{
	  printf ("Enter item number %d in cosmetics: ", i + 1);
	  scanf ("%s", name);
	  if (strcmp (name, "c1") != 0 && strcmp (name, "c2") != 0
	      && strcmp (name, "c3") != 0
	      && strcmp (name, "c4") != 0 && strcmp (name, "c5") != 0)
	    {
	      printf ("please enter valid item number\n");
	      goto label;
	    }
	  else if (strcmp (name, "c1") == 0)
	    {
	    label1:
	      printf ("Enter quantity of Lakme cream: ");
	      scanf ("%d", &a);
	      if (a > item.c[0].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label1;
		}
	      else
		{
		  bill += a * 25;
		  item.c[0].q -= a;
		}
	    }
	  else if (strcmp (name, "c2") == 0)
	    {
	    label2:
	      printf ("Enter quantity of Nail Polish: ");
	      scanf ("%d", &b);
	      if (b > item.c[0].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label2;
		}
	      else
		{
		  bill += b * 13.5;
		  item.c[0].q -= b;
		}
	    }
	  else if (strcmp (name, "c3") == 0)
	    {
	    label3:
	      printf ("Enter quantity of Hair gel: ");
	      scanf ("%d", &c);
	      if (c > item.c[2].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label3;
		}
	      else
		{
		  bill += c * 65;
		  item.c[2].q -= c;
		}
	    }
	  else if (strcmp (name, "c4") == 0)
	    {
	    label4:
	      printf ("Enter quantity of Body lotion: ");
	      scanf ("%d", &d);
	      if (d > item.c[3].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label4;
		}
	      else
		{
		  bill += d * 30;
		  item.c[3].q -= d;
		}
	    }
	  else if (strcmp (name, "c5") == 0)
	    {
	    label5:
	      printf ("Enter quantity of Lip balm: ");
	      scanf ("%d", &e);
	      if (e > item.c[4].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label5;
		}
	      else
		{
		  bill += e * 4.75;
		  item.c[4].q -= e;
		}
	    }
	}
      return bill;
    }
}

//---------------------------daily_essential_bill---------------------
float
daily_essential_bill (struct general *ptr)
{
  char name[2];
  int a, c, d, e, i, n;
  float bill = 0, b;
label6:
  printf
    ("Enter number of items if you want to buy in daily essentials else enter 0: ");
  scanf ("%d", &n);
  totitems += n;
  if (n == 0)
    return bill;
  else if (n > 5)
    {
      printf ("please enter valid number\n");
      goto label6;
    }
  else
  label:
    {
      for (i = 0; i < n; i++)
	{
	  printf ("Enter item number %d: ", i + 1);
	  scanf ("%s", name);
	  if (strcmp (name, "d1") != 0
	      && strcmp (name, "d2") != 0
	      && strcmp (name, "d3") != 0
	      && strcmp (name, "d4") != 0 && strcmp (name, "d5") != 0)
	    {
	      printf ("please enter valid item number\n");
	      goto label;
	    }
	  else if (strcmp (name, "d1") == 0)
	    {
	    label1:
	      printf ("Enter quantity of Tooth brushes: ");
	      scanf ("%d", &a);
	      if (a > item.d[0].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label1;
		}
	      else
		{
		  bill += a * 25;
		  item.d[0].q -= a;
		}
	    }
	  else if (strcmp (name, "d2") == 0)
	    {
	    label2:
	      printf ("Enter quantity of Milk(in litres): ");
	      scanf ("%f", &b);
	      if (b > item.d[1].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label2;
		}
	      else
		{
		  bill += b * 20;
		  item.d[1].q -= b;
		}
	    }
	  else if (strcmp (name, "d3") == 0)
	    {
	    label3:
	      printf ("Enter quantity of shampoo packets: ");
	      scanf ("%d", &c);
	      if (c > item.d[2].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label3;
		}
	      else
		{
		  bill += c * 5;
		  item.d[2].q -= c;
		}
	    }
	  else if (strcmp (name, "d4") == 0)
	    {
	    label4:
	      printf ("Enter quantity of Soaps: ");
	      scanf ("%d", &d);
	      if (d > item.d[3].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label4;
		}
	      else
		{
		  bill += d * 20;
		  item.d[3].q -= d;
		}
	    }
	  else if (strcmp (name, "d5") == 0)
	    {
	    label5:
	      printf ("Enter quantity of Tooth pastes: ");
	      scanf ("%d", &e);
	      if (e > item.d[4].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label5;
		}
	      else
		{
		  bill += e * 10;
		  item.d[4].q -= e;
		}
	    }
	}
      return bill;
    }
}
//---------------------------stationary_bill---------------------

float
stationery_bill (struct general *ptr)
{
  char name[2];
  int a, b, c, d, e, i, n;
  float bill = 0;
label6:
  printf
    ("Enter number of items if you want to buy in stationery else enter 0: ");
  scanf ("%d", &n);
  totitems += n;
  if (n == 0)
    return bill;
  else if (n > 5)
    {
      printf ("please enter valid number\n");
      goto label6;
    }
  else
  label:
    {
      for (i = 0; i < n; i++)
	{
	  printf ("Enter item number %d in stationery: ", i + 1);
	  scanf ("%s", name);
	  if (strcmp (name, "s1") != 0
	      && strcmp (name, "s2") != 0
	      && strcmp (name, "s3") != 0
	      && strcmp (name, "s4") != 0 && strcmp (name, "s5") != 0)
	    {
	      printf ("please enter valid item number\n");
	      goto label;
	    }
	  else if (strcmp (name, "s1") == 0)
	    {
	    label1:
	      printf ("Enter quantity of Books: ");
	      scanf ("%d", &a);
	      if (a > item.s[0].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label1;
		}
	      else
		{
		  bill += a * 30;
		  item.s[0].q -= a;
		}
	    }
	  else if (strcmp (name, "s2") == 0)
	    {
	    label2:
	      printf ("Enter quantity of pens: ");
	      scanf ("%d", &b);
	      if (b > item.s[1].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label2;
		}
	      else
		{
		  bill += b * 5;
		  item.s[1].q -= b;
		}
	    }
	  else if (strcmp (name, "s3") == 0)
	    {
	    label3:
	      printf ("Enter quantity of calculators: ");
	      scanf ("%d", &c);
	      if (c > item.s[2].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label3;
		}
	      else
		{
		  bill += c * 120;
		  item.s[2].q -= c;
		}
	    }
	  else if (strcmp (name, "s4") == 0)
	    {
	    label4:
	      printf ("Enter quantity of Envelopes: ");
	      scanf ("%d", &d);
	      if (d > item.s[3].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label4;
		}
	      else
		{
		  bill += d * 5;
		  item.s[3].q -= d;
		}
	    }
	  else if (strcmp (name, "s5") == 0)
	    {
	    label5:
	      printf ("Enter quantity of Dolls: ");
	      scanf ("%d", &e);
	      if (e > item.s[4].q)
		{
		  printf ("please enter valid quantity\n");
		  goto label5;
		}
	      else
		{
		  bill += e * 150;
		  item.s[4].q -= e;
		}
	    }
	}
      return bill;
    }
}

//---------------------------bill---------------------

void
bill (float bi)
{
  int a, b, c, d, e;
  float cash;
  printf ("The amount to be paid is %f\n", bi);
  printf ("Enter the cash\n");
  printf ("Number of 50's ");
  scanf ("%d", &a);
  printf ("Number of 100's ");
  scanf ("%d", &b);
  printf ("Number of 200's ");
  scanf ("%d", &c);
  printf ("Number of 500's ");
  scanf ("%d", &d);
  printf ("Number of 2000's ");
  scanf ("%d", &e);
  cash = ((a * 50) + (b * 100) + (c * 200) + (d * 500) + (e * 2000));
  if (cash > bi)
    printf ("Please collect your change %f and your items at the counter\n",
	    cash - bi);
  else if (cash == bi)
    printf
      ("The total bill is paid and Please collect your items at the counter\n");
  else
    {
      printf ("The total bill amount is not paid\n Please pay again\n");
      bi = (bi - cash);
      bill (bi);
    }
}
//---------------------------ship:to ship items to an address---------------------
void
ship (float bi)
{
  int n, i;
  char name[100];
  long int pin;
  long long int num;
  struct address
  {
    int flat;
    char street[100];
    char city[100];
    char state[100];
  } st;
  struct expdate
  {
    int m;
    int y;
  };
  struct credit
  {
    long long int number;
    struct expdate e;
    int cvv[3];
  } cd;
  printf ("Enter the delivery Address:\n");
  printf ("Enter your full name: ");
  scanf ("%s", name);
  printf ("Flat no.: ");
  scanf ("%d", &st.flat);
  printf ("Street: ");
  scanf ("%s", st.street);
  printf ("City: ");
  scanf ("%s", st.city);
  printf ("State: ");
  scanf ("%s", st.state);
  printf ("Enter your pincode\n");
  scanf ("%ld", &pin);
label11:
  printf ("Enter your 10 digit mobile number\n");
  scanf ("%lld", &num);
  if ((num <= 1000000000) || (num >= 9999999999))
    goto label11;
  printf ("Total payable amount is %f\n", bi);
  printf ("1.Cash On Delivery\n2.Credit Card Payment\n\t");
  scanf ("%d", &n);
  if (n == 1)
    {
      printf ("The items will be delivered to the  given address\n");
      printf ("Expected Delivery: 2-3 days\n");
    }
  else
    {
    label:printf ("Enter the 16-digit credit card number\n");
      scanf ("%lld", &cd.number);
      printf ("Enter the expiry date\n");
      printf ("Month: ");
      scanf ("%d", &cd.e.m);
      printf ("Year: ");
      scanf ("%d", &cd.e.y);
    label15:printf ("Enter the CVV code\n");
      for (i = 0; i < 3; i++)
	{
	  scanf ("%d", &cd.cvv[i]);
	  if ((cd.cvv[i] < 0) || (cd.cvv[i] > 9))
	    {
	      printf ("Please Enter single digit at a time\n");
	      goto label15;
	    }
	}
      {
	if (((cd.number >= 1000000000000000)
	     && (cd.number <= 9999999999999999)) && ((cd.e.m > 0)
						     && (cd.e.m < 13))
	    && (sizeof (cd.cvv) == 12))
	  {
	    printf
	      ("We Will Check the given details and send a message to the given numnber with trcaking link of the order\n");
	    printf ("Expected Delivery:2-3 days\n");
	  }
	else
	  {
	    printf ("Please enter valid details\n");
	    goto label;
	  }
      }
    }
}
//---------------------------review:to take review from customer---------------------
void
review ()
{
  int i, k, m;
  char s[1000];
  float j;
  printf ("Can you spend your esteemed time by giving a rating\n");

label2:
  printf ("Press 1 for yes and 2 for no\n");
  scanf ("%d", &m);
  if (m == 1)
    {
    label1:
      {
	printf ("please give a rating between 0 to 5 for our service.\n");
	scanf ("%f", &j);
	if ((j >= 0) && (j <= 2))
	  {
	    printf
	      ("I am so sorry for such a bad experience,can you please write what was your problem.\n");
	    scanf ("%s", s);
	  }
	else if ((j > 2) && (j <= 4))
	  {
	    printf
	      ("It looks like you are ok with your experience.Please suggest some improvements to make it even more better.\n");
	    scanf ("%s", s);

	  }
	else if ((j > 4) && (j <= 5))
	  {
	    printf
	      ("Thank you so much for an outstanding rating.Please suggest some improvements to make it even more better.\n");
	    scanf ("%s", s);
	  }
	else
	  {
	    printf ("Enter a valid rating.\n");
	    goto label1;
	  }
      }

      printf ("\tTHANKS FOR VISITING OUR STORE\n\t   SEE YOU AGAIN.\n");
    }
  else if (m == 2)
    {
      printf ("\tTHANKS FOR VISITING OUR STORE\n\t   SEE YOU AGAIN.\n");
    }
  else
    {
      printf ("please enter 1 or 2 \n");
      goto label2;
    }
}


