// func _ac_cmcc_pkt_auth_manage @ 004361c8 size=9580

int _ac_cmcc_pkt_auth_manage(void *param_1,int param_2,void *param_3,void *param_4)

{
  uint uVar1;
  int iVar2;
  char cVar4;
  void *pvVar3;
  byte bVar5;
  undefined2 uVar6;
  char *__format;
  char *pcVar7;
  int iVar8;
  byte *pbVar9;
  undefined4 uVar10;
  char *pcVar11;
  int iVar12;
  char *pcVar13;
  int iVar14;
  undefined8 uVar15;
  int local_1134;
  uint local_1130;
  undefined2 local_112c;
  undefined4 local_1128;
  undefined4 local_1124;
  undefined4 local_1120;
  undefined4 local_111c;
  undefined2 local_1118;
  undefined4 local_1114;
  undefined4 local_1110;
  undefined4 local_110c;
  undefined4 local_1108;
  undefined4 local_1104;
  undefined4 local_1100;
  undefined4 local_10fc;
  undefined4 local_10f8;
  undefined4 local_10f4;
  undefined4 local_10f0;
  undefined4 local_10ec;
  undefined4 local_10e8;
  undefined4 local_10e4;
  undefined4 local_10e0;
  undefined4 local_10dc;
  undefined4 local_10d8;
  undefined4 local_10d4;
  undefined4 local_10d0;
  undefined4 local_10cc;
  undefined4 local_10c8;
  byte local_10c4 [19];
  undefined1 local_10b1;
  undefined4 local_10a4 [8];
  int local_1084 [8];
  char acStack_1064 [32];
  char *local_1044 [8];
  undefined1 auStack_1024 [40];
  undefined1 auStack_ffc [38];
  byte abStack_fd6 [104];
  char acStack_f6e [106];
  undefined1 auStack_f04 [32];
  uint local_ee4;
  undefined1 local_ee0;
  undefined1 local_edf;
  ushort local_ed6;
  uint local_e9c;
  undefined2 local_e98;
  undefined1 auStack_e84 [352];
  int local_d24;
  undefined1 auStack_d18 [308];
  int local_be4 [11];
  int local_bb8;
  undefined1 auStack_bac [352];
  int local_a4c;
  undefined1 auStack_a40 [308];
  int local_90c [11];
  int local_8e0;
  undefined1 auStack_8d4 [308];
  char acStack_7a0 [56];
  undefined1 auStack_768 [12];
  byte local_75c;
  byte local_75b;
  byte local_75a;
  byte local_759;
  byte local_758;
  byte local_757;
  char *local_754;
  undefined1 auStack_5e8 [72];
  byte local_5a0;
  byte local_59f;
  byte local_59e;
  byte local_59d;
  byte local_59c;
  byte local_59b;
  undefined4 local_37c;
  undefined4 local_378;
  undefined4 local_374;
  undefined4 local_370;
  undefined4 local_36c;
  undefined1 auStack_310 [72];
  byte local_2c8;
  byte local_2c7;
  byte local_2c6;
  byte local_2c5;
  byte local_2c4;
  byte local_2c3;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  int local_38;
  int local_34;
  uint local_30;
  
  pbVar9 = (byte *)((int)param_1 + 0x10);
  param_2 = param_2 + -0x10;
  memset(local_1044,0,0x20);
  memset(acStack_f6e + 2,0,0x65);
  memset(abStack_fd6 + 2,0,0x65);
  local_1130 = 0;
  local_112c = 0;
  memset(auStack_ffc,0,0x28);
  local_30 = (uint)*(byte *)((int)param_1 + 0xf);
  memset(param_4,0,0x640);
  memcpy(param_4,param_1,0x10);
  if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d Get attribute: %d\n\n","_ac_cmcc_pkt_auth_manage",0x51b,local_30);
  }
  iVar8 = 0;
  local_34 = 0;
  iVar14 = 0;
  local_38 = 0;
  iVar12 = 0;
  for (; (iVar12 < (int)local_30 && (0 < param_2)); param_2 = param_2 - (uint)pbVar9[1]) {
    if (wportal_debug_switch == 0) {
      bVar5 = *pbVar9;
    }
    else {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        bVar5 = *pbVar9;
      }
      else {
        printf("[WPORTAL_DBG]%s()/%d Get attr type: %x, len: %d\n\n","_ac_cmcc_pkt_auth_manage",
               0x51e,(uint)*pbVar9,(uint)pbVar9[1]);
        bVar5 = *pbVar9;
      }
    }
    if (bVar5 == 1) {
      if ((pbVar9[1] - 2 & 0xff) < 0x65) {
        strncpy(acStack_f6e + 2,(char *)(pbVar9 + 2),pbVar9[1] - 2);
        local_38 = 1;
        acStack_f6e[pbVar9[1]] = '\0';
        if (wportal_debug_switch == 0) {
          bVar5 = *pbVar9;
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            bVar5 = *pbVar9;
          }
          else {
            printf("[WPORTAL_DBG]%s()/%d Get username: %s\n","_ac_cmcc_pkt_auth_manage",0x527,
                   acStack_f6e + 2);
            bVar5 = *pbVar9;
          }
        }
      }
      else {
        bVar5 = *pbVar9;
      }
    }
    else {
      bVar5 = *pbVar9;
    }
    if (bVar5 == 2) {
      if ((pbVar9[1] - 2 & 0xff) < 0x65) {
        iVar14 = 1;
        strncpy((char *)(abStack_fd6 + 2),(char *)(pbVar9 + 2),pbVar9[1] - 2);
        abStack_fd6[pbVar9[1]] = 0;
        if (wportal_debug_switch == 0) {
          bVar5 = *pbVar9;
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            bVar5 = *pbVar9;
          }
          else {
            printf("[WPORTAL_DBG]%s()/%d Get password: %s\n","_ac_cmcc_pkt_auth_manage",0x533,
                   abStack_fd6 + 2);
            bVar5 = *pbVar9;
          }
        }
      }
      else {
        bVar5 = *pbVar9;
      }
    }
    else {
      bVar5 = *pbVar9;
    }
    if ((bVar5 == 4) && (pbVar9[1] == 0x12)) {
      memcpy(abStack_fd6 + 2,pbVar9 + 2,0x10);
      local_34 = 1;
    }
    if (cmcc_test_mode == 0) {
      if (*pbVar9 == 0x55) {
        if (pbVar9[1] == 0xe) {
          local_1128 = 0;
          local_1124 = 0;
          local_1120 = 0;
          local_111c = 0;
          iVar8 = 1;
          local_1118 = 0;
          strncpy((char *)&local_1128,(char *)(pbVar9 + 2),0xc);
          FUN_004360d4(&local_1130,&local_1128);
          uVar1 = (uint)pbVar9[1];
        }
        else {
          uVar1 = (uint)pbVar9[1];
        }
      }
      else {
        uVar1 = (uint)pbVar9[1];
      }
    }
    else if (*pbVar9 == 0x55) {
      if (pbVar9[1] == 8) {
        iVar8 = 1;
        memcpy(&local_1130,pbVar9 + 2,6);
        uVar1 = (uint)pbVar9[1];
      }
      else {
        uVar1 = (uint)pbVar9[1];
      }
    }
    else {
      uVar1 = (uint)pbVar9[1];
    }
    iVar12 = iVar12 + 1;
    pbVar9 = pbVar9 + uVar1;
  }
  iVar12 = wportal_get_mode();
  if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d mode is %d WPORTAL_AUTH_MODE_INTERFACE is %d getMac is %d\n",
           "_ac_cmcc_pkt_auth_manage",0x562,iVar12,2,iVar8);
  }
  if (iVar8 == 0) {
    local_10d8 = 0;
    local_10d0 = 0;
    local_10cc = 0;
    local_10c8 = 0;
    memset(auStack_f04,0,0x80);
    local_10d4 = *(undefined4 *)((int)param_1 + 8);
    local_10d8 = CONCAT13(1,local_10d8._1_3_);
    iVar2 = wsta_db_get_entry_by_ip(local_10d8,local_10d4,0,0,0,auStack_f04);
    if (iVar2 == 0) {
      iVar8 = 1;
      local_1130 = local_e9c;
      local_112c = local_e98;
LAB_004367a0:
      memset(auStack_ffc,0,0x28);
      FUN_00408190(local_10d8,local_10d4,local_10d0,local_10cc,local_10c8,auStack_ffc,0x28,"0.0.0.0"
                  );
      goto LAB_00436618;
    }
    if ((iVar12 == 2) || (iVar12 == 3)) goto LAB_004367a0;
    if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d Get wstation error for ip %08x\n","_ac_cmcc_pkt_auth_manage",
             0x56e,*(undefined4 *)((int)param_1 + 8));
    }
  }
  else {
    uVar10 = *(undefined4 *)((int)param_1 + 8);
    local_10e4 = 0;
    local_10e0 = 0;
    local_10dc = 0;
    local_10ec = 0x1000000;
    local_10e8 = uVar10;
    memset(auStack_ffc,0,0x28);
    FUN_00408190(local_10ec,uVar10,0,0,0,auStack_ffc,0x28,"0.0.0.0");
    if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d ip_string: %s\n","_ac_cmcc_pkt_auth_manage",0x582,auStack_ffc);
    }
