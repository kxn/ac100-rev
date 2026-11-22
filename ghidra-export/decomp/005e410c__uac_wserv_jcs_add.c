// func _uac_wserv_jcs_add @ 005e410c size=8536

void _uac_wserv_jcs_add(undefined4 param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  undefined4 *__src;
  size_t __n;
  undefined8 uVar9;
  undefined4 local_308;
  uint local_304;
  undefined4 local_300;
  undefined4 local_2fc;
  undefined4 local_2f8;
  char acStack_2f4 [64];
  undefined1 local_2b4;
  undefined4 local_2b0;
  undefined4 local_2ac;
  undefined4 local_2a8;
  char acStack_2a4 [39];
  undefined1 local_27d;
  undefined4 local_27c;
  undefined4 local_278;
  char acStack_274 [64];
  undefined1 local_234;
  char acStack_230 [127];
  undefined1 local_1b1;
  undefined4 local_1b0;
  char acStack_1ac [150];
  undefined1 local_116;
  uint local_115;
  undefined1 local_111 [4];
  byte local_10d;
  undefined4 local_10c;
  uint local_108;
  undefined4 local_104;
  char acStack_100 [49];
  undefined1 local_cf;
  uint local_ce;
  uint local_ca;
  int local_c6;
  undefined1 auStack_c2 [128];
  undefined4 local_42;
  undefined4 local_3e;
  undefined1 local_3a;
  undefined1 local_39;
  undefined1 local_36;
  undefined1 local_35;
  undefined2 local_34;
  undefined2 local_32;
  undefined2 local_30;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  
  local_304 = 0;
  local_308 = 0;
  if ((g_wserv_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_jcs_add() begin.\r\n","_uac_wserv_jcs_add",0x98f);
  }
  iVar3 = apmngr_db_get_ap_max();
  uVar4 = apmngr_db_get_ap_max();
  iVar3 = FUN_004082a0((iVar3 >> 5) + (uint)((uVar4 & 0x1f) != 0),4,0x991);
  if (iVar3 == 0) {
    iVar5 = -1;
    if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("<wserv>[error]%s(): %d  -> wserv_calloc() fail\r\n","_uac_wserv_jcs_add",0x994);
    }
    goto LAB_005e4ae8;
  }
  memset(acStack_230,0,0x205);
  local_1b0 = 0xffffffff;
  iVar5 = json_object_object_get(param_1,"enable");
  if (iVar5 == 0) {
    iVar5 = -1;
    if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0x99c,"enable");
    }
    goto LAB_005e4ae8;
  }
  iVar6 = json_object_get_type(iVar5);
  if (iVar6 == 6) {
    pcVar8 = (char *)json_object_get_string(iVar5);
  }
  else {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_uac_wserv_jcs_add",0x99d);
    }
    pcVar8 = "";
  }
  strncpy((char *)&local_304,pcVar8,3);
  local_304 = local_304 & 0xffffff00;
  iVar5 = strcmp((char *)&local_304,"on");
  local_115 = (uint)(iVar5 == 0);
  iVar5 = json_object_object_get(param_1,"auto_bind");
  if (iVar5 == 0) {
    iVar5 = -1;
    if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0x9a8,"auto_bind");
    }
    goto LAB_005e4ae8;
  }
  iVar6 = json_object_get_type(iVar5);
  if (iVar6 == 6) {
    pcVar8 = (char *)json_object_get_string(iVar5);
  }
  else {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_uac_wserv_jcs_add",0x9a9);
    }
    pcVar8 = "";
  }
  strncpy((char *)&local_304,pcVar8,3);
  local_304 = local_304 & 0xffffff00;
  iVar5 = strncmp((char *)&local_304,"on",4);
  if (iVar5 == 0) {
    local_111 = (undefined1  [4])0x1;
  }
  else {
    uVar4 = (uint)local_111 & 3;
    puVar2 = (uint *)(local_111 + -uVar4);
    *puVar2 = *puVar2 & -1 << (4 - uVar4) * 8 | 0U >> uVar4 * 8;
    puVar1 = local_111 + 3;
    uVar4 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar4) =
         *(uint *)(puVar1 + -uVar4) & 0xffffffffU >> (uVar4 + 1) * 8 | 0 << (3 - uVar4) * 8;
  }
  if (local_111 == (undefined1  [4])0x0) {
    local_10d = 0;
    local_10c = local_10c & 0xff | 0x7f7f00;
  }
  else {
    iVar5 = json_object_object_get(param_1,"default_bind_vlan");
    if (iVar5 == 0) {
      iVar5 = -1;
      if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0x9b7,
               "default_bind_vlan");
      }
      goto LAB_005e4ae8;
    }
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      uVar4 = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 == 2) {
        uVar9 = json_object_get_double(iVar5);
        uVar4 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
      else {
        uVar4 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_wserv_jcs_add",0x9b8);
        }
      }
    }
    local_10d = (byte)((uVar4 & 0xffff) >> 8);
    local_10c = local_10c & 0xffffff | (uVar4 & 0xffff) << 0x18;
    iVar5 = json_object_object_get(param_1,"default_bind_freq");
    if (iVar5 == 0) {
      iVar5 = -1;
      if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0x9bc,
               "default_bind_freq");
      }
      goto LAB_005e4ae8;
    }
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      uVar4 = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 != 2) {
        if (jcs_err_switch == 0) {
          local_10c = local_10c & 0xff0000ff | 0xffff00;
        }
        else {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_wserv_jcs_add",0x9bd);
          local_10c = local_10c & 0xff0000ff | 0xffff00;
        }
        goto LAB_005e42bc;
      }
      uVar9 = json_object_get_double(iVar5);
      uVar4 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
    local_10c = local_10c & 0xff0000ff | (uVar4 & 0xffff) << 8;
  }
