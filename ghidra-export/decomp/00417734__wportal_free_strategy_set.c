// func _wportal_free_strategy_set @ 00417734 size=4652

int _wportal_free_strategy_set(undefined4 param_1)

{
  undefined1 auVar1 [4];
  int iVar2;
  int iVar3;
  char cVar5;
  size_t sVar4;
  undefined4 **ppuVar6;
  undefined1 *puVar7;
  char *pcVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 *puVar17;
  undefined4 uVar18;
  undefined8 uVar19;
  undefined4 *puVar20;
  undefined4 *puVar21;
  undefined1 auVar22 [4];
  undefined4 uVar23;
  uint local_788;
  undefined2 local_784;
  char local_780 [16];
  ushort local_770;
  undefined4 local_76c;
  undefined4 local_768;
  undefined4 local_764;
  undefined4 local_760;
  undefined4 local_75c;
  undefined4 local_758;
  undefined4 local_754;
  undefined4 local_750;
  undefined4 local_74c;
  undefined4 local_748;
  undefined4 local_744;
  undefined4 local_740;
  undefined4 local_73c;
  undefined4 local_738;
  undefined4 local_734;
  undefined4 local_730;
  uint local_72c [4];
  undefined4 local_71c;
  undefined4 *local_718;
  undefined4 local_714;
  undefined4 local_710;
  undefined4 local_70c;
  char acStack_708 [39];
  undefined1 local_6e1;
  undefined4 local_6e0;
  undefined1 auStack_6dc [4];
  undefined1 auStack_6d8 [4];
  undefined1 auStack_6d4 [4];
  undefined1 auStack_6d0 [4];
  undefined1 auStack_6cc [44];
  undefined4 auStack_6a0 [16];
  char acStack_660 [127];
  undefined1 local_5e1;
  char acStack_5e0 [150];
  undefined1 local_54a;
  undefined1 auStack_548 [324];
  undefined1 auStack_404 [324];
  undefined1 auStack_2c0 [152];
  int local_228;
  undefined4 local_224;
  undefined1 auStack_17c [152];
  int local_e4;
  undefined4 local_e0;
  byte local_dc;
  undefined4 *local_d8;
  uint local_d4;
  undefined4 *local_d0;
  uint local_cc;
  undefined4 local_c8;
  undefined4 *local_c4;
  uint local_c0;
  undefined1 local_bc [4];
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  uint local_a8;
  uint local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  uint local_38;
  undefined4 local_34;
  uint local_30;
  
  memset(acStack_5e0,0,0x97);
  memset(acStack_660,0,0x80);
  memset(acStack_708,0,0x28);
  local_71c = 0;
  local_718 = (undefined4 *)0x0;
  local_714 = 0;
  local_710 = 0;
  local_70c = 0;
  local_780[0] = '\0';
  local_780[1] = '\0';
  local_780[2] = '\0';
  local_780[3] = '\0';
  local_780[4] = '\0';
  local_780[5] = '\0';
  local_780[6] = '\0';
  local_780[7] = '\0';
  local_780[8] = '\0';
  local_780[9] = '\0';
  local_780[10] = '\0';
  local_780[0xb] = '\0';
  local_780[0xc] = '\0';
  local_780[0xd] = '\0';
  local_780[0xe] = '\0';
  local_780[0xf] = '\0';
  local_770 = 0;
  local_788 = 0;
  local_784 = 0;
  local_730 = 0;
  local_72c[0] = 0;
  local_72c[1] = 0;
  local_72c[2] = 0;
  local_72c[3] = 0;
  iVar2 = json_object_object_get(param_1,"name");
  if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_free_strategy_set",0x15c3);
    }
    pcVar8 = "";
  }
  else {
    pcVar8 = (char *)json_object_get_string(iVar2);
  }
  strncpy(acStack_5e0,pcVar8,0x96);
  local_54a = 0;
  iVar2 = json_object_object_get(param_1,"match_type");
  if (iVar2 == 0) {
LAB_0041786c:
    uVar14 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_free_strategy_set",0x15c6);
    }
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar14 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 != 2) goto LAB_0041786c;
      uVar19 = json_object_get_double(iVar2);
      uVar14 = __fixdfsi((int)((ulonglong)uVar19 >> 0x20),(int)uVar19);
    }
  }
  iVar2 = json_object_object_get(param_1,&DAT_00677c20);
  if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_free_strategy_set",0x15c9);
    }
    pcVar8 = "";
  }
  else {
    pcVar8 = (char *)json_object_get_string(iVar2);
  }
  strncpy(acStack_708,pcVar8,0x27);
  local_6e1 = 0;
  iVar2 = strcmp(acStack_708,"null");
  uVar13 = 0;
  if (iVar2 != 0) {
    FUN_0051a7a8(acStack_708,&local_71c);
    iVar2 = json_object_object_get(param_1,"src_ip_mask");
    if (iVar2 == 0) {
LAB_00418004:
      uVar13 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_free_strategy_set",0x15d0);
      }
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar13 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_00418004;
        uVar19 = json_object_get_double(iVar2);
        uVar13 = __fixdfsi((int)((ulonglong)uVar19 >> 0x20),(int)uVar19);
      }
    }
  }
  iVar2 = json_object_object_get(param_1,"src_mac");
  if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_free_strategy_set",0x15d4);
    }
    pcVar8 = "";
  }
  else {
    pcVar8 = (char *)json_object_get_string(iVar2);
  }
  strncpy(local_780,pcVar8,0x11);
  local_770 = local_770 & 0xff00;
  if (local_780[0] != '\0') {
    sscanf(local_780,"%2X-%2X-%2X-%2X-%2X-%2X",&local_6e0,auStack_6dc,auStack_6d8,auStack_6d4,
           auStack_6d0,auStack_6cc);
    puVar17 = &local_6e0;
    iVar2 = 0;
    do {
      puVar7 = (undefined1 *)((int)&local_788 + iVar2);
      uVar18 = *puVar17;
      iVar2 = iVar2 + 1;
      puVar17 = puVar17 + 1;
      *puVar7 = (char)uVar18;
    } while (iVar2 != 6);
  }
  puVar17 = (undefined4 *)0x0;
  if (g_portal_auth_mode == 1) {
    iVar2 = json_object_object_get(param_1,"src_vlan");
    if (iVar2 == 0) {
LAB_00418290:
      puVar17 = (undefined4 *)0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_free_strategy_set",0x15e5);
      }
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        puVar17 = (undefined4 *)json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_00418290;
        uVar19 = json_object_get_double(iVar2);
        puVar17 = (undefined4 *)__fixdfsi((int)((ulonglong)uVar19 >> 0x20),(int)uVar19);
      }
    }
  }
  iVar2 = json_object_object_get(param_1,"id");
  if (iVar2 == 0) {
LAB_0041799c:
    uVar18 = 0xffffffff;
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_wportal_free_strategy_set",0x15e9);
    }
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 == 3) {
      uVar18 = json_object_get_int(iVar2);
    }
    else {
      iVar3 = json_object_get_type();
      if (iVar3 != 2) goto LAB_0041799c;
      uVar19 = json_object_get_double(iVar2);
      uVar18 = __fixdfsi((int)((ulonglong)uVar19 >> 0x20),(int)uVar19);
    }
  }
  if (uVar14 == 0) {
    iVar2 = json_object_object_get(param_1,"src_port_start");
    if (iVar2 == 0) {
LAB_004179f0:
      local_38 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_free_strategy_set",0x15ee);
      }
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        local_38 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_004179f0;
        uVar19 = json_object_get_double(iVar2);
        local_38 = __fixdfsi((int)((ulonglong)uVar19 >> 0x20),(int)uVar19);
      }
    }
    iVar2 = json_object_object_get(param_1,"src_port_end");
    if (iVar2 == 0) {
LAB_00417a44:
      local_34 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_free_strategy_set",0x15f1);
      }
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        local_34 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_00417a44;
        uVar19 = json_object_get_double(iVar2);
        local_34 = __fixdfsi((int)((ulonglong)uVar19 >> 0x20),(int)uVar19);
      }
    }
    iVar2 = json_object_object_get(param_1,"dst_port_start");
    if (iVar2 == 0) {
LAB_00417a98:
      uVar16 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_free_strategy_set",0x15f4);
      }
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar16 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_00417a98;
        uVar19 = json_object_get_double(iVar2);
        uVar16 = __fixdfsi((int)((ulonglong)uVar19 >> 0x20),(int)uVar19);
      }
    }
    iVar2 = json_object_object_get(param_1,"dst_port_end");
    if (iVar2 == 0) {
LAB_00417ae8:
      uVar15 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_wportal_free_strategy_set",0x15f7);
      }
    }
    else {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar15 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_00417ae8;
        uVar19 = json_object_get_double(iVar2);
        uVar15 = __fixdfsi((int)((ulonglong)uVar19 >> 0x20),(int)uVar19);
      }
    }
    iVar2 = json_object_object_get(param_1,"dst_ip");
    if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_wportal_free_strategy_set",0x15fa);
      }
      pcVar8 = "";
    }
    else {
      pcVar8 = (char *)json_object_get_string(iVar2);
    }
    strncpy(acStack_708,pcVar8,0x27);
    local_6e1 = 0;
    uVar12 = 0;
    iVar2 = strcmp(acStack_708,"null");
    if (iVar2 != 0) {
      FUN_0051a7a8(acStack_708,&local_730);
      iVar2 = json_object_object_get(param_1,"dst_ip_mask");
      if (iVar2 == 0) {
LAB_00418220:
        uVar12 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_wportal_free_strategy_set",0x1601);
        }
      }
      else {
        iVar3 = json_object_get_type(iVar2);
        if (iVar3 == 3) {
          uVar12 = json_object_get_int(iVar2);
        }
        else {
          iVar3 = json_object_get_type();
          if (iVar3 != 2) goto LAB_00418220;
          uVar19 = json_object_get_double(iVar2);
          uVar12 = __fixdfsi((int)((ulonglong)uVar19 >> 0x20),(int)uVar19);
        }
      }
    }
    iVar2 = json_object_object_get(param_1,"protocol");
    if (iVar2 != 0) {
      iVar3 = json_object_get_type(iVar2);
      if (iVar3 == 3) {
        uVar11 = json_object_get_int(iVar2);
      }
      else {
        iVar3 = json_object_get_type();
        if (iVar3 != 2) goto LAB_00417ba4;
        uVar19 = json_object_get_double(iVar2);
        uVar11 = __fixdfsi((int)((ulonglong)uVar19 >> 0x20),(int)uVar19);
      }
      goto LAB_00417c3c;
    }
