// func FUN_004b6c38 @ 004b6c38 size=216

void FUN_004b6c38(undefined4 param_1,undefined4 param_2,char *param_3,int param_4)

{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  char *__s;
  byte local_f0 [100];
  undefined1 auStack_8c [112];
  
  memset(local_f0,0,100);
  FUN_00408590(auStack_8c);
  FUN_00408670(auStack_8c,param_1,param_2);
  iVar3 = 0;
  FUN_00407e90(local_f0,auStack_8c);
  bVar1 = 0 < param_4;
  __s = param_3;
  while (bVar1) {
    pbVar2 = local_f0 + iVar3;
    iVar3 = iVar3 + 1;
    snprintf(__s,3,"%02x",(uint)*pbVar2);
    bVar1 = iVar3 < param_4;
    __s = __s + 2;
  }
  param_3[param_4 * 2] = '\0';
  return;
}

