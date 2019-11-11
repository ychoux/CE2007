uint32_t LPF_Calc(uint32_t newdata){
  LPFSum = LPFSum+newdata-x[I1];   // subtract oldest, add newest
  x[I1] = newdata;     // save new data
  if(I1 == 0){
    I1 = Size-1;              // wrap
  } else{
    I1--;                     // make room for data
  }
  return LPFSum/Size;
}
