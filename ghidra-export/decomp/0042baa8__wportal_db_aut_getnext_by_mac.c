// func _wportal_db_aut_getnext_by_mac @ 0042baa8 size=136

undefined4 _wportal_db_aut_getnext_by_mac(void *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_190 [12];
  undefined1 auStack_184 [376];
  
  memset(auStack_190,0,0x180);
  memcpy(auStack_184,param_1,6);
  uVar2 = 0xffffffff;
  iVar1 = FUN_004080c0(aut_tree,auStack_190);
  if ((iVar1 != 0) && (iVar1 = FUN_00408680(iVar1), iVar1 != 0)) {
    uVar2 = 0;
    _wportal_db_aut_copy(param_2,iVar1);
  }
  return uVar2;
}

