// func mesh_jcs_global_set @ 004bf6c0 size=2400

void mesh_jcs_global_set(undefined4 param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  int local_178;
  int local_174;
  int local_170;
  int local_16c;
  int local_168;
  int local_164;
  undefined4 local_160;
  char local_15c [20];
  char local_148 [20];
  char acStack_134 [32];
  undefined1 local_114;
  char acStack_113 [63];
  undefined1 local_d4;
  char acStack_d3 [32];
  undefined1 local_b3;
  undefined1 auStack_b0 [136];
  
  iVar10 = 0;
  local_16c = 0;
  memset(auStack_b0,0,0x82);
  memset(acStack_134,0,0x82);
  local_170 = 0;
  local_148[0] = '\0';
  local_148[1] = '\0';
  local_148[2] = '\0';
  local_148[3] = '\0';
  local_148[4] = '\0';
  local_148[5] = '\0';
  local_148[6] = '\0';
  local_148[7] = '\0';
  local_148[8] = '\0';
  local_148[9] = '\0';
  local_148[10] = '\0';
  local_148[0xb] = '\0';
  local_148[0xc] = '\0';
  local_148[0xd] = '\0';
  local_148[0xe] = '\0';
  local_148[0xf] = '\0';
  local_148[0x10] = 0;
  local_15c[0] = '\0';
  local_15c[1] = '\0';
  local_15c[2] = '\0';
  local_15c[3] = '\0';
  local_15c[4] = '\0';
  local_15c[5] = '\0';
  local_15c[6] = '\0';
  local_15c[7] = '\0';
  local_15c[8] = '\0';
  local_15c[9] = '\0';
  local_15c[10] = '\0';
  local_15c[0xb] = '\0';
  local_15c[0xc] = '\0';
  local_15c[0xd] = '\0';
  local_15c[0xe] = '\0';
  local_15c[0xf] = '\0';
  local_15c[0x10] = 0;
  iVar3 = json_object_object_get(param_1,"re_recover_flag");
  if ((iVar3 != 0) &&
     ((iVar4 = json_object_get_type(iVar3), iVar4 == 3 ||
      (iVar4 = json_object_get_type(iVar3), iVar4 == 2)))) {
    iVar10 = json_object_get_type(iVar3);
    if (iVar10 == 3) {
      iVar10 = json_object_get_int(iVar3);
    }
    else {
      iVar10 = json_object_get_type();
      if (iVar10 == 2) {
        uVar11 = json_object_get_double(iVar3);
        iVar10 = __fixdfsi((int)((ulonglong)uVar11 >> 0x20),(int)uVar11);
      }
      else {
        iVar10 = -1;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "mesh_jcs_global_set",0x4d9);
        }
      }
    }
  }
  mesh_db_mesh_enable_get(&local_16c);
  iVar3 = json_object_object_get(param_1,"enable");
  if (iVar3 == 0) {
LAB_004bf840:
    bVar1 = false;
    bVar2 = false;
  }
  else {
    iVar4 = json_object_get_type(iVar3);
    iVar9 = 0;
    if (iVar4 == 6) {
      do {
        while( true ) {
          if (onoff_map <= iVar9) {
            if (jcs_err_switch == 0) goto LAB_004bf7cc;
            pcVar8 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
            goto LAB_004bfd8c;
          }
          iVar4 = iVar9 * 0x10;
          pcVar8 = *(char **)(PTR__mt_onoff_00731f8c + iVar4);
          if (pcVar8 != (char *)0x0) break;
          iVar9 = iVar9 + 1;
        }
        pcVar7 = (char *)json_object_get_string(iVar3);
        iVar6 = strcmp(pcVar8,pcVar7);
        iVar9 = iVar9 + 1;
      } while (iVar6 != 0);
      iVar3 = *(int *)(PTR__mt_onoff_00731f8c + iVar4 + 0xc);
    }
    else {
      if (jcs_err_switch != 0) {
        pcVar8 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
LAB_004bfd8c:
        printf(pcVar8,"mesh_jcs_global_set",0x4e0);
      }
LAB_004bf7cc:
      if (jcs_err_switch == 0) {
        iVar3 = -1;
      }
      else {
        printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","mesh_jcs_global_set",
               0x4e0);
        iVar3 = -1;
      }
    }
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d old_enable=%d, enable=%d\n","mesh_jcs_global_set",0x4e1,local_16c,
             iVar3);
    }
    if (local_16c == iVar3) goto LAB_004bf840;
    mesh_db_mesh_enable_set(iVar3);
    bVar1 = false;
    if (iVar3 == 0) {
      bVar1 = true;
      apmngr_db_foreach_proc(0x200000,_mesh_del_all_re_router,0);
      if (iVar10 != 0) {
        bVar1 = false;
        mesh_stop_re_auto_add_proc();
      }
    }
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d notify all mesh_dev enable=%d\n","mesh_jcs_global_set",0x4f5,iVar3
            );
    }
    handle_global_mesh_switch(iVar3);
    bVar2 = true;
    if ((iVar3 != 0) && (iVar10 != 0)) {
      mesh_start_re_auto_add_proc();
    }
  }
  mesh_db_backhaul_info_get(auStack_b0);
  memcpy(acStack_134,auStack_b0,0x82);
  iVar3 = json_object_object_get(param_1,"backhaul_ssid");
  if (iVar3 != 0) {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 6) {
      pcVar8 = (char *)json_object_get_string(iVar3);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "mesh_jcs_global_set",0x509);
      }
      pcVar8 = "";
    }
    strncpy(acStack_134,pcVar8,0x20);
    local_114 = 0;
  }
  iVar3 = json_object_object_get(param_1,"backhaul_key");
  if (iVar3 != 0) {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 6) {
      pcVar8 = (char *)json_object_get_string(iVar3);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "mesh_jcs_global_set",0x50c);
      }
      pcVar8 = "";
    }
    strncpy(acStack_113,pcVar8,0x3f);
    local_d4 = 0;
  }
  iVar3 = json_object_object_get(param_1,"backhaul_token");
  if (iVar3 != 0) {
    iVar4 = json_object_get_type(iVar3);
    if (iVar4 == 6) {
      pcVar8 = (char *)json_object_get_string(iVar3);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "mesh_jcs_global_set",0x50f);
      }
      pcVar8 = "";
    }
    strncpy(acStack_d3,pcVar8,0x20);
    local_b3 = 0;
  }
  mesh_db_backhaul_info_set(acStack_134);
  iVar3 = memcmp(auStack_b0,acStack_134,0x82);
  if (iVar3 != 0) {
    mesh_pkt_backhaul_request_send_to_all(acStack_134,acStack_113,acStack_d3);
    if (bVar1) {
      bVar2 = true;
      bVar1 = true;
    }
    else {
      bVar2 = true;
      if (local_16c != 0) {
        bVar1 = iVar10 == 0;
      }
    }
  }
  iVar3 = json_object_object_get(param_1,"web_password");
  if (iVar3 != 0) {
    mesh_db_web_password_get(local_148,0x11);
    iVar10 = json_object_get_type(iVar3);
    if (iVar10 == 6) {
      pcVar8 = (char *)json_object_get_string(iVar3);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "mesh_jcs_global_set",0x521);
      }
      pcVar8 = "";
    }
    strncpy(local_15c,pcVar8,0x10);
    local_15c[0x10] = 0;
    iVar3 = strcmp(local_148,local_15c);
    if (iVar3 != 0) {
      sVar5 = strlen(local_15c);
      mesh_db_web_password_set(local_15c,sVar5);
      sVar5 = strlen(local_15c);
      mesh_pkt_web_password_request_send_to_all(local_15c,(int)(short)sVar5);
    }
  }
  iVar3 = json_object_object_get(param_1,"re_auto_switch");
  if (iVar3 == 0) goto LAB_004bfa74;
  mesh_db_re_auto_switch_get(&local_170);
  iVar10 = json_object_get_type(iVar3);
  if (iVar10 == 6) {
    iVar10 = 0;
    while (iVar10 < onoff_map) {
      pcVar8 = *(char **)(PTR__mt_onoff_00731f8c + iVar10 * 0x10);
      if (pcVar8 == (char *)0x0) {
        iVar10 = iVar10 + 1;
      }
      else {
        pcVar7 = (char *)json_object_get_string(iVar3);
        iVar4 = strcmp(pcVar8,pcVar7);
        if (iVar4 == 0) {
          iVar3 = *(int *)(PTR__mt_onoff_00731f8c + iVar10 * 0x10 + 0xc);
          goto LAB_004bfa44;
        }
        iVar10 = iVar10 + 1;
      }
    }
    if (jcs_err_switch != 0) {
      pcVar8 = "[JCS_ERR]%s()/%d Warning: map string to int failed.\n";
LAB_004bfe54:
      printf(pcVar8,"mesh_jcs_global_set",0x52c);
    }
  }
  else if (jcs_err_switch != 0) {
    pcVar8 = "[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n";
    goto LAB_004bfe54;
  }
  if (jcs_err_switch == 0) {
    iVar3 = -1;
  }
  else {
    printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n","mesh_jcs_global_set",0x52c)
    ;
    iVar3 = -1;
  }
