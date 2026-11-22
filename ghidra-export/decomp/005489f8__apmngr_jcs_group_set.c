// func _apmngr_jcs_group_set @ 005489f8 size=364

void _apmngr_jcs_group_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  char *__src;
  undefined8 uVar4;
  char acStack_90 [127];
  undefined1 local_11;
  
  memset(acStack_90,0,0x80);
  iVar1 = json_object_object_get(param_1,"group_id");
  if (iVar1 != 0) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar3 = json_object_get_int(iVar1);
      goto LAB_00548a74;
    }
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar4 = json_object_get_double(iVar1);
      uVar3 = __fixunsdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
      goto LAB_00548a74;
    }
  }
  uVar3 = 0xffff;
  if (jcs_err_switch != 0) {
    printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
           "_apmngr_jcs_group_set",0x2fb);
  }
LAB_00548a74:
  iVar1 = json_object_object_get(param_1,"name");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_apmngr_jcs_group_set",0x2fe);
    }
    __src = "";
  }
  else {
    __src = (char *)json_object_get_string(iVar1);
  }
  strncpy(acStack_90,__src,0x7f);
  local_11 = 0;
  apmngr_db_group_set(uVar3,acStack_90);
  return;
}