LAB_00436618:
    if (local_38 != 0) {
      if ((iVar14 != 0) && (local_34 == iVar14)) {
        if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(param_4), iVar8 != 0)) {
          pcVar13 = 
          "[WPORTAL_DBG]%s()/%d Contain password and chappassword attribute at the same time\n";
          pcVar11 = "_ac_cmcc_pkt_auth_manage";
          uVar10 = 0x58d;
          goto LAB_00436b08;
        }
        goto LAB_004368b8;
      }
      if (((iVar8 == 1) && (wportal_debug_switch != 0)) &&
         (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[WPORTAL_DBG]%s()/%d Get auth packet username: %s, mac: %02x:%02x:%02x:%02x:%02x:%02x\n"
               ,"_ac_cmcc_pkt_auth_manage",0x594,acStack_f6e + 2,local_1130 >> 0x18,
               local_1130 >> 0x10 & 0xff,local_1130 >> 8 & 0xff,local_1130 & 0xff,
               (uint)local_112c._0_1_,(uint)(byte)local_112c);
      }
      pcVar13 = (char *)0xfff;
      memset(auStack_f04,0,0x80);
      if (cmcc_test_mode == 0) {
        if ((iVar8 == 1) && (iVar12 != 2)) {
          iVar2 = wsta_db_get_entry_by_mac(&local_1130,auStack_f04);
          if (iVar2 == 0) {
            pcVar13 = (char *)(uint)local_ed6;
            if (pcVar13 != (char *)0x0) goto LAB_004366bc;
          }
          else {
            if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[WPORTAL_DBG]%s()/%d Get wstation error\n","_ac_cmcc_pkt_auth_manage",0x5a0);
            }
            if (iVar12 != 3) goto LAB_004368b8;
          }
        }
        pcVar13 = (char *)0xfff;
      }
