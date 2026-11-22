// func apmngr_hdap_get_direct_by_name @ 005481f0 size=116

undefined4 apmngr_hdap_get_direct_by_name(char *param_1)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_1 != (char *)0x0) {
    sVar1 = strlen(param_1);
    iVar2 = memcmp(param_1 + (sVar1 - 3),&DAT_006cd69c,3);
    uVar3 = 1;
    if (iVar2 != 0) {
      iVar2 = memcmp(param_1 + (sVar1 - 3),&DAT_006cd6a0,3);
      uVar3 = 2;
      if (iVar2 != 0) {
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}

