// func uac_hex_to_str @ 0052297c size=164

undefined4 uac_hex_to_str(int param_1,int param_2,char *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if ((param_1 != 0) && (param_3 != (char *)0x0)) {
    for (iVar2 = 0; iVar2 < param_2; iVar2 = iVar2 + 1) {
      sprintf(param_3,"%s%02X",param_3,(uint)*(byte *)(param_1 + iVar2));
    }
    uVar1 = 1;
  }
  return uVar1;
}

