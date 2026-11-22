// func wserv_calloc @ 005e8d84 size=76

void wserv_calloc(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_004082a0(param_1,param_2,0x10c);
  if (iVar1 != 0) {
    l_wserv_mem_stat = param_2 * param_1 + l_wserv_mem_stat;
  }
  return;
}

