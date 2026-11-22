// func _wportal_db_aut_del @ 0042be3c size=340

undefined4 _wportal_db_aut_del(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_208 [104];
  undefined1 auStack_1a0 [16];
  undefined1 auStack_190 [12];
  undefined1 auStack_184 [76];
  undefined1 auStack_138 [75];
  undefined1 auStack_ed [221];
  
  uVar3 = 0xffffffff;
  memset(auStack_208,0,0x74);
  FUN_0051ad88(auStack_1a0);
  memset(auStack_190,0,0x180);
  iVar1 = _wportal_db_aut_get(param_1,auStack_190);
  if (iVar1 == 0) {
    memcpy(auStack_208,auStack_ed,0x65);
    FUN_00408690(aut_tree,auStack_190);
    iVar1 = FUN_00407fa0(username_hash_for_aut,auStack_208);
    if ((iVar1 != 0) && (iVar2 = FUN_00407fe0(iVar1 + 0x68), iVar2 == 0)) {
      FUN_00407f40(username_hash_for_aut,iVar1);
      FUN_00407df0(iVar1);
    }
    iVar1 = FUN_00407fa0(dm_calling_station_hash,auStack_184);
    if ((iVar1 != 0) && (iVar2 = FUN_00407fe0(iVar1 + 8), iVar2 == 0)) {
      FUN_00407f40(dm_calling_station_hash,iVar1);
      FUN_00407df0(iVar1);
    }
    uVar3 = 0;
    iVar1 = FUN_00407fa0(dm_framed_ip_hash,auStack_138);
    if ((iVar1 != 0) && (iVar2 = FUN_00407fe0(iVar1 + 0x28), iVar2 == 0)) {
      FUN_00407f40(dm_framed_ip_hash,iVar1);
      FUN_00407df0(iVar1);
    }
  }
  return uVar3;
}

