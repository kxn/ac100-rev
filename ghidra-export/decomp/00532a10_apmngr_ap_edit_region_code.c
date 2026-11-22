// func apmngr_ap_edit_region_code @ 00532a10 size=412

undefined4 apmngr_ap_edit_region_code(uint param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char *__nptr;
  undefined4 uVar3;
  undefined1 auStack_2e8 [721];
  undefined1 local_17;
  
  param_1 = param_1 & 0xffff;
  memset(auStack_2e8,0,0x2d8);
  iVar1 = apmngr_db_entry_get_by_id(param_1,auStack_2e8);
  if (iVar1 == 0) {
    iVar1 = apmngr_db_get_cur_using_region_code(param_1);
    uVar3 = 0;
    if (iVar1 != 0xff) {
      iVar1 = json_object_object_get(param_2,"region_code");
      if (iVar1 != 0) {
        iVar2 = json_object_get_type(iVar1);
        if (iVar2 == 6) {
          __nptr = (char *)json_object_get_string(iVar1);
          iVar1 = atoi(__nptr);
          local_17 = (undefined1)iVar1;
        }
        else {
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
                   "apmngr_ap_edit_region_code",0x7e8);
          }
          if (jcs_err_switch != 0) {
            printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
                   "apmngr_ap_edit_region_code",0x7e8);
          }
          local_17 = 0xff;
        }
      }
      uVar3 = 0;
      iVar1 = apmngr_set_ap_cur_using_region_code(param_1,local_17);
      if (((iVar1 != 0) && (uVar3 = 0xffffffff, apmngr_err_switch != '\0')) &&
         (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APMNGR_ERROR]%s()/%d set apmngr set ap cur region code failed!\n",
               "apmngr_ap_edit_region_code",0x7ec);
      }
    }
  }
  else {
    uVar3 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d get ap_entry failed! id=%d\n","apmngr_ap_edit_region_code",0x7e1
             ,param_1);
    }
  }
  return uVar3;
}

