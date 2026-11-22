// func wportal_db_nsa_del @ 00430d68 size=264

undefined4 wportal_db_nsa_del(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_1f8 [104];
  undefined1 auStack_190 [12];
  undefined1 auStack_184 [122];
  undefined1 auStack_10a [246];
  
  uVar3 = 0xffffffff;
  if (param_1 != 0) {
    memset(auStack_1f8,0,0x74);
    FUN_0051ad88(auStack_190);
    memset(auStack_184,0,0x168);
    FUN_004082d0(wportal_nsa_mutex,0xffffffff);
    iVar1 = _wportal_db_nsa_get(param_1,auStack_184);
    if (iVar1 == 0) {
      _wportal_db_nsa_del(param_1);
      memcpy(auStack_1f8,auStack_10a,0x65);
      iVar1 = FUN_00407fa0(username_hash_for_nsa,auStack_1f8);
      if ((iVar1 != 0) && (iVar2 = FUN_00407fe0(iVar1 + 0x68), iVar2 == 0)) {
        FUN_00407f40(username_hash_for_nsa,iVar1);
        FUN_00407df0(iVar1);
      }
      uVar3 = 0;
      FUN_00407f30(wportal_nsa_mutex);
    }
    else {
      FUN_00407f30(wportal_nsa_mutex);
    }
  }
  return uVar3;
}

