// func _wportal_get_stream_load_by_mac @ 0040ce64 size=632

/* WARNING: Type propagation algorithm not settling */

undefined4 _wportal_get_stream_load_by_mac(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  char *__src;
  undefined1 *puVar5;
  undefined4 local_1d8;
  undefined2 local_1d4;
  char local_1d0 [16];
  uint local_1c0;
  undefined4 local_1bc [7];
  undefined1 auStack_1a0 [368];
  int local_30;
  uint local_2c;
  int local_28;
  uint local_24;
  
  local_1d0[0] = '\0';
  local_1d0[1] = '\0';
  local_1d0[2] = '\0';
  local_1d0[3] = '\0';
  local_1d0[4] = '\0';
  local_1d0[5] = '\0';
  local_1d0[6] = '\0';
  local_1d0[7] = '\0';
  local_1d0[8] = '\0';
  local_1d0[9] = '\0';
  local_1d0[10] = '\0';
  local_1d0[0xb] = '\0';
  local_1d0[0xc] = '\0';
  local_1d0[0xd] = '\0';
  local_1d0[0xe] = '\0';
  local_1d0[0xf] = '\0';
  local_1c0 = 0;
  local_1d8 = 0;
  local_1d4 = 0;
  local_1bc[0] = 0;
  local_1bc[1] = 0;
  local_1bc[2] = 0;
  local_1bc[3] = 0;
  local_1bc[4] = 0;
  local_1bc[5] = 0;
  memset(auStack_1a0,0,0x180);
  memset(auStack_1a0,0,0x180);
  iVar1 = json_object_object_get(param_1,"mac");
  if ((iVar1 == 0) || (iVar2 = json_object_get_type(iVar1), iVar2 != 6)) {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "_wportal_get_stream_load_by_mac",0x2225);
    }
    __src = "";
  }
  else {
    __src = (char *)json_object_get_string(iVar1);
  }
  strncpy(local_1d0,__src,0x13);
  local_1c0 = local_1c0 & 0xffffff00;
  if (local_1d0[0] != '\0') {
    sscanf(local_1d0,"%2X-%2X-%2X-%2X-%2X-%2X",local_1bc,local_1bc + 1,local_1bc + 2,local_1bc + 3,
           local_1bc + 4,local_1bc + 5);
    puVar4 = local_1bc;
    iVar1 = 0;
    do {
      puVar5 = (undefined1 *)((int)&local_1d8 + iVar1);
      uVar3 = *puVar4;
      iVar1 = iVar1 + 1;
      puVar4 = puVar4 + 1;
      *puVar5 = (char)uVar3;
    } while (iVar1 != 6);
  }
  iVar1 = wportal_db_aut_get(&local_1d8,auStack_1a0);
  if (iVar1 == 0) {
    uVar3 = json_object_new_int(local_2c << 10);
    json_object_object_add(param_2,"acctInputOctets",uVar3);
    uVar3 = json_object_new_int(local_30 << 10 | local_2c >> 0x16);
    json_object_object_add(param_2,"acctInputGigawords",uVar3);
    uVar3 = json_object_new_int(local_24 << 10);
    json_object_object_add(param_2,"acctOutputOctets",uVar3);
    uVar3 = json_object_new_int(local_28 << 10 | local_24 >> 0x16);
    json_object_object_add(param_2,"acctOutputGigawords",uVar3);
    uVar3 = json_object_new_int(0);
    json_object_object_add(param_2,&DAT_00676a24,uVar3);
    uVar3 = 0;
  }
  else {
    uVar3 = json_object_new_int(0xffffffff);
    json_object_object_add(param_2,&DAT_00676a24,uVar3);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

