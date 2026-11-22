// func _uac_dhcpdef_jcs_svr_modify @ 00462708 size=1632

void _uac_dhcpdef_jcs_svr_modify(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *__format;
  char *pcVar4;
  undefined8 uVar5;
  char acStack_1a0 [39];
  undefined1 local_179;
  char *local_178;
  char acStack_174 [150];
  undefined1 local_de;
  char local_dd;
  undefined1 auStack_dc [16];
  undefined1 auStack_cc [155];
  char local_31;
  undefined1 auStack_30 [20];
  
  memset(auStack_cc,0,0xac);
  memset(&local_178,0,0xac);
  memset(acStack_1a0,0,0x28);
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_uac_dhcpdef_jcs_svr_modify",0x46a,
           "_uac_dhcpdef_jcs_svr_modify");
  }
  memset(auStack_cc,0,0xac);
  memset(&local_178,0,0xac);
  iVar1 = json_object_object_get(param_1,"svr_id");
  if (iVar1 == 0) {
    pcVar4 = (char *)0xffffffff;
    if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00462810;
    pcVar4 = "svr_id";
    __format = "\x1b[31;49m[%s]<%s():%d> %s not found!\x1b[0m\r\n";
    uVar3 = 0x470;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_178 = (char *)json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar5 = json_object_get_double(iVar1);
        local_178 = (char *)__fixdfsi((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
      }
      else {
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_dhcpdef_jcs_svr_modify",0x471);
        }
        local_178 = (char *)0xffffffff;
      }
    }
    if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(local_178), iVar1 != 0)) {
      printf("[%s]<%s():%d> svr_id = %d.\r\n","dhcp_defend","_uac_dhcpdef_jcs_svr_modify",0x472,
             local_178);
    }
    iVar1 = dhcpdef_db_svr_entry_get(local_178,auStack_cc);
    if (iVar1 == 0) {
      iVar1 = json_object_object_get(param_1,"name");
      if (iVar1 == 0) {
        pcVar4 = (char *)0xffffffff;
        if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00462810;
        pcVar4 = "name";
        __format = "\x1b[31;49m[%s]<%s():%d> %s not found!\x1b[0m\r\n";
        uVar3 = 0x47b;
      }
      else {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          pcVar4 = (char *)json_object_get_string(iVar1);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_uac_dhcpdef_jcs_svr_modify",0x47c);
          }
          pcVar4 = "";
        }
        strncpy(acStack_174,pcVar4,0x96);
        local_de = 0;
        iVar1 = json_object_object_get(param_1,"addr_type");
        if (iVar1 == 0) {
          pcVar4 = (char *)0xffffffff;
          if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
          goto LAB_00462810;
          pcVar4 = "addr_type";
          __format = "\x1b[31;49m[%s]<%s():%d> %s not found!\x1b[0m\r\n";
          uVar3 = 0x47f;
        }
        else {
          iVar2 = json_object_get_type(iVar1);
          if (iVar2 == 3) {
            local_dd = json_object_get_int(iVar1);
          }
          else {
            iVar2 = json_object_get_type();
            if (iVar2 == 2) {
              uVar5 = json_object_get_double(iVar1);
              local_dd = __fixdfsi((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n"
                       ,"_uac_dhcpdef_jcs_svr_modify",0x480);
              }
              local_dd = -1;
            }
          }
          iVar1 = json_object_object_get(param_1,"svr_addr");
          if (iVar1 == 0) {
            pcVar4 = (char *)0xffffffff;
            if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
            goto LAB_00462810;
            pcVar4 = "svr_addr";
            __format = "\x1b[31;49m[%s]<%s():%d> %s not found!\x1b[0m\r\n";
            uVar3 = 0x483;
          }
          else {
            iVar2 = json_object_get_type(iVar1);
            if (iVar2 == 6) {
              pcVar4 = (char *)json_object_get_string(iVar1);
            }
            else {
              if (jcs_err_switch != 0) {
                printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                       ,"_uac_dhcpdef_jcs_svr_modify",0x484);
              }
              pcVar4 = "";
            }
            strncpy(acStack_1a0,pcVar4,0x27);
            local_179 = 0;
            if (local_dd != '\x01') {
              local_dd = dhcpdef_str2iptype(acStack_1a0);
            }
            dhcpdef_str2addr((int)local_dd,acStack_1a0,auStack_dc);
            iVar1 = memcmp(auStack_cc,&local_178,0xac);
            if (iVar1 != 0) {
              if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(&local_178), iVar1 != 0)) {
                printf("[%s]<%s():%d> modify DHCP server entry[%d].\r\n","dhcp_defend",
                       "_uac_dhcpdef_jcs_svr_modify",0x496,local_178);
              }
              iVar1 = dhcpdef_db_svr_entry_modify(&local_178);
              pcVar4 = (char *)0xffffffff;
              if ((iVar1 == 0) &&
                 ((local_31 != local_dd ||
                  (iVar1 = memcmp(auStack_30,auStack_dc,0x10), pcVar4 = local_178, iVar1 != 0)))) {
                dhcpdef_db_svr_all_bindap_foreach(local_178,_svr_modify_cb,0);
                pcVar4 = local_178;
              }
              goto LAB_00462810;
            }
            pcVar4 = (char *)0xffffffff;
            if ((g_dhcpdef_warn == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
            goto LAB_00462810;
            __format = "\x1b[33;49m[%s]<%s():%d> server entry[%d] no change.\x1b[0m\r\n";
            uVar3 = 0x48d;
            pcVar4 = local_178;
          }
        }
      }
    }
    else {
      pcVar4 = (char *)0xffffffff;
      if ((g_dhcpdef_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_00462810;
      __format = "\x1b[31;49m[%s]<%s():%d> can NOT get server entry by svr_id[%d]!\x1b[0m\r\n";
      uVar3 = 0x476;
      pcVar4 = local_178;
    }
  }
  printf(__format,"dhcp_defend","_uac_dhcpdef_jcs_svr_modify",uVar3,pcVar4);
  pcVar4 = (char *)0xffffffff;
LAB_00462810:
  uVar3 = json_object_new_int(pcVar4);
  json_object_object_add(param_2,"svr_id",uVar3);
  if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[%s]<%s():%d> json out obj: svr_id[%d]\r\n","dhcp_defend","_uac_dhcpdef_jcs_svr_modify",
           0x4a7,pcVar4);
  }
  return;
}