LAB_00417ba4:
    uVar11 = 0xffffffff;
    if (jcs_err_switch == 0) goto LAB_00417c3c;
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "_wportal_free_strategy_set",0x1605);
  }
  else {
    iVar2 = json_object_object_get(param_1,&DAT_00677ca8);
    if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_wportal_free_strategy_set",0x160a);
      }
      pcVar8 = "";
    }
    else {
      pcVar8 = (char *)json_object_get_string(iVar2);
    }
    uVar11 = 0;
    uVar12 = 0;
    strncpy(acStack_660,pcVar8,0x7f);
    uVar15 = 0;
    local_5e1 = 0;
    uVar16 = 0;
    local_34 = 0;
    local_38 = 0;
LAB_00417c3c:
  }
  local_30 = (uint)local_71c._0_1_;
  cVar5 = '\x01';
  if (local_30 == 1) {
    cVar5 = '\x02';
LAB_00417c60:
    if (local_730._0_1_ == cVar5) {
      return 0;
    }
  }
  else if (local_30 == 2) goto LAB_00417c60;
  memset(auStack_17c,0,0x144);
  memset(auStack_2c0,0,0x144);
  if (local_30 == 2) {
    local_e4 = 2;
  }
  else if (local_730._0_1_ == '\x02') {
    local_e4 = 2;
  }
  else if (local_30 == 1) {
    local_e4 = 1;
  }
  else if (local_730._0_1_ == '\x01') {
    local_e4 = 1;
  }
  else {
    local_e4 = 3;
  }
  local_dc = (byte)uVar14;
  local_e0 = uVar18;
  if ((local_e4 == 1) || (local_e4 == 3)) {
    uVar10 = uVar14 & 0xff;
    sVar4 = strlen(acStack_5e0);
    memcpy(auStack_17c,acStack_5e0,sVar4 + 1);
    puVar20 = local_718;
    if (uVar14 == 0) {
      if (uVar13 == 0) {
        local_d4 = 0;
      }
      else {
        local_d4 = -1 << (-uVar13 & 0x1f);
      }
      if (uVar12 == 0) {
        local_c0 = 0;
      }
      else {
        local_c0 = -1 << (-uVar12 & 0x1f);
      }
      local_cc = local_788;
      local_bc = (undefined1  [4])local_38;
      local_c8 = CONCAT22(local_784,local_c8._2_2_);
      local_b8 = local_34;
      local_d8 = (undefined4 *)(local_d4 & (uint)local_718);
      local_c4 = (undefined4 *)(local_c0 & local_72c[0]);
      local_d0 = puVar17;
      local_b4 = uVar16;
      local_b0 = uVar15;
      local_ac = uVar11;
LAB_00417df4:
      if (uVar10 == 0) goto LAB_00417dfc;
LAB_004180e8:
      if (((uVar10 != 1) || (wportal_info_switch == 0)) ||
         (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00417d20;
      pcVar8 = 
      "[WPORTAL_INFO]%s()/%d Set ftt url entry: %s type: %d src_ip: %x/%x mac: %x:%x:%x:%x:%x:%x vlan: %d  url: %s\n"
      ;
      uVar16 = 0x166f;
      puVar17 = &local_c8;
      puVar20 = local_d8;
      uVar13 = local_d4;
      puVar21 = local_d0;
      uVar14 = local_cc;
      auVar1 = (undefined1  [4])local_c8;
LAB_00418174:
      printf(pcVar8,"_wportal_free_strategy_set",uVar16,auStack_17c,(uint)local_dc,puVar20,uVar13,
             uVar14 >> 0x18,uVar14 >> 0x10 & 0xff,uVar14 >> 8 & 0xff,uVar14 & 0xff,
             (uint)auVar1 >> 0x18,(uint)auVar1 >> 0x10 & 0xff,puVar21,(int)puVar17 + 2);
    }
    else {
      if (uVar14 != 1) goto LAB_00417df4;
      local_d8 = local_718;
      if (uVar13 == 0) {
        local_d4 = 0;
      }
      else {
        local_d4 = -1 << (-uVar13 & 0x1f);
      }
      memcpy((void *)((int)&local_c8 + 2),acStack_660,0x80);
      local_cc = local_788;
      local_c8 = CONCAT22(local_784,local_c8._2_2_);
      local_d8 = (undefined4 *)(local_d4 & (uint)puVar20);
      local_d0 = puVar17;
      if (uVar10 != 0) goto LAB_004180e8;
LAB_00417dfc:
      if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        pcVar8 = 
        "[WPORTAL_INFO]%s()/%d Set ftt tuple entry: %s type: %d src_ip: %x/%x dst_ip: %x/%x mac: %x:%x:%x:%x:%x:%x vlan: %d src_port: %d-%d dst_port: %d-%d protocol: %d\n"
        ;
        uVar9 = 0x1663;
        puVar17 = local_d8;
        uVar13 = local_d4;
        puVar20 = local_c4;
        uVar12 = local_c0;
        puVar21 = local_d0;
        auVar22 = local_bc;
        uVar16 = local_b8;
        uVar15 = local_b4;
        uVar11 = local_b0;
        uVar23 = local_ac;
        uVar14 = local_cc;
        auVar1 = (undefined1  [4])local_c8;
        goto LAB_00418500;
      }
    }
  }
  else {
    sVar4 = strlen(acStack_5e0);
    memcpy(auStack_17c,acStack_5e0,sVar4 + 1);
    if (uVar14 == 0) {
      memcpy(&local_d8,&local_718,0x10);
      local_c8 = uVar13;
      memcpy(local_bc + 2,local_72c,0x10);
      local_c0 = local_788;
      local_a4 = local_38;
      local_bc._0_2_ = local_784;
      local_a0 = local_34;
      local_c4 = puVar17;
      local_a8 = uVar12;
      local_9c = uVar16;
      local_98 = uVar15;
      local_94 = uVar11;
      FUN_00408480(&local_d8,uVar13,&local_d8);
      ppuVar6 = (undefined4 **)(local_bc + 2);
LAB_00418580:
      FUN_00408480(ppuVar6,uVar12,ppuVar6);
    }
    else if (uVar14 == 1) {
      memcpy(&local_d8,&local_718,0x10);
      local_c8 = uVar13;
      memcpy(local_bc + 2,acStack_660,0x80);
      ppuVar6 = &local_d8;
      local_c0 = local_788;
      local_bc._0_2_ = local_784;
      uVar12 = uVar13;
      local_c4 = puVar17;
      goto LAB_00418580;
    }
    if (local_dc == 0) {
      memset(auStack_6a0,0,0x40);
      memset(&local_6e0,0,0x40);
      local_744 = 0;
      local_740 = 0;
      local_73c = 0;
      local_738 = 0;
      local_734 = 0;
      local_758 = 0;
      local_754 = 0;
      local_750 = 0;
      local_74c = 0;
      local_748 = 0;
      FUN_00408560(&local_d8,2,&local_744);
      FUN_00408190(local_744,local_740,local_73c,local_738,local_734,auStack_6a0,0x40,"---");
      FUN_00408560(local_bc + 2,2,&local_758);
      FUN_00408190(local_758,local_754,local_750,local_74c,local_748,&local_6e0,0x40,"---");
      if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        pcVar8 = 
        "[WPORTAL_INFO]%s()/%d Set ftt tuple entry: %s type: %d src_ip: %s/%x dst_ip: %s/%x mac: %x:%x:%x:%x:%x:%x vlan: %d src_port: %d-%d dst_port: %d-%d protocol: %d\n"
        ;
        uVar9 = 0x16aa;
        puVar17 = auStack_6a0;
        uVar13 = local_c8;
        puVar20 = &local_6e0;
        uVar12 = local_a8;
        puVar21 = local_c4;
        auVar22 = (undefined1  [4])local_a4;
        uVar16 = local_a0;
        uVar15 = local_9c;
        uVar11 = local_98;
        uVar23 = local_94;
        uVar14 = local_c0;
        auVar1 = local_bc;
LAB_00418500:
        printf(pcVar8,"_wportal_free_strategy_set",uVar9,auStack_17c,(uint)local_dc,puVar17,uVar13,
               puVar20,uVar12,uVar14 >> 0x18,uVar14 >> 0x10 & 0xff,uVar14 >> 8 & 0xff,uVar14 & 0xff,
               (uint)auVar1 >> 0x18,(uint)auVar1 >> 0x10 & 0xff,puVar21,auVar22,uVar16,uVar15,uVar11
               ,uVar23);
      }
    }
    else if (local_dc == 1) {
      memset(&local_6e0,0,0x40);
      local_76c = 0;
      local_768 = 0;
      local_764 = 0;
      local_760 = 0;
      local_75c = 0;
      FUN_00408560(&local_d8,2,&local_76c);
      FUN_00408190(local_76c,local_768,local_764,local_760,local_75c,&local_6e0,0x40,"---");
      if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        pcVar8 = 
        "[WPORTAL_INFO]%s()/%d Set ftt url entry: %s type: %d src_ip: %s/%x mac: %x:%x:%x:%x:%x:%x vlan: %d  url: %s\n"
        ;
        uVar16 = 0x16bc;
        puVar17 = (undefined4 *)local_bc;
        puVar20 = &local_6e0;
        uVar13 = local_c8;
        puVar21 = local_c4;
        uVar14 = local_c0;
        auVar1 = local_bc;
        goto LAB_00418174;
      }
    }
  }
