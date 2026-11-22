// func getCodeIn @ 005d3758 size=112

void getCodeIn(uint param_1,char *param_2,int param_3)

{
  char *__src;
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  puVar1 = &valid_addr_range;
  do {
    uVar3 = puVar1[1];
    if (*puVar1 <= param_1) {
      if (param_1 <= uVar3) {
        __src = &DAT_007c6a5c + iVar2 * 0x8c;
        goto LAB_005d37ac;
      }
      uVar3 = puVar1[1];
    }
    iVar2 = iVar2 + 1;
  } while ((uVar3 != 0) && (puVar1 = puVar1 + 0x23, iVar2 != 0x96));
  __src = "unknown";
LAB_005d37ac:
  strncpy(param_2,__src,param_3 - 1);
  return;
}

