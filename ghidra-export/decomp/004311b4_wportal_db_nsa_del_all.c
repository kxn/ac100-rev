// func wportal_db_nsa_del_all @ 004311b4 size=292

undefined4 wportal_db_nsa_del_all(code *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_98 [104];
  undefined1 auStack_30 [20];
  
  FUN_004082d0(wportal_nsa_mutex,0xffffffff);
  iVar1 = FUN_004081b0(nsa_list);
  while (iVar1 != 0) {
    iVar2 = FUN_00408680(iVar1);
    if (param_1 != (code *)0x0) {
      (*param_1)(iVar1,param_2);
    }
    _wportal_db_nsa_del(iVar1 + 0x74);
    memset(auStack_98,0,0x74);
    FUN_0051ad88(auStack_30);
    memcpy(auStack_98,(void *)(iVar1 + 0x7a),0x65);
    iVar3 = FUN_00407fa0(username_hash_for_nsa,auStack_98);
    iVar1 = iVar2;
    if ((iVar3 != 0) && (iVar2 = FUN_00407fe0(iVar3 + 0x68), iVar2 == 0)) {
      FUN_00407f40(username_hash_for_nsa,iVar3);
      FUN_00407df0(iVar3);
    }
  }
  FUN_00407f30(wportal_nsa_mutex);
  return 0;
}

