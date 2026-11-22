// func _wportal_get_ssid_page @ 0040efa8 size=1664

undefined4 _wportal_get_ssid_page(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  short sVar5;
  char *pcVar6;
  short local_600 [2];
  char local_5fc [8];
  undefined4 local_5f4;
  undefined4 local_5f0;
  undefined4 local_5ec;
  undefined4 local_5e8;
  undefined4 local_5e4;
  char local_5e0 [20];
  undefined4 local_5cc;
  undefined4 local_5c8;
  undefined4 local_5c4;
  undefined4 local_5c0;
  uint local_5bc;
  undefined4 local_5b8;
  undefined1 auStack_5b4 [4];
  undefined1 auStack_5b0 [4];
  undefined1 auStack_5ac [4];
  undefined1 auStack_5a8 [4];
  undefined1 auStack_5a4 [4];
  char local_5a0 [39];
  undefined1 local_579;
  undefined1 auStack_578 [32];
  uint local_558;
  undefined1 local_554;
  undefined1 local_553;
  byte local_510;
  byte local_50f;
  byte local_50e;
  byte local_50d;
  byte local_50c;
  byte local_50b;
  undefined1 auStack_4f8 [304];
  undefined1 auStack_3c8 [216];
  undefined1 auStack_2f0 [72];
  byte local_2a8;
  byte local_2a7;
  byte local_2a6;
  byte local_2a5;
  byte local_2a4;
  byte local_2a3;
  
  local_5cc = 0;
  local_5c8 = 0;
  local_5c4 = 0;
  local_5c0 = 0;
  local_5bc = 0;
  local_5e0[0] = '\0';
  local_5e0[1] = '\0';
  local_5e0[2] = '\0';
  local_5e0[3] = '\0';
  local_5e0[4] = '\0';
  local_5e0[5] = '\0';
  local_5e0[6] = '\0';
  local_5e0[7] = '\0';
  local_5e0[8] = '\0';
  local_5e0[9] = '\0';
  local_5e0[10] = '\0';
  local_5e0[0xb] = '\0';
  local_5e0[0xc] = '\0';
  local_5e0[0xd] = '\0';
  local_5e0[0xe] = '\0';
  local_5e0[0xf] = '\0';
  local_5e0[0x10] = '\0';
  local_5e0[0x11] = '\0';
  local_5e0[0x12] = '\0';
  local_5e0[0x13] = '\0';
  memset(local_5a0,0,0x28);
  local_600[0] = 0;
  memset(auStack_2f0,0,0x2d8);
  local_5fc[0] = '\0';
  local_5fc[1] = '\0';
  local_5fc[2] = '\0';
  local_5fc[3] = '\0';
  local_5fc[4] = '\0';
  local_5fc[5] = '\0';
  iVar1 = json_object_object_get(param_1,"mac");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar6 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_wportal_get_ssid_page",0x21a3);
      }
      pcVar6 = "";
    }
    strncpy((char *)&local_5cc,pcVar6,0x13);
    local_5bc = local_5bc & 0xffffff00;
    if (local_5cc._0_1_ != '\0') {
      sscanf((char *)&local_5cc,"%2X-%2X-%2X-%2X-%2X-%2X",&local_5b8,auStack_5b4,auStack_5b0,
             auStack_5ac,auStack_5a8,auStack_5a4);
      puVar3 = &local_5b8;
      iVar1 = 0;
      do {
        pcVar6 = local_5fc + iVar1;
        uVar4 = *puVar3;
        iVar1 = iVar1 + 1;
        puVar3 = puVar3 + 1;
        *pcVar6 = (char)uVar4;
      } while (iVar1 != 6);
    }
  }
  memset(local_5a0,0,0x28);
  iVar1 = json_object_object_get(param_1,&DAT_00677c24);
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar6 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_wportal_get_ssid_page",0x21b6);
      }
      pcVar6 = "";
    }
    strncpy(local_5a0,pcVar6,0x27);
    local_579 = 0;
    FUN_0051a7a8(local_5a0,&local_5f4);
  }
  memset(auStack_578,0,0x80);
  if ((((local_5fc[0] == '\0') && (local_5fc[1] == '\0')) && (local_5fc[2] == '\0')) &&
     (local_5fc[3] == '\0')) {
    if (((local_5fc[4] == '\0') && (local_5fc[5] == '\0')) && (local_5a0[0] != '\0')) {
      iVar1 = wsta_db_get_entry_by_ip(local_5f4,local_5f0,local_5ec,local_5e8,local_5e4,auStack_578)
      ;
      if (iVar1 == 0) goto LAB_0040f1d8;
      uVar4 = 0xffffffff;
      if (wportal_debug_switch == 0) goto LAB_0040f204;
      iVar1 = is_target_debug_ap(0xffffffff);
      if (iVar1 == 0) {
        uVar4 = 0xffffffff;
        goto LAB_0040f204;
      }
      pcVar6 = "[WPORTAL_DBG]%s()/%d Get wsta entry fail\n\n";
      uVar4 = 0x21c0;
    }
    else {
      if ((local_5fc[4] != '\0') || (local_5fc[5] != '\0')) goto LAB_0040f1c4;
      uVar4 = 0xffffffff;
      if (wportal_debug_switch == 0) goto LAB_0040f204;
      iVar1 = is_target_debug_ap(0xffffffff);
      if (iVar1 == 0) {
        uVar4 = 0xffffffff;
        goto LAB_0040f204;
      }
      pcVar6 = "[WPORTAL_DBG]%s()/%d MAC is ZERO and IP is empty\n\n";
      uVar4 = 0x21d1;
    }
  }
  else {
LAB_0040f1c4:
    iVar1 = wsta_db_get_entry_by_mac(local_5fc,auStack_578);
    if (iVar1 == 0) {
LAB_0040f1d8:
      iVar1 = uac_wservice_get_wserv_id(local_558,local_554,local_553);
      if (iVar1 == -1) {
        uVar4 = 0xffffffff;
        if (wportal_debug_switch == 0) goto LAB_0040f204;
        iVar1 = is_target_debug_ap(0xffffffff);
        if (iVar1 == 0) {
          uVar4 = 0xffffffff;
          goto LAB_0040f204;
        }
        pcVar6 = "[WPORTAL_DBG]%s()/%d Get wserv_id fail\n\n";
        uVar4 = 0x21d9;
      }
      else {
        memset(auStack_4f8,0,0x205);
        iVar2 = uac_wservice_get_entry_by_id(iVar1,auStack_4f8);
        if (iVar2 == 0) {
          iVar2 = uac_wservice_get_vlan(local_558,local_554,local_553,local_600);
          if ((iVar2 != 0) && (wportal_debug_switch != 0)) {
            iVar2 = is_target_debug_ap();
            if (iVar2 != 0) {
              printf("[WPORTAL_DBG]%s()/%d uac_wservice_get_vlan get fail\n\n",
                     "_wportal_get_ssid_page",0x21e9);
            }
          }
          if ((local_5fc[0] == '\0') && (local_5fc[1] == '\0')) {
            if ((local_5fc[2] == '\0') &&
               ((((local_5fc[3] == '\0' && (local_5fc[4] == '\0')) && (local_5fc[5] == '\0')) &&
                ((snprintf((char *)&local_5cc,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_510,
                           (uint)local_50f,(uint)local_50e,(uint)local_50d,(uint)local_50c,
                           (uint)local_50b), wportal_info_switch != 0 &&
                 (iVar2 = is_target_debug_ap(), iVar2 != 0)))))) {
              printf("[WPORTAL_INFO]%s()/%d get mac by ip:%s - %s\n\n","_wportal_get_ssid_page",
                     0x21f0,&local_5cc,local_5a0);
            }
          }
          memset(auStack_2f0,0,0x2d8);
          local_5e0[0] = '\0';
          local_5e0[1] = '\0';
          local_5e0[2] = '\0';
          local_5e0[3] = '\0';
          local_5e0[4] = '\0';
          local_5e0[5] = '\0';
          local_5e0[6] = '\0';
          local_5e0[7] = '\0';
          local_5e0[8] = '\0';
          local_5e0[9] = '\0';
          local_5e0[10] = '\0';
          local_5e0[0xb] = '\0';
          local_5e0[0xc] = '\0';
          local_5e0[0xd] = '\0';
          local_5e0[0xe] = '\0';
          local_5e0[0xf] = '\0';
          local_5e0[0x10] = '\0';
          local_5e0[0x11] = '\0';
          local_5e0[0x12] = '\0';
          local_5e0[0x13] = '\0';
          iVar2 = apmngr_db_entry_get_by_id(local_558 & 0xffff,auStack_2f0);
          if (iVar2 == 0) {
            snprintf(local_5e0,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_2a8,(uint)local_2a7,
                     (uint)local_2a6,(uint)local_2a5,(uint)local_2a4,(uint)local_2a3);
          }
          uVar4 = json_object_new_int(iVar1);
          json_object_object_add(param_2,"serv_id",uVar4);
          sVar5 = local_600[0];
          if (local_600[0] == 0) {
            sVar5 = 0xfff;
          }
          uVar4 = json_object_new_int(sVar5);
          json_object_object_add(param_2,"vlan_id",uVar4);
          uVar4 = json_object_new_string(auStack_3c8);
          json_object_object_add(param_2,"ssid",uVar4);
          uVar4 = json_object_new_string(&local_5cc);
          json_object_object_add(param_2,"mac",uVar4);
          uVar4 = json_object_new_string(local_5e0);
          json_object_object_add(param_2,"apMac",uVar4);
          uVar4 = 0;
          goto LAB_0040f204;
        }
        uVar4 = 0xffffffff;
        if (wportal_debug_switch == 0) goto LAB_0040f204;
        iVar1 = is_target_debug_ap(0xffffffff);
        if (iVar1 == 0) {
          uVar4 = 0xffffffff;
          goto LAB_0040f204;
        }
        pcVar6 = "[WPORTAL_DBG]%s()/%d uac_wservice_get_entry_by_id fail\n\n";
        uVar4 = 0x21e2;
      }
    }
    else {
      uVar4 = 0xffffffff;
      if (wportal_debug_switch == 0) goto LAB_0040f204;
      iVar1 = is_target_debug_ap(0xffffffff);
      if (iVar1 == 0) {
        uVar4 = 0xffffffff;
        goto LAB_0040f204;
      }
      pcVar6 = "[WPORTAL_DBG]%s()/%d Get wsta entry fail\n\n";
      uVar4 = 0x21ca;
    }
  }
  printf(pcVar6,"_wportal_get_ssid_page",uVar4);
  uVar4 = 0xffffffff;
LAB_0040f204:
  uVar4 = json_object_new_int(uVar4);
  json_object_object_add(param_2,&DAT_00676a24,uVar4);
  return 0;
}

