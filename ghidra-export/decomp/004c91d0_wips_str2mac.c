// func wips_str2mac @ 004c91d0 size=72

void wips_str2mac(char *param_1,int param_2)

{
  sscanf(param_1,"%02hhx-%02hhx-%02hhx-%02hhx-%02hhx-%02hhx",param_2,param_2 + 1,param_2 + 2,
         param_2 + 3,param_2 + 4,param_2 + 5);
  return;
}