LAB_005e42bc:
  iVar5 = json_object_object_get(param_1,"ssid_id");
  if (iVar5 != 0) {
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 6) {
      pcVar8 = (char *)json_object_get_string(iVar5);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_wserv_jcs_add",0x9c9);
      }
      pcVar8 = "";
    }
    strncpy(acStack_230,pcVar8,0x7f);
    local_1b1 = 0;
  }
  iVar5 = json_object_object_get(param_1,"ssid");
  if (iVar5 == 0) {
    iVar5 = -1;
    if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0x9cd,"ssid");
    }
    goto LAB_005e4ae8;
  }
  iVar6 = json_object_get_type(iVar5);
  if (iVar6 == 6) {
    pcVar8 = (char *)json_object_get_string(iVar5);
  }
  else {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_uac_wserv_jcs_add",0x9ce);
    }
    pcVar8 = "";
  }
  strncpy(acStack_100,pcVar8,0x31);
  local_cf = 0;
  iVar5 = json_object_object_get(param_1,"ssid_code_type");
  if (iVar5 == 0) {
    iVar5 = -1;
    if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0x9d1,
             "ssid_code_type");
    }
    goto LAB_005e4ae8;
  }
  iVar6 = json_object_get_type(iVar5);
  if (iVar6 == 3) {
    local_104 = json_object_get_int(iVar5);
  }
  else {
    iVar6 = json_object_get_type();
    if (iVar6 == 2) {
      uVar9 = json_object_get_double(iVar5);
      local_104 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_uac_wserv_jcs_add",0x9d2);
      }
      local_104 = 0xffffffff;
    }
  }
  iVar5 = json_object_object_get(param_1,&DAT_006ce874);
  if (iVar5 == 0) {
    iVar5 = -1;
    if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0x9d5,&DAT_006ce874
            );
    }
    goto LAB_005e4ae8;
  }
  iVar6 = json_object_get_type(iVar5);
  if (iVar6 == 6) {
    pcVar8 = (char *)json_object_get_string(iVar5);
  }
  else {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_uac_wserv_jcs_add",0x9d6);
    }
    pcVar8 = "";
  }
  strncpy(acStack_1ac,pcVar8,0x96);
  local_116 = 0;
  iVar5 = json_object_object_get(param_1,"isolate");
  if (iVar5 == 0) {
    iVar5 = -1;
    if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0x9d9,"isolate");
    }
    goto LAB_005e4ae8;
  }
  iVar6 = json_object_get_type(iVar5);
  if (iVar6 == 1) {
    local_ce = json_object_get_boolean(iVar5);
  }
  else {
    iVar6 = json_object_get_type();
    if (iVar6 == 3) {
      iVar5 = json_object_get_int(iVar5);
      local_ce = (uint)(iVar5 != 0);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get boolean with error obj or value type is unmatch.\n",
               "_uac_wserv_jcs_add",0x9da);
      }
      local_ce = 0;
    }
  }
  iVar5 = json_object_object_get(param_1,&DAT_006a6fbc);
  if (iVar5 == 0) {
    iVar5 = -1;
    if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0x9dd,&DAT_006a6fbc
            );
    }
    goto LAB_005e4ae8;
  }
  iVar6 = json_object_get_type(iVar5);
  if (iVar6 == 1) {
    local_ca = json_object_get_boolean(iVar5);
  }
  else {
    iVar6 = json_object_get_type();
    if (iVar6 == 3) {
      iVar5 = json_object_get_int(iVar5);
      local_ca = (uint)(iVar5 != 0);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get boolean with error obj or value type is unmatch.\n",
               "_uac_wserv_jcs_add",0x9de);
      }
      local_ca = 0;
    }
  }
  iVar5 = json_object_object_get(param_1,"encryption");
  if (iVar5 == 0) {
    iVar5 = -1;
    if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0x9e1,"encryption")
      ;
    }
    goto LAB_005e4ae8;
  }
  iVar6 = json_object_get_type(iVar5);
  if (iVar6 == 3) {
    local_c6 = json_object_get_int(iVar5);
  }
  else {
    iVar6 = json_object_get_type();
    if (iVar6 == 2) {
      uVar9 = json_object_get_double(iVar5);
      local_c6 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_uac_wserv_jcs_add",0x9e2);
      }
      local_c6 = -1;
    }
  }
  if (local_c6 == 2) {
    iVar5 = json_object_object_get(param_1,"auth");
    if (iVar5 == 0) {
      iVar5 = -1;
      if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0x9ff,"auth");
      }
      goto LAB_005e4ae8;
    }
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      local_2b0 = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 == 2) {
        uVar9 = json_object_get_double(iVar5);
        local_2b0 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_wserv_jcs_add",0xa00);
        }
        local_2b0 = 0xffffffff;
      }
    }
    iVar5 = json_object_object_get(param_1,"cipher");
    if (iVar5 == 0) {
      iVar5 = -1;
      if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0xa03,"cipher");
      }
      goto LAB_005e4ae8;
    }
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      local_2ac = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 == 2) {
        uVar9 = json_object_get_double(iVar5);
        local_2ac = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_wserv_jcs_add",0xa04);
        }
        local_2ac = 0xffffffff;
      }
    }
    iVar5 = json_object_object_get(param_1,"key_update_intv");
    if (iVar5 == 0) {
      iVar5 = -1;
      if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0xa07,
               "key_update_intv");
      }
      goto LAB_005e4ae8;
    }
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      local_2a8 = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 == 2) {
        uVar9 = json_object_get_double(iVar5);
        local_2a8 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_wserv_jcs_add",0xa08);
        }
        local_2a8 = 0xffffffff;
      }
    }
    iVar5 = json_object_object_get(param_1,"radius_ip");
    if (iVar5 == 0) {
      iVar5 = -1;
      if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0xa0b,"radius_ip"
              );
      }
      goto LAB_005e4ae8;
    }
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 6) {
      pcVar8 = (char *)json_object_get_string(iVar5);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_wserv_jcs_add",0xa0c);
      }
      pcVar8 = "";
    }
    strncpy(acStack_2a4,pcVar8,0x27);
    local_27d = 0;
    iVar5 = json_object_object_get(param_1,"radius_port");
    if (iVar5 == 0) {
      iVar5 = -1;
      if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0xa0f,
               "radius_port");
      }
      goto LAB_005e4ae8;
    }
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      local_27c = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 == 2) {
        uVar9 = json_object_get_double(iVar5);
        local_27c = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_wserv_jcs_add",0xa10);
        }
        local_27c = 0xffffffff;
      }
    }
    iVar5 = json_object_object_get(param_1,"radius_acct_port");
    if (iVar5 == 0) {
      iVar5 = -1;
      if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0xa13,
               "radius_acct_port");
      }
      goto LAB_005e4ae8;
    }
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      local_278 = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 == 2) {
        uVar9 = json_object_get_double(iVar5);
        local_278 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_wserv_jcs_add",0xa14);
        }
        local_278 = 0xffffffff;
      }
    }
    iVar5 = json_object_object_get(param_1,"radius_pwd");
    if (iVar5 == 0) {
      iVar5 = -1;
      if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0xa17,
               "radius_pwd");
      }
      goto LAB_005e4ae8;
    }
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 6) {
      pcVar8 = (char *)json_object_get_string(iVar5);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_wserv_jcs_add",0xa18);
      }
      pcVar8 = "";
    }
    strncpy(acStack_274,pcVar8,0x40);
    local_234 = 0;
    __src = &local_2b0;
    __n = 0x80;
