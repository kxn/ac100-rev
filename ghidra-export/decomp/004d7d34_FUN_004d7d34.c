// func FUN_004d7d34 @ 004d7d34 size=84

void FUN_004d7d34(byte *param_1,char *param_2)

{
  snprintf(param_2,0x14,"%.2X-%.2X-%.2X-%.2X-%.2X-%.2X",(uint)*param_1,(uint)param_1[1],
           (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
  return;
}

