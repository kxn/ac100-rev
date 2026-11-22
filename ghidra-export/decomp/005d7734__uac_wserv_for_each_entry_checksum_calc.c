// func _uac_wserv_for_each_entry_checksum_calc @ 005d7734 size=532

undefined4
_uac_wserv_for_each_entry_checksum_calc(int param_1,undefined4 *param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar6;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar7;
  code *pcVar8;
  uint local_28 [2];
  
  local_28[0] = (*param_3 & 0xf) - 1;
  if ((g_wserv_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    param_4 = *param_3;
    printf("<wserv>[debug]%s(): %d  -> rd_wlan->rf_id=%d, ap_id=%d.\r\n",
           "_uac_wserv_for_each_entry_checksum_calc",0x13cd,param_4,0xffffffff);
  }
  if ((g_wserv_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    param_4 = local_28[0];
    printf("<wserv>[debug]%s(): %d  -> rd_id=%d.\r\n","_uac_wserv_for_each_entry_checksum_calc",
           0x13ce,local_28[0]);
  }
  uVar6 = rdmngr_db_generate_ap_id(*param_3);
  iVar3 = apmngr_db_capacity_support(uVar6,1,0x3f);
  iVar4 = apmngr_db_capacity_support(uVar6,1,0x2b);
  iVar5 = apmngr_db_is_ap_support_ssid_mlo_feature(uVar6);
  if (iVar3 == 0) {
    if (*(int *)(param_1 + 0x11b) == 0) {
      return 0;
    }
  }
  else {
    (*(code *)*param_2)(param_2[1],param_1 + 0x11b,4);
  }
  if (iVar5 == 1) {
    (*(code *)*param_2)(param_2[1],param_1 + 0x128,4);
  }
  uVar7 = 0xce;
  if (iVar4 != 0) {
    uVar7 = 0xd9;
  }
  if (g_wserv_debug == 0) {
    pcVar8 = (code *)*param_2;
  }
  else {
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      pcVar8 = (code *)*param_2;
    }
    else {
      uVar1 = param_1 + 0x80U & 3;
      uVar2 = param_1 + 0x83U & 3;
      printf("<wserv>[debug]%s(): %d  -> wserv_entry->id=%d, len=%d.\r\n",
             "_uac_wserv_for_each_entry_checksum_calc",0x13f1,
             (*(int *)((param_1 + 0x80U) - uVar1) << uVar1 * 8 |
             param_4 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar2 + 1) * 8 |
             *(uint *)((param_1 + 0x83U) - uVar2) >> (3 - uVar2) * 8,uVar7);
      pcVar8 = (code *)*param_2;
    }
  }
  (*pcVar8)(param_2[1],param_1 + 300,uVar7);
  (*(code *)*param_2)(param_2[1],local_28,4);
  (*(code *)*param_2)(param_2[1],param_3 + 1,1);
  return 0;
}

