// func _apmngr_jcs_ssid @ 00549a64 size=1172

void _apmngr_jcs_ssid(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  char *__src;
  undefined8 uVar7;
  undefined4 local_688;
  undefined4 local_684;
  undefined4 local_680;
  undefined4 local_67c;
  undefined4 local_678;
  undefined4 local_674;
  undefined4 local_670;
  undefined1 auStack_66c [16];
  undefined4 local_65c;
  char acStack_658 [127];
  undefined1 local_5d9;
  undefined1 auStack_5d8 [16];
  undefined2 local_5c8;
  undefined1 auStack_300 [20];
  int local_2ec;
  short local_2e8;
  undefined4 local_2c0;
  undefined1 auStack_e8 [192];
  
  memset(acStack_658,0,0x80);
  memset(auStack_300,0,0x2d8);
  memset(auStack_5d8,0,0x2d8);
  local_684 = 0;
  local_688 = 0;
  memset(&local_680,0,0x28);
  iVar1 = json_object_object_get(param_1,"start");
  if (iVar1 == 0) {
LAB_00549b20:
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_apmngr_jcs_ssid",0xba8);
    }
    local_680 = 0xffffffff;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_680 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 != 2) goto LAB_00549b20;
      uVar7 = json_object_get_double(iVar1);
      local_680 = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
    }
  }
  iVar1 = json_object_object_get(param_1,"size");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_67c = json_object_get_int(iVar1);
      goto LAB_00549b8c;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar7 = json_object_get_double(iVar1);
      local_67c = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
      goto LAB_00549b8c;
    }
  }
  if (jcs_err_switch == 0) {
    local_67c = 0xffffffff;
  }
  else {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "_apmngr_jcs_ssid",0xbab);
    local_67c = 0xffffffff;
  }
LAB_00549b8c:
  local_65c = json_object_new_array();
  iVar1 = json_object_object_get(param_1,"entry_id");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_ssid",0xbaf);
    }
    __src = "";
  }
  else {
    __src = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_658,__src,0x7f);
  local_5d9 = 0;
  uVar3 = atoi(acStack_658);
  iVar1 = apmngr_db_entry_get_by_id(uVar3 & 0xffff,auStack_300);
  if (iVar1 == 0) {
    iVar2 = 1;
    iVar1 = apdb_radio_count_by_id(local_2c0,auStack_e8);
    local_670 = local_2c0;
    memcpy(auStack_66c,auStack_e8,0x10);
    while (iVar2 <= iVar1) {
      uVar4 = rdmngr_db_generate_rd_id(uVar3 & 0xffff,iVar2);
      local_674 = 1;
      iVar5 = rdmngr_db_get_rd_status(uVar4);
      if (iVar5 == 0) {
        if ((apmngr_debug_switch != '\0') && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
          printf("[APMNGR_DEBUG]%s()/%d rd id %d is disabled\n","_apmngr_jcs_ssid",0xbc0,uVar4);
        }
        local_674 = 0;
      }
      if (local_2ec == 5) {
        if (local_2e8 != -1) {
          iVar5 = apmngr_db_entry_get_by_id(local_2e8,auStack_5d8);
          if (((iVar5 == 0) &&
              (iVar5 = rdmngr_db_get_freq_band_idx(uVar4,&local_684,&local_688), iVar5 == 0)) &&
             (iVar5 = rdmngr_db_get_closet_freq_band_rd_id(local_5c8,local_684,local_688),
             iVar5 != -1)) {
            iVar6 = rdmngr_db_get_rd_status(iVar5);
            if (iVar6 == 0) {
              if (apmngr_debug_switch == '\0') {
                local_674 = 0;
              }
              else {
                iVar6 = is_target_debug_ap();
                if (iVar6 != 0) {
                  printf("[APMNGR_DEBUG]%s()/%d rd id %d\'s parent rd id %d is disabled\n",
                         "_apmngr_jcs_ssid",0xbcc,uVar4,iVar5);
                }
                local_674 = 0;
              }
            }
            goto LAB_00549db0;
          }
        }
        if (apmngr_warning_switch == '\0') {
          iVar2 = iVar2 + 1;
        }
        else {
          iVar5 = is_target_debug_ap();
          if (iVar5 == 0) {
            iVar2 = iVar2 + 1;
          }
          else {
            printf("[APMNGR_WARNING]%s()/%d rdmngr_db_get_freq_band_idx or rdmngr_db_get_freq_band_rd_id failed for ap id %d and rd id %d\n"
                   ,"_apmngr_jcs_ssid",0xbc7,(int)local_2e8,uVar4);
            iVar2 = iVar2 + 1;
          }
        }
      }
      else {
LAB_00549db0:
        wserv_db_rd_for_each_wserv(uVar4,0,_apmngr_jcs_ssid_get,&local_680);
        iVar2 = iVar2 + 1;
      }
    }
    json_object_object_add(param_2,"ssid_entry",local_65c);
    uVar4 = json_object_new_int(local_678);
    json_object_object_add(param_2,"total_num",uVar4);
  }
  else {
    json_object_put(local_65c);
  }
  return;
}