LAB_004bfa44:
  if (local_170 != iVar3) {
    apmngr_db_foreach_proc(0xe0000,_mesh_tmp_re_roam_close,0);
    mesh_db_re_auto_switch_set(iVar3);
    mesh_pkt_auto_switch_request_send_to_all(iVar3,1);
  }
LAB_004bfa74:
  iVar3 = json_object_object_get(param_1,"bh_work_mode");
  if (iVar3 != 0) {
    local_168 = 0;
    local_164 = 0;
    local_160 = (void *)((uint)local_160 & 0xffff);
    local_174 = 0;
    iVar10 = json_object_get_type(iVar3);
    if (iVar10 == 6) {
      pcVar8 = (char *)json_object_get_string(iVar3);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "mesh_jcs_global_set",0x53a);
      }
      pcVar8 = "";
    }
    strncpy((char *)&local_168,pcVar8,9);
    local_160._1_3_ = (uint3)local_160._2_2_;
    iVar3 = atoi((char *)&local_168);
    mesh_db_bh_work_mode_get(&local_174);
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d jcs begin set bh_work_mode=%d, pre_work_mode=%d;\n",
             "mesh_jcs_global_set",0x53d,iVar3,local_174);
    }
    if ((local_174 != iVar3) && (iVar3 != 0)) {
      local_178 = iVar3;
      apmngr_db_foreach_proc(0xff7fffff,_mesh_bh_work_mode_changed_cb,&local_178);
    }
    mesh_db_bh_work_mode_set(iVar3);
    mesh_pkt_bh_work_mode_send_to_all(iVar3);
  }
  if (bVar1) {
    local_168 = 0;
    local_164 = 0;
    local_160 = (void *)0x0;
    local_164 = apmngr_db_get_ap_max();
    local_160 = (void *)FUN_00408450(local_164 << 1,0x2e2);
    if (local_160 == (void *)0x0) {
      if (mesh_err_switch != '\0') {
        printf("[MESH_ERROR]%s()/%d Malloc failed\n","mesh_delete_all_sub_dev",0x2e5);
      }
    }
    else {
      memset(local_160,0,local_164 << 1);
      apmngr_db_foreach_proc(0x1700000,_mesh_cb_all_child_collect,&local_168);
      if (0 < local_168) {
        FUN_00407e80("mesh_delete_all_sub_dev");
        apmngr_ap_delete(local_160,local_168,0,0,1);
        FUN_004082b0(0,"mesh_delete_all_sub_dev");
      }
      FUN_00407df0(local_160);
    }
  }
  if (bVar2) {
    FUN_00407f60(1);
  }
  return;
}

