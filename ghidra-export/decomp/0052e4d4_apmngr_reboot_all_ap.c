// func apmngr_reboot_all_ap @ 0052e4d4 size=296

undefined4 apmngr_reboot_all_ap(int param_1,undefined1 param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  int local_20;
  int local_1c;
  undefined4 local_18;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  if (param_1 == 0) {
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      __format = "[APMNGR_ERROR]%s()/%d apmngr_reboot_all_ap(): reset type not correct.\n";
      uVar2 = 0x294;
LAB_0052e5b4:
      printf(__format,"apmngr_reboot_all_ap",uVar2);
      return 0xffffffff;
    }
  }
  else {
    iVar1 = apmngr_db_get_ap_max();
    local_20 = FUN_00408450(iVar1 << 1,0x298);
    if (local_20 != 0) {
      local_18 = CONCAT13(param_2,local_18._1_3_);
      local_1c = 0;
      iVar1 = apmngr_db_foreach_proc(0xff7fffff,_apmngr_collect_reboot_ap_ids,&local_20);
      uVar2 = 0xffffffff;
      if ((iVar1 == 0) && (uVar2 = 0, 0 < local_1c)) {
        uVar2 = apmngr_ap_reboot(local_20,local_1c,param_1);
      }
      FUN_00407df0(local_20);
      return uVar2;
    }
    if (apmngr_err_switch != '\0') {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[APMNGR_ERROR]%s()/%d Malloc error.\n";
      uVar2 = 0x29b;
      goto LAB_0052e5b4;
    }
  }
  return 0xffffffff;
}

