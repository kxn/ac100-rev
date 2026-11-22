// func _wportal_nonsense_auth @ 00421da4 size=1284

undefined4 _wportal_nonsense_auth(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  char local_68 [20];
  char local_54 [20];
  undefined1 auStack_40 [40];
  
  local_54[0] = '\0';
  local_54[1] = '\0';
  local_54[2] = '\0';
  local_54[3] = '\0';
  local_54[4] = '\0';
  local_54[5] = '\0';
  local_54[6] = '\0';
  local_54[7] = '\0';
  local_54[8] = '\0';
  local_54[9] = '\0';
  local_54[10] = '\0';
  local_54[0xb] = '\0';
  local_54[0xc] = '\0';
  local_54[0xd] = '\0';
  local_54[0xe] = '\0';
  local_54[0xf] = '\0';
  local_54[0x10] = '\0';
  local_54[0x11] = '\0';
  local_68[0] = '\0';
  local_68[1] = '\0';
  local_68[2] = '\0';
  local_68[3] = '\0';
  local_68[4] = '\0';
  local_68[5] = '\0';
  local_68[6] = '\0';
  local_68[7] = '\0';
  local_68[8] = '\0';
  local_68[9] = '\0';
  local_68[10] = '\0';
  local_68[0xb] = '\0';
  local_68[0xc] = '\0';
  local_68[0xd] = '\0';
  local_68[0xe] = '\0';
  local_68[0xf] = '\0';
  local_68[0x10] = '\0';
  local_68[0x11] = '\0';
  memset(auStack_40,0,0x28);
  if ((param_1 == 0) || (param_2 == 0)) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[WPORTAL_ERR]%s()/%d Para is invalid.\n";
    uVar3 = 0x696;
  }
  else {
    iVar2 = json_object_new_object();
    if (iVar2 != 0) {
      snprintf(local_54,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_1 + 0x74),
               (uint)*(byte *)(param_1 + 0x75),(uint)*(byte *)(param_1 + 0x76),
               (uint)*(byte *)(param_1 + 0x77),(uint)*(byte *)(param_1 + 0x78),
               (uint)*(byte *)(param_1 + 0x79));
      snprintf(local_68,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*(byte *)(param_2 + 0x48),
               (uint)*(byte *)(param_2 + 0x49),(uint)*(byte *)(param_2 + 0x4a),
               (uint)*(byte *)(param_2 + 0x4b),(uint)*(byte *)(param_2 + 0x4c),
               (uint)*(byte *)(param_2 + 0x4d));
      FUN_00408190(*(undefined4 *)(param_2 + 0x26c),*(undefined4 *)(param_2 + 0x270),
                   *(undefined4 *)(param_2 + 0x274),*(undefined4 *)(param_2 + 0x278),
                   *(undefined4 *)(param_2 + 0x27c),auStack_40,0x28,"0.0.0.0");
      uVar3 = json_object_new_int(6);
      json_object_object_add(iVar2,"type",uVar3);
      if (g_portal_auth_mode == 1) {
        uVar3 = json_object_new_int(*(undefined4 *)(param_1 + 0x128));
        pcVar5 = "vlan_id";
      }
      else {
        uVar3 = json_object_new_int(*(undefined4 *)(param_1 + 0x128));
        pcVar5 = "serv_id";
      }
      json_object_object_add(iVar2,pcVar5,uVar3);
      uVar3 = json_object_new_string(local_54);
      json_object_object_add(iVar2,"mac",uVar3);
      uVar3 = json_object_new_string(param_1 + 0xdf);
      json_object_object_add(iVar2,&DAT_00677c24,uVar3);
      uVar3 = json_object_new_string(local_68);
      json_object_object_add(iVar2,"apMac",uVar3);
      uVar3 = json_object_new_string(auStack_40);
      json_object_object_add(iVar2,&DAT_00679a24,uVar3);
      uVar3 = json_object_new_int(*(undefined4 *)(param_1 + 0x148));
      json_object_object_add(iVar2,"auth_type",uVar3);
      iVar4 = *(int *)(param_1 + 0x14c);
      if (iVar4 == 0) {
        pcVar5 = "local";
      }
      else if (iVar4 == 1) {
        pcVar5 = "remote";
      }
      else {
        pcVar5 = (char *)0x0;
        if (iVar4 == 99) {
          pcVar5 = "tmp";
        }
      }
      uVar3 = json_object_new_string(pcVar5);
      json_object_object_add(iVar2,"auth_server_type",uVar3);
      uVar3 = json_object_new_string(param_1 + 0x7a);
      json_object_object_add(iVar2,"username",uVar3);
      if (*(int *)(param_1 + 0x148) == 0x20) {
        uVar3 = json_object_new_int(*(undefined2 *)(param_1 + 0x164));
        json_object_object_add(iVar2,"serialNo",uVar3);
        FUN_00408190(*(undefined4 *)(param_1 + 0x150),*(undefined4 *)(param_1 + 0x154),
                     *(undefined4 *)(param_1 + 0x158),*(undefined4 *)(param_1 + 0x15c),
                     *(undefined4 *)(param_1 + 0x160),auStack_40,0x28,"0.0.0.0");
        uVar3 = json_object_new_string(auStack_40);
        json_object_object_add(iVar2,"cmccServerIp",uVar3);
        cVar1 = *(char *)(param_1 + 0x166);
      }
      else {
        cVar1 = *(char *)(param_1 + 0x166);
      }
      if (cVar1 == '\0') {
        uVar3 = json_object_new_string(param_1 + 0xc);
        pcVar5 = "password";
      }
      else {
        uVar3 = json_object_new_int(*(undefined4 *)(param_1 + 0xc));
        json_object_object_add(iVar2,"challenge1",uVar3);
        uVar3 = json_object_new_int(*(undefined4 *)(param_1 + 0x10));
        json_object_object_add(iVar2,"challenge2",uVar3);
        uVar3 = json_object_new_int(*(undefined4 *)(param_1 + 0x14));
        json_object_object_add(iVar2,"challenge3",uVar3);
        uVar3 = json_object_new_int(*(undefined4 *)(param_1 + 0x18));
        json_object_object_add(iVar2,"challenge4",uVar3);
        uVar3 = json_object_new_int(*(undefined4 *)(param_1 + 0x1c));
        json_object_object_add(iVar2,"chapPassword1",uVar3);
        uVar3 = json_object_new_int(*(undefined4 *)(param_1 + 0x20));
        json_object_object_add(iVar2,"chapPassword2",uVar3);
        uVar3 = json_object_new_int(*(undefined4 *)(param_1 + 0x24));
        json_object_object_add(iVar2,"chapPassword3",uVar3);
        uVar3 = json_object_new_int(*(undefined4 *)(param_1 + 0x28));
        json_object_object_add(iVar2,"chapPassword4",uVar3);
        uVar3 = json_object_new_int(*(undefined1 *)(param_1 + 0x2c));
        pcVar5 = "chapid";
      }
      json_object_object_add(iVar2,pcVar5,uVar3);
      uVar3 = json_object_new_int(*(undefined1 *)(param_1 + 0x166));
      json_object_object_add(iVar2,"useChap",uVar3);
      wportal_send_to_nginx(iVar2);
      json_object_put(iVar2);
      return 0;
    }
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    pcVar5 = "[WPORTAL_ERR]%s()/%d Create send obj failed.\n";
    uVar3 = 0x69d;
  }
  printf(pcVar5,"_wportal_nonsense_auth",uVar3);
  return 0xffffffff;
}

