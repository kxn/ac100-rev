// func _apdb_jcs_callback_get_aplist @ 005faaa0 size=440

void _apdb_jcs_callback_get_aplist(undefined4 param_1,undefined4 param_2)

{
  char *__s;
  FILE *__s_00;
  size_t sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char acStack_98 [132];
  
  memset(acStack_98,0,0x80);
  FUN_004082d0(l_apdb_mutex,0xffffffff);
  __s = (char *)cJSON_Print(nego_ap_root);
  file_id = file_id + 1;
  FUN_00407f30(l_apdb_mutex);
  if (__s == (char *)0x0) {
    uVar3 = 0xffffffff;
    __s_00 = (FILE *)0x0;
  }
  else {
    snprintf(acStack_98,0x80,"%s_%d","/tmp/apdb_ap_list_temp",file_id);
    __s_00 = fopen(acStack_98,"w+");
    if (__s_00 == (FILE *)0x0) {
      uVar3 = 0xffffffff;
      if (apdb_err_switch != 0) {
        printf("[APDB_ERROR]%s()/line %d : open get file[%s] fail!\n",
               "_apdb_jcs_callback_get_aplist",0x142c,acStack_98);
      }
    }
    else {
      sVar1 = strlen(__s);
      sVar1 = fwrite(__s,sVar1,1,__s_00);
      if (sVar1 == 1) {
        uVar3 = 0;
        uVar2 = json_object_new_string(acStack_98);
        json_object_object_add(param_2,"file_name",uVar2);
      }
      else {
        uVar3 = 0xffffffff;
        if (apdb_err_switch != 0) {
          printf("[APDB_ERROR]%s()/line %d : write result to file fail!\n",
                 "_apdb_jcs_callback_get_aplist",0x1435);
        }
      }
    }
  }
  uVar3 = json_object_new_int(uVar3);
  json_object_object_add(param_2,&DAT_00676a24,uVar3);
  if (__s != (char *)0x0) {
    free(__s);
  }
  if (__s_00 != (FILE *)0x0) {
    fclose(__s_00);
  }
  return;
}

