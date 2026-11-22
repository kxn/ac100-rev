// func apmngr_lag_config_edit @ 0052d390 size=236

undefined4
apmngr_lag_config_edit
          (undefined2 param_1,undefined1 param_2,undefined1 param_3,uint param_4,char *param_5)

{
  undefined1 *__s;
  char *__nptr;
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  param_4 = param_4 & 0xff;
  __s = (undefined1 *)FUN_00408450(param_4,0x790);
  memset(__s,0,param_4);
  __nptr = strtok(param_5,",");
  puVar3 = __s;
  while (__nptr != (char *)0x0) {
    iVar1 = atoi(__nptr);
    *puVar3 = (char)iVar1;
    __nptr = strtok((char *)0x0,",");
    puVar3 = puVar3 + 1;
  }
  uVar2 = 0xffffffff;
  iVar1 = apmngr_pkt_lag_config_update_pkt_send(param_1,param_2,param_3,param_4,__s);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  if (__s != (undefined1 *)0x0) {
    FUN_00407df0(__s);
  }
  return uVar2;
}

