// func _uac_rdmngr_jcs_setable @ 006278e4 size=1472

int _uac_rdmngr_jcs_setable(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  char *__dest;
  undefined2 uVar8;
  undefined4 uVar6;
  uint uVar7;
  char *pcVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined8 uVar12;
  int local_688;
  undefined1 auStack_684 [12];
  short local_678;
  uint local_630 [2];
  char local_628;
  short local_624;
  undefined1 auStack_5d8 [16];
  undefined2 local_5c8;
  undefined4 local_598;
  undefined1 auStack_3c0 [192];
  undefined1 auStack_300 [20];
  int local_2ec;
  undefined2 local_2e8;
  undefined4 local_2c0;
  undefined1 auStack_e8 [192];
  
  memset(local_630,0,0x54);
  memset(auStack_300,0,0x2d8);
  local_688 = 0;
  memset(auStack_5d8,0,0x2d8);
  memset(auStack_684,0,0x54);
  iVar1 = rdmngr_profile_get_max_rd_per_ap();
  iVar2 = apmngr_db_get_ap_max();
  iVar3 = apmngr_db_get_template_max();
  iVar4 = apmngr_db_get_sensor_max();
  puVar5 = (undefined4 *)FUN_004082a0((iVar2 + iVar3 + iVar4) * iVar1,4,0x956);
  if (puVar5 == (undefined4 *)0x0) {
    iVar1 = 0;
    if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d no memory!\n","_uac_rdmngr_jcs_setable",0x959);
      iVar1 = 0;
    }
    goto LAB_00627bfc;
  }
  __dest = (char *)FUN_00408450(0x1c16,0x95e);
  if (__dest == (char *)0x0) {
    iVar1 = 0;
    if (rdmngr_err_switch != 0) {
      iVar2 = is_target_debug_ap();
      iVar1 = 0;
      if (iVar2 != 0) {
        pcVar9 = "[RDMNGR_ERROR]%s()/%d no memory!\n";
        uVar6 = 0x961;
        goto LAB_00627d80;
      }
    }
  }
  else {
    iVar1 = json_object_object_get(param_1,"multi_id_list");
    if (iVar1 == 0) {
      iVar1 = 0;
      if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        pcVar9 = "[RDMNGR_ERROR]%s()/%d multi_id_list not found!\n";
        uVar6 = 0x969;
LAB_00627d80:
        printf(pcVar9,"_uac_rdmngr_jcs_setable",uVar6);
      }
    }
    else {
      memset(__dest,0,0x1c16);
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 6) {
        pcVar9 = (char *)json_object_get_string(iVar1);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_uac_rdmngr_jcs_setable",0x96f);
        }
        pcVar9 = "";
      }
      strncpy(__dest,pcVar9,0x1c15);
      __dest[0x1c15] = '\0';
      iVar1 = rdmngr_profile_get_max_rd_per_ap();
      iVar2 = apmngr_db_get_ap_max();
      iVar3 = apmngr_db_get_template_max();
      iVar4 = apmngr_db_get_sensor_max();
      iVar2 = FUN_0062784c(__dest,puVar5,(iVar2 + iVar3 + iVar4) * iVar1);
      if (iVar2 < 1) {
        iVar1 = 1;
        if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[RDMNGR_ERROR]%s()/%d _uac_rdmngr_util_str_split() fail, str: %s!\n",
                 "_uac_rdmngr_jcs_setable",0x974,__dest);
        }
      }
      else {
        iVar1 = mesh_db_bh_work_mode_get(&local_688);
        if (iVar1 == -1) {
          iVar1 = 1;
          if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            pcVar9 = "[RDMNGR_ERROR]%s()/%d get mesh bh work mode error\n";
            uVar6 = 0x97a;
            goto LAB_00627d80;
          }
        }
        else {
          iVar3 = 0;
          puVar10 = puVar5;
          do {
            iVar1 = atoi((char *)*puVar10);
            iVar1 = rdmngr_db_rd_entry_get(iVar1,local_630);
            if (iVar1 == 0) {
              iVar1 = json_object_object_get(param_1,"channel");
              if (iVar1 != 0) {
                iVar4 = json_object_get_type(iVar1);
                if (iVar4 == 3) {
                  local_624 = json_object_get_int(iVar1);
                }
                else {
                  iVar4 = json_object_get_type();
                  if (iVar4 == 2) {
                    uVar12 = json_object_get_double(iVar1);
                    local_624 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
                  }
                  else {
                    if (jcs_err_switch != 0) {
                      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                             ,"_uac_rdmngr_jcs_setable",0x987);
                    }
                    local_624 = -1;
                  }
                }
              }
              iVar1 = atoi((char *)*puVar10);
              uVar8 = rdmngr_db_generate_ap_id(iVar1);
              iVar1 = apmngr_db_entry_get_by_id(uVar8,auStack_300);
              if (iVar1 == 0) {
                if (((local_624 != -1) &&
                    ((((local_2ec == 4 || (local_2ec == 8)) || (local_2ec == 6)) || (local_2ec == 5)
                     ))) && (iVar1 = apmngr_db_entry_get_by_id(local_2e8,auStack_5d8), iVar1 != -1))
                {
                  iVar1 = apdb_radio_count_by_id(local_598,auStack_3c0);
                  iVar4 = apdb_radio_count_by_id(local_2c0,auStack_e8);
                  if (iVar4 < 2) {
LAB_00627d48:
                    iVar1 = 0;
                    goto LAB_00627b6c;
                  }
                  if (local_628 == '\0') {
                    if (local_688 == 2) goto LAB_00627d48;
                  }
                  else if (local_628 == '\x01') {
                    if (iVar4 == 2) goto LAB_00627d48;
                    if (iVar4 == 3) {
                      uVar11 = local_630[0] & 0xf;
                      if (iVar1 == 3) {
                        iVar1 = 0;
                        if ((local_688 == 2) || (uVar11 == 2)) goto LAB_00627b6c;
                      }
                      else if (iVar1 == 2) {
                        uVar6 = rdmngr_db_generate_rd_id(local_5c8,2);
                        iVar1 = rdmngr_db_rd_entry_get(uVar6,auStack_684);
                        if ((iVar1 == 0) &&
                           (uVar7 = rdmngr_db_get_band_by_channel((int)local_678), uVar7 == uVar11))
                        {
                          iVar1 = 0;
                          goto LAB_00627b6c;
                        }
                      }
                    }
                  }
                }
              }
              else if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
                uVar6 = 0x98c;
                pcVar9 = "[RDMNGR_ERROR]%s()/%d get ap_entry error by rd_id: %s\n";
                goto LAB_00627b4c;
              }
            }
            else if ((rdmngr_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
              pcVar9 = "[RDMNGR_ERROR]%s()/%d rd_id:%s, rdmngr_db_rd_entry_get() failed.\n";
              uVar6 = 0x982;
LAB_00627b4c:
              printf(pcVar9,"_uac_rdmngr_jcs_setable",uVar6,*puVar10);
            }
            iVar3 = iVar3 + 1;
            puVar10 = puVar10 + 1;
          } while (iVar3 != iVar2);
          iVar1 = 1;
        }
      }
    }
  }
LAB_00627b6c:
  FUN_00407df0(puVar5);
  if (__dest != (char *)0x0) {
    FUN_00407df0(__dest);
  }
  if (iVar1 != 0) {
    return iVar1;
  }
LAB_00627bfc:
  uVar6 = json_object_new_int(4);
  json_object_object_add(param_2,"result",uVar6);
  return iVar1;
}

