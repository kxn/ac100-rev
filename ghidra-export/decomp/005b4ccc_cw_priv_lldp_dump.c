// func cw_priv_lldp_dump @ 005b4ccc size=60

undefined4 cw_priv_lldp_dump(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x10);
  printf("\t\t\tres[0-3]: %d, %d, %d, %d \r\n",(uint)*pbVar1,(uint)pbVar1[1],(uint)pbVar1[2],
         (uint)pbVar1[3]);
  return 0;
}

