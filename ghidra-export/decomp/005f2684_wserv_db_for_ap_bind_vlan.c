// func wserv_db_for_ap_bind_vlan @ 005f2684 size=672

undefined4 wserv_db_for_ap_bind_vlan(uint param_1,uint param_2,code *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  uint uVar7;
  char cVar8;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_30 = 0;
  local_2c = 0;
  if (param_1 < 0x1001) {
    if (-1 < (int)param_2) {
      iVar1 = apmngr_db_get_ap_max();
      iVar2 = apmngr_db_get_template_max();
      if (((int)param_2 < iVar1 + iVar2) ||
         ((49999 < (int)param_2 &&
          (iVar1 = apmngr_db_get_sensor_max(), (int)param_2 < iVar1 + 50000)))) {
        uVar7 = 1;
        FUN_004082d0(DAT_007cbef0,0xffffffff);
        do {
          while( true ) {
            while( true ) {
              uVar3 = rdmngr_profile_get_max_rd_per_ap();
              if (uVar3 < uVar7) {
                FUN_00407f30(DAT_007cbef0);
                return 0;
              }
              uVar6 = rdmngr_db_generate_rd_id(param_2,uVar7);
              iVar1 = _wserv_is_rd_enable(uVar6);
              if (iVar1 != 0) break;
              uVar7 = uVar7 + 1;
            }
            iVar1 = rdmngr_db_generate_rd_idx_by_rd_id(uVar6);
            if (*(char *)(DAT_007cbf04 + iVar1 * 0xc) != '\0') break;
            uVar7 = uVar7 + 1;
          }
          cVar8 = '\x01';
          uVar3 = 0;
          while (uVar4 = rdmngr_profile_get_max_wlan_per_rd(), uVar3 < uVar4) {
            pcVar5 = (char *)(*(int *)(DAT_007cbf04 + iVar1 * 0xc + 8) + uVar3 * 6);
            uVar4 = (uint)*(short *)(pcVar5 + 2);
            if ((((*pcVar5 == '\0') || (param_1 != (int)*(short *)(pcVar5 + 4))) || ((int)uVar4 < 0)
                ) || (l_wserv_profile <= uVar4)) {
LAB_005f2880:
              cVar8 = cVar8 + '\x01';
              uVar3 = uVar3 + 1;
            }
            else {
              iVar2 = DAT_007cbefc + uVar4 * 0x21c;
              if ((*(int *)(iVar2 + 0xc) == 0) || (*(int *)(iVar2 + 299) == 0)) goto LAB_005f2880;
              local_2c = CONCAT13(cVar8,local_2c._1_3_);
              cVar8 = cVar8 + '\x01';
              local_30 = uVar6;
              (*param_3)(&local_30,uVar4,param_4);
              uVar3 = uVar3 + 1;
            }
          }
          uVar7 = uVar7 + 1;
        } while( true );
      }
    }
    if (g_wserv_warning != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      pcVar5 = "<wserv>[warning]%s(): %d  -> ap_id[%d] is invalid!\r\n";
      uVar6 = 0x132e;
      goto LAB_005f2900;
    }
  }
  else if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    pcVar5 = "<wserv>[warning]%s(): %d  -> vlan_id[%d] is invalid!\r\n";
    uVar6 = 0x1328;
    param_2 = param_1;
LAB_005f2900:
    printf(pcVar5,"wserv_db_for_ap_bind_vlan",uVar6,param_2);
    return 0xffffffff;
  }
  return 0xffffffff;
}

