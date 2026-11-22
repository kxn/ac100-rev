// func wserv_db_rd_unbind_with_freq_vlan @ 005f237c size=776

undefined4
wserv_db_rd_unbind_with_freq_vlan
          (int param_1,uint param_2,uint param_3,undefined4 param_4,int param_5,int *param_6)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ushort local_58 [2];
  int local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  
  local_34 = param_2 & 0xffff;
  local_30 = param_3 & 0xffff;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  FUN_0051ad88(&local_4c);
  FUN_004082d0(DAT_007cbef0,0xffffffff);
  iVar3 = *(int *)(DAT_007cbefc + param_1 * 0x21c + 0x218);
  if (iVar3 != 0) {
    FUN_00408570(iVar3,_wserv_rd_hash_info_collection,&local_4c);
  }
  FUN_00407f30(DAT_007cbef0);
  iVar3 = FUN_004081b0(&local_4c);
  do {
    if (iVar3 == 0) {
      return 0;
    }
    local_3c = FUN_00408680(iVar3);
    iVar5 = *(int *)(iVar3 + 0x214);
    local_58[0] = 0;
    local_50 = -1;
    local_38 = (uint)*(byte *)(iVar3 + 0x218);
    local_40 = rdmngr_db_generate_ap_id(iVar5);
    local_54 = 1;
    iVar1 = rdmngr_db_get_freq_band_idx(iVar5,&local_50,&local_54);
    if (iVar1 == 0) {
      uVar6 = 1 << (local_54 - 1U & 0x1f);
      uVar7 = uVar6 & 0xffff;
      if (local_50 == 1) {
        uVar7 = (uVar6 & 0xff) << 8;
      }
      else if (local_50 == -1) {
        if ((g_wserv_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          __format = "<wserv>[error]%s(): %d  -> Illegal freq %d.\r\n";
          uVar4 = 0x10f6;
          iVar5 = local_50;
          goto LAB_005f2608;
        }
        goto LAB_005f249c;
      }
      wserv_db_rd_get_bind_vlan_by_wlan_id(iVar5,local_38,local_58);
      if (((uVar7 & ~local_30) != 0) || (local_58[0] != local_34)) {
        if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("<wserv>[debug]%s(): %d  -> unbind rf_id: %d wserv_id: %d\r\n",
                 "_wserv_unbind_with_freq_vlan",0x1100,iVar5,param_1);
        }
        puVar2 = (uint *)(param_5 + ((int)local_40 >> 5) * 4);
        uVar6 = *puVar2;
        if ((((int)uVar6 >> (local_40 & 0x1f) & 1U) == 0) &&
           (*puVar2 = uVar6 | 1 << (local_40 & 0x1f), param_6 != (int *)0x0)) {
          *param_6 = *param_6 + 1;
        }
        wserv_db_rd_unbind(iVar5,param_1,param_4);
        iVar5 = wserv_sqlite_notify(3,iVar3 + 0x214,8);
        if (((iVar5 != 0) && (g_wserv_error != 0)) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("<wserv>[error]%s(): %d  -> wserv_sqlite_notify() unbind fail. rd_id=%d, wlan_id=%d!\r\n"
                 ,"_wserv_unbind_with_freq_vlan",0x1111,*(undefined4 *)(iVar3 + 0x214),
                 (uint)*(byte *)(iVar3 + 0x218));
        }
      }
    }
    else if ((g_wserv_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      uVar4 = 0x10ea;
      __format = "<wserv>[error]%s(): %d  -> Get freq band and index failed of rf_id %d.\r\n";
LAB_005f2608:
      printf(__format,"_wserv_unbind_with_freq_vlan",uVar4,iVar5);
    }
LAB_005f249c:
    FUN_00407df0(iVar3);
    iVar3 = local_3c;
  } while( true );
}

