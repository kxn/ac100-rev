// func _wportal_free_strategy_add @ 00412a48 size=4772

int _wportal_free_strategy_add(undefined4 param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined1 *puVar15;
  size_t sVar16;
  undefined4 *puVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  char cVar24;
  char *pcVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined1 *puVar29;
  undefined1 *puVar30;
  undefined1 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined8 uVar34;
  undefined4 local_3c8;
  undefined2 local_3c4;
  char local_3c0 [16];
  ushort local_3b0;
  undefined4 local_3ac;
  undefined4 local_3a8;
  undefined4 local_3a4;
  undefined4 local_3a0;
  undefined4 local_39c;
  undefined4 local_398;
  undefined4 local_394;
  undefined4 local_390;
  undefined4 local_38c;
  undefined4 local_388;
  undefined4 local_384;
  undefined4 local_380;
  undefined4 local_37c;
  undefined4 local_378;
  undefined4 local_374;
  undefined4 local_370;
  uint local_36c [4];
  undefined4 local_35c;
  uint local_358 [4];
  char acStack_348 [39];
  undefined1 local_321;
  undefined4 local_320;
  undefined1 auStack_31c [4];
  undefined1 auStack_318 [4];
  undefined1 auStack_314 [4];
  undefined1 auStack_310 [4];
  undefined1 auStack_30c [44];
  undefined1 auStack_2e0 [64];
  char acStack_2a0 [127];
  undefined1 local_221;
  char acStack_220 [150];
  undefined1 local_18a;
  undefined1 auStack_188 [152];
  undefined4 local_f0;
  undefined4 local_ec;
  undefined1 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  int local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined2 local_c8;
  undefined1 auStack_c6 [18];
  int local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  memset(acStack_220,0,0x97);
  memset(acStack_2a0,0,0x80);
  memset(acStack_348,0,0x28);
  local_35c = 0;
  local_358[0] = 0;
  local_358[1] = 0;
  local_358[2] = 0;
  local_358[3] = 0;
  local_3c0[0] = '\0';
  local_3c0[1] = '\0';
  local_3c0[2] = '\0';
  local_3c0[3] = '\0';
  local_3c0[4] = '\0';
  local_3c0[5] = '\0';
  local_3c0[6] = '\0';
  local_3c0[7] = '\0';
  local_3c0[8] = '\0';
  local_3c0[9] = '\0';
  local_3c0[10] = '\0';
  local_3c0[0xb] = '\0';
  local_3c0[0xc] = '\0';
  local_3c0[0xd] = '\0';
  local_3c0[0xe] = '\0';
  local_3c0[0xf] = '\0';
  local_3b0 = 0;
  local_3c8 = 0;
  local_3c4 = 0;
  local_370 = 0;
  local_36c[0] = 0;
  local_36c[1] = 0;
  local_36c[2] = 0;
  local_36c[3] = 0;
  iVar10 = json_object_object_get(param_1,"name");
  if ((iVar10 == 0) || (iVar11 = json_object_get_type(iVar10), iVar11 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_free_strategy_add",0x13fd);
    }
    pcVar25 = "";
  }
  else {
    pcVar25 = (char *)json_object_get_string(iVar10);
  }
  strncpy(acStack_220,pcVar25,0x96);
  local_18a = 0;
  iVar10 = json_object_object_get(param_1,"id");
  if (iVar10 == 0) {
LAB_00412b80:
    local_30 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_free_strategy_add",0x1400);
    }
  }
  else {
    iVar11 = json_object_get_type(iVar10);
    if (iVar11 == 3) {
      local_30 = json_object_get_int(iVar10);
    }
    else {
      iVar11 = json_object_get_type();
      if (iVar11 != 2) goto LAB_00412b80;
      uVar34 = json_object_get_double(iVar10);
      local_30 = __fixdfsi((int)((ulonglong)uVar34 >> 0x20),(int)uVar34);
    }
  }
  iVar10 = json_object_object_get(param_1,"match_type");
  if (iVar10 == 0) {
LAB_00412bd4:
    iVar10 = -1;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_free_strategy_add",0x1403);
    }
  }
  else {
    iVar11 = json_object_get_type(iVar10);
    if (iVar11 == 3) {
      iVar10 = json_object_get_int(iVar10);
    }
    else {
      iVar11 = json_object_get_type();
      if (iVar11 != 2) goto LAB_00412bd4;
      uVar34 = json_object_get_double(iVar10);
      iVar10 = __fixdfsi((int)((ulonglong)uVar34 >> 0x20),(int)uVar34);
    }
  }
  iVar11 = json_object_object_get(param_1,&DAT_00677c20);
  if ((iVar11 == 0) || (iVar12 = json_object_get_type(iVar11), iVar12 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_free_strategy_add",0x1406);
    }
    pcVar25 = "";
  }
  else {
    pcVar25 = (char *)json_object_get_string(iVar11);
  }
  strncpy(acStack_348,pcVar25,0x27);
  local_321 = 0;
  iVar11 = strcmp(acStack_348,"null");
  iVar12 = 0;
  if (iVar11 != 0) {
    FUN_0051a7a8(acStack_348,&local_35c);
    iVar11 = json_object_object_get(param_1,"src_ip_mask");
    if (iVar11 == 0) {
LAB_004132b0:
      iVar12 = -1;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_free_strategy_add",0x140d);
      }
    }
    else {
      iVar12 = json_object_get_type(iVar11);
      if (iVar12 == 3) {
        iVar12 = json_object_get_int(iVar11);
      }
      else {
        iVar12 = json_object_get_type();
        if (iVar12 != 2) goto LAB_004132b0;
        uVar34 = json_object_get_double(iVar11);
        iVar12 = __fixdfsi((int)((ulonglong)uVar34 >> 0x20),(int)uVar34);
      }
    }
  }
  iVar11 = json_object_object_get(param_1,"src_mac");
  if ((iVar11 == 0) || (iVar13 = json_object_get_type(iVar11), iVar13 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_free_strategy_add",0x1411);
    }
    pcVar25 = "";
  }
  else {
    pcVar25 = (char *)json_object_get_string(iVar11);
  }
  strncpy(local_3c0,pcVar25,0x11);
  local_3b0 = local_3b0 & 0xff00;
  if (local_3c0[0] != '\0') {
    sscanf(local_3c0,"%2X-%2X-%2X-%2X-%2X-%2X",&local_320,auStack_31c,auStack_318,auStack_314,
           auStack_310,auStack_30c);
    puVar17 = &local_320;
    iVar11 = 0;
    do {
      puVar15 = (undefined1 *)((int)&local_3c8 + iVar11);
      uVar33 = *puVar17;
      iVar11 = iVar11 + 1;
      puVar17 = puVar17 + 1;
      *puVar15 = (char)uVar33;
    } while (iVar11 != 6);
  }
  uVar33 = 0;
  if (g_portal_auth_mode == 1) {
    iVar11 = json_object_object_get(param_1,"src_vlan");
    if (iVar11 == 0) {
LAB_0041353c:
      uVar33 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_free_strategy_add",0x1422);
      }
    }
    else {
      iVar13 = json_object_get_type(iVar11);
      if (iVar13 == 3) {
        uVar33 = json_object_get_int(iVar11);
      }
      else {
        iVar13 = json_object_get_type();
        if (iVar13 != 2) goto LAB_0041353c;
        uVar34 = json_object_get_double(iVar11);
        uVar33 = __fixdfsi((int)((ulonglong)uVar34 >> 0x20),(int)uVar34);
      }
    }
  }
  if (iVar10 == 0) {
    iVar11 = json_object_object_get(param_1,"src_port_start");
    if (iVar11 == 0) {
LAB_00412d08:
      local_40 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_free_strategy_add",0x1428);
      }
    }
    else {
      iVar13 = json_object_get_type(iVar11);
      if (iVar13 == 3) {
        local_40 = json_object_get_int(iVar11);
      }
      else {
        iVar13 = json_object_get_type();
        if (iVar13 != 2) goto LAB_00412d08;
        uVar34 = json_object_get_double(iVar11);
        local_40 = __fixdfsi((int)((ulonglong)uVar34 >> 0x20),(int)uVar34);
      }
    }
    iVar11 = json_object_object_get(param_1,"src_port_end");
    if (iVar11 == 0) {
LAB_00412d5c:
      local_3c = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_free_strategy_add",0x142b);
      }
    }
    else {
      iVar13 = json_object_get_type(iVar11);
      if (iVar13 == 3) {
        local_3c = json_object_get_int(iVar11);
      }
      else {
        iVar13 = json_object_get_type();
        if (iVar13 != 2) goto LAB_00412d5c;
        uVar34 = json_object_get_double(iVar11);
        local_3c = __fixdfsi((int)((ulonglong)uVar34 >> 0x20),(int)uVar34);
      }
    }
    iVar11 = json_object_object_get(param_1,"dst_port_start");
    if (iVar11 == 0) {
LAB_00412db0:
      local_38 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_free_strategy_add",0x142e);
      }
    }
    else {
      iVar13 = json_object_get_type(iVar11);
      if (iVar13 == 3) {
        local_38 = json_object_get_int(iVar11);
      }
      else {
        iVar13 = json_object_get_type();
        if (iVar13 != 2) goto LAB_00412db0;
        uVar34 = json_object_get_double(iVar11);
        local_38 = __fixdfsi((int)((ulonglong)uVar34 >> 0x20),(int)uVar34);
      }
    }
    iVar11 = json_object_object_get(param_1,"dst_port_end");
    if (iVar11 == 0) {
LAB_00412e04:
      local_34 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_free_strategy_add",0x1431);
      }
    }
    else {
      iVar13 = json_object_get_type(iVar11);
      if (iVar13 == 3) {
        local_34 = json_object_get_int(iVar11);
      }
      else {
        iVar13 = json_object_get_type();
        if (iVar13 != 2) goto LAB_00412e04;
        uVar34 = json_object_get_double(iVar11);
        local_34 = __fixdfsi((int)((ulonglong)uVar34 >> 0x20),(int)uVar34);
      }
    }
    iVar11 = json_object_object_get(param_1,"dst_ip");
    if ((iVar11 == 0) || (iVar13 = json_object_get_type(iVar11), iVar13 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_wportal_free_strategy_add",0x1434);
      }
      pcVar25 = "";
    }
    else {
      pcVar25 = (char *)json_object_get_string(iVar11);
    }
    iVar11 = 0;
    strncpy(acStack_348,pcVar25,0x27);
    local_321 = 0;
    iVar13 = strcmp(acStack_348,"null");
    if (iVar13 != 0) {
      FUN_0051a7a8(acStack_348,&local_370);
      iVar11 = json_object_object_get(param_1,"dst_ip_mask");
      if (iVar11 == 0) {
LAB_004134cc:
        iVar11 = -1;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_wportal_free_strategy_add",0x143b);
        }
      }
      else {
        iVar13 = json_object_get_type(iVar11);
        if (iVar13 == 3) {
          iVar11 = json_object_get_int(iVar11);
        }
        else {
          iVar13 = json_object_get_type();
          if (iVar13 != 2) goto LAB_004134cc;
          uVar34 = json_object_get_double(iVar11);
          iVar11 = __fixdfsi((int)((ulonglong)uVar34 >> 0x20),(int)uVar34);
        }
      }
    }
    iVar13 = json_object_object_get(param_1,"protocol");
    if (iVar13 != 0) {
      iVar14 = json_object_get_type(iVar13);
      if (iVar14 == 3) {
        uVar32 = json_object_get_int(iVar13);
      }
      else {
        iVar14 = json_object_get_type();
        if (iVar14 != 2) goto LAB_00412ec4;
        uVar34 = json_object_get_double(iVar13);
        uVar32 = __fixdfsi((int)((ulonglong)uVar34 >> 0x20),(int)uVar34);
      }
      goto LAB_00412f5c;
    }
