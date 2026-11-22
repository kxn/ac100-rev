// func _uac_dhcpdef_jcs_svr_add @ 00462ef4 size=1044

void _uac_dhcpdef_jcs_svr_add(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *__format;
  char *pcVar4;
  undefined8 uVar5;
  char *pcVar6;
  char acStack_f0 [39];
  undefined1 local_c9;
  undefined4 local_c8;
  char acStack_c4 [150];
  undefined1 local_2e;
  char local_2d;
  undefined1 auStack_2c [20];
  
  memset(&local_c8,0,0xac);
  memset(acStack_f0,0,0x28);
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_uac_dhcpdef_jcs_svr_add",0x350,
           "_uac_dhcpdef_jcs_svr_add");
  }
  memset(&local_c8,0,0xac);
  local_c8 = 0xffffffff;
  iVar1 = json_object_object_get(param_1,"name");
  if (iVar1 == 0) {
    pcVar4 = (char *)0xffffffff;
    if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0046309c;
    pcVar6 = "name";
    __format = "\x1b[31;49m[%s]<%s():%d> %s not found!\x1b[0m\r\n";
    uVar3 = 0x357;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar4 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_dhcpdef_jcs_svr_add",0x358);
      }
      pcVar4 = "";
    }
    strncpy(acStack_c4,pcVar4,0x96);
    local_2e = 0;
    iVar1 = json_object_object_get(param_1,"addr_type");
    if (iVar1 == 0) {
      pcVar4 = (char *)0xffffffff;
      if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0046309c;
      pcVar6 = "addr_type";
      __format = "\x1b[31;49m[%s]<%s():%d> %s not found!\x1b[0m\r\n";
      uVar3 = 0x35b;
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        local_2d = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar5 = json_object_get_double(iVar1);
          local_2d = __fixdfsi((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_uac_dhcpdef_jcs_svr_add",0x35c);
          }
          local_2d = -1;
        }
      }
      iVar1 = json_object_object_get(param_1,"svr_addr");
      if (iVar1 == 0) {
        pcVar4 = (char *)0xffffffff;
        if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0046309c;
        pcVar6 = "svr_addr";
        __format = "\x1b[31;49m[%s]<%s():%d> %s not found!\x1b[0m\r\n";
        uVar3 = 0x35f;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          pcVar4 = (char *)json_object_get_string(iVar1);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_uac_dhcpdef_jcs_svr_add",0x360);
          }
          pcVar4 = "";
        }
        strncpy(acStack_f0,pcVar4,0x27);
        local_c9 = 0;
        if (local_2d != '\x01') {
          local_2d = dhcpdef_str2iptype(acStack_f0);
        }
        dhcpdef_str2addr((int)local_2d,acStack_f0,auStack_2c);
        pcVar4 = (char *)dhcpdef_db_svr_entry_add(&local_c8);
        if ((g_dhcpdef_info == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0046309c;
        __format = "[%s]<%s():%d> Get svr_id[%d] from ID allocator.\r\n";
        uVar3 = 0x36e;
        pcVar6 = pcVar4;
      }
    }
  }
  printf(__format,"dhcp_defend","_uac_dhcpdef_jcs_svr_add",uVar3,pcVar6);
LAB_0046309c:
  uVar3 = json_object_new_int(pcVar4);
  json_object_object_add(param_2,"svr_id",uVar3);
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> json out obj: svr_id[%d]\r\n","dhcp_defend","_uac_dhcpdef_jcs_svr_add",
           0x373,pcVar4);
  }
  return;
}

