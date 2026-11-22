// func wportal_update_user_to_ap @ 0041b830 size=504

undefined4 wportal_update_user_to_ap(int param_1,uint param_2)

{
  int iVar1;
  char cVar2;
  char *__format;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_390 [8];
  uint local_388;
  undefined1 auStack_368 [32];
  undefined4 local_348;
  ushort local_33a;
  undefined1 auStack_2e8 [16];
  undefined2 local_2d8;
  
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_mac(param_1 + 0x34,auStack_2e8);
  if (iVar1 == 0) {
    memset(auStack_390,0,0x28);
    memcpy(auStack_390,(void *)(param_1 + 0xc),6);
    memset(auStack_368,0,0x80);
    iVar1 = wsta_db_get_entry_by_mac(auStack_390,auStack_368);
    if (iVar1 == 0) {
      if (g_portal_auth_mode == 1) {
        local_388 = *(uint *)(param_1 + 0x14);
      }
      else {
        local_388 = (uint)local_33a;
      }
      wportal_update_user_to_ap_by_id(local_348,auStack_390,param_2);
      cVar2 = *(char *)(param_1 + 0x80);
      if (((cVar2 == '\x01') || (cVar2 == '\x10')) || (cVar2 == ' ')) {
        if (param_2 == 0) {
          iVar4 = *(int *)(param_1 + 0x168);
          iVar1 = *(int *)(param_1 + 0x16c);
          if ((iVar4 == 0) && (iVar1 == 0)) {
            cVar2 = *(char *)(param_1 + 0x80);
            goto LAB_0041b93c;
          }
          uVar3 = 0;
        }
        else {
          if (param_2 != 1) {
            cVar2 = *(char *)(param_1 + 0x80);
            goto LAB_0041b93c;
          }
          uVar3 = 1;
          iVar1 = 0;
          iVar4 = 0;
        }
        _wportal_update_bw_control_to_ap_by_id(local_2d8,param_1 + 0xc,uVar3,iVar4,iVar1);
        cVar2 = *(char *)(param_1 + 0x80);
      }
      else {
        cVar2 = *(char *)(param_1 + 0x80);
      }
LAB_0041b93c:
      if (cVar2 != '@') {
        return 0;
      }
      if (1 < param_2) {
        return 0;
      }
      _wportal_update_bw_control_to_ap_by_id
                (local_2d8,param_1 + 0xc,param_2,*(undefined4 *)(param_1 + 0x168),
                 *(undefined4 *)(param_1 + 0x16c));
      return 0;
    }
    if (wportal_debug_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[WPORTAL_DBG]%s()/%d Get wsta entry failed.\n";
    uVar3 = 0x3493;
  }
  else {
    if (wportal_debug_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[WPORTAL_DBG]%s()/%d Get ap entry failed.\n";
    uVar3 = 0x3489;
  }
  printf(__format,"wportal_update_user_to_ap",uVar3);
  return 0xffffffff;
}