LAB_00412ec4:
    uVar32 = 0xffffffff;
    if (jcs_err_switch == 0) goto LAB_00412f5c;
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "_wportal_free_strategy_add",0x143f);
  }
  else {
    iVar11 = json_object_object_get(param_1,&DAT_00677ca8);
    if ((iVar11 == 0) || (iVar13 = json_object_get_type(iVar11), iVar13 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_wportal_free_strategy_add",0x1444);
      }
      pcVar25 = "";
    }
    else {
      pcVar25 = (char *)json_object_get_string(iVar11);
    }
    uVar32 = 0;
    iVar11 = 0;
    strncpy(acStack_2a0,pcVar25,0x7f);
    local_221 = 0;
    local_34 = 0;
    local_38 = 0;
    local_3c = 0;
    local_40 = 0;
LAB_00412f5c:
  }
  cVar24 = '\x01';
  if (local_35c._0_1_ == '\x01') {
    cVar24 = '\x02';
LAB_00412f7c:
    if (local_370._0_1_ == cVar24) {
      return -1;
    }
  }
  else if (local_35c._0_1_ == '\x02') goto LAB_00412f7c;
  puVar15 = (undefined1 *)FUN_00408450(0x144,0x144b);
  if (puVar15 == (undefined1 *)0x0) {
    return -1;
  }
  memset(puVar15,0,0x144);
  if (local_35c._0_1_ == '\x02') {
    uVar26 = 2;
LAB_00412fdc:
    *(undefined4 *)(puVar15 + 0x98) = uVar26;
  }
  else if (local_370._0_1_ == '\x02') {
    *(undefined4 *)(puVar15 + 0x98) = 2;
  }
  else if (local_35c._0_1_ == '\x01') {
    *(undefined4 *)(puVar15 + 0x98) = 1;
  }
  else {
    if (local_370._0_1_ != '\x01') {
      uVar26 = 3;
      goto LAB_00412fdc;
    }
    *(undefined4 *)(puVar15 + 0x98) = 1;
  }
  uVar31 = (undefined1)iVar10;
  if ((*(int *)(puVar15 + 0x98) == 1) || (*(int *)(puVar15 + 0x98) == 3)) {
    sVar16 = strlen(acStack_220);
    memcpy(puVar15,acStack_220,sVar16 + 1);
    uVar9 = local_358[0];
    uVar8 = local_36c[0];
    puVar15[0xa0] = uVar31;
    *(undefined4 *)(puVar15 + 0x9c) = local_30;
    if (iVar10 == 0) {
      *(uint *)(puVar15 + 0xa4) = local_358[0];
      if (iVar12 == 0) {
        *(undefined4 *)(puVar15 + 0xa8) = 0;
      }
      else {
        *(int *)(puVar15 + 0xa8) = -1 << (-iVar12 & 0x1fU);
      }
      *(uint *)(puVar15 + 0xb8) = local_36c[0];
      if (iVar11 == 0) {
        *(undefined4 *)(puVar15 + 0xbc) = 0;
      }
      else {
        *(int *)(puVar15 + 0xbc) = -1 << (-iVar11 & 0x1fU);
      }
      memcpy(puVar15 + 0xb0,&local_3c8,6);
      *(undefined4 *)(puVar15 + 200) = local_38;
      *(undefined4 *)(puVar15 + 0xc0) = local_40;
      *(undefined4 *)(puVar15 + 0xac) = uVar33;
      *(undefined4 *)(puVar15 + 0xc4) = local_3c;
      *(undefined4 *)(puVar15 + 0xd0) = uVar32;
      *(undefined4 *)(puVar15 + 0xcc) = local_34;
      *(uint *)(puVar15 + 0xa4) = *(uint *)(puVar15 + 0xa8) & uVar9;
      *(uint *)(puVar15 + 0xb8) = *(uint *)(puVar15 + 0xbc) & uVar8;
      if ((wportal_info_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
      goto LAB_0041302c;
      bVar1 = puVar15[0xa0];
      pcVar25 = 
      "[WPORTAL_INFO]%s()/%d Add ftt tuple entry: %s type: %d src_ip: %x/%x dst_ip: %x/%x mac: %x:%x:%x:%x:%x:%x vlan: %d src_port: %d-%d dst_port: %d-%d protocol: %d\n"
      ;
      puVar30 = *(undefined1 **)(puVar15 + 0xa4);
      uVar27 = 0x14a0;
      uVar26 = *(undefined4 *)(puVar15 + 0xa8);
      puVar17 = *(undefined4 **)(puVar15 + 0xb8);
      uVar23 = *(undefined4 *)(puVar15 + 0xbc);
      bVar2 = puVar15[0xb0];
      bVar3 = puVar15[0xb1];
      bVar4 = puVar15[0xb2];
      bVar5 = puVar15[0xb3];
      bVar6 = puVar15[0xb4];
      bVar7 = puVar15[0xb5];
      uVar28 = *(undefined4 *)(puVar15 + 0xac);
      uVar18 = *(undefined4 *)(puVar15 + 0xc0);
      uVar19 = *(undefined4 *)(puVar15 + 0xc4);
      uVar20 = *(undefined4 *)(puVar15 + 200);
      uVar21 = *(undefined4 *)(puVar15 + 0xcc);
      uVar22 = *(undefined4 *)(puVar15 + 0xd0);
      goto LAB_004137b8;
    }
    if (iVar10 != 1) goto LAB_0041302c;
    *(uint *)(puVar15 + 0xa4) = local_358[0];
    if (iVar12 == 0) {
      *(undefined4 *)(puVar15 + 0xa8) = 0;
    }
    else {
      *(int *)(puVar15 + 0xa8) = -1 << (-iVar12 & 0x1fU);
    }
    puVar30 = puVar15 + 0xb6;
    memcpy(puVar30,acStack_2a0,0x80);
    memcpy(puVar15 + 0xb0,&local_3c8,6);
    *(undefined4 *)(puVar15 + 0xac) = uVar33;
    *(uint *)(puVar15 + 0xa4) = *(uint *)(puVar15 + 0xa8) & uVar9;
    if ((wportal_info_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
    goto LAB_0041302c;
    bVar1 = puVar15[0xa0];
    pcVar25 = 
    "[WPORTAL_INFO]%s()/%d Add ftt url entry: %s type: %d src_ip: %x/%x mac: %x:%x:%x:%x:%x:%x vlan: %d  url: %s\n"
    ;
    puVar17 = *(undefined4 **)(puVar15 + 0xa4);
    uVar28 = 0x14ac;
    uVar26 = *(undefined4 *)(puVar15 + 0xa8);
    bVar2 = puVar15[0xb0];
    bVar3 = puVar15[0xb1];
    bVar4 = puVar15[0xb2];
    bVar5 = puVar15[0xb3];
    bVar6 = puVar15[0xb4];
    bVar7 = puVar15[0xb5];
    uVar23 = *(undefined4 *)(puVar15 + 0xac);
  }
  else {
    sVar16 = strlen(acStack_220);
    memcpy(puVar15,acStack_220,sVar16 + 1);
    puVar15[0xa0] = uVar31;
    *(undefined4 *)(puVar15 + 0x9c) = local_30;
    if (iVar10 == 0) {
      puVar30 = puVar15 + 0xa4;
      puVar29 = puVar15 + 0xc2;
      memcpy(puVar30,local_358,0x10);
      *(int *)(puVar15 + 0xb4) = iVar12;
      memcpy(puVar29,local_36c,0x10);
      *(int *)(puVar15 + 0xd4) = iVar11;
      memcpy(puVar15 + 0xbc,&local_3c8,6);
      *(undefined4 *)(puVar15 + 0xd8) = local_40;
      *(undefined4 *)(puVar15 + 0xdc) = local_3c;
      *(undefined4 *)(puVar15 + 0xe0) = local_38;
      *(undefined4 *)(puVar15 + 0xb8) = uVar33;
      *(undefined4 *)(puVar15 + 0xe8) = uVar32;
      *(undefined4 *)(puVar15 + 0xe4) = local_34;
      FUN_00408480(puVar30,iVar12,puVar30);
      FUN_00408480(puVar29,iVar11,puVar29);
      memset(auStack_2e0,0,0x40);
      memset(&local_320,0,0x40);
      local_384 = 0;
      local_380 = 0;
      local_37c = 0;
      local_378 = 0;
      local_374 = 0;
      local_398 = 0;
      local_394 = 0;
      local_390 = 0;
      local_38c = 0;
      local_388 = 0;
      FUN_00408560(puVar30,2,&local_384);
      FUN_00408560(puVar29,2,&local_398);
      FUN_00408190(local_384,local_380,local_37c,local_378,local_374,auStack_2e0,0x40,"---");
      FUN_00408190(local_398,local_394,local_390,local_38c,local_388,&local_320,0x40,"---");
      if (wportal_info_switch == 0) goto LAB_0041302c;
      iVar13 = is_target_debug_ap();
      puVar30 = auStack_2e0;
      if (iVar13 == 0) goto LAB_0041302c;
      bVar1 = puVar15[0xa0];
      puVar17 = &local_320;
      uVar26 = *(undefined4 *)(puVar15 + 0xb4);
      pcVar25 = 
      "[WPORTAL_INFO]%s()/%d Add ftt tuple entry: %s type: %d src_ip: %s/%x dst_ip: %s/%x mac: %x:%x:%x:%x:%x:%x vlan: %d src_port: %d-%d dst_port: %d-%d protocol: %d\n"
      ;
      uVar27 = 0x14e6;
      uVar23 = *(undefined4 *)(puVar15 + 0xd4);
      bVar2 = puVar15[0xbc];
      bVar3 = puVar15[0xbd];
      bVar4 = puVar15[0xbe];
      bVar5 = puVar15[0xbf];
      bVar6 = puVar15[0xc0];
      bVar7 = puVar15[0xc1];
      uVar28 = *(undefined4 *)(puVar15 + 0xb8);
      uVar18 = *(undefined4 *)(puVar15 + 0xd8);
      uVar19 = *(undefined4 *)(puVar15 + 0xdc);
      uVar20 = *(undefined4 *)(puVar15 + 0xe0);
      uVar21 = *(undefined4 *)(puVar15 + 0xe4);
      uVar22 = *(undefined4 *)(puVar15 + 0xe8);
LAB_004137b8:
      printf(pcVar25,"_wportal_free_strategy_add",uVar27,puVar15,(uint)bVar1,puVar30,uVar26,puVar17,
             uVar23,(uint)bVar2,(uint)bVar3,(uint)bVar4,(uint)bVar5,(uint)bVar6,(uint)bVar7,uVar28,
             uVar18,uVar19,uVar20,uVar21,uVar22);
      goto LAB_0041302c;
    }
    puVar29 = puVar15 + 0xa4;
    if (iVar10 != 1) goto LAB_0041302c;
    memcpy(puVar29,local_358,0x10);
    *(int *)(puVar15 + 0xb4) = iVar12;
    puVar30 = puVar15 + 0xc2;
    sVar16 = strlen(acStack_2a0);
    memcpy(puVar30,acStack_2a0,sVar16 + 1);
    memcpy(puVar15 + 0xbc,&local_3c8,6);
    *(undefined4 *)(puVar15 + 0xb8) = uVar33;
    FUN_00408480(puVar29,iVar12,puVar29);
    memset(&local_320,0,0x40);
    local_3ac = 0;
    local_3a8 = 0;
    local_3a4 = 0;
    local_3a0 = 0;
    local_39c = 0;
    FUN_00408560(puVar29,2,&local_3ac);
    FUN_00408190(local_3ac,local_3a8,local_3a4,local_3a0,local_39c,&local_320,0x40,"---");
    if ((wportal_info_switch == 0) || (iVar13 = is_target_debug_ap(), iVar13 == 0))
    goto LAB_0041302c;
    bVar1 = puVar15[0xa0];
    pcVar25 = 
    "[WPORTAL_INFO]%s()/%d Add ftt url entry: %s type: %d src_ip: %s/%x mac: %x:%x:%x:%x:%x:%x vlan: %d  url: %s\n\n"
    ;
    puVar17 = &local_320;
    uVar28 = 0x14f6;
    uVar26 = *(undefined4 *)(puVar15 + 0xb4);
    bVar2 = puVar15[0xbc];
    bVar3 = puVar15[0xbd];
    bVar4 = puVar15[0xbe];
    bVar5 = puVar15[0xbf];
    bVar6 = puVar15[0xc0];
    bVar7 = puVar15[0xc1];
    uVar23 = *(undefined4 *)(puVar15 + 0xb8);
  }
  printf(pcVar25,"_wportal_free_strategy_add",uVar28,puVar15,(uint)bVar1,puVar17,uVar26,(uint)bVar2,
         (uint)bVar3,(uint)bVar4,(uint)bVar5,(uint)bVar6,(uint)bVar7,uVar23,puVar30);
LAB_0041302c:
  iVar13 = wportal_db_ftt_add(puVar15);
  if (iVar13 == 0) {
    iVar13 = *(int *)(puVar15 + 0x98);
    uVar26 = 6;
    if (iVar13 != 1) {
      if (iVar13 == 2) {
        uVar26 = 0x11;
      }
      else {
        if (iVar13 != 3) {
          return 0;
        }
        *(undefined4 *)(puVar15 + 0x98) = 1;
        _wportal_update_free_strategy_to_ap(puVar15,6);
        *(undefined4 *)(puVar15 + 0x98) = 3;
        memset(auStack_188,0,0x144);
        sVar16 = strlen(acStack_220);
        memcpy(auStack_188,acStack_220,sVar16 + 1);
        local_f0 = 2;
        local_ec = local_30;
        local_e8 = uVar31;
        if (iVar10 == 0) {
          local_e4 = 0;
          local_e0 = 0;
          local_dc = 0;
          local_d8 = 0;
          local_d4 = iVar12;
          memset(auStack_c6,0,0x10);
          local_b0 = local_40;
          local_a8 = local_38;
          local_cc = local_3c8;
          local_a4 = local_34;
          local_c8 = local_3c4;
          local_ac = local_3c;
          local_d0 = uVar33;
          local_b4 = iVar11;
          local_a0 = uVar32;
        }
        else if (iVar10 == 1) {
          local_e4 = 0;
          local_e0 = 0;
          local_dc = 0;
          local_d8 = 0;
          local_d4 = iVar12;
          sVar16 = strlen(acStack_2a0);
          memcpy(auStack_c6,acStack_2a0,sVar16 + 1);
          local_cc = local_3c8;
          local_c8 = local_3c4;
          local_d0 = uVar33;
        }
        puVar15 = auStack_188;
        uVar26 = 0x11;
      }
    }
    iVar13 = _wportal_update_free_strategy_to_ap(puVar15,uVar26);
  }
  else {
    FUN_00407df0(puVar15);
  }
  return iVar13;
}