LAB_004366bc:
      if ((wportal_debug_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
        if (iVar12 != 0) goto LAB_004366d0;
LAB_00436890:
        memset(auStack_f04,0,0x80);
        iVar2 = wsta_db_get_entry_by_mac(&local_1130,auStack_f04);
        if (iVar2 == 0) {
          pcVar11 = (char *)uac_wservice_get_wserv_id(local_ee4,local_ee0,local_edf);
          if (pcVar11 == (char *)0xffffffff) {
            if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(param_4), iVar8 != 0)) {
              pcVar13 = "[WPORTAL_DBG]%s()/%d Get wserv_id fail\n\n";
              pcVar11 = "_ac_cmcc_pkt_auth_manage";
              uVar10 = 0x5cb;
              goto LAB_00436b08;
            }
          }
          else {
            if (wportal_debug_switch != 0) {
              iVar2 = is_target_debug_ap();
              if (iVar2 != 0) {
                uVar10 = 0x5cf;
                pcVar7 = pcVar11;
LAB_00436e54:
                __format = "[WPORTAL_DBG]%s()/%d wserv id: %d\n";
                pcVar11 = pcVar7;
LAB_00436e58:
                printf(__format,"_ac_cmcc_pkt_auth_manage",uVar10,pcVar7);
              }
              goto LAB_004366e8;
            }
LAB_00436704:
            memset(auStack_768,0,0x180);
            if (iVar8 == 1) {
              iVar8 = wportal_db_aut_get(&local_1130,auStack_768);
              if ((iVar8 == 0) &&
                 (((iVar8 = wportal_get_mode(), iVar8 == 1 && (pcVar13 == local_754)) ||
                  ((iVar8 = wportal_get_mode(), iVar8 == 0 && (pcVar11 == local_754)))))) {
LAB_0043673c:
                _ac_cmcc_send_pkt(param_4,param_3,4,2);
                return 0;
              }
            }
            else {
              iVar8 = wportal_db_aut_get_by_ip(auStack_ffc,auStack_768);
              if (iVar8 == 0) {
                if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
                  printf("[WPORTAL_DBG]%s()/%d already Exit ip_string : %s mac: %02x:%02x:%02x:%02x:%02x:%02x\n"
                         ,"_ac_cmcc_pkt_auth_manage",0x62d,auStack_ffc,(uint)local_75c,
                         (uint)local_75b,(uint)local_75a,(uint)local_759,(uint)local_758,
                         (uint)local_757);
                }
                goto LAB_0043673c;
              }
            }
            if ((iVar12 == 1) || (pcVar13 = pcVar11, iVar12 == 0)) {
              local_1044[0] = pcVar13;
              cVar4 = *(char *)((int)param_1 + 2);
            }
            else {
              pcVar13 = local_1044[0];
              if ((iVar12 == 2) || (pcVar13 = pcVar11, iVar12 == 3)) {
                local_1044[0] = pcVar13;
                strncpy((char *)local_1044,acStack_1064,0x20);
                cVar4 = *(char *)((int)param_1 + 2);
              }
              else {
                cVar4 = *(char *)((int)param_1 + 2);
              }
            }
            if (cVar4 == '\0') {
              if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
                printf("[WPORTAL_DBG]%s()/%d Get cmcc chap pkt %d\n","_ac_cmcc_pkt_auth_manage",
                       0x654,0);
              }
              if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
                printf("[WPORTAL_DBG]%s()/%d CMCC_PKT_CHAP_PAP(send_header) is %d\n",
                       "_ac_cmcc_pkt_auth_manage",0x655,(uint)*(byte *)((int)param_4 + 2));
              }
              if (local_34 == 0) {
                if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(param_4), iVar8 != 0)
                   ) {
                  pcVar13 = "[WPORTAL_DBG]%s()/%d CHAP auth not including chap password\n";
                  pcVar11 = "_ac_cmcc_pkt_auth_manage";
                  uVar10 = 0x658;
                  goto LAB_00436b08;
                }
              }
              else {
                memcpy(local_10a4,local_1044,0x20);
                local_1128 = 0;
                local_1124 = 0;
                local_1120 = 0;
                local_111c = 0;
                local_1118 = 0;
                memset(auStack_1024,0,0x28);
                local_1134 = 0;
                local_1114 = 0;
                local_1110 = 0;
                local_110c = 0;
                local_1108 = 0;
                local_1104 = 0;
                iVar8 = wportal_get_mode();
                if (iVar8 == 1) {
                  memset(auStack_d18,0,0x16c);
                  iVar8 = wportal_db_rdt_get_by_vlan(local_10a4[0],auStack_d18);
                  if ((iVar8 != 0) || (local_be4[0] == 0)) {
                    if ((wportal_debug_switch != 0) &&
                       (iVar8 = is_target_debug_ap(param_4), iVar8 != 0)) {
                      pcVar13 = "[WPORTAL_DBG]%s()/%d Get rdt entry error or rdt not enable\n";
                      pcVar11 = "_ac_cmcc_auth_chap";
                      uVar10 = 0x37b;
                      goto LAB_00436b08;
                    }
                    goto LAB_004368b8;
                  }
                }
                else {
                  iVar8 = wportal_get_mode();
                  if (iVar8 == 0) {
                    memset(auStack_e84,0,0x16c);
                    iVar8 = wportal_db_ssid_rdt_get(local_10a4[0],auStack_e84);
                    if (iVar8 != 0) {
                      if ((wportal_debug_switch != 0) &&
                         (iVar8 = is_target_debug_ap(param_4), iVar8 != 0)) {
                        pcVar13 = "[WPORTAL_DBG]%s()/%d Get rdt entry error or rdt is not enable\n";
                        pcVar11 = "_ac_cmcc_auth_chap";
                        uVar10 = 0x385;
                        goto LAB_00436b08;
                      }
                      goto LAB_004368b8;
                    }
                  }
                  else {
                    iVar8 = wportal_get_mode();
                    if (iVar8 == 2) {
                      memset(auStack_d18,0,0x16c);
                      iVar8 = wportal_db_iface_rdt_get(local_10a4,auStack_d18);
                      if (iVar8 != 0) {
                        if ((wportal_debug_switch != 0) &&
                           (iVar8 = is_target_debug_ap(param_4), iVar8 != 0)) {
                          pcVar13 = 
                          "[WPORTAL_DBG]%s()/%d Get rdt entry error or iface is not enable\n";
                          pcVar11 = "_ac_cmcc_auth_chap";
                          uVar10 = 0x38f;
                          goto LAB_00436b08;
                        }
                        goto LAB_004368b8;
                      }
                    }
                  }
                }
                memset(auStack_5e8,0,0x2d8);
                apmngr_db_entry_get_by_id(local_ee4 & 0xffff,auStack_5e8);
                memset(local_10c4,0,0x20);
                if (wportal_debug_switch == 0) {
                  uVar6 = *(undefined2 *)((int)param_4 + 4);
                }
                else {
                  iVar8 = is_target_debug_ap();
                  if (iVar8 == 0) {
                    uVar6 = *(undefined2 *)((int)param_4 + 4);
                  }
                  else {
                    printf("[WPORTAL_DBG]%s()/%d Get serial no: %d\n\n","_ac_cmcc_auth_chap",0x39a,
                           (uint)*(ushort *)((int)param_4 + 4));
                    uVar6 = *(undefined2 *)((int)param_4 + 4);
                  }
                }
                iVar8 = wportal_db_cmcc_get_serialno(uVar6,local_10c4);
                if (iVar8 == 0) {
                  iVar8 = json_object_new_object();
                  local_1128 = 0;
                  local_1124 = 0;
                  local_1120 = 0;
                  local_111c = 0;
                  local_1118 = 0;
                  snprintf((char *)&local_1128,0x12,"%02x-%02x-%02x-%02x-%02x-%02x",
                           local_1130 >> 0x18,local_1130 >> 0x10 & 0xff,local_1130 >> 8 & 0xff,
                           local_1130 & 0xff,(uint)local_112c._0_1_,(uint)(byte)local_112c);
                  uVar10 = json_object_new_string(&local_1128);
                  json_object_object_add(iVar8,"mac",uVar10);
                  local_1110 = *(undefined4 *)((int)param_4 + 8);
                  local_1114 = CONCAT13(1,local_1114._1_3_);
                  FUN_00408190(local_1114,local_1110,local_110c,local_1108,local_1104,auStack_1024,
                               0x28,"0.0.0.0");
                  uVar10 = json_object_new_string(auStack_1024);
                  json_object_object_add(iVar8,&DAT_00677c24,uVar10);
                  pcVar13 = acStack_f6e + 2;
                  if (acStack_f6e[2] == '\0') {
                    pcVar13 = "***";
                  }
                  uVar10 = json_object_new_string(pcVar13);
                  json_object_object_add(iVar8,"username",uVar10);
                  uVar10 = json_object_new_int();
                  json_object_object_add(iVar8,"chapPassword1",uVar10);
                  uVar10 = json_object_new_int();
                  json_object_object_add(iVar8,"chapPassword2",uVar10);
                  uVar10 = json_object_new_int();
                  json_object_object_add(iVar8,"chapPassword3",uVar10);
                  uVar10 = json_object_new_int();
                  json_object_object_add(iVar8,"chapPassword4",uVar10);
                  iVar12 = wportal_get_mode();
                  if (iVar12 == 1) {
                    uVar10 = json_object_new_int(local_10a4[0]);
                    json_object_object_add(iVar8,"vlan_id",uVar10);
                    iVar12 = local_bb8;
                  }
                  else {
                    iVar12 = wportal_get_mode();
                    if (iVar12 == 0) {
                      uVar10 = json_object_new_int(local_10a4[0]);
                      json_object_object_add(iVar8,"serv_id",uVar10);
                      iVar12 = local_d24;
                    }
                    else {
                      iVar14 = wportal_get_mode();
                      iVar12 = 0;
                      if (((iVar14 == 2) && (iVar12 = local_bb8, wportal_debug_switch != 0)) &&
                         (iVar14 = is_target_debug_ap(), iVar14 != 0)) {
                        printf("[WPORTAL_DBG]%s()/%d auth_server_type: %d\n","_ac_cmcc_auth_chap",
                               0x3d5,local_bb8);
                      }
                    }
                  }
                  uVar10 = json_object_new_int();
                  json_object_object_add(iVar8,"challenge1",uVar10);
                  uVar10 = json_object_new_int();
                  json_object_object_add(iVar8,"challenge2",uVar10);
                  uVar10 = json_object_new_int();
                  json_object_object_add(iVar8,"challenge3",uVar10);
                  uVar10 = json_object_new_int();
                  json_object_object_add(iVar8,"challenge4",uVar10);
                  if (wportal_debug_switch != 0) {
                    iVar14 = 0;
                    printf("Chap challenge:");
                    pbVar9 = local_10c4;
                    do {
                      iVar14 = iVar14 + 1;
                      printf("%x ",(uint)*pbVar9);
                      pbVar9 = local_10c4 + iVar14;
                    } while (iVar14 != 0x10);
                    putchar(10);
                  }
                  uVar10 = json_object_new_int(0);
                  json_object_object_add(iVar8,"cmcc_auth_type",uVar10);
                  uVar10 = json_object_new_int(local_10b1);
                  json_object_object_add(iVar8,"chapid",uVar10);
                  snprintf((char *)&local_1128,0x12,"%02x-%02x-%02x-%02x-%02x-%02x",(uint)local_5a0,
                           (uint)local_59f,(uint)local_59e,(uint)local_59d,(uint)local_59c,
                           (uint)local_59b);
                  uVar10 = json_object_new_string(&local_1128);
                  json_object_object_add(iVar8,"apMac",uVar10);
                  FUN_00408190(local_37c,local_378,local_374,local_370,local_36c,auStack_1024,0x28,
                               "0.0.0.0");
                  uVar10 = json_object_new_string(auStack_1024);
                  json_object_object_add(iVar8,&DAT_00679a24,uVar10);
                  if (wportal_debug_switch == 0) {
                    cVar4 = *(char *)((int)param_3 + 3);
                  }
                  else {
                    iVar14 = is_target_debug_ap();
                    if (iVar14 == 0) {
                      cVar4 = *(char *)((int)param_3 + 3);
                    }
                    else {
                      printf("[WPORTAL_DBG]%s()/%d Auth apmac: %s, apip: %s\n\n",
                             "_ac_cmcc_auth_chap",0x3fd,&local_1128,auStack_1024);
                      cVar4 = *(char *)((int)param_3 + 3);
                    }
                  }
                  local_1114 = CONCAT13(cVar4,local_1114._1_3_);
                  if (cVar4 == '\x01') {
                    local_1110 = *(undefined4 *)((int)param_3 + 8);
                  }
                  else {
                    memcpy(&local_1110,(void *)((int)param_3 + 0xc),0x10);
                  }
                  FUN_00408190(local_1114,local_1110,local_110c,local_1108,local_1104,auStack_1024,
                               0x28,"0.0.0.0");
                  if ((wportal_debug_switch != 0) && (iVar14 = is_target_debug_ap(), iVar14 != 0)) {
                    printf("[WPORTAL_DBG]%s()/%d Get CMCC server address: %s\n","_ac_cmcc_auth_chap"
                           ,0x409,auStack_1024);
                  }
                  uVar10 = json_object_new_string(auStack_1024);
                  json_object_object_add(iVar8,"cmccServerIp",uVar10);
                  uVar10 = json_object_new_int(*(undefined2 *)((int)param_4 + 4));
                  json_object_object_add(iVar8,"serialNo",uVar10);
                  if (iVar12 == 0) {
                    if ((wportal_debug_switch != 0) && (iVar12 = is_target_debug_ap(), iVar12 != 0))
                    {
                      printf("[WPORTAL_DBG]%s()/%d Chap local auth\n","_ac_cmcc_auth_chap",0x410);
                    }
                    uVar10 = json_object_new_int(7);
                    json_object_object_add(iVar8,"type",uVar10);
                    iVar12 = wportal_send_to_nginx_for_return(iVar8,&local_1134,0);
                    if (iVar12 == 0) {
                      iVar12 = json_object_object_get(local_1134,&DAT_00676a24);
                      if (iVar12 == 0) {
LAB_00438678:
                        iVar12 = -1;
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_ac_cmcc_auth_chap",0x417);
                        }
                      }
                      else {
                        iVar14 = json_object_get_type(iVar12);
                        if (iVar14 == 3) {
                          iVar12 = json_object_get_int(iVar12);
                        }
                        else {
                          iVar14 = json_object_get_type();
                          if (iVar14 != 2) goto LAB_00438678;
                          uVar15 = json_object_get_double(iVar12);
                          iVar12 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                        }
                      }
                      if ((wportal_debug_switch != 0) &&
                         (iVar14 = is_target_debug_ap(), iVar14 != 0)) {
                        printf("[WPORTAL_DBG]%s()/%d Auth result: %d chap/pap is %d\n\n",
                               "_ac_cmcc_auth_chap",0x419,iVar12,(uint)*(byte *)((int)param_4 + 2));
                      }
                      uVar10 = 0;
                      if (iVar12 == 9) goto LAB_00438374;
                    }
                    else if ((wportal_debug_switch != 0) &&
                            (iVar12 = is_target_debug_ap(), iVar12 != 0)) {
                      printf("[WPORTAL_DBG]%s()/%d Get nginx result error\n","_ac_cmcc_auth_chap",
                             0x427);
                    }
                    iVar12 = -1;
                    _ac_cmcc_send_pkt(param_4,param_3,4,4);
                  }
                  else {
                    pvVar3 = (void *)FUN_00408450(0x34,0x42f);
                    if (pvVar3 != (void *)0x0) {
                      memcpy((void *)((int)pvVar3 + 0x28),&local_1130,6);
                      *(undefined2 *)((int)pvVar3 + 0x24) = *(undefined2 *)((int)param_4 + 6);
                      uVar6 = *(undefined2 *)((int)param_4 + 4);
                      *(undefined1 *)((int)pvVar3 + 0x2e) = 0;
                      *(undefined2 *)((int)pvVar3 + 0x26) = uVar6;
                      *(undefined4 *)((int)pvVar3 + 0x20) = *(undefined4 *)((int)param_4 + 8);
                      memcpy(pvVar3,param_3,0x20);
                      iVar12 = wportal_db_cmcc_add_wq(pvVar3);
                      if (iVar12 != 0) {
                        if ((wportal_debug_switch != 0) &&
                           (iVar14 = is_target_debug_ap(), iVar14 != 0)) {
                          printf("[WPORTAL_DBG]%s()/%d Add wq error\n","_ac_cmcc_auth_chap",0x43c);
                        }
                        FUN_00407df0(pvVar3);
                        goto LAB_00437d70;
                      }
                      iVar12 = wportal_get_mode();
                      if (iVar12 == 2) {
                        uVar10 = json_object_new_string(local_be4);
                        json_object_object_add(iVar8,"interface",uVar10);
                      }
                      uVar10 = json_object_new_int(8);
                      json_object_object_add(iVar8,"type",uVar10);
                      iVar12 = wportal_send_to_nginx_for_return(iVar8,&local_1134,0);
                      if (iVar12 == 0) {
                        iVar12 = json_object_object_get(local_1134,&DAT_00676a24);
                        if (iVar12 == 0) {
LAB_004383f8:
                          iVar14 = -1;
                          if (jcs_err_switch != 0) {
                            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                   ,"_ac_cmcc_auth_chap",0x452);
                          }
                        }
                        else {
                          iVar14 = json_object_get_type(iVar12);
                          if (iVar14 == 3) {
                            iVar14 = json_object_get_int(iVar12);
                          }
                          else {
                            iVar14 = json_object_get_type();
                            if (iVar14 != 2) goto LAB_004383f8;
                            uVar15 = json_object_get_double(iVar12);
                            iVar14 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                          }
                        }
                        if ((wportal_debug_switch != 0) &&
                           (iVar12 = is_target_debug_ap(), iVar12 != 0)) {
                          printf("[WPORTAL_DBG]%s()/%d Auth result: %d\n\n","_ac_cmcc_auth_chap",
                                 0x454,iVar14);
                        }
                        iVar12 = 0;
                        if (iVar14 == 1) goto LAB_00437d70;
                        if ((wportal_debug_switch != 0) &&
                           (iVar12 = is_target_debug_ap(), iVar12 != 0)) {
                          pcVar13 = "[WPORTAL_DBG]%s()/%d Get nginx result no authing error\n";
                          uVar10 = 0x458;
                          goto LAB_004383a8;
                        }
                      }
                      else if ((wportal_debug_switch != 0) &&
                              (iVar12 = is_target_debug_ap(), iVar12 != 0)) {
                        pcVar13 = "[WPORTAL_DBG]%s()/%d Get nginx result error\n";
                        uVar10 = 0x460;
LAB_004383a8:
                        printf(pcVar13,"_ac_cmcc_auth_chap",uVar10);
                      }
                      _ac_cmcc_send_pkt(param_4,param_3,4,4);
                      iVar12 = -1;
                      wportal_db_cmcc_del_wq(&local_1130);
                      goto LAB_00437d70;
                    }
                    uVar10 = 4;
LAB_00438374:
                    iVar12 = 0;
                    _ac_cmcc_send_pkt(param_4,param_3,4,uVar10);
                  }
