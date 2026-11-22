// func cloud_mngt_jcs_clear_cloud_config_id @ 0048f32c size=188

void cloud_mngt_jcs_clear_cloud_config_id(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *__src;
  char acStack_50 [64];
  undefined1 local_10;
  
  memset(acStack_50,0,0x41);
  iVar1 = json_object_object_get(param_1,"cloud_config_id");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      __src = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "cloud_mngt_jcs_clear_cloud_config_id",0x1ebb);
      }
      __src = "";
    }
    strncpy(acStack_50,__src,0x40);
    local_10 = 0;
  }
  apmngr_db_entry_cloud_config_id_batch_set(acStack_50);
  return;
}

