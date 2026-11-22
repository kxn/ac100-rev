// func _apmngr_jcs_callback_datasync @ 005484d0 size=276

void _apmngr_jcs_callback_datasync(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  void *__src;
  undefined8 uVar4;
  void *local_18;
  size_t local_14;
  
  local_18 = (void *)0x0;
  local_14 = 0;
  iVar1 = json_object_object_get(param_1,&DAT_006cd710);
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_14 = json_object_get_int(iVar1);
      goto LAB_00548540;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar4 = json_object_get_double(iVar1);
      local_14 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
      goto LAB_00548540;
    }
  }
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "_apmngr_jcs_callback_datasync",0xa0f);
  }
  local_14 = 0xffffffff;
LAB_00548540:
  local_18 = (void *)FUN_00408450(local_14,0xa10);
  uVar3 = json_object_object_get(param_1,"data_msg");
  __src = (void *)json_object_get_string(uVar3);
  memcpy(local_18,__src,local_14);
  apmngr_db_datasync_handle(&local_18);
  FUN_00407df0(local_18);
  return;
}