LAB_00437d70:
                  if (iVar8 != 0) {
                    json_object_put(iVar8);
                  }
                  if (local_1134 == 0) {
                    uVar6 = *(undefined2 *)((int)param_4 + 4);
                  }
                  else {
                    json_object_put();
                    local_1134 = 0;
                    uVar6 = *(undefined2 *)((int)param_4 + 4);
                  }
                  wportal_db_cmcc_del_serialno(uVar6);
                  return iVar12;
                }
                if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(param_4), iVar8 != 0)
                   ) {
                  pcVar13 = "[WPORTAL_DBG]%s()/%d Get serialno error\n";
                  pcVar11 = "_ac_cmcc_auth_chap";
                  uVar10 = 0x39e;
                  goto LAB_00436b08;
                }
              }
            }
            else {
              if (cVar4 != '\x01') {
                if (wportal_debug_switch == 0) {
                  return -1;
                }
                iVar8 = is_target_debug_ap();
                if (iVar8 == 0) {
                  return -1;
                }
                printf("[WPORTAL_DBG]%s()/%d Get cmcc pkt type error: %x\n",
                       "_ac_cmcc_pkt_auth_manage",0x661,(uint)*(byte *)((int)param_1 + 2));
                return -1;
              }
              uVar1 = local_ee4;
              if ((wportal_debug_switch != 0) &&
                 (iVar8 = is_target_debug_ap(), uVar1 = local_ee4, iVar8 != 0)) {
                printf("[WPORTAL_DBG]%s()/%d Get cmcc pap pkt\n","_ac_cmcc_pkt_auth_manage",0x648);
                uVar1 = local_ee4;
              }
              if (iVar14 != 0) {
                memcpy(local_1084,local_1044,0x20);
                local_1128 = 0;
                local_1124 = 0;
                local_1120 = 0;
                local_111c = 0;
                local_1118 = 0;
                memset(auStack_1024,0,0x28);
                local_1134 = 0;
                local_1100 = 0;
                local_10fc = 0;
                local_10f8 = 0;
                local_10f4 = 0;
                local_10f0 = 0;
                iVar8 = wportal_get_mode();
                if (iVar8 == 1) {
                  memset(auStack_a40,0,0x16c);
                  iVar8 = wportal_db_rdt_get_by_vlan(local_1084[0],auStack_a40);
                  if ((iVar8 != 0) || (local_90c[0] == 0)) {
                    if ((wportal_debug_switch != 0) &&
                       (iVar8 = is_target_debug_ap(param_4), iVar8 != 0)) {
                      pcVar13 = "[WPORTAL_DBG]%s()/%d Get rdt entry error or rdt is not enable\n";
                      pcVar11 = "_ac_cmcc_auth_pap";
                      uVar10 = 0x265;
                      goto LAB_00436b08;
                    }
                    goto LAB_004368b8;
                  }
                }
                else {
                  iVar8 = wportal_get_mode();
                  if (iVar8 == 0) {
                    memset(auStack_bac,0,0x16c);
                    iVar8 = wportal_db_ssid_rdt_get(local_1084[0],auStack_bac);
                    if (iVar8 != 0) {
                      if ((wportal_debug_switch != 0) &&
                         (iVar8 = is_target_debug_ap(param_4), iVar8 != 0)) {
                        pcVar13 = "[WPORTAL_DBG]%s()/%d Get rdt entry error or rdt is not enable\n";
                        pcVar11 = "_ac_cmcc_auth_pap";
                        uVar10 = 0x26f;
                        goto LAB_00436b08;
                      }
                      goto LAB_004368b8;
                    }
                  }
                  else {
                    iVar8 = wportal_get_mode();
                    if (iVar8 == 2) {
                      memset(auStack_a40,0,0x16c);
                      iVar8 = wportal_db_iface_rdt_get(local_1084,auStack_a40);
                      if (iVar8 != 0) {
                        if ((wportal_debug_switch != 0) &&
                           (iVar8 = is_target_debug_ap(param_4), iVar8 != 0)) {
                          pcVar13 = 
                          "[WPORTAL_DBG]%s()/%d Get rdt entry error or iface is not enable\n";
                          pcVar11 = "_ac_cmcc_auth_pap";
                          uVar10 = 0x279;
                          goto LAB_00436b08;
                        }
                        goto LAB_004368b8;
                      }
                    }
                    else {
                      iVar12 = wportal_get_mode();
                      iVar8 = local_1084[0];
                      if (iVar12 == 3) {
                        if (local_1084[0] == -1) {
                          memset(auStack_a40,0,0x16c);
                          iVar8 = wportal_db_iface_rdt_get(local_1084,auStack_a40);
                          if (iVar8 == 0) goto LAB_00437134;
                          if ((wportal_debug_switch != 0) &&
                             (iVar8 = is_target_debug_ap(param_4), iVar8 != 0)) {
                            pcVar13 = 
                            "[WPORTAL_DBG]%s()/%d Get rdt entry error or iface is not enable\n";
                            pcVar11 = "_ac_cmcc_auth_pap";
                            uVar10 = 0x28f;
                            goto LAB_00436b08;
                          }
                        }
                        else {
                          memset(auStack_bac,0,0x16c);
                          iVar8 = wportal_db_ssid_rdt_get(iVar8,auStack_bac);
                          if (iVar8 == 0) goto LAB_00437134;
                          if ((wportal_debug_switch != 0) &&
                             (iVar8 = is_target_debug_ap(param_4), iVar8 != 0)) {
                            pcVar13 = 
                            "[WPORTAL_DBG]%s()/%d Get rdt entry error or rdt is not enable\n";
                            pcVar11 = "_ac_cmcc_auth_pap";
                            uVar10 = 0x285;
                            goto LAB_00436b08;
                          }
                        }
                        goto LAB_004368b8;
                      }
                    }
                  }
                }
LAB_00437134:
                memset(auStack_310,0,0x2d8);
                iVar8 = apmngr_db_entry_get_by_id(uVar1 & 0xffff,auStack_310);
                iVar12 = json_object_new_object();
                local_1128 = 0;
                local_1124 = 0;
                local_1120 = 0;
                local_111c = 0;
                local_1118 = 0;
                snprintf((char *)&local_1128,0x12,"%02x-%02x-%02x-%02x-%02x-%02x",local_1130 >> 0x18
                         ,local_1130 >> 0x10 & 0xff,local_1130 >> 8 & 0xff,local_1130 & 0xff,
                         (uint)local_112c._0_1_,(uint)(byte)local_112c);
                uVar10 = json_object_new_string(&local_1128);
                json_object_object_add(iVar12,"mac",uVar10);
                local_10fc = *(undefined4 *)((int)param_4 + 8);
                local_1100 = CONCAT13(1,local_1100._1_3_);
                FUN_00408190(local_1100,local_10fc,local_10f8,local_10f4,local_10f0,auStack_1024,
                             0x28,"0.0.0.0");
                uVar10 = json_object_new_string(auStack_1024);
                json_object_object_add(iVar12,&DAT_00677c24,uVar10);
                uVar10 = json_object_new_int(1);
                json_object_object_add(iVar12,"cmcc_auth_type",uVar10);
                pcVar13 = acStack_f6e + 2;
                if (acStack_f6e[2] == '\0') {
                  pcVar13 = "***";
                }
                uVar10 = json_object_new_string(pcVar13);
                json_object_object_add(iVar12,"username",uVar10);
                uVar10 = json_object_new_string(abStack_fd6 + 2);
                json_object_object_add(iVar12,"password",uVar10);
                iVar14 = wportal_get_mode();
                if (iVar14 == 1) {
                  uVar10 = json_object_new_int(local_1084[0]);
                  json_object_object_add(iVar12,"vlan_id",uVar10);
                  local_a4c = local_8e0;
                  if ((wportal_debug_switch != 0) &&
                     (iVar14 = is_target_debug_ap(), local_a4c = local_8e0, iVar14 != 0)) {
                    printf("[WPORTAL_DBG]%s()/%d Auth mac: %s, vlan: %d, username: %s, password: %s\n"
                           ,"_ac_cmcc_auth_pap",0x2b7,&local_1128,local_1084[0],acStack_f6e + 2,
                           abStack_fd6 + 2);
                    local_a4c = local_8e0;
                  }
LAB_004372e0:
                  uVar1 = (uint)local_2c7;
                  iVar14 = local_a4c;
                }
                else {
                  iVar14 = wportal_get_mode();
                  if (iVar14 == 0) {
                    uVar10 = json_object_new_int(local_1084[0]);
                    json_object_object_add(iVar12,"serv_id",uVar10);
                    if ((wportal_debug_switch != 0) && (iVar14 = is_target_debug_ap(), iVar14 != 0))
                    {
                      printf("[WPORTAL_DBG]%s()/%d Auth mac: %s, wservid: %d, username: %s, password: %s\n"
                             ,"_ac_cmcc_auth_pap",0x2be,&local_1128,local_1084[0],acStack_f6e + 2,
                             abStack_fd6 + 2);
                    }
                    goto LAB_004372e0;
                  }
                  iVar14 = 0;
                  iVar2 = wportal_get_mode();
                  uVar1 = (uint)local_2c7;
                  if (iVar2 == 2) {
                    local_a4c = local_8e0;
                    if (wportal_debug_switch == 0) goto LAB_004372e0;
                    iVar2 = is_target_debug_ap();
                    iVar14 = local_8e0;
                    if (iVar2 == 0) {
                      uVar1 = (uint)local_2c7;
                    }
                    else {
                      printf("[WPORTAL_DBG]%s()/%d auth_server_type: %d\n","_ac_cmcc_auth_pap",0x2c5
                             ,local_8e0);
                      uVar1 = (uint)local_2c7;
                    }
                  }
                }
                snprintf((char *)&local_1128,0x12,"%02x-%02x-%02x-%02x-%02x-%02x",(uint)local_2c8,
                         uVar1,(uint)local_2c6,(uint)local_2c5,(uint)local_2c4,(uint)local_2c3);
                uVar10 = json_object_new_string(&local_1128);
                json_object_object_add(iVar12,"apMac",uVar10);
                FUN_00408190(local_a4,local_a0,local_9c,local_98,local_94,auStack_1024,0x28,
                             "0.0.0.0");
                uVar10 = json_object_new_string(auStack_1024);
                json_object_object_add(iVar12,&DAT_00679a24,uVar10);
                local_1100 = CONCAT13(*(char *)((int)param_3 + 3),local_1100._1_3_);
                if (*(char *)((int)param_3 + 3) == '\x01') {
                  local_10fc = *(undefined4 *)((int)param_3 + 8);
                }
                else {
                  memcpy(&local_10fc,(void *)((int)param_3 + 0xc),0x10);
                }
                FUN_00408190(local_1100,local_10fc,local_10f8,local_10f4,local_10f0,auStack_1024,
                             0x28,"0.0.0.0");
                if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[WPORTAL_DBG]%s()/%d Get CMCC server ip: %s\n\n","_ac_cmcc_auth_pap",0x2db
                         ,auStack_1024);
                }
                uVar10 = json_object_new_string(auStack_1024);
                json_object_object_add(iVar12,"cmccServerIp",uVar10);
                uVar10 = json_object_new_int(*(undefined2 *)((int)param_4 + 4));
                json_object_object_add(iVar12,"serialNo",uVar10);
                if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  printf("[WPORTAL_DBG]%s()/%d Auth apmac: %s, apip: %s\n\n","_ac_cmcc_auth_pap",
                         0x2e0,&local_1128,auStack_1024);
                }
                if (iVar14 == 0) {
                  if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
                    printf("[WPORTAL_DBG]%s()/%d Pap local auth\n","_ac_cmcc_auth_pap",0x2e4);
                  }
                  uVar10 = json_object_new_int(7);
                  json_object_object_add(iVar12,"type",uVar10);
                  iVar8 = wportal_send_to_nginx_for_return(iVar12,&local_1134,0);
                  if (iVar8 == 0) {
                    iVar8 = json_object_object_get(local_1134,&DAT_00676a24);
                    if (iVar8 == 0) {
LAB_004380cc:
                      iVar8 = -1;
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                               ,"_ac_cmcc_auth_pap",0x2eb);
                      }
                    }
                    else {
                      iVar14 = json_object_get_type(iVar8);
                      if (iVar14 == 3) {
                        iVar8 = json_object_get_int(iVar8);
                      }
                      else {
                        iVar14 = json_object_get_type();
                        if (iVar14 != 2) goto LAB_004380cc;
                        uVar15 = json_object_get_double(iVar8);
                        iVar8 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                      }
                    }
                    if ((wportal_debug_switch != 0) && (iVar14 = is_target_debug_ap(), iVar14 != 0))
                    {
                      printf("[WPORTAL_DBG]%s()/%d Auth result: %d\n\n","_ac_cmcc_auth_pap",0x2ed,
                             iVar8);
                    }
                    uVar10 = 0;
                    if (iVar8 == 9) {
                      iVar8 = 0;
                      goto LAB_00437f1c;
                    }
                  }
                  else if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)
                          ) {
                    printf("[WPORTAL_DBG]%s()/%d Get nignx result error\n","_ac_cmcc_auth_pap",0x2fb
                          );
                  }
                  iVar8 = -1;
                  _ac_cmcc_send_pkt(param_4,param_3,4,4);
                }
                else {
                  if ((wportal_debug_switch != 0) &&
                     (iVar14 = is_target_debug_ap(0x34), iVar14 != 0)) {
                    printf("[WPORTAL_DBG]%s()/%d Pap radius auth\n","_ac_cmcc_auth_pap",0x302);
                  }
                  pvVar3 = (void *)FUN_00408450(0x34,0x305);
                  if (pvVar3 != (void *)0x0) {
                    memcpy((void *)((int)pvVar3 + 0x28),&local_1130,6);
                    *(undefined2 *)((int)pvVar3 + 0x24) = *(undefined2 *)((int)param_4 + 6);
                    *(undefined2 *)((int)pvVar3 + 0x26) = *(undefined2 *)((int)param_4 + 4);
                    *(undefined1 *)((int)pvVar3 + 0x2e) = 1;
                    *(undefined4 *)((int)pvVar3 + 0x20) = *(undefined4 *)((int)param_4 + 8);
                    memcpy(pvVar3,param_3,0x20);
                    iVar8 = wportal_db_cmcc_add_wq(pvVar3);
                    if (iVar8 != 0) {
                      if ((wportal_debug_switch != 0) &&
                         (iVar14 = is_target_debug_ap(), iVar14 != 0)) {
                        printf("[WPORTAL_DBG]%s()/%d Add wq error\n","_ac_cmcc_auth_pap",0x312);
                      }
                      FUN_00407df0(pvVar3);
                      goto LAB_00437490;
                    }
                    iVar8 = wportal_get_mode();
                    if (iVar8 == 2) {
                      uVar10 = json_object_new_string(local_90c);
                      json_object_object_add(iVar12,"interface",uVar10);
                    }
                    uVar10 = json_object_new_int(8);
                    json_object_object_add(iVar12,"type",uVar10);
                    iVar8 = wportal_send_to_nginx_for_return(iVar12,&local_1134,0);
                    if (iVar8 == 0) {
                      iVar8 = json_object_object_get(local_1134,&DAT_00676a24);
                      if (iVar8 == 0) {
LAB_00438248:
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                 ,"_ac_cmcc_auth_pap",0x32a);
                        }
                      }
                      else {
                        iVar14 = json_object_get_type(iVar8);
                        if (iVar14 == 3) {
                          iVar8 = json_object_get_int(iVar8);
                        }
                        else {
                          iVar14 = json_object_get_type();
                          if (iVar14 != 2) goto LAB_00438248;
                          uVar15 = json_object_get_double(iVar8);
                          iVar8 = __fixdfsi((int)((ulonglong)uVar15 >> 0x20),(int)uVar15);
                        }
                        if (iVar8 == 1) {
                          iVar8 = 0;
                          goto LAB_00437490;
                        }
                      }
                      if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0))
                      {
                        pcVar13 = "[WPORTAL_DBG]%s()/%d Get nignx result not authing\n";
                        uVar10 = 0x32e;
                        goto LAB_004381f8;
                      }
                    }
                    else if ((wportal_debug_switch != 0) &&
                            (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
                      pcVar13 = "[WPORTAL_DBG]%s()/%d Get nignx result error\n";
                      uVar10 = 0x336;
LAB_004381f8:
                      printf(pcVar13,"_ac_cmcc_auth_pap",uVar10);
                    }
                    _ac_cmcc_send_pkt(param_4,param_3,4,4);
                    iVar8 = -1;
                    wportal_db_cmcc_del_wq(&local_1130);
                    goto LAB_00437490;
                  }
                  uVar10 = 4;
