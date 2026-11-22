// func _wportal_db_nsa_getnext_by_mac @ 0042ba20 size=136

undefined4 _wportal_db_nsa_getnext_by_mac(void *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_178 [116];
  undefined1 auStack_104 [248];
  
  memset(auStack_178,0,0x168);
  memcpy(auStack_104,param_1,6);
  uVar2 = 0xffffffff;
  iVar1 = FUN_004080c0(nsa_tree,auStack_178);
  if ((iVar1 != 0) && (iVar1 = FUN_00408680(iVar1), iVar1 != 0)) {
    uVar2 = 0;
    _wportal_db_nsa_copy(param_2,iVar1);
  }
  return uVar2;
}

