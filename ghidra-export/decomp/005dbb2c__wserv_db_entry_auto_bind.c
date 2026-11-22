// func _wserv_db_entry_auto_bind @ 005dbb2c size=820

undefined4 _wserv_db_entry_auto_bind(int param_1,int *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined2 local_50;
  undefined2 local_4e;
  undefined4 local_4c;
  uint local_48;
  undefined4 local_44;
  uint local_40;
  uint local_38;
  int local_34;
  int local_30;
  
  uVar9 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  iVar8 = *param_2;
  local_30 = param_2[1];
  if (*(int *)(param_1 + 0x11f) != 0) {
    local_50 = *(undefined2 *)(iVar8 + 0x44);
    local_4e = *(undefined2 *)(iVar8 + 0x46);
    local_34 = uac_wservice_get_ap_radio_cnt(*(undefined4 *)(iVar8 + 0x40),iVar8 + 0x218,&local_50);
    if (local_34 < 0) {
      uVar9 = 0xffffffff;
      if ((g_wserv_error != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
        printf("<wserv>[error]%s(): %d  -> uac_wservice_get_ap_radio_cnt() fail, ret=%d.\r\n",
               "_wserv_db_entry_auto_bind",0x101a,local_34);
      }
    }
    else {
      uVar11 = 1;
      uVar12 = 0xffffffff;
      local_38 = 0xffffffff;
      iVar10 = 1;
      while (uVar9 = 0, iVar10 <= local_34) {
        uVar9 = rdmngr_db_generate_rd_id(*(undefined2 *)(iVar8 + 0x10),iVar10);
        iVar4 = rdmngr_db_get_rd_freq_band(uVar9);
        if (iVar4 == 0) {
          local_38 = local_38 + 1;
          uVar11 = 1 << (local_38 & 0x1f);
LAB_005dbc40:
          uVar11 = uVar11 & 0xffff;
          uVar1 = *(undefined1 *)(param_1 + 0x125);
        }
        else {
          if (iVar4 == 1) {
            uVar12 = uVar12 + 1;
            uVar11 = (1 << (uVar12 & 0x1f)) << 8;
            goto LAB_005dbc40;
          }
          uVar1 = *(undefined1 *)(param_1 + 0x125);
        }
        if ((uVar11 & CONCAT11(uVar1,*(undefined1 *)(param_1 + 0x126))) == 0) {
LAB_005dbc60:
          iVar10 = iVar10 + 1;
        }
        else {
          iVar4 = rdmngr_db_rd_entry_max_ssid_get(uVar9);
          if (iVar4 < 0) {
            if (g_wserv_warning == 0) {
              iVar10 = iVar10 + 1;
            }
            else {
              iVar5 = is_target_debug_ap();
              if (iVar5 == 0) {
                iVar10 = iVar10 + 1;
              }
              else {
                printf("<wserv>[warning]%s(): %d  -> rdmngr_db_rd_entry_max_ssid_get() fail, max_ssid=%d.\r\n"
                       ,"_wserv_db_entry_auto_bind",0x1035,iVar4);
                iVar10 = iVar10 + 1;
              }
            }
          }
          else {
            uVar7 = *(uint *)(param_1 + 0x80);
            iVar5 = wserv_db_rd_wlan_binded_other_num(uVar9,uVar7);
            if (iVar5 < iVar4) {
              uVar2 = param_1 + 0x80U & 3;
              uVar3 = param_1 + 0x83U & 3;
              iVar4 = wserv_db_rd_bind(uVar9,(*(int *)((param_1 + 0x80U) - uVar2) << uVar2 * 8 |
                                             uVar7 & 0xffffffffU >> (4 - uVar2) * 8) &
                                             -1 << (uVar3 + 1) * 8 |
                                             *(uint *)((param_1 + 0x83U) - uVar3) >> (3 - uVar3) * 8
                                       ,*(undefined2 *)(param_1 + 0x123),local_30);
              if (iVar4 == -1) goto LAB_005dbc60;
              local_48 = wserv_db_wlanid_get_by_wservid(uVar9,*(undefined4 *)(param_1 + 0x80));
              local_48 = local_48 & 0xff;
              local_44 = *(undefined4 *)(param_1 + 0x80);
              local_40 = (uint)*(ushort *)(param_1 + 0x123);
              local_4c = uVar9;
              iVar4 = wserv_sqlite_notify(2,&local_4c,0x10);
              if (iVar4 == 0) {
                iVar10 = iVar10 + 1;
              }
              else if (g_wserv_error == 0) {
                iVar10 = iVar10 + 1;
              }
              else {
                iVar4 = is_target_debug_ap();
                if (iVar4 == 0) {
                  iVar10 = iVar10 + 1;
                }
                else {
                  printf("<wserv>[error]%s(): %d  -> wserv_sqlite_notify() WSERV_SQL_OP_RD_BIND fail: UPDATE %s SET WSERV%d=%d,VLAN%d=%d WHERE radio_id=%d;\r\n"
                         ,"_wserv_db_entry_auto_bind",0x1056,"bind_tbl",local_48,local_44,local_48,
                         local_40,local_4c);
                  iVar10 = iVar10 + 1;
                }
              }
            }
            else if (g_wserv_warning == 0) {
              iVar10 = iVar10 + 1;
            }
            else {
              iVar6 = is_target_debug_ap();
              if (iVar6 == 0) {
                iVar10 = iVar10 + 1;
              }
              else {
                printf("<wserv>[warning]%s(): %d  -> reach max ssid, wlan_cnt=%d, max_ssid=%d.\r\n",
                       "_wserv_db_entry_auto_bind",0x103b,iVar5,iVar4);
                iVar10 = iVar10 + 1;
              }
            }
          }
        }
      }
    }
  }
  return uVar9;
}