LAB_00437f1c:
                  _ac_cmcc_send_pkt(param_4,param_3,4,uVar10);
                }
LAB_00437490:
                if (iVar12 != 0) {
                  json_object_put(iVar12);
                }
                if (local_1134 == 0) {
                  return iVar8;
                }
                json_object_put();
                return iVar8;
              }
              if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(param_4), iVar8 != 0))
              {
                pcVar13 = "[WPORTAL_DBG]%s()/%d PAP auth not including password\n";
                pcVar11 = "_ac_cmcc_pkt_auth_manage";
                uVar10 = 0x64b;
                goto LAB_00436b08;
              }
            }
          }
        }
        else if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(param_4), iVar8 != 0)) {
          pcVar13 = "[WPORTAL_DBG]%s()/%d Get wstation error\n";
          pcVar11 = "_ac_cmcc_pkt_auth_manage";
          uVar10 = 0x5c4;
LAB_00436b08:
          printf(pcVar13,pcVar11,uVar10);
        }
      }
      else {
        printf("[WPORTAL_DBG]%s()/%d vlan: %d\n","_ac_cmcc_pkt_auth_manage",0x5bb,pcVar13);
        if (iVar12 == 0) goto LAB_00436890;
LAB_004366d0:
        if (iVar12 == 2) {
          memset(acStack_1064,0,0x20);
          if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(auStack_ffc), iVar2 != 0))
          {
            printf("[WPORTAL_DBG]%s()/%d interface : 0x%p\n","_ac_cmcc_pkt_auth_manage",0x5d5,
                   acStack_1064);
          }
          iVar2 = wportal_send_to_wifidog_for_cmcc(auStack_ffc,acStack_1064);
          if (iVar2 != 0) {
            if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(param_4), iVar8 != 0)) {
              pcVar13 = "[WPORTAL_DBG]%s()/%d Get interface error\n";
              pcVar11 = "_ac_cmcc_pkt_auth_manage";
              uVar10 = 0x5d8;
              goto LAB_00436b08;
            }
            goto LAB_004368b8;
          }
          pcVar11 = (char *)0xffffffff;
          if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[WPORTAL_DBG]%s()/%d interface : %s\n","_ac_cmcc_pkt_auth_manage",0x5dc,
                   acStack_1064);
            goto LAB_004366e8;
          }
