// func cloud_mngt_wsta_callback_sta_add @ 0048fae8 size=1924

undefined4 cloud_mngt_wsta_callback_sta_add(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *__s;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined4 local_f90;
  undefined4 local_f8c;
  undefined4 local_f88;
  undefined4 local_f84;
  undefined1 auStack_f80 [9];
  char local_f77;
  undefined1 auStack_f2c [9];
  char local_f23;
  undefined1 auStack_ed8 [8];
  byte local_ed0;
  undefined1 auStack_ecf [247];
  undefined1 auStack_dd8 [8];
  byte local_dd0;
  undefined1 auStack_dcf [247];
  undefined1 auStack_cd8 [368];
  undefined1 auStack_b68 [20];
  int local_b54;
  undefined1 local_ae8;
  int local_a1c;
  undefined1 auStack_9e8 [304];
  char acStack_8b8 [216];
  undefined1 auStack_7e0 [304];
  char acStack_6b0 [216];
  undefined1 auStack_5d8 [20];
  undefined4 local_5c4;
  undefined1 auStack_590 [6];
  char acStack_58a [650];
  undefined1 auStack_300 [20];
  undefined4 local_2ec;
  undefined1 auStack_2b8 [6];
  char acStack_2b2 [654];
  
  memset(auStack_300,0,0x2d8);
  memset(auStack_7e0,0,0x205);
  memset(auStack_f2c,0,0x54);
  local_f84 = 0xffffffff;
  local_f88 = 0xffffffff;
  memset(auStack_dd8,0,0x100);
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_wsta_callback_sta_add start\n",
           "cloud_mngt_wsta_callback_sta_add",0xee7);
  }
  if (ap_report_switch == 0) {
    return 0;
  }
  iVar1 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0x22),auStack_300);
  if (iVar1 == -1) {
    uVar6 = 0xffffffff;
    if (cloud_mngt_debug_switch == '\0') {
      return 0xffffffff;
    }
    pcVar4 = "[CLOUD_MNGT_DEBUG]%s()/%d get ap entry by id failed.\n";
    uVar5 = 0xeef;
LAB_0048feb4:
    printf(pcVar4,"cloud_mngt_wsta_callback_sta_add",uVar5);
  }
  else {
    iVar1 = _cloud_mngt_role_match(local_2ec);
    if (iVar1 == 0) {
      return 0;
    }
    uVar6 = 0xffffffff;
    puVar2 = (undefined4 *)FUN_00408450(0x14,0xef8);
    if (puVar2 == (undefined4 *)0x0) {
      return 0xffffffff;
    }
    puVar2[3] = 2;
    __s = (undefined4 *)FUN_00408450(0x30,0xefe);
    if (__s != (undefined4 *)0x0) {
      memset(__s,0,0x30);
      memcpy(__s + 1,(void *)(param_1 + 0x68),6);
      *__s = 1;
      iVar1 = FUN_00408450(0xe8,0xf08);
      __s[6] = iVar1;
      if (iVar1 != 0) {
        uVar7 = FUN_00407dd0();
        *(undefined8 *)(__s + 8) = uVar7;
        memset((void *)__s[6],0,0xe8);
        *(undefined4 *)__s[6] = 0;
        uVar6 = rdmngr_db_generate_rd_id
                          (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24));
        iVar1 = uac_wservice_get_wserv_id
                          (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                           *(undefined1 *)(param_1 + 0x25));
        if (iVar1 == -1) {
LAB_00490148:
          FUN_00407df0(puVar2);
          FUN_00407df0(__s[6]);
          FUN_00407df0(__s);
          return 0xffffffff;
        }
        iVar1 = uac_wservice_get_entry_by_id(iVar1,auStack_7e0);
        if (iVar1 != 0) goto LAB_00490148;
        iVar1 = rdmngr_db_rd_entry_get(uVar6,auStack_f2c);
        if ((iVar1 != 0) ||
           (iVar1 = rdmngr_db_get_freq_band_idx(uVar6,&local_f84,&local_f88), iVar1 != 0))
        goto LAB_00490148;
        *(undefined1 *)(__s + 10) = 0;
        memset(auStack_dd8,0,0x100);
        iVar1 = stats_db_ssid_get(*(undefined2 *)(param_1 + 0x22),*(undefined1 *)(param_1 + 0x24),
                                  *(undefined1 *)(param_1 + 0x25),auStack_dd8);
        if (iVar1 == 0) {
          if (*(char *)(param_1 + 0x25) == '\0') {
            iVar1 = __s[6];
          }
          else if ((local_dd0 & 3) == 3) {
            memcpy((void *)((int)__s + 0x29),auStack_dcf,6);
            *(undefined1 *)(__s + 10) = 1;
            iVar1 = __s[6];
          }
          else {
            iVar1 = __s[6];
          }
        }
        else {
          iVar1 = __s[6];
        }
        *(undefined2 *)(iVar1 + 0xd8) = *(undefined2 *)(param_1 + 0x2e);
        *(char *)(__s[6] + 0xe0) = (char)local_f84;
        *(char *)(__s[6] + 0xe1) = (char)local_f88;
        strncpy((char *)(__s[6] + 4),acStack_6b0,0x32);
        memcpy(__s + 4,auStack_2b8,6);
        strncpy((char *)(__s[6] + 0x37),acStack_2b2,0x9b);
        *(int *)(__s[6] + 0xd4) = (int)*(char *)(param_1 + 0x35);
        *(int *)(__s[6] + 0xdc) = (int)local_f23;
        *(undefined4 *)(__s[6] + 0xe4) = *(undefined4 *)(param_1 + 0x78);
        puVar2[4] = __s;
        FUN_004082d0(cloud_mngt_msg_mutex,0xffffffff);
        FUN_004086b0(&g_cloud_mngt_msg_list,puVar2);
        FUN_004084b0(cloud_mngt_msg_cond);
        FUN_00407f30(cloud_mngt_msg_mutex);
        memset(auStack_5d8,0,0x2d8);
        memset(auStack_9e8,0,0x205);
        memset(auStack_f80,0,0x54);
        local_f8c = 0xffffffff;
        local_f90 = 0xffffffff;
        memset(auStack_ed8,0,0x100);
        if (cloud_mngt_debug_switch != '\0') {
          printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_wsta_callback_sta_add start\n",
                 "cloud_mngt_wsta_callback_sta_add_events",0xe75);
        }
        if (ap_report_switch != 0) {
          iVar1 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_1 + 0x22),auStack_5d8);
          if (iVar1 == -1) {
            if (cloud_mngt_debug_switch != '\0') {
              pcVar4 = "[CLOUD_MNGT_DEBUG]%s()/%d get ap entry by id failed.\n";
              uVar6 = 0xe7d;
LAB_004901a4:
              printf(pcVar4,"cloud_mngt_wsta_callback_sta_add_events",uVar6);
            }
          }
          else {
            iVar1 = _cloud_mngt_role_match(local_5c4);
            if ((iVar1 != 0) &&
               (puVar2 = (undefined4 *)FUN_00408450(0x80,0xe86), puVar2 != (undefined4 *)0x0)) {
              memset(puVar2,0,0x80);
              memcpy(puVar2 + 1,(void *)(param_1 + 0x68),6);
              *puVar2 = 1;
              iVar1 = FUN_00408450(0xe8,0xe8f);
              puVar2[6] = iVar1;
              if (iVar1 != 0) {
                uVar7 = FUN_00407dd0();
                *(undefined8 *)(puVar2 + 8) = uVar7;
                memset((void *)puVar2[6],0,0xe8);
                *(undefined4 *)puVar2[6] = 0;
                uVar6 = rdmngr_db_generate_rd_id
                                  (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24));
                iVar1 = uac_wservice_get_wserv_id
                                  (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24),
                                   *(undefined1 *)(param_1 + 0x25));
                if ((iVar1 != -1) &&
                   (iVar3 = uac_wservice_get_entry_by_id(iVar1,auStack_9e8), iVar3 == 0)) {
                  iVar3 = uac_wservice_get_vlan
                                    (*(undefined4 *)(param_1 + 0x20),*(undefined1 *)(param_1 + 0x24)
                                     ,*(undefined1 *)(param_1 + 0x25),puVar2[6] + 0xd8);
                  if (iVar3 == 0) {
                    iVar3 = rdmngr_db_rd_entry_get(uVar6,auStack_f80);
                    if ((iVar3 == 0) &&
                       (iVar3 = rdmngr_db_get_freq_band_idx(uVar6,&local_f8c,&local_f90), iVar3 == 0
                       )) {
                      *(undefined1 *)(puVar2 + 10) = 0;
                      memset(auStack_ed8,0,0x100);
                      iVar3 = stats_db_ssid_get(*(undefined2 *)(param_1 + 0x22),
                                                *(undefined1 *)(param_1 + 0x24),
                                                *(undefined1 *)(param_1 + 0x25),auStack_ed8);
                      if ((iVar3 == 0) &&
                         ((*(char *)(param_1 + 0x25) != '\0' && ((local_ed0 & 3) == 3)))) {
                        memcpy((void *)((int)puVar2 + 0x29),auStack_ecf,6);
                        *(undefined1 *)(puVar2 + 10) = 1;
                      }
                      pcVar4 = (char *)(puVar2 + 0x16);
                      strcpy(pcVar4,"none");
                      iVar3 = wportal_db_ssid_rdt_get(iVar1,auStack_cd8);
                      if (iVar3 == 0) {
                        iVar3 = wportal_db_aut_get(param_1 + 0x68,auStack_b68);
                        if (((iVar3 == 0) && (local_a1c != 0xf)) && (local_b54 == iVar1)) {
                          cloud_mngt_authentication_real_type_get(local_ae8,pcVar4,0x14);
                          puVar2[0x1e] = 1;
                        }
                        else {
                          cloud_mngt_authentication_type_get(auStack_cd8,pcVar4,0x14);
                        }
                      }
                      memcpy(puVar2 + 0xc,(void *)(param_1 + 0x3c),0x14);
                      memcpy(puVar2 + 0x11,(void *)(param_1 + 0x50),0x14);
                      *(undefined1 *)((int)puVar2 + 0x2f) = *(undefined1 *)(param_1 + 0x24);
                      *(char *)(puVar2[6] + 0xe0) = (char)local_f8c;
                      *(char *)(puVar2[6] + 0xe1) = (char)local_f90;
                      strncpy((char *)(puVar2[6] + 4),acStack_8b8,0x32);
                      memcpy(puVar2 + 4,auStack_590,6);
                      strncpy((char *)(puVar2[6] + 0x37),acStack_58a,0x9b);
                      *(int *)(puVar2[6] + 0xd4) = (int)*(char *)(param_1 + 0x35);
                      *(int *)(puVar2[6] + 0xdc) = (int)local_f77;
                      *(undefined4 *)(puVar2[6] + 0xe4) = *(undefined4 *)(param_1 + 0x78);
                      uVar6 = get_ap_nms_mask(*(undefined4 *)(param_1 + 0x20));
                      puVar2[0x1d] = uVar6;
                      *(short *)(puVar2 + 0x1c) = (short)*(undefined4 *)(param_1 + 0x20);
                      iVar1 = FUN_00408540(client_events_container,puVar2);
                      if (iVar1 == 0) {
                        if (cloud_mngt_debug_switch != '\0') {
                          pcVar4 = 
                          "[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_wsta_callback_sta_add end\n";
                          uVar6 = 0xeda;
                          goto LAB_004901a4;
                        }
                        goto LAB_0048fe5c;
                      }
                      if (puVar2[6] != 0) {
                        FUN_00407df0();
                        puVar2[6] = 0;
                      }
                      goto LAB_00490138;
                    }
                  }
                }
                FUN_00407df0(puVar2[6]);
              }
LAB_00490138:
              FUN_00407df0(puVar2);
            }
          }
        }
LAB_0048fe5c:
        uVar6 = 0;
        if (cloud_mngt_debug_switch == '\0') {
          return 0;
        }
        pcVar4 = "[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_wsta_callback_sta_add end\n";
        uVar5 = 0xf3c;
        goto LAB_0048feb4;
      }
      FUN_00407df0(puVar2);
      puVar2 = __s;
    }
    FUN_00407df0(puVar2);
  }
  return uVar6;
}

