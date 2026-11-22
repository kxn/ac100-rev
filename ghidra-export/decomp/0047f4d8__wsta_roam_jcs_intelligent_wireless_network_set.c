// func _wsta_roam_jcs_intelligent_wireless_network_set @ 0047f4d8 size=216

void _wsta_roam_jcs_intelligent_wireless_network_set(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  iVar1 = json_object_object_get(param_1,"wireless_network_mode");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar3 = json_object_get_int(iVar1);
      goto LAB_0047f550;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar4 = json_object_get_double(iVar1);
      uVar3 = __fixunsdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
      goto LAB_0047f550;
    }
  }
  uVar3 = 0xffffffff;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "_wsta_roam_jcs_intelligent_wireless_network_set",0xe6);
  }
LAB_0047f550:
  uVar3 = wsta_intelligent_roam_manual_change_wireless_network_mode(uVar3);
  uVar3 = json_object_new_int(uVar3);
  json_object_object_add(param_2,"result",uVar3);
  return;
}

