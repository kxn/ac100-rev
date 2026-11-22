// func apupd_jcs_large_image_status_get @ 0063f0a4 size=820

void apupd_jcs_large_image_status_get(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined4 local_8d0;
  undefined2 local_8cc;
  char local_8c8 [16];
  uint local_8b8;
  undefined1 auStack_8b4 [52];
  undefined4 local_880;
  undefined1 auStack_814 [416];
  undefined1 local_674;
  undefined1 local_673;
  
  local_8c8[0] = '\0';
  local_8c8[1] = '\0';
  local_8c8[2] = '\0';
  local_8c8[3] = '\0';
  local_8c8[4] = '\0';
  local_8c8[5] = '\0';
  local_8c8[6] = '\0';
  local_8c8[7] = '\0';
  local_8c8[8] = '\0';
  local_8c8[9] = '\0';
  local_8c8[10] = '\0';
  local_8c8[0xb] = '\0';
  local_8c8[0xc] = '\0';
  local_8c8[0xd] = '\0';
  local_8c8[0xe] = '\0';
  local_8c8[0xf] = '\0';
  local_8b8 = 0;
  local_8d0 = 0;
  local_8cc = 0;
  memset(auStack_8b4,0,0xa0);
  memset(auStack_814,0,0x800);
  memset(auStack_8b4,0,0xa0);
  memset(auStack_814,0,0x800);
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar5 = 1;
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0063f1d8;
    pcVar3 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar4 = 0xe00;
  }
  else {
    iVar1 = json_object_object_get(param_1,"mac");
    if (iVar1 == 0) {
      uVar5 = 0x14;
      iVar1 = json_object_object_get(param_1,"model_id");
      if (iVar1 == 0) goto LAB_0063f1d8;
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        local_880 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar6 = json_object_get_double(iVar1);
          local_880 = __fixunsdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
        }
        else {
          local_880 = 0xffffffff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "apupd_jcs_large_image_status_get",0xe1b);
          }
        }
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 6) {
        pcVar3 = (char *)json_object_get_string(iVar1);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "apupd_jcs_large_image_status_get",0xe08);
        }
        pcVar3 = "";
      }
      strncpy(local_8c8,pcVar3,0x13);
      local_8b8 = local_8b8 & 0xffffff00;
      sscanf(local_8c8,"%hhx-%hhx-%hhx-%hhx-%hhx-%hhx",&local_8d0,(int)&local_8d0 + 1,
             (int)&local_8d0 + 2,(int)&local_8d0 + 3,&local_8cc,(int)&local_8cc + 1);
      iVar1 = apupd_db_wtp_get_by_mac(&local_8d0,auStack_8b4);
      if ((iVar1 != 0) || (iVar1 = FUN_00408430(&local_8d0), iVar1 != 0)) {
        uVar5 = 0x12;
        if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0063f1d8;
        pcVar3 = "[APUPD_ERROR]%32s() %05d: get wtp failed.\r\n";
        uVar4 = 0xe0d;
        goto LAB_0063f2f8;
      }
    }
    iVar1 = apupd_db_model_get_by_id(local_880,auStack_814);
    if (iVar1 != 0) {
      uVar5 = 0;
      uVar4 = json_object_new_int(local_673);
      json_object_object_add(param_2,"can_down_sub_image",uVar4);
      uVar4 = json_object_new_int(local_674);
      json_object_object_add(param_2,"sub_image_num",uVar4);
      goto LAB_0063f1d8;
    }
    uVar5 = 0x15;
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0063f1d8;
    pcVar3 = "[APUPD_ERROR]%32s() %05d: get model by id failed.\r\n";
    uVar4 = 0xe20;
  }
LAB_0063f2f8:
  printf(pcVar3,"apupd_jcs_large_image_status_get",uVar4);
LAB_0063f1d8:
  uVar5 = json_object_new_int(uVar5);
  json_object_object_add(param_2,&DAT_00676a24,uVar5);
  return;
}

