// func _uac_wserv_ip_jcs_add @ 005e7074 size=936

/* WARNING: Type propagation algorithm not settling */

void _uac_wserv_ip_jcs_add(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  char *pcVar6;
  undefined8 uVar7;
  uint local_78 [7];
  undefined4 local_5c;
  char acStack_58 [63];
  undefined1 local_19;
  
  local_78[0] = 0;
  memset(acStack_58,0,0x40);
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_ip_jcs_add() begin.\r\n","_uac_wserv_ip_jcs_add",
           0xed3);
  }
  local_78[2] = 0;
  local_78[3] = 0;
  local_78[4] = 0;
  local_78[5] = 0;
  local_78[6] = 0;
  local_5c = 0;
  local_78[1] = 0xffffffff;
  iVar1 = json_object_object_get(param_1,"ip_addr");
  if (iVar1 == 0) {
    uVar3 = 0xffffffff;
    if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005e720c;
    uVar4 = 0xed9;
    pcVar6 = "ip_addr";
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar6 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_wserv_ip_jcs_add",0xeda);
      }
      pcVar6 = "";
    }
    strncpy(acStack_58,pcVar6,0x3f);
    local_19 = 0;
    FUN_0051a7a8(acStack_58,local_78 + 2);
    iVar1 = json_object_object_get(param_1,"relay");
    if (iVar1 == 0) {
      uVar3 = 0xffffffff;
      if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005e720c;
      uVar4 = 0xede;
      pcVar6 = "relay";
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (iVar2 == 3) {
        uVar5 = json_object_get_int(iVar1);
      }
      else {
        iVar2 = json_object_get_type();
        if (iVar2 == 2) {
          uVar7 = json_object_get_double(iVar1);
          uVar5 = __fixdfsi((int)((ulonglong)uVar7 >> 0x20),(int)uVar7);
        }
        else {
          uVar5 = 0xff;
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_uac_wserv_ip_jcs_add",0xedf);
            uVar5 = 0xff;
          }
        }
      }
      local_5c = CONCAT13(uVar5,local_5c._1_3_);
      iVar1 = json_object_object_get(param_1,"enable");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          pcVar6 = (char *)json_object_get_string(iVar1);
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n"
                   ,"_uac_wserv_ip_jcs_add",0xee4);
          }
          pcVar6 = "";
        }
        strncpy((char *)local_78,pcVar6,3);
        local_78[0] = local_78[0] & 0xffffff00;
        iVar1 = strcmp((char *)local_78,"on");
        if (iVar1 == 0) {
          local_5c._1_3_ = CONCAT12(1,local_5c._2_2_);
        }
        else {
          local_5c._1_3_ = (uint3)local_5c._2_2_;
        }
        uVar3 = wserv_db_ip_add(local_78 + 1);
        uac_wservice_igmp_white_list_change();
        goto LAB_005e720c;
      }
      uVar3 = 0xffffffff;
      if ((g_wserv_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_005e720c;
      uVar4 = 0xee3;
      pcVar6 = "enable";
    }
  }
  uVar3 = 0xffffffff;
  printf("<wserv>[error]%s(): %d  -> %s not found!\r\n","_uac_wserv_ip_jcs_add",uVar4,pcVar6);
LAB_005e720c:
  uVar4 = json_object_new_int(uVar3);
  json_object_object_add(param_2,"id",uVar4);
  if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> _uac_wserv_ip_jcs_add() finish, id=%d.\r\n",
           "_uac_wserv_ip_jcs_add",0xef3,uVar3);
  }
  return;
}

