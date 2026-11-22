// func wsta_db_sta_deassoc @ 0063a948 size=1596

undefined4 wsta_db_sta_deassoc(uint *param_1,code *param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_v1;
  char *__format;
  undefined4 uVar5;
  uint uVar6;
  char local_f8 [32];
  undefined1 auStack_d8 [44];
  undefined1 auStack_ac [24];
  undefined1 auStack_94 [80];
  undefined1 auStack_44 [28];
  
  local_f8[0] = '\0';
  local_f8[1] = '\0';
  local_f8[2] = '\0';
  local_f8[3] = '\0';
  local_f8[4] = '\0';
  local_f8[5] = '\0';
  local_f8[6] = '\0';
  local_f8[7] = '\0';
  local_f8[8] = '\0';
  local_f8[9] = '\0';
  local_f8[10] = '\0';
  local_f8[0xb] = '\0';
  local_f8[0xc] = '\0';
  local_f8[0xd] = '\0';
  local_f8[0xe] = '\0';
  local_f8[0xf] = '\0';
  local_f8[0x10] = '\0';
  local_f8[0x11] = '\0';
  local_f8[0x12] = '\0';
  local_f8[0x13] = '\0';
  memset(local_f8 + 0x14,0,0x38);
  if (((int)*param_1 < 0) || (iVar2 = apmngr_db_get_ap_max(), iVar2 <= (int)*param_1)) {
    if ((g_wsta_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      uVar6 = *param_1;
      __format = "<wsta>[warning]%s(): %d  -> invalid ap_id[%d]!\r\n";
      uVar5 = 0x87b;
LAB_0063aa70:
      printf(__format,"wsta_db_sta_deassoc",uVar5,uVar6);
      return 0xffffffff;
    }
  }
  else if ((*(char *)(param_1 + 1) == '\0') ||
          (uVar6 = rdmngr_profile_get_max_rd_per_ap(), uVar6 < *(byte *)(param_1 + 1))) {
    if (g_wsta_warning != 0) {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      uVar6 = (uint)*(byte *)(param_1 + 1);
      __format = "<wsta>[warning]%s(): %d  -> invalid rd_id[%d]!\r\n";
      uVar5 = 0x881;
      goto LAB_0063aa70;
    }
  }
  else if ((*(char *)((int)param_1 + 5) == '\0') ||
          (uVar6 = rdmngr_profile_get_max_wlan_per_rd(), uVar6 < *(byte *)((int)param_1 + 5))) {
    if (g_wsta_warning != 0) {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      uVar6 = (uint)*(byte *)((int)param_1 + 5);
      __format = "<wsta>[warning]%s(): %d  -> invalid wlan_id[%d]!\r\n";
      uVar5 = 0x887;
      goto LAB_0063aa70;
    }
  }
  else {
    if ((*(short *)((int)param_1 + 6) != 0) || (param_1[2] != 0)) {
      FUN_004082d0(DAT_007cc6bc,0xffffffff);
      iVar2 = FUN_00407fa0(DAT_007cc6cc,(int)param_1 + 6);
      if (iVar2 == 0) {
        if ((g_wsta_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("<wsta>[warning]%s(): %d  -> wsta[%02X:%02X:%02X:%02X:%02X:%02X] not found!\r\n",
                 "wsta_db_sta_deassoc",0x8d1,(uint)*(byte *)((int)param_1 + 6),
                 (uint)*(byte *)((int)param_1 + 7),(uint)*(byte *)(param_1 + 2),
                 (uint)*(byte *)((int)param_1 + 9),(uint)*(byte *)((int)param_1 + 10),
                 (uint)*(byte *)((int)param_1 + 0xb));
        }
        uVar5 = 1;
        DAT_007cc744 = DAT_007cc744 + 1;
      }
      else {
        if ((*(uint *)(iVar2 + 0x20) == *param_1) &&
           ((*(uint *)(iVar2 + 0x24) & 0xffff0000) == (param_1[1] & 0xffff0000))) {
          memcpy(auStack_94,(void *)(iVar2 + 0x18),0x68);
          iVar3 = wsta_calloc(1,0x80,"wsta_db_sta_deassoc",0x89f);
          if (iVar3 != 0) {
            memcpy((void *)(iVar3 + 0x18),(void *)(iVar2 + 0x18),0x68);
            FUN_00407e70();
            bVar1 = g_wsta_debug != 0;
            *(undefined4 *)(iVar3 + 0x30) = extraout_v1;
            if ((bVar1) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
              printf("<wsta>[debug]%s(): %d  -> disassoc.leave_time:%d, rssi_recv_time:%d.\n\r\n",
                     "wsta_db_sta_deassoc",0x8a5,*(undefined4 *)(iVar3 + 0x30),
                     *(undefined4 *)(iVar2 + 0x38));
            }
            iVar4 = FUN_00408380(DAT_007cc718,iVar3);
            if (iVar4 == 0) {
              iVar4 = FUN_00407ed0(DAT_007cc718);
              if ((0 < iVar4) && (DAT_007cc714 < 1)) {
                DAT_007cc714 = FUN_00408340(5,0,_wsta_del_sta_timer_handle,0,0,"wsta_db_sta_deassoc"
                                            ,0x8b1);
              }
              FUN_004086b0(&DAT_007cc71c,iVar3 + 0xc);
              if ((g_wsta_debug != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                printf("<wsta>[debug]%s(): %d  -> wsta_db_sta_deassoc mac:%02x:%02x:%02x:%02x:%02x:%02x.\n\r\n"
                       ,"wsta_db_sta_deassoc",0x8b6,(uint)*(byte *)(iVar3 + 0x68),
                       (uint)*(byte *)(iVar3 + 0x69),(uint)*(byte *)(iVar3 + 0x6a),
                       (uint)*(byte *)(iVar3 + 0x6b),(uint)*(byte *)(iVar3 + 0x6c),
                       (uint)*(byte *)(iVar3 + 0x6d));
              }
            }
            else {
              if ((g_wsta_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
                printf("<wsta>[error]%s(): %d  -> sta tmp hash add failed!\r\n",
                       "wsta_db_sta_deassoc",0x8a8);
              }
              wsta_free(iVar3);
            }
          }
          if ((g_wsta_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("<wsta>[debug]%s(): %d  -> free sta:%02x:%02x:%02x:%02x:%02x:%02x.\r\n",
                   "wsta_db_sta_deassoc",0x8ba,(uint)*(byte *)(iVar2 + 0x68),
                   (uint)*(byte *)(iVar2 + 0x69),(uint)*(byte *)(iVar2 + 0x6a),
                   (uint)*(byte *)(iVar2 + 0x6b),(uint)*(byte *)(iVar2 + 0x6c),
                   (uint)*(byte *)(iVar2 + 0x6d));
          }
          _wsta_free_entry(iVar2);
          FUN_00407f30(DAT_007cc6bc);
          if (param_2 != (code *)0x0) {
            (*param_2)(auStack_ac,param_3);
          }
          iVar2 = wsta_db_get_mac_entry_by_peer(auStack_44,local_f8 + 0x14);
          if ((iVar2 == 0) && (iVar2 = memcmp(auStack_d8,auStack_44,6), iVar2 != 0)) {
            return 0;
          }
          snprintf(local_f8,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)((int)param_1 + 6),
                   (uint)*(byte *)((int)param_1 + 7),(uint)*(byte *)(param_1 + 2),
                   (uint)*(byte *)((int)param_1 + 9),(uint)*(byte *)((int)param_1 + 10),
                   (uint)*(byte *)((int)param_1 + 0xb));
          loggerk_reg(0x5b,0x3a9a,1,local_f8,0);
          _uac_wstation_do_event(1,auStack_ac);
          return 0;
        }
        if ((g_wsta_warning != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("<wsta>[warning]%s(): %d  -> invalid deassoc args, wsta info[%d/%d/%d], deassoc wsta info[%d/%d/%d]!\r\n"
                 ,"wsta_db_sta_deassoc",0x898,*(undefined4 *)(iVar2 + 0x20),
                 (uint)*(byte *)(iVar2 + 0x24),(uint)*(byte *)(iVar2 + 0x25),*param_1,
                 (uint)*(byte *)(param_1 + 1),(uint)*(byte *)((int)param_1 + 5));
        }
        uVar5 = 0xffffffff;
        DAT_007cc748 = DAT_007cc748 + 1;
      }
      FUN_00407f30(DAT_007cc6bc);
      return uVar5;
    }
    if (g_wsta_warning != 0) {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      printf("<wsta>[warning]%s(): %d  -> invalid mac addr!\r\n","wsta_db_sta_deassoc",0x88d);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

