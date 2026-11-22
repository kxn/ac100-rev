// func mac2str @ 00548cd0 size=84

void mac2str(byte *param_1,char *param_2,size_t param_3)

{
  snprintf(param_2,param_3,"%.2X-%.2X-%.2X-%.2X-%.2X-%.2X",(uint)*param_1,(uint)param_1[1],
           (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
  return;
}

