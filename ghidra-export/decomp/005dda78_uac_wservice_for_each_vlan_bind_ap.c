// func uac_wservice_for_each_vlan_bind_ap @ 005dda78 size=296

undefined4 uac_wservice_for_each_vlan_bind_ap(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 local_2f8;
  undefined2 local_2f6;
  undefined1 auStack_2f0 [64];
  undefined4 local_2b0;
  undefined2 local_2ac;
  undefined2 local_2aa;
  undefined1 auStack_d8 [192];
  
  uVar3 = 0;
  if (param_2 != 0) {
    iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_2f0);
    if (iVar1 == 0) {
      local_2f8 = local_2ac;
      local_2f6 = local_2aa;
      iVar1 = uac_wservice_get_ap_radio_cnt(local_2b0,auStack_d8,&local_2f8);
      if (iVar1 < 0) {
        uVar3 = 0xffffffff;
        if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("<wserv>[error]%s(): %d  -> uac_wservice_get_ap_radio_cnt() fail, ret=%d.\r\n",
                 "uac_wservice_for_each_vlan_bind_ap",0x160f,iVar1);
        }
      }
      else {
        uVar3 = wserv_db_for_each_vlan_bind_ap(param_1,iVar1,param_2,param_3);
      }
    }
    else {
      uVar3 = 0xffffffff;
      if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[error]%s(): %d  -> apmngr_db_entry_get_by_id() fail.\r\n",
               "uac_wservice_for_each_vlan_bind_ap",0x1605);
      }
    }
  }
  return uVar3;
}

