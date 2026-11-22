// func wserv_db_rd_get_bind_vlan_by_wlan_id @ 005f2184 size=504

undefined4 wserv_db_rd_get_bind_vlan_by_wlan_id(undefined4 param_1,uint param_2,undefined2 *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 uVar8;
  
  param_2 = param_2 & 0xff;
  uVar1 = rdmngr_db_generate_rd_idx_by_rd_id();
  if (-1 < (int)uVar1) {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    iVar4 = apmngr_db_get_sensor_max();
    iVar5 = rdmngr_profile_get_max_rd_per_ap();
    if (uVar1 < (uint)((iVar2 + iVar3 + iVar4) * iVar5)) {
      if ((param_2 != 0) && (uVar6 = rdmngr_profile_get_max_wlan_per_rd(), param_2 <= uVar6)) {
        if (param_3 != (undefined2 *)0x0) {
          *param_3 = 0;
        }
        FUN_004082d0(DAT_007cbef0,0xffffffff);
        pcVar7 = (char *)(DAT_007cbf04 + uVar1 * 0xc);
        if (*pcVar7 == '\0') {
          uVar8 = 0xffffffff;
          if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("<wserv>[warning]%s(): %d  -> idx[%d] has not been used, rd_id[%d]!\r\n",
                   "wserv_db_rd_get_bind_vlan_by_wlan_id",0x12ea,uVar1,param_1);
          }
        }
        else {
          pcVar7 = (char *)(*(int *)(pcVar7 + 8) + (param_2 - 1) * 6);
          uVar8 = 0xffffffff;
          if ((*pcVar7 != '\0') && (uVar8 = 0, param_3 != (undefined2 *)0x0)) {
            *param_3 = *(undefined2 *)(pcVar7 + 4);
          }
        }
        FUN_00407f30(DAT_007cbef0);
        return uVar8;
      }
      if (g_wserv_warning == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 != 0) {
        printf("<wserv>[warning]%s(): %d  -> wlan_id[%d] is invalid!\r\n",
               "wserv_db_rd_get_bind_vlan_by_wlan_id",0x12de,param_2);
        return 0xffffffff;
      }
      return 0xffffffff;
    }
  }
  if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wserv>[warning]%s(): %d  -> invalid rd_id[0x%08x] fail,idx[0x%08x]!\r\n",
           "wserv_db_rd_get_bind_vlan_by_wlan_id",0x12d8,param_1,uVar1);
    return 0xffffffff;
  }
  return 0xffffffff;
}