LAB_005e4ff4:
    memcpy(auStack_c2,__src,__n);
  }
  else if ((local_c6 == 4) || (local_c6 == 1)) {
    iVar5 = json_object_object_get(param_1,"auth");
    if (iVar5 == 0) {
      iVar5 = -1;
      if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0x9ec,"auth");
      }
      goto LAB_005e4ae8;
    }
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      local_300 = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 == 2) {
        uVar9 = json_object_get_double(iVar5);
        local_300 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_wserv_jcs_add",0x9ed);
        }
        local_300 = 0xffffffff;
      }
    }
    iVar5 = json_object_object_get(param_1,"cipher");
    if (iVar5 == 0) {
      iVar5 = -1;
      if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0x9f0,"cipher");
      }
      goto LAB_005e4ae8;
    }
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      local_2fc = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 == 2) {
        uVar9 = json_object_get_double(iVar5);
        local_2fc = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_wserv_jcs_add",0x9f1);
        }
        local_2fc = 0xffffffff;
      }
    }
    iVar5 = json_object_object_get(param_1,"key_update_intv");
    if (iVar5 == 0) {
      iVar5 = -1;
      if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0x9f4,
               "key_update_intv");
      }
      goto LAB_005e4ae8;
    }
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      local_2f8 = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 == 2) {
        uVar9 = json_object_get_double(iVar5);
        local_2f8 = __fixdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_wserv_jcs_add",0x9f5);
        }
        local_2f8 = 0xffffffff;
      }
    }
    iVar5 = json_object_object_get(param_1,"key");
    if (iVar5 == 0) {
      iVar5 = -1;
      if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0x9f8,"key");
      }
      goto LAB_005e4ae8;
    }
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 6) {
      pcVar8 = (char *)json_object_get_string(iVar5);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_wserv_jcs_add",0x9f9);
      }
      pcVar8 = "";
    }
    strncpy(acStack_2f4,pcVar8,0x40);
    __src = &local_300;
    local_2b4 = 0;
    __n = 0x50;
    goto LAB_005e4ff4;
  }
  iVar5 = json_object_object_get(param_1,"bw_ctrl_enable");
  if (iVar5 == 0) {
    iVar5 = -1;
    if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
      printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0xa21,
             "bw_ctrl_enable");
    }
  }
  else {
    iVar6 = json_object_get_type(iVar5);
    if (iVar6 == 3) {
      local_3a = json_object_get_int(iVar5);
    }
    else {
      iVar6 = json_object_get_type();
      if (iVar6 == 2) {
        uVar9 = json_object_get_double(iVar5);
        local_3a = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_wserv_jcs_add",0xa22);
        }
        local_3a = 0xff;
      }
    }
    iVar5 = json_object_object_get(param_1,"bw_ctrl_mode");
    if (iVar5 == 0) {
      iVar5 = -1;
      if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
        printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0xa25,
               "bw_ctrl_mode");
      }
    }
    else {
      iVar6 = json_object_get_type(iVar5);
      if (iVar6 == 3) {
        local_39 = json_object_get_int(iVar5);
      }
      else {
        iVar6 = json_object_get_type();
        if (iVar6 == 2) {
          uVar9 = json_object_get_double(iVar5);
          local_39 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_uac_wserv_jcs_add",0xa26);
          }
          local_39 = 0xff;
        }
      }
      iVar5 = json_object_object_get(param_1,"igmp_snooping_enable");
      if (iVar5 == 0) {
        iVar5 = -1;
        if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
          printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0xa29,
                 "igmp_snooping_enable");
        }
      }
      else {
        iVar6 = json_object_get_type(iVar5);
        if (iVar6 == 6) {
          pcVar8 = (char *)json_object_get_string(iVar5);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_uac_wserv_jcs_add",0xa2a);
          }
          pcVar8 = "";
        }
        strncpy((char *)&local_304,pcVar8,3);
        local_304 = local_304 & 0xffffff00;
        iVar5 = strcmp((char *)&local_304,"on");
        local_36 = iVar5 == 0;
        iVar5 = json_object_object_get(param_1,"igmp_drop_unknown");
        if (iVar5 == 0) {
          iVar5 = -1;
          if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
            printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0xa35,
                   "igmp_drop_unknown");
          }
        }
        else {
          iVar6 = json_object_get_type(iVar5);
          if (iVar6 == 3) {
            local_35 = json_object_get_int(iVar5);
          }
          else {
            iVar6 = json_object_get_type();
            if (iVar6 == 2) {
              uVar9 = json_object_get_double(iVar5);
              local_35 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"_uac_wserv_jcs_add",0xa36);
              }
              local_35 = 0xff;
            }
          }
          iVar5 = json_object_object_get(param_1,"igmp_2g_rate");
          if (iVar5 == 0) {
            iVar5 = -1;
            if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
              printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0xa39,
                     "igmp_2g_rate");
            }
          }
          else {
            iVar6 = json_object_get_type(iVar5);
            if (iVar6 == 3) {
              local_34 = json_object_get_int(iVar5);
            }
            else {
              iVar6 = json_object_get_type();
              if (iVar6 == 2) {
                uVar9 = json_object_get_double(iVar5);
                local_34 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
              }
              else {
                if (jcs_err_switch != 0) {
                  printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                         ,"_uac_wserv_jcs_add",0xa3a);
                }
                local_34 = 0xffff;
              }
            }
            iVar5 = json_object_object_get(param_1,"igmp_5g_rate");
            if (iVar5 == 0) {
              iVar5 = -1;
              if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0xa3d,
                       "igmp_5g_rate");
              }
            }
            else {
              iVar6 = json_object_get_type(iVar5);
              if (iVar6 == 3) {
                local_32 = json_object_get_int(iVar5);
              }
              else {
                iVar6 = json_object_get_type();
                if (iVar6 == 2) {
                  uVar9 = json_object_get_double(iVar5);
                  local_32 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
                }
                else {
                  if (jcs_err_switch != 0) {
                    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                           ,"_uac_wserv_jcs_add",0xa3e);
                  }
                  local_32 = 0xffff;
                }
              }
              iVar5 = json_object_object_get(param_1,"igmp_query_interval");
              if (iVar5 == 0) {
                iVar5 = -1;
                if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                  printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0xa41,
                         "igmp_query_interval");
                }
              }
              else {
                iVar6 = json_object_get_type(iVar5);
                if (iVar6 == 3) {
                  local_30 = json_object_get_int(iVar5);
                }
                else {
                  iVar6 = json_object_get_type();
                  if (iVar6 == 2) {
                    uVar9 = json_object_get_double(iVar5);
                    local_30 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
                  }
                  else {
                    if (jcs_err_switch != 0) {
                      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                             ,"_uac_wserv_jcs_add",0xa42);
                    }
                    local_30 = 0xffff;
                  }
                }
                iVar5 = json_object_object_get(param_1,"igmp_max_resp_time");
                if (iVar5 == 0) {
                  iVar5 = -1;
                  if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                    printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",0xa45
                           ,"igmp_max_resp_time");
                  }
                }
                else {
                  iVar6 = json_object_get_type(iVar5);
                  if (iVar6 == 3) {
                    local_2e = json_object_get_int(iVar5);
                  }
                  else {
                    iVar6 = json_object_get_type();
                    if (iVar6 == 2) {
                      uVar9 = json_object_get_double(iVar5);
                      local_2e = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
                    }
                    else {
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                               ,"_uac_wserv_jcs_add",0xa46);
                      }
                      local_2e = 0xff;
                    }
                  }
                  iVar5 = json_object_object_get(param_1,"igmp_snooping_switch");
                  if (iVar5 == 0) {
                    iVar5 = -1;
                    if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                      printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",
                             0xa49,"igmp_snooping_switch");
                    }
                  }
                  else {
                    iVar6 = json_object_get_type(iVar5);
                    if (iVar6 == 6) {
                      pcVar8 = (char *)json_object_get_string(iVar5);
                    }
                    else {
                      if (jcs_err_switch != 0) {
                        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                               ,"_uac_wserv_jcs_add",0xa4a);
                      }
                      pcVar8 = "";
                    }
                    strncpy((char *)&local_304,pcVar8,3);
                    local_304 = local_304 & 0xffffff00;
                    iVar5 = strcmp((char *)&local_304,"on");
                    local_2d = iVar5 == 0;
                    iVar5 = json_object_object_get(param_1,"igmp_query_switch");
                    if (iVar5 == 0) {
                      iVar5 = -1;
                      if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                        printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add",
                               0xa55,"igmp_query_switch");
                      }
                    }
                    else {
                      iVar6 = json_object_get_type(iVar5);
                      if (iVar6 == 6) {
                        pcVar8 = (char *)json_object_get_string(iVar5);
                      }
                      else {
                        if (jcs_err_switch != 0) {
                          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                                 ,"_uac_wserv_jcs_add",0xa56);
                        }
                        pcVar8 = "";
                      }
                      strncpy((char *)&local_304,pcVar8,3);
                      local_304 = local_304 & 0xffffff00;
                      iVar5 = strcmp((char *)&local_304,"on");
                      local_2c = iVar5 == 0;
                      local_10c = CONCAT31(local_10c._0_3_,1);
                      iVar5 = json_object_object_get(param_1,"up_limit");
                      if (iVar5 == 0) {
                        iVar5 = -1;
                        if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                          printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_jcs_add"
                                 ,0xa62,"up_limit");
                        }
                      }
                      else {
                        iVar6 = json_object_get_type(iVar5);
                        if (iVar6 == 3) {
                          local_42 = json_object_get_int(iVar5);
                        }
                        else {
                          iVar6 = json_object_get_type();
                          if (iVar6 == 2) {
                            uVar9 = json_object_get_double(iVar5);
                            local_42 = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
                          }
                          else {
                            if (jcs_err_switch != 0) {
                              printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                     ,"_uac_wserv_jcs_add",0xa63);
                            }
                            local_42 = 0xffffffff;
                          }
                        }
                        iVar5 = json_object_object_get(param_1,"down_limit");
                        if (iVar5 == 0) {
                          iVar5 = -1;
                          if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
                            printf("<wserv>[error]%s(): %d  -> %s not found!\r\n",
                                   "_uac_wserv_jcs_add",0xa66,"down_limit");
                          }
                        }
                        else {
                          iVar6 = json_object_get_type(iVar5);
                          if (iVar6 == 3) {
                            local_3e = json_object_get_int(iVar5);
                          }
                          else {
                            iVar6 = json_object_get_type();
                            if (iVar6 == 2) {
                              uVar9 = json_object_get_double(iVar5);
                              local_3e = __fixunsdfsi((int)((ulonglong)uVar9 >> 0x20),(int)uVar9);
                            }
                            else {
                              if (jcs_err_switch != 0) {
                                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                                       ,"_uac_wserv_jcs_add",0xa67);
                              }
                              local_3e = 0xffffffff;
                            }
                          }
                          iVar5 = json_object_object_get(param_1,"mlo_switch");
                          if (iVar5 == 0) {
                            iVar5 = -1;
                            if ((g_wserv_error != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0))
                            {
                              printf("<wserv>[error]%s(): %d  -> %s not found!\r\n",
                                     "_uac_wserv_jcs_add",0xa6b,"mlo_switch");
                            }
                          }
                          else {
                            iVar6 = json_object_get_type(iVar5);
                            if (iVar6 == 1) {
                              local_108 = json_object_get_boolean(iVar5);
                            }
                            else {
                              iVar6 = json_object_get_type();
                              if (iVar6 == 3) {
                                iVar5 = json_object_get_int(iVar5);
                                local_108 = (uint)(iVar5 != 0);
                              }
                              else if (jcs_err_switch == 0) {
                                local_108 = 0;
                              }
                              else {
                                printf("[JCS_ERR]%s()/%d Warning: Get boolean with error obj or value type is unmatch.\n"
                                       ,"_uac_wserv_jcs_add",0xa6c);
                                local_108 = 0;
                              }
                            }
                            iVar5 = wserv_db_entry_add(acStack_230);
                            if ((g_wserv_debug != 0) && (iVar6 = is_target_debug_ap(1), iVar6 != 0))
                            {
                              printf("<wserv>[debug]%s(): %d  -> wserv_db_entry_add() wserv_id=%d.\r\n"
                                     ,"_uac_wserv_jcs_add",0xa70,iVar5);
                            }
                            uac_wservice_callback_proc(1,acStack_230);
                            if ((iVar5 != -1) && (local_111 != (undefined1  [4])0x0)) {
                              uac_wservice_refresh_bind_list
                                        (local_1b0,local_10c >> 0x18 | (uint)local_10d << 8,
                                         (local_10c << 8) >> 0x10,iVar3,&local_308);
                              uVar7 = local_1b0;
                              iVar6 = apmngr_db_get_ap_max();
                              uVar4 = apmngr_db_get_ap_max();
                              iVar6 = wserv_db_entry_get_binded_ap_id_bm
                                                (uVar7,iVar3,
                                                 (iVar6 >> 5) + (uint)((uVar4 & 0x1f) != 0),
                                                 &local_308);
                              if ((iVar6 != 0) &&
                                 ((g_wserv_error != 0 && (iVar6 = is_target_debug_ap(), iVar6 != 0))
                                 )) {
                                printf("<wserv>[error]%s(): %d  -> wserv_db_entry_get_binded_ap_id_bm() fail. wserv_id[%d]\r\n"
                                       ,"_uac_wserv_jcs_add",0xa7b,local_1b0);
                              }
                              _uac_wserv_update_aps_md5(iVar3,local_308);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_005e4ae8:
  uVar7 = json_object_new_int(iVar5);
  json_object_object_add(param_2,"serv_id",uVar7);
  if ((g_wserv_debug != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_jcs_add() finish, wserv_id=%d.\r\n",
           "_uac_wserv_jcs_add",0xa84,iVar5);
  }
  if (iVar3 != 0) {
    FUN_00407df0(iVar3);
  }
  return;
}

