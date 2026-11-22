// func _wportal_db_aut_del_by_ip @ 0042bf90 size=560

undefined4 _wportal_db_aut_del_by_ip(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_208 [104];
  undefined1 auStack_1a0 [16];
  undefined1 auStack_190 [12];
  int local_184;
  uint local_180;
  undefined1 auStack_138 [75];
  undefined1 auStack_ed [221];
  
  memset(auStack_208,0,0x74);
  FUN_0051ad88(auStack_1a0);
  memset(auStack_190,0,0x180);
  iVar1 = _wportal_db_aut_get_by_ip(param_1,auStack_190);
  if (iVar1 == 0) {
    if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d got ip:%s\n","_wportal_db_aut_del_by_ip",0x759,param_1);
    }
    memcpy(auStack_208,auStack_ed,0x65);
    FUN_00408690(aut_tree,auStack_190);
    iVar1 = FUN_00407fa0(username_hash_for_aut,auStack_208);
    if ((iVar1 != 0) && (iVar2 = FUN_00407fe0(iVar1 + 0x68), iVar2 == 0)) {
      FUN_00407f40(username_hash_for_aut,iVar1);
      FUN_00407df0(iVar1);
    }
    if ((((local_184 != 0) || ((local_180 & 0xffff0000) != 0)) &&
        (iVar1 = FUN_00407fa0(dm_calling_station_hash,&local_184), iVar1 != 0)) &&
       (iVar2 = FUN_00407fe0(iVar1 + 8), iVar2 == 0)) {
      FUN_00407f40(dm_calling_station_hash,iVar1);
      FUN_00407df0(iVar1);
    }
    uVar3 = 0;
    iVar1 = FUN_00407fa0(dm_framed_ip_hash,auStack_138);
    if ((iVar1 != 0) && (iVar2 = FUN_00407fe0(iVar1 + 0x28), iVar2 == 0)) {
      if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(dm_framed_ip_hash), iVar2 != 0)
         ) {
        printf("[WPORTAL_DBG]%s()/%d here delete dm_framed_ip_hash node:%s\n",
               "_wportal_db_aut_del_by_ip",0x77c,auStack_138);
      }
      uVar3 = 0;
      FUN_00407f40(dm_framed_ip_hash,iVar1);
      FUN_00407df0(iVar1);
    }
  }
  else {
    uVar3 = 0xffffffff;
    if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d can\'t not ip:%s\n","_wportal_db_aut_del_by_ip",0x754,param_1);
    }
  }
  return uVar3;
}

