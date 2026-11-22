// func _apmngr_jcs_ap_telnet_evt @ 00549ef8 size=856

void _apmngr_jcs_ap_telnet_evt(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  char *__src;
  undefined4 uVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined8 uVar8;
  char acStack_890 [127];
  undefined1 local_811;
  undefined2 local_810 [1014];
  
  iVar6 = 0;
  memset(acStack_890,0,0x80);
  memset(local_810,0,0x7e4);
  iVar1 = json_object_object_get(param_1,"entry_id");
  if (((iVar1 != 0) && (iVar2 = json_object_get_type(iVar1), iVar2 == 5)) &&
     (iVar2 = json_object_array_length(iVar1), 0 < iVar2)) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 5) {
      puVar7 = local_810;
      for (; iVar2 = json_object_array_length(iVar1), iVar6 < iVar2; iVar6 = iVar6 + 1) {
        if (iVar6 == 0x3f2) {
          iVar6 = 0x3f2;
          break;
        }
        iVar2 = json_object_array_get_idx(iVar1,iVar6);
        if (iVar2 == 0) {
LAB_0054a1d0:
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                   "_apmngr_jcs_ap_telnet_evt",0xa54);
          }
          *puVar7 = 0xffff;
        }
        else {
          iVar3 = json_object_get_type(iVar2);
          if (iVar3 == 3) {
            uVar4 = json_object_get_int(iVar2);
            *puVar7 = uVar4;
          }
          else {
            iVar3 = json_object_get_type();
            if (iVar3 != 2) goto LAB_0054a1d0;
            uVar8 = json_object_get_double(iVar2);
            uVar4 = __fixunsdfsi((int)((ulonglong)uVar8 >> 0x20),(int)uVar8);
            *puVar7 = uVar4;
          }
        }
        puVar7 = puVar7 + 1;
      }
    }
    else {
      iVar2 = json_object_get_type(iVar1);
      if (((iVar2 != 4) || (iVar1 = json_object_object_length(iVar1), iVar1 != 0)) &&
         (iVar6 = 0, jcs_err_switch != 0)) {
        printf("[JCS_ERR]%s()/%d Warning: Get intArray with error obj or value type is unmatch.\n",
               "_apmngr_jcs_ap_telnet_evt",0xa54);
      }
    }
  }
  iVar1 = json_object_object_get(param_1,&DAT_006cdd1c);
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_ap_telnet_evt",0xa58);
    }
    __src = "";
  }
  else {
    __src = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_890,__src,0x7f);
  local_811 = 0;
  iVar1 = strncmp(acStack_890,"on",0x80);
  if (iVar1 == 0) {
    iVar6 = apmngr_hdap_insert_peer_id(local_810,iVar6);
    if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(local_810), iVar1 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d receive telnet evt on\n","_apmngr_jcs_ap_telnet_evt",0xa5f);
    }
    uVar5 = 1;
  }
  else {
    iVar1 = strncmp(acStack_890,"off",0x80);
    if (iVar1 != 0) {
      return;
    }
    if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(local_810), iVar1 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d receive telnet evt off\n","_apmngr_jcs_ap_telnet_evt",0xa64);
    }
    uVar5 = 0;
  }
  apmngr_ap_telnet_status_update(local_810,iVar6,uVar5);
  return;
}

