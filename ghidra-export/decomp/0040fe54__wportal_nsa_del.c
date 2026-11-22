// func _wportal_nsa_del @ 0040fe54 size=448

undefined4 _wportal_nsa_del(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char *__src;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined4 local_48;
  undefined2 local_44;
  char local_40 [16];
  ushort local_30;
  undefined4 local_2c;
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [12];
  
  local_40[0] = '\0';
  local_40[1] = '\0';
  local_40[2] = '\0';
  local_40[3] = '\0';
  local_40[4] = '\0';
  local_40[5] = '\0';
  local_40[6] = '\0';
  local_40[7] = '\0';
  local_40[8] = '\0';
  local_40[9] = '\0';
  local_40[10] = '\0';
  local_40[0xb] = '\0';
  local_40[0xc] = '\0';
  local_40[0xd] = '\0';
  local_40[0xe] = '\0';
  local_40[0xf] = '\0';
  local_30 = 0;
  local_48 = 0;
  local_44 = 0;
  iVar1 = json_object_object_get(param_1,"mac");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_nsa_del",0x110f);
    }
    __src = "";
  }
  else {
    __src = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_40,__src,0x11);
  local_30 = local_30 & 0xff00;
  if (local_40[0] != '\0') {
    sscanf(local_40,"%2X-%2X-%2X-%2X-%2X-%2X",&local_2c,auStack_28,auStack_24,auStack_20,auStack_1c,
           auStack_18);
    puVar3 = &local_2c;
    iVar1 = 0;
    do {
      puVar4 = (undefined1 *)((int)&local_48 + iVar1);
      uVar5 = *puVar3;
      iVar1 = iVar1 + 1;
      puVar3 = puVar3 + 1;
      *puVar4 = (char)uVar5;
    } while (iVar1 != 6);
  }
  wportal_db_nsa_del(&local_48);
  if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d wportal del nsa. send to datasync is sync:%d \n",
           "_wportal_nsa_del",0x111f,param_2);
  }
  if (((param_2 == 0) && (wportal_info_switch != 0)) && (iVar1 = is_target_debug_ap(), iVar1 != 0))
  {
    printf("[WPORTAL_INFO]%s()/%d dump nas list after del:\n\n","_wportal_nsa_del",0x1137);
  }
  return 0;
}

