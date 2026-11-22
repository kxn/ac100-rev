// func _multi_link_checksum_send @ 00663190 size=300

undefined4 _multi_link_checksum_send(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_2e8 [16];
  undefined2 local_2d8;
  
  if (multi_link_debug_switch != '\0') {
    printf("[MULTI_LINK_DEBUG]%s()/%d _multi_link_checksum_send apip = %d\n",
           "_multi_link_checksum_send",0x11b,param_1);
  }
  memset(auStack_2e8,0,0x2d8);
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_2e8);
  if (iVar1 == 0) {
    iVar1 = apmngr_checksum_update(auStack_2e8,0);
    if (iVar1 == 0) {
      uVar2 = apmngr_db_timer_md5_send_interval_default_get();
      iVar1 = apmngr_entry_timer_start(local_2d8,1,uVar2);
      if (iVar1 == 0) {
        return 0;
      }
    }
    if (multi_link_err_switch != '\0') {
      printf("[MULTI_LINK_ERROR]%s()/%d update md5 failed.\n","_multi_link_checksum_send",0x129);
      return 0xffffffff;
    }
  }
  else if (multi_link_err_switch != '\0') {
    printf("[MULTI_LINK_ERROR]%s()/%d apmngr_db_entry_get_by_id[%d] fail.\n",
           "_multi_link_checksum_send",0x123,param_1);
    return 0xffffffff;
  }
  return 0xffffffff;
}

