// func _wportal_wtp_access_notify @ 0041dbcc size=6656

/* WARNING: Type propagation algorithm not settling */

undefined4 _wportal_wtp_access_notify(ushort param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar8;
  undefined1 uVar9;
  undefined1 *puVar6;
  void *__s;
  int iVar7;
  char *pcVar10;
  int *piVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  size_t sVar14;
  undefined1 *__dest;
  undefined4 *__s_00;
  undefined *puVar15;
  int iVar16;
  undefined4 *puVar17;
  uint uVar18;
  undefined1 local_778 [4];
  char *local_774;
  void *local_770;
  undefined4 local_76c;
  undefined4 local_768;
  undefined4 local_764;
  undefined4 local_760;
  undefined1 auStack_75c [8];
  int local_754;
  undefined4 local_74c;
  undefined4 local_748;
  undefined4 local_744;
  undefined4 local_740;
  undefined4 local_73c;
  int local_738 [7];
  char local_71c [8];
  undefined4 local_714;
  undefined4 local_710;
  undefined4 local_70c;
  undefined4 local_684;
  int local_680;
  undefined4 local_664;
  undefined4 local_660;
  undefined4 local_64c;
  char local_5d8 [128];
  char local_558 [180];
  int local_4a4;
  undefined4 local_484;
  undefined4 local_480;
  int local_47c;
  undefined1 auStack_46c [308];
  undefined4 local_338;
  undefined1 auStack_300 [20];
  uint local_2ec;
  
  uVar18 = (uint)param_1;
  local_738[0] = 0;
  local_738[1] = 0;
  local_738[2] = 0;
  local_738[3] = 0;
  local_738[4] = 0;
  local_738[5] = 0;
  local_738[6] = 0;
  memset(auStack_300,0,0x2d8);
  local_768 = 0;
  local_764 = 0;
  local_760 = 0;
  local_778[0] = 0;
  if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d WTP access notify, id: %d, config_changed: %d\n\n",
           "_wportal_wtp_access_notify",0x2b10,uVar18,param_2);
  }
  iVar2 = apmngr_db_entry_get_by_id(uVar18,auStack_300);
  if (iVar2 == -1) {
    uVar13 = 0xffffffff;
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar10 = "[WPORTAL_ERR]%s()/%d get ap entry by id failed.\n";
    uVar12 = 0x2b13;
LAB_0041de38:
    printf(pcVar10,"_wportal_wtp_access_notify",uVar12);
    return uVar13;
  }
  if (((((1 < local_2ec) && (local_2ec != 3)) && (local_2ec != 2)) &&
      ((local_2ec != 4 && (local_2ec != 8)))) && (local_2ec != 6)) {
    uVar13 = 0;
    if (wportal_debug_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    pcVar10 = "[WPORTAL_DBG]%s()/%d No need to handle for no-AP.\n";
    uVar12 = 0x2b18;
    goto LAB_0041de38;
  }
  iVar2 = apmngr_db_capacity_support(uVar18,1,0x38);
  if (iVar2 == 1) {
    memset(auStack_46c,0,0x16c);
    local_338 = 0x1000;
    iVar2 = wportal_db_rdt_add(auStack_46c);
    if (((iVar2 == 0) && (wportal_info_switch != 0)) &&
       (iVar2 = is_target_debug_ap(local_738 + 1), iVar2 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d roam portal added successfully\n","_wportal_wtp_access_notify",
             0x2b24);
    }
  }
  local_738[1] = 0;
  local_738[2] = 0;
  local_738[3] = 0;
  local_738[4] = 0;
  local_738[5] = 0;
  local_738[6] = 0;
  local_738[0] = (uint)param_1 << 0x10;
  FUN_0051ad88(local_738 + 1);
  FUN_0051ad88(local_738 + 4);
  if (g_portal_auth_mode == 1) {
    iVar2 = apmngr_db_capacity_support(uVar18,1,0x38);
    if (iVar2 == 1) {
      uac_wservice_for_each_vlan_bind_ap(uVar18,_wportal_wtp_access_manage_for_vlan,local_738);
      memset(local_5d8,0,0x16c);
      iVar2 = 0;
      do {
        iVar3 = wportal_db_rdt_get_by_vlan(iVar2,local_5d8);
        if (iVar3 != 0) break;
        if (local_4a4 != 0) {
          if (local_5d8[0] != '\0') {
            puVar6 = (undefined1 *)FUN_00408450(0xb8,0x2a29);
            if (puVar6 == (undefined1 *)0x0) break;
            memset(puVar6,0,0xb8);
            piVar11 = (int *)_wportal_url_parser(local_5d8);
            if ((wportal_info_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("[WPORTAL_INFO]%s()/%d Download fail url: %s\n\n",
                     "_wportal_wtp_access_update_all_free_strg_for_vlan",0x2a31,local_5d8);
            }
            if (piVar11 == (int *)0x0) {
              if ((wportal_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                printf("[WPORTAL_ERR]%s()/%d unknown rdtEntry.fail_url: %s\n\n",
                       "_wportal_wtp_access_update_all_free_strg_for_vlan",0x2a64,local_5d8);
              }
              *puVar6 = 2;
              memcpy(puVar6 + 0x2a,local_5d8,0x80);
              puVar6[0x14] = 1;
              *(int *)(puVar6 + 0x20) = local_4a4;
              *(undefined4 *)(puVar6 + 0x10) = local_484;
              FUN_004086b0(local_738 + 4,puVar6 + 4);
            }
            else {
              if (*piVar11 == 0) {
                *puVar6 = 0;
                puVar6[0x14] = 0;
                *(int *)(puVar6 + 0x2c) = piVar11[2];
                *(undefined4 *)(puVar6 + 0x30) = 0xffffffff;
                if ((local_47c != 0x10) && (local_47c != 0x20)) {
                  *(int *)(puVar6 + 0x3c) = piVar11[6];
                  *(int *)(puVar6 + 0x40) = piVar11[6];
                }
                *(undefined4 *)(puVar6 + 0x44) = 6;
LAB_0041e714:
                *(int *)(puVar6 + 0x20) = local_4a4;
              }
              else {
                if (*piVar11 != 1) {
                  *puVar6 = 2;
                  memcpy(puVar6 + 0x2a,piVar11 + 7,0x80);
                  puVar6[0x14] = 1;
                  goto LAB_0041e714;
                }
                *puVar6 = 1;
                puVar6[0x14] = 0;
                memcpy(puVar6 + 0x36,piVar11 + 2,0x10);
                *(undefined4 *)(puVar6 + 0x48) = 0x80;
                if ((local_47c != 0x10) && (local_47c != 0x20)) {
                  *(int *)(puVar6 + 0x54) = piVar11[6];
                  *(int *)(puVar6 + 0x58) = piVar11[6];
                }
                *(undefined4 *)(puVar6 + 0x5c) = 6;
                *(int *)(puVar6 + 0x2c) = local_4a4;
                FUN_00408480(puVar6 + 0x36,*(undefined4 *)(puVar6 + 0x48),puVar6 + 0x36);
              }
              *(undefined4 *)(puVar6 + 0x10) = local_484;
              FUN_004086b0(local_738 + 4,puVar6 + 4);
              FUN_00407df0(piVar11);
            }
          }
          if (local_558[0] != '\0') {
            if ((wportal_info_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("[WPORTAL_INFO]%s()/%d  rdtEntry->auth_type is: %d cloud cloud_server_num is %d \n\n"
                     ,"_wportal_wtp_access_update_all_free_strg_for_vlan",0x2a78,local_47c,
                     cloud_server_num);
            }
            if (local_47c == 0x40) {
              if ((wportal_info_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                printf("[WPORTAL_INFO]%s()/%d no need to send cloud free to ap!!\n",
                       "_wportal_wtp_access_update_all_free_strg_for_vlan",0x2a7b);
              }
            }
            else {
              puVar6 = (undefined1 *)FUN_00408450(0xb8,0x2a7f);
              if (puVar6 == (undefined1 *)0x0) break;
              memset(puVar6,0,0xb8);
              piVar11 = (int *)_wportal_url_parser(local_558);
              if ((wportal_info_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                printf("[WPORTAL_INFO]%s()/%d Download portal url: %s\n\n",
                       "_wportal_wtp_access_update_all_free_strg_for_vlan",0x2a86,local_558);
              }
              if (piVar11 == (int *)0x0) {
                if ((wportal_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                  printf("[WPORTAL_ERR]%s()/%d unknown portal url: %s\n\n",
                         "_wportal_wtp_access_update_all_free_strg_for_vlan",0x2ab3,local_558);
                }
                *puVar6 = 2;
                memcpy(puVar6 + 0x2a,local_558,0x80);
                puVar6[0x14] = 1;
                *(int *)(puVar6 + 0x20) = local_4a4;
                *(undefined4 *)(puVar6 + 0x10) = local_480;
                FUN_004086b0(local_738 + 4,puVar6 + 4);
              }
              else {
                if (*piVar11 == 0) {
                  *puVar6 = 0;
                  puVar6[0x14] = 0;
                  *(int *)(puVar6 + 0x2c) = piVar11[2];
                  *(undefined4 *)(puVar6 + 0x30) = 0xffffffff;
                  *(int *)(puVar6 + 0x3c) = piVar11[6];
                  *(int *)(puVar6 + 0x40) = piVar11[6];
                  *(undefined4 *)(puVar6 + 0x44) = 6;
LAB_0041e7e8:
                  *(int *)(puVar6 + 0x20) = local_4a4;
                }
                else {
                  if (*piVar11 != 1) {
                    *puVar6 = 2;
                    memcpy(puVar6 + 0x2a,piVar11 + 7,0x80);
                    puVar6[0x14] = 1;
                    goto LAB_0041e7e8;
                  }
                  __dest = puVar6 + 0x36;
                  *puVar6 = 1;
                  puVar6[0x14] = 0;
                  memcpy(__dest,piVar11 + 2,0x10);
                  *(undefined4 *)(puVar6 + 0x48) = 0x80;
                  *(int *)(puVar6 + 0x54) = piVar11[6];
                  *(int *)(puVar6 + 0x58) = piVar11[6];
                  *(undefined4 *)(puVar6 + 0x5c) = 6;
                  *(int *)(puVar6 + 0x2c) = local_4a4;
                  FUN_00408480(__dest,0x80,__dest);
                }
                *(undefined4 *)(puVar6 + 0x10) = local_480;
                FUN_004086b0(local_738 + 4,puVar6 + 4);
                FUN_00407df0(piVar11);
              }
            }
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0x1000);
    }
    else {
      uac_wservice_for_each_vlan_bind_ap(uVar18,_wportal_wtp_access_manage_for_vlan,local_738);
    }
  }
  else {
    if (g_portal_auth_mode != 0) {
      __s_00 = (undefined4 *)0x0;
      if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d Portal mode error: %d\n","_wportal_wtp_access_notify",0x2b47,
               g_portal_auth_mode);
      }
      goto LAB_0041dd44;
    }
    uac_wservice_for_each_entry_bind_ap(uVar18,_wportal_wtp_access_manage_for_ssid,local_738);
  }
  iVar2 = FUN_00407fe0(local_738 + 1);
  iVar3 = FUN_00407fe0(local_738 + 4);
  iVar4 = apmngr_db_capacity_support(uVar18,1,2);
  if (iVar4 == 1) {
    iVar4 = _wportal_db_support_new_portal_by_id(uVar18);
    iVar16 = iVar2 + 1;
    if (iVar4 == 0) {
      sVar14 = iVar3 * 0x9c + 0x18 + iVar16 * 0x16c;
      __s_00 = (undefined4 *)FUN_00408450(sVar14,0x2bcd);
      if (__s_00 != (undefined4 *)0x0) {
        memset(__s_00,0,sVar14);
        *__s_00 = 9;
        iVar4 = FUN_004081b0(local_738 + 1);
        iVar5 = 0x18;
        for (iVar16 = 0; iVar16 < iVar2; iVar16 = iVar16 + 1) {
          iVar7 = *(int *)(iVar4 + 0xc);
          piVar11 = (int *)((int)__s_00 + iVar5);
          if (iVar7 == 0) {
            iVar7 = 0xfff;
          }
          *piVar11 = iVar7;
          if (g_portal_auth_mode == 1) {
            pcVar10 = "http://192.168.1.253:%d/wportal/?pagetype=%d";
          }
          else {
            pcVar10 = "http://192.168.1.253:%d/wportal/?ssid_mode=true&pagetype=%d";
            if (g_portal_auth_mode != 0) {
              if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_0041dd44;
              pcVar10 = "[WPORTAL_ERR]%s()/%d Portal mode error\n";
              uVar13 = 0x2beb;
              goto LAB_0041e32c;
            }
          }
          iVar5 = iVar5 + 0x84;
          snprintf((char *)(piVar11 + 1),0x80,pcVar10,g_portal_port,100);
          iVar4 = FUN_00408680(iVar4);
        }
        iVar2 = apmngr_db_capacity_support(uVar18,1,0x38);
        if (iVar2 == 1) {
          if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[WPORTAL_INFO]%s()/%d prev count =%d\n","_wportal_wtp_access_notify",0x2bf7,
                   iVar16);
          }
          __s_00[iVar16 * 0x21 + 6] = 0x1000;
          if (g_portal_auth_mode == 1) {
            pcVar10 = "http://192.168.1.253:%d/wportal/?pagetype=%d";
          }
          else {
            if (g_portal_auth_mode != 0) {
              if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_0041dd44;
              pcVar10 = "[WPORTAL_ERR]%s()/%d Portal mode error\n";
              uVar13 = 0x2c04;
              goto LAB_0041e32c;
            }
            pcVar10 = "http://192.168.1.253:%d/wportal/?ssid_mode=true&pagetype=%d";
          }
          iVar5 = iVar5 + 0x84;
          snprintf((char *)(__s_00 + iVar16 * 0x21 + 6 + 1),0x80,pcVar10,g_portal_port,100);
          iVar16 = iVar16 + 1;
        }
        __s_00[3] = iVar16;
        goto LAB_0041edfc;
      }
      if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
      goto LAB_0041dd44;
      pcVar10 = "[WPORTAL_ERR]%s()/%d Malloc buffer error\n";
      uVar13 = 0x2bd0;
    }
    else {
      iVar4 = rdmngr_profile_get_max_rd_per_ap();
      iVar5 = rdmngr_profile_get_max_wlan_per_rd();
      sVar14 = iVar2 + 0x19 + iVar3 * 0x9c + iVar16 * 0x16c + iVar16 * 0x10 * iVar4 * iVar5;
      __s_00 = (undefined4 *)FUN_00408450(sVar14,0x2b5b);
      if (__s_00 == (undefined4 *)0x0) {
        if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_0041dd44;
        pcVar10 = "[WPORTAL_ERR]%s()/%d Malloc buffer error\n";
        uVar13 = 0x2b5e;
      }
      else {
        memset(__s_00,0,sVar14);
        *__s_00 = 0x1b;
        puVar17 = __s_00 + 6;
        iVar16 = FUN_004081b0(local_738 + 1);
        iVar4 = 0;
        while (iVar4 < iVar2) {
          uVar8 = 0xfff;
          if (*(int *)(iVar16 + 0xc) != 0) {
            uVar8 = (short)*(int *)(iVar16 + 0xc);
          }
          *(undefined2 *)puVar17 = uVar8;
          if (g_portal_auth_mode == 1) {
            snprintf((char *)((int)puVar17 + 2),0x80,"http://192.168.1.253:%d/wportal/?pagetype=%d",
                     g_portal_port,100);
            *(undefined1 *)((int)puVar17 + 0x82) = 0xff;
            puVar17 = (undefined4 *)((int)puVar17 + 0x83);
          }
          else {
            if (g_portal_auth_mode != 0) {
              if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_0041dd44;
              pcVar10 = "[WPORTAL_ERR]%s()/%d Portal mode error\n";
              uVar13 = 0x2b93;
              goto LAB_0041e32c;
            }
            snprintf((char *)((int)puVar17 + 2),0x80,
                     "http://192.168.1.253:%d/wportal/?ssid_mode=true&pagetype=%d",g_portal_port,100
                    );
            FUN_0051ad88(&local_768);
            iVar5 = *(int *)(iVar16 + 0xc);
            if (iVar5 == 0xfff) {
              iVar5 = 0;
            }
            uac_wservice_for_ap_bind_vlan(iVar5,uVar18,_wportal_collect_ssid_info_cb,&local_768);
            uVar9 = FUN_00407fe0(&local_768);
            *(undefined1 *)((int)puVar17 + 0x82) = uVar9;
            puVar17 = (undefined4 *)((int)puVar17 + 0x83);
            iVar5 = FUN_004081b0(&local_768);
            if (iVar5 != 0) {
              uVar9 = *(undefined1 *)(iVar5 + 0xc);
              while( true ) {
                *(undefined1 *)puVar17 = uVar9;
                *(undefined1 *)((int)puVar17 + 1) = *(undefined1 *)(iVar5 + 0xd);
                puVar17 = (undefined4 *)((int)puVar17 + 2);
                iVar5 = FUN_00408680(iVar5);
                if (iVar5 == 0) break;
                uVar9 = *(undefined1 *)(iVar5 + 0xc);
              }
            }
          }
          while( true ) {
            iVar5 = FUN_004081b0(&local_768);
            if (iVar5 == 0) break;
            FUN_00408500(iVar5);
            FUN_00407df0(iVar5);
          }
          iVar16 = FUN_00408680(iVar16);
          iVar4 = iVar4 + 1;
        }
        iVar2 = apmngr_db_capacity_support(uVar18,1,0x38);
        if (iVar2 == 1) {
          if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[WPORTAL_INFO]%s()/%d prev count =%d\n","_wportal_wtp_access_notify",0x2ba6,
                   iVar4);
          }
          *(undefined2 *)puVar17 = 0x1000;
          if (g_portal_auth_mode == 1) {
            pcVar10 = "http://192.168.1.253:%d/wportal/?pagetype=%d";
          }
          else {
            if (g_portal_auth_mode != 0) {
              if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_0041dd44;
              pcVar10 = "[WPORTAL_ERR]%s()/%d Portal mode error\n";
              uVar13 = 0x2bba;
              goto LAB_0041e32c;
            }
            pcVar10 = "http://192.168.1.253:%d/wportal/?ssid_mode=true&pagetype=%d";
          }
          snprintf((char *)((int)puVar17 + 2),0x80,pcVar10,g_portal_port,100);
          *(undefined1 *)((int)puVar17 + 0x82) = 0xff;
          __s_00[3] = iVar4 + 1;
          iVar5 = (int)puVar17 + (0x83 - (int)__s_00);
        }
        else {
          iVar5 = (int)puVar17 - (int)__s_00;
          __s_00[3] = iVar4;
        }
LAB_0041edfc:
        iVar2 = FUN_004081b0(local_738 + 4);
        iVar4 = 0;
        for (iVar16 = 0; iVar16 < iVar3; iVar16 = iVar16 + 1) {
          memset(local_71c,0,0x40);
          if (*(char *)(iVar2 + -4) != '\x01') {
            puVar17 = (undefined4 *)((int)__s_00 + iVar5);
            if (*(char *)(iVar2 + 0x10) == '\x01') {
              *puVar17 = *(undefined4 *)(iVar2 + 0xc);
              iVar5 = iVar5 + 0x9c;
              iVar4 = iVar4 + 1;
              *(undefined1 *)(puVar17 + 1) = *(undefined1 *)(iVar2 + 0x10);
              puVar17[2] = *(undefined4 *)(iVar2 + 0x14);
              puVar17[3] = *(undefined4 *)(iVar2 + 0x18);
              puVar17[4] = *(undefined4 *)(iVar2 + 0x1c);
              memcpy(puVar17 + 5,(void *)(iVar2 + 0x20),6);
              memcpy((void *)((int)puVar17 + 0x1a),(void *)(iVar2 + 0x26),0x80);
            }
            else if (*(char *)(iVar2 + 0x10) == '\0') {
              pcVar10 = inet_ntop(2,(void *)(iVar2 + 0x28),local_71c,0x40);
              if (pcVar10 != (char *)0x0) {
                *puVar17 = *(undefined4 *)(iVar2 + 0xc);
                iVar5 = iVar5 + 0x9c;
                iVar4 = iVar4 + 1;
                *(undefined1 *)(puVar17 + 1) = *(undefined1 *)(iVar2 + 0x10);
                puVar17[7] = *(undefined4 *)(iVar2 + 0x28);
                puVar17[8] = *(undefined4 *)(iVar2 + 0x2c);
                puVar17[4] = *(undefined4 *)(iVar2 + 0x1c);
                memcpy(puVar17 + 5,(void *)(iVar2 + 0x20),6);
                puVar17[0xb] = *(undefined4 *)(iVar2 + 0x38);
                puVar17[0xc] = *(undefined4 *)(iVar2 + 0x3c);
                puVar17[0xd] = *(undefined4 *)(iVar2 + 0x40);
              }
            }
          }
          iVar2 = FUN_00408680(iVar2);
        }
        __s_00[5] = iVar4;
        if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[WPORTAL_INFO]%s()/%d Portal count: %d, free strategy count: %d\n",
                 "_wportal_wtp_access_notify",0x2c43,__s_00[3],__s_00[5]);
        }
        __s_00[1] = g_portal_port;
        serv_wtp_address_arg_init(auStack_75c);
        apmngr_db_get_addr_by_capacity(uVar18,auStack_75c,1,1,0x15f0000,0);
        iVar2 = _wportal_update_to_ap(__s_00,iVar5,auStack_75c,1);
        if (((iVar2 != 0) && (wportal_debug_switch != 0)) &&
           (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[WPORTAL_DBG]%s()/%d Update to ap error\n","_wportal_wtp_access_notify",0x2c4c);
        }
        serv_wtp_address_arg_destroy(auStack_75c);
        FUN_00407df0(__s_00);
        iVar2 = apmngr_db_capacity_support(uVar18,1,0x21);
        if (iVar2 != 1) goto LAB_0041e128;
        sVar14 = iVar3 * 0xa8 + 0x18;
        __s_00 = (undefined4 *)FUN_00408450(sVar14,0x2c5d);
        if (__s_00 != (undefined4 *)0x0) {
          memset(__s_00,0,sVar14);
          iVar2 = _wportal_db_support_new_portal_by_id(uVar18);
          uVar13 = 0x1c;
          iVar4 = 0;
          if (iVar2 == 0) {
            uVar13 = 0x13;
          }
          iVar16 = 0x18;
          iVar5 = 0;
          *__s_00 = uVar13;
          iVar2 = FUN_004081b0(local_738 + 4);
          for (; iVar4 < iVar3; iVar4 = iVar4 + 1) {
            if (*(char *)(iVar2 + -4) == '\x01') {
              puVar17 = (undefined4 *)((int)__s_00 + iVar16);
              *puVar17 = *(undefined4 *)(iVar2 + 0xc);
              *(undefined1 *)(puVar17 + 1) = *(undefined1 *)(iVar2 + 0x10);
              memset(puVar17 + 2,0,0x10);
              puVar17[6] = *(undefined4 *)(iVar2 + 0x24);
              puVar17[7] = *(undefined4 *)(iVar2 + 0x28);
              memcpy(puVar17 + 8,(void *)(iVar2 + 0x2c),6);
              memcpy((void *)((int)puVar17 + 0x26),(void *)(iVar2 + 0x32),0x80);
              if ((wportal_info_switch == 0) || (iVar7 = is_target_debug_ap(), iVar7 == 0)) {
                iVar16 = iVar16 + 0xa8;
                iVar5 = iVar5 + 1;
              }
              else {
                printf("[WPORTAL_INFO]%s()/%d temp->url_type.url is [%s] id[%d]\n",
                       "_wportal_wtp_access_notify",0x2c82,(void *)((int)puVar17 + 0x26),*puVar17);
                iVar16 = iVar16 + 0xa8;
                iVar5 = iVar5 + 1;
              }
            }
            iVar2 = FUN_00408680(iVar2);
          }
          __s_00[5] = iVar5;
          __s_00[1] = g_portal_port;
          serv_wtp_address_arg_init(auStack_75c);
          apmngr_db_get_addr_by_capacity(uVar18,auStack_75c,1,1,0x15f0000,0);
          iVar2 = _wportal_update_to_ap(__s_00,iVar16,auStack_75c,1);
          if (((iVar2 != 0) && (wportal_debug_switch != 0)) &&
             (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            uVar13 = 0x2c91;
            goto LAB_0041e10c;
          }
          goto LAB_0041e114;
        }
        __s_00 = (undefined4 *)0x0;
        if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_0041dd44;
        pcVar10 = "[WPORTAL_ERR]%s()/%d Malloc buffer error\n";
        uVar13 = 0x2c60;
      }
    }
LAB_0041e32c:
    printf(pcVar10,"_wportal_wtp_access_notify",uVar13);
    goto LAB_0041dd44;
  }
  sVar14 = iVar3 * 0x34 + 0x18 + (iVar2 + 1) * 0x16c;
  if ((wportal_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d WTP access buffer len: %d\n","_wportal_wtp_access_notify",0x2ca4,
           sVar14);
  }
  if ((wportal_info_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d Create WPORTAL_AP_EVENT_BUILD_CAPWAP buffer len: %d\n",
           "_wportal_wtp_access_notify",0x2ca5,sVar14);
  }
  __s_00 = (undefined4 *)FUN_00408450(sVar14,0x2ca7);
  if (__s_00 == (undefined4 *)0x0) {
    if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0041dd44;
    pcVar10 = "[WPORTAL_ERR]%s()/%d Malloc buffer error\n";
    uVar13 = 0x2caa;
    goto LAB_0041e32c;
  }
  memset(__s_00,0,sVar14);
  *__s_00 = 9;
  if ((wportal_info_switch != 0) && (iVar3 = is_target_debug_ap(local_738 + 1), iVar3 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d Vlan count: %d\n","_wportal_wtp_access_notify",0x2cb3,iVar2);
  }
  iVar3 = FUN_004081b0(local_738 + 1);
  iVar16 = 0x18;
  for (iVar4 = 0; iVar4 < iVar2; iVar4 = iVar4 + 1) {
    iVar5 = *(int *)(iVar3 + 0xc);
    piVar11 = (int *)((int)__s_00 + iVar16);
    if (iVar5 == 0) {
      iVar5 = 0xfff;
    }
    *piVar11 = iVar5;
    if (g_portal_auth_mode == 1) {
      pcVar10 = "http://192.168.1.253:%d/wportal/?pagetype=%d";
    }
    else {
      pcVar10 = "http://192.168.1.253:%d/wportal/?ssid_mode=true&pagetype=%d";
      if (g_portal_auth_mode != 0) {
        if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_0041dd44;
        pcVar10 = "[WPORTAL_ERR]%s()/%d Portal mode error\n";
        uVar13 = 0x2cc6;
        goto LAB_0041e32c;
      }
    }
    iVar16 = iVar16 + 0x84;
    snprintf((char *)(piVar11 + 1),0x80,pcVar10,g_portal_port,100);
    iVar3 = FUN_00408680(iVar3);
  }
  iVar2 = apmngr_db_capacity_support(uVar18,1,0x38);
  if (iVar2 == 1) {
    if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d prev count =%d\n","_wportal_wtp_access_notify",0x2cd2,iVar4);
    }
    __s_00[iVar4 * 0x21 + 6] = 0x1000;
    if (g_portal_auth_mode == 1) {
      pcVar10 = "http://192.168.1.253:%d/wportal/?pagetype=%d";
    }
    else {
      if (g_portal_auth_mode != 0) {
        if ((wportal_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_0041dd44;
        pcVar10 = "[WPORTAL_ERR]%s()/%d Portal mode error\n";
        uVar13 = 0x2cdf;
        goto LAB_0041e32c;
      }
      pcVar10 = "http://192.168.1.253:%d/wportal/?ssid_mode=true&pagetype=%d";
    }
    iVar16 = iVar16 + 0x84;
    snprintf((char *)(__s_00 + iVar4 * 0x21 + 6 + 1),0x80,pcVar10,g_portal_port,100);
    iVar4 = iVar4 + 1;
  }
  bVar1 = wportal_info_switch != 0;
  __s_00[3] = iVar4;
  if ((bVar1) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d Portal count: %d, free strategy count: %d\n",
           "_wportal_wtp_access_notify",0x2ce9,__s_00[3],__s_00[5]);
  }
  __s_00[1] = g_portal_port;
  serv_wtp_address_arg_init(auStack_75c);
  apmngr_db_get_addr_by_capacity(uVar18,auStack_75c,0,1,0x15f0000,1,2);
  iVar2 = _wportal_update_to_ap(__s_00,iVar16,auStack_75c,1);
  if (((iVar2 != 0) && (wportal_debug_switch != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    uVar13 = 0x2cf2;
LAB_0041e10c:
    printf("[WPORTAL_DBG]%s()/%d Update to ap error\n","_wportal_wtp_access_notify",uVar13);
  }
LAB_0041e114:
  serv_wtp_address_arg_destroy(auStack_75c);
  FUN_00407df0(__s_00);
LAB_0041e128:
  serv_wtp_address_arg_init(auStack_75c);
  iVar2 = apmngr_db_capacity_support(uVar18,1,2);
  if (iVar2 == 1) {
    apmngr_db_get_addr_by_capacity(uVar18,auStack_75c,1,1,0x15f0000,0);
    if (local_754 != 0) {
      _wportal_common_free_strategy_arg_add(auStack_75c,1);
      apmngr_db_get_addr_by_capacity(uVar18,auStack_75c,1,1,0x15f0000,1,0x21);
      if (local_754 != 0) {
        FUN_004082d0(wportal_free_strategy_packet_mutex,0xffffffff);
        serv_wtp_address_arg_move(&free_strategy_arg_v6,auStack_75c);
        FUN_00407f30(wportal_free_strategy_packet_mutex);
      }
    }
  }
  else {
    apmngr_db_get_addr_by_capacity(uVar18,auStack_75c,0,1,0x15f0000,1,2);
    if (local_754 != 0) {
      _wportal_common_free_strategy_arg_add(auStack_75c,0);
    }
  }
  if (99 < (uint)(DAT_00759f6c + DAT_00759f7c + DAT_00759f5c)) {
    _wportal_common_free_strategy_send();
  }
  serv_wtp_address_arg_destroy(auStack_75c);
  _wportal_refresh_port(uVar18);
  wportal_wechatlist_download();
  if (wechat_server_ip != '\0') {
    sVar14 = strlen(&wechat_server_ip);
    pcVar10 = (char *)(sVar14 + 1);
    local_71c[0] = '\0';
    local_71c[1] = '\0';
    local_71c[2] = '\0';
    local_71c[3] = '\0';
    local_71c[4] = '\0';
    local_71c[5] = '\0';
    local_71c[6] = '\0';
    local_71c[7] = '\0';
    local_714 = 0;
    local_710 = 0;
    local_70c = 0;
    local_774 = (char *)0x0;
    local_770 = (void *)0x0;
    __s = (void *)FUN_00408450(pcVar10,0x5d8);
    if (__s != (void *)0x0) {
      memset(__s,0,(size_t)pcVar10);
      memcpy(__s,&wechat_server_ip,(size_t)pcVar10);
      iVar2 = cw_pkt_buf_create(0xfa);
      if (iVar2 == 0) {
        iVar3 = 0;
      }
      else {
        FUN_0051ad88(&local_714);
        local_774 = pcVar10;
        local_770 = __s;
        iVar3 = cw_parsed_pkt_create(7);
        if (((iVar3 != 0) &&
            (iVar4 = cw_service_msg_add(iVar3,0x25,local_71c,1,0x42,&local_774), iVar4 != -1)) &&
           ((iVar4 = capwap_packet_assemble(iVar2,iVar3), iVar4 != -1 &&
            (iVar4 = serv_wtp_address_arg_init(&local_74c), iVar4 != -1)))) {
          apmngr_db_get_addr_by_capacity(uVar18,&local_74c,1,1,0x15f0000,1,7);
          serv_packet_send(&local_74c,iVar2,1);
          FUN_00407df0(__s);
          cw_parsed_pkt_destroy(iVar3);
          cw_pkt_buf_destroy(iVar2);
          serv_wtp_address_arg_destroy(&local_74c);
          goto LAB_0041e1dc;
        }
      }
      FUN_00407df0(__s);
      if (iVar2 != 0) {
        cw_pkt_buf_destroy(iVar2);
      }
      if (iVar3 != 0) {
        cw_parsed_pkt_destroy(iVar3);
      }
    }
  }
LAB_0041e1dc:
  local_774 = (char *)0x0;
  local_770 = (void *)0x0;
  local_76c = 0;
  memset(local_71c,0,0x144);
  local_74c = 0;
  local_748 = 0;
  local_744 = 0;
  local_740 = 0;
  local_73c = 0;
  FUN_004082d0(wportal_cloud_server_update_mutex,0xffffffff);
  puVar15 = &cloud_server_ip;
  for (iVar2 = 0; iVar2 < cloud_server_num; iVar2 = iVar2 + 1) {
    local_74c = 0;
    local_748 = 0;
    local_744 = 0;
    local_740 = 0;
    local_73c = 0;
    FUN_0051a7a8(puVar15,&local_74c);
    memset(local_71c,0,0x144);
    local_684 = 1;
    local_680 = g_default_cloud_free_id_begin + iVar2;
    local_664 = local_748;
    local_660 = 0xffffffff;
    local_64c = 6;
    local_770 = (void *)0x6;
    local_76c = 2;
    local_774 = local_71c;
    _wportal_update_free_strategy_cb(uVar18,&local_774);
    puVar15 = puVar15 + 0x28;
  }
  __s_00 = (undefined4 *)0x0;
  FUN_00407f30(wportal_cloud_server_update_mutex);
  wportal_db_https_enable_get(local_778);
  wportal_update_https_enable_to_ap(uVar18,local_778[0],0);
  uac_wserv_ssid_portal_switch_to_ap(uVar18);
LAB_0041dd44:
  while (iVar2 = FUN_004081b0(local_738 + 1), iVar2 != 0) {
    FUN_00408500(iVar2);
    FUN_00407df0(iVar2);
  }
  while (iVar2 = FUN_004081b0(local_738 + 4), iVar2 != 0) {
    FUN_00408500(iVar2);
    FUN_00407df0(iVar2 + -4);
  }
  if (__s_00 == (undefined4 *)0x0) {
    return 0;
  }
  FUN_00407df0(__s_00);
  return 0;
}

