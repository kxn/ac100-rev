// func wportal_db_nsa_del_by_mode_id @ 00430e70 size=452

undefined4 wportal_db_nsa_del_by_mode_id(uint param_1,uint param_2,code *param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_a0 [104];
  undefined1 auStack_38 [20];
  
  iVar1 = wportal_get_mode();
  if (((iVar1 != 1) || (uVar5 = 0xffffffff, param_1 < 0x1000)) &&
     ((iVar1 = wportal_get_mode(), iVar1 != 0 ||
      ((uVar5 = 0xffffffff, -1 < (int)param_1 &&
       (uVar2 = wserv_profile_get_max_wservice(), param_1 < uVar2)))))) {
    FUN_004082d0(wportal_nsa_mutex,0xffffffff);
    iVar3 = wportal_get_mode();
    iVar1 = vlan_list_array_for_nsa;
    if (iVar3 != 1) {
      iVar1 = ssid_list_array_for_nsa;
    }
    iVar1 = FUN_004081b0(iVar1 + param_1 * 0xc);
    while (iVar3 = iVar1, iVar3 != 0) {
      iVar1 = FUN_00408680(iVar3);
      if ((iVar3 + -0x110 != 0) && ((param_2 & 0xff & *(uint *)(iVar3 + 0x38)) != 0)) {
        if (param_3 != (code *)0x0) {
          (*param_3)(iVar3 + -0x110,param_4);
        }
        _wportal_db_nsa_del(iVar3 + -0x9c);
        memset(auStack_a0,0,0x74);
        FUN_0051ad88(auStack_38);
        memcpy(auStack_a0,(void *)(iVar3 + -0x96),0x65);
        iVar3 = FUN_00407fa0(username_hash_for_nsa,auStack_a0);
        if ((iVar3 != 0) && (iVar4 = FUN_00407fe0(iVar3 + 0x68), iVar4 == 0)) {
          FUN_00407f40(username_hash_for_nsa,iVar3);
          FUN_00407df0(iVar3);
        }
      }
    }
    FUN_00407f30(wportal_nsa_mutex);
    uVar5 = 0;
  }
  return uVar5;
}

