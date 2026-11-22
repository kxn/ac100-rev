// func cloud_mngt_bssid_handle @ 0049b814 size=2116

void cloud_mngt_bssid_handle(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  char acStack_960 [40];
  undefined1 auStack_938 [9];
  char local_92f;
  char local_90e;
  char local_90c;
  char acStack_8e4 [256];
  undefined1 auStack_7e4 [128];
  int local_764;
  char local_74c [212];
  undefined1 auStack_678 [10];
  ushort local_66e;
  int local_518;
  char local_510 [300];
  int local_3e4;
  undefined1 auStack_3e0 [216];
  undefined1 auStack_308 [16];
  undefined2 local_2f8;
  undefined4 local_2c8;
  byte local_2c0;
  byte local_2bf;
  byte local_2be;
  byte local_2bd;
  byte local_2bc;
  byte local_2bb;
  undefined1 auStack_2ba [375];
  undefined1 auStack_143 [83];
  undefined1 auStack_f0 [84];
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  int local_5c;
  int local_30;
  int local_2c;
  
  memset(auStack_308,0,0x2d8);
  memset(acStack_8e4,0,0x100);
  memset(auStack_7e4,0,0x168);
  memset(auStack_678,0,0x168);
  memset(auStack_938,0,0x54);
  memset(local_510,0,0x205);
  memset(acStack_960,0,0x28);
  if (param_1 != 0) {
    iVar1 = FUN_004081b0(param_1);
    iVar12 = 0;
    if (iVar1 != 0) {
      piVar8 = *(int **)(iVar1 + 0xc);
      do {
        if ((piVar8 != (int *)0x0) && (*piVar8 - 1U < 4)) {
          iVar2 = apmngr_db_entry_get_by_mac(piVar8 + 1,auStack_308);
          if ((iVar2 == 0) && (iVar2 = check_can_direct_report_by_ac(auStack_308,1), iVar2 == 0)) {
            iVar2 = json_object_new_object();
            if (iVar2 == 0) goto joined_r0x0049c048;
            local_30 = json_object_new_array();
            memset(acStack_8e4,0,0x100);
            snprintf(acStack_8e4,0x100,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_2c0,
                     (uint)local_2bf,(uint)local_2be,(uint)local_2bd,(uint)local_2bc,(uint)local_2bb
                    );
            uVar3 = json_object_new_string(acStack_8e4);
            json_object_object_add(iVar2,"deviceMac",uVar3);
            uVar3 = json_object_new_string(auStack_2ba);
            json_object_object_add(iVar2,"deviceName",uVar3);
            uVar3 = json_object_new_int(local_2f8);
            json_object_object_add(iVar2,&DAT_006983bc,uVar3);
            uVar3 = json_object_new_int64(0,local_2c8);
            json_object_object_add(iVar2,"deviceModelId",uVar3);
            FUN_00408190(local_9c,local_98,local_94,local_90,local_8c,acStack_960,0x28,"0.0.0.0");
            pcVar10 = "0.0.0.0";
            if (local_5c != 0) {
              pcVar10 = acStack_960;
            }
            uVar3 = json_object_new_string(pcVar10);
            json_object_object_add(iVar2,&DAT_00677c24,uVar3);
            iVar9 = 1;
            if (local_5c - 1U < 3) {
              iVar9 = (int)"cloud_mngt_apmngr_callback_wtp_join"[local_5c + 0x23];
            }
            uVar3 = json_object_new_int(iVar9);
            json_object_object_add(iVar2,"status",uVar3);
            apdb_get_ap_by_id(local_2c8,auStack_f0,auStack_7e4);
            uVar3 = json_object_new_string(site_id);
            json_object_object_add(iVar2,"projectId",uVar3);
            pcVar10 = local_74c;
            if (local_74c[0] == '\0') {
              if (local_764 == 1) {
                pcVar10 = "WIRELESSROUTER";
                goto LAB_0049be7c;
              }
              if (local_764 == 3) {
                pcVar10 = "SMBWIRELESSROUTER";
                goto LAB_0049be7c;
              }
            }
            else {
LAB_0049be7c:
              uVar3 = json_object_new_string(pcVar10);
              json_object_object_add(iVar2,"deviceType",uVar3);
            }
            uVar13 = 1;
            uVar3 = json_object_new_boolean(cloud_config_switch);
            json_object_object_add(iVar2,"syncConfig",uVar3);
            local_2c = apdb_radio_count_by_id(local_2c8,auStack_f0);
            iVar9 = rdmngr_profile_get_max_wlan_per_rd();
            local_518 = FUN_00408450(iVar9 << 8,0x7b2);
            while ((int)uVar13 <= local_2c) {
              uVar3 = rdmngr_db_generate_rd_id(local_2f8,uVar13);
              if ((local_518 == 0) ||
                 (iVar9 = rdmngr_db_rd_entry_get(uVar3,auStack_938), iVar9 != 0)) {
                uVar13 = uVar13 + 1;
              }
              else {
                iVar9 = stats_db_radio_get_total(local_2f8,uVar13 & 0xff,auStack_678,0);
                if (iVar9 == 0) {
                  if (cloud_mngt_bssid_test != 0) {
                    memset(acStack_8e4,0,0x100);
                    snprintf(acStack_8e4,0x100,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_2c0,
                             (uint)local_2bf,(uint)local_2be,(uint)local_2bd,(uint)local_2bc,
                             (uint)local_2bb);
                    printf("\ap_mac %s\r\n",acStack_8e4);
                    printf("\rd_index id: %u\r\n",uVar13);
                    cloud_mngt_stats_db_ssid_print(local_518);
                  }
                  iVar9 = 0;
                  uVar14 = 1;
                  while (uVar4 = rdmngr_profile_get_max_wlan_per_rd(), uVar14 <= uVar4) {
                    iVar11 = local_518 + iVar9;
                    if ((*(byte *)(iVar11 + 8) & 8) == 0) {
                      iVar5 = wserv_db_rd_get_wserv_id(uVar3,uVar14 & 0xff);
                      if ((iVar5 == -1) ||
                         (iVar5 = uac_wservice_get_entry_by_id(iVar5,local_510), iVar5 != 0))
                      goto LAB_0049bc6c;
                      uVar6 = json_object_new_object();
                      uVar7 = json_object_new_int(uVar13);
                      json_object_object_add(uVar6,"radioId",uVar7);
                      uVar7 = json_object_new_int(uVar3);
                      json_object_object_add(uVar6,"radioIndex",uVar7);
                      uVar7 = json_object_new_int(1);
                      json_object_object_add(uVar6,"vapType",uVar7);
                      if ((*(byte *)(iVar11 + 8) & 3) == 3) {
                        memset(acStack_8e4,0,0x100);
                        snprintf(acStack_8e4,0x100,"%02X-%02X-%02X-%02X-%02X-%02X",
                                 (uint)*(byte *)(iVar11 + 9),(uint)*(byte *)(iVar11 + 10),
                                 (uint)*(byte *)(iVar11 + 0xb),(uint)*(byte *)(iVar11 + 0xc),
                                 (uint)*(byte *)(iVar11 + 0xd),(uint)*(byte *)(iVar11 + 0xe));
                        pcVar10 = acStack_8e4;
                      }
                      else {
                        pcVar10 = "-1";
                      }
                      uVar7 = json_object_new_string(pcVar10);
                      json_object_object_add(uVar6,"bssid",uVar7);
                      uVar7 = json_object_new_string(auStack_3e0);
                      json_object_object_add(uVar6,"ssidName",uVar7);
                      if (local_3e4 - 1U < 2) {
                        pcVar10 = (&PTR_s_unknown_0069b874)[local_3e4];
                      }
                      else {
                        pcVar10 = "unknown";
                      }
                      uVar7 = json_object_new_string(pcVar10);
                      json_object_object_add(uVar6,"ssidCodeType",uVar7);
                      iVar11 = (int)local_90c;
                      if (iVar11 == 0) {
                        iVar11 = -0x50;
                      }
                      uVar7 = json_object_new_int(iVar11);
                      json_object_object_add(uVar6,"weakSigThresh",uVar7);
                      uVar7 = cloud_mngt_radio_type_get((int)local_92f);
                      uVar7 = json_object_new_string(uVar7);
                      json_object_object_add(uVar6,"mode",uVar7);
                      uVar4 = (uint)local_66e;
                      if (uVar4 != 2) {
                        if (uVar4 < 8) {
                          pcVar10 = (&PTR_DAT_0069b4b4)[uVar4];
                        }
                        else {
                          pcVar10 = "---";
                        }
                        uVar7 = json_object_new_string(pcVar10);
                        json_object_object_add(uVar6,&DAT_00698cb4,uVar7);
                      }
                      uVar7 = json_object_new_int((int)local_90e);
                      json_object_object_add(uVar6,&DAT_0069974c,uVar7);
                      pcVar10 = local_510;
                      if (local_510[0] == '\0') {
                        pcVar10 = "";
                      }
                      uVar14 = uVar14 + 1;
                      uVar7 = json_object_new_string(pcVar10);
                      json_object_object_add(uVar6,"ssidId",uVar7);
                      iVar9 = iVar9 + 0x100;
                      json_object_array_add(local_30,uVar6);
                    }
                    else {
LAB_0049bc6c:
                      uVar14 = uVar14 + 1;
                      iVar9 = iVar9 + 0x100;
                    }
                  }
                  uVar13 = uVar13 + 1;
                }
                else {
                  uVar13 = uVar13 + 1;
                }
              }
            }
            if (local_518 != 0) {
              FUN_00407df0();
            }
            if (local_30 != 0) {
              json_object_object_add(iVar2,"vapStats",local_30);
            }
            uVar3 = json_object_new_string(auStack_143);
            json_object_object_add(iVar2,"configId",uVar3);
            if ((iVar12 == 0) && (iVar12 = json_object_new_array(), iVar12 == 0)) goto LAB_0049b960;
            json_object_array_add(iVar12,iVar2);
          }
        }
        iVar1 = FUN_00408680(iVar1);
        if (iVar1 == 0) break;
        piVar8 = *(int **)(iVar1 + 0xc);
      } while( true );
    }
    if (iVar12 != 0) {
      iVar1 = json_object_new_object();
      cloud_mngt_update_devstatus_param_add(iVar1);
      json_object_object_add(iVar1,"subDevice",iVar12);
      iVar2 = cloud_mngt_obj_send_to_cloud(1,iVar1);
      iVar12 = iVar1;
      if ((iVar2 != 0) && (cloud_mngt_debug_switch != '\0')) {
        printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_obj_send_to_cloud failed\n",
               "cloud_mngt_bssid_info_changed_handle",0x757);
      }
joined_r0x0049c048:
      iVar2 = iVar12;
      if (iVar2 != 0) {
LAB_0049b960:
        json_object_put(iVar2);
      }
    }
  }
  return;
}

