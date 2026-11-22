// func _uac_wta_backup_entry_for_each_cb @ 00630a18 size=360

undefined4 _uac_wta_backup_entry_for_each_cb(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined2 local_28;
  undefined2 local_26;
  
  if (g_wsta_debug == 0) {
    local_28 = *(undefined2 *)(param_1 + 0x44);
  }
  else {
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      local_28 = *(undefined2 *)(param_1 + 0x44);
    }
    else {
      printf("<wsta>[debug]%s(): %d  -> _uac_wta_backup_entry_for_each_cb() begin.\r\n",
             "_uac_wta_backup_entry_for_each_cb",0x318);
      local_28 = *(undefined2 *)(param_1 + 0x44);
    }
  }
  local_26 = *(undefined2 *)(param_1 + 0x46);
  iVar2 = uac_wservice_get_ap_radio_cnt(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,&local_28);
  if (iVar2 < 0) {
    uVar5 = 1;
    if ((g_wsta_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("<wsta>[error]%s(): %d  -> uac_wservice_get_ap_radio_cnt() fail, ret=%d.\r\n",
             "_uac_wta_backup_entry_for_each_cb",800,iVar2);
    }
  }
  else {
    uVar1 = *(undefined2 *)(param_1 + 0x10);
    for (uVar4 = 1; (int)uVar4 <= iVar2; uVar4 = uVar4 + 1) {
      wsta_db_sta_rd_foreach(uVar1,uVar4 & 0xff,_uac_wsta_backup_entry,param_2);
    }
    uVar5 = 0;
    if ((g_wsta_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wsta>[debug]%s(): %d  -> _uac_wta_backup_entry_for_each_cb() finish.\r\n",
             "_uac_wta_backup_entry_for_each_cb",0x329);
    }
  }
  return uVar5;
}

