// func _apmngr_db_status_get @ 0054b308 size=2488

undefined4 _apmngr_db_status_get(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int extraout_v1;
  char *pcVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined *puVar9;
  undefined4 uVar10;
  uint uVar11;
  uint *puVar12;
  undefined4 local_820;
  int local_81c;
  int local_818;
  int local_814;
  int local_810;
  char local_80c [12];
  undefined1 auStack_800 [24];
  char local_7e8;
  undefined1 auStack_7c4 [8];
  char local_7bc;
  undefined1 auStack_770 [34];
  undefined2 local_74e;
  byte local_74c;
  undefined1 auStack_6f0 [128];
  char acStack_670 [8];
  uint local_668 [62];
  char acStack_570 [256];
  undefined1 auStack_470 [218];
  char acStack_396 [65];
  char local_355 [77];
  undefined1 auStack_308 [16];
  undefined2 local_2f8;
  undefined1 auStack_2ba [650];
  undefined1 *local_30;
  
  memset(auStack_6f0,0,0x80);
  memset(auStack_470,0,0x168);
  memset(auStack_7c4,0,0x54);
  if (param_2[6] == -1) {
    iVar1 = *(int *)(param_1 + 0xc);
  }
  else {
    if (*(int *)(param_1 + 0x3c) != param_2[6]) {
      return 0;
    }
    if (*(int *)(param_1 + 0x14) == 7) {
      if (*(int *)(param_1 + 0x3c) == 0) {
        return 0;
      }
      iVar1 = sensor_is_bh_testing(*(undefined2 *)(param_1 + 0x10));
      if (iVar1 != 0) {
        return 0;
      }
      iVar1 = *(int *)(param_1 + 0xc);
    }
    else {
      iVar1 = *(int *)(param_1 + 0xc);
    }
  }
  uVar10 = 0;
  if (iVar1 != 0) {
    iVar1 = param_2[7];
    if (iVar1 == 2) {
      if (*(int *)(param_1 + 0x2ac) - 2U < 2) {
        return 0;
      }
      iVar1 = *(int *)(param_1 + 0x24);
    }
    else if (iVar1 == 1) {
      if (1 < *(int *)(param_1 + 0x2ac) - 2U) {
        return 0;
      }
      iVar1 = *(int *)(param_1 + 0x24);
    }
    else {
      if (iVar1 == -1) {
        return 0;
      }
      iVar1 = *(int *)(param_1 + 0x24);
    }
    uVar10 = 0;
    if (iVar1 == 0) {
      pcVar6 = (char *)param_2[3];
      if (pcVar6 == (char *)0x0) {
        iVar1 = param_2[2];
      }
      else if (*pcVar6 == '\0') {
        iVar1 = param_2[2];
      }
      else {
        iVar1 = _apmngr_db_search_check(param_1,pcVar6,param_2[4]);
        if (iVar1 != 1) {
          return 0;
        }
        iVar1 = param_2[2];
      }
      param_2[2] = iVar1 + 1;
      if (*param_2 < 1) {
        uVar10 = 0;
        if (0 < param_2[1]) {
          iVar1 = json_object_new_object();
          if (iVar1 == 0) {
            if (apmngr_err_switch == '\0') {
              return 1;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return 1;
            }
            uVar8 = 0x7bf;
          }
          else {
            memset(acStack_570,0,0x100);
            snprintf(acStack_570,0x100,"%d",(uint)*(ushort *)(param_1 + 0x10));
            uVar10 = json_object_new_string(acStack_570);
            json_object_object_add(iVar1,"entry_id",uVar10);
            uVar10 = json_object_new_string(param_1 + 0x4e);
            json_object_object_add(iVar1,"entry_name",uVar10);
            iVar2 = apdb_get_ap_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,auStack_470);
            if (iVar2 == 0) {
              pcVar6 = local_355;
              if (local_355[0] == '\0') {
                pcVar6 = acStack_396;
              }
              uVar10 = json_object_new_string(pcVar6);
              json_object_object_add(iVar1,"model_name",uVar10);
            }
            memset(auStack_800,0,0x3c);
            iVar2 = *(int *)(param_1 + 0x14);
            if ((((iVar2 == 4) || (iVar2 == 8)) || (iVar2 == 6)) || (iVar2 == 5)) {
              iVar2 = mesh_db_ap_entry_get(*(undefined2 *)(param_1 + 0x10),auStack_800);
              if ((iVar2 == 0) && (local_7e8 != '\0')) {
                pcVar6 = (char *)mesh_db_uplink_type_str_get();
              }
              else {
                pcVar6 = "unknown";
              }
              uVar10 = json_object_new_string(pcVar6);
              json_object_object_add(iVar1,"uplink_type",uVar10);
            }
            mac2str(param_1 + 0x48,auStack_6f0,0x80);
            uVar10 = json_object_new_string(auStack_6f0);
            json_object_object_add(iVar1,"mac",uVar10);
            FUN_00408190(*(undefined4 *)(param_1 + 0x26c),*(undefined4 *)(param_1 + 0x270),
                         *(undefined4 *)(param_1 + 0x274),*(undefined4 *)(param_1 + 0x278),
                         *(undefined4 *)(param_1 + 0x27c),auStack_6f0,0x80,"0.0.0.0");
            uVar10 = json_object_new_string(auStack_6f0);
            json_object_object_add(iVar1,&DAT_00677c24,uVar10);
            if (*(int *)(param_1 + 0x2ac) - 2U < 2) {
              memset(acStack_570,0,0x100);
              uVar10 = multi_link_status_get(*(undefined2 *)(param_1 + 0x10));
            }
            else {
              memset(acStack_570,0,0x100);
              uVar10 = 2;
            }
            snprintf(acStack_570,0x100,"%d",uVar10);
            uVar10 = json_object_new_string(acStack_570);
            json_object_object_add(iVar1,"link_status",uVar10);
            memset(acStack_570,0,0x100);
            snprintf(acStack_570,0x100,"%d",*(undefined4 *)(param_1 + 0x288));
            uVar10 = json_object_new_string(acStack_570);
            json_object_object_add(iVar1,"led_status",uVar10);
            memset(acStack_570,0,0x100);
            snprintf(acStack_570,0x100,"%d",(uint)*(byte *)(param_1 + 0x295));
            uVar10 = json_object_new_string(acStack_570);
            json_object_object_add(iVar1,"telnet_status",uVar10);
            if (*(int *)(param_1 + 0x14) == 7) {
              memset(acStack_670,0,0xc0);
              local_30 = auStack_308;
              memset(local_30,0,0x2d8);
              memset(auStack_770,0,0x80);
              local_810 = 0;
              local_814 = 0;
              local_818 = 0;
              local_81c = 0;
              local_820 = 0;
              local_80c[0] = '\0';
              local_80c[1] = '\0';
              local_80c[2] = '\0';
              local_80c[3] = '\0';
              local_80c[4] = '\0';
              local_80c[5] = '\0';
              local_80c[6] = '\0';
              local_80c[7] = '\0';
              local_80c[8] = '\0';
              local_80c[9] = '\0';
              iVar2 = sensor_db_vap_list_get
                                (*(undefined2 *)(param_1 + 0x10),acStack_670,0x10,&local_810);
              if (iVar2 == 0) {
                puVar12 = local_668;
                for (iVar2 = 0; iVar2 < local_810; iVar2 = iVar2 + 1) {
                  if ((((*puVar12 & 0x40) != 0) &&
                      (iVar3 = wsta_db_get_entry_by_mac(acStack_670 + iVar2 * 0xc,auStack_770),
                      iVar3 == 0)) &&
                     ((iVar3 = apmngr_db_entry_get_by_id(local_74e,auStack_308), iVar3 == 0 &&
                      (iVar3 = rdmngr_db_get_radio_cnt_by_ap_id(local_2f8,&local_814,&local_818),
                      iVar3 != -1)))) {
                    uVar10 = rdmngr_db_generate_rd_id(local_2f8,local_74c);
                    iVar3 = rdmngr_db_get_freq_band_idx(uVar10,&local_81c,&local_820);
                    if (iVar3 == 0) {
                      uVar10 = json_object_new_string(auStack_2ba);
                      json_object_object_add(iVar1,"link_ap_name",uVar10);
                      memset(acStack_570,0,0x100);
                      snprintf(acStack_570,0x100,"%d",(uint)local_74c);
                      uVar10 = json_object_new_string(acStack_570);
                      json_object_object_add(iVar1,"link_freq_unit",uVar10);
                      iVar2 = local_818;
                      if (local_81c == 0) {
                        iVar2 = local_814;
                      }
                      if (iVar2 < 2) {
                        if (local_81c == 0) {
                          pcVar6 = "2.4G";
                        }
                        else {
                          pcVar6 = "5G";
                        }
                        strcpy(local_80c,pcVar6);
                      }
                      else {
                        if (local_81c == 0) {
                          puVar9 = &DAT_00693fd4;
                        }
                        else {
                          puVar9 = &DAT_00693fd0;
                        }
                        snprintf(local_80c,10,"%s%d",puVar9,local_820);
                      }
                      uVar10 = json_object_new_string(local_80c);
                      pcVar6 = "link_freq_name";
                      goto LAB_0054bc28;
                    }
                  }
                  puVar12 = puVar12 + 3;
                }
              }
              uVar10 = json_object_new_string(&DAT_00688af8);
              pcVar6 = "link_ap_name";
LAB_0054bc28:
              json_object_object_add(iVar1,pcVar6,uVar10);
            }
            iVar2 = json_object_new_array();
            if (iVar2 != 0) {
              uVar11 = 1;
              iVar3 = apdb_radio_count_by_id(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218);
              while( true ) {
                while( true ) {
                  if (iVar3 < (int)uVar11) {
                    json_object_object_add(iVar1,"rf_entry",iVar2);
                    iVar2 = 0;
                    if (*(int *)(param_1 + 0x2ac) - 2U < 2) {
                      FUN_00407e70();
                      iVar2 = extraout_v1 - *(int *)(param_1 + 0x284);
                    }
                    memset(acStack_670,0,0x100);
                    snprintf(acStack_670,0x100,"%d",iVar2);
                    uVar10 = json_object_new_string(acStack_670);
                    json_object_object_add(iVar1,"online_time",uVar10);
                    json_object_array_add(param_2[5],iVar1);
                    param_2[1] = param_2[1] + -1;
                    return 0;
                  }
                  uVar4 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),uVar11);
                  iVar5 = rdmngr_db_rd_entry_get(uVar4,auStack_7c4);
                  if (iVar5 == 0) break;
                  uVar11 = uVar11 + 1;
                }
                iVar5 = json_object_new_object();
                if (iVar5 == 0) break;
                memset(acStack_670,0,0x100);
                snprintf(acStack_670,0x100,"%d",uVar4 & 0xf);
                uVar10 = json_object_new_string(acStack_670);
                json_object_object_add(iVar5,"freq_unit",uVar10);
                pcVar6 = (char *)apdb_get_radio_freq_name_by_freq((int)local_7bc);
                if (pcVar6 == (char *)0x0) {
                  pcVar6 = "---";
                }
                uVar10 = json_object_new_string(pcVar6);
                json_object_object_add(iVar5,"freq_name",uVar10);
                memset(acStack_670,0,0x100);
                uVar7 = uVar11 & 0xff;
                uVar11 = uVar11 + 1;
                uVar10 = wsta_db_get_rd_sta_num(*(undefined2 *)(param_1 + 0x10),uVar7);
                snprintf(acStack_670,0x100,"%d",uVar10);
                uVar10 = json_object_new_string(acStack_670);
                json_object_object_add(iVar5,"rf_client_num",uVar10);
                memset(acStack_670,0,0x100);
                uVar10 = rdmngr_db_get_rd_entry_chnl(uVar4);
                snprintf(acStack_670,0x100,"%d",uVar10);
                uVar10 = json_object_new_string(acStack_670);
                json_object_object_add(iVar5,"channel",uVar10);
                json_object_array_add(iVar2,iVar5);
              }
              if ((apmngr_err_switch != '\0') && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                printf("[APMNGR_ERROR]%s()/%d Create json object failed when tranverse ap list.\n",
                       "_apmngr_db_status_get",0x829);
              }
              json_object_put(iVar1);
              json_object_put(iVar2);
              return 1;
            }
            json_object_put(iVar1);
            if (apmngr_err_switch == '\0') {
              return 1;
            }
            iVar1 = is_target_debug_ap();
            if (iVar1 == 0) {
              return 1;
            }
            uVar8 = 0x819;
          }
          uVar10 = 1;
          printf("[APMNGR_ERROR]%s()/%d Create json object failed when tranverse ap list.\n",
                 "_apmngr_db_status_get",uVar8);
        }
      }
      else {
        uVar10 = 0;
        *param_2 = *param_2 + -1;
      }
    }
  }
  return uVar10;
}

