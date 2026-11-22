// func _uac_wsta_jcs_del @ 0063135c size=512

void _uac_wsta_jcs_del(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *__format;
  undefined8 uVar4;
  
  if ((g_wsta_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wsta>[debug]%s(): %d  -> _uac_wsta_jcs_del() begin.\r\n","_uac_wsta_jcs_del",0x46d);
  }
  iVar1 = json_object_object_get(param_1,"entry_id");
  if (iVar1 == 0) {
    iVar1 = -1;
    if ((g_wsta_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wsta>[error]%s(): %d  -> %s not found!\r\n","_uac_wsta_jcs_del",0x46f,"entry_id");
    }
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar2 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar4 = json_object_get_double(iVar1);
        iVar2 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
      }
      else {
        iVar2 = -1;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_wsta_jcs_del",0x470);
        }
      }
    }
    iVar1 = wsta_db_free_sta(iVar2,_uac_wsta_del_cb,0);
    if (iVar1 == 0) {
      iVar1 = iVar2;
      if ((g_wsta_debug == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00631408;
      __format = "<wsta>[debug]%s(): %d  -> _uac_wsta_jcs_del() success.\r\n";
      uVar3 = 0x479;
    }
    else {
      if ((g_wsta_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00631408;
      __format = "<wsta>[error]%s(): %d  -> wsta_db_free_sta() fail!\r\n";
      uVar3 = 0x475;
    }
    printf(__format,"_uac_wsta_jcs_del",uVar3);
  }
LAB_00631408:
  uVar3 = json_object_new_int(iVar1);
  json_object_object_add(param_2,"entry_id",uVar3);
  return;
}

