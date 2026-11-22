// func _uac_wsta_pkt_sta_info_list @ 00635f9c size=336

undefined4
_uac_wsta_pkt_sta_info_list
          (undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_2f8;
  undefined4 local_2f4;
  undefined1 auStack_2f0 [16];
  undefined2 local_2e0;
  
  local_2f8 = 0;
  local_2f4 = 0;
  if (*(uint *)(param_1 + 8) < 0x3e9) {
    uVar4 = 0;
    iVar1 = apmngr_db_entry_get_by_mac(param_3,auStack_2f0);
    if (iVar1 == 0) {
      for (; uVar4 < *(uint *)(param_1 + 8); uVar4 = uVar4 + 1) {
        puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + uVar4 * 0x10);
        uac_wstation_assoc(local_2e0,*param_1,param_1[7],puVar2 + 2,puVar2[1],*puVar2,0,0,&local_2f8
                          );
      }
      uVar3 = 0;
    }
    else {
      uVar3 = 0x15;
      if ((g_wsta_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wsta>[warning]%s(): %d  -> apmngr_db_entry_get_by_mac() fail.\r\n",
               "_uac_wsta_pkt_sta_info_list",0x376);
      }
    }
  }
  else {
    uVar3 = 0x15;
    if ((g_wsta_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[warning]%s(): %d  -> list_val->sta_cnt=%d is invalid.\r\n",
             "_uac_wsta_pkt_sta_info_list",0x36f,*(undefined4 *)(param_1 + 8));
    }
  }
  _uac_wsta_pkt_set_result_code(param_4,uVar3);
  return 0;
}

