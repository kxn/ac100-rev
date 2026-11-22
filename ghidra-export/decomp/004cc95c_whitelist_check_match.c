// func whitelist_check_match @ 004cc95c size=248

undefined4
whitelist_check_match(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_78 [12];
  undefined4 local_6c;
  
  uVar2 = 0;
  memset(auStack_78,0,0x5c);
  if ((*(int *)(param_4 + 0x28) + 0xfecea7fcU < 2) &&
     ((iVar1 = wips_whitelist_get(param_1,&DAT_00688af8,0,1,auStack_78), iVar1 == 0 ||
      ((*(int *)(param_4 + 0x28) == 0x1315804 &&
       (iVar1 = wips_whitelist_get(&DAT_006a81e4,param_2,param_3,2,auStack_78), iVar1 == 0)))))) {
    uVar2 = 1;
    wips_whitelist_send(local_6c,*(undefined2 *)(param_4 + 0x38),0);
  }
  return uVar2;
}

