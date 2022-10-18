#include <stdio.h>

#define MaxDegree 100
#define NUM 100


typedef struct
{
  int CoeffArray[MaxDegree + 1];
  int HighPower;
} Polynomial;



void ZeroPolynomial(Polynomial *Poly)
{
  int i;
  for (i = 0; i <= MaxDegree; i++){
   Poly->CoeffArray[i] = 0;
   Poly->HighPower = 0;
  }
}


void InputPolynomial(Polynomial *Poly)
{
  int Coeff = 0, Power = 0;
  ZeroPolynomial(Poly);
  while (scanf("%d %d", &Coeff, &Power) && Power >= 0)
  {
    Poly->CoeffArray[Power] = Coeff;
    if (Poly->HighPower < Power){
      Poly->HighPower = Power;
    }
  }
}



void PrintPolynomial(Polynomial Poly)
{
  int i;
  printf("[ %d %d ]", Poly.CoeffArray[Poly.HighPower], Poly.HighPower);
  for(i = Poly.HighPower - 1; i >= 0; i--)
  if(Poly.CoeffArray[i] != 0)
    printf(" [ %d %d ]", Poly.CoeffArray[i], i);
  printf("\n");
}



void AddPolynomial(const Polynomial *Poly1, const Polynomial *Poly2, Polynomial *PolySum)
{
  int i;
  ZeroPolynomial(PolySum);
  if (Poly1->HighPower < Poly2->HighPower) /*确定最高位*/
    PolySum->HighPower = Poly2->HighPower;
  else
    PolySum->HighPower = Poly1->HighPower;

  for (i = PolySum->HighPower; i >= 0; i--){
    PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
  }
}


int main()
{
  Polynomial Poly[2 * NUM];
  Polynomial PolySum[NUM];


  int n;
  scanf("%d", &n);

  int i;

  for (i = 0; i < 2 * n; i++){
    InputPolynomial(&Poly[i]);
  }


  for (i = 0; i < n; i++)
  {
     AddPolynomial(&Poly[2 * i], &Poly[2 * i + 1], &PolySum[i]);
     PrintPolynomial(PolySum[i]);
  }

  return 0;
}
