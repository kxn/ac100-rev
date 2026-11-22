// func cloud_mngt_jcs_cloud_config_switch_set @ 0048c060 size=200

void cloud_mngt_jcs_cloud_config_switch_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar1 = json_object_object_get(param_1,"status");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
      goto LAB_0048c0bc;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar3 = json_object_get_double(iVar1);
      iVar1 = __fixdfsi((int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
      goto LAB_0048c0bc;
    }
  }
  iVar1 = -1;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "cloud_mngt_jcs_cloud_config_switch_set",0x1eac);
  }
LAB_0048c0bc:
  if (cloud_config_switch != (iVar1 != 0)) {
    cloud_config_switch = (uint)(iVar1 != 0);
  }
  return;
}

