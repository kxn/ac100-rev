// func _wportal_get_ssid_by_serv_id @ 0040e038 size=552

undefined4 _wportal_get_ssid_by_serv_id(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *__format;
  undefined8 uVar4;
  undefined1 auStack_218 [304];
  undefined1 auStack_e8 [216];
  
  iVar1 = json_object_object_get(param_1,"serv_id");
  if (iVar1 == 0) {
    uVar3 = 0xffffffff;
    if (wportal_debug_switch == 0) goto LAB_0040e0e8;
    iVar1 = is_target_debug_ap(0xffffffff);
    if (iVar1 == 0) {
      uVar3 = 0xffffffff;
      goto LAB_0040e0e8;
    }
    __format = "[WPORTAL_DBG]%s()/%d Get serv_id fail\n\n";
    uVar3 = 0x22c9;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      iVar1 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar4 = json_object_get_double(iVar1);
        iVar1 = __fixdfsi((int)((ulonglong)uVar4 >> 0x20),(int)uVar4);
      }
      else {
        iVar1 = -1;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_wportal_get_ssid_by_serv_id",0x22ce);
        }
      }
    }
    if ((wportal_info_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d wserv_id is %d\n\n","_wportal_get_ssid_by_serv_id",0x22d0,iVar1)
      ;
    }
    if (iVar1 == -1) {
      uVar3 = 0xffffffff;
      if (wportal_debug_switch == 0) goto LAB_0040e0e8;
      iVar1 = is_target_debug_ap(0xffffffff);
      if (iVar1 == 0) {
        uVar3 = 0xffffffff;
        goto LAB_0040e0e8;
      }
      __format = "[WPORTAL_DBG]%s()/%d Get wserv_id fail\n\n";
      uVar3 = 0x22d3;
    }
    else {
      memset(auStack_218,0,0x205);
      iVar1 = uac_wservice_get_entry_by_id(iVar1,auStack_218);
      if (iVar1 == 0) {
        uVar3 = json_object_new_string(auStack_e8);
        json_object_object_add(param_2,"ssid",uVar3);
        uVar3 = 0;
        goto LAB_0040e0e8;
      }
      uVar3 = 0xffffffff;
      if (wportal_debug_switch == 0) goto LAB_0040e0e8;
      iVar1 = is_target_debug_ap(0xffffffff);
      if (iVar1 == 0) {
        uVar3 = 0xffffffff;
        goto LAB_0040e0e8;
      }
      __format = "[WPORTAL_DBG]%s()/%d wservice_get_entry fail\n\n";
      uVar3 = 0x22dc;
    }
  }
  printf(__format,"_wportal_get_ssid_by_serv_id",uVar3);
  uVar3 = 0xffffffff;
LAB_0040e0e8:
  uVar3 = json_object_new_int(uVar3);
  json_object_object_add(param_2,&DAT_00676a24,uVar3);
  return 0;
}

