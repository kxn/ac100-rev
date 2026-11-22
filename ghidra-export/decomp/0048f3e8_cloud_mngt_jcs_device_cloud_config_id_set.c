// func cloud_mngt_jcs_device_cloud_config_id_set @ 0048f3e8 size=364

void cloud_mngt_jcs_device_cloud_config_id_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  char *__src;
  undefined8 uVar4;
  char acStack_58 [64];
  undefined1 local_18;
  
  memset(acStack_58,0,0x41);
  iVar1 = json_object_object_get(param_1,"id");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar3 = json_object_get_int(iVar1);
      goto LAB_0048f464;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar4 = json_object_get_double(iVar1);
      uVar3 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
      goto LAB_0048f464;
    }
  }
  uVar3 = 0xffff;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "cloud_mngt_jcs_device_cloud_config_id_set",0x1e9f);
  }
LAB_0048f464:
  iVar1 = json_object_object_get(param_1,"cloud_config_id");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "cloud_mngt_jcs_device_cloud_config_id_set",0x1ea1);
    }
    __src = "";
  }
  else {
    __src = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_58,__src,0x40);
  local_18 = 0;
  apmngr_db_entry_cloud_config_id_set(uVar3,acStack_58);
  return;
}

