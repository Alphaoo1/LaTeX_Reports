int factorL2(int n,  double *a, int LDA ){
    int k=0;
    const double minpiv=1e-6;
    double piv =a[0];
    while((fabs(piv)>minpiv) && (k< n-1))
    {
        dscal_(n-(k+1),1./piv, a+(k+1+k*LDA),1);
        dger_(n-(k+1), n-(k+1), -1., a+(k+1+k*LDA), 1, a+(k+(k+1)*LDA), LDA, a+(k+1+(k+1)*LDA), LDA);
        k +=1;
        piv=a[k+k*LDA];
    }
    if (fabs(piv)<=minpiv)
    {
        std::cout<<"Null point in dLU2: "<<piv<<__FILE__<<":"<<__LINE__<<std::endl;
        return 0;
    }
    return 1;
};
