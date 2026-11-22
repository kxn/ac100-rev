// func wips_mac2str @ 004c7eec size=76

void wips_mac2str(byte *param_1,char *param_2)

{
  sprintf(param_2,"%02x-%02x-%02x-%02x-%02x-%02x",(uint)*param_1,(uint)param_1[1],(uint)param_1[2],
          (uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
  return;
}

