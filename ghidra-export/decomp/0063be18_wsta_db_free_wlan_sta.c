// func wsta_db_free_wlan_sta @ 0063be18 size=1428

undefined4
wsta_db_free_wlan_sta(uint param_1,uint param_2,uint param_3,code *param_4,undefined4 param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_v1;
  char *__format;
  undefined4 uVar6;
  int iVar7;
  void *__s1;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 auStack_64 [12];
  undefined1 auStack_58 [6];
  byte local_52;
  undefined1 auStack_4e [38];
  
  param_3 = param_3 & 0xff;
  param_2 = param_2 & 0xff;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  memset(auStack_64,0,0x38);
  if (((int)param_1 < 0) || (iVar2 = apmngr_db_get_ap_max(), iVar2 <= (int)param_1)) {
    if ((g_wsta_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      __format = "<wsta>[warning]%s(): %d  -> invalid ap_id[%d]!\r\n";
      uVar6 = 0x984;
      param_3 = param_1;
      goto LAB_0063bf34;
    }
  }
  else if ((param_2 == 0) || (uVar3 = rdmngr_profile_get_max_rd_per_ap(), uVar3 < param_2)) {
    if (g_wsta_warning != 0) {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      __format = "<wsta>[warning]%s(): %d  -> invalid rd_id[%d]!\r\n";
      uVar6 = 0x989;
      param_3 = param_2;
      goto LAB_0063bf34;
    }
  }
  else {
    if ((param_3 != 0) && (uVar3 = rdmngr_profile_get_max_wlan_per_rd(), param_3 <= uVar3)) {
      FUN_0051ad88(&local_70);
      FUN_004082d0(DAT_007cc6bc,0xffffffff);
      if (*(int *)(*(int *)(*(int *)(DAT_007cc6e4 + param_1 * 4) + (param_2 - 1) * 4) +
                   (param_3 - 1) * 0xc + 8) != 0) {
        iVar2 = FUN_004081b0();
        while (iVar2 != 0) {
          iVar4 = wsta_calloc(1,0x80,"wsta_db_free_wlan_sta",0x99b);
          if (iVar4 != 0) {
            memcpy((void *)(iVar4 + 0x18),(void *)(iVar2 + 0x18),0x68);
            FUN_004086b0(&local_70,iVar4 + 0xc);
          }
          __s1 = (void *)(iVar2 + 0x68);
          iVar4 = wsta_db_get_mac_entry_by_peer(__s1,auStack_64);
          if (iVar4 == 0) {
            uVar3 = 0;
LAB_0063c228:
            while (uVar3 < local_52) {
              iVar4 = memcmp(__s1,auStack_4e + uVar3 * 0xc,6);
              if ((iVar4 == 0) ||
                 (iVar4 = FUN_00407fa0(DAT_007cc6cc,auStack_4e + uVar3 * 0xc), iVar4 == 0)) {
                uVar3 = uVar3 + 1 & 0xff;
              }
              else {
                iVar7 = wsta_calloc(1,0x80,"wsta_db_free_wlan_sta",0x9ab);
                if (iVar7 != 0) {
                  memcpy((void *)(iVar7 + 0x18),(void *)(iVar4 + 0x18),0x68);
                  FUN_004086b0(&local_70,iVar7 + 0xc);
                }
                _wsta_free_entry(iVar4);
                uVar3 = uVar3 + 1 & 0xff;
              }
            }
            iVar4 = memcmp(__s1,auStack_58,6);
            if ((iVar4 != 0) && (iVar4 = FUN_00407fa0(DAT_007cc6cc,auStack_58), iVar4 != 0)) {
              iVar7 = wsta_calloc(1,0x80,"wsta_db_free_wlan_sta",0x9ba);
              if (iVar7 != 0) {
                memcpy((void *)(iVar7 + 0x18),(void *)(iVar4 + 0x18),0x68);
                FUN_004086b0(&local_70,iVar7 + 0xc);
              }
              _wsta_free_entry(iVar4);
            }
            wsta_db_free_mlo_mac_entry(auStack_64);
          }
          else {
            iVar4 = wsta_db_get_mac_entry_by_mld(__s1,auStack_64);
            uVar3 = 0;
            if (iVar4 == 0) goto LAB_0063c228;
          }
          iVar4 = FUN_00408680(iVar2);
          _wsta_free_entry(iVar2);
          iVar2 = iVar4;
        }
      }
      FUN_00407f30(DAT_007cc6bc);
      iVar2 = FUN_004081b0(&local_70);
      while (iVar2 != 0) {
        iVar4 = FUN_00408680(iVar2);
        iVar7 = iVar2 + -0xc;
        if (param_4 != (code *)0x0) {
          (*param_4)(iVar7,param_5);
        }
        _uac_wstation_do_event(1,iVar7);
        FUN_00407e70();
        bVar1 = g_wsta_debug != 0;
        *(undefined4 *)(iVar2 + 0x24) = extraout_v1;
        if ((bVar1) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("<wsta>[debug]%s(): %d  -> entry_tmp->leave_time:%d\t\r\n","wsta_db_free_wlan_sta",
                 0x9dd,*(undefined4 *)(iVar2 + 0x24));
        }
        FUN_004082d0(DAT_007cc6bc,0xffffffff);
        iVar5 = FUN_00408380(DAT_007cc718,iVar7);
        if (iVar5 == 0) {
          iVar7 = FUN_00407ed0(DAT_007cc718);
          if ((0 < iVar7) && (DAT_007cc714 < 1)) {
            DAT_007cc714 = FUN_00408340(5,0,_wsta_del_sta_timer_handle,0,0,"wsta_db_free_wlan_sta",
                                        0x9eb);
          }
          FUN_004086b0(&DAT_007cc71c,iVar2);
          if ((g_wsta_debug != 0) && (iVar7 = is_target_debug_ap(), iVar7 != 0)) {
            printf("<wsta>[debug]%s(): %d  -> wsta_db_free_wlan_sta mac:%02x:%02x:%02x:%02x:%02x:%02x.\n\r\n"
                   ,"wsta_db_free_wlan_sta",0x9f0,(uint)*(byte *)(iVar2 + 0x5c),
                   (uint)*(byte *)(iVar2 + 0x5d),(uint)*(byte *)(iVar2 + 0x5e),
                   (uint)*(byte *)(iVar2 + 0x5f),(uint)*(byte *)(iVar2 + 0x60),
                   (uint)*(byte *)(iVar2 + 0x61));
          }
        }
        else {
          if ((g_wsta_error != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            printf("<wsta>[error]%s(): %d  -> sta tmp hash add failed!\r\n","wsta_db_free_wlan_sta",
                   0x9e1);
          }
          FUN_00408500(iVar2);
          wsta_free(iVar7);
        }
        FUN_00407f30(DAT_007cc6bc);
        iVar2 = iVar4;
      }
      return 0;
    }
    if (g_wsta_warning != 0) {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      __format = "<wsta>[warning]%s(): %d  -> invalid wlan_id[%d]!\r\n";
      uVar6 = 0x98e;
LAB_0063bf34:
      printf(__format,"wsta_db_free_wlan_sta",uVar6,param_3);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

