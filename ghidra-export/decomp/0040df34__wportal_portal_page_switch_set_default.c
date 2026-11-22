// func _wportal_portal_page_switch_set_default @ 0040df34 size=260

void _wportal_portal_page_switch_set_default(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined1 auStack_178 [360];
  undefined4 local_10;
  
  iVar1 = json_object_object_get(param_1,"serv_id");
  memset(auStack_178,0,0x16c);
  if (iVar1 != 0) {
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
                 "_wportal_portal_page_switch_set_default",0x1fdc);
        }
      }
    }
    iVar1 = wportal_db_ssid_rdt_get(uVar3,auStack_178);
    if (iVar1 == 0) {
      local_10 = 1;
      wserv_db_entry_set_ssid_portal_switch(uVar3 & 0xff,1);
      wserv_db_entry_for_each_rd(uVar3,_wportal_wserv_update_portal_page_switch,auStack_178);
    }
  }
  return;
}

