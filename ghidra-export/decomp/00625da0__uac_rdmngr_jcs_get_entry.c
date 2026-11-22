// func _uac_rdmngr_jcs_get_entry @ 00625da0 size=824

void _uac_rdmngr_jcs_get_entry(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar4;
  int iVar3;
  char *__format;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined1 auStack_348 [88];
  undefined1 auStack_2f0 [732];
  
  memset(auStack_348,0,0x54);
  memset(auStack_2f0,0,0x2d8);
  if ((rdmngr_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_jcs_get_entry() begin.\n","_uac_rdmngr_jcs_get_entry",
           0x48c);
  }
  iVar1 = json_object_object_get(param_1,"rf_id");
  if (iVar1 == 0) {
    if (rdmngr_err_switch == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[RDMNGR_ERROR]%s()/%d %s not found!\n","_uac_rdmngr_jcs_get_entry",0x48f,"rf_id");
    return;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 3) {
    uVar5 = json_object_get_int(iVar1);
  }
  else {
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar6 = json_object_get_double(iVar1);
      uVar5 = __fixdfsi((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
    }
    else {
      uVar5 = 0xffffffff;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_uac_rdmngr_jcs_get_entry",0x490);
      }
    }
  }
  iVar1 = json_object_new_array();
  if (iVar1 == 0) {
    if (rdmngr_err_switch == 0) {
      return;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return;
    }
    printf("[RDMNGR_ERROR]%s()/%d JSON_ARRAY_CREATE() fail!\n","_uac_rdmngr_jcs_get_entry",0x495);
    return;
  }
  uVar4 = rdmngr_db_generate_ap_id(uVar5);
  iVar2 = apmngr_db_entry_get_by_id(uVar4,auStack_2f0);
  if ((iVar2 == 0) && (iVar2 = rdmngr_db_rd_entry_get(uVar5,auStack_348), iVar2 == 0)) {
    _uac_rdmngr_get_rd_entry(auStack_2f0,auStack_348,iVar1);
    iVar2 = json_object_to_json_string_ext(iVar1,0);
    if (iVar2 == 0) {
      if ((rdmngr_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00625e78;
      __format = "[RDMNGR_ERROR]%s()/%d JSON_STRING_FROM_OBJ fail!\n";
      uVar5 = 0x4a4;
    }
    else {
      if ((rdmngr_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d entry string:%s\n","_uac_rdmngr_jcs_get_entry",0x4a7,iVar2);
      }
      uVar5 = json_object_new_string(iVar2);
      json_object_object_add(param_2,"rd_entry",uVar5);
      uVar5 = json_object_new_int(0);
      json_object_object_add(param_2,&DAT_00676a24,uVar5);
      if ((rdmngr_debug_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
      goto LAB_00625e78;
      __format = "[RDMNGR_DEBUG]%s()/%d _uac_rdmngr_jcs_get_entry() success.\n";
      uVar5 = 0x4aa;
    }
  }
  else {
    if ((rdmngr_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00625e78;
    __format = "[RDMNGR_ERROR]%s()/%d apmngr_db_entry_get_by_id() failed.\n";
    uVar5 = 0x49c;
  }
  printf(__format,"_uac_rdmngr_jcs_get_entry",uVar5);
LAB_00625e78:
  json_object_put(iVar1);
  return;
}

