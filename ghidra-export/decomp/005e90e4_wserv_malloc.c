// func wserv_malloc @ 005e90e4 size=60

void wserv_malloc(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00408450(param_1,0x101);
  if (iVar1 != 0) {
    l_wserv_mem_stat = param_1 + l_wserv_mem_stat;
  }
  return;
}

