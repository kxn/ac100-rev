// func mesh_jcs_discover_cap_change @ 004bc2d4 size=712

void mesh_jcs_discover_cap_change(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char *__format;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_a0;
  undefined2 local_9c;
  char local_98 [16];
  uint local_88;
  undefined1 auStack_84 [100];
  int local_20;
  
  memset(auStack_84,0,0x68);
  local_98[0] = '\0';
  local_98[1] = '\0';
  local_98[2] = '\0';
  local_98[3] = '\0';
  local_98[4] = '\0';
  local_98[5] = '\0';
  local_98[6] = '\0';
  local_98[7] = '\0';
  local_98[8] = '\0';
  local_98[9] = '\0';
  local_98[10] = '\0';
  local_98[0xb] = '\0';
  local_98[0xc] = '\0';
  local_98[0xd] = '\0';
  local_98[0xe] = '\0';
  local_98[0xf] = '\0';
  local_88 = 0;
  local_a0 = 0;
  local_9c = 0;
  pcVar1 = (char *)mesh_db_discover_state_get();
  if (pcVar1 != (char *)0x1) {
    uVar6 = 0xfffffffe;
    if (mesh_debug_switch == '\0') goto LAB_004bc33c;
    __format = 
    "[MESH_DEBUG]%s()/%d You can\'t do dev pair in state(%d),please trigger discover first\n";
    uVar5 = 0x5a6;
LAB_004bc38c:
    printf(__format,"mesh_jcs_discover_cap_change",uVar5,pcVar1);
    goto LAB_004bc33c;
  }
  iVar2 = json_object_object_get(param_1,"mac");
  if ((iVar2 == 0) || (iVar3 = json_object_get_type(iVar2), iVar3 != 6)) {
    uVar6 = 0xffffffff;
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Illegal object for mac\n","mesh_jcs_discover_cap_change",0x5ad);
    }
    goto LAB_004bc33c;
  }
  iVar3 = json_object_get_type(iVar2);
  if (iVar3 == 6) {
    pcVar1 = (char *)json_object_get_string(iVar2);
  }
  else {
    if (jcs_err_switch != 0) {
      printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
             "mesh_jcs_discover_cap_change",0x5b0);
    }
    pcVar1 = "";
  }
  strncpy(local_98,pcVar1,0x13);
  local_88 = local_88 & 0xffffff00;
  iVar2 = sscanf(local_98,"%hhx-%hhx-%hhx-%hhx-%hhx-%hhx",&local_a0,(int)&local_a0 + 1,
                 (int)&local_a0 + 2,(int)&local_a0 + 3,&local_9c,(int)&local_9c + 1);
  if (iVar2 != 6) {
    uVar6 = 0xffffffff;
    if (mesh_err_switch == '\0') goto LAB_004bc33c;
    __format = "[MESH_ERROR]%s()/%d Mac addr(%s) is illegal!\n";
    uVar5 = 0x5b5;
    pcVar1 = local_98;
    goto LAB_004bc38c;
  }
  uVar6 = 0xffffffff;
  iVar2 = mesh_db_discover_entry_get(&local_a0,auStack_84);
  if ((iVar2 != 0) || (local_20 != 0)) goto LAB_004bc33c;
  iVar2 = json_object_object_get(param_1,"cap_id");
  if (iVar2 == 0) {
LAB_004bc530:
    if (jcs_err_switch == 0) {
      uVar4 = 0xffff;
    }
    else {
      printf("[JCS_ERR]%s()/%d Warning: transfer string to int failed.\n",
             "mesh_jcs_discover_cap_change",0x5bd);
      uVar4 = 0xffff;
    }
  }
  else {
    iVar3 = json_object_get_type(iVar2);
    if (iVar3 != 6) {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: obj type not string, parse failed.\n",
               "mesh_jcs_discover_cap_change",0x5bd);
      }
      goto LAB_004bc530;
    }
    pcVar1 = (char *)json_object_get_string(iVar2);
    uVar4 = atoi(pcVar1);
    uVar4 = uVar4 & 0xffff;
  }
  uVar6 = mesh_db_discover_select_cap_set(&local_a0,uVar4,1);
LAB_004bc33c:
  uVar6 = json_object_new_int(uVar6);
  json_object_object_add(param_2,&DAT_00676a24,uVar6);
  return;
}

