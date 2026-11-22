// func _wportal_db_aut_get_by_ip @ 0042b934 size=116

undefined4 _wportal_db_aut_get_by_ip(char *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_190 [88];
  char acStack_138 [300];
  
  memset(auStack_190,0,0x180);
  strncpy(acStack_138,param_1,0x28);
  iVar1 = FUN_004080c0(aut_tree,auStack_190);
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    _wportal_db_aut_copy(param_2);
    uVar2 = 0;
  }
  return uVar2;
}