LAB_004366e4:
          pcVar11 = (char *)0xffffffff;
LAB_004366e8:
          if (wportal_debug_switch != 0) {
            if ((iVar14 != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[WPORTAL_DBG]%s()/%d Password: %s\n","_ac_cmcc_pkt_auth_manage",0x608,
                     abStack_fd6 + 2);
            }
            if (local_34 != 0) {
              printf("Chap password:");
              local_38 = 0;
              do {
                printf("%x ",(uint)abStack_fd6[local_38 + 2]);
                local_38 = local_38 + 1;
              } while (local_38 != 0x10);
              putchar(10);
            }
          }
          goto LAB_00436704;
        }
        pcVar11 = (char *)0xffffffff;
        if (iVar12 != 3) goto LAB_004366e4;
        memset(auStack_f04,0,0x80);
        iVar2 = wsta_db_get_entry_by_mac(&local_1130,auStack_f04);
        if (iVar2 != 0) {
          memset(auStack_8d4,0,0x16c);
          iVar2 = wportal_db_iface_rdt_get_first_cmcc(auStack_8d4);
          if (iVar2 == 0) {
            strncpy(acStack_1064,acStack_7a0,0x20);
            if (wportal_debug_switch == 0) goto LAB_00436704;
            iVar2 = is_target_debug_ap();
            if (iVar2 == 0) goto LAB_004366e8;
            __format = "[WPORTAL_DBG]%s()/%d interface : %s\n";
            uVar10 = 0x600;
            pcVar7 = acStack_1064;
            goto LAB_00436e58;
          }
          if ((wportal_debug_switch == 0) || (iVar8 = is_target_debug_ap(param_4), iVar8 == 0))
          goto LAB_004368b8;
          pcVar13 = "[WPORTAL_DBG]%s()/%d get first iface db rdt failed\n";
          pcVar11 = "_ac_cmcc_pkt_auth_manage";
          uVar10 = 0x5fc;
          goto LAB_00436b08;
        }
        pcVar11 = (char *)uac_wservice_get_wserv_id(local_ee4,local_ee0,local_edf);
        if (pcVar11 != (char *)0xffffffff) {
          if (wportal_debug_switch == 0) goto LAB_00436704;
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) goto LAB_004366e8;
          uVar10 = 0x5ee;
          pcVar7 = pcVar11;
          goto LAB_00436e54;
        }
        if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(param_4), iVar8 != 0)) {
          pcVar13 = "[WPORTAL_DBG]%s()/%d Get wserv_id fail\n\n";
          pcVar11 = "_ac_cmcc_pkt_auth_manage";
          uVar10 = 0x5ea;
          goto LAB_00436b08;
        }
      }
LAB_004368b8:
      uVar10 = 4;
      goto LAB_00436634;
    }
    if ((wportal_debug_switch != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d Not included username or mac attribute\n",
             "_ac_cmcc_pkt_auth_manage",0x587);
    }
  }
  uVar10 = 1;
LAB_00436634:
  iVar8 = _ac_cmcc_send_pkt(param_4,param_3,4,uVar10);
  return iVar8;
}

