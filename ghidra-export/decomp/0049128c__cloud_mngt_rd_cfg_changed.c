// func _cloud_mngt_rd_cfg_changed @ 0049128c size=284

undefined4 _cloud_mngt_rd_cfg_changed(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *__format;
  undefined4 uVar5;
  undefined1 auStack_2f0 [732];
  
  uVar1 = rdmngr_db_generate_ap_id();
  uVar1 = uVar1 & 0xffff;
  memset(auStack_2f0,0,0x2d8);
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d _cloud_mngt_rd_cfg_changed start\n",
           "_cloud_mngt_rd_cfg_changed",0xe3d);
  }
  iVar2 = apmngr_db_get_ap_max();
  if (iVar2 <= (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    if ((int)uVar1 < iVar2 + iVar3) {
      return 0;
    }
  }
  iVar2 = apmngr_db_entry_get_by_id(uVar1,auStack_2f0);
  if (iVar2 == -1) {
    uVar4 = 0xffffffff;
    if (cloud_mngt_debug_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[CLOUD_MNGT_DEBUG]%s()/%d get ap entry by id failed.\n";
    uVar5 = 0xe44;
  }
  else {
    uVar4 = notify_ap_onoffline_handle(auStack_2f0);
    if (cloud_mngt_debug_switch == '\0') {
      return uVar4;
    }
    __format = "[CLOUD_MNGT_DEBUG]%s()/%d _cloud_mngt_rd_cfg_changed end\n";
    uVar5 = 0xe49;
  }
  printf(__format,"_cloud_mngt_rd_cfg_changed",uVar5);
  return uVar4;
}

