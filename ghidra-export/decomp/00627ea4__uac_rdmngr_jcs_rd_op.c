// func _uac_rdmngr_jcs_rd_op @ 00627ea4 size=1672

void _uac_rdmngr_jcs_rd_op(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  char *__dest;
  char *__s;
  undefined2 uVar9;
  undefined4 uVar7;
  size_t sVar8;
  char *pcVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint uVar13;
  undefined4 local_360 [18];
  char local_318;
  undefined1 auStack_308 [20];
  uint local_2f4;
  int local_30;
  int local_2c;
  
  memset(auStack_308,0,0x2d8);
  memset(local_360,0,0x54);
  iVar2 = rdmngr_profile_get_max_rd_per_ap();
  iVar3 = apmngr_db_get_ap_max();
  iVar4 = apmngr_db_get_template_max();
  iVar5 = apmngr_db_get_sensor_max();
  puVar6 = (undefined4 *)FUN_004082a0((iVar3 + iVar4 + iVar5) * iVar2,4,0x8bd);
  if (puVar6 == (undefined4 *)0x0) {
    if ((rdmngr_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) {
      __dest = (char *)0x0;
    }
    else {
      printf("[RDMNGR_ERROR]%s()/%d no memory!\n","_uac_rdmngr_jcs_rd_op",0x8c0);
      __dest = (char *)0x0;
    }
LAB_00628118:
    __s = (char *)0x0;
    uVar11 = 0xffffffff;
  }
  else {
    __dest = (char *)FUN_00408450(0x1c16,0x8c4);
    if (__dest == (char *)0x0) {
      if (rdmngr_err_switch == 0) goto LAB_00628118;
      iVar2 = is_target_debug_ap();
      __s = (char *)0x0;
      if (iVar2 == 0) {
        uVar11 = 0xffffffff;
        goto LAB_0062811c;
      }
      pcVar10 = "[RDMNGR_ERROR]%s()/%d no memory!\n";
      uVar7 = 0x8c7;
    }
    else {
      memset(__dest,0,0x1c16);
      __s = (char *)FUN_00408450(0x1c16,0x8cc);
      if (__s == (char *)0x0) {
        uVar11 = 0xffffffff;
        if (rdmngr_err_switch == 0) goto LAB_0062811c;
        iVar2 = is_target_debug_ap();
        uVar7 = 0x8cf;
        if (iVar2 == 0) goto LAB_0062811c;
        pcVar10 = "[RDMNGR_ERROR]%s()/%d no memory!\n";
      }
      else {
        memset(__s,0,0x1c16);
        iVar2 = json_object_object_get(param_1,"operation");
        if (iVar2 == 0) {
LAB_00627fbc:
          uVar13 = 0;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get boolean with error obj or value type is unmatch.\n"
                   ,"_uac_rdmngr_jcs_rd_op",0x8d5);
          }
        }
        else {
          iVar3 = json_object_get_type(iVar2);
          if (iVar3 == 1) {
            iVar2 = json_object_get_boolean(iVar2);
            uVar13 = (uint)(iVar2 != 0);
          }
          else {
            iVar3 = json_object_get_type();
            if (iVar3 != 3) goto LAB_00627fbc;
            iVar2 = json_object_get_int(iVar2);
            uVar13 = (uint)(iVar2 != 0);
          }
        }
        iVar2 = json_object_object_get(param_1,"multi_id_list");
        if (iVar2 != 0) {
          iVar3 = json_object_get_type(iVar2);
          if (iVar3 == 6) {
            pcVar10 = (char *)json_object_get_string(iVar2);
          }
          else {
            if (jcs_err_switch != 0) {
              printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                     ,"_uac_rdmngr_jcs_rd_op",0x8de);
            }
            pcVar10 = "";
          }
          strncpy(__dest,pcVar10,0x1c15);
          __dest[0x1c15] = '\0';
          iVar2 = rdmngr_profile_get_max_rd_per_ap();
          iVar3 = apmngr_db_get_ap_max();
          iVar4 = apmngr_db_get_template_max();
          iVar5 = apmngr_db_get_sensor_max();
          local_2c = FUN_0062784c(__dest,puVar6,(iVar3 + iVar4 + iVar5) * iVar2);
          if (local_2c < 1) {
            uVar11 = 0xffffffff;
            if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[RDMNGR_ERROR]%s()/%d _uac_rdmngr_util_str_split() fail, str: %s!\n",
                     "_uac_rdmngr_jcs_rd_op",0x8e3,__dest);
              uVar11 = 0xffffffff;
            }
          }
          else {
            local_30 = 0;
            uVar11 = 0;
            puVar12 = puVar6;
            do {
              iVar2 = atoi((char *)*puVar12);
              iVar2 = rdmngr_db_rd_entry_get(iVar2,local_360);
              if (iVar2 == 0) {
                iVar2 = atoi((char *)*puVar12);
                uVar9 = rdmngr_db_generate_ap_id(iVar2);
                iVar2 = apmngr_db_entry_get_by_id(uVar9,auStack_308);
                if (iVar2 != 0) goto LAB_00628074;
                if (((local_2f4 < 2) || (local_2f4 == 3)) || (local_2f4 == 2)) {
                  bVar1 = local_318 != '\0';
                  if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                    printf("[RDMNGR_DEBUG]%s()/%d newStatus:%d, old:%d\n","_uac_rdmngr_jcs_rd_op",
                           0x8f8,uVar13,(uint)bVar1);
                  }
                  if (bVar1 == 0) {
                    if (uVar13 != 0) {
                      iVar2 = rdmngr_db_rd_entry_enable(local_360[0]);
                      goto LAB_0062836c;
                    }
                    uVar11 = uVar11 | 1;
                    goto LAB_00628080;
                  }
                  if (uVar13 != 0) {
                    uVar11 = uVar11 | 1;
                    goto LAB_00628080;
                  }
                  iVar2 = rdmngr_db_rd_entry_disable(local_360[0]);
LAB_0062836c:
                  if (iVar2 == 0) {
                    uVar11 = uVar11 | 2;
                  }
                  rdmngr_trigger_radio_onoff_nms_event(local_360[0],uVar13);
                  sVar8 = strlen(__s);
                  iVar2 = atoi((char *)*puVar12);
                  sprintf(__s + sVar8,"%d,",iVar2);
                  local_318 = (char)uVar13;
                  iVar2 = apmngr_checksum_update(auStack_308,0);
                  if (iVar2 != 0) {
                    if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                      printf("[RDMNGR_ERROR]%s()/%d update md5 failed.\n","_uac_rdmngr_jcs_rd_op",
                             0x917);
                    }
                    goto LAB_00628080;
                  }
                  uVar7 = rdmngr_db_generate_ap_id(local_360[0]);
                  iVar2 = rdmngr_wtp_pkt_send(uVar7,local_360);
                  if (iVar2 == 0) {
                    rdmngr_callback_proc(uVar13,local_360[0],0,0);
                    goto LAB_00628080;
                  }
                  if ((rdmngr_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
                  goto LAB_00628080;
                  pcVar10 = "[RDMNGR_ERROR]%s()/%d rd_id:%s, rdmngr_wtp_pkt_send() failed.\n";
                  uVar7 = 0x91c;
                  goto LAB_006281ec;
                }
                if (rdmngr_debug_switch == 0) {
                  uVar11 = uVar11 | 1;
                }
                else {
                  iVar2 = is_target_debug_ap();
                  if (iVar2 == 0) {
                    uVar11 = uVar11 | 1;
                  }
                  else {
                    printf("[RDMNGR_DEBUG]%s()/%d rd_id:%s can not enable/disable.\n",
                           "_uac_rdmngr_jcs_rd_op",0x8f2,*puVar12);
                    uVar11 = uVar11 | 1;
                  }
                }
              }
              else {
LAB_00628074:
                if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  uVar7 = 0x8ec;
                  pcVar10 = 
                  "[RDMNGR_ERROR]%s()/%d rd_id:%s, rdmngr_db_rd_entry_get() or apmngr_db_entry_get_by_id() failed.\n"
                  ;
LAB_006281ec:
                  printf(pcVar10,"_uac_rdmngr_jcs_rd_op",uVar7,*puVar12);
                }
              }
LAB_00628080:
              puVar12 = puVar12 + 1;
              local_30 = local_30 + 1;
            } while (local_30 != local_2c);
            if (uVar11 == 0) {
              uVar11 = 0xffffffff;
            }
          }
          goto LAB_0062811c;
        }
        uVar11 = 0xffffffff;
        if (rdmngr_err_switch == 0) goto LAB_0062811c;
        iVar2 = is_target_debug_ap();
        uVar7 = 0x8da;
        if (iVar2 == 0) goto LAB_0062811c;
        pcVar10 = "[RDMNGR_ERROR]%s()/%d multi_id_list not found!\n";
      }
    }
    uVar11 = 0xffffffff;
    printf(pcVar10,"_uac_rdmngr_jcs_rd_op",uVar7);
  }
LAB_0062811c:
  uVar7 = json_object_new_int(uVar11);
  json_object_object_add(param_2,"result",uVar7);
  sVar8 = strlen(__s);
  if (1 < sVar8) {
    __s[sVar8 - 1] = '\0';
    uVar7 = json_object_new_string(__s);
    json_object_object_add(param_2,"success_id_list",uVar7);
  }
  if (puVar6 != (undefined4 *)0x0) {
    FUN_00407df0(puVar6);
  }
  if (__dest != (char *)0x0) {
    FUN_00407df0(__dest);
  }
  if (__s != (char *)0x0) {
    FUN_00407df0(__s);
  }
  return;
}

