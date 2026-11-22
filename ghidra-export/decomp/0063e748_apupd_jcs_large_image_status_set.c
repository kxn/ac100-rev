// func apupd_jcs_large_image_status_set @ 0063e748 size=2396

void apupd_jcs_large_image_status_set(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined4 local_1740;
  undefined2 local_173c;
  undefined4 local_1738;
  undefined4 local_1734;
  undefined4 local_1730;
  undefined4 local_172c;
  char local_1728 [16];
  uint local_1718;
  undefined1 auStack_1714 [64];
  undefined1 auStack_16d4 [128];
  char acStack_1654 [128];
  char acStack_15d4 [128];
  undefined1 auStack_1554 [52];
  undefined4 local_1520;
  undefined1 auStack_14b4 [20];
  undefined1 auStack_14a0 [416];
  undefined1 auStack_1300 [78];
  undefined1 auStack_12b2 [650];
  undefined1 auStack_1028 [88];
  undefined4 local_fd0;
  char local_ef0;
  char local_eee;
  char local_e87;
  int local_e84;
  int local_83c;
  undefined1 auStack_828 [88];
  undefined4 local_7d0;
  undefined1 local_687;
  int local_67c;
  int local_678;
  undefined1 auStack_674 [16];
  ushort local_664;
  ushort local_662;
  ushort local_660;
  uint local_65c;
  undefined4 local_658;
  undefined1 auStack_654 [1580];
  
  local_1728[0] = '\0';
  local_1728[1] = '\0';
  local_1728[2] = '\0';
  local_1728[3] = '\0';
  local_1728[4] = '\0';
  local_1728[5] = '\0';
  local_1728[6] = '\0';
  local_1728[7] = '\0';
  local_1728[8] = '\0';
  local_1728[9] = '\0';
  local_1728[10] = '\0';
  local_1728[0xb] = '\0';
  local_1728[0xc] = '\0';
  local_1728[0xd] = '\0';
  local_1728[0xe] = '\0';
  local_1728[0xf] = '\0';
  local_1718 = 0;
  local_1740 = 0;
  local_173c = 0;
  memset(auStack_1554,0,0xa0);
  memset(auStack_828,0,0x800);
  memset(auStack_1028,0,0x800);
  memset(auStack_14b4,0,0x1ae);
  memset(auStack_1300,0,0x2d8);
  memset(acStack_15d4,0,0x80);
  memset(acStack_1654,0,0x80);
  memset(auStack_16d4,0,0x80);
  memset(auStack_1714,0,0x40);
  memset(auStack_1028,0,0x800);
  memset(auStack_828,0,0x800);
  memset(auStack_1554,0,0xa0);
  memset(auStack_14b4,0,0x1ae);
  local_1738 = 0;
  local_1734 = 0;
  local_1730 = 0;
  local_172c = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar7 = 1;
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0063e930;
    pcVar5 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar6 = 0xe4e;
  }
  else {
    iVar1 = json_object_object_get(param_1,"mac");
    if (iVar1 == 0) {
      uVar7 = 0x14;
      iVar1 = json_object_object_get(param_1,"model_id");
      if (iVar1 == 0) goto LAB_0063e930;
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar7 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar8 = json_object_get_double(iVar1);
          uVar7 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
        }
        else if (jcs_err_switch == 0) {
          uVar7 = 0xffffffff;
        }
        else {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "apupd_jcs_large_image_status_set",0xe69);
          uVar7 = 0xffffffff;
        }
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 6) {
        pcVar5 = (char *)json_object_get_string(iVar1);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
                 "apupd_jcs_large_image_status_set",0xe56);
        }
        pcVar5 = "";
      }
      strncpy(local_1728,pcVar5,0x13);
      local_1718 = local_1718 & 0xffffff00;
      sscanf(local_1728,"%hhx-%hhx-%hhx-%hhx-%hhx-%hhx",&local_1740,(int)&local_1740 + 1,
             (int)&local_1740 + 2,(int)&local_1740 + 3,&local_173c,(int)&local_173c + 1);
      iVar1 = apupd_db_wtp_get_by_mac(&local_1740,auStack_1554);
      if ((iVar1 != 0) || (iVar1 = FUN_00408430(&local_1740), uVar7 = local_1520, iVar1 != 0)) {
        uVar7 = 0x12;
        if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0063e930;
        pcVar5 = "[APUPD_ERROR]%32s() %05d: get wtp failed.\r\n";
        uVar6 = 0xe5b;
        goto LAB_0063ea8c;
      }
    }
    local_7d0 = uVar7;
    iVar1 = apupd_db_model_get_by_id(local_7d0,auStack_1028);
    if (iVar1 != 0) {
      uVar7 = 0x16;
      if (local_e87 != '\x01') goto LAB_0063e930;
      local_687 = 0;
      iVar1 = apupd_db_model_set(auStack_828,8);
      if (iVar1 == -1) {
        uVar7 = 1;
        if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0063e930;
        pcVar5 = "[APUPD_ERROR]%32s() %05d: set can_down_sub_image failed.\r\n";
        uVar6 = 0xe7c;
        goto LAB_0063ea8c;
      }
      uVar7 = 0;
      local_67c = apupd_image_size_get("/tmp/apupd.bin");
      if (local_67c == 0) goto LAB_0063e930;
      if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(local_67c), iVar1 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: file path %s\'s file_size is %d\r\n",
               "apupd_jcs_large_image_status_set",0xe83,"/tmp/apupd.bin",local_67c);
      }
      local_678 = FUN_00408450(local_67c,0xe84);
      iVar1 = local_67c;
      if (local_678 == 0) {
        uVar7 = 1;
        if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0063e930;
        pcVar5 = "[APUPD_ERROR]%32s() %05d: malloc failed.\r\n";
        uVar6 = 0xe87;
        goto LAB_0063ea8c;
      }
      iVar2 = apupd_image_file_read("/tmp/apupd.bin",local_678,local_67c);
      if (iVar1 != iVar2) {
        if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(local_678), iVar1 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: read file %s failed.\r\n",
                 "apupd_jcs_large_image_status_set",0xe8c,"/tmp/apupd.bin");
        }
        goto LAB_0063eba4;
      }
      apupd_md5_calc(local_678,local_67c,auStack_674,5);
      if ((local_eee == '\x01') && (local_e84 == 0)) {
        if ((local_ef0 == '\x01') || (local_ef0 == '\x03')) {
LAB_0063edcc:
          if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("[APUPD_ERROR]%32s() %05d: tmp_model.upd_type = %d\r\n",
                   "apupd_jcs_large_image_status_set",0xea8,local_83c);
          }
          if (local_83c - 2U < 2) {
            iVar1 = apupd_update_model_entry_get_by_id(local_fd0);
            iVar1 = FUN_004081b0(iVar1 + 0x14);
            while (iVar1 != 0) {
              iVar2 = FUN_00408680(iVar1);
              if (g_apupd_error == 0) {
                iVar1 = *(int *)(iVar1 + 0x24);
              }
              else {
                iVar4 = is_target_debug_ap();
                if (iVar4 == 0) {
                  iVar1 = *(int *)(iVar1 + 0x24);
                }
                else {
                  printf("[APUPD_ERROR]%32s() %05d: tmp_update_wtp:%p\r\n",
                         "apupd_jcs_large_image_status_set",0xeb3,iVar1 + -0xc);
                  iVar1 = *(int *)(iVar1 + 0x24);
                }
              }
              apmngr_db_entry_get_by_mac(iVar1 + 0x2e,auStack_1300);
              memset(acStack_15d4,0,0x80);
              memset(acStack_1654,0,0x80);
              memset(auStack_16d4,0,0x80);
              memset(auStack_1714,0,0x40);
              uVar3 = *(uint *)(iVar1 + 0x40);
              sprintf(acStack_15d4,"%d.%d.%d Build %02d%02d%02d Rel.%05d",
                      (uint)*(ushort *)(iVar1 + 0x38),(uint)*(ushort *)(iVar1 + 0x3a),
                      (uint)*(ushort *)(iVar1 + 0x3c),uVar3 >> 0x10,(uVar3 << 0x10) >> 0x18,
                      uVar3 & 0xff,*(undefined4 *)(iVar1 + 0x44));
              sprintf(acStack_1654,"%d.%d.%d Build %02d%02d%02d Rel.%05d",(uint)local_664,
                      (uint)local_662,(uint)local_660,local_65c >> 0x10,(local_65c << 0x10) >> 0x18,
                      local_65c & 0xff,local_658);
              sprintf(local_1728,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(iVar1 + 0x2e),
                      (uint)*(byte *)(iVar1 + 0x2f),(uint)*(byte *)(iVar1 + 0x30),
                      (uint)*(byte *)(iVar1 + 0x31),(uint)*(byte *)(iVar1 + 0x32),
                      (uint)*(byte *)(iVar1 + 0x33));
              FUN_00408190(*(undefined4 *)(iVar1 + 0x18),*(undefined4 *)(iVar1 + 0x1c),
                           *(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(iVar1 + 0x24),
                           *(undefined4 *)(iVar1 + 0x28),auStack_1714,0x40,"---");
              uVar7 = apmngr_db_product_type_str(local_ef0);
              pcVar5 = "---";
              if ((local_ef0 != '\x01') && (pcVar5 = acStack_1654, local_ef0 == '\x03')) {
                pcVar5 = "---";
              }
              loggerk_reg(0x54,0x380f,1,uVar7,1,auStack_12b2,1,auStack_1714,1,local_1728,1,
                          acStack_15d4,1,pcVar5,0);
              iVar1 = iVar2;
            }
          }
          goto LAB_0063ed24;
        }
        iVar1 = dkmgt_firmwareInfo_check(local_678,local_67c,auStack_14b4);
        if (iVar1 != 0) {
          if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(local_678), iVar1 == 0))
          goto LAB_0063eba4;
          pcVar5 = "[APUPD_ERROR]%32s() %05d: image file is wrong.\r\n";
          uVar7 = 0xe98;
          goto LAB_0063ed10;
        }
        apupd_cloud_image_dump(auStack_14b4);
        iVar1 = apupd_transfer_softver_str_to_softver_struct(auStack_14a0,&local_1738);
        if (iVar1 == 0) {
          apupd_get_cloud_image_info_from_firmware_info(auStack_14b4,auStack_654);
          memcpy(&local_664,&local_1738,0x10);
          goto LAB_0063edcc;
        }
        if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(local_678), iVar1 != 0)) {
          pcVar5 = 
          "[APUPD_ERROR]%32s() %05d: apupd_transfer_softver_str_to_softver_struct failed.\r\n";
          uVar7 = 0xe9f;
          goto LAB_0063ed10;
        }
      }
      else {
LAB_0063ed24:
        iVar1 = apupd_db_model_set(auStack_828,1);
        if (iVar1 == -1) {
          if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(local_678), iVar1 != 0)) {
            pcVar5 = "[APUPD_ERROR]%32s() %05d: set image failed.\r\n";
            uVar7 = 0xedf;
LAB_0063ed10:
            printf(pcVar5,"apupd_jcs_large_image_status_set",uVar7);
          }
        }
        else {
          uVar7 = 0;
          iVar1 = apupd_db_send_sub_image_info_to_update_wtp(local_7d0);
          if (iVar1 != -1) goto LAB_0063e930;
          if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(local_678), iVar1 != 0)) {
            pcVar5 = "[APUPD_ERROR]%32s() %05d: set sub image info failed.\r\n";
            uVar7 = 0xee5;
            goto LAB_0063ed10;
          }
        }
      }
LAB_0063eba4:
      uVar7 = 1;
      FUN_00407df0(local_678);
      goto LAB_0063e930;
    }
    uVar7 = 0x15;
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0063e930;
    pcVar5 = "[APUPD_ERROR]%32s() %05d: get model by id failed.\r\n";
    uVar6 = 0xe6e;
  }
LAB_0063ea8c:
  printf(pcVar5,"apupd_jcs_large_image_status_set",uVar6);
LAB_0063e930:
  uVar7 = json_object_new_int(uVar7);
  json_object_object_add(param_2,&DAT_00676a24,uVar7);
  return;
}

