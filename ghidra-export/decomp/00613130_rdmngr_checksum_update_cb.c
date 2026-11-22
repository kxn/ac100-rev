// func rdmngr_checksum_update_cb @ 00613130 size=448

undefined4 rdmngr_checksum_update_cb(int param_1,int param_2,int param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  int local_68;
  int local_64;
  undefined1 auStack_60 [76];
  
  memset(&local_68,0,0x50);
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    if (rdmngr_err_switch == 0) {
      return 2;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 2;
    }
    __format = "[RDMNGR_ERROR]%s()/%d invalid args.\n";
    uVar2 = 0x7b2;
  }
  else {
    if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(auStack_60), iVar1 != 0)) {
      printf("[RDMNGR_DEBUG]%s()/%d ap_id=%d, calc checksum begin.\n","rdmngr_checksum_update_cb",
             0x7b6,(uint)*(ushort *)(param_1 + 0x10));
    }
    local_68 = param_2;
    local_64 = param_3;
    iVar1 = rate_db_get_for_md5(auStack_60);
    if (iVar1 == 0) {
      iVar1 = rdmngr_for_each_entry_bind_ap
                        (*(undefined2 *)(param_1 + 0x10),rdmngr_for_each_entry_checksum_calc,
                         &local_68);
      if (iVar1 == 0) {
        if (rdmngr_debug_switch == 0) {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        printf("[RDMNGR_DEBUG]%s()/%d ap_id=%d, calc checksum finish.\n","rdmngr_checksum_update_cb"
               ,0x7c4,(uint)*(ushort *)(param_1 + 0x10));
        return 0;
      }
      if (rdmngr_debug_switch == 0) {
        return 2;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 2;
      }
      __format = "[RDMNGR_DEBUG]%s()/%d uac_rdmngr_for_each_entry_bind_ap() fail.\n";
      uVar2 = 0x7c0;
    }
    else {
      if (rdmngr_err_switch == 0) {
        return 2;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 2;
      }
      __format = "[RDMNGR_ERROR]%s()/%d get rate configure failed.\n";
      uVar2 = 0x7bb;
    }
  }
  printf(__format,"rdmngr_checksum_update_cb",uVar2);
  return 2;
}

