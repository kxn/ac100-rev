// func _uac_wsta_jcs_del_by_mac @ 00630ce8 size=568

void _uac_wsta_jcs_del_by_mac(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 local_30;
  undefined2 local_2c;
  char local_28 [16];
  ushort local_18;
  
  local_28[0] = '\0';
  local_28[1] = '\0';
  local_28[2] = '\0';
  local_28[3] = '\0';
  local_28[4] = '\0';
  local_28[5] = '\0';
  local_28[6] = '\0';
  local_28[7] = '\0';
  local_28[8] = '\0';
  local_28[9] = '\0';
  local_28[10] = '\0';
  local_28[0xb] = '\0';
  local_28[0xc] = '\0';
  local_28[0xd] = '\0';
  local_28[0xe] = '\0';
  local_28[0xf] = '\0';
  local_18 = 0;
  local_30 = 0;
  local_2c = 0;
  if ((g_wsta_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wsta>[debug]%s(): %d  -> _uac_wsta_jcs_del_by_mac() begin.\r\n",
           "_uac_wsta_jcs_del_by_mac",0x48a);
  }
  iVar1 = json_object_object_get(param_1,"mac");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_uac_wsta_jcs_del_by_mac",0x48c);
    }
    pcVar4 = "";
  }
  else {
    pcVar4 = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_28,pcVar4,0x11);
  local_18 = local_18 & 0xff00;
  iVar1 = sscanf(local_28,"%hhx-%hhx-%hhx-%hhx-%hhx-%hhx",&local_30,(int)&local_30 + 1,
                 (int)&local_30 + 2,(int)&local_30 + 3,&local_2c,(int)&local_2c + 1);
  if (iVar1 == 6) {
    iVar1 = wsta_db_free_sta_by_mac_new(&local_30,_uac_wsta_del_cb,0);
    if (iVar1 == 0) {
      if ((g_wsta_debug == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00630dd0;
      pcVar4 = "<wsta>[debug]%s(): %d  -> wsta_db_free_sta_by_mac() success.\r\n";
      uVar3 = 0x49b;
    }
    else {
      if ((g_wsta_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00630dd0;
      pcVar4 = "<wsta>[error]%s(): %d  -> wsta_db_free_sta_by_mac() fail!\r\n";
      uVar3 = 0x497;
    }
    printf(pcVar4,"_uac_wsta_jcs_del_by_mac",uVar3);
  }
  else {
    iVar1 = 0;
    if ((g_wsta_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wsta>[error]%s(): %d  -> mac addr(%s) is illegal!\r\n","_uac_wsta_jcs_del_by_mac",
             0x491,local_28);
    }
  }
LAB_00630dd0:
  uVar3 = json_object_new_int(iVar1);
  json_object_object_add(param_2,&DAT_00676a24,uVar3);
  return;
}

