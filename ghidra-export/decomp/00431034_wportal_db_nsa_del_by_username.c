// func wportal_db_nsa_del_by_username @ 00431034 size=384

undefined4 wportal_db_nsa_del_by_username(char *param_1,code *param_2,undefined4 param_3)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_a0 [104];
  undefined1 auStack_38 [16];
  
  uVar5 = 0xffffffff;
  if (param_1 != (char *)0x0) {
    memset(auStack_a0,0,0x74);
    FUN_0051ad88(auStack_38);
    sVar1 = strlen(param_1);
    memcpy(auStack_a0,param_1,sVar1 + 1);
    FUN_004082d0(wportal_nsa_mutex,0xffffffff);
    iVar2 = FUN_00407fa0(username_hash_for_nsa,auStack_a0);
    if (iVar2 == 0) {
      FUN_00407f30(wportal_nsa_mutex);
    }
    else {
      iVar3 = FUN_004081b0(iVar2 + 0x68);
      while (iVar4 = iVar3, iVar4 != 0) {
        iVar3 = FUN_00408680(iVar4);
        if ((iVar4 + -0x11c != 0) && (*(int *)(iVar4 + 0x30) != 1)) {
          if (param_2 != (code *)0x0) {
            (*param_2)(iVar4 + -0x11c,param_3);
          }
          _wportal_db_nsa_del(iVar4 + -0xa8);
          iVar4 = FUN_00407fe0(iVar2 + 0x68);
          if (iVar4 == 0) {
            FUN_00407f40(username_hash_for_nsa,iVar2);
            FUN_00407df0(iVar2);
          }
        }
      }
      uVar5 = 0;
      FUN_00407f30(wportal_nsa_mutex);
    }
  }
  return uVar5;
}