LAB_00417d20:
  iVar2 = wportal_db_ftt_set(auStack_17c);
  if (iVar2 != 0) {
    return iVar2;
  }
  wportal_db_ftt_get_by_name(auStack_17c,auStack_2c0);
  puVar7 = auStack_2c0;
  if (local_228 == 1) {
    uVar16 = 7;
    local_224 = uVar18;
  }
  else if (local_228 == 2) {
    puVar7 = auStack_2c0;
    uVar16 = 0x12;
    local_224 = uVar18;
  }
  else {
    if (local_228 != 3) goto LAB_00417ef8;
    local_228 = 1;
    local_224 = uVar18;
    _wportal_update_free_strategy_to_ap(auStack_2c0,7);
    _wportal_free_strategy_transfer_v4_to_v6(auStack_2c0,auStack_404);
    puVar7 = auStack_404;
    uVar16 = 0x12;
  }
  _wportal_update_free_strategy_to_ap(puVar7,uVar16);
LAB_00417ef8:
  iVar2 = local_e4;
  if (local_e4 == 1) {
    uVar18 = 6;
  }
  else {
    if (local_e4 != 2) {
      if (local_e4 != 3) {
        return 0;
      }
      local_e4 = 1;
      _wportal_update_free_strategy_to_ap(auStack_17c,6);
      local_e4 = iVar2;
      _wportal_free_strategy_transfer_v4_to_v6(auStack_17c,auStack_548);
      _wportal_update_free_strategy_to_ap(auStack_548,0x11);
      return 0;
    }
    uVar18 = 0x11;
  }
  _wportal_update_free_strategy_to_ap(auStack_17c,uVar18);
  return 0;
}

