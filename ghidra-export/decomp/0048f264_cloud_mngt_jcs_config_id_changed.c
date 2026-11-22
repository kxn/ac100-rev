// func cloud_mngt_jcs_config_id_changed @ 0048f264 size=200

void cloud_mngt_jcs_config_id_changed(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *__src;
  char local_90 [128];
  undefined1 local_10;
  
  memset(local_90,0,0x81);
  iVar1 = json_object_object_get(param_1,"new_config_id");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      __src = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "cloud_mngt_jcs_config_id_changed",0x1edc);
      }
      __src = "";
    }
    strncpy(local_90,__src,0x80);
    local_10 = 0;
  }
  if (local_90[0] != '\0') {
    FUN_004083e0(local_90);
  }
  return;
}

