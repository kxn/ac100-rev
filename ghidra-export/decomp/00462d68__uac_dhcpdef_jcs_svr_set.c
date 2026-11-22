// func _uac_dhcpdef_jcs_svr_set @ 00462d68 size=396

void _uac_dhcpdef_jcs_svr_set(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  char *pcVar4;
  undefined8 uVar5;
  
  iVar1 = json_object_object_get(param_1,"operation");
  if (iVar1 == 0) {
    if (g_dhcpdef_error == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    pcVar4 = "operation";
    __format = "\x1b[31;49m[%s]<%s():%d> %s not found!\x1b[0m\r\n";
    uVar3 = 0x4b5;
    goto LAB_00462e30;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 3) {
    pcVar4 = (char *)json_object_get_int(iVar1);
LAB_00462eac:
    if (pcVar4 == (char *)0x0) {
      _uac_dhcpdef_jcs_svr_modify(param_1,param_2);
      return;
    }
  }
  else {
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar5 = json_object_get_double(iVar1);
      pcVar4 = (char *)__fixdfsi((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
      goto LAB_00462eac;
    }
    if (jcs_err_switch == 0) {
      pcVar4 = (char *)0xffffffff;
    }
    else {
      printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
             "_uac_dhcpdef_jcs_svr_set",0x4b6);
      pcVar4 = (char *)0xffffffff;
    }
  }
  if (g_dhcpdef_error == 0) {
    return;
  }
  iVar1 = is_target_debug_ap();
  if (iVar1 == 0) {
    return;
  }
  __format = "\x1b[31;49m[%s]<%s():%d> Invalid JCS SET operation [%d]!\x1b[0m\r\n";
  uVar3 = 0x4bf;
LAB_00462e30:
  printf(__format,"dhcp_defend","_uac_dhcpdef_jcs_svr_set",uVar3,pcVar4);
  return;
}

