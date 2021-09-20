int factorBasic(int n,  double *a, int LDA ){
  int k=0;
  double piv=a[0];
  const double minpiv=1e-6;
  while((fabs(piv)>minpiv) && (k<n-1))
  {
      for(int i=k+1; i<n; i++)
      {
          a[i+k*LDA]=a[i+k*LDA]/piv;
      }
      for (int i=k+1; i<n; i++)
      {
          for (int j=k+1; j<n; j++)
          {
              a[i+j*LDA] =a[i+j*LDA]-a[i+k*LDA]*a[k+j*LDA];
          }
      }
      k +=1;
      piv=a[k+k*LDA];
  }
  if(fabs(piv)<=minpiv)
  {
      std::cout<<"Null point in dLU1: "<<piv<<__FILE__<<":"<<__LINE__<<std::endl;
      return 0;
  }
  return 1;
}

