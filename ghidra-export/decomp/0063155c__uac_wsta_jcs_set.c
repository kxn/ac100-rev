// func _uac_wsta_jcs_set @ 0063155c size=372

void _uac_wsta_jcs_set(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  if ((g_wsta_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wsta>[debug]%s(): %d  -> _uac_wsta_jcs_set() begin.\r\n","_uac_wsta_jcs_set",0x459);
  }
  iVar1 = json_object_object_get(param_1,"overload_threshold");
  if ((iVar1 != 0) &&
     ((iVar2 = json_object_get_type(iVar1), iVar2 == 3 ||
      (iVar2 = json_object_get_type(iVar1), iVar2 == 2)))) {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      uVar3 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar4 = json_object_get_double(iVar1);
        uVar3 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
      }
      else {
        uVar3 = 0xffffffff;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_wsta_jcs_set",0x45d);
        }
      }
    }
    wsta_db_overload_threshold_set(uVar3);
  }
  if ((g_wsta_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wsta>[debug]%s(): %d  -> _uac_wsta_jcs_set() success.\r\n","_uac_wsta_jcs_set",0x461);
    return;
  }
  return;
}

