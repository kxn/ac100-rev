// func _uac_wserv_jcs_wserv_op @ 005daf78 size=1652

void _uac_wserv_jcs_wserv_op(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  char *__dest;
  undefined4 uVar8;
  char *pcVar9;
  undefined4 local_248;
  undefined1 auStack_244 [283];
  int local_129;
  int local_38;
  undefined4 *local_34;
  int local_30;
  int local_2c;
  
  memset(auStack_244,0,0x205);
  local_248 = 0;
  iVar1 = apmngr_db_get_ap_max();
  uVar2 = apmngr_db_get_ap_max();
  iVar1 = FUN_004082a0((iVar1 >> 5) + (uint)((uVar2 & 0x1f) != 0),4,0xd7d);
  if (iVar1 == 0) {
    puVar7 = (undefined4 *)0x0;
    if ((g_wserv_error == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0)) {
      __dest = (char *)0x0;
    }
    else {
      printf("<wserv>[error]%s(): %d  -> wserv_db_entry_disable() fail\r\n",
             "_uac_wserv_jcs_wserv_op",0xd80);
      __dest = (char *)0x0;
    }
LAB_005db1f0:
    uVar8 = json_object_new_int(0xffffffff);
    json_object_object_add(param_2,"result",uVar8);
    if (puVar7 == (undefined4 *)0x0) goto LAB_005db21c;
  }
  else {
    iVar3 = apmngr_db_get_ap_max();
    iVar4 = apmngr_db_get_template_max();
    iVar5 = apmngr_db_get_sensor_max();
    iVar6 = rdmngr_profile_get_max_rd_per_ap();
    puVar7 = (undefined4 *)FUN_004082a0((iVar3 + iVar4 + iVar5) * iVar6,4,0xd84);
    if (puVar7 == (undefined4 *)0x0) {
      __dest = (char *)0x0;
      if (g_wserv_error != 0) {
        iVar3 = is_target_debug_ap();
        __dest = (char *)0x0;
        if (iVar3 != 0) {
          uVar8 = 0xd87;
          goto LAB_005db454;
        }
      }
      goto LAB_005db1f0;
    }
    __dest = (char *)FUN_00408450(0x1c16,0xd8b);
    if (__dest == (char *)0x0) {
      if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        uVar8 = 0xd8e;
LAB_005db454:
        printf("<wserv>[error]%s(): %d  -> no memory!\r\n","_uac_wserv_jcs_wserv_op",uVar8);
      }
      goto LAB_005db1f0;
    }
    iVar3 = json_object_object_get(param_1,"serv_id");
    if (iVar3 == 0) {
      if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_wserv_op",0xd93,
               "serv_id");
      }
    }
    else {
      memset(__dest,0,0x1c16);
      iVar4 = json_object_get_type(iVar3);
      if (iVar4 == 6) {
        pcVar9 = (char *)json_object_get_string(iVar3);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "_uac_wserv_jcs_wserv_op",0xd96);
        }
        pcVar9 = "";
      }
      strncpy(__dest,pcVar9,0x1c15);
      __dest[0x1c15] = '\0';
      iVar3 = apmngr_db_get_ap_max();
      iVar4 = apmngr_db_get_template_max();
      iVar5 = apmngr_db_get_sensor_max();
      iVar6 = rdmngr_profile_get_max_rd_per_ap();
      local_2c = FUN_005d9d1c(__dest,puVar7,(iVar3 + iVar4 + iVar5) * iVar6);
      if (local_2c < 1) {
        if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("<wserv>[error]%s(): %d  -> _uac_wserv_util_str_split() fail, str: %s!\r\n",
                 "_uac_wserv_jcs_wserv_op",0xd9b,__dest);
        }
        goto LAB_005db1f0;
      }
      local_38 = 0;
      iVar3 = -1;
      local_30 = 0;
      local_34 = puVar7;
      do {
        iVar4 = atoi((char *)*local_34);
        iVar5 = wserv_db_get_entry_by_id(iVar4,auStack_244);
        if (iVar5 == 0) {
          if (param_3 == 0) {
            if (local_129 == 0) goto LAB_005db170;
            iVar3 = wserv_db_entry_disable(iVar4,_uac_wserv_del_cb);
            if (iVar3 == -1) {
              if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                pcVar9 = "<wserv>[error]%s(): %d  -> wserv_db_entry_disable() del fail\r\n";
                uVar8 = 0xdcc;
LAB_005db570:
                printf(pcVar9,"_uac_wserv_jcs_wserv_op",uVar8);
              }
            }
            else {
              iVar3 = wserv_db_entry_disable(iVar4,_uac_wserv_add_cb);
              if (iVar3 != -1) goto LAB_005db520;
              if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                uVar8 = 0xdd3;
                pcVar9 = "<wserv>[error]%s(): %d  -> wserv_db_entry_disable() add fail\r\n";
                goto LAB_005db570;
              }
            }
LAB_005db364:
            local_38 = 1;
LAB_005db36c:
            iVar3 = -1;
            if ((g_wserv_warning != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
              if (param_3 == 0) {
                pcVar9 = "disable";
              }
              else {
                pcVar9 = "enable";
              }
              printf("<wserv>[warning]%s(): %d  -> wserv_db_entry_%s fail. wserv_id[%d]\r\n",
                     "_uac_wserv_jcs_wserv_op",0xdde,pcVar9,iVar4);
              iVar3 = -1;
            }
          }
          else {
            if (local_129 == 0) {
              iVar3 = wserv_db_entry_enable(iVar4,_uac_wserv_del_cb);
              if (iVar3 == -1) {
                if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                  printf("<wserv>[error]%s(): %d  -> wserv_db_entry_Enable() del fail\r\n",
                         "_uac_wserv_jcs_wserv_op",0xdb1);
                }
              }
              else {
                uac_wservice_sync_all_wlan_to_re();
              }
              iVar3 = wserv_db_entry_enable(iVar4,_uac_wserv_add_cb);
              if (iVar3 == -1) {
                if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                  pcVar9 = "<wserv>[error]%s(): %d  -> wserv_db_entry_Enable() add fail\r\n";
                  uVar8 = 0xdbb;
                  goto LAB_005db570;
                }
                goto LAB_005db364;
              }
LAB_005db520:
              uac_wservice_sync_all_wlan_to_re();
              local_38 = 1;
            }
            else {
LAB_005db170:
              if (iVar3 == -1) goto LAB_005db36c;
            }
            iVar5 = apmngr_db_get_ap_max();
            uVar2 = apmngr_db_get_ap_max();
            iVar5 = wserv_db_entry_get_binded_ap_id_bm
                              (iVar4,iVar1,(iVar5 >> 5) + (uint)((uVar2 & 0x1f) != 0),&local_248);
            if (((iVar5 != 0) && (g_wserv_error != 0)) && (iVar5 = is_target_debug_ap(), iVar5 != 0)
               ) {
              pcVar9 = 
              "<wserv>[error]%s(): %d  -> wserv_db_entry_get_binded_ap_id_bm() fail. wserv_id[%d]\r\n"
              ;
              uVar8 = 0xde5;
              goto LAB_005db3d8;
            }
          }
        }
        else if ((g_wserv_warning != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          uVar8 = 0xda4;
          pcVar9 = "<wserv>[warning]%s(): %d  -> wserv_db_get_entry_by_id() fail. wserv_id[%d]\r\n";
LAB_005db3d8:
          printf(pcVar9,"_uac_wserv_jcs_wserv_op",uVar8,iVar4);
        }
        local_34 = local_34 + 1;
        local_30 = local_30 + 1;
      } while (local_30 != local_2c);
      _uac_wserv_update_aps_md5(iVar1,local_248);
      iVar4 = 1;
      if (local_38 != 0) {
        iVar4 = iVar3;
      }
      uVar8 = json_object_new_int(iVar4);
      json_object_object_add(param_2,"result",uVar8);
    }
  }
  FUN_00407df0(puVar7);
LAB_005db21c:
  if (__dest != (char *)0x0) {
    FUN_00407df0(__dest);
  }
  if (iVar1 != 0) {
    FUN_00407df0(iVar1);
  }
  return;
}

