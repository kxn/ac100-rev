// func _wportal_db_aut_get @ 0042b8c0 size=116

undefined4 _wportal_db_aut_get(void *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_190 [12];
  undefined1 auStack_184 [376];
  
  memset(auStack_190,0,0x180);
  memcpy(auStack_184,param_1,6);
  iVar1 = FUN_004080c0(aut_tree,auStack_190);
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    _wportal_db_aut_copy(param_2);
    uVar2 = 0;
  }
  return uVar2;
}

